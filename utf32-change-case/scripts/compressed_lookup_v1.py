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
    N = 8
    by_key = [[] for _ in range(1024*100)]
    for src_code in range(0x1_ffff + 1):
        src = chr(src_code)
        dst = conv(src)
        if src != dst:
            key = src_code >> N
            by_key[key].append((src_code, src, dst))

    while len(by_key[-1]) == 0:
        del by_key[-1]

    print(f"constexpr size_t UTF32_{name}_V1_MAX_HI_BITS = %d;" % len(by_key))
    offset = 0

    long_replacements_total = 0

    print(f"constexpr uint32_t UTF32_{name}_V1_OFFSET[UTF32_{name}_V1_MAX_HI_BITS] = {{")
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

        print(f" 0x{codeword:08x},")
    else:
        print("};")

    print(f"constexpr uint32_t UTF32_{name}_V1_DATA[{offset}] = {{")
    for key, group in enumerate(by_key):
        if not group:
            continue

        min = group[0][0]
        max = group[-1][0]
        print(f" // 0x{key:04x}: 0x{min:04x} .. 0x{max:04x}")
        print(' ', end='')
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

            print("0x%04x," % dstcode, end='')
        else:
            print()

    print("};")


if __name__ == '__main__':
    main()
