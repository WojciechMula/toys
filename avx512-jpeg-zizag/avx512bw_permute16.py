import sys

shuffled1 = [
    "[ 0, 1][ 2, 3][ 4, 5][ 8, 9][10,11][16,17][18,19][24,25]",
    "[ 6, 7][12,13][14,15][20,21][26,27][28,29][32,33][34,35]",
    "[22,23][30,31][36,37][42,43][44,45][48,49][50,51][56,57]",
    "[38,39][46,47][52,53][54,55][58,59][60,61][62,63][62,62]",
]

extra1 = [
    [19],
    [15, 29],
    [31, 45, 48],
    [],
]

shuffled2 = [
    "[32,33][32,33][32,33][32,33][32,33][32,33][32,33][32,33]",
    "[18,19][34,35][40,41][48,49][48,49][48,49][48,49][48,49]",
    "[14,15][28,29][34,35][34,35][34,35][34,35][34,35][34,35]",
    "[30,31][44,45][44,45][44,45][44,45][44,45][44,45][44,45]",
]

JPEG_order = [ # for pairs of rows (128-bit lane)
    ( 0,  1,  8, 16,  9,  2,  3, 10, 17, 24, 32, 25, 18, 11,  4,  5),
    (12, 19, 26, 33, 40, 48, 41, 34, 27, 20, 13,  6,  7, 14, 21, 28),
    (35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23, 30, 37, 44, 51),
    (58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 47, 55, 62, 63),
]


def main():
    if '--html' in sys.argv[1:]:
        print_html()
    else:
        code_helpers()


def code_helpers():
    print "shuffle 16-bit patterns"
    print "step #1"
    shuffle_16bit_patterns(shuffled1)
    print "step #2"
    shuffle_16bit_patterns(shuffled2)

    print
    print "shuffle 8-bit patterns"
    print "step #1"
    shuffle_8bit_patterns(shuffled1)
    print "step #2"
    shuffle_8bit_patterns(shuffled2)


def print_html():
    html(shuffled1, extra1)

    print
    html(shuffled2)


def parse_pairs(s):
    result = []
    for item in s.replace(']', '').split('['):
        if item == '':
            continue

        tmp = item.split(',')
        a = int(tmp[0].strip())
        b = int(tmp[1].strip())
        result.append((a, b))


    assert len(result) == 8

    return result


def shuffle_16bit_patterns(shuffle):
    for lane, row in enumerate(shuffle):
        pairs = parse_pairs(row)
        
        tmp = [a/2 for a, b in pairs]
        print "lane #%d: %s" % (lane, ', '.join('%2d' % x for x in tmp))


def parse_bytes(s):
    s = s.replace(']', ' ')
    s = s.replace('[', ' ')
    s = s.replace(',', ' ')

    result = map(int, s.split())
    assert len(result) == 16
    return result


def shuffle_8bit_patterns(shuffle):
    for lane in xrange(4):
        bytes = parse_bytes(shuffle[lane])
        order = JPEG_order[lane]

        tmp = []
        for index in order:
            try:
                tmp.append(bytes.index(index))
            except ValueError:
                tmp.append(-1)

        print "lane #%d: %s" % (lane, ', '.join('%2d' % x for x in tmp))


def html(shuffled, extra=None):
    colors = ["red", "green", "blue", "magenta"]
    extra_color = "black"
    for lane in xrange(4):
        try:
            extra_indices = extra[lane]
        except TypeError:
            extra_indices = []

        def get_color(index):
            if index in extra_indices:
                return extra_color
            
            lane_idx = index/16
            return colors[lane_idx]

        row = shuffled[lane]
        pairs = parse_pairs(row)
        tmp = []
        for a, b in pairs:
            color_a = get_color(a)
            color_b = colors[b/16]
            html = '[<font color="%s">%2d</font>,<font color="%s">%2d</font>]' % (get_color(a), a, get_color(b), b)
            tmp.append(html)

        print "lane %d = %s" % (lane, ''.join(tmp))



if __name__ == '__main__':
    main()

