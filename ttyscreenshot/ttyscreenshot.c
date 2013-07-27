/*
	$Date: 2008-06-21 18:28:37 $, $Revision: 1.6 $
	
	Grab tty as image (PNM)

	License: public domain

	compile:
		gcc -O2 ttyscreenshot.c -o ttyscreenshot
	
	
	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl
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

/* aux functions */
uint8_t swapbits(uint8_t b);
void expandbits(uint8_t b, uint8_t fore, uint8_t back);
void die(char*);
void ordie(char*);


/* font data */
uint8_t font[256][32];

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

	dsc.charcount	= 256;
	dsc.charheight	= 16;
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
	
	printf("P6\n%d %d\n255\n", columns*char_width, lines*16);

	lseek(fd, 4, SEEK_SET);

	if (char_width == 8)
		for (line=0; line < lines; line++) {

			/* load whole character row */
			read(fd, char_row, columns*2);
			for (col=1; col < columns*2; col+=2) 
				char_row[col] = swapbits(char_row[col]);

			/* process each line of font data */
			for (y=0; y < 16; y++) {
				for (col=0; col < columns*2; col+=2) {
					c    = char_row[col];   /* get charcode */
					attr = char_row[col+1]; /* get attribute */

					fore = attr & 0x0f; /* from attribute extract foreground color */
					back = attr >> 4;   /* and background color */
					expandbits(font[c][y], fore, back);
				}
			}
		}
	else
		for (line=0; line < lines; line++) {
			read(fd, char_row, columns*2);
			for (col=1; col < columns*2; col+=2) 
				char_row[col] = swapbits(char_row[col]);

			for (y=0; y < 16; y++) {
				for (col=0; col < columns*2; col+=2) {
					c = char_row[col];
					attr = char_row[col+1];
					
					fore = attr & 0x0f;
					back = attr >> 4;
					
					expandbits(font[c][y], fore, back);
				
					/* repeat last column of some characters */
					if (c >= 0xbf && c <= 0xdf && (font[c][y] & 0x01))
						fwrite(&palette[fore][0], 3, 1, stdout);
					else
						fwrite(&palette[back][0], 3, 1, stdout);
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


void expandbits(uint8_t b, uint8_t fore, uint8_t back) {
	uint8_t mask = 0x80;
	while (mask) {
		if (b & mask)
			fwrite(&palette[fore][0], 3, 1, stdout);
		else
			fwrite(&palette[back][0], 3, 1, stdout);
		mask >>= 1;
	}
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
