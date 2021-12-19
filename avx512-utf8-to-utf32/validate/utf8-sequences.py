def main():
    L = list(sequences())

    name = 'utf8-sequences'
    path = f'{name}.h'
    with open(path, 'w') as f:
        f.write(HEADER % len(L))

    print(f"{path} generated")

    path = f'{name}.cpp'
    with open(path, 'w') as f:
        f.write(CPP % name)

        for i, (seq, valid) in enumerate(L):
            tmp = list(map(ord, seq))
            image = "   {%d, {0x%02x, 0x%02x, 0x%02x, 0x%02x, 0x%02x}}" % \
                (valid, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4])

            if i + 1 < len(L):
                image += ','

            f.write(image)
            f.write('\n')

        f.write(TAIL)

    print(f"{path} generated")


HEADER = """#pragma once

#include <cstddef>
#include <cstdint>

struct UTF8seq {
    bool valid;
    uint8_t bytes[5];
};

constexpr size_t utf8_sequences_size = %d;
extern UTF8seq utf8_sequences[utf8_sequences_size];
"""


CPP = """#include "%s.h"

UTF8seq utf8_sequences[utf8_sequences_size] = {
"""

TAIL = """};
"""


def sequences():
    """
    Produces 5-byte sequences and defines whether they are valid UTF-8.
    We are more focused on the two first bytes, as they are crucial, the
    remaining bytes are either a valid ASCII or continuation byte.
    """
    def aux():
        ASCII = b'.'
        CONT  = b'\x80' # continuation byte
        for b0 in range(256):
            b0 = b0.to_bytes(1, 'little')
            for b1 in range(256):
                b1 = b1.to_bytes(1, 'little')
                yield (b0, b1, ASCII, ASCII, ASCII)
                yield (b0, b1, CONT,  ASCII, ASCII)
                yield (b0, b1, ASCII, CONT,  ASCII)
                yield (b0, b1, CONT,  CONT,  ASCII)
                yield (b0, b1, CONT,  CONT,  CONT)

    for seq in aux():
        bytes = b''.join(seq)
        try:
            str(bytes, encoding='utf8')
            yield (seq, True)
        except UnicodeError as e:
            yield (seq, False)


if __name__ == '__main__':
    main()
