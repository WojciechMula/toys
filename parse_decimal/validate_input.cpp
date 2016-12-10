#include <cstdio>
#include <cstdint>
#include <immintrin.h>
#include <string>


bool all_digits(const char* string, size_t size) {

    for (size_t i=0; i < size; i++) {
        if (string[i] < '0' || string[i] > '9')
            return false;
    }

    return true;
}


bool all_digits_SSE(const char* string, size_t size) {

    size_t i;

    const __m128i ascii0 = _mm_set1_epi8('0');
    const __m128i ascii9 = _mm_set1_epi8('9');

    const size_t n = size / 16;
    const size_t k = size % 16;

    __m128i* ptr = (__m128i*)string;
    for (i=0; i < n; i++) {
        
        const __m128i v   = _mm_loadu_si128(ptr++);
        const __m128i lt0 = _mm_cmplt_epi8(v, ascii0);
        const __m128i gt9 = _mm_cmpgt_epi8(v, ascii9);
        const __m128i outside = _mm_or_si128(lt0, gt9);

        if (_mm_movemask_epi8(outside)) {
            return false;
        }
    }

    return all_digits(string + n*16, k);
}


bool all_digits_SWAR(const char* string, size_t size) {

    size_t i;

    const size_t n = size / 8;
    const size_t k = size % 8;

    uint64_t* ptr = (uint64_t*)string;
    for (i=0; i < n; i++) {
        
        const uint64_t v = *ptr++;

        if ((v & 0xf0f0f0f0f0f0f0f0llu) != 0x3030303030303030llu) { // any higger nibble not equal 0x30
            return false;
        }

        if ((v + 0x4646464646464646llu) & 0x8080808080808080llu) { // any value 0x3a .. 0x3f
            return false;
        }
    }

    return all_digits(string + n*8, k);
}


template <typename FUN>
bool validate(const char* name, FUN check) {

    printf("%s... ", name);

    std::string ref;
    std::string str;
    const size_t n = 1024;

    for (size_t i=0; i < n; i++) {
        ref.push_back(rand() % 10 + '0');
    }

    str = ref;
    for (size_t size=1; size < n; size++) {
        if (!check(str.data(), size)) {
            printf("failed for size %lu\n", size);
            return false;
        }
    }

    for (size_t pos=0; pos < 32; pos++) {
        for (int i=0; i < 256; i++) {
            if (i >= '0' && i <= '9') {
                continue;
            }

            str = ref; // ref has all ascii digits
            str[pos] = char(i);

            if (check(str.data(), 32)) {
                printf("failed at %lu for char %d\n", pos, i);
                return false;
            }
        }
    }

    puts("OK");
    return true;
}


int main() {
    validate("naive", all_digits);
    validate("SSE",   all_digits_SSE);
    validate("SWAR",  all_digits_SWAR);
}
