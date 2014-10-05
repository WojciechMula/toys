/*
	Convert to octal representation - measure speedup over naive version

	Author  : Wojciech Muła
	Date    : 2014-09-28
	License : BSD
*/


#include <string>
#include <vector>
#include <sys/time.h>


#include "common.c"
#include "conv.swar.c"
#include "conv.pdep.c"
#include "conv.sse2.c"
#include "conv.single-lookup.c"
#include "conv.two-lookups.c"


class measure_item_t {
    uint32_t t1;
    uint32_t t2;

public:
    const std::string name;

public:
    measure_item_t(const std::string& name)
        : name(name)
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

    const int convert = 10;
    const int time    = 10;
    const int speedup = 10;

    printf("| %*s | %*s | %*s |\n",
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
        const int n = printf("| %*s | %*.4f | %*.2f | ",
            convert, m.name.c_str(),
            time,    m.get_time(),
            speedup, m.get_speedup(ref)
        );

        const double f = m.get_speedup(ref)/max_speedup;
        const int k = f * (terminal_width - n);
        bar(k, '#');
    }
}


void csv_results(FILE* f, const results_t& results) {

    fprintf(f, "\"convert\",\"time [s]\",\"speedup\"\n");

    const auto& ref = results[0];
    for (const auto& m: results) {
        fprintf(f, "\"%s\",%.4f,%0.2f\n",
            m.name.c_str(),
            m.get_time(),
            m.get_speedup(ref)
        );
    }
}


// ------------------------------------------------------------------------


template <typename F>
measure_item_t measure(F convert, int iterations, const std::string& name) {
    std::printf("measure %s... ", name.c_str());
    std::fflush(stdout);

	measure_item_t m(name);

	m.start();

    uint16_t word = 0;
    while (iterations-- > 0) {
        convert(word & 0x0fff);
		word += 33;
    }

    m.stop();

    std::printf("ok\n");

    return m;
}


results_t measure() {
    const int n  = 10000000;

    results_t res;

    prepare_single_lookup();

    res.push_back(measure(to_oct_naive, n, "naive"));
    res.push_back(measure(to_oct_mul,   n, "mul"));
    res.push_back(measure(to_oct_sse2,  n, "SSE2"));
#ifdef HAVE_PDEP_INSTRUCTION
    res.push_back(measure(to_oct_pdep,  n, "pdep"));
#endif

    res.push_back(measure(to_oct_single_lookup, n, "1 LUT"));
    res.push_back(measure(to_oct_two_lookups,   n, "2 LUTs"));

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

