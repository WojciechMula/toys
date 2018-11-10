import sys

from collections import OrderedDict
from benchmark_parser import parse, update_speedup

from table import Table

def main():
    with open(sys.argv[1], 'rt') as f:
        data = load(f)

    format_table(data)


def load(file):
    data = parse(file)
    update_speedup(data, reference_key='SSE')

    d = {}
    for item in data:
        if type(item) is str:
            size, count = parse_size_count(item)
            key = (size, count)
        else:
            assert type(item) is OrderedDict
            assert key not in d

            d[key] = item

    return d


def parse_size_count(s):
    # s = "vector size=<num>, count=<num>"
    s = s.replace('=', ' ')
    s = s.replace(',', ' ')
    F = s.split()
    
    return int(F[2]), int(F[-1])


def format_table(data):
    vector_size  = list(set(key[0] for key in data.iterkeys()))
    vector_count = list(set(key[1] for key in data.iterkeys()))
    procedures   = data.values()[0].keys()

    vector_size.sort()
    vector_count.sort()

    # prepare header
    table = Table()
    table.add_header(["procedure"] + [("%d vectors" % c, 3) for c in vector_count])
    h = [""]
    t = ["best", "avg", "speedup"]
    for _ in vector_count:
        h.extend(t)
    table.add_header(h)
    
    # prepare data
    for size in vector_size:
        table.add_row([("*size %d*" % size, len(vector_count)*3 + 1)])
        for procedure in procedures:
            row = []
            row.append(procedure)

            for count in vector_count:
                key = (size, count)
                measurement = data[key]
                row.append('%0.3f' % measurement[procedure].best)
                row.append('%0.3f' % measurement[procedure].avg)
                row.append('%0.2f' % measurement[procedure].speedup)

            table.add_row(row)

    print table

if __name__ == '__main__':
    main()

