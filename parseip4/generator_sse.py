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

    def generate_conversion(self, maxlength):
        assert maxlength in (1, 2, 3)
        self.write("SSE_CONVERT_MAX%d" % maxlength)

    def generate_case(self, lengths):
        ml = max(lengths)
        pshufb_pattern = generate_pshufb_pattern(lengths)

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


def generate_pshufb_pattern(lengths):
    ml = max(lengths)
    if ml == 1:
        return generate_pshufb_pattern_max1(lengths)
    elif ml == 2:
        return generate_pshufb_pattern_max2(lengths)
    elif ml == 3:
        return generate_pshufb_pattern_max3(lengths)
    else:
        assert False


def generate_pshufb_pattern_max1(lengths):
    pshufb_pattern = [-1] * 16
    offset = 0
    for i, l in enumerate(lengths):
        idx = i
        if l == 1:
            pshufb_pattern[idx] = offset
            offset += 2
        else:
            assert False

    return pshufb_pattern


def generate_pshufb_pattern_max2(lengths):
    pshufb_pattern = [-1] * 16
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

    return pshufb_pattern


def generate_pshufb_pattern_max3(lengths):
    pshufb_pattern = [-1] * 16
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

    return pshufb_pattern


def uint8(x):
    if x < 0:
        return "uint8_t(%d)" % x
    else:
        return str(x)
