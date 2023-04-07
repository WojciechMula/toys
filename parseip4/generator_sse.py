import sys

class GeneratorSSE:
    def __init__(self):
        self.ind = 0
        self.f = sys.stdout
        self.return_on_error = True

    def generate(self):
        self.write("/* Code generated automatically; DO NOT EDIT */")
        self.indent()
        self.generate_main()
        self.unindent()

    def generate_main(self):
        raise NotImplementedError

    def generate_pshufb_pattern_max1(self, lengths, pshufb_pattern):
        offset = 0
        for i, l in enumerate(lengths):
            idx = i
            if l == 1:
                pshufb_pattern[idx] = offset
                offset += 2
            else:
                assert False

    def generate_pshufb_pattern_max2(self, lengths, pshufb_pattern):
        offset = 0
        for i, l in enumerate(lengths):
            idx = i
            if l == 1:
                pshufb_pattern[idx + 4] = offset
                offset += 2
            elif l == 2:
                pshufb_pattern[idx] = offset
                pshufb_pattern[idx + 4] = offset + 1
                offset += 3
            else:
                assert False

    def generate_pshufb_pattern_max3(self, lengths, pshufb_pattern):
        offset = 0
        for i, l in enumerate(lengths):
            idx = i
            if l == 1:
                pshufb_pattern[2*idx + 1] = offset
                offset += 2
            elif l == 2:
                pshufb_pattern[2*idx + 0] = offset + 0
                pshufb_pattern[2*idx + 1] = offset + 1
                pshufb_pattern[2*idx + 8 + 1] = offset + 0
                offset += 3
            elif l == 3:
                pshufb_pattern[2*idx + 0] = offset + 1
                pshufb_pattern[2*idx + 1] = offset + 2
                pshufb_pattern[2*idx + 8] = offset + 0
                pshufb_pattern[2*idx + 8 + 1] = offset + 0
                offset += 4
            else:
                assert False

    def generate_pshufb_pattern(self, lengths):
        pshufb_pattern = [-1] * 16

        ml = max(lengths)
        if ml == 1:
            self.generate_pshufb_pattern_max1(lengths, pshufb_pattern)
        elif ml == 2:
            self.generate_pshufb_pattern_max2(lengths, pshufb_pattern)
        elif ml == 3:
            self.generate_pshufb_pattern_max3(lengths, pshufb_pattern)
        else:
            assert False

        return pshufb_pattern

    def generate_conversion(self, maxlength):
        self.write("const __m128i t1 = _mm_shuffle_epi8(t0, pattern);")
        if maxlength == 1:
            self.write("res.ipv4 = _mm_cvtsi128_si32(t1) & 0x0f0f0f0f;")
        elif maxlength == 2:
            self.write("const __m128i ascii0 = _mm_set1_epi8('0');")
            self.write("const __m128i t2     = _mm_cmpeq_epi8(t1, ascii0);")
            self.write("const uint32_t msd = _mm_cvtsi128_si32(t2);")
            self.write("if (msd != 0) {")
            self.write("    res.err = errLeadingZeros;")
            if self.return_on_error:
                self.write("    return res;")
            self.write("}")
            self.write("const uint64_t ascii = _mm_cvtsi128_si64(t1);")
            self.write("const uint64_t w01   = ascii & 0x0f0f0f0f0f0f0f0f;")
            self.write("const uint32_t w0    = w01 >> 32;")
            self.write("const uint32_t w1    = w01 & 0xfffffffflu;")
            self.write("res.ipv4 = 10 * w1 + w0;")
        elif maxlength == 3:
            self.write("const __m128i ascii0  = _mm_set1_epi8('0'); // 0x30")
            self.write("const __m128i eq0     = _mm_cmpeq_epi8(t1, ascii0);")
            self.write("const uint16_t eqmask = _mm_movemask_epi8(eq0);")
            self.write("if ((eqmask & 0xaa00) != 0) {")
            self.write("    res.err = errLeadingZeros;")
            if self.return_on_error:
                self.write("    return res;")
            self.write("}")
            self.write("const __m128i t2 = _mm_subs_epu8(t1, ascii0);")
            self.write("const __m128i weights = _mm_setr_epi8(10, 1, 10, 1, 10, 1, 10, 1, 100, 0, 100, 0, 100, 0, 100, 0);")
            self.write("const __m128i t3 = _mm_maddubs_epi16(t2, weights);")
            self.write("const __m128i t4 = _mm_alignr_epi8(t3, t3, 8);")
            self.write("const __m128i t5 = _mm_add_epi16(t4, t3);")
            self.write("const __m128i gt        = _mm_cmpgt_epi16(t5, _mm_set1_epi16(255));")
            self.write("const uint16_t gtmask   = _mm_movemask_epi8(gt);")
            self.write("if ((gtmask & 0x00ff) != 0) {")
            self.write("    res.err = errTooBig;")
            if self.return_on_error:
                self.write("    return res;")
            self.write("}")
            self.write("const __m128i t6 = _mm_packus_epi16(t5, t5);")
            self.write("res.ipv4 = _mm_cvtsi128_si32(t6);")
        else:
            assert False

    def generate_case(self, lengths):
        ml = max(lengths)
        pshufb_pattern = self.generate_pshufb_pattern(lengths)

        self.indent()
        self.write("{")
        img = ', '.join('%d' % idx for idx in pshufb_pattern)
        self.write("const __m128i pattern = _mm_setr_epi8(%s);" % img)
        self.generate_conversion(ml)
        self.write("}")
        self.unindent()

    def write(self, text):
        f = self.f
        f.write(' ' * self.ind)
        f.write(text)
        f.write('\n')

    def indent(self):
        self.ind += 4

    def unindent(self):
        self.ind -= 4
