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

void get_EGA_font(unsigned char font[256][32]) {
	struct consolefontdesc dsc;
	int tty = open("/dev/tty", O_RDWR); ordie("open");
	
	dsc.charcount	= 256;
	dsc.charheight	= 16;
	dsc.chardata	= (void*)font;
	ioctl(tty, GIO_FONTX, &dsc); ordie("ioctl(GIO_FONTX)");
	close(tty); ordie("close");
}

typedef unsigned char byte;

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

void expand8(byte b, byte fore, byte back) {
	byte mask = 0x80;
	byte i;

	while (mask) {
		if (b & mask)
			for (i=0; i<3; i++)
				putchar(palette[fore][i]);
		else
			for (i=0; i<3; i++)
				putchar(palette[back][i]);
		mask >>= 1;
	}
}

void expand9(byte b, char repeat, byte fore, byte back) {
	byte i;

	expand8(b, fore, back);

	if (repeat && (b & 0x80))
		for (i=0; i<3; i++)
			putchar(palette[fore][i]);
	else
		for (i=0; i<3; i++)
			putchar(palette[back][i]);
}

void usage() {
	puts("usage...");
	exit(EXIT_FAILURE);
}


int main(int argv, char* argc[]) {
	get_EGA_font(font);
	FILE* vcsa;
	unsigned int lines, columns;
	unsigned int col, line, y, c, attr;
	int cw, term;
	char path[PATH_MAX];

	if (argv < 3)
		usage();

	cw = atof(argc[1]);
	if (cw != 8 && cw != 9) {
		usage();
	}

	term = atof(argc[2]);
	snprintf(path, PATH_MAX, "/dev/vcsa%d", term);
	vcsa = fopen(path, "r"); ordie("fopen");

	lines   = getc(vcsa);
	columns = getc(vcsa);

	printf("P6\n%d %d\n255\n", columns*cw, lines*16);

	if (cw == 8)
		for (line=0; line < lines; line++) {
			for (y=0; y < 16; y++) {
				fseek(vcsa, 4 + line*columns*2, SEEK_SET);
				for (col=0; col < columns; col++) {
					c = getc(vcsa);
					attr = getc(vcsa);
					expand8(font[c][y], attr & 0x0f, (attr >> 4) & 0x07);
				}
			}
		}
	else
		for (line=0; line < lines; line++) {
			for (y=0; y < 16; y++) {
				fseek(vcsa, 4 + line*columns*2, SEEK_SET);
				for (col=0; col < columns; col++) {
					c = getc(vcsa);
					attr = getc(vcsa);
					if ((c > 0xbf) && (c <= 0xdf))
						expand9(font[c][y], 1, attr & 0x0f, (attr >> 4) & 0x07);
					else
						expand9(font[c][y], 0, attr & 0x0f, (attr >> 4) & 0x07);
				}
			}
		}

	fclose(vcsa);
	return 0;
}

/*
vim: ts=4 sw=4 nowrap noexpandtab
*/
