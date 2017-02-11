/*
	wm/2009-11-13
	public domain

*/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

size_t parse_number(char* str, char* name);

#define BUF_SIZE 4096
char buffer[BUF_SIZE];

int main(int argc, char* argv[]) {
	FILE* file;
	size_t offset;
	size_t count;
	size_t readed;

	if (argc != 4) {
		puts("Copy from given file to stdout count bytes starting at offset");
		printf("usage: %s file offset count\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	offset	= parse_number(argv[2], "offset");
	count	= parse_number(argv[3], "count");

	/* try open file */
	errno	= 0;
	file	= fopen(argv[1], "rb");
	if (errno)
		perror("Can't open file");

	/* seek to offset */
	fseek(file, offset, SEEK_SET);
	if (errno)
		perror("Can't seek to given position");

	/* copy to stdout count bytes */
	while (1) {
		if (count > BUF_SIZE)
			readed = fread(buffer, 1, BUF_SIZE, file);
		else
			readed = fread(buffer, 1, count, file);

		if (readed == 0)
			break;
	
		if (errno)
			perror("Can't read from file");

		fwrite(buffer, 1, readed, stdout);
		if (errno)
			perror("Can't write to stdout");

		count -= readed;
	}

	fclose(file);
	if (errno)
		perror("Can't close file");

	exit(EXIT_SUCCESS);
}
/*------------------------------------------------------------------------*/

size_t parse_number(char* str, char* name) {
	size_t result;
	char* err;

	errno	= 0;
	result	= strtoul(str, &err, 0);
	if (errno)
		perror(name);
	else
	if (*err != '\0') {
		fprintf(stderr, "%s: invalid number\n", name);
		exit(EXIT_FAILURE);
	}

	return result;
}
/*------------------------------------------------------------------------*/

