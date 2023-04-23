import os
from itertools import chain

def main():
    files = []
    for f in os.listdir('datasets'):
        if f.endswith('.txt'):
            files.append(f.removesuffix('.txt'))

    files.sort()

    def hashcpp(s):
        return "generated/hash_%s.cpp" % (s,)

    def pextcpp(s):
        return "generated/pext_%s.cpp" % (s,)

    def dataset(s):
        return "datasets/%s.txt" % (s,)

    ALL = chain(map(hashcpp, files), map(pextcpp, files))
    print("%s: %s" % ("ALL", ' '.join(ALL)))

    for f in files:
        src = dataset(f)
        dst = hashcpp(f)
        rule(dst, "hash/main -i %s -o %s" % (src, dst), [src, "hash/main"])

    for f in files:
        src = dataset(f)
        dst = pextcpp(f)
        rule(dst, "pext/main -i %s -o %s" % (src, dst), [src, "pext/main"])

    rule("hash/main", "go build -C hash")
    rule("pext/main", "go build -C pext")


def rule(target, command, deps=[]):
    print()
    if deps:
        print("%s: %s" % (target, ' '.join(deps)))
    else:
        print("%s:" % target)
    print("\t%s" % command)

if __name__ == '__main__':
    main()
