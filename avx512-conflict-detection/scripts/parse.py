import sys
from table import Table

def main():
    with open(sys.argv[1]) as f:
        input_size, maxint_values, data = parse(f)

    t = Table()
    t.add_header(['size [32-bit words]', 'Intel algorithm [MB/s]', 'Alternative algorithm [MB/s]', 'Speedup'])
    for srt in [False, True]:
        for maxint in sorted(maxint_values):
            t.add_row([(format_dataset(maxint, srt), 4)])
            for size in sorted(input_size):
                intel = data[(size, maxint, srt, 'Intel')]
                v2    = data[(size, maxint, srt, 'V2')]
                speedup = (v2 / intel)
                t.add_row([
                    '{:,d}'.format(size),
                    '%0.2f' % intel,
                    '%0.2f' % v2,
                    '%0.2f' % speedup,
                ])

    print(t)


maxsize_fmt = {
    1: "constant value",
    4: "values from 0 to 3",
    15: "values from 0 to 14",
    64: "values from 0 to 63",
    256: "bytes"

}


def format_dataset(maxsize, sorted):
    if maxsize == 1:
        return maxsize_fmt[maxsize]

    if sorted:
        return "random " + maxsize_fmt[maxsize]
    else:
        return "sorted " + maxsize_fmt[maxsize]


def parse(f):
    d = {}
    size = set()
    maxint = set()
    for line in f:
        if line.startswith('Benchmark'):
            k, v = parse_line(line)
            d[k] = v

            size.add(k[0])
            maxint.add(k[1])

    return size, maxint, d


def parse_line(s):
    # BenchmarkHistogram/V2/1024-1-false-4                  266161          4506 ns/op     227.23 MB/s
    #                    nn ssss m sssss                                                   speed
    F = s.replace('/', ' ').replace('-', ' ').split()

    perf = float(F[-3])

    name   = F[1]
    size   = int(F[2])
    maxint = int(F[3])
    sorted = (F[4] == 'true')
    key = (size, maxint, sorted, name)
    return key, perf


if __name__ == '__main__':
    main()
