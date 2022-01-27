def _mm_set1_epi8(x):
    return x

def dump(name, v):
    tmp = "|".join('%02x' % x for x in v)
    print("%-2s = |%s|" % (name, tmp))

def _mm_add_epi8(v, x):
    if type(x) is int:
        return [(y + x) & 0xff for y in v]
    
def _mm_subs_epu8(v, x):
    if type(x) is int:
        return [max(y - x, 0) for y in v]

def _mm_sub_epi8(v, x):
    if type(x) is int:
        return [(y - x) & 0xff for y in v]

def _mm_and_si128(v, x):
    if type(x) is int:
        return [(y & x) & 0xff for y in v]

def _mm_adds_epu8(v, x):
    if type(x) is int:
        return [min((y + x), 255) for y in v]

def _mm_min_epu8(v1, v2):
    return [min(a, b) for (a, b) in zip(v1, v2)]


v = list(map(ord, "0123456789abcdefABCDEF?xyzXYZ\xff\x04"))
dump("v", v)
t1 = _mm_add_epi8(v, _mm_set1_epi8(0xff - ord('9'))); # puts 0-9 at top of unsigned integer range
dump("t1", t1)
t2 = _mm_subs_epu8(t1, _mm_set1_epi8(6)); # now, put 6 blank spots above 0-9
dump("t2", t2)
t3 = _mm_sub_epi8(t2, _mm_set1_epi8(0xf0));
dump("t3", t3)
t4 = _mm_and_si128(v, _mm_set1_epi8(0xdf)); # squash case
dump("t4", t4)
t5 = _mm_sub_epi8(t4, _mm_set1_epi8(ord('A'))); # put the 'A-F' at 0..5
dump("t5", t5)
t6 = _mm_adds_epu8(t5, _mm_set1_epi8(10)); # now put A-F at 10..15, with a guarantee that nothing is smaller
dump("t6", t6)
t7 = _mm_min_epu8(t3, t6); # t7 is normalized hex nibbles
dump("t7", t7)
t8 = _mm_adds_epu8(t7, _mm_set1_epi8(127-15)); # t8 has high_bit == 1 iff what we had wasn't valid hex
dump("t8", t8)
