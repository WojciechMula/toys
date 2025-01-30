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
        gencode(lambda s: s.upper(), "uppercase")
        gencode(lambda s: s.lower(), "lowercase")

    try:
        old = path.read_text()
    except FileNotFoundError:
        old = ''

    new = f.getvalue()
    if old != new:
        print(f"generating {path}")
        path.write_text(new)


def gencode(conv, name):
    conv2 = {}
    conv3 = {}

    for src_code in range(0x1_ffff + 1):
        src = chr(src_code)
        dst = conv(src)
        if src != dst:
            if len(dst) == 2:
                conv2[src_code] = tuple(map(ord, dst))
            elif len(dst) == 3:
                conv3[src_code] = tuple(map(ord, dst))

    if conv2:
        print()
        print(f"void aux_{name}_utf32_char_with_two_codepoints(uint32_t in, uint32_t* out) {{")
        print(" switch (in) {")
        for src_code, (dst0, dst1) in conv2.items():
            print(f"  case 0x{src_code:04x}:")
            print(f"    out[0] = 0x{dst0:04x};")
            print(f"    out[1] = 0x{dst1:04x};")
            print("    break;")
        print(" } // switch")
        print("}")

    if conv3:
        print()
        print(f"void aux_{name}_utf32_char_with_three_codepoints(uint32_t in, uint32_t* out) {{")
        print(" switch (in) {")
        for src_code, (dst0, dst1, dst2) in conv3.items():
            print(f"  case 0x{src_code:04x}:")
            print(f"    out[0] = 0x{dst0:04x};")
            print(f"    out[1] = 0x{dst1:04x};")
            print(f"    out[2] = 0x{dst2:04x};")
            print("    break;")
        print(" } // switch")
        print("}")


if __name__ == '__main__':
    main()
