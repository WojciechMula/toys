# -*- coding: utf-8 -*-
from collections import OrderedDict
from table import Table
from utils import unicode_bar
import sys
import codecs

sys.stdout = codecs.getwriter('utf-8')(sys.stdout)

class Measurement:
    __slots__ = ['best', 'avg', 'speedup']

    def __init__(self, best, avg):
        self.best = best
        self.avg  = avg

    def update(self, best, avg):
        self.best = min(self.best, best)
        self.avg  = min(self.avg, avg)


def load(file):
    result = OrderedDict()
    size   = None
    for line in file:
        if line.startswith('element count'):
            size = int(line.split()[-1])
            if size not in result:
                result[size] = OrderedDict()
        elif ':' in line:
            name, data = line.split(':', 2)
            name = name.strip()
    
            tmp = data.split()
            min_cycles = float(tmp[0])
            avg_cycles = float(tmp[3])

            assert size is not None
            dict = result[size]

            if name not in dict:
                dict[name] = Measurement(min_cycles, avg_cycles)
            else:
                dict[name].update(min_cycles, avg_cycles)

    return result


def update_speedup(data):

    global_max_speedup = None

    for size, measurements in data.iteritems():

        base_best_time = measurements['scalar'].best
        for name, measurement in measurements.iteritems():
            measurement.speedup = base_best_time/measurement.best

        max_speedup = max(m.speedup for m in measurements.itervalues())
        if global_max_speedup is None:
            global_max_speedup = max_speedup
        else:
            global_max_speedup = max(global_max_speedup, max_speedup)

    return global_max_speedup


def render(data, global_max_speedup):

    table = Table()
    table.add_header(["procedure", "best",     "avg.",      "speedup", ""])
    table.add_header(["",          "[cycles]", "[cycles]",  "", ""])

    for size, measurements in data.iteritems():
        table.add_row([("size %d items" % size, 5)])

        for name, measurement in measurements.iteritems():

            barlen = 50 * measurement.speedup/global_max_speedup

            table.add_row([
                name,
                '%0.3f' % measurement.best,
                '%0.3f' % measurement.avg,
                '%0.2f' % measurement.speedup,
                '``%s``' % unicode_bar(barlen)
            ])

    print unicode(table)


def main():
    with open(sys.argv[1]) as f:
        data = load(f)
        global_max_speedup = update_speedup(data)
        render(data, global_max_speedup)


if __name__ == '__main__':
    main()
