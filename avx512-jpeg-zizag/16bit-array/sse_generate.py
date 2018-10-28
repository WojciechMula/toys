import sys

order = [
    [ 0,  1,  8, 16,  9,  2,  3, 10],
    [17, 24, 32, 25, 18, 11,  4,  5],
    [12, 19, 26, 33, 40, 48, 41, 34],
    [27, 20, 13,  6,  7, 14, 21, 28],
    [35, 42, 49, 56, 57, 50, 43, 36],
    [29, 22, 15, 23, 30, 37, 44, 51],
    [58, 59, 52, 45, 38, 31, 39, 46],
    [53, 60, 61, 54, 47, 55, 62, 63],
]

source_reg_name = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H']
target_reg_name = ['row%d' % k for k in range(8)]


def main():
    lines = generate_code()
    indent = ' ' * 8
    output = '\n'.join(indent + line for line in lines)
    with open(sys.argv[1], 'wt') as f:
        f.write(output)


def generate_code():
    lines = []

    for rowid, row in enumerate(order):
        lines.append('')
        lines.append('// row #%d' % rowid)

        def get_tmp_name(register):
            return '%s_%d' % (source_reg_name[register], rowid)

        indices, used_registers = get_target_order(row)

        target_name = target_reg_name[rowid]
        
        # generate partial results for given row
        for register in used_registers:

            register_name = source_reg_name[register]
            tmp_name      = get_tmp_name(register)
            shuf_name  = '%s_shuf' % tmp_name
            pshufb_fmt = ', '.join(map(str, get_pshufb_bytes(register, indices)))

            lines.append('static const __m128i %s = _mm_setr_epi8(%s);' % (shuf_name, pshufb_fmt))
            lines.append('const __m128i %s = _mm_shuffle_epi8(%s, %s);' % (tmp_name, register_name, shuf_name))

        # merge vectors
        lines.append("")
        lines.append("__m128i %s;" % target_name)
        src1 = get_tmp_name(used_registers[0])
        src2 = get_tmp_name(used_registers[1])
        lines.append("%s = _mm_or_si128(%s, %s);" % (target_name, src1, src2))
        for register in used_registers[2:]:
            lines.append("%s = _mm_or_si128(%s, %s);" % (target_name, target_name, get_tmp_name(register)))

    return lines


def get_target_order(row):
    indices = []
    used_registers = set()
    for index in row:
        register = index / 8
        word     = index % 8
        
        indices.append((register, word))
        used_registers.add(register)

    used_registers = list(sorted(used_registers))

    return (indices, used_registers)


def get_pshufb_bytes(shuffled_register, indices):
    res = []
    for register, word in indices:
        if register == shuffled_register:
            res.append(word * 2 + 0)
            res.append(word * 2 + 1)
        else:
            res.append(-1)
            res.append(-1)

    return res


if __name__ == '__main__':
    main()
