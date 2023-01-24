def bitswap(x):
    assert x < 128

    res = 0
    for src in range(7):
        dst = 7 - src
        bit = int(bool(x & (1 << src)))
        res |= bit << dst

    return res

def bitimg(x):
    res = ''
    mask = 0x80
    for i in range(8):
        if x & mask:
            res += '1'
        else:
            res += '0'
        mask >>= 1
    
    return res

name = 'bitswap7'
offset = 0
for x in range(128):
    y = bitswap(x)
    print("DATA %s<>+0x%02x(SB)/1, $0x%02x // %s => %s" % (name, offset, y, bitimg(x), bitimg(y)))
    offset += 1

print("GLOBL %s<>(SB), RODATA|NOPTR, $%d" % (name, offset))
