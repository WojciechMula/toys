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

    N = 8
    by_key = [[] for _ in range(1024*100)]
    for src_code in range(0x1_ffff):
        src = chr(src_code)
        dst = conv(src)
        if src != dst:
            key = src_code >> N
            by_key[key].append((src_code, src, dst))

    while len(by_key[-1]) == 0:
        del by_key[-1]

    writeln(f"constexpr size_t UTF32_{name}_V2_MAX_HI_BITS = %d;" % len(by_key))
    offset = 0

    long_replacements = []
    long_replacements_total = 0

    writeln(f"constexpr uint32_t UTF32_{name}_V2_OFFSET[UTF32_{name}_V2_MAX_HI_BITS] = {{")
    offset = 0
    for key, group in enumerate(by_key):
        if group:
            # encoding:
            # - min: u8
            # - max: u8
            # - offset: u16

            min = group[0][0] & 0xff
            max = group[-1][0] & 0xff
            assert offset < 2**16

            codeword = (offset << 16) | (max << 8) | min
            offset += max - min + 1
        else:
            min = 0xff
            max = 0x00
            codeword = (max << 8) | min

        writeln(f" 0x{codeword:08x},")
    else:
        writeln("};")

    writeln(f"constexpr uint32_t UTF32_{name}_V2_DATA[{offset}] = {{")
    for key, group in enumerate(by_key):
        if not group:
            continue

        min = group[0][0]
        max = group[-1][0]
        writeln(f" // 0x{key:04x}: 0x{min:04x} .. 0x{max:04x}")
        write(' ')
        for ofs in range(min, max + 1):
            src_code = (key << N) | ofs
            src = chr(src_code)
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

                long_replacements_total += len(dst)

            write("0x%04x," % dstcode)
        else:
            write('\n')

    writeln("};")

    return f


if __name__ == '__main__':
    main()
