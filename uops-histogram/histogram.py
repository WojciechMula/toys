import sys

architectures = set((s.upper() for s in sys.argv[1:]))

histogram = {}
for uops in range(100):
    histogram[uops] = []

for line in sys.stdin:
    F = line.split()
    arch  = F[0]
    uops  = int(F[1])
    instr = ' '.join(F[2:])

    if arch not in architectures:
        continue

    histogram[uops].append(instr)

print '* - uops'
print '  - count'
print '  - %'
print '  - CPU instructions'

total = sum(map(len, histogram.itervalues()))
for uops in sorted(histogram):
    instructions = histogram[uops]
    if not instructions:
        continue

    count = len(instructions)
    proc = 100.0*count/total

    print '* - %d' % uops
    print '  - %d' % count
    print '  - %.2f' % proc
    if count < 50:
        tmp = sorted(s.lower() for s in instructions)
        print '  - %s' % (', '.join(tmp))
    else:
        print '  -'
