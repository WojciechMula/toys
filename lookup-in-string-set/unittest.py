import metadata

def main():
    with open('unittest.cpp', 'wt') as f:
        unittestcpp(f)


def unittestcpp(f):
    paths = {}
    for path, lookups, checks in metadata.gather():
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


if __name__ == '__main__':
    main()

