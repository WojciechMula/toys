upper = set()
lower = set()
for src_code in range(0x1_ffff + 1):
    src = chr(src_code)
    dst = src.upper()
    if dst != src:
        if len(dst) == 1:
            upper.add(ord(dst) ^ src_code)
        else:
            upper.add(0x8000_0000)

    dst = src.lower()
    if dst != src:
        if len(dst) == 1:
            lower.add(ord(dst) ^ src_code)
        else:
            lower.add(0x8000_0000)

print("upper: %d" % (len(upper)))
print("lower: %d" % (len(lower)))
