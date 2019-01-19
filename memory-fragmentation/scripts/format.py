import sys
from parse import load
from table import Table

def main():
    d = load(sys.argv[1])
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


if __name__ == '__main__':
    main()

