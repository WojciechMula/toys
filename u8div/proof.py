
def long_div_ver1(a, b):
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


def long_div_ver2(a, b):
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


def long_div_avx512(a, b):
    res = 0
    tmp = 0
    for i in range(8):
        tmp <<= 1
        tmp |= (a >> (7-i)) & 0x01

        print();
        print("tmp = %08x" % tmp);

        assert 0 <= tmp < 256

        res <<= 1
        if tmp >= b:
            tmp -= b
            res |= 1

        print("res = %08x" % res);

    return res


def gt(x, y):
    if x > y:
        return 0xffff
    else:
        return 0

def andnot(a, b):
    return ~a & b



def verify(func):
    for a in range(0, 256):
        for b in range(1, 256):
            want = a // b
            got  = func(a, b)
            assert got == want, f"a = {a}, b = {b}, want = {want}, got = {got}"


def main():
    long_div_avx512(213, 6)
    return
    functions = [long_div_ver1, long_div_ver2, long_div_avx512]

    for func in functions:
        verify(func)

    print("All OK")


if __name__ == '__main__':
    main()
