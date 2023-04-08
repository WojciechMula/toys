import sys
import itertools
from generator_sse import GeneratorSSE, generate_pshufb_pattern, uint8

class Generator(GeneratorSSE):
    def __init__(self):
        super().__init__()
        self.return_on_error = False

    def generate_main(self):
        code = list(self._generate())

        tmp = []
        for length, n in code:
            img = ', '.join(map(uint8, generate_pshufb_pattern(length)))
            tmp.append("{%s}" % img)

        self.write("static uint8_t patterns[81][16] = {")
        self.indent()
        for i, img in enumerate(tmp):
            last = (i == len(tmp) - 1)
            if last:
                self.write(img)
            else:
                self.write(img + ',')

        self.unindent()
        self.write("};")

        self.write("const __m128i pattern = _mm_loadu_si128((const __m128i*)&patterns[code]);")
        self.write("switch (code) {")
        self.indent()
        for ml in [1, 2, 3]:
            for lengths, n in code:
                if max(lengths) == ml:
                    self.write("case 0x%02x: // %s" % (n, lengths))

            self.write("{")
            self.indent()
            self.generate_conversion(ml)
            self.unindent()
            self.write("}")
            self.write("break;")

        self.unindent()
        self.write("}")

    def _generate(self):
        for l0, l1, l2, l3 in itertools.product(range(3), range(3), range(3), range(3)):
            n = l3 * 1 + l2 * 3 + l1 * 9 + l0 * 27
            yield ([l0 + 1, l1 + 1, l2 + 1, l3 + 1], n)


if __name__ == '__main__':
    g = Generator()
    g.generate()
