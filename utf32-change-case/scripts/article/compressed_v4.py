import sys
from io import StringIO
from pathlib import Path
from contextlib import redirect_stdout

def main():
    path = Path(sys.argv[1])

    f = StringIO()
    with redirect_stdout(f):
        mktable()

    try:
        old = path.read_text()
    except FileNotFoundError:
        old = ''

    new = f.getvalue()
    if old != new:
        print(f"generating {path}")
        path.write_text(new)


def mktable():
    print(".. list-table::")
    print("    :header-rows: 1")
    print()
    print("    * - #")
    print("      - higher bits")
    print("      - lower bits")
    print("      - uppercase 1st level entries")
    print("      - uppercase 2nd level entries")
    print("      - uppercase total size [bytes]")
    print("      - lowercase 1st level entries")
    print("      - lowercase 2nd level entries")
    print("      - lowercase total size [bytes]")
    print("      - total size [bytes]")

    for id, lower_bits in enumerate(range(1, 17), 1):
        upper_1st_level_entries, upper_2nd_level_entries  = stats(lower_bits, lambda s: s.upper())
        lower_1st_level_entries, lower_2nd_level_entries  = stats(lower_bits, lambda s: s.lower())

        higher_bits = 17 - lower_bits
        row_size = 2**lower_bits * 4

        upper_size = upper_1st_level_entries * 1 + upper_2nd_level_entries * row_size
        lower_size = lower_1st_level_entries * 1 + lower_2nd_level_entries * row_size

        print(f"    * - {id}")
        print(f"      - {higher_bits}")
        print(f"      - {lower_bits}")
        print(f"      - {upper_1st_level_entries:,}")
        print(f"      - {upper_2nd_level_entries:,}")
        print(f"      - {upper_size:,}")
        print(f"      - {lower_1st_level_entries:,}")
        print(f"      - {lower_2nd_level_entries:,}")
        print(f"      - {lower_size:,}")
        print(f"      - {upper_size + lower_size:,}")


def stats(N, conv):
    lookup = {}
    for src_code in range(0x1_ffff + 1):
        key = src_code >> N
        src = chr(src_code)
        dst = conv(src)
        if key not in lookup:
            lookup[key] = []

        L = lookup[key]
        if src == dst:
            L.append(0)
        if src != dst:
            if len(dst) == 1:
                L.append(ord(dst) ^ src_code)
            else:
                L.append(0x8000_0000)

    rows = set()
    for row in lookup.values():
        rows.add(tuple(row))

    return (len(lookup), len(rows))


if __name__ == '__main__':
    main()
