/*
	$Date: 2008-06-08 23:00:14 $, $Revision: 1.12 $
	
	Simple PPM files (24bpp) loader/identify [implementation].
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl
	
	License: public domain
*/

#ifdef PPM_ALIGN_MALLOC
#	if !((PPM_ALIGN_MALLOC & (PPM_ALIGN_MALLOC - 1)) == 0 && PPM_ALIGN_MALLOC)
#		error "PPM_ALIGN_MALLOC have to be power of two"
#	endif
#   define _XOPEN_SOURCE 600
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "load_ppm.h"

static char __ppm_read_int(FILE* f, int* v) {
	int value = 0;	// readed value
	int c;			// buffer
	char valid = 0;	// flag
	
	while (1) {
		c = fgetc(f);
		if (c >= '0' && c <= '9') {
			value = 10*value + (c - '0');
			valid = 1;
		}
		else {
			ungetc(c, f);
			break;
		}
	}
	
	if (valid) // alter variable only if succed
		*v = value;
	return valid;
}

static char __ppm_skip_whitespaces(FILE* f) {
	char skipped = 0;
	int c;
	while (1) {
		c = getc(f);
		if (c == '\n' || c == '\t' || c == '\r' || c == ' ')
			skipped = 1;
		else {
			ungetc(c, f);
			break;
		}
	}
	return skipped;
}

static char __ppm_skip_comment(FILE* f) {
	int c;
	c = fgetc(f);
	if (c != '#') {
		ungetc(c, f);
		return 0;
	}
	while (c != '\n')
		c = fgetc(f);
	
	if (c == EOF)
		return 0;
	else
		return 1;
}


#ifdef PPM_ALIGN_MALLOC
static void* ppm_malloc(size_t size) {
	void* ptr;
	if (posix_memalign(&ptr, PPM_ALIGN_MALLOC, size))
		return NULL;
	else
		return ptr;
}

#define malloc ppm_malloc
#endif


int ppm_identify(FILE* f, int* width, int* height, int* maxval) {
	int c;
	
	// check signature
	if (fgetc(f) != 'P' || fgetc(f) != '6')
		return -1;

	// read width
	while (__ppm_skip_whitespaces(f) || __ppm_skip_comment(f));
	if (!__ppm_read_int(f, width)) return -2;
	
	// read height
	while (__ppm_skip_whitespaces(f) || __ppm_skip_comment(f));
	if (!__ppm_read_int(f, height)) return -3;

	// read maxval
	while (__ppm_skip_whitespaces(f) || __ppm_skip_comment(f));
	if (!__ppm_read_int(f, maxval)) return -4;

	c = fgetc(f);
	if (!(c == '\n' || c == '\t' || c == '\r' || c == ' ')) return -5; 
	if (*maxval > 65535) return -6;

	return 0;
}


int ppm_bytes_per_line(int img_width, int bytes_per_pixel, int unit) {
	int blocks;
	// unit in pixels
	if (unit < -1) { 
		unit   = -unit;
		blocks = (img_width + unit-1)/unit;
		return blocks * unit * bytes_per_pixel;
	}
	else
	// unit in bytes
	if (unit > 1) { 
		blocks = (img_width * bytes_per_pixel + unit-1)/unit;
		return blocks * unit;
	}
	// no rounding
	else
		return img_width * bytes_per_pixel;
}


int ppm_load(FILE* file, int* width, int* height, int* maxval, uint8_t** data) {
	int size, result;

	result = ppm_identify(file, width, height, maxval);
	if (result < 0)
		return result;
	
	// data is NULL -- do nothing
	if (data == NULL)
		return 0;

	if (*maxval < 256)
		size = *width * 3;
	else
		size = *width * 6;
		
	*data = (uint8_t*)malloc(size);
	if (!*data)
		return -7;

	if (fread((void*)*data, size, 1, file) < 1)
		return -8;
	else
		return 0;
}


int ppm_load_32bpp_alpha(FILE* file, int* width, int* height, int* maxval, uint8_t** data, int unit, uint8_t alpha) {
	int size, result, y, x, bpl;
	uint8_t* tmpbuffer;
	uint8_t* dst;
	uint8_t* src;
	uint8_t  R, G, B;

	result = ppm_identify(file, width, height, maxval);
	if (result < 0)
		return result;
	
	// data is NULL -- do nothing
	if (data == NULL)
		return 0;


	if (*maxval < 256)
		bpl = ppm_bytes_per_line(*width, 4, unit);
	else
		return -10;
	
	*data = (uint8_t*)malloc(*height * bpl);
	if (!*data)
		return -7;
	else
		memset(*data, 0, *height * bpl);
	
	if (*maxval < 256)
		size = *width * 3;
	else
		size = *width * 6;
	
	tmpbuffer = (uint8_t*)malloc(size);
	if (!tmpbuffer)
		return -9;
	
	// read
	dst = *data;
	for (y=0; y < *height; y++) {
		src = tmpbuffer;
		if (fread((void*)tmpbuffer, size, 1, file) < 1) {
			free(tmpbuffer);
			return -8;
		}
		for (x=0; x < *width; x++) {
			R = *src++;
			G = *src++;
			B = *src++;
			*dst++ = B;
			*dst++ = G;
			*dst++ = R;
			*dst++ = alpha;
		}
		dst += bpl - (*width * 4);
	}

	free(tmpbuffer);
	return 0;
}


int ppm_load_32bpp(FILE* file, int* width, int* height, int* maxval, uint8_t** data, int unit) {
	return ppm_load_32bpp_alpha(file, width, height, maxval, data, unit, 0x00);
}


int ppm_load_16bpp(FILE* file, int* width, int* height, int* maxval, uint8_t** data, int unit) {
	int size, result, y, x, bpl;
	uint8_t* tmpbuffer;
	uint8_t* src;
	uint8_t* dst;
	uint16_t r, g, b;

	result = ppm_identify(file, width, height, maxval);
	if (result < 0)
		return result;
	
	// data is NULL -- do nothing
	if (data == NULL)
		return 0;


	if (*maxval < 256)
		bpl = ppm_bytes_per_line(*width, 2, unit);
	else
		return -10;
		
	*data = (uint8_t*)malloc(*height * bpl);
	if (!*data)
		return -7;
	else
		memset(*data, 0, *height * bpl);
	
	if (*maxval < 256)
		size = *width * 3;
	else
		size = *width * 6;
	
	tmpbuffer = (uint8_t*)malloc(size);
	if (!tmpbuffer)
		return -9;
	
	// read
	dst = *data;
	for (y=0; y < *height; y++) {
		src = tmpbuffer;
		if (fread((void*)tmpbuffer, size, 1, file) < 1) {
			free(tmpbuffer);
			return -8;
		}
		for (x=0; x < *width; x++) {
			r = *src++ >> 3;
			g = *src++ >> 2;
			b = *src++ >> 3;
			*(uint16_t*)dst = (r << 11) | (g << 5) | b;
			dst += 2;
		}
		dst += bpl - (*width * 2);
	}

	free(tmpbuffer);
	return 0;
}


int ppm_load_gray(FILE* file, int* width, int* height, int* maxval, uint8_t** data, int unit, GrayScaleMode gsm) {
	int size, result, y, x, bpl;
	uint8_t* tmpbuffer;
	uint8_t* src;
	uint8_t* dst;
	uint16_t r, g, b;
	double   gray;

	result = ppm_identify(file, width, height, maxval);
	if (result < 0)
		return result;
	
	// data is NULL -- do nothing
	if (data == NULL)
		return 0;


	if (*maxval < 256)
		bpl = ppm_bytes_per_line(*width, 1, unit);
	else
		return -10;
		
	*data = (uint8_t*)malloc(*height * bpl);
	if (!*data)
		return -7;
	else
		memset(*data, 0, *height * bpl);
	
	if (*maxval < 256)
		size = *width * 3;
	else
		size = *width * 6;
	
	tmpbuffer = (uint8_t*)malloc(size);
	if (!tmpbuffer)
		return -9;
	
	// read
	dst = *data;
	for (y=0; y < *height; y++) {
		src = tmpbuffer;
		if (fread((void*)tmpbuffer, size, 1, file) < 1) {
			free(tmpbuffer);
			return -8;
		}
		if (gsm == Simple)
			for (x=0; x < *width; x++) {
				r = *src++;
				g = *src++;
				b = *src++;
				*dst++ = (r + g + b)/3;
			}
		else
			for (x=0; x < *width; x++) {
				r = *src++;
				g = *src++;
				b = *src++;
				gray = 0.299*r + 0.587*g + 0.114*b;
				if (gray > 255.0) 
					*dst++ = 0xff;
				else
					*dst++ = (uint8_t)gray;
			}
		dst += bpl - *width;
	}

	free(tmpbuffer);
	return 0;
}


#ifdef TEST_PPM
int main(int argc, char* argv[]) {
	int i;
	int width, height, maxval;
	int result;
	uint8_t* img;
	FILE* file;
	
	if (argc == 1)
		puts("usage: program [PPM files]");
	else
		for (i=1; i < argc; i++) {
			file = fopen(argv[i], "rb");
			if (!file) {
				fprintf(stderr, "Can't open for read '%s'\n", argv[i]);
				continue;
			}
			
			result = load_ppm(file, &width, &height, &maxval, &img);
			if (result < 0)
				fprintf(stderr, "Error loading file '%s': %s",
				       argv[i], PPM_errormsg[-result]);
			else {
				printf("PPM file '%s' has dimensions %dx%d, image size %d bytes (%sbpp)\n",
				       argv[i], width, height,
					   width * height * (maxval < 256 ? 1 : 2),
					   maxval < 256 ? "8" : "16");
				free(img);
			}
		}
}
#endif

// vim: ts=4 sw=4 nowrap noexpandtab
