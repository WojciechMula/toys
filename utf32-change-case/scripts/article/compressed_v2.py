from contextlib import redirect_stdout


def mktable(conv):
    N = 8
    L = {}
    for src_code in range(0x1_ffff + 1):
        src = chr(src_code)
        key = src_code >> N

        if src != conv(src):
            if key not in L:
                L[key] = []

            L[key].append(src_code)

    total = 0
    for id, (key, chars) in enumerate(L.items()):
        min = chars[0]
        max = chars[-1]
        count = max - min + 1
        print()
        print(f"* - {id}")
        print(f"  - ``0x{key:03x}``")
        print(f"  - ``0x{min:04x}``")
        print(f"  - ``0x{max:04x}``")
        print(f"  - {count}")

        total += count
    else:
        print("* -")
        print("  -")
        print("  -")
        print("  -")
        print(f"  - {total} total")


if __name__ == '__main__':
    path = "v2_upper.rst"
    with open(path, 'w') as f:
        print(f"creating {path}")
        with redirect_stdout(f):
            mktable(lambda s: s.upper())

    path = "v2_lower.rst"
    with open(path, 'w') as f:
        print(f"creating {path}")
        with redirect_stdout(f):
            mktable(lambda s: s.lower())
