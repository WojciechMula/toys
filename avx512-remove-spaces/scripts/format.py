import sys
from table import Table
from parse import load

def main():
    path = sys.argv[1]

    with open(path) as f:
        data = load(f)

    tbl = format_table(data)
    print tbl


def format_table(data):
    table = Table()
    table.add_header(["number of spaces",
                      ("scalar [cycles/byte]", 3),
                      ("AVX512VBMI [cycles/byte]", 3),
                      ("AVX512VBMI (Travis) [cycles/byte]", 3),
                      ("AVX512VBMI (Zach) [cycles/byte]", 3)])
    table.add_header(["",
                      "avg (min)", "avg (max)", "best",
                      "avg (min)", "avg (max)", "best",
                      "avg (min)", "avg (max)", "best",
                      "avg (min)", "avg (max)", "best",
                     ])
    
    for cardinality in xrange(1, 64+1):
        scalar, avx512, avx512_travis, avx512_zach = data[cardinality]

        table.add_row([
            '%d' % cardinality,
            '%0.3f' % min(scalar.values),
            '%0.3f' % max(scalar.values),
            '%0.3f' % scalar.best,
            '%0.3f' % min(avx512.values),
            '%0.3f' % max(avx512.values),
            '%0.3f' % avx512.best,
            '%0.3f' % min(avx512_travis.values),
            '%0.3f' % max(avx512_travis.values),
            '%0.3f' % avx512_travis.best,
            '%0.3f' % min(avx512_zach.values),
            '%0.3f' % max(avx512_zach.values),
            '%0.3f' % avx512_zach.best,
        ])

    return table


if __name__ == '__main__':
    main()

