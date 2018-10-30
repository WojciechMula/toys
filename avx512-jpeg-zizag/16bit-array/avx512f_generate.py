import sys

order = [
    [ 0,  1,  8, 16,  9,  2,  3, 10,
     17, 24, 32, 25, 18, 11,  4,  5,
     12, 19, 26, 33, 40, 48, 41, 34,
     27, 20, 13,  6,  7, 14, 21, 28],

    [35, 42, 49, 56, 57, 50, 43, 36,
     29, 22, 15, 23, 30, 37, 44, 51,
     58, 59, 52, 45, 38, 31, 39, 46,
     53, 60, 61, 54, 47, 55, 62, 63],
]

source_reg_name = ['A', 'B']
target_reg_name = ['row0', 'row1']


def main():
    lines = generate_code()
    indent = ' ' * 8
    tmp = []
    for line in lines:
        if line.startswith('//') or line == '':
            tmp.append(indent + line)
        else:
            tmp.append(indent + line + ';')

    output = '\n'.join(tmp)
    
    try:
        file = open(sys.argv[1], 'wt')
    except IndexError:
        file = sys.stdout

    file.write(output)


LO_WORD = 0
HI_WORD = 1

def generate_code():

    lines = []

    for rowid, row in enumerate(order):
        indices = [get_target_register(index) for index in row]
        lines.append('')
        lines.append('// row %d' % rowid)

        target_name = target_reg_name[rowid]
        lines.append('__m512i %s = _mm512_setzero_si512()' % target_name)

        for register in [0, 1]:
            for target_helve in [LO_WORD, HI_WORD]:
                for source_helve in [LO_WORD, HI_WORD]:

                    shuffle  = generate_shuffle(indices, target_helve, source_helve, register)

                    ret = generate_permute_code(shuffle, rowid, target_helve, source_helve, register)
                    lines.extend(ret)

    return lines


def generate_permute_code(shuffle, rowid, target_helve, source_helve, register):

    register_name = source_reg_name[register]
    target_name   = target_reg_name[rowid]

    prefix        = '%s%d_%d%d' % (register_name, rowid, source_helve, target_helve)
    shuffle_name  = '%s_shuf' % prefix
    mask_name     = '%s_mask' % prefix
    permuted_name = '%s_perm' % prefix

    lines = []
    shuffle_fmt   = ', '.join(map(str, shuffle)) 
    lines.append('const __m512i %s = _mm512_setr_epi32(%s)' % \
                 (shuffle_name, shuffle_fmt))
    lines.append('const __m512i %s = _mm512_permutexvar_epi32(%s, %s)' % \
                 (permuted_name, shuffle_name, register_name))

    if target_helve == source_helve:
        # simple mask is needed
        if target_helve == LO_WORD:
            mask_fmt = format_mask(shuffle, '0x0000ffff')
        else:
            mask_fmt = format_mask(shuffle, '0xffff0000')

        permuted_expr = permuted_name

    else:
        # map lo helves into hi helves or vice versa
        if source_helve == LO_WORD and target_helve == HI_WORD:
            shifted_expr = '_mm512_slli_epi32(%s, 16)' % permuted_name
        elif source_helve == HI_WORD and target_helve == LO_WORD:
            shifted_expr = '_mm512_srli_epi32(%s, 16)' % permuted_name

        permuted_expr = shifted_expr
        mask_fmt = format_mask(shuffle, '-1')

    lines.append('const __m512i %s = _mm512_setr_epi32(%s)' % (mask_name, mask_fmt))

    # target = target | (permuted & mask)
    lines.append('%s = _mm512_ternarylogic_epi32(%s, %s, %s, 0xf8)' % \
                 (target_name, target_name, permuted_expr, mask_name))
    
    return lines


def generate_shuffle(indices, target_helve, source_helve, source_reg):

    assert target_helve in [0, 1]
    assert source_helve in [0, 1]
    assert source_reg in [0, 1]

    shuffle = []

    for i in xrange(0, len(indices), 2):
        item = indices[i + target_helve]
        reg, index, helve = item
        if reg == source_reg and helve == source_helve:
            shuffle.append(index)
        else:
            shuffle.append(-1)

    assert shuffle.count(-1) != len(shuffle)
    return shuffle


def get_target_register(word):
    register = word / 32
    index    = (word % 32)/2
    helve    = word % 2

    return register, index, helve


def format_mask(shuffle, dword_mask):
    assert type(dword_mask) is str

    tmp = []
    for index in shuffle:
        if index == -1:
            tmp.append('0')
        else:
            tmp.append(dword_mask)

    return ', '.join(tmp)


if __name__ == '__main__':
    main()
