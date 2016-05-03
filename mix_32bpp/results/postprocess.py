import sys


def postprocess(file):
    function = None

    result = {}
    for line in file:
        if 'function' in line:
            function = line.split()[1].replace(',', '')

        elif 'time =' in line:
            time = int(line.split()[2])
            assert function is not None

            if function not in result:
                result[function] = time
            else:
                result[function] = min(time, result[function])

    return result


def main():
    try:
        path = sys.argv[1]
    except IndexError:
        print "No file"
        return

    with open(path, 'rt') as f:
        r = postprocess(f)

    functions = sorted(r.keys())
    for fun in functions:
        print '%-12s %6d' % (fun, r[fun])

if __name__ == '__main__':
    main()
