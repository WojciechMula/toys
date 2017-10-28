import random

def calculate_vbyte_size(values):

    size = len(values)

    assert size % 4 == 0

    control_stream_size = size / 4

    cnt1, cnt2, cnt3, cnt4 = get_vbyte_statistics(values)

    data_stream_size = cnt1 * 1 \
                     + cnt2 * 2 \
                     + cnt3 * 3 \
                     + cnt4 * 4

    return control_stream_size + data_stream_size


def get_vbyte_statistics(values):

    cnt1 = 0
    cnt2 = 0
    cnt3 = 0
    cnt4 = 0

    for value in values:
        if value < 0x100:
            cnt1 += 1
        elif value < 0x10000:
            cnt2 += 1
        elif value < 0x1000000:
            cnt3 += 1
        elif value < 0x100000000:
            cnt4 += 1
        else:
            assert False, "value too big"

    return (cnt1, cnt2, cnt3, cnt4)


def encode_differences_inplace(data):

    size   = len(data)
    chunks = size / 4

    data.sort()

    previous = data[:4]
    for i in xrange(4, size, 4): # 4 x 32-bit number when SSE is used
        current = data[i:i+4]

        data[i + 0] = current[0] - previous[0]
        data[i + 1] = current[1] - previous[1]
        data[i + 2] = current[2] - previous[2]
        data[i + 3] = current[3] - previous[3]

        previous = current


def experiment():
    
    from math import sqrt

    size = 1024 * 100

    functions = [
        (random.random, "uniform"),
    ]

    def random_input(bits, function):

        random.seed(0)
        
        data = [function() for _ in  xrange(size)]
        minv = min(data)
        maxv = max(data)
        d    = maxv - minv
        data = [(x - minv)/d for x in data]

        assert 0 < bits <= 32
        maxsize = 2**bits - 1

        return [int(maxsize * x)  for x in data]


    for function, name in functions:

        print name

        for bits in xrange(1, 32 + 1):

            data = random_input(bits, function)

            initial_size = size * 4
            vbyte_size   = calculate_vbyte_size(data)
            encode_differences_inplace(data)
            diff_size    = calculate_vbyte_size(data)

            if False:
                print "range: 0..%d (%d bits)" % (2**bits - 1, bits)
                print "unpacked size: %8d" % initial_size
                print "VByte:         %8d (improvement: %4.2f%%)" % (vbyte_size, 100.0 * (initial_size - vbyte_size)/initial_size)
                print "VByte (diff):  %8d (improvement: %4.2f%%)" % (diff_size,  100.0 * (vbyte_size - diff_size)/vbyte_size)
            else:
                imprv = float(vbyte_size - diff_size)/vbyte_size
                k     = 40
                n     = int(k * imprv)
            
                print "%2d %8d %8d %5.2f %s" % (bits, vbyte_size, diff_size, imprv, n * '*')


if __name__ == '__main__':
    experiment()

