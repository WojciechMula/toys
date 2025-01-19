#ifndef __LOAD_PPM_H_INCLUDED__
#define __LOAD_PPM_H_INCLUDED__
/*
	$Date: 2008-06-21 22:18:18 $, $Revision: 1.6 $
	
	Simple PPM files (24bpp) loader/identify [header].
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl
	
	License: public domain
*/

#include <stdio.h>


/*
	identify PPM (i.e. 24bpp RGB).

	Input:
		f      - file

	Output:
		width,
		height - image dimensions
		maxval - maximal value of sample (usually 255)
		data   - pointer to image pixels (if NULL image pixels
		         are not loaded, no memory is allocated)
				 user have to free data

	Returns:
		status, 0 if succed, < 0 -- some error occured, error
		message: PPM_errormsg[-ret_val]
*/
int ppm_identify(
	FILE* f,
	int* width,
	int* height,
	int* maxval
);


// returns bytes in scanline for given width and bpp
// unit > 0 -- bytes
// unit < 0 -- pixels
int ppm_bytes_per_line(int img_width, int bytes_per_pixel, int uint);


// load original 24bpp image
int ppm_load(
	FILE* file,
	int* width,
	int* height,
	int* maxval,
	uint8_t** data
);

// load PPM and convert to 32bpp image, with desired alpha per pixel
int ppm_load_32bpp_alpha(
	FILE* file, 
	int* width, 
	int* height, 
	int* maxval, 
	uint8_t** data, 
	int unit, // units: greater then 0 -- in bytes
	          //        less then 0    -- in pixels
	uint8_t alpha
);

// load PPM and convert to 32bpp image (alpha is zero)
int ppm_load_32bpp(
	FILE* file, 
	int* width, 
	int* height, 
	int* maxval, 
	uint8_t** data, 
	int unit // units: greater then 0 -- in bytes
	         //        less then 0    -- in pixels
);

// load PPM and convert to 16bpp image
int ppm_load_16bpp(
	FILE* file,
	int* width, 
	int* height, 
	int* maxval, 
	uint8_t** data, 
	int unit
);

typedef enum {
	Simple,	// average of R, G, B
	Weigted	// weighted sum of R, G, B
} GrayScaleMode;


// load PPM and convert to grayscale image
int ppm_load_gray(
	FILE* file, 
	int* width, 
	int* height, 
	int* maxval, 
	uint8_t** data, 
	int unit, 
	GrayScaleMode gsm
);


#define PPM_maxerror 11
static char* PPM_errormsg[PPM_maxerror] __attribute__((unused)) = {
	/* 0 */ "no error",
	/* 1 */ "wrong signature",
	/* 2 */ "image width absent",
	/* 3 */ "image height absent",
	/* 4 */ "image maxval absent",
	/* 5 */ "no single whitespace after maxval",
	/* 6 */ "maxval larger then 65535",
	/* 7 */ "no free memory for image pixels",
	/* 8 */ "too few image pixels"
	/* 9 */ "no free memory for tmp buffer",
	/* 10 */ "can't convert, maxval > 255",
};

#endif

// vim: ts=4 sw=4 nowrap noexpandtab
