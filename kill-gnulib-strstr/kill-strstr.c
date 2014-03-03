#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

uint32_t get_time(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}

double strstr_wrapper(char* data, char* substr) {
	uint32_t t1 = get_time();

	char* c = strstr(data, substr);

	uint32_t t2 = get_time();

	return (t2 - t1)/1000000.0;
}

int main(int argc, char* argv[]) {

	if (argc == 1)
		return EXIT_SUCCESS;

	const uint32_t MiB  = 1024*1024;
	const uint32_t size = 16*MiB;

	char* buffer = (char*)malloc(size);

	if (buffer == NULL)
		return EXIT_FAILURE;

	memset(buffer, '?', size);
	buffer[size - 1] = '\0';

	for (int i=1; i < argc; i++) {
		printf("searching string '%s'... ", argv[i]);
		fflush(stdout);
		const double dt = strstr_wrapper(buffer, argv[i]);

		printf("time: %0.3f\n", dt);
	}

	free(buffer);
	return EXIT_SUCCESS;
}
