def setbit(value, bit):
    value |= 1 << bit

    return value


def reference(pos, length):
    assert pos >= 0 and pos < 16
    assert length >= 1 and length <= 16
    
    result = 0
    for i in xrange(length):
        result = setbit(result, pos + i)

    return result


def bt_hack(pos, length):

    a = setbit(0, pos)
    b = setbit(0, pos + length)

    return b - a


for pos in xrange(0, 16):
    for length in xrange(1, 17):
        ref = reference(pos, length)
        ret = bt_hack(pos, length)

        if ref != ret:
            print 'result: %x, expected: %x' % (ret, ref)
            assert false
