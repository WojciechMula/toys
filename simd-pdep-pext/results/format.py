import sys

from benchmark_parser import parse, update_speedup, get_maximum_speedup
from table import Table
from utils import unicode_bar


def main():
    path = sys.argv[1]
    if 'pext' in path:
        reference = 'pext scalar'
    elif 'pdep' in path:
        reference = 'pdep scalar'
    else:
        assert False, path

    with open(path, 'rt') as f:
        data = parse(f)
        update_speedup(data, reference)

    table = Table()
    table.add_header(["procedure", ("time in cycles per byte", 2), ("speed-up", 2)])
    table.add_header(["", "average", "best", "", ""])

    for i in range(0, len(data), 2):
        raw_label = data[i]
        group     = data[i + 1]

        row = [(label[raw_label], 5)]
        table.add_row(row)

        for procedure in group:
            m = group[procedure]

            row = [
                procedure,
                '%0.3f' % m.avg,
                '%0.3f' % m.best,
                '%0.1f' % m.speedup,
                '``%s``' % unicode_bar(40 * m.speedup / get_maximum_speedup(group))
            ]

            table.add_row(row)

    print(table)


label = {
    "testing any mask"                              : "any 32-bit mask",
    "testing mask having no more than 6 bits set"   : "mask has no more than 6 bits",
    "testing mask having no more than 8 bits set"   : "mask has no more than 8 bits",
    "testing mask having no more than 16 bits set"  : "mask has no more than 16 bits",
    "testing mask having no more than 24 bits set"  : "mask has no more than 24 bits",
}


if __name__ == '__main__':
    main()
