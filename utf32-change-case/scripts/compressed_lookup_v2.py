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
    for src_code in range(0x1_ffff + 1):
        src = chr(src_code)
        dst = conv(src)
        if src != dst:
            # we use 10 higher bits
            key = src_code >> N
            by_key[key].append((src, dst))

    while len(by_key[-1]) == 0:
        del by_key[-1]

    print(f"constexpr size_t UTF32_{name}_V2_MAX_HI_BITS = %d;" % len(by_key))
    offset = 0
    size = 2**N

    long_replacements = []
    long_replacements_total = 0

    print(f"const uint16_t UTF32_{name}_V2_OFFSET[UTF32_{name}_V2_MAX_HI_BITS] = {{")
    offset = 0
    for key, group in enumerate(by_key):
        if group:
            print(f" {offset},")
            offset += size
        else:
            print(" 0xffff,")
    else:
        print("};")

    print(f"uint32_t UTF32_{name}_V2_DATA[UTF32_{name}_V2_MAX_HI_BITS * {size} + 1] = {{")
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
                print(" 0x%04x," % dstcode, end='')
            else:
                print("0x%04x," % dstcode, end='')

        print()

    print("};")

    print("")

    print(f"constexpr size_t UTF32_{name}_LONG_REPL_SIZE = {long_replacements_total};")
    print(f"uint32_t UTF32_{name}_LONG_REPL[UTF32_{name}_LONG_REPL_SIZE] = {{")
    for repl in long_replacements:
        (src, dst) = repl
        print(f" // '{src}' => '{dst}' ({len(dst)})")
        for c in dst:
            print(" 0x%04x," % ord(c), end='')
        else:
            print()

    print("};")


if __name__ == '__main__':
    main()
