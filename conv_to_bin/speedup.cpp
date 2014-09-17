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
#include <vector>

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

    std::vector<measure_item_t> results;

    results.push_back(measure(convert_to_bin::naive,  n, "naive"));
    results.push_back(measure(convert_to_bin::lookup, n, "lookup"));
    results.push_back(measure(convert_to_bin::swar,   n, "SWAR"));
    results.push_back(measure(convert_to_bin::simd,   n, "SIMD"));
#if defined(HAVE_PDEP_INSTRUCTION)
    results.push_back(measure(convert_to_bin::pdep,   n, "PDEP"));
#endif

    std::puts("");
    std::puts("results");

    for (const auto& m: results) {
        m.print(results.front());
    }
}


// ------------------------------------------------------------------------


int main() {

	convert_to_bin::prepare_lookup();
    measure();
}

