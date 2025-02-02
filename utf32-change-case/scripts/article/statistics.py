import unicodedata
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
    print(f".. list-table:: How many characters are subject of case change (Unicode {unicodedata.unidata_version})")
    print(f"    :header-rows: 1")
    print(f"    :class: col2right, col3right, col4right, col5right")

    upper_1_char, upper_2_chars, upper_3_chars = stats(lambda s: s.upper())
    lower_1_char, lower_2_chars, lower_3_chars = stats(lambda s: s.lower())

    print("    * -")
    print("      - 1 code point")
    print("      - 2 code points")
    print("      - 3 code points")
    print("      - total")
    print("    * - uppercase")
    print(f"      - {upper_1_char}")
    print(f"      - {upper_2_chars}")
    print(f"      - {upper_3_chars}")
    print(f"      - {upper_1_char + upper_2_chars + upper_3_chars}")
    print("    * - lowercase")
    print(f"      - {lower_1_char}")
    print(f"      - {lower_2_chars}")
    print(f"      - {lower_3_chars}")
    print(f"      - {lower_1_char + lower_2_chars + lower_3_chars}")


def stats(conv):
    count_1_char  = 0
    count_2_chars = 0
    count_3_chars = 0

    for src_code in range(0x1_ffff + 1):
        src = chr(src_code)
        dst = conv(src)
        if dst != src:
            if len(dst) == 1:
                count_1_char += 1
            elif len(dst) == 2:
                count_2_chars += 1
            elif len(dst) == 3:
                count_3_chars += 1

    return (count_1_char, count_2_chars, count_3_chars)


if __name__ == '__main__':
    main()
