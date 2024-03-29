import os
import sys
from itertools import chain


def main():
    hasGo = True
    if "--without-go" in sys.argv:
        hasGo = False

    makefile('Makefile', hasGo)


def makefile(name, hasGo):
    datasets = []
    for f in os.listdir('datasets'):
        if f.endswith('.txt'):
            datasets.append(f[:-4])

    datasets.sort()

    def hashcpp(s):
        return "generated/hash_%s.cpp" % (s,)

    def pextcpp(s):
        return "generated/pext_%s.cpp" % (s,)

    def splitcpp(s):
        return "generated/split_%s.cpp" % (s,)

    def dataset(s):
        return "datasets/%s.txt" % (s,)

    SRC = chain(map(hashcpp, datasets), map(pextcpp, datasets), map(splitcpp, datasets))

    with open(name, 'w') as f:
        f.write("FLAGS=-Wall -Wextra -pedantic -std=c++17 -march=skylake\n")
        f.write("SRC=%s\n" % (' '.join(SRC)))
        f.write("all: unittest benchmark\n")
        rule(f, "unittest", "$(CXX) $(FLAGS) unittest.cpp -o unittest", ["unittest.cpp"])
        rule(f, "unittest.cpp", "python3 unittest.py", ["unittest.py", "$(SRC)"])
        rule(f, "benchmark", "$(CXX) $(FLAGS) -O2 benchmark.cpp -o benchmark", ["benchmark.cpp", "benchmark.cpp.in"])
        rule(f, "benchmark.cpp.in", "python3 benchmark.py", ["benchmark.py", "$(SRC)"])

        if hasGo:
            for ds in datasets:
                src = dataset(ds)
                dst = hashcpp(ds)
                rule(f, dst, "hash/main -i %s -o %s" % (src, dst), [src, "hash/main"])

            for ds in datasets:
                src = dataset(ds)
                dst = pextcpp(ds)
                rule(f, dst, "pext/main -i %s -o %s" % (src, dst), [src, "pext/main"])

            for ds in datasets:
                src = dataset(ds)
                dst = splitcpp(ds)
                rule(f, dst, "split/main -i %s -o %s" % (src, dst), [src, "split/main"])

            rule(f, "hash/main",  "go build -C hash",  ["hash/*.go"])
            rule(f, "pext/main",  "go build -C pext",  ["pext/*.go"])
            rule(f, "split/main", "go build -C split", ["split/*.go"])

    print("Created %s" % name)


def rule(f, target, command, deps=[]):
    f.write('\n')
    if deps:
        f.write("%s: %s\n" % (target, ' '.join(deps)))
    else:
        f.write("%s:\n" % target)
    f.write("\t%s\n" % command)


if __name__ == '__main__':
    main()
