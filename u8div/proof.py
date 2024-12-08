
def div_ver1(a, b):
    b <<= 7
    bit = 0x0080
    res = 0

    for i in range(8):
        mask = gt(b, a)

        a   = a - andnot(mask, b)
        res = res | andnot(mask, bit)

        b >>= 1
        bit >>= 1

    return res

def div_ver2(a, b):
    b <<= 7
    bit = 0x0080
    res = 0

    for i in range(8):
        mask = gt(b, a)

        a   = a - andnot(mask, b)
        res = res | andnot(mask, bit)

        bit >>= 1
        a <<= 1

    return res


def gt(x, y):
    if x > y:
        return 0xffff
    else:
        return 0

def andnot(a, b):
    return ~a & b


def main():
    for a in range(0, 256):
        for b in range(1, 256):
            want = a // b
            got  = div_ver1(a, b)
            assert got == want, f"a = {a}, b = {b}, want = {want}, got = {got}"

            got  = div_ver2(a, b)
            assert got == want, f"a = {a}, b = {b}, want = {want}, got = {got}"

    print("All OK")


if __name__ == '__main__':
    main()
