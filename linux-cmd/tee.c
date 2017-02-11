/*
	tee implementation

	Author: Wojciech Mu³a
	e-mail: wojciech_mula@poczta.onet.pl
	www:    http://0x80.pl/

	License: public domain

	$Id$
*/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifndef __cplusplus
	typedef char bool;
#	define true  1
#	define false 0
#endif

struct file_t {
	FILE*	file;
	bool	exit_on_failure;
	char*	name;
};

#define BUF_SIZE 4096
char buffer[BUF_SIZE];

void tee(struct file_t* input, struct file_t* files, int count);

int main(int argc, char* argv[]) {
	struct file_t	input;
	struct file_t*	files;
	size_t  requested_size;
	int	i, count;
	bool	exit_on_failure = false;

	requested_size = sizeof(struct file_t) * argc;
	files = malloc(requested_size);
	if (files == NULL) {
		fprintf(stderr, "Can't allocate %u byte(s)\n", requested_size);
		exit(EXIT_FAILURE);
	}

	input.file = stdin;
	input.name = "<stdin>";
	input.exit_on_failure = false;

	count = 1;
	files[0].file = stdout;
	files[0].name = "<stdout>";
	files[0].exit_on_failure = true;

	for (i=1; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0)
			exit_on_failure = false;
		else
		if (strcmp(argv[i], "-e") == 0)
			exit_on_failure = true;
		else {
			errno = 0;
			files[count].file = fopen(argv[i], "wb");
			files[count].name = argv[i];
			files[count].exit_on_failure = exit_on_failure;
			if (errno) {
				fprintf(stderr, "Can't open file %s: %s\n", argv[i], strerror(errno));
				if (exit_on_failure)
					exit(EXIT_FAILURE);
			}
			else
				count += 1;
		}
	} // for

	// do the job
	tee(&input, files, count);

	// clean up
	for (i=1; i < count; i++)
		fclose(files[i].file);

	free(files);

	return EXIT_SUCCESS;

}
//---------------------------------------------------------------------------

void tee(struct file_t* input, struct file_t* files, int count) {
	int i;
	size_t readed;
	while (1) {
		errno = 0;
		readed = fread(buffer, 1, BUF_SIZE, input->file);
		if (readed == 0)
			break;
		if (errno) {
			fprintf(stderr, "can't read from %s: %s\n", input->name, strerror(errno));
			if (input->exit_on_failure)
				exit(EXIT_FAILURE);

			continue;
		}

		for (i=0; i < count; i++) {
			errno = 0;
			fwrite(buffer, 1, readed, files[i].file);
			if (errno) {
				fprintf(stderr, "can't write to %s: %s\n", files[i].name, strerror(errno));
				if (files[i].exit_on_failure)
					exit(EXIT_FAILURE);
			}
		}
	}
}
//---------------------------------------------------------------------------
