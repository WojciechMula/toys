import sys
import itertools

class Item:
    def __init__(self, lengths):
        self.length = lengths

        offset = 0
        pattern = [0xff] * 16
        for i, l in enumerate(lengths):
            idx = i
            if l == 0:
                pattern[idx] = offset
                offset += 2
            elif l == 1:
                pattern[idx] = offset + 1
                pattern[idx + 4] = offset
                offset += 3
            elif l == 2:
                pattern[idx] = offset + 2
                pattern[idx + 4] = offset + 1
                pattern[idx + 8] = offset
                offset += 4
            else:
                assert False

        self.pattern = pattern
        self.max_digits = max(lengths) + 1
        self.val = 0
        for l, w in zip(lengths, [1, 3, 9, 27]):
            self.val += l * w

        self.code = 0
        n = 0
        for l in lengths:
            n += l + 1
            self.code |= 1 << n
            n += 1

        self.pattern[-1] = self.max_digits
        self.pattern[-2] = (self.code >> 8) & 0xff
        self.pattern[-3] = (self.code >> 0) & 0xff


class Generator:
    def __init__(self):
        self.ind = 0
        self.f = sys.stdout

    def generate(self):
        self.write("/* Code generated automatically; DO NOT EDIT */")
        self.indent()
        self.generate_table()
        self.unindent()

    def generate_table(self):
        all = []
        for l3, l2, l1, l0 in itertools.product(range(3), range(3), range(3), range(3)): 
            all.append(Item([l0, l1, l2, l3]))
        
        self.write("static const uint8_t patterns[81][16] = {")
        for item in all:
            img = ", ".join('%d' % x for x in item.pattern)
            self.write("/* %02d */ {%s}," % (item.val, img))
        self.unindent()
        self.write("};")

    def write(self, text):
        f = self.f
        f.write(' ' * self.ind)
        f.write(text)
        f.write('\n')

    def indent(self):
        self.ind += 4

    def unindent(self):
        self.ind -= 4


g = Generator()
g.generate()
