/*
	Convert to hexadecimal representation - measure speedup over naive version

	Author  : Wojciech Muła
	Date    : 2014-09-17
	License : BSD
*/


#include <string>
#include <vector>
#include <sys/time.h>


#include "common.c"
#include "conv_to_hex.c"
#include "expand_nibble.c"


class measure_item_t {
    uint32_t t1;
    uint32_t t2;

public:
    const std::string expand_name;
    const std::string convert_name;

public:
    measure_item_t(const std::string& expand_name, const std::string& convert_name)
        : expand_name(expand_name)
        , convert_name(convert_name)
        {}

public:
	double get_time() const {
		return (t2 - t1)/1000000.0;
	}

    double get_speedup(const measure_item_t& other) const {
        return other.get_time()/get_time();
    }

	void start() {
		t1 = get_current_time();
	}

	void stop() {
		t2 = get_current_time();
	}

private:
	uint32_t get_current_time(void) {
		static struct timeval T;
		gettimeofday(&T, NULL);
		return (T.tv_sec * 1000000) + T.tv_usec;
	}
};


typedef std::vector<measure_item_t> results_t;


// ------------------------------------------------------------------------

void print_results(const results_t& results) {

    auto bar = [](int n, char c) {
        while (n-- > 0) {
            putchar(c);
        }

        putchar('\n');
    };

    const int terminal_width = 79;

    const int expand  = 11;
    const int convert = 7;
    const int time    = 8;
    const int speedup = 7;

    printf("| %*s | %*s | %*s | %*s |\n",
        -expand,  "expand",
        -convert, "convert",
        time,     "time [s]",
        speedup,  "speedup");


    bar(terminal_width, '-');

    const auto& ref = results[0];
    double max_speedup = 0;
    for (const auto& m: results) {
        max_speedup = std::max(max_speedup, m.get_speedup(ref));
    }

    for (const auto& m: results) {
        const int n = printf("| %*s | %*s | %*.4f | %*.2f | ",
            expand,  m.expand_name.c_str(),
            convert, m.convert_name.c_str(),
            time,    m.get_time(),
            speedup, m.get_speedup(ref)
        );

        const double f = m.get_speedup(ref)/max_speedup;
        const int k = f * (terminal_width - n);
        bar(k, '#');
    }
}


void csv_results(FILE* f, const results_t& results) {

    fprintf(f, "\"expand\",\"convert\",\"time [s]\",\"speedup\"\n");

    const auto& ref = results[0];
    for (const auto& m: results) {
        fprintf(f, "\"%s\",\"%s\",%.4f,%0.2f\n",
            m.expand_name.c_str(),
            m.convert_name.c_str(),
            m.get_time(),
            m.get_speedup(ref)
        );
    }
}


// ------------------------------------------------------------------------


template <typename F1, typename F2>
measure_item_t measure(F1 expand, F2 convert, int iterations, const std::string& expand_name, const std::string& convert_name) {
    std::printf("measure expand=%s, convert=%s... ", expand_name.c_str(), convert_name.c_str());
    std::fflush(stdout);

	measure_item_t m(expand_name, convert_name);

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


results_t measure() {
    const int n  = 10000000;

    results_t res;

    res.push_back(measure(nibble_expand_naive, nibbles_to_hex_naive, n, "naive", "naive"));
    res.push_back(measure(nibble_expand_naive, nibbles_to_hex_swar,  n, "naive", "swar"));
    res.push_back(measure(nibble_expand_naive, nibbles_to_hex_simd,  n, "naive", "simd"));

    res.push_back(measure(nibble_expand_naive_handcrafted, nibbles_to_hex_naive, n, "handcrafted", "naive"));
    res.push_back(measure(nibble_expand_naive_handcrafted, nibbles_to_hex_swar,  n, "handcrafted", "swar"));
    res.push_back(measure(nibble_expand_naive_handcrafted, nibbles_to_hex_simd,  n, "handcrafted", "simd"));

    res.push_back(measure(nibble_expand_mul, nibbles_to_hex_naive, n, "mul", "naive"));
    res.push_back(measure(nibble_expand_mul, nibbles_to_hex_swar,  n, "mul", "swar"));
    res.push_back(measure(nibble_expand_mul, nibbles_to_hex_simd,  n, "mul", "simd"));

    res.push_back(measure(nibble_expand_simd, nibbles_to_hex_naive, n, "simd", "naive"));
    res.push_back(measure(nibble_expand_simd, nibbles_to_hex_swar,  n, "simd", "swar"));
    res.push_back(measure(nibble_expand_simd, nibbles_to_hex_simd,  n, "simd", "simd"));

#ifdef HAVE_PDEP_INSTRUCTION
    res.push_back(measure(nibble_expand_pdep, nibbles_to_hex_naive, n, "simd", "naive"));
    res.push_back(measure(nibble_expand_pdep, nibbles_to_hex_swar,  n, "simd", "swar"));
    res.push_back(measure(nibble_expand_pdep, nibbles_to_hex_simd,  n, "simd", "simd"));
#endif

    return res;
}


// ------------------------------------------------------------------------


int main() {

    const auto res = measure();

	std::puts("");
    print_results(res);

    FILE* f = fopen("results.csv", "wb");
    if (f) {
        csv_results(f, res);
        fclose(f);
    }
}

