import sys
from table import Table

def main():
    path_input  = sys.argv[1]
    path_output = sys.argv[2]

    with open(path_input) as f:
        data = load(f)

    s = str(format_table(data))
    with open(path_output, 'wt') as f:
        f.write(s)


def load(file):
    data = {}
    size = None

    for line in file:
        F = line.split()
        if F[0] == 'File':
            size = F[1]
            assert size[-1] == 'M'
            size = int(size[:-1])
            continue

        assert size is not None
        if size not in data:
            data[size] = [None, None, None]

        F = line.split(': .', 2)
        name = F[0].strip()
        time = int(F[1].split()[1])
        if name == "C++ istreambuf_iterator":
            index = 0
        elif name == "C++ stream::rdbuf":
            index = 1
        elif name == "libc fread":
            index = 2
        else:
            print "'%s'" % name
            assert False

        data[size][index] = time

    return data


def format_table(data):
    table = Table()
    table.add_header(["size [MB]",
                      "istreambuf_iterator",
                      ("stream::rdbuf", 2),
                      ("LibC fread", 2)])
    table.add_header(["",
                      "time [us]",
                      "time [us]", "speed-up",
                      "time [us]", "speed-up"])

    for size in sorted(data):
        iterator_time, rdbuf_time, fread_time = data[size]       
        rdbuf_speedup = float(iterator_time) / rdbuf_time;
        fread_speedup = float(iterator_time) / fread_time;

        table.add_row([
            '%d' % size,
            '%d' % iterator_time,
            '%d' % rdbuf_time,
            '%0.2f' % rdbuf_speedup,
            '%d' % fread_time,
            '%0.2f' % fread_speedup,
        ])


    return table


if __name__ == '__main__':
    main()
