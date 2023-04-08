import sys
import itertools
from generator_sse import GeneratorSSE, generate_pshufb_pattern, uint8

class Item:
    def __init__(self, lengths):
        self.length = lengths
        self.pshufb_pattern = generate_pshufb_pattern(lengths)
        self.max_digits = max(lengths)
        self.val = 0
        for l, w in zip(lengths, [1, 3, 9, 27]):
            self.val += (l - 1) * w

        self.code = 0
        n = 0
        for l in lengths:
            n += l
            self.code |= 1 << n
            n += 1

        self.pshufb_pattern.extend([0]*4)
        assert len(self.pshufb_pattern) == 20

        self.pshufb_pattern[16] = (self.code >> 0) & 0xff
        self.pshufb_pattern[17] = (self.code >> 8) & 0xff
        self.pshufb_pattern[18] = self.max_digits


class Generator(GeneratorSSE):
    def generate_main(self):
        all = []
        for l3, l2, l1, l0 in itertools.product(range(1, 4), range(1, 4), range(1, 4), range(1, 4)):
            all.append(Item([l0, l1, l2, l3]))
        
        self.write("static const uint8_t patterns[81][20] = {")
        for item in all:
            img = ", ".join(uint8(x) for x in item.pshufb_pattern)
            self.write("/* %02d */ {%s}," % (item.val, img))
        self.unindent()
        self.write("};")


if __name__ == '__main__':
    g = Generator()
    g.generate()
