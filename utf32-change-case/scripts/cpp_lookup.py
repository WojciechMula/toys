from itertools import product
from io import StringIO


def main():
    f = StringIO()

    make_lookup(f, lambda s: s.upper(), "uppercase")
    make_lookup(f, lambda s: s.lower(), "lowercase")

    print(f.getvalue())


def make_lookup(f, trans, name):
    def write(s):
        f.write(s)

    def writeln(s):
        f.write(s + '\n')

    writeln(f"size_t cpp_utf32_{name}(const uint32_t* input, size_t n, uint32_t* output) {{")
    writeln("  size_t j=0;");
    writeln("  for (size_t i=0; i < n; i++)")
    writeln("  switch (input[i]) {")
    for src_code in range(0x1_ffff):
        src = chr(src_code)
        dst = trans(src)
        if src == dst:
            continue

        writeln(f"    case 0x{src_code:x}:");
        for c in dst:
            dst_code = ord(c);
            writeln(f"      output[j++] = 0x{dst_code:x};")
            writeln("      break;")

    else:
        writeln("      default:")
        writeln("        output[j++] = input[i];")
        writeln("    }")

    writeln("  return j;");
    writeln("};");

    return f


if __name__ == '__main__':
    main()
