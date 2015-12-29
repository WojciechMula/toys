#include <time.h>
#include <sys/time.h>

unsigned get_time() {
	struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}
