import sys

class Generator:
    def __init__(self):
        self.ind = 0
        self.f = sys.stdout

    def generate(self):
        self.write("/* Code generated automatically; DO NOT EDIT */")
        self.indent()
        self.write("const __m128i ascii0 = _mm_set1_epi8('0');")
        self.write("const __m128i t0 = _mm_sub_epi8(input, ascii0);")
        self.generate_main_switch()
        self.unindent()

    def generate_main_switch(self):
        bylen = {}
        for code in range(256):
            l3 = (code >> (0*2)) & 0x03
            l2 = (code >> (1*2)) & 0x03
            l1 = (code >> (2*2)) & 0x03
            l0 = (code >> (3*2)) & 0x03
            lengths = [l0, l1, l2, l3]
            if 0 not in lengths:
                inputlen = sum(lengths) + 3
                if inputlen not in bylen:
                    bylen[inputlen] = [lengths]
                else:
                    bylen[inputlen].append(lengths)

        keys = sorted(bylen.keys())
        self.write("switch (ipv4.size()) {")
        self.indent()
        for key in keys:
            values = bylen[key]
            self.write("case %d: // %d case(s)" % (key, len(values)))
            self.indent()
            self.write("switch (dotmask & 0x%02x) {" % ((1 << key) - 1))
            self.indent()
            for lengths in values:
                self.write("case 0x%02x: // %s" % (lengths2patterns(lengths), lengths))
                self.indent()
                self.generate_case(lengths)
                self.unindent()
            else:
                self.write("default:")
                self.indent()
                self.write("res.err = errInvalidInput;")
                self.write("return res;")
                self.unindent()
            self.unindent()
            self.write("}")
            self.write("break;")
            self.unindent()

        self.unindent()
        self.write("}")

    def generate_case(self, lengths):
        offset = 0
        pshufb_pattern = [-1] * 16
        for i, l in enumerate(lengths):
            var = 'val%d' % i
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

        self.indent()
        self.write("{")
        img = ', '.join('%d' % idx for idx in pshufb_pattern)
        self.write("const __m128i pattern = _mm_setr_epi8(%s);" % img)
        self.write("const __m128i t1 = _mm_shuffle_epi8(t0, pattern);")
        if max(lengths) == 1:
            self.write("res.ipv4 = _mm_cvtsi128_si32(t1);")
        elif max(lengths) == 2:
            self.write("const uint64_t w01 = _mm_cvtsi128_si64(t1);")
            self.write("const uint32_t w0 = w01;")
            self.write("const uint32_t w1 = (w01 >> 32);")
            self.write("res.ipv4 = 10 * w1 + w0;")
        elif max(lengths) == 3:
            self.write("const uint64_t w01 = _mm_cvtsi128_si64(t1);")
            self.write("const uint32_t w2 = _mm_extract_epi32(t1, 2);")
            self.write("const uint32_t w0 = w01;")
            self.write("const uint32_t w1 = (w01 >> 32);")
            self.write("res.ipv4 = 10 * (10 * w2 + w1) + w0;")
        else:
            assert False

        self.write("}")
        self.unindent()

        self.write("break;")

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
