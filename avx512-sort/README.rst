================================================================================
             Counting sort within an AVX512F register
================================================================================

(Sort of) `counting sort`__  within an AVX512F register --- sounds crazy.

__ https://en.wikipedia.org/wiki/Counting_sort

The algorithm is slower than C++ std::sort, but works entirely on registers, 
so it might be faster in practice. Moreover, std::sort sorts data in-place,
while AVX512 doesn't destroy the source.

Type ``make`` to build programs ``verify`` and ``speed``. Type ``make run``
to run them using `Software Development Emulator`__.

__ https://software.intel.com/en-us/articles/intel-software-development-emulator

Output from ``speed`` on Knights Landing 7120::

    sorting a single AVX512 register

    std::sort...                    1.53
    insertion sort...               5.55
    AVX512F sort...                 1.77
    AVX512F sort (for loop)...      2.04
    AVX512F sort (while loop)...    2.19

    sorting two AVX512 registers
    
    std::sort...                    5.24
    insertion sort...              12.99
    AVX512F sort...                 5.78

