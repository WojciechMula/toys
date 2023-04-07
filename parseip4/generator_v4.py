import sys
from generator_sse import GeneratorSSE

class Generator(GeneratorSSE):
    def __init__(self):
        super().__init__()

    def generate_main(self):
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
        self.write("const __m128i t0 = input;")
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
                self.write("break;")
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


if __name__ == '__main__':
    g = Generator()
    g.generate()
