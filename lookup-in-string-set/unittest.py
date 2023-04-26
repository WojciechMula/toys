import os

def main():
    with open('unittest.cpp', 'wt') as f:
        unittestcpp(f)


def unittestcpp(f):
    rootdir = 'generated'
    paths = {}
    for name in os.listdir(rootdir):
        if name.endswith('.cpp'):
            path = rootdir + '/' + name
            with open(path, 'rt') as cpp:
                lookups, checks = parsecpp(cpp)
                paths[path] = (lookups, checks)

    def writeln(s):
        f.write(s)
        f.write('\n')

    writeln('#include <cstdio>')
    writeln('#include "hash.cpp.in"')
    writeln('#include "pext.cpp.in"')
    for path in sorted(paths):
        writeln('#include "%s"' % path)
    writeln("")
    writeln("void check_all() {")
    for path in sorted(paths):
        _, checks = paths[path]
        for check in checks:
            writeln('    puts("checking %s");' % check['name'])
            writeln("    %s();" % check['name'])

    writeln('    puts("All OK");')
    writeln("}")
    writeln("")
    writeln("int main() {")
    writeln("\tcheck_all();")
    writeln("}")

def parsecpp(f):
    lookups = []
    checks = []
    for line in f:
        line, lookup = cut(line, '//lookup:')
        if lookup:
            lookups.append(parsecomment(line))
            continue

        line, check = cut(line, '//check:')
        if check:
            checks.append(parsecomment(line))
            continue

    return lookups, checks


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

