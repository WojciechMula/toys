import sys
import codecs

from benchmark_parser import parse, update_speedup, get_maximum_speedup
from table import Table
from utils import unicode_bar

sys.stdout = codecs.getwriter('utf-8')(sys.stdout)


def main():
    with open(sys.argv[1], 'rt') as f:
        data = parse(f)
        update_speedup(data, 'scalar')
        data = data[0]

    table = Table()
    table.add_header(["procedure", ("time in cycles per byte", 2), ("speed-up", 2)])
    table.add_header(["", "average", "best", "", ""])

    for procedure in data:
        m = data[procedure]

        row = [
            procedure,
            '%0.3f' % m.avg,
            '%0.3f' % m.best,
            '%0.1f' % m.speedup,
            '``%s``' % unicode_bar(40 * m.speedup / get_maximum_speedup(data))
        ]

        table.add_row(row)

    print unicode(table)


if __name__ == '__main__':
    main()
