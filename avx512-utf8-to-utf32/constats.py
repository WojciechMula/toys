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


if __name__ == '__main__':
    main()
