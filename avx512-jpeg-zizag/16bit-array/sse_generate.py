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
    try:
        idx = sys.argv.index('--copy-single')
        del sys.argv[idx]
        copy_single_item = True
    except ValueError:
        copy_single_item = False
    
    lines = generate_code(copy_single_item)
    indent = ' ' * 8
    output = '\n'.join(indent + line for line in lines)
    
    try:
        file = open(sys.argv[1], 'wt')
    except IndexError:
        file = sys.stdout

    file.write(output)


def generate_code(copy_single_item):
    lines = []

    for rowid, row in enumerate(order):
        lines.append('')
        lines.append('// row #%d' % rowid)

        def get_tmp_name(register):
            return '%s_%d' % (source_reg_name[register], rowid)

        indices, used_registers = get_target_order(row)

        target_name = target_reg_name[rowid]

        # 1. generate partial results for given row
        copy_item = []
        shuffle   = []
        for register in used_registers:

            single_item = get_single_item_indices(register, indices)

            if copy_single_item and single_item is not None:
                target_index, source_index = single_item
                copy_item.append((register, source_index, target_index))
            else:
                pshufb_input = get_pshufb_bytes(register, indices)
                shuffle.append((register, pshufb_input))

        # 2. generate C++ code
        
        def generate_shuffle(register, pshufb_input):
            register_name = source_reg_name[register]
            tmp_name      = get_tmp_name(register)
            shuf_name     = '%s_shuf' % tmp_name

            pshufb_fmt    = ', '.join(map(str, pshufb_input))

            lines.append('static const __m128i %s = _mm_setr_epi8(%s);' % (shuf_name, pshufb_fmt))
            lines.append('const __m128i %s = _mm_shuffle_epi8(%s, %s);' % (tmp_name, register_name, shuf_name))

            return tmp_name


        def generate_copy_item(register, source_index, target_index):
            register_name   = source_reg_name[register]
            extract         = '_mm_extract_epi16(%s, %d)' % (register_name, source_index)

            lines.append('%s = _mm_insert_epi16(%s, %s, %d);' % (target_name, target_name, extract, target_index))


        assert len(shuffle) >= 2

        # 2a. initalize row register
        t0 = generate_shuffle(*shuffle[0])
        del shuffle[0]
        t1 = generate_shuffle(*shuffle[0])
        del shuffle[0]
        lines.append('__m128i %s = _mm_or_si128(%s, %s);' % (target_name, t0, t1))

        # 2b. update row register with shuffled registers
        for instr in shuffle:
            tk = generate_shuffle(*instr)
            lines.append('%s = _mm_or_si128(%s, %s);' % (target_name, target_name, tk))

        # 2c. copy individual items
        for instr in copy_item:
            generate_copy_item(*instr)

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


def get_single_item_indices(source_register, indices):

    res = None

    for target_index, (register, source_index) in enumerate(indices):
        if register != source_register:
            continue

        if res is None:
            res = (target_index, source_index)
        else:
            return None

    return res;


if __name__ == '__main__':
    main()
