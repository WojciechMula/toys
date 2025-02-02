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
    mktable()


def mktable():
    print(".. list-table::")
    print("    :header-rows: 1")
    print()
    print("    * - higher bits")
    print("      - lower bits")
    print("      - row size [bytes]")
    print("      - uppercase 1st level entries")
    print("      - uppercase 2nd level entries")
    print("      - uppercase total size [bytes]")
    print("      - lowercase 1st level entries")
    print("      - lowercase 2nd level entries")
    print("      - lowercase total size [bytes]")
    print("      - total size [bytes]")

    for lower_bits in range(1, 17):
        max_upper, count_upper = stats(lower_bits, lambda s: s.upper())
        max_lower, count_lower = stats(lower_bits, lambda s: s.lower())

        higher_bits = 17 - lower_bits
        row_size = 2**lower_bits * 4

        upper_1st_level_entries = max_upper
        upper_2nd_level_entries = count_upper
        upper_size = upper_1st_level_entries * 4 + upper_2nd_level_entries * row_size

        lower_1st_level_entries = max_lower
        lower_2nd_level_entries = count_lower
        lower_size = lower_1st_level_entries * 4 + lower_2nd_level_entries * row_size

        print(f"    * - {higher_bits}")
        print(f"      - {lower_bits}")
        print(f"      - {row_size}")
        print(f"      - {upper_1st_level_entries:,}")
        print(f"      - {upper_2nd_level_entries:,}")
        print(f"      - {upper_size:,}")
        print(f"      - {lower_1st_level_entries:,}")
        print(f"      - {lower_2nd_level_entries:,}")
        print(f"      - {lower_size:,}")
        print(f"      - {upper_size + lower_size:,}")


def stats(N, conv):
    lookup = set()
    for src_code in range(0x1_ffff + 1):
        src = chr(src_code)
        if src != conv(src):
            key = src_code >> N
            lookup.add(key)

    return (max(lookup), len(lookup))


if __name__ == '__main__':
    main()
