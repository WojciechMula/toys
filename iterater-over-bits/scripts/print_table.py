from table import Table

def print_report(path):

    table1 = Table()
    table2 = Table()

    header_common = [
        "case",
        "size [bits]",
        "cardinality [bits]",
        "fill factor",
    ]

    table1.set_header(header_common + [
        "naive [us]",
        "better [us]",
        "block-3 [us]",
        "block-4 [us]",
    ])

    table2.set_header(header_common + [
        "naive [x]",
        "better [x]",
        "block-3 [x]",
        "block-4 [x]",
    ])

    with open(path, 'rt') as f:
        prev_name = None
        for line in f:
            F = line.split(',')
            assert(len(F) == 7)

            if F[0] == prev_name:
                name = ""
            else:
                name = F[0]
                prev_name = name

            size = int(F[1])
            cardinality = int(F[2])
            fill_factor = float(cardinality)/size

            naive_time  = int(F[3])
            better_time = int(F[4])
            block3_time = int(F[5])
            block4_time = int(F[6])
         
            row_common = [
                name,
                '%d' % size,
                '%d' % cardinality,
                '%0.2f' % fill_factor,
            ]

            table1.add_row(row_common + [
                format(naive_time, ",d"),
                format(better_time, ",d"),
                format(block3_time, ",d"),
                format(block4_time, ",d"),
            ])

            table2.add_row(row_common + [
                "%0.2f" % (float(naive_time)/naive_time),
                "%0.2f" % (float(naive_time)/better_time),
                "%0.2f" % (float(naive_time)/block3_time),
                "%0.2f" % (float(naive_time)/block4_time),
            ])

    print table1
    print
    print table2


if __name__ == '__main__':
    import sys
    print_report(sys.argv[1])
