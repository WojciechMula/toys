import sys

from benchmark_parser import parse, update_speedup, get_maximum_speedup
from table import Table
from utils import unicode_bar


def main():
    path = sys.argv[1]
    reference = "std"
    with open(path, 'rt') as f:
        data = parse(f)
        update_speedup(data, reference)

    table = Table()
    table.add_header(["procedure", ("time in cycles per byte", 2), ("speed-up", 2)])
    table.add_header(["", "average", "best", "", ""])

    for i in range(0, len(data), 2):
        label = data[i]
        group = data[i + 1]

        row = [(label, 5)]
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


if __name__ == '__main__':
    main()
