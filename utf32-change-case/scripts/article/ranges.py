def main():
    lower, upper = map(sets, map(ranges, aux()))

    for i in range(max(len(lower), len(upper))):
        lowercase_range, lowercase_count = format(lower, i)
        uppercase_range, uppercase_count = format(upper, i)

        print(f"    * - {lowercase_range}")
        print(f"      - {lowercase_count}")
        print(f"      - {uppercase_range}")
        print(f"      - {uppercase_count}")


def format(list, index):
    try:
        item = list[index]
        if isinstance(item, tuple):
            first, last = item
            assert first != last
            rng   = f"[``0x{first:02x}`` ... ``0x{last:02x}``]"
            count = last - first + 1
        elif isinstance(item, set):
            count = len(item)
            tmp = [f"``0x{val:02x}``" for val in item]
            if len(tmp) > 1:
                rng = "{" + ', '.join(tmp) + "}"
            else:
                rng = tmp[0]
        else:
            assert False

        return (rng, str(count))
    except IndexError:
        return ("", "")


def aux():
    lower = []
    upper = []
    for i in range(0x1_ffff + 1):
        src = chr(i)
        if src != src.lower():
            lower.append(i)
        if src != src.upper():
            upper.append(i)

    return (lower, upper)


def ranges(L):
    res = []
    first, last = L[0], L[0]
    for x in L[1:]:
        if last + 1 == x:
            last = x
        else:
            res.append((first, last))
            first = last = x

    res.append((first, last))

    return res


def sets(L):
    res = []
    s = set()
    for (first, last) in L:
        if first == last:
            s.add(first)
        else:
            if s:
                res.append(s)
                s = set()
            else:
                res.append((first, last))

    if s:
        res.append(s)

    return res


if __name__ == '__main__':
    main()
