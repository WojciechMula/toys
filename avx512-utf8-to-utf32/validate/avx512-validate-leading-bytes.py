# proof for AVX512 approach

def length(nibble):
    if nibble & 0x8 == 0x0:
        return 1
    if nibble & 0xc == 0x8:
        return 0
    if nibble & 0xe == 0xc:
        return 2
    if nibble & 0xf == 0xe:
        return 3
    if nibble & 0xf == 0xf:
        return 4

    assert False


def generate_words():
    continuation = b'\x80'
    for byte0 in range(0, 256):
        if length(byte0 >> 4) < 2:
            continue

        for byte1 in range(256):
            if byte1 & 0xc0 != 0x80:
                continue

            b0 = byte0.to_bytes(1, 'little')
            b1 = byte1.to_bytes(1, 'little')

            char2 = b0 + b1
            v, r = is_valid_utf8(b0 + b1)
            if v:
                yield (r, v, byte0, byte1)
                continue

            v, r = is_valid_utf8(b0 + b1 + continuation)
            if v:
                yield (r, v, byte0, byte1)
                continue

            v, r = is_valid_utf8(b0 + b1 + continuation + continuation)
            if v:
                yield (r, v, byte0, byte1)
                continue

            yield (r, False, byte0, byte1)


def is_valid_utf8(bytes):
    try:
        str(bytes, encoding='utf8')
        return True, ''
    except UnicodeError as e:
        return False, str(e)


def algorithm(leading_byte, continuation1):
    assert 0 <= leading_byte <= 255
    assert 0 <= continuation1 <= 255

    nibble1 = leading_byte >> 4
    nibble0 = leading_byte & 0xf

    # pshufb of (leading_byte >> 4)
    n = length(nibble1)

    if n == 0:
        return (False, "cont")
    
    if n == 1:
        return (True, "ASCII")

    if n == 2:
        greater = (leading_byte >= 0xc2)
        return (greater, "len2")

    if False:
        # naive version
        if n == 3:
            M = (continuation1 & 0x3f) > 0x1f
            if nibble0 == 0b0000:
                return (M, "len3: M")
            if nibble0 == 0b1101:
                return (not M, "len3: !M")

            return (True, "len3")
    else:
        if n == 3:
            tmp = continuation1 & 0x3f
            if nibble0 == 0b0000:
                tmp = tmp ^ 0b0000_0000
            elif nibble0 == 0b1101:
                tmp = tmp ^ 0b0010_0000
            else:
                tmp = tmp ^ 0b1100_0000

            return (tmp > 0x1f, "len3")

    if False:
        if n == 4:
            M = (continuation1 & 0x3f) > 0x0f
            if nibble0 == 0b0000:
                return (M, f"len4: M ({M}, {continuation1:08b})")
            if nibble0 in (0b0001, 0b0010, 0b0011):
                return True, "len4"
            if nibble0 == 0b0100:
                return (not M, "len4: !M")
            
            return (False, "len4*")
    else:
        if n == 4:
            tmp = continuation1 & 0x3f

            a = (tmp - 0x10) & 0xff

            tmp = a ^ 0x40

            if nibble0 == 0b0000:
                # tmp > 0x0f
                mask = 0x40
            elif nibble0 in (0b0001, 0b0010, 0b0011):
                # true
                mask = 0xc0
            elif nibble0 == 0b0100:
                # tmp <= 0x0f
                mask = 0x80
            else:
                # false
                mask = 0x00

            t0 = (tmp & mask)
            flag = t0 != 0

            print(f"{nibble0:02x}: {continuation1 & 0x3f:02x} & {mask:02x} = {t0:02x} ({flag})")

            return (flag, "len4*")
            

    return (False, "other")


def main():
    failed = 0
    for i, (reason, expected, byte0, byte1) in enumerate(generate_words()):
        result, which = algorithm(byte0, byte1)
        if result != expected:
            #print(reason)
            print(failed, '\t', f'{byte0:02x} {byte1:02x} -> expected={expected}, result={result} {which}')
            print()
            failed += 1


if __name__ == '__main__':
    main()
