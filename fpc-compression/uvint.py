def encode(x):
    assert x >= 0
    buf = b''
    while True:
        if x < 128:
            buf += (x | 0x80).to_bytes(1, "little")
            break
        else:
            buf += (x & 0x7f).to_bytes(1, "little")

        x >>= 7

    return buf


def decode(buf):
    x = 0
    i = 0
    while True:
        v = int(buf[i])
        x = ((v & 0x7f) << (7*i)) | x
        i += 1
        if v & 0x80:
            return x, i

def decode_from_file(file):
    x = 0
    i = 0
    while True:
        b = file.read(1)
        assert len(b) == 1, len(b)
        v = int.from_bytes(b, 'little')
        x = ((v & 0x7f) << (7*i)) | x
        i += 1
        if v & 0x80:
            return x


if __name__ == '__main__':
    for x in range(0, 100000):
        enc = encode(x)
        dec, length = decode(enc)
        assert x == dec
        assert len(enc), length
