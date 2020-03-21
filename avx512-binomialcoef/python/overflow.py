#!/usr/bin/env python3

import sys
from PIL import Image, ImageDraw
from factor import FactorialNumber, precalculate

def binomial_fraction(n, k):
    p = min(k, n - k)

    num = 1
    denom = 1
    for i in range(p):
        num   *= n - p + (i + 1)
        denom *= (i + 1)

    return (num, denom)

numbers = list(precalculate())
primes = numbers[0].primes

def avx512_binomial_algorithm(n, k):
    p = min(k, n - k)

    num = FactorialNumber([], primes)
    denom = FactorialNumber([], primes)
    for i in range(p):
        num_coef   = n - p + (i + 1)
        denom_coef = i + 1

        num   += numbers[num_coef]
        denom += numbers[denom_coef]

    num -= denom

    return num


maxint = 2**64 - 1

def scalar_binomial_overflow(n, k):
    num, denom = binomial_fraction(n, k)
    return num > maxint or denom > maxint


def avx512_binomial_overflow(n, k):
    divided = avx512_binomial_algorithm(n, k)
    num = 1
    denom = 1
    for (base, power) in divided:
        if power > 0:
            num *= base**power
        elif power < 0:
            denom *= base**power

    return num > maxint or denom > maxint


BOTH_VALID   = 0
SCALAR_VALID = 1
AVX512_VALID = 2
NONE_VALID   = 3

class Parameters:
    def __init__(self):
        self.cell_size = 3
        self.spacing = 2
        self.padding = 4
        self.background = '#000'
        self.colors = {
            BOTH_VALID: '#0f0',
            NONE_VALID: '#f00',
            SCALAR_VALID: '#ff0',
            AVX512_VALID: '#fff'
        }

    def size(self, n):
        return self.cell_size * n + \
               self.spacing * (n - 1) + \
               self.padding * 2


def draw_grid(num_range, params, overflow):
    size = params.size(num_range)
    img = Image.new('RGB', (size, size))
    draw = ImageDraw.Draw(img)
    draw.rectangle((0, 0, img.width, img.height), fill=params.background)

    for n in range(1, num_range + 1):
        y = (n - 1) * (params.cell_size + params.spacing) + params.padding
        for k in range(1, num_range + 1):
            idx = overflow(n, k)
            color = params.colors[idx]
            x = (k - 1) * (params.cell_size + params.spacing) + params.padding
            draw.rectangle((x, y, x + params.cell_size, y + params.cell_size), fill=color)

    return img


def main():
    if len(sys.argv) <= 1:
        print(f"usage: {sys.argv[0]} output-file")
        sys.exit(1)

    params = Parameters()
    num_range = 128

    def overflow(n, k):
        scalar_overflow = scalar_binomial_overflow(n, k)
        avx512_overflow = avx512_binomial_overflow(n, k)
        if scalar_overflow and avx512_overflow:
            return NONE_VALID

        if not scalar_overflow and not avx512_overflow:
            return BOTH_VALID

        if scalar_overflow:
            assert not avx512_overflow
            return AVX512_VALID
        else:
            assert avx512_overflow
            return SCALAR_VALID

    img = draw_grid(num_range, params, overflow)
    img.save(sys.argv[1])


if __name__ == '__main__':
    main()
