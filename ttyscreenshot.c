#include <stdlib.h>
#include <stdio.h>
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
typedef unsigned char byte;

/* aux functions */
byte swapbits(byte b);
void expandbits(byte b, byte fore, byte back);
void die(char*);
void ordie(char*);


/* font data */
byte font[256][32];

/* palette data */
byte palette[16][3] = {
	{   0,    0,    0}, /* black */
	{   0,    0,  255}, /* blue */
	{   0,  139,    0}, /* dark green */
	{   0,  139,  139}, /* dark cyan */
	{ 139,    0,    0}, /* dark red */
	{ 139,    0,  139}, /* dark magenta */
	{ 255,   64,   64}, /* brown */
	{ 211,  211,  211}, /* light gray */
	{ 169,  169,  169}, /* dark gray */
	{ 173,  216,  230}, /* light blue */
	{ 144,  238,  144}, /* light green */
	{ 224,  255,  255}, /* light cyan */
	{ 255,    0,    0}, /* light red */
	{ 255,    0,  255}, /* light magenta */
	{ 255,  255,    0}, /* yellow */
	{ 255,  255,  255}  /* white */
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
		"You need permissions to read /dev/vcsa[console-num] device",
		
		stderr
	);
	exit(EXIT_FAILURE);
}


int main(int argv, char* argc[]) {

	int fd;
	struct consolefontdesc dsc;
	char path[PATH_MAX];
	
	int  char_width, console_num;	/* program arguments */
	byte lines, columns;			/* dimensions of console */

	/* aux vars: */
	byte c, attr, fore, back;
	int  col, line, y;
	byte* char_row;


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
	ioctl(fd, GIO_CMAP, &palette); ordie("ioctl(GIO_CMAP)");
	close(fd); ordie("close(tty)");

	/* 4. Get dimensions of console */
	snprintf(path, PATH_MAX, "/dev/vcsa%d", console_num);
	fd = open(path, O_RDWR); ordie("open(vcsa)");

	read(fd, &lines, 1);   ordie("read(lines)");
	read(fd, &columns, 1); ordie("read(columns)");

	/* 5. Allocate cache memory for a chars row */
	char_row = (byte*)malloc(columns*2);
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


byte swapbits(byte b) {
	/* input:  8-bit number (bits order in a nibble: 3,2,1,0) */
	/* output: 8-bit number (bits order in a nibble: 3,0,1,2) */
	return (b & 0xaa) | ((b & 0x44) >> 2) | ((b & 0x11) << 2);
}


void expandbits(byte b, byte fore, byte back) {
	byte mask = 0x80;
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
