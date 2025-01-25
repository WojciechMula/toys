from itertools import product
from io import StringIO


def main():
    f = StringIO()

    make_lookup(f, lambda s: s.upper(), "UPPERCASE")
    make_lookup(f, lambda s: s.lower(), "LOWERCASE")

    print(f.getvalue())


def make_lookup(f, conv, name):
    def write(s):
        f.write(s)

    def writeln(s):
        f.write(s + '\n')

    N = 7
    by_key = [[] for _ in range(1024*100)]
    for src_code in range(0x1_ffff):
        src = chr(src_code)
        dst = conv(src)
        if src != dst:
            # we use 10 higher bits
            key = src_code >> N
            by_key[key].append((src, dst))

    while len(by_key[-1]) == 0:
        del by_key[-1]

    writeln(f"constexpr size_t UTF32_{name}_MAX_HI_BITS = %d;" % len(by_key))
    offset = 0
    size = 2**N

    long_replacements = []
    long_replacements_total = 0;

    writeln(f"const uint16_t UTF32_{name}_OFFSET[UTF32_UPPERCASE_MAX_HI_BITS] = {{")
    offset = 0
    for key, group in enumerate(by_key):
        if group:
            writeln(f" {offset},")
            offset += size
        else:
            writeln(f" 0xffff,")
    else:
        writeln("};")

    writeln(f"uint32_t UTF32_{name}_DATA[UTF32_{name}_MAX_HI_BITS * {size} + 1] = {{")
    for key, group in enumerate(by_key):
        if not group:
            continue

        min = key << N
        max = (key << N) + (size - 1)
        writeln(" // 0x%04x .. 0x%04x" % (min, max))
        write(' ')
        for ofs in range(size):
            code = (key << N) | ofs
            src = chr(code)
            dst = conv(src)
            if len(dst) == 1:
                dstcode = ord(dst)
            else:
                if len(dst) == 2:
                    dstcode = 0x8000_0000 | long_replacements_total
                elif len(dst) == 3:
                    dstcode = 0xc000_0000 | long_replacements_total
                else:
                    assert False

                long_replacements.append((src, dst))
                long_replacements_total += len(dst)

            if ofs:
                write(" 0x%04x," % dstcode)
            else:
                write("0x%04x," % dstcode)
        
        write('\n')
    
    writeln("};");

    writeln("")

    writeln(f"constexpr size_t UTF32_{name}_LONG_REPL_SIZE = {long_replacements_total};")
    writeln(f"uint32_t UTF32_{name}_LONG_REPL[UTF32_{name}_LONG_REPL_SIZE] = {{");
    #raise ValueError((long_replacements_total, long_replacements))
    for repl in long_replacements:
        (src, dst) = repl
        writeln(f" // '{src}' => '{dst}' ({len(dst)})")
        for c in dst:
            write(" 0x%04x," % ord(c))
        else:
            writeln("")

    writeln("};");

    return f


if __name__ == '__main__':
    main()
