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

void ordie(char* info) {
	if (errno != 0) {
		fprintf(stdout, "%s [errno=%d]: %s\n", info, errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

typedef unsigned char byte;
typedef unsigned short int word;

byte font[256][32];

byte palette[16][3] = {
	{   0,    0,    0}, // black
	{   0,    0,  255}, // blue
	{   0,  139,    0}, // dark green
	{   0,  139,  139}, // dark cyan
	{ 139,    0,    0}, // dark red
	{ 139,    0,  139}, // dark magenta
	{ 255,   64,   64}, // brown
	{ 211,  211,  211}, // light gray
	{ 169,  169,  169}, // dark gray
	{ 173,  216,  230}, // light blue
	{ 144,  238,  144}, // light green
	{ 224,  255,  255}, // light cyan
	{ 255,    0,    0}, // light red
	{ 255,    0,  255}, // light magenta
	{ 255,  255,    0}, // yellow
	{ 255,  255,  255}  // white
};

void get_EGA_font(unsigned char font[256][32]) {
	struct consolefontdesc dsc;
	int tty = open("/dev/tty", O_RDWR); ordie("open");
	int i;
	
	dsc.charcount	= 256;
	dsc.charheight	= 16;
	dsc.chardata	= (void*)font;
	ioctl(tty, GIO_FONTX, &dsc); ordie("ioctl(GIO_FONTX)");

	ioctl(tty, GIO_CMAP, &palette); ordie("ioctl(GIO_CMAP)");
	close(tty); ordie("close");
}


byte swapbits(byte b) {
	// input:  8-bit number (bits order in a nibble: 3,2,1,0)
	// output: 8-bit number (bits order in a nibble: 3,0,1,2)
	return (b & 0xaa) | ((b & 0x44) >> 2) | ((b & 0x11) << 2);
}


void expand8(byte b, byte fore, byte back) {
	byte mask = 0x80;
	while (mask) {
		if (b & mask)
			fwrite(&palette[fore][0], 3, 1, stdout);
		else
			fwrite(&palette[back][0], 3, 1, stdout);
		mask >>= 1;
	}
}


void usage() {
	puts("usage...");
	exit(EXIT_FAILURE);
}


int main(int argv, char* argc[]) {
	int vcsa;
	byte lines, columns, c, attr, fore, back;
	
	unsigned int col, line, y;
	int cw, term;
	char path[PATH_MAX];
	byte* char_row;
	
	get_EGA_font(font);
	int i;

	if (argv < 3)
		usage();

	cw = atof(argc[1]);
	if (cw != 8 && cw != 9)
		usage();

	term = atof(argc[2]);
	snprintf(path, PATH_MAX, "/dev/vcsa%d", term);
	vcsa = open(path, O_RDWR); ordie("open");

	read(vcsa, &lines, 1);   ordie("read(lines)");
	read(vcsa, &columns, 1); ordie("read(columns)");

	char_row = (byte*)malloc(columns*2); ordie("malloc");
	if (char_row == NULL) {
		errno=1;
		ordie("malloc");
	}
	
	printf("P6\n%d %d\n255\n", columns*cw, lines*16);

	lseek(vcsa, 4, SEEK_SET);

	if (cw == 8)
		for (line=0; line < lines; line++) {
			read(vcsa, char_row, columns*2);
			for (col=1; col < columns*2; col+=2) 
				char_row[col] = swapbits(char_row[col]);

			for (y=0; y < 16; y++) {
				for (col=0; col < columns*2; col+=2) {
					c = char_row[col];
					attr = char_row[col+1];

					fore = attr & 0x0f;
					back = attr >> 4;
					expand8(font[c][y], fore, back);
				}
			}
		}
	else
		for (line=0; line < lines; line++) {
			read(vcsa, char_row, columns*2);
			for (col=1; col < columns*2; col+=2) 
				char_row[col] = swapbits(char_row[col]);

			for (y=0; y < 16; y++) {
				for (col=0; col < columns*2; col+=2) {
					c = char_row[col];
					attr = char_row[col+1];
					
					fore = attr & 0x0f;
					back = attr >> 4;
					
					expand8(font[c][y], fore, back);
					
					if (c >= 0xbf && c <= 0xdf && (font[c][y] & 0x01))
						fwrite(&palette[fore][0], 3, 1, stdout);
					else
						fwrite(&palette[back][0], 3, 1, stdout);
				}
			}
		}

	close(vcsa);
	return 0;
}

/*
vim: ts=4 sw=4 nowrap noexpandtab
*/
