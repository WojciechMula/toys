import sys
from table import Table

def report(file):

    table = Table()
    table.set_header(["procedure", "time [us]", "speedup"])

    for line in file:
        line = line.strip()
        if not line:
            continue

        F = map(int, line.split(','))

        size            = F[0]
        iters           = F[1]
        scalar          = F[2]
        sse_generic     = F[3]
        sse             = F[4]
        avx2_generic    = F[5]
        avx2            = F[6]

        base_time = float(scalar)

        table.add_row([(("element count  %d" % size), 3)]) 
        table.add_row(["scalar",         "%d" % scalar,       "%0.2f" % (base_time / scalar)])
        table.add_row(["SSE (generic)",  "%d" % sse_generic,  "%0.2f" % (base_time / sse_generic)])
        table.add_row(["SSE",            "%d" % sse,          "%0.2f" % (base_time / sse)])
        table.add_row(["AVX2 (generic)", "%d" % avx2_generic, "%0.2f" % (base_time / avx2_generic)])
        table.add_row(["AVX2",           "%d" % avx2,         "%0.2f" % (base_time / avx2)])

    print table


def main():
    with open(sys.argv[1]) as f:
        report(f)


if __name__ == '__main__':
    main()

