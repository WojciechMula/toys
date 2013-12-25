/*

	Program test how C stdlib handles directories opened
	with function fopen.

	Compilation:

	$ gcc -Wall fopen_directory.c -o your_favorite_name

	Usage:

	$ ./your_favorite_name directory_path

	Author  : Wojciech Muła
	Date    : 2013-12-25
	License : public domain

*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h> // for strerror

void fopen_directory(const char* path);
void print_errno(const char* prefix);

int main(int argc, char* argv[]) {
	int i;
	if (argc > 1) {
		for (i=1; i < argc; i++)
			fopen_directory(argv[i]);

		return EXIT_SUCCESS;
	} else {
		printf("usage: %s directory\n", argv[0]);

		return EXIT_FAILURE;
	}
}


void fopen_directory(const char* path) {
	FILE* f;

	printf("testing '%s'...\n", path);

	print_errno("fopen");
	f = fopen(path, "rb");
	if (f == NULL) {
		return;
	}

	int seek_res = fseek(f, 0, SEEK_END);
	print_errno("fseek");
	printf("fseek result: %d\n", seek_res);

	long tell_res = ftell(f);
	print_errno("ftell");
	printf("ftell result: %ld\n", tell_res);

	int feof_res = feof(f);
	print_errno("feof");
	printf("feof result: %d (EOF=%s)\n", feof_res, feof_res == EOF ? "yes" : "no");

	int fgetc_res = fgetc(f);
	print_errno("fgetc");
	printf("fgetc result: %d (EOF=%s)\n", fgetc_res, fgetc_res == EOF ? "yes" : "no");

	char fread_buffer[1024];
	int fread_result = fread(fread_buffer, 1024, 1, f);
	print_errno("fread");
	printf("fread result: %d\n", fread_result);
}

void print_errno(const char* prefix) {
	printf("%s: %s [errno=%d]\n", prefix, strerror(errno), errno);
}
