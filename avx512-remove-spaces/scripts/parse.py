from collections import OrderedDict
from procedure_names import display_name

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
        data[c] = OrderedDict()

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
        name = display_name[F[0].strip()]
        if name is None:
            continue

        F = F[1].split()

        if name not in data[cardinality]:
            data[cardinality][name] = Measurements()

        best = float(F[0])
        avg  = float(F[3])

        meas = data[cardinality][name]
        meas.set_best(best)
        meas.add_value(avg)

    return data
