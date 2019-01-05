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
