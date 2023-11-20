def diff1(h1, h2):
    s = 0
    for i in range(128):
        s += abs(h1[i] - h2[i])

    return s

def make_byte_hist(s):
    h = [0] * 128
    for i in range(len(s)):
        b = ord(s[i])
        h[b] += 1

    return h


def diff2(h1, h2):
    # assume we use 64-bit numbers, thus 4-element arrays
    s = 0
    for i in range(4):
        d = h1[i] ^ h2[i]
        s += d.bit_count()
    
    return s


def make_bit_hist(s):
    h = [0] * 4
    for i in range(len(s)):
        b = ord(s[i])

        word_idx = b >> 6
        bit_pos  = b & 0x3f
        bit      = 1 << bit_pos

        h[word_idx] |= bit

    return h


word = "rebase"
misspelled = "revase" # b -> v

h1 = make_byte_hist(word)
h2 = make_byte_hist(misspelled)

print("h1 =", h1)
print("h2 =", h2)
print(diff1(h1, h2))

h1 = make_bit_hist(word)
h2 = make_bit_hist(misspelled)

print("h1 = [%s]" % ' '.join(('{:064b}'.format(w) for w in h1)))
print("h2 = [%s]" % ' '.join(('{:064b}'.format(w) for w in h2)))
print(diff2(h1, h2))
