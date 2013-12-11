/*
	Grab tty as image (PNM)

	License: public domain

	compile:
		gcc -O2 ttyscreenshot.c -o ttyscreenshot
	
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl

	Changelog:

		2013-10-13: some cleanups
		2008-06-21: initial relase
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/ioctl.h>
#include <sys/kd.h>

extern int errno;
typedef void (*save_fun)(uint8_t char_code, uint8_t font_row, uint8_t fore, uint8_t back);

/* aux functions */
uint8_t swapbits(uint8_t b);
void save_8bit_width(uint8_t char_code, uint8_t font_row, uint8_t fore, uint8_t back);
void save_9bit_width(uint8_t char_code, uint8_t font_row, uint8_t fore, uint8_t back);
void die(char*);
void ordie(char*);


#define CHAR_COUNT  256
#define CHAR_HEIGHT 32

/* font data */
uint8_t font[CHAR_COUNT][CHAR_HEIGHT];

/* palette data */
uint8_t palette[16][3] = {
	{  0,   0,   0},
	{170,   0,   0},
	{  0, 170,   0},
	{170,  85,   0},
	{  0,   0, 170},
	{170,   0, 170},
	{  0, 170, 170},
	{170, 170, 170},
	{ 85,  85,  85},
	{255,  85,  85},
	{ 85, 255,  85},
	{255, 255,  85},
	{ 85,  85, 255},
	{255,  85, 255},
	{ 85, 255, 255},
	{255, 255, 255}
};


void usage() {
	fputs(
		"Program save contents of console in PNM file\n"
		"(PNM is printed on standard output\n"
		"\n"
		"usage:\n"
		"\tttyscreenshot [8|9] console-num\n"
		"\n"
		"First argument is a character width in pixels;\n"
		"9 pixels is a default width use by EGA/VGA cards,\n"
		"8 pixels isn't.\n"
		"\n"
		"You need permissions to read /dev/vcsa[console-num] device.\n"
		"\n"
		"Author: Wojciech Mu³a, http://www.republika.pl/wmula//\n",
		
		stderr
	);
	exit(EXIT_FAILURE);
}


int main(int argv, char* argc[]) {

	int fd;
	struct consolefontdesc dsc;
	char path[PATH_MAX];
	save_fun save;
	
	int  char_width, console_num;	/* program arguments */
	uint8_t lines, columns;			/* dimensions of console */

	/* aux vars: */
	uint8_t c, attr, fore, back;
	int  col, line, y;
	uint8_t* char_row;


	/* 1. Parse program arguments */
	if (argv < 3)
		usage();

	char_width = atoi(argc[1]);
	if (char_width != 8 && char_width != 9)
		die("First argument (character width) must be either 8 or 9.");

	console_num = atoi(argc[2]);
	if (console_num < 0 || console_num > 63)
		die("Second argument (console number) must lie in range 0..63");


	/* 2. Load fonts */
	snprintf(path, PATH_MAX, "/dev/tty%d", console_num);
	fd = open(path, O_RDWR); ordie("open(tty)");

	dsc.charcount	= CHAR_COUNT;
	dsc.charheight	= CHAR_HEIGHT;
	dsc.chardata	= (void*)font;
	ioctl(fd, GIO_FONTX, &dsc); ordie("ioctl(GIO_FONTX)");

	/* 3. Load palette */
	ioctl(fd, GIO_CMAP, &palette);
	if (errno) {
		fprintf(stderr, "Can't load palette, using defaults.  Reason [errno=%d]: %s\n", errno, strerror(errno));
		errno = 0;
	}
		
	close(fd); ordie("close(tty)");

	/* 4. Get dimensions of console */
	snprintf(path, PATH_MAX, "/dev/vcsa%d", console_num);
	fd = open(path, O_RDWR); ordie("open(vcsa)");

	read(fd, &lines, 1);   ordie("read(lines)");
	read(fd, &columns, 1); ordie("read(columns)");

	/* 5. Allocate cache memory for a chars row */
	char_row = (uint8_t*)malloc(columns*2);
	if (char_row == NULL)
		die("malloc failed");
	
	lseek(fd, 4, SEEK_SET);

	/* 6. Save image */
	if (char_width == 8)
		save = save_8bit_width;
	else
		save = save_9bit_width;


	printf("P6\n%d %d\n255\n", columns*char_width, lines*16);
	for (line=0; line < lines; line++) {
		/* load whole character row */
		read(fd, char_row, columns*2);

		/* process each line of font data */
		for (y=0; y < 16; y++) {
			for (col=0; col < columns*2; col+=2) {
				c    = char_row[col];   /* get charcode */
				attr = swapbits(char_row[col+1]); /* get attribute - order of bits have to be fixed */

				fore = attr & 0x0f; /* from attribute extract foreground color */
				back = attr >> 4;   /* and background color */
				save(c, font[c][y], fore, back);
			}
		}
	}

	free(char_row);
	close(fd);

	return 0;
}


uint8_t swapbits(uint8_t b) {
	/* input:  8-bit number (bits order in a nibble: 3,2,1,0) */
	/* output: 8-bit number (bits order in a nibble: 3,0,1,2) */
	return (b & 0xaa) | ((b & 0x44) >> 2) | ((b & 0x11) << 2);
}


void save_8bit_width(uint8_t char_code, uint8_t font_row, uint8_t fore, uint8_t back) {
	uint8_t mask;
	for (mask = 0x80; mask != 0; mask >>= 1) {
		if (font_row & mask)
			fwrite(&palette[fore][0], 3, 1, stdout);
		else
			fwrite(&palette[back][0], 3, 1, stdout);
	}
}


void save_9bit_width(uint8_t char_code, uint8_t font_row, uint8_t fore, uint8_t back) {
	save_8bit_width(char_code, font_row, fore, back);

	/* repeat last column of some characters */
	if (char_code >= 0xbf && char_code <= 0xdf && (font_row & 0x01))
		fwrite(&palette[fore][0], 3, 1, stdout);
	else
		fwrite(&palette[back][0], 3, 1, stdout);
}


void ordie(char* info) {
	if (errno != 0) {
		fprintf(stderr, "%s [errno=%d]: %s\n", info, errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

void die(char* info) {
	fprintf(stderr, "%s\n", info);
	exit(EXIT_FAILURE);
}

/*
vim: ts=4 sw=4 nowrap noexpandtab
*/
