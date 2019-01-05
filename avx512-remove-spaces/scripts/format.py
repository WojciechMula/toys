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
                      "speedup (avg)"])
    table.add_header(["",
                      "avg (min)", "avg (max)", "best",
                      "avg (min)", "avg (max)", "best",
                      ""])
    
    for cardinality in xrange(1, 64+1):
        scalar, avx512 = data[cardinality]

        speedup = scalar.get_avg() / avx512.get_avg()

        table.add_row([
            '%d' % cardinality,
            '%0.3f' % min(scalar.values),
            '%0.3f' % max(scalar.values),
            '%0.3f' % scalar.best,
            '%0.3f' % min(avx512.values),
            '%0.3f' % max(avx512.values),
            '%0.3f' % avx512.best,
            '%0.2f' % speedup
        ])

    return table


if __name__ == '__main__':
    main()

