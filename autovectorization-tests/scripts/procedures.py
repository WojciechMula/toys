#!/usr/bin/env python3

import sys

PROCEDURES = {
    'accumulate_default.cpp' : {
        'title'             : "accumulate --- default",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/accumulate',
        'procedures'        : ["accumulate_epi8", "accumulate_epi32"],
    },

    'accumulate_custom.cpp' : {
        'title'             : "accumulate --- custom",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/accumulate',
        'procedures'        : ["accumulate_custom_epi8", "accumulate_custom_epi32"],
    },

    'all_of.cpp'            : {
        'title'             : "all_of",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/all_any_none_of',
        'procedures'        : ["all_of_epi8", "all_of_epi32"],
    },

    'any_of.cpp'            : {
        'title'             : "any_of",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/all_any_none_of',
        'procedures'        : ["any_of_epi8", "any_of_epi32"],
    },

    'copy.cpp'              : {
        'title'             : "copy",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/copy',
        'procedures'        : ["copy_epi8", "copy_epi32"],
    },

    'copy_if.cpp'           : {
        'title'             : "copy_if",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/copy',
        'procedures'        : ["copy_if_epi8", "copy_if_epi32"],
    },

    'count.cpp'             : {
        'title'             : "count",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/count',
        'procedures'        : ["count_epi8", "count_epi32"],
    },

    'count_if.cpp'          : {
        'title'             : "count_if",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/count',
        'procedures'        : ["count_if_epi8", "count_if_epi32"],
    },

    'fill.cpp'              : {
        'title'             : "fill",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/fill',
        'procedures'        : ["fill_epi8", "fill_epi32"],
    },

    'find.cpp'              : {
        'title'             : "find",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/find',
        'procedures'        : ["find_epi8", "find_epi32"],
    },

    'find_if.cpp'           : {
        'title'             : "find_if",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/find',
        'procedures'        : ["find_if_epi8", "find_if_epi32"],
    },

    'is_sorted.cpp'         : {
        'title'             : "is_sorted",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/is_sorted',
        'procedures'        : ["is_sorted_epi8", "is_sorted_epi32"],
    },

    'none_of.cpp'           : {
        'title'             : "none_of",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/all_any_none_of',
        'procedures'        : ["none_of_epi8", "none_of_epi32"],
    },

    'remove.cpp'            : {
        'title'             : "remove",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/remove',
        'procedures'        : ["remove_epi8", "remove_epi32"],
    },

    'remove_if.cpp'         : {
        'title'             : "remove_if",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/remove',
        'procedures'        : ["remove_if_epi8", "remove_if_epi32"],
    },

    'replace.cpp'           : {
        'title'             : "replace",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/replace',
        'procedures'        : ["replace_epi8", "replace_epi32"],
    },

    'replace_if.cpp'        : {
        'title'             : "replace_if",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/replace',
        'procedures'        : ["replace_if_epi8", "replace_if_epi32"],
    },

    'reverse.cpp'           : {
        'title'             : "reverse",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/reverse',
        'procedures'        : ["reverse_epi8", "reverse_epi32"],
    },

    'transform_abs.cpp'     : {
        'title'             : "transform --- abs",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/transform',
        'procedures'        : ["transform_abs_epi8", "transform_abs_epi32"],
    },

    'transform_inc.cpp'     : {
        'title'             : "transform --- increment",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/transform',
        'procedures'        : ["transform_inc_epi8", "transform_inc_epi32"],
    },

    'transform_neg.cpp'    : {
        'title'             : "transform --- negation",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/transform',
        'procedures'        : ["transform_neg_epi8", "transform_neg_epi32"],
    },

    'unique.cpp'            : {
        'title'             : "unique",
        'link'              : 'https://en.cppreference.com/w/cpp/algorithm/unique',
        'procedures'        : ["unique_epi8", "unique_epi32"],
    },
}


def print_checklist(file):
    procedures = []
    for item in PROCEDURES.values():
        for procedure in item['procedures']:
            procedures.append(procedure)

    def writeln(s):
        file.write(s)
        file.write('\n')
   
    writeln('compiler: ')
    writeln('cmdline: ')
    writeln('')
    for procedure in sorted(procedures):
        writeln('%s: ??' % procedure)
   

if __name__ == '__main__':
    print_checklist(sys.stdout)
