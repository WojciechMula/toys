import sys
import itertools
from generator_sse import GeneratorSSE

class Generator(GeneratorSSE):
    def __init__(self):
        super().__init__()

    def generate_main(self):
        self.write("const __m128i t0 = input;")
        self.write("switch (code) {")
        for lengths, n in self._generate():
            self.indent()
            self.write("case %d: // %s" % (n, lengths))
            self.generate_case(lengths)
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
