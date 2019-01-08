import sys
from table import Table
from parse_speed import load

def main():
    path = sys.argv[1]

    with open(path) as f:
        data = load(f)

    tbl = format_table(data)
    print tbl


def format_table(data):
    keys = [name for (name, time) in data.values()[0]]

    table = Table()

    # prepare header
    header1 = ["file"]
    header2 = [""]
    for key in keys:
        header1.append((key, 2))
        header2.append("time [us]")
        header2.append("speed-up")

    table.add_header(header1)
    table.add_header(header2)

    # add data
    for file in data:
        measurements = data[file]
        row = [file]
        reference_time = None
        for (name, time) in measurements:
            row.append('%d' % time)
            if reference_time is None:
                reference_time = float(time)
                row.append('')
            else:
                speedup = reference_time / time
                row.append('%0.2f' % speedup)

        table.add_row(row)

    return table


if __name__ == '__main__':
    main()
