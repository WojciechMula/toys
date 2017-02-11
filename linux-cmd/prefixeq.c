/*
	Program check if two file has common prefix.
	
	prefixeq file1 file2 size

	is equivalent to

	head -b size file1 > /tmp/1
	head -b size file2 > /tmp/2
	cmp /tmp/1 /tmp/2


	Wojciech Mu³a, 2009-12-25
	public domain
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
	FILE* file1;
	FILE* file2;
	char  buf1[BUF_SIZE];
	char  buf2[BUF_SIZE];
	int   size;
	int   read;
	size_t readed1;
	size_t readed2;
	char* err;
	int   result;

	if (argc < 4) {
		puts("usage: cmpprefix file2 file1 size");
		return EXIT_FAILURE;
	}
	
	size = strtol(argv[3], &err, 0);
	if (*err != '\0') {
		fprintf(stderr,
			"invalid digit '%c' at position %d\n",
			*err,
			err - &argv[3][0]
		);
		return EXIT_FAILURE;
	}
	else
	if (size < 0) {
		fprintf(stderr, "size less then zero\n");
		return EXIT_FAILURE;
	}
	else
	if (size == 0) {
		fprintf(stderr, "size equal zero\n");
		return EXIT_FAILURE;
	}

	errno = 0;
	file1 = fopen(argv[1], "rb");
	if (errno) {
		fprintf(stderr, "Can't open file 1 '%s' (err=%d): %s\n",
			argv[1],
			errno,
			strerror(errno)
		);
		return EXIT_FAILURE;
	}

	file2 = fopen(argv[2], "rb");
	if (errno) {
		fprintf(stderr, "Can't open file 1 '%s' (err=%d): %s\n",
			argv[1],
			errno,
			strerror(errno)
		);
		fclose(file1);
		return EXIT_FAILURE;
	}
	
	result = EXIT_SUCCESS;
	while (size > 0) {
		read = (size < BUF_SIZE) ? size : BUF_SIZE;
		readed1 = fread(buf1, 1, read, file1);
		if (errno) {
			fprintf(stderr, "Can't read from file 1 '%s' (err=%d): %s\n",
				argv[1],
				errno,
				strerror(errno)
			);
			result = EXIT_FAILURE;
			goto cleanup;
		}

		readed2 = fread(buf2, 1, read, file2);
		if (errno) {
			fprintf(stderr, "Can't read from file 2 '%s' (err=%d): %s\n",
				argv[2],
				errno,
				strerror(errno)
			);
			result = EXIT_FAILURE;
			goto cleanup;
		}

		if (readed1 != read || readed2 != read) {
			/* different sizes */
			result = EXIT_FAILURE;
			goto cleanup;
		}
		else
		if (memcmp(buf1, buf2, read) != 0) {
			result = EXIT_FAILURE;
			goto cleanup;
		}
		else
			size -= read;
	} 

cleanup:
	fclose(file1);
	fclose(file2);
	return result;
}
/*------------------------------------------------------------------------*/

