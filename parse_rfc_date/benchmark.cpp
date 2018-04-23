#include "benchmark.h"
#include "sse.cpp"
#include "scalar.cpp"

#include <ctime>
#include <cstring>
#include <cstdlib>
#include <locale>

#define SIZE 1024
char input[SIZE][32];

int randint(int min, int max) {
    return rand() % (max - min) + min;
}

void prepare_data() {
    std::tm time;

    memset(input, 0, sizeof(input));

    for (size_t i=0; i < SIZE; i++) {
        time.tm_sec  = randint(0, 59);
        time.tm_min  = randint(0, 59);
        time.tm_hour = randint(1, 24);
        time.tm_mday = randint(1, 31);
        time.tm_mon  = randint(0, 11);
        time.tm_year = randint(0, 1000);
        time.tm_wday = randint(0, 6);

        std::strftime(input[i], 30, "%a, %d %b %Y %H:%M:%S GMT", &time);
    }
}


volatile int global_result = 0;


void benchmark_scalar() {
    std::tm fields;
    global_result = 0;
    for (size_t i=0; i < SIZE; i++) {
        global_result += parse_rfc_date_reference(input[i], &fields);
    }
}


void benchmark_SSE() {
    std::tm fields;
    global_result = 0;
    for (size_t i=0; i < SIZE; i++) {
        global_result += parse_rfc_date(input[i], &fields);
    }
}


int main() {

    std::srand(0);
    prepare_data();

    const size_t iterations = 1000;
    const size_t size = SIZE;

    BEST_TIME(/**/, benchmark_scalar(), "scalar", iterations, size);
    BEST_TIME(/**/, benchmark_SSE(),    "SSE",    iterations, size); 
}
