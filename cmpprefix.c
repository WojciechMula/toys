/*

	Program checks if file starts with string.
	Nonprintable chars can be passed in format
	\xhh where h is an hex digit.

	Example:

	cmpprefix file "\xff\xd8\xff\xe0\x00\x10JFIF" && echo "JPEG without EXIF"

	Wojciech Mu³a, 2009-12-25
	public domain

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int parse_string(char* input, char* otput);
void safe_print(char* string, int len);
void help();

int main(int argc, char* argv[]) {

	FILE* input;
	char* string;
	char* buf;
	int  len;
	int  result;

	if (argc < 3) {
		help();
		return EXIT_FAILURE;
	}
	
	len = strlen(argv[2]);
	if (len == 0) {
		fprintf(stderr, "empty string\n");
		return EXIT_FAILURE;
	}
	
	string = malloc(len+1);
	if (string == NULL) {
		fprintf(stderr, "can't allocate %d byte(s)\n", len+1);
		return EXIT_FAILURE;
	}
	
	/* any escapes? */
	len = parse_string(argv[2], string);
#ifdef DEBUG
	printf("len = %d, ", len);
	safe_print(string, len);
	putchar('\n');
#endif

	buf = malloc(len);
	if (buf == NULL) {
		free(string);
		fprintf(stderr, "can't allocate %d byte(s)\n", len);
		return EXIT_FAILURE;
	}

	errno = 0;
	input = fopen(argv[1], "rb");
	if (errno) {
		fprintf(stderr, "Can't open file '%s' (err=%d): %s\n",
			argv[1],
			errno,
			strerror(errno)
		);
		free(string);
		free(buf);
		return EXIT_FAILURE;
	}
	
	result = EXIT_SUCCESS;
	if (fread(buf, 1, len, input) != len) {
		/* file shorter then string */
		result = EXIT_FAILURE;
		goto cleanup;
	}

	if (memcmp(string, buf, len) == 0) {
		result = EXIT_SUCCESS;
		goto cleanup;
	}
	else {
		result = EXIT_FAILURE;
		goto cleanup;
	}
cleanup:
	free(string);
	free(buf);
	fclose(input);
	return result;
}
/*------------------------------------------------------------------------*/

void help() {
	puts("usage: cmpprefix file string");
	puts("");
	puts("Program checks if file starts with string.");
	puts("Nonprintable chars can be passed in format");
	puts("\\xhh where h is a hex digit.");
	puts("");
	puts("Example:");
	puts("");
	puts("cmpprefix file \"\\xff\\xd8\\xff\\xe0\\x00\\x10JFIF\" && echo \"JPEG without EXIF\"");
}
/*------------------------------------------------------------------------*/

int hexval(const char c) {
	if (c >= '0' && c <= '9')
		return c - '0';
	else
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	else
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	else
		return -1;
}
/*------------------------------------------------------------------------*/

int parse_string(char* input, char* output) {
	char* c = input;
	char* o = output;
	
	int h1, h2;
	
	while (*c) {
		/* parse escape sequence \xhh */
		if ( c[0] == '\\' &&
		    (c[1] == 'x' || c[1] == 'X') &&
		    (h2=hexval(c[2])) != -1 && 
		    (h1=hexval(c[3])) != -1
		) {
			*o++ = h2*16 + h1;
			c += 4;
			continue;
		}

		/* or just copy char */
		*o++ = *c++;
	}
	*o = 0;

	return (o - output);
}
/*------------------------------------------------------------------------*/

void safe_print(char* c, int n) {
	int i;
	if (n <= 0)
		return;

	for (i=0; i < n; i++, c++) {
		if (isprint(*c))
			putchar(*c);
		else
			printf("<%02x>", (unsigned char)(*c));
	}
}
/*------------------------------------------------------------------------*/

