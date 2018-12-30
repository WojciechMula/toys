import sys
from table import Table

def main():
    d = load(sys.argv[1])
    d = group(d)
    render(d)


def render(data):
    table = Table()
    table.add_header([("allocations", 4), ("libc memory usage", 4)])
    table.add_header(["count", "min [B]", "max [B]", "total [B]",
                      "allocated [B]", "free [B]", "waste [B]", "waste [%]"])

    for size in sorted(data):
        table.add_row([("approx target memory usage: %s" % format(size, ',d'), 8)])
        for record in data[size]:
            table.add_row([
                format(record.malloc_calls, ',d'),
                format(record.min_alloc, ',d'),
                format(record.max_alloc, ',d'),
                format(record.sum_allocated, ',d'),
                format(record.malloc_allocated, ',d'),
                format(record.malloc_free, ',d'),
                format(record.malloc_waste, ',d'),
                format(record.malloc_waste_perc, '.2f'),
            ])

    print table


class Record(object):
    pass


def load(path):
    result = []
    with open(path, 'rt') as f:
        for line in f:
            F = map(int, line.split())
            r = Record()
            r.memory_usage_limit = F[0]
            r.min_alloc = F[1]
            r.max_alloc = F[2]
            r.sum_allocated = F[3]
            r.malloc_calls = F[4]
            r.malloc_allocated = F[5]
            r.malloc_free = F[6]
            r.malloc_waste = r.malloc_allocated - (r.malloc_free + r.sum_allocated)
            r.malloc_waste_perc = 100.0 * r.malloc_waste / r.malloc_allocated
            result.append(r)

    return result


def group(data):
    result = {}
    for record in data:
        key = record.memory_usage_limit
        if key not in result:
            result[key] = []

        result[key].append(record)

    return result


if __name__ == '__main__':
    main()

