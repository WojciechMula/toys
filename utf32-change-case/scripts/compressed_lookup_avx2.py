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

    offset = 0
    size = 2**N

    count = f"UTF32_{name}_MAX_HI_BITS_AVX2"
    fallback = f"UTF32_{name}_FALLBACK_AVX2"
    writeln(f"constexpr size_t {count} = %d;" % len(by_key))
    writeln(f"constexpr size_t {fallback} = %d * {size};" % len(by_key))

    writeln(f"const uint32_t UTF32_{name}_OFFSET_AVX2[{count} + 1] = {{")
    offset = 0
    for key, group in enumerate(by_key):
        if group:
            writeln(f" {offset},")
            offset += size
        else:
            writeln(f" {fallback},")
    else:
        writeln(f" {fallback},")
        writeln("};")

    writeln(f"uint32_t UTF32_{name}_DATA_AVX2[({count} + 1) * {size}] = {{")
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
                dstcode = ord(dst) ^ code
            else:
                dstcode = 0x8000_0000

            if ofs:
                write(" 0x%04x," % dstcode)
            else:
                write("0x%04x," % dstcode)

        write('\n')

    if True:
        writeln(" // fallback")
        for ofs in range(size):
            if ofs:
                write(" 0x%04x," % 0)
            else:
                write("0x%04x," % 0)
        else:
            write('\n')

    writeln("};")

    return f


if __name__ == '__main__':
    main()
