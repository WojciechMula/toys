import sys
from io import StringIO
from pathlib import Path
from contextlib import redirect_stdout


def main():
    f = StringIO()

    path = Path(sys.argv[1])

    f = StringIO()
    with redirect_stdout(f):
        print("// Code generated automatically; DO NOT EDIT")
        print()
        make_lookup(lambda s: s.upper(), "uppercase")
        make_lookup(lambda s: s.lower(), "lowercase")

    try:
        old = path.read_text()
    except FileNotFoundError:
        old = ''

    new = f.getvalue()
    if old != new:
        print(f"generating {path}")
        path.write_text(new)


def make_lookup(trans, name):
    print(f"size_t cpp_utf32_{name}(const uint32_t* input, size_t n, uint32_t* output) {{")
    print("  size_t j=0;")
    print("  for (size_t i=0; i < n; i++)")
    print("  switch (input[i]) {")
    for src_code in range(0x1_ffff):
        src = chr(src_code)
        dst = trans(src)
        if src == dst:
            continue

        print(f"    case 0x{src_code:x}:")
        for c in dst:
            dst_code = ord(c)
            print(f"      output[j++] = 0x{dst_code:x};")
        else:
            print("      break;")

    else:
        print("      default:")
        print("        output[j++] = input[i];")
        print("    }")

    print("  return j;")
    print("};")


if __name__ == '__main__':
    main()
