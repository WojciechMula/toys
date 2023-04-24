import os
from itertools import chain

def main():
    makefile('Makefile')
    allcpp()

def makefile(name):
    datasets = []
    for f in os.listdir('datasets'):
        if f.endswith('.txt'):
            datasets.append(f.removesuffix('.txt'))

    datasets.sort()

    def hashcpp(s):
        return "generated/hash_%s.cpp" % (s,)

    def pextcpp(s):
        return "generated/pext_%s.cpp" % (s,)

    def dataset(s):
        return "datasets/%s.txt" % (s,)

    ALL = chain(map(hashcpp, datasets), map(pextcpp, datasets))

    with open(name, 'w') as f:
        f.write("%s: %s" % ("all", ' '.join(ALL)))

        for ds in datasets:
            src = dataset(ds)
            dst = hashcpp(ds)
            rule(f, dst, "hash/main -i %s -o %s" % (src, dst), [src, "hash/main"])

        for ds in datasets:
            src = dataset(ds)
            dst = pextcpp(ds)
            rule(f, dst, "pext/main -i %s -o %s" % (src, dst), [src, "pext/main"])

        rule(f, "hash/main", "go build -C hash", ["hash/*.go"])
        rule(f, "pext/main", "go build -C pext", ["pext/*.go"])

    print("Created %s" % name)


def rule(f, target, command, deps=[]):
    f.write('\n')
    if deps:
        f.write("%s: %s\n" % (target, ' '.join(deps)))
    else:
        f.write("%s:\n" % target)
    f.write("\t%s\n" % command)


def allcpp():
    rootdir = 'generated'
    for name in os.listdir(rootdir):
        if name.endswith('.cpp'):
            with open('generated' + '/' + name, 'rt') as f:
                parsecpp(f)

def parsecpp(f):
    for line in f:
        line, lookup = cut(line, '//lookup:')
        if lookup:
            print(parsecomment(line))
            continue

        line, check = cut(line, '//check:')
        if check:
            print(parsecomment(line))
            continue


def parsecomment(s):
    r = {}
    for term in s.split(','):
        v, k = term.split('=', 1)
        r[v.strip()] = k.strip()

    return r


def cut(s, prefix):
    if s.startswith(prefix):
        return s.removeprefix(prefix), True

    return s, False

if __name__ == '__main__':
    main()
