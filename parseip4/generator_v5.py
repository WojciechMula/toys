import sys
import itertools

class Item:
    pass

primes = [
    0, 1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
    61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131,
    137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
    283, 293, 307
]

class Generator:
    def __init__(self):
        self.ind = 0
        self.f = sys.stdout

    def generate(self):
        if 0:
            self.find_best()
            return

        self.write("/* Code generated automatically; DO NOT EDIT */")
        self.indent()
        self.generate_table()
        self.unindent()

    def find_best(self):
        bylen = {}
        for code in range(256):
            l3 = (code >> (0*2)) & 0x03
            l2 = (code >> (1*2)) & 0x03
            l1 = (code >> (2*2)) & 0x03
            l0 = (code >> (3*2)) & 0x03
            lengths = [l0, l1, l2, l3]
            if 0 not in lengths:
                inputlen = sum(lengths) + 3
                item = Item()
                item.lengths = lengths
                item.inputlen = inputlen
                if inputlen not in bylen:
                    bylen[inputlen] = [item]
                else:
                    bylen[inputlen].append(item)

        keys = sorted(bylen.keys())
        n = 0
        for key in keys:
            values = bylen[key]
            for item in values:
                self.fillup_details(item)
                n += 1

        p = [x for x in primes if x <= 100]
        oldmax = 1000000
        for mul1, mul2, mul3, mul4 in itertools.product(p, p, p, p):
            try:
                s = set()
                for key in keys:
                    values = bylen[key]
                    k = key
                    k = mul1 * k
                    for item in values:
                        w0 = item.code & 0xf
                        w1 = (item.code >> 4) & 0xf
                        w2 = (item.code >> 8) & 0xf

                        hash = k ^ w0 * mul2 ^ w1 * mul3 + w2 * mul4
                        if hash in s:
                            raise ValueError()
                        s.add(hash)
            except ValueError:
                pass

            if len(s) == n:
                m = max(s)
                if m <= oldmax:
                    print("params=", (mul1, mul2, mul3, mul4), "max =", m)
                    oldmax = m

    def generate_table(self):
        bylen = {}
        for code in range(256):
            l3 = (code >> (0*2)) & 0x03
            l2 = (code >> (1*2)) & 0x03
            l1 = (code >> (2*2)) & 0x03
            l0 = (code >> (3*2)) & 0x03
            lengths = [l0, l1, l2, l3]
            if 0 not in lengths:
                inputlen = sum(lengths) + 3
                item = Item()
                item.lengths = lengths
                item.inputlen = inputlen
                if inputlen not in bylen:
                    bylen[inputlen] = [item]
                else:
                    bylen[inputlen].append(item)

        keys = sorted(bylen.keys())
        tmp = {}
        for key in keys:
            values = bylen[key]
            for item in values:
                self.fillup_details(item)
                assert item.hashcode not in tmp
                tmp[item.hashcode] = item

        self.write("static const int8_t patterns[256][16] = {")
        self.indent()
        for byte in range(256):
            if byte in tmp:
                item = tmp[byte]
                pattern = item.pattern[:]
                max_digits = item.max_digits
            else:
                pattern = 16 * [0]
                max_digits = 0

            pattern[15] = max_digits

            img = ", ".join('%d' % x for x in pattern)
            self.write("/* %03d */ {%s}," % (byte, img))
        self.unindent()
        self.write("};")

    def fillup_details(self, item):
        offset = 0
        pshufb_pattern = [-1] * 16
        for i, l in enumerate(item.lengths):
            idx = 3 - i
            if l == 1:
                pshufb_pattern[idx] = offset
                offset += 2
            elif l == 2:
                pshufb_pattern[idx] = offset + 1
                pshufb_pattern[idx + 4] = offset
                offset += 3
            elif l == 3:
                pshufb_pattern[idx] = offset + 2
                pshufb_pattern[idx + 4] = offset + 1
                pshufb_pattern[idx + 8] = offset
                offset += 4
            else:
                assert False

        item.pattern = pshufb_pattern
        item.max_digits = max(item.lengths)
        item.code = lengths2patterns(item.lengths)

        w0 = item.code & 0xf
        w1 = (item.code >> 4) & 0xf
        w2 = (item.code >> 8) & 0xf
        k  = item.inputlen

        mul0 = 23
        mul1 =  5
        mul2 = 13
        item.hashcode = k ^ w0 * mul0 ^ w1 * mul1 + w2 * mul2

    def write(self, text):
        f = self.f
        f.write(' ' * self.ind)
        f.write(text)
        f.write('\n')

    def indent(self):
        self.ind += 4

    def unindent(self):
        self.ind -= 4


def lengths2patterns(lengths):
    mask = [0]*16
    n = lengths[0]
    mask[n] = 1
    n += lengths[1] + 1
    mask[n] = 1
    n += lengths[2] + 1
    mask[n] = 1
    n += lengths[3] + 1
    #mask[n] = 1

    img = ''.join('%d' % x for x in reversed(mask))

    return int(img, 2)

g = Generator()
g.generate()
