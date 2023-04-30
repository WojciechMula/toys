import os
import sys
import re
from benchmark_parser import parse_line
from table import Table


def main():
    data = prepare(sys.argv[1])
    render(data)


known_perc = [0, 25, 50, 75]
known_procedures = ['pext', 'split', 'hash1', 'hash2', 'hash3', 'hash_sum0', 'hash_sumN', 'hash_sdb', 'hash_djb2']

def render(data):
    table = Table()
    table.add_header(['', ('valid words density', 8)])
    table.add_header(['procedure', '0%', 'speed-up', '25%', 'speed-up', '50%', 'speed-up', '75%', 'speed-up'])
    for dataset, val in data.items():
        table.add_row([('dataset ``%s``' % dataset, 9)])
        rows = []
        for _ in known_procedures:
            rows.append([''] * 9)

        for j, perc in enumerate(known_perc, start=1):
            procs = val[perc]
            columns = []
            colvalue = 2*j - 1
            colspeedup = 2*j
            for i, procedure in enumerate(known_procedures):
                best = procs[procedure].best
                rows[i][colvalue] = best
                rows[i][0] = procedure
                columns.append(best)
            
            minval = min(columns)
            for i, procedure in enumerate(known_procedures):
                v = rows[i][colvalue]
                rows[i][colvalue] = '%0.2f' % v
                if v == minval:
                    rows[i][colvalue] = '**%s**' % rows[i][colvalue]

                rows[i][colspeedup] = '%0.3f' % (minval/v)

        for row in rows:
            table.add_row(row)

    print(table)


def prepare(path):
    result = {}
    with open(path) as f:
        for line in f:
            line = line.rstrip()
            if line.startswith('lookup'):
                name, meas = parse_line(line)
                typ = parse_lookup_name(name)
                result[dataset][perc][typ] = meas
            elif line.startswith('benchmark'):
                ret = parse_benchmark(line)
                if ret:
                    dataset, perc = ret
                    if dataset not in result:
                        result[dataset] = {}

                    result[dataset][perc] = {}
    return result


def parse_benchmark(line):
    m = re.match(r'benchmark for testdata/([a-z0-9-]*)_1M_([0-9]{3})perc.txt', line)
    if not m:
        return

    dataset, perc = m.groups()
    return dataset, int(perc)


def parse_lookup_name(s):
    tmp = s.split('_')
    if tmp[-1] in ('pext', 'split', 'hash1', 'hash2', 'hash3'):
        return tmp[-1]

    if tmp[-2] == 'hash':
        return tmp[-2] + '_' + tmp[-1]

    raise ValueError(tmp)


if __name__ == '__main__':
    main()
