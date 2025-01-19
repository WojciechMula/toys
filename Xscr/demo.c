/*
 	Compilation:

	$ gcc -O2 Xscr.c demo.c -lX11 -o demo

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Xscr.h"

void motion(
	int x, int y, Time t,
	unsigned int kb_mask
) {
	printf("mouse position: %d, %d\n", x, y);
}

void buttons(
	int x, int y, Time t,
	KeyOrButtonState s,
	unsigned int button,
	unsigned int kb_mask
) {
	printf("state=%s, button=%d\n",
	        s==Pressed ? "Pressed" : "Released",
	        button
	);
}

void keyboard(
	int x, int y, Time t,
	KeySym c,
	KeyOrButtonState s,
	unsigned int state
) {
	printf("state=%s, key=%s\n",
	       s==Pressed ? "Pressed" : "Released",
	       XKeysymToString(c)
	);
	if (c == XK_q || c == XK_Q)
		Xscr_quit();
}

int main(int argc, char* argv[]) {
	int result;

	int screen_width = 640;
	int screen_height = 480;

	int img_width, img_height, x, y;
	uint8_t *data;
	uint8_t *img_row;
	uint8_t *src, *dst;
	FILE* file;

	if (argc < 4) {
		printf("usage: %s width height ppmfile\n", argv[0]);
		return 1;
	}

	img_width  = screen_width  = atoi(argv[1]);
	img_height = screen_height = atoi(argv[2]);

	file = fopen(argv[3], "rb");
	if (!file) {
		printf("Can't open '%s'\n", argv[3]);
		return 1;
	}
	data    = (uint8_t*)malloc(screen_width * screen_height * 4);
	img_row = (uint8_t*)malloc(img_width * 3);
	if (!data || !img_row) {
		printf("Not enough memory\n");
		return 1;
	}

	// load file
	memset(data, 0x333333, screen_width * screen_height * 4);

	int H = (img_height < screen_height) ? img_height : screen_height;
	int W = (img_width < screen_width) ? img_width : screen_width;

	fseek(file, -img_width * img_height * 3, SEEK_END);
	for (y=0; y < H; y++) {
		fread(img_row, img_width, 3, file);
		if (feof(file))
			break;

		src = img_row;
		dst = &data[y * screen_width * 4];
		for (x=0; x < W; x++) {
			*dst++ = *(src+2);
			*dst++ = *(src+1);
			*dst++ = *(src+0);
			*dst++ = 0x00;
			src += 3;
		}
	}

	fclose(file);


	// run mainloop
	result = Xscr_mainloop(
		screen_width,
		screen_height,
		DEPTH_32bpp, False, data,
		keyboard, motion, buttons,
		"Xscr demo"
	);

	// check exit status
	if (result) {
		printf("Xscr error: %s\n", Xscr_error_str(result));
	}

	free(data);
	free(img_row);
	return 0;
}

// vim: ts=4 sw=4 nowrap
