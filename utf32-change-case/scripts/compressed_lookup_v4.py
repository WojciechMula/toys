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
    N = 12
    group_size = 2**N

    groups = {}

    # 0th element is a fallback
    groups[(0,) * group_size] = 0
    lookup = []

    for hi in range((0x1_ffff >> N) + 1):
        tmp = [0] * group_size
        for lo in range(group_size):
            src_code = (hi << N) | lo
            src = chr(src_code)
            dst = conv(src)
            if src != dst:
                if len(dst) == 1:
                    dst_code = ord(dst)
                    tmp[lo] = src_code ^ dst_code
                elif len(dst) == 2:
                    tmp[lo] = 0x8000_0000
                elif len(dst) == 3:
                    tmp[lo] = 0xc000_0000

        tmp = tuple(tmp)
        try:
            id = groups[tmp]
        except KeyError:
            id = len(groups)
            groups[tmp] = id

        lookup.append(id)

    assert len(groups) < 256

    size_const = f"UTF32_{name}_V4_MAX_HI_BITS"
    print(f"constexpr size_t {size_const} = %d;" % len(lookup))
    print()

    print(f"constexpr uint8_t UTF32_{name}_V4_LOOKUP[{size_const} + 4] = {{")
    for id in lookup:
        print(f" {id},")
    else:
        for i in range(4):
            print(" 0,")
    print("};")

    tmp = list(groups.items())
    tmp.sort(key=lambda kv: kv[1])

    size_const = f"UTF32_{name}_V4_DATA_SIZE"
    print(f"constexpr size_t {size_const} = %d;" % len(tmp))
    print(f"constexpr uint32_t UTF32_{name}_V4_DATA[{size_const} * {group_size}] = {{")
    for arr, id in tmp:
        print(f" // 0x{id:x}")
        for diff in arr:
            print(f" 0x{diff:04x},")

    print("};")


if __name__ == '__main__':
    main()
