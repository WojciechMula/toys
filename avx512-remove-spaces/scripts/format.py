import sys
from table import Table

def main():
    path = sys.argv[1]

    with open(path) as f:
        data = load(f)

    tbl = format_table(data)
    print tbl


class Measurements(object):
    def __init__(self):
        self.values = []
        self.best = None


    def add_value(self, value):
        self.values.append(value)


    def get_avg(self):
        return sum(self.values) / len(self.values)


    def set_best(self, best):
        if self.best is None:
            self.best = best
        else:
            self.best = min(best, self.best)


    def __str__(self):
        return '%0.2f - %0.3f (%0.3f)' % (min(self.values), max(self.values), self.best);


def load(file):
    data = {}
    for c in xrange(0, 64 + 1):
        data[c] = (Measurements(), Measurements())

    cardinality = None
    for line in file:
        if line.startswith('rdtsc_overhead'):
            continue

        F = line.replace('=', ' ').replace(',', ' ').split()
        if F[0] == 'cardinality':
            cardinality = int(F[1])
            continue

        assert cardinality is not None
        if F[0] == 'scalar':
            meas = data[cardinality][0]
        elif F[0] == 'AVX512VBMI':
            meas = data[cardinality][1]
        else:
            assert False

        best = float(F[2])
        avg  = float(F[5])

        meas.set_best(best)
        meas.add_value(avg)

    return data


def format_table(data):
    table = Table()
    table.add_header(["number of spaces",
                      ("scalar [cycles/byte]", 3),
                      ("AVX512VBMI [cycles/byte]", 3),
                      "speedup (avg)"])
    table.add_header(["",
                      "avg (min)", "avg (max)", "best",
                      "avg (min)", "avg (max)", "best",
                      ""])
    
    for cardinality in xrange(1, 64+1):
        scalar, avx512 = data[cardinality]

        speedup = scalar.get_avg() / avx512.get_avg()

        table.add_row([
            '%d' % cardinality,
            '%0.3f' % min(scalar.values),
            '%0.3f' % max(scalar.values),
            '%0.3f' % scalar.best,
            '%0.3f' % min(avx512.values),
            '%0.3f' % max(avx512.values),
            '%0.3f' % avx512.best,
            '%0.2f' % speedup
        ])

    return table


if __name__ == '__main__':
    main()

