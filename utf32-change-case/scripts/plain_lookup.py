import sys
from io import StringIO
from pathlib import Path
from contextlib import redirect_stdout


def main():
    f = StringIO()

    f = StringIO()

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


def make_lookup(trans, name):
    long_replacements = []
    long_replacements_total = 0

    print(f"const uint32_t UTF32_{name}_PLAIN[0x1ffff] = {{")
    for src_code in range(0x1_ffff):
        src = chr(src_code)
        dst = trans(src)
        if len(dst) == 1:
            print(" 0x%04x," % ord(dst))
        else:
            if len(dst) == 2:
                dstcode = 0x8000_0000 | long_replacements_total
            elif len(dst) == 3:
                dstcode = 0xc000_0000 | long_replacements_total
            else:
                assert False

            print(" 0x%04x," % dstcode)

            long_replacements.append((src, dst))
            long_replacements_total += len(dst)

    print("};")

    print("")

    print(f"constexpr size_t UTF32_{name}_PLAIN_LONG_REPL_SIZE = {long_replacements_total};")
    print(f"uint32_t UTF32_{name}_PLAIN_LONG_REPL[UTF32_{name}_PLAIN_LONG_REPL_SIZE] = {{")
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
