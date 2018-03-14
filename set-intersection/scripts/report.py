import sys
from collections import OrderedDict
from table import Table

def load(file):

    result = OrderedDict()

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

    return result


def main():

    with open(sys.argv[1], 'rt') as f:
        data = load(f)

    table = Table()
    table.set_header(["size A", "size B", "size ratio", "std [us]", "SSE [us]", "binsearch [us]"])

    for key, values in data.iteritems():
        small_size, large_size = key

        std_time = values["std"]
        sse_time = values["SSE"]
        bs_time  = values["binsearch"]

        table.add_row([
            '%d' % small_size,
            '%d' % large_size,
            '%0.2f' % (large_size/float(small_size)),
            '%d' % std_time,
            '%d' % sse_time,
            '%d' % bs_time])

        def speedup(base, new):
            try:
                coef = base/float(new)
            except ZeroDivisionError:
                coef = float(base)

            return 'x %0.2f' % coef

        table.add_row([
            "",
            "",
            "",
            "",
            speedup(std_time, sse_time),
            speedup(std_time, bs_time),
        ])

    print table

if __name__ == '__main__':
    main()
