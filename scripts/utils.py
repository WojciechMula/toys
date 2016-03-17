def unicode_bar(width):
    fractions = (
        '',        # 0 - empty
        u'\u258f', # 1/8
        u'\u258e', # 2/8
        u'\u258d', # 3/8
        u'\u258c', # 4/8
        u'\u258b', # 5/8
        u'\u258a', # 6/8
        u'\u2589', # 7/8
    )

    block = u'\u2588'

    assert width >= 0.0

    k8 = int(width * 8)

    k = k8 / 8
    f = k8 % 8

    return block * k + fractions[f]

