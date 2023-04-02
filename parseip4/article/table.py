def main(): 
    print(".. list-table:: Valid dot patterns")
    print("    :header-rows: 1")
    print("")

    def row(length, numpatterns, bin, hex):
        print("    * - %s" % length)
        print("      - %s" % numpatterns)
        print("      - %s" % bin)
        print("      - %s" % hex)

    row("length in bytes", "# of patterns", "masks (binary)", "masks (hex)")
    L = generate()
    total = 0
    for length in sorted(L):
        patterns = L[length]
        numpatterns = len(patterns)
        total += numpatterns
        bin = ', '.join('``%s``' % p for p in patterns)
        hex = ', '.join('``%04x``' % int(p, 2) for p in patterns)
        
        row(length, numpatterns, bin, hex)
    else:
        row("total", total, "", "")


def generate():
    L = {}
    for code in range(256):
        l3 = (code >> (0*2)) & 0x03
        l2 = (code >> (1*2)) & 0x03
        l1 = (code >> (2*2)) & 0x03
        l0 = (code >> (3*2)) & 0x03
        lengths = [l0, l1, l2, l3]
        if 0 in lengths:
            continue

        bin = ('0' * l0 + '1') + ('0' * l1 + '1') + ('0' * l2 + '1') + '0' * l3
        n = len(bin)
        if n not in L:
            L[n] = set()

        L[n].add(bin)

    return L
        
if __name__ == '__main__':
    main()
