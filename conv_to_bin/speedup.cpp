/*
	Convert to binary representation - measure speedup over naive version

	Author  : Wojciech Muła
	Date    : 2014-09-16
	License : BSD
*/


#include <cstdio>
#include <cstdint>
#include <cstring>
#include <assert.h>
#include <string>

#include <sys/time.h>

#include "conv_to_bin.cpp"

// ------------------------------------------------------------------------

class measure_item_t {
    const std::string name;
    uint32_t t1, t2;

public:
    measure_item_t(const std::string& name) : name(name) {}

public:
    void print() const {
        std::printf("%20s: %10.4fs\n", name.c_str(), get_time());
    }

    void print(const measure_item_t& other) const {
        std::printf("%20s: %10.4fs (speedup: %0.2f)\n", name.c_str(), get_time(), other.get_time()/get_time());
    }

	double get_time() const {
		return (t2 - t1)/1000000.0;
	}

	void start() {
		t1 = get_time();
	}

	void stop() {
		t2 = get_time();
	}

private:
	uint32_t get_time(void) {
		static struct timeval T;
		gettimeofday(&T, NULL);
		return (T.tv_sec * 1000000) + T.tv_usec;
	}
};




template <typename F>
measure_item_t measure(F function, int iterations, const std::string& name) {
    std::printf("measure %s... ", name.c_str());
    std::fflush(stdout);

	measure_item_t m(name);

	m.start();

    uint8_t byte = 0;
    while (iterations-- > 0) {
        function(byte);
		byte += 33;
    }

    m.stop();

    std::printf("ok\n");

    return m;
}


void measure() {
    const int  n  = 10000000;

    const auto m1 = measure(convert_to_bin::naive,  n, "naive");
    const auto m2 = measure(convert_to_bin::lookup, n, "lookup");
    const auto m3 = measure(convert_to_bin::swar,   n, "SWAR");
    const auto m4 = measure(convert_to_bin::simd,   n, "SIMD");

	std::puts("");
	std::puts("results:");

    m1.print();
    m2.print(m1);
    m3.print(m1);
    m4.print(m1);
}


// ------------------------------------------------------------------------


int main() {

	convert_to_bin::prepare_lookup();
    measure();
}

