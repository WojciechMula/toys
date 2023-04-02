import sys

class Generator:
    def __init__(self):
        self.ind = 0
        self.f = sys.stdout

    def generate(self):
        self.write("/* Code generated automatically; DO NOT EDIT */")
        self.write("uint32_t tmp;")
        self.indent()
        self.generate_switch()
        self.unindent()

    def generate_switch(self):
        self.write("switch (code) {")
        self.indent()
        for code in range(256):
            l3 = (code >> (0*2)) & 0x03
            l2 = (code >> (1*2)) & 0x03
            l1 = (code >> (2*2)) & 0x03
            l0 = (code >> (3*2)) & 0x03
            lengths = [l0, l1, l2, l3]
            if 0 not in lengths:
                self.write("case 0x%02x: // %s" % (code, lengths))
                self.indent()
                self.generate_case(lengths)
                self.unindent()

        self.unindent()
        self.write("}")

    def generate_case(self, lengths):
        offset = 0
        for i, l in enumerate(lengths):
            target = 'res.byte[%d]' % (i)
            if l == 1:
                self.write("%s = (data[%d] - '0');" % (target, offset,))
                offset += 2
            elif l == 2:
                self.write("%s  = 10 * (data[%d] - '0') + (data[%d] - '0');" % (target, offset, offset + 1))
                self.write("if (%s < 10) { res.err = errLeadingZeros; break; }" % (target,))
                offset += 3
            elif l == 3:
                self.write("tmp = (data[%d] - '0');" % (offset))
                self.write("tmp = 10 * tmp + (data[%d] - '0');" % (offset + 1))
                self.write("tmp = 10 * tmp + (data[%d] - '0');" % (offset + 2))
                self.write("if (tmp < 100) { res.err = errLeadingZeros; break; }")
                self.write("if (tmp > 255) { res.err = errTooBig; break; }")
                self.write("%s = tmp;" % (target,))
                offset += 4
            else:
                assert False

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

g = Generator()
g.generate()
