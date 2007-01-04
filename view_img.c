/* 
 * This simple program display b/w image (128x256 pixels)
 * on Linux terminal run on EGA/VGA video card.
 *
 * It is just a proof of concept, so everything is hardwired
 * in the code.
 *
 * What this program do?
 * - splits image into 256 pieces (8x16 pixels) and set them
 *   as console font (ioctl PIO_FONTX)
 * - switches console into utf-8 mode, and then print
 *   all characters from 0-256 (16x16); unicode characters
 *   U+F000 - U+F1FF gives direct access to loaded font
 *   (showcfont also uses this method)
 * 
 * The main problem
 * ================
 *
 * EGA/VGA cards use fonts of width 8 pixels, but by default
 * cell grid has width 9 pixels.  For most characters 9th column
 * is blank, but for characters 0xC0-0xDF 9th column is a copy
 * of first one (line-drawing characters are placed somewhere
 * in that range). Because of that displayed image is not
 * consistent -- text mode were designed to display characters,
 * not graphics.
 *
 * But if you have a root login and pass parameter 'root', then
 * program will try to reprogram EGA/VGA card in order to get
 * real 8-pixels with characters -- it is absolutely safe for
 * your hardware. 
 * 
 *
 * Compilation
 * ===========
 *
 * 	gcc -O2 view_img.c -o view_img
 *
 * 	Program uses setterm utility.
 *
 * Author
 * ======
 *
 * Wojciech Mu³a
 * wojciech_mula@poczta.onet.pl
 *
 * License: public-domain
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include <fcntl.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <sys/io.h>
#include <linux/kd.h>

#include <errno.h>
extern int errno;

#include "img.xbm"

unsigned char font[2][16][16][32];
unsigned char font_sav[2][16][16][32];

void ordie(char* info);

unsigned char byte_inv[256] = {0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0,
0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0, 0x08, 0x88, 0x48, 0xc8, 0x28,
0xa8, 0x68, 0xe8, 0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8, 0x04, 0x84,
0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4, 0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74,
0xf4, 0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c, 0x9c, 0x5c, 0xdc,
0x3c, 0xbc, 0x7c, 0xfc, 0x02, 0x82, 0x42, 0xc2, 0x22, 0xa2, 0x62, 0xe2, 0x12,
0x92, 0x52, 0xd2, 0x32, 0xb2, 0x72, 0xf2, 0x0a, 0x8a, 0x4a, 0xca, 0x2a, 0xaa,
0x6a, 0xea, 0x1a, 0x9a, 0x5a, 0xda, 0x3a, 0xba, 0x7a, 0xfa, 0x06, 0x86, 0x46,
0xc6, 0x26, 0xa6, 0x66, 0xe6, 0x16, 0x96, 0x56, 0xd6, 0x36, 0xb6, 0x76, 0xf6,
0x0e, 0x8e, 0x4e, 0xce, 0x2e, 0xae, 0x6e, 0xee, 0x1e, 0x9e, 0x5e, 0xde, 0x3e,
0xbe, 0x7e, 0xfe, 0x01, 0x81, 0x41, 0xc1, 0x21, 0xa1, 0x61, 0xe1, 0x11, 0x91,
0x51, 0xd1, 0x31, 0xb1, 0x71, 0xf1, 0x09, 0x89, 0x49, 0xc9, 0x29, 0xa9, 0x69,
0xe9, 0x19, 0x99, 0x59, 0xd9, 0x39, 0xb9, 0x79, 0xf9, 0x05, 0x85, 0x45, 0xc5,
0x25, 0xa5, 0x65, 0xe5, 0x15, 0x95, 0x55, 0xd5, 0x35, 0xb5, 0x75, 0xf5, 0x0d,
0x8d, 0x4d, 0xcd, 0x2d, 0xad, 0x6d, 0xed, 0x1d, 0x9d, 0x5d, 0xdd, 0x3d, 0xbd,
0x7d, 0xfd, 0x03, 0x83, 0x43, 0xc3, 0x23, 0xa3, 0x63, 0xe3, 0x13, 0x93, 0x53,
0xd3, 0x33, 0xb3, 0x73, 0xf3, 0x0b, 0x8b, 0x4b, 0xcb, 0x2b, 0xab, 0x6b, 0xeb,
0x1b, 0x9b, 0x5b, 0xdb, 0x3b, 0xbb, 0x7b, 0xfb, 0x07, 0x87, 0x47, 0xc7, 0x27,
0xa7, 0x67, 0xe7, 0x17, 0x97, 0x57, 0xd7, 0x37, 0xb7, 0x77, 0xf7, 0x0f, 0x8f,
0x4f, 0xcf, 0x2f, 0xaf, 0x6f, 0xef, 0x1f, 0x9f, 0x5f, 0xdf, 0x3f, 0xbf, 0x7f,
0xff};

void setcell(int x, int y) {
	int k;
	unsigned char *d;
	unsigned int adr;

	d   = img_bits;
	adr = y*16*16 + x;
	for (k=0; k < 16; k++) {
		font[0][y][x][k] = ~byte_inv[d[adr]];
		adr += 16;
	}
}

#define SEQ_IDX		0x3c4
#define SEQ_DATA	0x3c5
#define true  1
#define false 0

int main(int argc, char* argv[]) {
	struct consolefontdesc dsc;
	int tty;
	int x, y, k;
	unsigned int ucs2;
	unsigned char b;
	char root = false;

	root = (argc > 1 && strcmp(argv[1], "root") == 0);

	if (root) {
		/* obtain permissions to access SEQUENCER */
		ioperm(SEQ_IDX,   1, 1); ordie("ioperm (1)");
		ioperm(SEQ_DATA,  1, 1); ordie("ioperm (2)");
	}
	
	tty = open("/dev/tty", O_RDWR); ordie("open");
	dsc.charcount	= 256;
	dsc.charheight	= 16;

	/* clear image */
	system("setterm -foreground black -background black");
	system("clear");
	system("setterm -foreground white -background black -bold on");

	printf("\033%%G"); /* turn on utf-8 */

	if (root) {
		/* set width of chars to 8 pixels */
		outb(1, SEQ_IDX);
		b = inb(SEQ_DATA);
		outb(1, SEQ_IDX);
		outb(b | 0x01, SEQ_DATA);
	}

	for (y=0; y<16; y++) {
		for (x=0; x<16; x++) {
			/* convert UCS-2 -> UTF-8 */
			ucs2 = 0xF000 + y*16 + x;
			putchar(0xe0 | (ucs2 >> 12));
			putchar(0x80 | ((ucs2 >> 6)  & 0x3f));
			putchar(0x80 | (ucs2 & 0x3f));

			/* copy piece of image to font data */
			setcell(x, y);
		}
		printf("\n");
	}
    	printf("\033%%@"); /* turn off UTF-8 */

	/* save original font */
	dsc.chardata = font_sav;
	ioctl(tty, GIO_FONTX, &dsc); ordie("GIO_FONTX");
	/* set new font -- our image */
	dsc.chardata = font;
	ioctl(tty, PIO_FONTX, &dsc); ordie("PIO_FONTX");

	/* wait for user */
	getchar();
	
	/* restore original font */
	dsc.chardata = font_sav;
	ioctl(tty, PIO_FONTX, &dsc); ordie("PIO_FONTX (2)");
	
	close(tty); ordie("close");
	system("setterm -foreground default -background default -bold off");
	system("clear");

	if (root) {
		/* set back width of chars to 9 pixels */
		outb(1, SEQ_IDX);
		b = inb(SEQ_DATA);
		outb(1, SEQ_IDX);
		outb(b & 0xE, SEQ_DATA);
	}
	return 0;
}

void ordie(char* info) {
	if (errno != 0) {
		fprintf(stdout, "%s [errno=%d]: %s\n", info, errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
}
