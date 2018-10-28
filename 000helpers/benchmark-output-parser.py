from collections import OrderedDict

__all__ = ['parse', 'calculate_speedup']

class Measurement(object):
    __slots__ = ['best', 'avg', 'speedup']

    def __init__(self, best, avg):
        self.best    = best
        self.avg     = avg
        self.speedup = None

    def __str__(self):
        if self.speedup is None:
            return '<%0.3f, %0.3f>' % (self.best, self.avg)
        else:
            return '<%0.3f, %0.3f, %0.2fx>' % (self.best, self.avg, self.speedup)


    __repr__ = __str__


def parse(file):
    
    result = []
    dict   = None

    for line in file:
        line = line.strip()
        if line.startswith('rdtsc_overhead'):
            continue

        if not line:
            continue
        
        if ':' not in line:
            if dict is not None:
                result.append(dict)
                dict = None

            result.append(line)
        else:
            name, measurement = parse_line(line)

            if dict is None:
                dict = OrderedDict()

            dict[name] = measurement
    else:
        if dict is not None:
            result.append(dict)

    return result


def parse_line(line):
    
    name, tail = line.rsplit(':', 1)
    name = name.strip()
    tmp  = tail.split()

    best = float(tmp[0])
    avg  = float(tmp[3])

    return name, Measurement(best, avg)


def calculate_speedup(measurements, reference_key = None):
    if not measurements:
        return

    if reference_key is None:
        reference_key = measurements.keys()[0]

    reference_value = measurements[reference_key].best

    for m in measurements.itervalues():
        m.speedup = reference_value / m.best


################################################################################


TEST_INPUT="""
rdtsc_overhead set to 33

size 1000
scalar                        	:   109.000 cycle/op (best)  117.240 cycle/op (avg)
SSE                           	:    49.000 cycle/op (best)   52.217 cycle/op (avg)
SSE (method: 2)                 :    51.000 cycle/op (best)   52.217 cycle/op (avg)
AVX2             	            :    33.000 cycle/op (best)   43.222 cycle/op (avg)


size 2000
scalar                        	:   109.000 cycle/op (best)  117.240 cycle/op (avg)
SSE                           	:    49.000 cycle/op (best)   52.217 cycle/op (avg)
SSE (method: 2)                 :    48.000 cycle/op (best)   52.217 cycle/op (avg)
AVX2             	            :    33.000 cycle/op (best)   43.222 cycle/op (avg)"""


def test():
    res = parse(TEST_INPUT.splitlines())
    assert len(res) == 4
    assert type(res[0]) is str
    assert type(res[2]) is str
    assert type(res[1]) is OrderedDict
    assert type(res[3]) is OrderedDict

    m = res[1]
    for v in m.values():
        assert v.speedup is None

    calculate_speedup(m, 'AVX2')
    for v in m.values():
        assert v.speedup is not None


if __name__ == '__main__':
    test()
