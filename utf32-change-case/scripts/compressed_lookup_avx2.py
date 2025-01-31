import sys
from io import StringIO
from pathlib import Path
from contextlib import redirect_stdout


def main():
    path = Path(sys.argv[1])

    f = StringIO()
    with redirect_stdout(f):
        print("// Code generated automatically; DO NOT EDIT")
        print()
        make_lookup(lambda s: s.upper(), "UPPERCASE")
        make_lookup(lambda s: s.lower(), "LOWERCASE")

    try:
        old = path.read_text()
    except FileNotFoundError:
        old = ''

    new = f.getvalue()
    if old != new:
        print(f"generating {path}")
        path.write_text(new)


def make_lookup(conv, name):
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
    print(f"constexpr size_t {count} = %d;" % len(by_key))
    print(f"constexpr size_t {fallback} = %d * {size};" % len(by_key))

    print(f"const uint32_t UTF32_{name}_OFFSET_AVX2[{count} + 1] = {{")
    offset = 0
    for key, group in enumerate(by_key):
        if group:
            print(f" {offset},")
            offset += size
        else:
            print(f" {fallback},")
    else:
        print(f" {fallback},")
        print("};")

    print(f"uint32_t UTF32_{name}_DATA_AVX2[({count} + 1) * {size}] = {{")
    for key, group in enumerate(by_key):
        if not group:
            continue

        min = key << N
        max = (key << N) + (size - 1)
        print(" // 0x%04x .. 0x%04x" % (min, max))
        print(' ', end='')
        for ofs in range(size):
            code = (key << N) | ofs
            src = chr(code)
            dst = conv(src)
            if len(dst) == 1:
                dstcode = ord(dst) ^ code
            else:
                dstcode = 0x8000_0000

            if ofs:
                print(" 0x%04x," % dstcode, end='')
            else:
                print("0x%04x," % dstcode, end='')

        print()

    if True:
        print(" // fallback")
        for ofs in range(size):
            if ofs:
                print(" 0x%04x," % 0, end='')
            else:
                print("0x%04x," % 0, end='')
        else:
            print()

    print("};")


if __name__ == '__main__':
    main()
