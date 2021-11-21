#!/usr/bin/env python3

def main():
    with open('itoa_divless_table.h', 'wt') as f:
        lookup(f, 'lookup0', shift=0, half=True)
        lookup(f, 'lookup1', shift=8, half=True)
        lookup(f, 'lookup2', shift=16)
        lookup(f, 'lookup3', shift=24)


def lookup(f, name, shift, half=False):
    if half:
        size = 8
    else:
        size = 16

    f.write(f'static uint8_t {name}[256][{size}] = {{\n')
    for i, values in enumerate(lookup_values(shift, half)):
        f.write('{%s}' % ', '.join(values))
        if i != 255:
            f.write(',')
        f.write('\n')

    f.write('};\n')


def lookup_values(shift, half):
    values = []
    for b in range(256):
        v = b << shift
        img = f'{v:016d}'
        if half:
            assert img[:8] == '00000000', "it's expected that higher 8 chars are zero"
            t = list(img[8:])
        else:
            t = list(img)
        values.append(t)

    return values


if __name__ == '__main__':
    main()
