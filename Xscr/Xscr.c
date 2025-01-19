/*
	$Date: 2008-06-21 18:27:04 $, $Revision: 1.9 $

	Simple direct-screen abstraction for X Window [implementation].

	Author: Wojciech Muła
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: public domain
*/

#include "Xscr.h"
#include <stdlib.h>

// global variables
Display* display;
Window   window;

static Bool running = False;
static Bool quit;
static char redraw;

void Xscr_quit()       {quit = True;}
void Xscr_redraw()     {redraw = 1;}
void Xscr_redraw_now() {redraw = 2;}
void Xscr_discard_events() {XSync(display, True);}

// conversion routines
void Xscr_prepare_lookups();
void Xscr_convert_gray_32bpp(void*, void*, unsigned int, unsigned int);
void Xscr_convert_gray_16bpp(void*, void*, unsigned int, unsigned int);
void Xscr_convert_gray_15bpp(void*, void*, unsigned int, unsigned int);
void Xscr_convert_16bpp_32bpp(void*, void*, unsigned int, unsigned int);
void Xscr_convert_15bpp_32bpp(void*, void*, unsigned int, unsigned int);
void Xscr_convert_32bpp_16bpp(void*, void*, unsigned int, unsigned int);


enum {
	NO_ERROR				= 0,
	CANT_OPEN_DISPLAY		= 1,
	DEPTHS_MISMATCH			= 2,
	UNSUPPORTED_CONVERSION 	= 3,
	OUT_OF_MEMORY			= 4,
	XIMAGE_CREATION_ERROR	= 5,
	XSCR_MAIN_LOOP_RUNNING	= 6,
	INVALID_IMAGE_WIDTH		= 7
};


int Xscr_mainloop(
	unsigned int width,
	unsigned int height,
	BitsPerPixel screen_depth,
	Bool require_exact_depth,
	uint8_t* screen_data,

	Xscr_keyboard_callback	keyboard_callback,
	Xscr_motion_callback	motion_callback,
	Xscr_buttons_callback	buttons_callback,
	const char* app_name
) {
	// X variables
	int      screen;
	GC       defaultGC;
	XEvent	 event;
	KeySym*  key_symbol;
	int	     ret;

	// priv variables
	uint8_t* real_screen_data = NULL;
	XImage*  image;
	int      depth;
	XSizeHints size_hints;
	XWMHints   WM_hints;
	void	   (*conv_func)(void*, void*, unsigned int, unsigned int) = NULL;

	// 0. is Xscr_mainloop running
	if (running)
		return XSCR_MAIN_LOOP_RUNNING;
	else
		running = True;

	// 1. is width is multiply of 32
	switch (screen_depth) {
		case 24:
			if ((width*4) % 32)
				return INVALID_IMAGE_WIDTH;
			break;
		case 15:
		case 16:
			if ((width*2) % 32)
				return INVALID_IMAGE_WIDTH;
			break;
		case 8:
			if (width % 32)
				return INVALID_IMAGE_WIDTH;
			break;
	}

	// 2. open display
	display = XOpenDisplay(NULL);
	if (!display) return CANT_OPEN_DISPLAY;

	// 3. get screen & depth
	screen = DefaultScreen(display);
	depth  = DefaultDepth(display, screen);

	// 4. setup conversion routins if needed
	if (depth != (int)screen_depth) {
		if (require_exact_depth)
			return DEPTHS_MISMATCH;

		// select conversion function
		switch ((int)screen_depth) {
			case 8:
				switch (depth) {
					case 24: conv_func = Xscr_convert_gray_32bpp; break;
					case 16: conv_func = Xscr_convert_gray_16bpp; break;
					case 15: conv_func = Xscr_convert_gray_15bpp; break;
					default: return UNSUPPORTED_CONVERSION;
				}
				break;

			case 16:
				switch (depth) {
					case 24: conv_func = Xscr_convert_16bpp_32bpp; break;
					default: return UNSUPPORTED_CONVERSION;
				}
				break;

			case 15:
				switch (depth) {
					case 24: conv_func = Xscr_convert_15bpp_32bpp; break;
					default: return UNSUPPORTED_CONVERSION;
				}
				break;

			case 24:
				switch (depth) {
					case 16: conv_func = Xscr_convert_32bpp_16bpp; break;
					default: return UNSUPPORTED_CONVERSION;
				}
				break;

			default:
				return UNSUPPORTED_CONVERSION;
		}

		// allocate mem for backbuffer
		switch (depth) {
			case 24:
				real_screen_data = malloc(width * height * 4);
				break;
			case 15:
			case 16:
				real_screen_data = malloc(width * height * 2);
				break;
			case 8:
				real_screen_data = malloc(width * height);
				break;
		}

		if (real_screen_data == NULL) return OUT_OF_MEMORY;
		image = XCreateImage(display, DefaultVisual(display, screen),
			depth, ZPixmap, 0, (char*)real_screen_data,
			width, height, 8, 0);

		Xscr_prepare_lookups();
	}
	else {
		image = XCreateImage(display, DefaultVisual(display, screen),
			depth, ZPixmap, 0, (char*)screen_data,
			width, height, 8, 0);
		if (image == NULL)
			return XIMAGE_CREATION_ERROR;
		}

	// 5. create window
	window = XCreateSimpleWindow( // make a simple window
		display,
		RootWindow(display, screen),
		0, 0,
		width, height,
		1,
		BlackPixel(display, screen),
		WhitePixel(display, screen)
	);

	// 6. set application name
	if (app_name)
		XStoreName(display, window, app_name);
	else
		XStoreName(display, window, "Xscr application");

	// 7a. set hints
	WM_hints.flags = InputHint | StateHint;
	WM_hints.input = True;
	WM_hints.initial_state = NormalState;
	XSetWMHints(display, window, &WM_hints);

	// 7b. set size hints (inhibit resizing)
	size_hints.flags = PMinSize | PMaxSize | PSize;
	size_hints.width = size_hints.min_width = size_hints.max_width = width;
	size_hints.height = size_hints.min_height = size_hints.max_height = height;
	XSetWMNormalHints(display, window, &size_hints);

	// 8. setup graphics context
	defaultGC = XCreateGC(display, window, 0, NULL);
	XSetForeground(display, defaultGC, BlackPixel(display, screen) );
	XSetBackground(display, defaultGC, WhitePixel(display, screen) );

	// 9. show window on the screen
	XMapWindow(display, window);

	// 10. decide what events we should read
	long event_mask = ExposureMask;

	if (motion_callback)
		event_mask |= PointerMotionMask;
	if (keyboard_callback) {
		event_mask |= KeyPressMask;
		event_mask |= KeyReleaseMask;
	}
	if (buttons_callback) {
		event_mask |= ButtonPressMask;
		event_mask |= ButtonReleaseMask;
	}

	XSelectInput(display, window, event_mask);

	// 11. start reading messages
	quit   = False;
	redraw = 1;

	while (!quit) {
		if (redraw) {
			if (conv_func)
				(*conv_func)((void*)screen_data, (void*)real_screen_data, width, height);

			XPutImage(display, window, defaultGC, image, 0, 0, 0, 0, width, height);

			if (redraw == 2)
				XFlush(display);

			redraw = 0;
		}

		XNextEvent(display, &event);
		switch (event.type) {
			case Expose:
				XPutImage(display, window, defaultGC, image,
				          event.xexpose.x, event.xexpose.y,
				          event.xexpose.x, event.xexpose.y,
				          event.xexpose.width, event.xexpose.height
				);
				break;
			case MotionNotify:
				motion_callback(
					event.xmotion.x,
					event.xmotion.y,
					event.xmotion.time,
					event.xmotion.state
				);
				break;
			case KeyPress:
                key_symbol = XGetKeyboardMapping(display, event.xkey.keycode, 1, &ret);
				keyboard_callback(
					event.xkey.x,
					event.xkey.y,
					event.xkey.time,
					key_symbol[0],
					Pressed,
					event.xkey.state
				);
				XFree(key_symbol);
				break;
			case KeyRelease:
                key_symbol = XGetKeyboardMapping(display, event.xkey.keycode, 1, &ret);
				keyboard_callback(
					event.xkey.x,
					event.xkey.y,
					event.xkey.time,
					key_symbol[0],
					Released,
					event.xkey.state
				);
				XFree(key_symbol);
				break;
			case ButtonPress:
				buttons_callback(
					event.xbutton.x,
					event.xbutton.y,
					event.xbutton.time,
					Pressed,
					event.xbutton.button,
					event.xbutton.state
				);
				break;
			case ButtonRelease:
				buttons_callback(
					event.xbutton.x,
					event.xbutton.y,
					event.xbutton.time,
					Released,
					event.xbutton.button,
					event.xbutton.state
				);
				break;
			default:
				break;
		}
	}

	XCloseDisplay(display);

	if (real_screen_data != NULL) {
		free(real_screen_data);
	}

	return NO_ERROR;
}


char* Xscr_error_str(int error_code) {
	switch (error_code) {
		case NO_ERROR:
			return "no error";

		case CANT_OPEN_DISPLAY:
			return "can't open display (is $DISPLAY set?)";

		case DEPTHS_MISMATCH:
			return "screen depth is different then required depth";

		case UNSUPPORTED_CONVERSION:
			return "unsupported screen depth conversions";

		case OUT_OF_MEMORY:
			return "not enough memory for backbuffer";

		case XIMAGE_CREATION_ERROR:
			return "can't create Ximage";

		case XSCR_MAIN_LOOP_RUNNING:
			return "Xscr_mainloop is alread y running";

		case INVALID_IMAGE_WIDTH:
			return "width isn't multiply of 32";

		default:
			return "unknown error";
	}
}


uint32_t __conv_gray_32bpp[256];
uint16_t __conv_gray_15bpp[256];
uint16_t __conv_gray_16bpp[256];
uint32_t __conv_15bpp_32bpp_lo[256];
uint32_t __conv_15bpp_32bpp_hi[256];
uint32_t __conv_16bpp_32bpp_lo[256];
uint32_t __conv_16bpp_32bpp_hi[256];

void Xscr_prepare_lookups() {
	uint32_t i, i5, i6;

	for (i=0; i < 256; i++) {
		i5 = i >> 3;
		i6 = i >> 2;

		// gray -> direct color
		__conv_gray_32bpp[i] =  (i << 16) |  (i << 8) | i;
		__conv_gray_16bpp[i] = (i5 << 11) | (i6 << 5) | i5;
		__conv_gray_15bpp[i] = (i5 << 10) | (i5 << 5) | i5;


		// 16bpp -> 32bpp
		// |rrrrrggg gggbbbbb|

		// |00000000 00000000 000ggg00 bbbbb000|
		__conv_16bpp_32bpp_lo[i] = ((i & 0xe0) << 5) | ((i & 0x1f) << 3);

		// |00000000 rrrrr000 ggg00000 00000000|
		__conv_16bpp_32bpp_hi[i] = ((i & 0x07) << 13) | ((i & 0xf8) << 16);


		// 15bpp -> 32bpp
		// |0rrrrrgg gggbbbbb|
		//
		// |00000000 rrrrr000 ggggg000 bbbbb000|

		// |00000000 00000000 000gg000 bbbbb000|
		__conv_15bpp_32bpp_lo[i] = ((i & 0xe0) << 5) | ((i & 0x1f) << 3);

		// |00000000 rrrrr000 ggg00000 00000000|
		__conv_15bpp_32bpp_hi[i] = ((i & 0x07) << 13) | ((i & 0x78) << 17);
	}
}



void Xscr_convert_gray_32bpp(
	void *gray,
	void *true_color,
	unsigned int width,
	unsigned int height
) {
	unsigned int x, y;
	uint8_t  *src;
	uint32_t *dst;

	src = gray;
	dst = true_color;
	for (y=0; y < height; y++)
		for (x=0; x < width; x++)
			*dst++ = __conv_gray_32bpp[*src++];
}


void Xscr_convert_gray_16bpp(
	void *gray,
	void *true_color,
	unsigned int width,
	unsigned int height
) {
	unsigned int x, y;
	uint8_t  *src;
	uint16_t *dst;

	src = gray;
	dst = true_color;
	for (y=0; y < height; y++)
		for (x=0; x < width; x++)
			*dst++ = __conv_gray_16bpp[*src++];
}


void Xscr_convert_gray_15bpp(
	void *gray,
	void *true_color,
	unsigned int width,
	unsigned int height
) {
	unsigned int x, y;
	uint8_t  *src;
	uint16_t *dst;

	src = gray;
	dst = true_color;
	for (y=0; y < height; y++)
		for (x=0; x < width; x++)
			*dst++ = __conv_gray_15bpp[*src++];
}


void Xscr_convert_16bpp_32bpp(
	void *pix16bpp,
	void *true_color,
	unsigned int width,
	unsigned int height
) {
	int n;
	uint16_t *src;
	uint32_t *dst;

	src = pix16bpp;
	dst = true_color;
	n   = width * height;
	while (n-- >= 0) {
		*dst++ = __conv_16bpp_32bpp_lo[*src & 0x00ff] |
				 __conv_16bpp_32bpp_hi[*src >> 8];
		src++;
	}
}


void Xscr_convert_15bpp_32bpp(
	void *pix15bpp,
	void *true_color,
	unsigned int width,
	unsigned int height
) {
	unsigned int x, y;
	uint16_t  *src;
	uint32_t *dst;

	src = pix15bpp;
	dst = true_color;
	for (y=0; y < height; y++)
		for (x=0; x < width; x++) {
			*dst++ = __conv_15bpp_32bpp_lo[*src & 0x00ff] |
			         __conv_15bpp_32bpp_hi[*src >> 8];
			src++;
		}
}


#ifdef XSCR_X86conv
void Xscr_convert_32bpp_16bpp(
	void *pix32bpp,
	void *pix16bpp,
	unsigned int width,
	unsigned int height
) {
	asm(
		"    xorl %%eax, %%eax                    \n\t"
		"    xorl %%ebx, %%ebx                    \n\t"
		".1:                                      \n\t"
		"    movl 0(%%esi), %%eax                 \n\t"
		"    movl 4(%%esi), %%ebx                 \n\t"
		"    shrb $2, %%ah                        \n\t"
		"    shrb $2, %%bh                        \n\t"

		"    shrl $3, %%eax                       \n\t"
		"    shrl $3, %%ebx                       \n\t"

		"    shlw $5, %%ax                        \n\t"
		"    shlw $5, %%bx                        \n\t"

		"    shrl $5, %%eax                       \n\t"
		"    shll $11, %%ebx                      \n\t"
		"                                         \n\t"
		"    addl $8, %%esi                       \n\t"
		"    orl  %%ebx, %%eax                    \n\t"
		"                                         \n\t"
		"    movl %%eax, (%%edi)                  \n\t"
		"    addl $4, %%edi                       \n\t"

		"    subl $1, %%ecx                       \n\t"
		"    jnz  .1                              \n\t"
	: /* no output */
	: "S" (pix32bpp), "D" (pix16bpp), "c" (width/2*height)
	: "%eax", "%ebx", "memory"
	);
	return;
}
#else
void Xscr_convert_32bpp_16bpp(
	void *pix32bpp,
	void *pix16bpp,
	unsigned int width,
	unsigned int height
) {
	unsigned int x, y;
	uint8_t *src;
	uint16_t  R, G, B;
	uint16_t *dst;

	src = pix32bpp;
	dst = pix16bpp;

	for (y=0; y < height; y++)
		for (x=0; x < width; x++) {
			B = *src++ >> 3;
			G = (uint16_t)(*src++ & 0xfc) << 3;
			R = (uint16_t)(*src++ & 0xf8) << 8;
			src++;

			*dst++ = R | G | B;
		}
}
#endif

// vim: ts=4 sw=4 nowrap
