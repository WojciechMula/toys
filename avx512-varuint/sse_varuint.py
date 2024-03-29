from itertools import chain


def main():
    shuffle_patterns = []
    input_lengths = []

    shuffle_patterns.append('uint8_t shuffle_patterns[256][16] = {')
    input_lengths.append('int input_lengths[256] = {')
    indent = ' ' * 4
    for i, (size, indices) in enumerate(pshufb_lookup()):
        fmt = ', '.join(map(str, indices))
        if i < 255:
            shuffle_patterns.append("%s{%s}," % (indent, fmt))
        else:
            shuffle_patterns.append("%s{%s}" % (indent, fmt))

        if i < 255:
            input_lengths.append('%s%d,' % (indent, size))
        else:
            input_lengths.append('%s%d' % (indent, size))

    shuffle_patterns.append('};')
    input_lengths.append('};')

    header = ["// generated by sse_varuint.py"]
    path = 'sse_varuint.incl.cpp'
    with open(path, 'wt') as f:
        for line in chain(header, shuffle_patterns, [""], input_lengths):
            f.write(line)
            f.write('\n')

    print("Generated %s" % path)


def pshufb_lookup():
    for c in range(256):
        code0 = (c >> (0*2)) & 0x3
        code1 = (c >> (1*2)) & 0x3
        code2 = (c >> (2*2)) & 0x3
        code3 = (c >> (3*2)) & 0x3

        indices = []
        size    = 0

        idx = 0

        for index, code in enumerate([code0, code1, code2, code3]):
            bytes = code + 1
            size += bytes

            tmp = []
            for i in range(bytes):
                tmp.append(idx)
                idx += 1

            while len(tmp) < 4:
                tmp.append(0x80)

            indices.extend(tmp)

        yield (size, indices)


if __name__ == '__main__':
    main()
