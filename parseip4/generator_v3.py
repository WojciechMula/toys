import sys

class Generator:
    def __init__(self):
        self.ind = 0
        self.f = sys.stdout

    def generate(self):
        self.write("/* Code generated automatically; DO NOT EDIT */")
        self.indent()
        self.write("uint32_t tmp;")
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
        for i, l in enumerate(lengths):
            var = 'res.byte[%d]' % i
            if l == 1:
                self.write("%s = (byte[%d] - '0');" % (var, offset,))
                offset += 2
            elif l == 2:
                self.write("%s  = 10 * (byte[%d] - '0') + (byte[%d] - '0');" % (var, offset, offset + 1))
                self.write("if (%s < 10) { res.err = errLeadingZeros; break; }" % (var,))
                offset += 3
            elif l == 3:
                self.write("tmp = (byte[%d] - '0');" % (offset))
                self.write("tmp = 10 * tmp + (byte[%d] - '0');" % (offset + 1))
                self.write("tmp = 10 * tmp + (byte[%d] - '0');" % (offset + 2))
                self.write("if (tmp < 100) { res.err = errLeadingZeros; break; }")
                self.write("if (tmp > 255) { res.err = errTooBig; break; }")
                self.write("%s = tmp;" % (var,))
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
