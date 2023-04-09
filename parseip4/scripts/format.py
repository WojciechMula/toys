from table import Table
from utils import unicode_bar
import sys
import codecs

#sys.stdout = codecs.getwriter('utf-8')(sys.stdout)

class Measurement:
    __slots__ = ['best', 'avg', 'speedup']

    def __init__(self, best, avg):
        self.best = best
        self.avg  = avg

    def update(self, best, avg):
        self.best = min(self.best, best)
        self.avg  = min(self.avg, avg)


def load(file):
    result = {}
    for line in file:
        if 'cycle/op' not in line:
            continue

        name, data = line.split(':', 2)
        name = name.strip()

        tmp = data.split()
        min_cycles = float(tmp[0])
        avg_cycles = float(tmp[3])

        if name not in result:
            result[name] = Measurement(min_cycles, avg_cycles)
        else:
            result[name].update(min_cycles, avg_cycles)

    return result


def update_speedup(data, procedures):
    best = []
    for name, measurement in data.items():
        if name in procedures:
            best.append(measurement.best)

    reference = min(best)
    for measurement in data.values():
        measurement.speedup = reference / measurement.best


def render(data, width=50):

    table = Table()
    table.add_header(["procedure", "best",     "avg.",      "speedup", ""])
    table.add_header(["",          "[cycles]", "[cycles]",  "", ""])

    max_speedup = max(m.speedup for m in data.values())
    for name, measurement in data.items():
        barlen = width * measurement.speedup/max_speedup
        table.add_row([
            name,
            '%0.3f' % measurement.best,
            '%0.3f' % measurement.avg,
            '%0.2f' % measurement.speedup,
            '``%s``' % unicode_bar(barlen)
        ])

    print(table)


def main():
    with open(sys.argv[1]) as f:
        data = load(f)
        update_speedup(data, {'glibc', 'go', 'naive'})
        render(data)


if __name__ == '__main__':
    main()
