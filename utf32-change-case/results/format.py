import sys
from benchmark_parser import parse, update_speedup, get_maximum_speedup
from table import Table
from utils import unicode_bar


def main():
    with open(sys.argv[1], 'rt') as f:
        data = parse(f)
        update_speedup(data, reference)

    data = sort_testcases(data)

    table = Table()
    table.add_header(["procedure", ("time in cycles per char", 2), ("speed-up", 2)])
    table.add_header(["", "average", "best", "", ""])

    for testcase, group in data.items():
        table.add_row([(f"dataset *{testcase}*", 5)])
        for procedure, m in group.items():
            row = [
                procedure,
                '%0.3f' % m.avg,
                '%0.3f' % m.best,
                '%0.1f' % m.speedup,
                '``%s``' % unicode_bar(40 * m.speedup / get_maximum_speedup(group))
            ]

            table.add_row(row)

    print(table)


def sort_testcases(data):
    tmp = {}
    key_prefix = "testcase "
    for i in range(0, len(data), 2):
        key = data[i]
        values = data[i+1]

        assert key.startswith(key_prefix)
        tmp[key.removeprefix(key_prefix)] = values

    result = {}
    for key in sorted(tmp):
        result[key] = filter_and_rename_measurements(tmp[key])

    return result


reference = "scalar uppercase [plain]"


rename = {
    "c++ uppercase":                            "C++ switch",
    "scalar uppercase [plain]":                 "scalar single lookup",
    "scalar uppercase [compressed v1]":         None,
    "scalar uppercase [compressed v2]":         None,
    "scalar uppercase [compressed v3]":         None,
    "AVX2 uppercase [plain]":                   "AVX2 single lookup",
    "AVX2 uppercase [compressed]":              None,
    "AVX2 uppercase [compressed 4 x unrolled]": None,
    "AVX2 uppercase [compressed v3]":           "AVX2 compressed lookup (variant #3)",
    "AVX2 uppercase [compressed v4]":           "AVX2 compressed lookup (variant #4)",
    "AVX2 uppercase [compressed v5]":           "AVX2 compressed lookup (variant #5)",
    "AVX512 uppercase [compressed v6]":         "AVX-512 compressed lookup (variant #6)",
    "AVX2 lowercase [compressed v3]":           None,
    "scalar lowercase [plain]":                 None,
    "scalar lowercase [compressed v1]":         None,
    "scalar lowercase [compressed v2]":         None,
    "scalar lowercase [compressed v3]":         None,
    "c++ lowercase":                            None,
}


def filter_and_rename_measurements(dict):
    tmp2 = {}
    for key, value in dict.items():
        key2 = rename[key]
        if key2 is not None:
            tmp2[key2] = value

    result = {}
    for key in rename.values():
        try:
            result[key] = tmp2[key]
        except KeyError:
            pass

    return result


if __name__ == '__main__':
    main()
