#!/usr/bin/env python3


def print_constants(name, bytes, rep=1):
    assert len(bytes) * rep == 64
    allbytes = ['%02x' % byte for byte in rep * bytes]

    tmp = ', '.join(str(byte) for byte in bytes)
    if rep == 1:
        print("// [%s]" % tmp)
    else:
        print("// %d * [%s]" % (rep, tmp))

    print(f"const __m512i {name} = _mm512_setr_epi64(")
    for k, i in enumerate(range(0, 64, 8)):
        qword = allbytes[i:i + 8]
        image = '0x' + ''.join(reversed(qword))
        if k < 7:
            print(f"    {image},")
        else:
            print(f"    {image}")
    print(");")
 

def main():
    bswap_lookup = [
        3, 2, 1, 0,
        7, 6, 5, 4,
        11, 10, 9, 8,
        15, 14, 13, 12,
    ]
    print_constants('bswap_lookup', bswap_lookup, 4);

    shift_left = [
        1, # 0000 - ASCII
        1, # 0001 - ASCII 
        1, # 0010 - ASCII
        1, # 0011 - ASCII
        1, # 0100 - ASCII
        1, # 0101 - ASCII
        1, # 0110 - ASCII
        1, # 0111 - ASCII
        0, # 1000 - continuation byte (never processed)
        0, # 1001 - continuation byte (never processed)
        0, # 1010 - continuation byte (never processed)
        0, # 1011 - continuation byte (never processed)
        3, # 1100 - 2-bytes char
        3, # 1101 - 2-bytes char
        4, # 1110 - 3-bytes char
        5, # 1111 - 4-bytes char
    ]
    print_constants('shift_left', shift_left, 4)

    shift_right = [
        25, # 0000 - ASCII
        25, # 0001 - ASCII 
        25, # 0010 - ASCII
        25, # 0011 - ASCII
        25, # 0100 - ASCII
        25, # 0101 - ASCII
        25, # 0110 - ASCII
        25, # 0111 - ASCII
         0, # 1000 - continuation byte (never processed)
         0, # 1001 - continuation byte (never processed)
         0, # 1010 - continuation byte (never processed)
         0, # 1011 - continuation byte (never processed)
        21, # 1100 - 2-bytes char
        21, # 1101 - 2-bytes char
        16, # 1110 - 3-bytes char
        11, # 1111 - 4-bytes char
    ]
    print_constants('shift_right', shift_right, 4)


    # lane{0,1,2} have got bytes: [  0,  1,  2,  3,  4,  5,  6,  8,  9, 10, 11, 12, 13, 14, 15]
    # lane3 has got bytes:        [ 16, 17, 18, 19,  4,  5,  6,  8,  9, 10, 11, 12, 13, 14, 15]
    expand_ver2 = [
        # lane 0:
        0, 1, 2, 3,
        1, 2, 3, 4,
        2, 3, 4, 5,
        3, 4, 5, 6,
        # lane 1:
        4, 5, 6, 7,
        5, 6, 7, 8,
        6, 7, 8, 9,
        7, 8, 9, 10,
        # lane 2:
         8,  9, 10, 11,
         9, 10, 11, 12,
        10, 11, 12, 13,
        11, 12, 13, 14,

        # lane 3 order: 13, 14, 15, 16 14, 15, 16, 17, 15, 16, 17, 18, 16, 17, 18, 19
        12, 13, 14, 15,
        13, 14, 15,  0,
        14, 15,  0,  1,
        15,  0,  1,  2,
    ]
    print_constants('expand_ver2', expand_ver2, 1)


if __name__ == '__main__':
    main()
