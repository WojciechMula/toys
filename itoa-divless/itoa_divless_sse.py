#!/usr/bin/env python3

def main():
    with open('itoa_divless_sse_table.h', 'wt') as f:
        lookup(f, 'lookup0', shift=0)
        lookup(f, 'lookup1', shift=8)
        lookup(f, 'lookup2', shift=16)
        lookup(f, 'lookup3', shift=24)


def lookup(f, name, shift):
    f.write(f'static uint8_t {name}[256][16] = {{\n')
    for i, values in enumerate(lookup_values(shift)):
        f.write('{%s}' % ', '.join(values))
        if i != 255:
            f.write(',')
        f.write('\n')

    f.write('};\n')


def lookup_values(shift):
    values = []
    for b in range(256):
        v = b << shift
        t = list(f'{v:016d}')
        values.append(t)

    return values


if __name__ == '__main__':
    main()
