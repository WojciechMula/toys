import sys
from benchmark_parser import *
from table import Table
from utils import unicode_bar

import sys
import codecs

sys.stdout = codecs.getwriter('utf-8')(sys.stdout)


def main():
    with open(sys.argv[1], 'rt') as f:
        data = parse(f)

    data = merge_many(data)
    update_speedup(data, field='avg')

    table = Table()
    table.add_header(["procedure", "best [cycles]", "average [cycles]", "speedup", ""])

    for name, measurement in data.iteritems():
        table.add_row([
            name,
            '%0.3f' % measurement.best,
            '%0.3f' % measurement.avg,
            '%0.2f' % measurement.speedup,
            '``%s``' % unicode_bar(5 * measurement.speedup)
        ])

    print unicode(table)


if __name__ == '__main__':
    main()
