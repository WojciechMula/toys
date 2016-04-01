base64="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

def group_shifts(mask):
    d = {}
    for i, c in enumerate(base64):
        index = i & mask

        val = ord(c) - i

        if index in d:
            d[index].append(val)
        else:
            d[index] = [val]

    return d


def masks():

    def popcnt(x):
        r = 0
        while x > 0:
            r += x % 2
            x /= 2

        return r

    for mask in xrange(2**6):
        if popcnt(mask) == 4:
            yield mask


for mask in masks():

    table = group_shifts(mask)
    rows  = set(str(row) for row in table.itervalues())

    if len(rows) == 4:
        print 'mask: %x' % mask
        for key in sorted(table):
            print key, table[key]

