#include "avx512-swap.cpp"
#include "avx512-partition.cpp"
#include "avx512-popcnt-partition.cpp"
#include "avx512-bmi2-partition.cpp"
#include "avx512-sort-register.cpp"


namespace qs {

    namespace avx512 {


        void dump(const char* name, const __m512i v) {
            uint32_t tmp[16];

            printf("%-10s = [", name);
            _mm512_storeu_si512((__m512i*)tmp, v);
            for (int i=0; i < 16; i++) {
                if (i > 0) {
                    putchar(' ');
                }

                printf("%08x", tmp[i]);
            }

            printf("]\n");
        }

        void quicksort(uint32_t* array, int left, int right) {

            int i = left;
            int j = right;

            const uint32_t pivot = array[(i + j)/2];
            const int AVX512_REGISTER_SIZE = 16; // in 32-bit words

            if (j - i >= 2 * AVX512_REGISTER_SIZE) {
                ::qs::avx512::partition_epi32(array, pivot, i, j);
            } else {
                const int size = j - i + 1;
                if (size > AVX512_REGISTER_SIZE) {
                    scalar_partition_epi32(array, pivot, i, j);
                } else {
                    const __m512i in = _mm512_loadu_si512(array + i);
                    __m512i result;

                    switch (size) {
                        case 16:
                            result = avx512_sort16_epi32(in);
                            break;
                        case 15:
                            result = avx512_sort15_epi32(in);
                            break;
                        case 14:
                            result = avx512_sort14_epi32(in);
                            break;
                        case 13:
                            result = avx512_sort13_epi32(in);
                            break;
                        case 12:
                            result = avx512_sort12_epi32(in);
                            break;
                        case 11:
                            result = avx512_sort11_epi32(in);
                            break;
                        case 10:
                            result = avx512_sort10_epi32(in);
                            break;
                        case 9:
                            result = avx512_sort9_epi32(in);
                            break;
                        case 8:
                            result = avx512_sort8_epi32(in);
                            break;
                        case 7:
                            result = avx512_sort7_epi32(in);
                            break;
                        case 6:
                            result = avx512_sort6_epi32(in);
                            break;
                        case 5:
                            result = avx512_sort5_epi32(in);
                            break;
                        case 4:
                            result = avx512_sort4_epi32(in);
                            break;
                        case 3:
                            result = avx512_sort3_epi32(in);
                            break;
                        case 2: {
                            if (array[i] > array[j]) {
                                uint32_t t = array[i];
                                array[i]   = array[j];
                                array[j]   = t;
                            }
                            return;
                            }

                         case 1:
                            return;

                         default:
                            assert(false);
                            break;
                    }

                    _mm512_storeu_si512(array + i, result);
                    return;
                }
            }

            if (left < j) {
                quicksort(array, left, j);
            }

            if (i < right) {
                quicksort(array, i, right);
            }
        }


        void popcnt_quicksort(uint32_t* array, int left, int right) {

            int i = left;
            int j = right;

            const uint32_t pivot = array[(i + j)/2];
            const int AVX512_REGISTER_SIZE = 16; // in 32-bit words

            if (j - i >= 2 * AVX512_REGISTER_SIZE) {
                ::qs::avx512::popcnt_partition_epi32(array, pivot, i, j);
            } else {
                scalar_partition_epi32(array, pivot, i, j);
            }

            if (left < j) {
                popcnt_quicksort(array, left, j);
            }

            if (i < right) {
                popcnt_quicksort(array, i, right);
            }
        }


        void bmi2_quicksort(uint32_t* array, int left, int right) {

            int i = left;
            int j = right;

            const uint32_t pivot = array[(i + j)/2];
            const int AVX512_REGISTER_SIZE = 16; // in 32-bit words

            if (j - i >= 2 * AVX512_REGISTER_SIZE) {
                ::qs::avx512::bmi2_partition_epi32(array, pivot, i, j);
            } else {
                scalar_partition_epi32(array, pivot, i, j);
            }

            if (left < j) {
                bmi2_quicksort(array, left, j);
            }

            if (i < right) {
                bmi2_quicksort(array, i, right);
            }
        }

    } // namespace avx512

} // namespace qs

