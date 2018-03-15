import sys
from collections import OrderedDict
from table import Table

def load(file):

    result = OrderedDict()
    procedures = set()

    for line in file:
        tmp = line.split(',')

        proc = tmp[0]
        small_size = int(tmp[1])
        large_size = int(tmp[2])
        time_us = int(tmp[3])

        key = (small_size, large_size)

        if key not in result:
            result[key] = {}

        result[key][proc] = time_us
        procedures.add(proc)

    return (procedures, result)


def main():

    with open(sys.argv[1], 'rt') as f:
        available_procedures, data = load(f)
   
    procedures = ["std", "SSE", "AVX2", "binsearch"]

    header = ["size A", "size B", "size ratio"]
    for proc in procedures:
        if proc in available_procedures:
            header.append("%s [us]" % proc)

    table = Table()
    table.set_header(header)

    for key, values in data.iteritems():
        small_size, large_size = key

        row = [
            '%d' % small_size,
            '%d' % large_size,
            '%0.2f' % (large_size/float(small_size)),
        ]

        for proc in procedures:
            if proc in available_procedures:
                row.append('%d' % values[proc])

        table.add_row(row)

        def speedup(base, new):
            try:
                coef = base/float(new)
            except ZeroDivisionError:
                coef = float(base)

            return 'x %0.2f' % coef

        row = ["", "", "", ""]
        for proc in procedures:
            if proc != 'std' and proc in available_procedures:
                row.append(speedup(values['std'], values[proc]))

        table.add_row(row)

    print table

if __name__ == '__main__':
    main()
