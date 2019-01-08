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
    keys  = data[1].keys()

    # prepare header
    header1 = ["number of spaces"]
    header2 = [""]
    for key in keys:
        header1.append(("%s [cycles/byte]" % key, 3))
        header2.extend(["avg (min)", "avg (max)", "best"])

    table.add_header(header1)
    table.add_header(header2)

    # add data
    for cardinality in xrange(1, 64+1):
        row = ['%d' % cardinality]
        measurements = data[cardinality]
        for meas in measurements.values():
            row.append('%0.3f' % min(meas.values))
            row.append('%0.3f' % max(meas.values))
            row.append('%0.3f' % meas.best)

        table.add_row(row)

    return table


if __name__ == '__main__':
    main()

