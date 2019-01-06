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
        data[c] = (Measurements(),
                   Measurements(),
                   Measurements())

    cardinality = None
    for line in file:
        if line.startswith('rdtsc_overhead'):
            continue


        F = line.split(':')

        if len(F) == 1:
            F = line.replace('=', ' ').replace(',', ' ').split()
            assert F[0] == 'cardinality'
            cardinality = int(F[1])
            continue

        assert cardinality is not None
        name = F[0].strip()
        F = F[1].split()
        if name == 'scalar':
            meas = data[cardinality][0]
        elif name == 'AVX512VBMI':
            meas = data[cardinality][1]
        elif name == 'AVX512VBMI (Travis)':
            meas = data[cardinality][2]
        elif name == 'AVX512VBMI (Zach)':
            meas = data[cardinality][2]
        else:
            assert False

        best = float(F[0])
        avg  = float(F[3])

        meas.set_best(best)
        meas.add_value(avg)

    return data
