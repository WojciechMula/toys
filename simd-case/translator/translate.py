import re
import sys

start = re.compile('^\s+//\sSIMD-case-start')
end   = re.compile('^\s+//\sSIMD-case-end')
case  = re.compile('case\s+([a-zA-Z_0-9]+)\s*:')

INSIDE  = 1
OUTSIDE = 2


class Case(object):
    def __init__(self, value):
        self.value = int(value)
        self.lines = []


class Parser(object):
    def __init__(self, iter):
        self.iter = iter


    def parse(self):
        self.location = OUTSIDE
        self.result = []
        self.cases  = []

        for line in self.iter:
            line = line.rstrip()
            #print '#', line
            self.dispatch(line)


        return self.result


    def dispatch(self, line):
        if start.match(line):
            assert self.location == OUTSIDE
            self.location = INSIDE
            return

        if end.match(line):
            assert self.location == INSIDE
            self.location = OUTSIDE
            self.flush()
            return

        if self.location == OUTSIDE:
            self.result.append(line)
        else:
            line = line.strip()
            if line:
                self.handle_line(line)


    def handle_line(self, line):
        m = case.match(line)
        if m:
            value = m.groups()[0]
            self.cases.append(Case(value))
        else:
            self.cases[-1].lines.append(line.lstrip())
            

    def flush(self):
        indent = ' ' * 4
        for case in self.cases:
            assert case.lines[-1] == 'break;'
            del case.lines[-1]

        self.result.append(self.cases)

        self.cases = []


class SIMDWriter(object):
    def __init__(self, cases, min_value, max_value, max_items):
        self.cases = cases

        self.min_value = min_value
        self.max_value = max_value
        self.max_items = max_items
        self.all_used  = (len(cases) == self.max_items)
        

    def feasible(self):
        s = set(c.value for c in self.cases)
        assert len(self.cases) == len(s)

        if len(s) > self.max_items:
            return False

        if max(s) > self.max_value:
            return False

        if min(s) < self.min_value:
            return False

        return True


    def generate(self):
        code = []

        code.append(self.generate_labels_array())
        code.extend(self.declare_case_vector())
        code.append(self.declare_input_vector())
        code.extend(self.get_index())

        indent = ' ' * 4
        for case in self.cases:
            code.append('%s:' % self.get_label(case))
            for line in case.lines:
                code.append(indent + line)
            else:
                code.append(indent + 'goto %s;' % self.get_end_label())
        else:
            code.append('%s:' % self.get_end_label())

            # if label is the last item in function GCC says: "expected primary-expression before '}'"   
            code.append(indent + ';')


        return code

    
    def generate_labels_array(self):
        tmp = []
        for case in self.cases:
            tmp.append('&&' + self.get_label(case))

        if not self.all_used:
            while len(tmp) < self.max_items:
                tmp.append('&&' + self.get_end_label())

        return 'static void* lookup[] = {%s};' % ', '.join(tmp)


    def get_label(self, case):
        return 'label_%x' % case.value


    def get_end_label(self):
        return 'label_end_switch'


class SSEWriter(SIMDWriter):
    def __init__(self, cases):
        super(SSEWriter, self).__init__(cases, 0, 65535, 128/16)


    def declare_case_vector(self):
        tmp = ['0x%04x' % c.value for c in self.cases]
        while len(tmp) < self.max_items:
            tmp.append(tmp[-1])

        return 'const __m128i cases = _mm_set_epi16(%s);' % (', '.join(tmp))


    def declare_input_vector(self):
        return 'const __m128i input = _mm_set1_epi16(x);'


    def get_index(self):
        if self.all_used:
            return [
                'const uint16_t mask = _mm_movemask_epi8(_mm_cmpeq_epi16(input, cases));',
                'if (mask == 0) goto %s;' % self.get_end_label(),
                'goto *lookup[__builtin_ctz(mask)];'
            ]
        else:
            full_16bit  = 0xffff
            unused_mask = (full_16bit << (len(self.cases))) & full_16bit

            return [
                'const uint16_t unused_mask = 0x%04x;' % unused_mask,
                'const uint16_t mask = _mm_movemask_epi8(_mm_cmpeq_epi16(input, cases)) | unused_mask;',
                'goto *lookup[__builtin_ctz(mask)];'
            ]


class SSE2REGWriter(SIMDWriter):
    def __init__(self, cases):
        super(SSE2REGWriter, self).__init__(cases, 0, 65535, 16)


    def declare_case_vector(self):
        tmp = ['0x%04x' % c.value for c in self.cases]
        while len(tmp) < self.max_items:
            tmp.append(tmp[-1])

        return [
            'const __m128i cases0 = _mm_set_epi16(%s);' % (', '.join(tmp[0:8])),
            'const __m128i cases1 = _mm_set_epi16(%s);' % (', '.join(tmp[8:16]))
        ]


    def declare_input_vector(self):
        return 'const __m128i input = _mm_set1_epi16(x);'


    def get_index(self):
        tmp = []

        tmp.append('const __m128i eq0 = _mm_cmpeq_epi16(input, cases0);')
        tmp.append('const __m128i eq1 = _mm_cmpeq_epi16(input, cases1);')
        tmp.append('const __m128i eq  = _mm_packs_epi16(eq0, eq1);')

        if self.all_used:
            tmp.extend([
                'const uint16_t mask = _mm_movemask_epi8(eq);',
                'if (mask == 0) goto %s;' % self.get_end_label(),
                'goto *lookup[__builtin_ctz(mask)];'
            ])
        else:
            full_16bit  = 0xffff
            unused_mask = (full_16bit << (2*len(self.cases))) & full_16bit

            tmp.extend([
                'const uint16_t unused_mask = 0x%04x;' % unused_mask,
                'const uint16_t mask = _mm_movemask_epi8(eq) | unused_mask;',
                'goto *lookup[__builtin_ctz(mask)];'
            ])

        return tmp


def main():
    with open(sys.argv[1]) as f:
        p = Parser(f)
        for item in p.parse():
            if type(item) is str:
                print item
                continue

            g = SSE2REGWriter(item)
            assert g.feasible()

            for line in g.generate():
                print line


if __name__ == '__main__':
    main()
