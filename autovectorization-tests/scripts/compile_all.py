#!/usr/bin/env python3

import sys

from pathlib import Path
from procedures import PROCEDURES

std_options = {
    'avx2': '-O3 -mavx2 -S %(cpp_file)s -o %(asm_file)s',
    'avx512': '-O3 -mavx512f -mavx512dq -mavx512bw -mavx512vbmi -mavx512vbmi2 -mavx512vl '
              '-S %(cpp_file)s -o %(asm_file)s',
}

compiler_options = {
    'gcc':  std_options,
    'clang': std_options,
        
}

def main():
    if len(sys.argv) < 2:
        print("Usage: script compile-command target")
        print()
        print("compiler-command tells how to invoke script (like 'gcc' or 'clang')")
        print("target is avx2 or avx512")
        return 1

    arg_compiler = sys.argv[1]
    arg_target = sys.argv[2]

    options = None
    for compiler in compiler_options:
        if compiler in arg_compiler:
            options = compiler_options[compiler][arg_target]

    if options is None:
        print(f"{arg_compiler} not recognized")
        return 1

    for cpp_file in PROCEDURES:
        asm_file = Path(cpp_file).stem + '_' + arg_target + '.s'
        opts = options % {'cpp_file': cpp_file,
                          'asm_file': asm_file}

        print(f"{arg_compiler} {opts}")

    return 0
        

if __name__ == '__main__':
    sys.exit(main())
