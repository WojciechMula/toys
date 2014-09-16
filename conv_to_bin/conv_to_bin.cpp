/*
	Convert to binary representation

	Author  : Wojciech Muła
	Date    : 2014-09-11
	License : BSD

	Compilation:

	$ gcc -O2 -Wall -Wextra -std=c99 conv_to_bin.c -o your_fav_name

*/


#include <cstdio>
#include <cstdint>
#include <cstring>
#include <assert.h>
#include <string>

#include <sys/time.h>

// --- naive --------------------------------------------------------------

uint64_t convert_naive(uint8_t v) {

	union {
		uint64_t qword;
		uint8_t  bytes[8];
	} result;

	for (int i=7; i >= 0; i--) {

		const uint8_t bit = (1 << i);

		result.bytes[i] = (v & bit) ? '1' : '0';
	}

	return result.qword;
}


// --- lookup -------------------------------------------------------------

uint64_t lookup[256];

uint64_t convert_lookup(uint8_t v) {
	return lookup[v];
}


void prepare_lookup() {
    for (int i=0; i < 256; i++) {
        lookup[i] = convert_naive(i);
    }
}

// --- SWAR version -------------------------------------------------------

uint64_t convert_swar(uint8_t v) {

	const uint64_t r1 =  v * 0x0101010101010101;
	const uint64_t r2 = r1 & 0x8040201008040201;
	const uint64_t r3 = r2 + 0x00406070787c7e7f;
	const uint64_t r4 = (r3 >> 7) & 0x0101010101010101;

	return 0x3030303030303030 + r4;  // ord('0') == 0x30
}

// --- SIMD version -------------------------------------------------------


#define SIMD_ALIGN __attribute__((aligned(16)))                                                     
#define packed_byte(x)   {x, x, x, x, x, x, x, x, x, x, x, x, x, x, x, x}

uint8_t bit_mask[16] SIMD_ALIGN = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
uint8_t ascii[16]    SIMD_ALIGN = packed_byte('0');


uint64_t convert_simd(uint8_t v) {

    uint64_t result;

	__asm__ __volatile__ (
		// 1. populate byte
		"movd       %%eax,  %%xmm0    \n"
		"punpcklbw  %%xmm0, %%xmm0    \n"

		// 2. mask bits
		"pand       bit_mask, %%xmm0  \n"
		"pcmpeqb    bit_mask, %%xmm0  \n"

		// 3. convert to ASCII
		"movdqa     ascii, %%xmm1     \n"
		"psubb      %%xmm0, %%xmm1    \n"

		// save result
		"movq       %%xmm1, (%%ebx)   \n"

		: /* no output */
		: "a" (0x01010101 * v),
		  "b" (&result)
        : "memory"
	);

	return result;
}


// ------------------------------------------------------------------------


void usage() {
    puts("usage:");
    puts("  program [verify|measure]");
}


// ------------------------------------------------------------------------


void verify() {
	for (int i=0; i < 256; i++) {
        const uint64_t naive = convert_naive(i);
        const uint64_t swar  = convert_naive(i);
        const uint64_t simd  = convert_naive(i);

        if (naive != swar) {
            std::printf("failed SWAR: %016llx != %016llx\n", naive, swar);
            return;
        }

        if (naive != simd) {
            std::printf("failed SIMD: %016llx != %016llx\n", naive, simd);
            return;
        }
	}

    std::puts("all ok");
}


// ------------------------------------------------------------------------


struct measure_item_t {
    const std::string name;
    const double time;

    measure_item_t(const std::string& name, uint32_t ts, uint32_t te)
        : name(name)
        , time((te - ts)/1000000.0) {
        
        // nop
    }

    void print() const {
        std::printf("%20s: %10.4fs\n", name.c_str(), time);
    }

    void print(const measure_item_t& other) const {
        std::printf("%20s: %10.4fs (speedup: %0.2f)\n", name.c_str(), time, other.time/time);
    }
};


uint32_t get_time(void) {                                                                           
    static struct timeval T;                                                                    
    gettimeofday(&T, NULL);                                                                     
    return (T.tv_sec * 1000000) + T.tv_usec;                                                    
}     


template <typename F>
measure_item_t measure(F function, int iterations, const std::string& name) {
    std::printf("measure %s... ", name.c_str());
    std::fflush(stdout);

    const auto t1 = get_time();

    uint8_t byte = 0;
    while (iterations-- > 0) {
        function(byte++);
    }

    const auto t2 = get_time();

    std::printf("ok\n");

    return measure_item_t(name, t1, t2);
}


void measure() {
    const int  n  = 10000000;

    const auto m1 = measure(convert_naive,  n, "naive");  
    const auto m2 = measure(convert_lookup, n, "lookup");  
    const auto m3 = measure(convert_swar,   n, "SWAR");  
    const auto m4 = measure(convert_simd,   n, "SIMD");  

    m1.print();
    m2.print(m1);
    m3.print(m1);
    m4.print(m1);
}


// ------------------------------------------------------------------------


int main(int argc, char* argv[]) {

    if (argc > 1) {
#define is_keyword(keyword) (strcmp((keyword), argv[1]) == 0)
        if (is_keyword("verify")) {
            prepare_lookup();
            verify();
        } else if (is_keyword("measure")) {
            prepare_lookup();
            measure();
        } else {
            usage();
        }

#undef is_keyword
    } else {
        usage();
    }
}

