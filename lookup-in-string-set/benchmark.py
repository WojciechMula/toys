import os
import random
import string
import metadata


MB = 1024**2


def main():
    testdata = writetestdata()
    path = 'benchmark.cpp.in'
    with open(path, 'wt') as f:
        benchmarkcpp(f, testdata)
        print("Created '%s'" % path)


def writetestdata():
    result = {}
    datasets = readdatasets()
    for ds in datasets:
        result[ds] = []
        for max_size in [1]:
            for perc in [0, 10, 25, 50, 75]:
                name = "%s_%dM_%03dperc.txt" % (ds, max_size, perc)
                path = 'testdata/%s' % name
                result[ds].append(path)
                if os.path.exists(path):
                    continue

                print("Generating %s" % name, end='', flush=True)
                res = generate_testdata(ds, max_size * MB, perc)
                with open("testdata/%s" % name, 'wt') as f:
                    f.write('\n'.join(res))
                    print(" done")

    return result


def readdatasets():
    datasets = set()
    for _, lookups, _ in metadata.gather():
        for d in lookups:
            datasets.add(d['dataset'])

    return list(sorted(datasets))


def benchmarkcpp(f, testdata):
    indent = 0
    def writeln(s):
        f.write(indent * ' ')
        f.write(s)
        f.write('\n')

    paths = []
    for path, _, _ in metadata.gather():
        paths.append(path)

    for path in sorted(paths):
        writeln('#include "%s"' % path)

    for ds in sorted(testdata):
        testfiles = testdata[ds]
        writeln("")
        writeln("void benchmark_%s(const Filter& filter) {" % ds.replace('-', '_'))
        indent += 4
        if 1:
            writeln('if (!filter.dataset("%s")) {' % ds)
            indent += 4
            writeln("return;")
            indent -= 4
            writeln("}")
        for testfile in testfiles:
            writeln("testdata.clear();")
            writeln('testdata = read_lines("%s");' % testfile)
            writeln('printf("benchmark for %s\\n");' % testfile)
            for _, lookups, _ in metadata.gather():
                for d in (d for d in lookups if d['dataset'] == ds):
                    writeln('if (filter.type("%s")) {' % d['type'])
                    indent += 4
                    writeln("auto fn = [](){")
                    indent += 4
                    if 1:
                        writeln("for (const auto& s: testdata) {")
                        indent += 4
                        writeln("total += %s(s);" % d['name'])
                        indent -= 4
                        writeln("}")
                    indent -= 4
                    writeln("};")
                    writeln('BEST_TIME(/*pre*/, fn(), "%s", repeat, testdata.size());' % d['name'])
                    indent -= 4
                    writeln("}")
        indent -= 4
        writeln("}")

    writeln("")
    writeln("void benchmark(const Filter& filter) {")
    indent += 4
    for ds in sorted(testdata):
        writeln("benchmark_%s(filter);" % ds.replace('-', '_'))
    indent -= 4
    writeln("}")


letters = string.ascii_letters + string.digits + '_'

def randletter():
    return random.choice(letters)


def generate_testdata(dataset, max_size, perc):
    random.seed(42)

    with open("datasets/%s.txt" % dataset) as f:
        words = [l.rstrip() for l in f.readlines()]

    res = []
    res.extend(words)
    random.shuffle(res)
    generated = sum(map(len, res))
    max_length = max(map(len, res))
    while generated <= max_size:
        if random.randint(0, 100) < perc:
            word = random.choice(words)
        else:
            tmp = list(random.choice(words))
            k = random.randint(0, len(tmp) - 1)
            tmp[k] = randletter()
            word = ''.join(tmp)

        generated += len(word)
        res.append(word)

    return res


if __name__ == '__main__':
    main()
