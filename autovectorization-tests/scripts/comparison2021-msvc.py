#!/usr/bin/env python3

from summary_base import Formatter

COMPILERS = {
    'MSVC 19.28.29333' : {
                'avx2'   : 'msvc19.28.29333-avx2.txt',
                'avx512' : 'msvc19.28.29333-avx512.txt',
    },
    'MSVC 19.16.27023.1' : {
                'avx2'   : 'msvc19-avx2.txt',
    },
    'GCC 10' : {
                'avx2'   : 'gcc10-avx2.txt',
                'avx512' : 'gcc10-avx512.txt',
    },
    'Clang 11' : {
                'avx2'   : 'clang11-avx2.txt',
                'avx512' : 'clang11-avx512.txt',
    },
}

if __name__ == '__main__':
    fmt = Formatter(COMPILERS)
    fmt.run()
