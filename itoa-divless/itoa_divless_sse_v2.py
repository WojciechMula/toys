#!/usr/bin/env python3

def main():
    with open('itoa_divless_sse_v2_table.h', 'wt') as f:
        lookup(f, 'lookup0', shift=0, half=True)
        lookup(f, 'lookup1', shift=8, half=True, adjust=True)
        lookup(f, 'lookup2', shift=16)
        lookup(f, 'lookup3', shift=24, adjust=True)


def lookup(f, name, shift, half=False, adjust=False):
    if half:
        size = 8
    else:
        size = 16

    f.write(f'static uint8_t {name}[256][{size}] = {{\n')
    for i, values in enumerate(lookup_values(shift, half, adjust)):
        f.write('{%s}' % ', '.join(values))
        if i != 255:
            f.write(',')
        f.write('\n')

    f.write('};\n')


def lookup_values(shift, half, adjust):
    values = []
    for b in range(256):
        v = b << shift
        img = f'{v:016d}'
        if half:
            assert img[:8] == '00000000', "it's expected that higher 8 chars are zero"
            t = list(img[8:])
        else:
            t = list(img)

        if adjust:
            t = map(int, t)
            t = ['%d' % (x + 255 - 9) for x in t]

        values.append(list(reversed(t)))

    return values


if __name__ == '__main__':
    main()

