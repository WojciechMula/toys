# program verifies if calculations in ../swar.c never cause overflow

for alpha1 in xrange(256):
    alpha2 = 255 - alpha1

    for a in xrange(256):
        for b in xrange(256):
            c = a * alpha1 + b * alpha2
            assert c < 2**16

print("OK")
