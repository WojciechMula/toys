import os
import functools


@functools.lru_cache(maxsize=None)
def gather(rootdir='generated'):
    res = []
    for name in os.listdir(rootdir):
        if name.endswith('.cpp'):
            path = rootdir + '/' + name
            with open(path, 'rt') as cpp:
                lookups, checks = parsecpp(cpp)
                res.append((path, lookups, checks))

    return res


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
        return s[len(prefix):], True

    return s, False
