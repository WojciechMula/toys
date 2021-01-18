#!/usr/bin/env python3

from summary_base import Formatter

COMPILERS = {
    'GCC 9' : {
                'avx2'   : 'gcc9-avx2.txt',
                'avx512' : 'gcc9-avx512.txt',
    },
    'GCC 10' : {
                'avx2'   : 'gcc10-avx2.txt',
                'avx512' : 'gcc10-avx512.txt',
    },
    'Clang 9' : {
                'avx2'   : 'clang9-avx2.txt',
                'avx512' : 'clang9-avx512.txt',
    },
    'Clang 11' : {
                'avx2'   : 'clang11-avx2.txt',
                'avx512' : 'clang11-avx512.txt',
    },
}

if __name__ == '__main__':
    fmt = Formatter(COMPILERS)
    fmt.run()
