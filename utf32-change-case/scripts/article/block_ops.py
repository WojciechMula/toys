from pathlib import Path
from table import Table


class Stats:
    def __init__(self):
        self.changed_case = 0
        self.unchanged    = 0
        self.ascii        = 0
        self.changed_case_hist = {}

    @property
    def nonascii(self):
        return self.changed_case + self.unchanged

    @property
    def total(self):
        return self.nonascii + self.ascii


def make_stats(text, conv, n):
    stats = Stats()

    for i in range(0, len(text), n):
        tmp = [c for c in text[i:i+n]]
        if all((ord(c) < 128 for c in tmp)):
            stats.ascii += 1
            continue

        changed = sum(int(conv(c) != c) for c in tmp)
        if changed > 0:
            stats.changed_case += 1
            stats.changed_case_hist[changed] = stats.changed_case_hist.get(changed, 0) + 1
        else:
            stats.unchanged += 1

    return stats


table_lower = Table()
table_lower.set_header(["dataset", "block size", "blocks", "ASCII", "changed case", "not changed"])

table_upper = Table()
table_upper.set_header(["dataset", "block size", "blocks", "ASCII", "changed case", "not changed"])

for path in sorted(Path("../../datasets").glob("*.utf32")):
    text = path.read_text(encoding='utf32')
    block_size = 8
    blocks = len(text) // block_size

    cases = [
        (lambda s: s.upper(), table_upper),
        (lambda s: s.lower(), table_lower),
    ]
    for conv, table in cases:
        stats = make_stats(text, lambda s: s.upper(), block_size)

        ascii        = '%.1f%%' % (100 * stats.ascii / stats.total)
        changed_case = '%.1f%%' % (100 * stats.changed_case / stats.nonascii)
        unchanged    = '%.1f%%' % (100 * stats.unchanged / stats.nonascii)

        table.add_row([
            path.stem,
            str(block_size),
            str(blocks),
            ascii,
            changed_case,
            unchanged
        ])

path = Path('table_upper.rst')
print(f"Creating {path}")
path.write_text(str(table_upper))

path = Path('table_lower.rst')
print(f"Creating {path}")
path.write_text(str(table_lower))
