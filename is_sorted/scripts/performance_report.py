import sys
from table import Table

procedure_name = [
        # following items must be kept in sync with benchmark.cpp
        "scalar",
        "SSE (generic)",
        "SSE (generic, unrolled 4 times)",
        "SSE",
        "SSE (unrolled 4 times)",
        "AVX2 (generic)",
        "AVX2 (generic, unrolled 4 times)",
        "AVX2",
        "AVX2 (unrolled 4 times)",
        "AVX512 (generic)",
        "AVX512",
]


def main(measurements_path):
    
    table = Table();
    table.set_header(["procedure", "time [us]", "speed-up"])
    
    with open(measurements_path, 'rt') as f:
        for line in f:
            F = map(int, (s.strip() for s in line.split(',')))
            size       = F[0]
            iterations = F[1]
            measurements = F[2:]

            table.add_row([('element count %d' % (size,), 3)])

            reference = float(measurements[0])
            for i, time in enumerate(measurements):
                row = []
                row.append(procedure_name[i])
                row.append('%d' % time)
                row.append('%0.2f' % (reference/time))
                table.add_row(row)

    print table


if __name__ == '__main__':
    main(sys.argv[1])
