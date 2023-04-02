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

    def generate_case_max1(self, lengths, pshufb_pattern):
        offset = 0
        for i, l in enumerate(lengths):
            idx = i
            if l == 1:
                pshufb_pattern[idx] = offset
                offset += 2
            else:
                assert False

    def generate_case_max2(self, lengths, pshufb_pattern):
        offset = 0
        for i, l in enumerate(lengths):
            idx = i
            if l == 1:
                pshufb_pattern[idx] = offset
                pshufb_pattern[idx + 12] = offset + 1 # place '.' in 3rd dword
                offset += 2
            elif l == 2:
                pshufb_pattern[idx] = offset + 1
                pshufb_pattern[idx + 4] = offset
                pshufb_pattern[idx + 12] = offset # place MSD in 3rd dword
                offset += 3
            else:
                assert False

    def generate_case_max3(self, lengths, pshufb_pattern):
        offset = 0
        for i, l in enumerate(lengths):
            idx = i
            if l == 1:
                pshufb_pattern[2*idx + 1] = offset
                offset += 2
            elif l == 2:
                pshufb_pattern[2*idx + 0] = offset + 0
                pshufb_pattern[2*idx + 1] = offset + 1
                offset += 3
            elif l == 3:
                pshufb_pattern[2*idx + 0] = offset + 1
                pshufb_pattern[2*idx + 1] = offset + 2
                pshufb_pattern[2*idx + 8] = offset + 0
                offset += 4
            else:
                assert False

    def minvalues_max3(self, lengths):
        m = [0] * 8
        for i, l in enumerate(lengths):
            if l == 1:
                val = -1
            elif l == 2:
                val = 9
            elif l == 3:
                val = 99

            m[i] = val

        return m

    def generate_case(self, lengths):
        offset = 0
        pshufb_pattern = [-1] * 16

        ml = max(lengths)
        if ml == 1:
            self.generate_case_max1(lengths, pshufb_pattern)
        elif ml == 2:
            self.generate_case_max2(lengths, pshufb_pattern)
        elif ml == 3:
            self.generate_case_max3(lengths, pshufb_pattern)
        else:
            assert False

        w = self.write

        self.indent()
        self.write("{")
        img = ', '.join('%d' % idx for idx in pshufb_pattern)
        self.write("const __m128i pattern = _mm_setr_epi8(%s);" % img)
        self.write("const __m128i t1 = _mm_shuffle_epi8(t0, pattern);")
        if ml == 1:
            self.write("res.ipv4 = _mm_cvtsi128_si32(t1);")
        elif ml == 2:
            self.write("const uint32_t msd = _mm_extract_epi32(t1, 3);")
            self.write("if (haszero32(msd)) {")
            self.write("    res.err = errLeadingZeros;")
            self.write("    return res;")
            self.write("}")
            self.write("const uint64_t w01 = _mm_cvtsi128_si64(t1);")
            self.write("const uint32_t w0  = w01;")
            self.write("const uint32_t w1  = (w01 >> 32);")
            self.write("res.ipv4 = 10 * w1 + w0;")
        elif ml == 3:
            self.write("const __m128i mul = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);")
            self.write("const __m128i t2  = _mm_maddubs_epi16(t1, mul);")
            self.write("const __m128i t3  = _mm_alignr_epi8(t2, t2, 8);")
            self.write("const __m128i t4  = _mm_add_epi16(t3, t2);")

            minval = self.minvalues_max3(lengths)
            self.write("const __m128i minval = _mm_setr_epi16(%s);" % ', '.join(str(x) for x in minval))
            self.write("const __m128i maxval = _mm_set1_epi16(0x0100);")
            self.write("const __m128i gt = _mm_cmpgt_epi16(t4, minval);")
            self.write("const __m128i lt = _mm_cmplt_epi16(t4, maxval);")
            self.write("const __m128i ir = _mm_and_si128(gt, lt);")
            self.write("const uint64_t w1 = _mm_cvtsi128_si64(ir);")
            self.write("if (haszero64(w1)) {")
            self.write("    res.err = errInvalidInput;")
            self.write("    return res;")
            self.write("}")

            self.write("const __m128i t5  = _mm_packus_epi16(t4, t4);")
            self.write("const uint32_t w0 = _mm_cvtsi128_si32(t5);")
            self.write("res.ipv4 = w0;")
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
