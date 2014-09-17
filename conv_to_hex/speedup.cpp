/*
	Convert to hexadecimal representation - measure speedup over naive version

	Author  : Wojciech Muła
	Date    : 2014-09-17
	License : BSD
*/


#include <string>
#include <vector>
#include <sys/time.h>


#include "conv_to_hex.c"
#include "expand_nibble.c"


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


template <typename F1, typename F2>
measure_item_t measure(F1 expand, F2 convert, int iterations, const std::string& name) {
    std::printf("measure %s... ", name.c_str());
    std::fflush(stdout);

	measure_item_t m(name);

	m.start();

    uint16_t word = 0;
    while (iterations-- > 0) {
        convert(expand(word));
		word += 33;
    }

    m.stop();

    std::printf("ok\n");

    return m;
}


void measure() {
    const int  n  = 10000000;

    std::vector<measure_item_t> results;

    results.push_back(measure(nibble_expand_naive, nibbles_to_hex_naive, n, "naive/naive"));
    results.push_back(measure(nibble_expand_naive, nibbles_to_hex_swar,  n, "naive/swar"));
    results.push_back(measure(nibble_expand_naive, nibbles_to_hex_simd,  n, "naive/simd"));

    results.push_back(measure(nibble_expand_mul, nibbles_to_hex_naive, n, "mul/naive"));
    results.push_back(measure(nibble_expand_mul, nibbles_to_hex_swar,  n, "mul/swar"));
    results.push_back(measure(nibble_expand_mul, nibbles_to_hex_simd,  n, "mul/simd"));

    results.push_back(measure(nibble_expand_simd, nibbles_to_hex_naive, n, "simd/naive"));
    results.push_back(measure(nibble_expand_simd, nibbles_to_hex_swar,  n, "simd/swar"));
    results.push_back(measure(nibble_expand_simd, nibbles_to_hex_simd,  n, "simd/simd"));

	std::puts("");
	std::puts("results:");

    for (const auto& m: results) {
        m.print(*results.begin());
    }
}


// ------------------------------------------------------------------------


int main() {

    measure();
}

