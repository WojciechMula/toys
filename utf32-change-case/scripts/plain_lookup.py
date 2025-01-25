from itertools import product
from io import StringIO


def main():
    f = StringIO()

    make_lookup(f, lambda s: s.upper(), "UPPERCASE")
    make_lookup(f, lambda s: s.lower(), "LOWERCASE")

    print(f.getvalue())


def make_lookup(f, trans, name):
    def write(s):
        f.write(s)

    def writeln(s):
        f.write(s + '\n')

    long_replacements = []
    long_replacements_total = 0

    writeln(f"const uint32_t UTF32_{name}_PLAIN[0x1ffff] = {{");
    for src_code in range(0x1_ffff):
        src = chr(src_code)
        dst = trans(src)
        if len(dst) == 1:
            writeln(" 0x%04x," % ord(dst))
        else:
            if len(dst) == 2:
                dstcode = 0x8000_0000 | long_replacements_total
            elif len(dst) == 3:
                dstcode = 0xc000_0000 | long_replacements_total
            else:
                assert False

            writeln(" 0x%04x," % dstcode)

            long_replacements.append((src, dst))
            long_replacements_total += len(dst)

    writeln("};");

    writeln("")

    writeln(f"constexpr size_t UTF32_{name}_PLAIN_LONG_REPL_SIZE = {long_replacements_total};")
    writeln(f"uint32_t UTF32_{name}_PLAIN_LONG_REPL[UTF32_{name}_PLAIN_LONG_REPL_SIZE] = {{");
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
