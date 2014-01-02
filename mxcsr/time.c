#include <sys/time.h>
#include <stdint.h>

uint32_t get_time(void) {
        static struct timeval T;
        gettimeofday(&T, NULL);
        return (T.tv_sec * 1000000) + T.tv_usec;
}

