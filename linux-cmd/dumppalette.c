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

void ordie(char*);


int main() {
	byte palette[16][3];
	int fd, i;

	/* 1. Load palette */
	fd = open("/dev/tty", O_RDWR); ordie("open(tty)");

	ioctl(fd, GIO_CMAP, &palette); ordie("ioctl(GIO_CMAP)");
	close(fd); ordie("close(tty)");

	for (i=0; i < 16; i++)
		printf("%2d: %3d, %3d, %3d\n", i, palette[i][0], palette[i][1], palette[i][2]);

	return 0;
}


void ordie(char* info) {
	if (errno != 0) {
		fprintf(stderr, "%s [errno=%d]: %s\n", info, errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

/*
vim: ts=4 sw=4 nowrap noexpandtab
*/
