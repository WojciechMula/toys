#include <iostream>

#include "scalar.cpp"
#include "avx512_naive.cpp"

int main() {
    std::cout << binom_scalar(50, 3) << '\n';
    std::cout << binom_scalar(50, 40) << '\n';
    std::cout << avx512_binom_scalar(50, 3) << '\n';
    std::cout << avx512_binom_scalar(50, 40) << '\n';
    std::cout << avx512_binom_scalar2(50, 3) << '\n';
    std::cout << avx512_binom_scalar2(50, 40) << '\n';
}
