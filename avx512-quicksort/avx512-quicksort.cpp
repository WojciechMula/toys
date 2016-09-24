#include "avx512-swap.cpp"
#include "avx512-partition.cpp"
#include "avx512-popcnt-partition.cpp"
#include "avx512-bmi2-partition.cpp"


namespace qs {

    namespace avx512 {

        void quicksort(uint32_t* array, int left, int right) {

            int i = left;
            int j = right;

            const uint32_t pivot = array[(i + j)/2];
            const int AVX512_REGISTER_SIZE = 16; // in 32-bit words

            if (j - i >= 2 * AVX512_REGISTER_SIZE) {
                ::qs::avx512::partition_epi32(array, pivot, i, j);
            } else {
                scalar_partition_epi32(array, pivot, i, j);
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
                quicksort(array, left, j);
            }

            if (i < right) {
                quicksort(array, i, right);
            }
        }

    } // namespace avx512

} // namespace qs

