#!/usr/bin/env python3

from summary_base import Formatter

COMPILERS = {
    'GCC' : {
                'avx2'   : 'gcc9-avx2.txt',
                'avx512' : 'gcc9-avx512.txt',
    },
    'Clang' : {
                'avx2'   : 'clang9-avx2.txt',
                'avx512' : 'clang9-avx512.txt',
    },
    'ICC' : {
                'avx2'   : 'icc19-avx2.txt',
                'avx512' : 'icc19-avx512.txt',
    },
    'MSVC' : {
                'avx2'   : 'msvc19-avx2.txt',
                'avx512' : 'msvc19-avx512.txt',
    },
}

if __name__ == '__main__':
    fmt = Formatter(COMPILERS)
    fmt.run()
