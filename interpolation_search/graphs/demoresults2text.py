def read(file):
    while True:
        field = next(file).split()

        if not field:
            continue

        if field[0] == "pow":
            exp = float(field[1])

            bin    = float(next(file).split()[-1])
            interp = float(next(file).split()[-1])

            yield exp, bin, interp, int(interp < bin)

if __name__ == '__main__':
    import sys
    for item in read(sys.stdin):
        print '%5.2f %5.2f %5.2f %d' % item

