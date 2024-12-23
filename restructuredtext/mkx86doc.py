#!/usr/bin/env python3
from pathlib import Path
from io import StringIO
import sys

def main():
    base_url = sys.argv[1].removesuffix('/')
    html     = Path(sys.argv[2])
    py       = Path(sys.argv[3])

    f = StringIO()
    def writeln(s):
        f.write(s + '\n')

    writeln(f'URL = "{base_url}"')
    writeln("OPCODES = {")
    for (name, title, url) in parse(html):
        writeln(f' "{name}": ("{url}", "{title}"),')
    writeln("}")

    update_file(Path("x86doc.py"), f.getvalue())
 

def parse(path):
    for line in path.read_text().splitlines():
        if not line.startswith('<tr>'):
            continue

        tmp = line.split('</td><td>')
        # ['<tr><td><a href="./html/BLSI.html">BLSI</a>', 'Extract Lowest Set Isolated Bit', 'BMI1</td></tr>']

        title = tmp[1]

        tmp = repl(tmp[0])
        # ['tr', 'td', 'a', 'href=', './html/BLSI.html', 'BLSI', '/a']

        url  = tmp[4].removeprefix("./")
        name = tmp[5]
        yield (name, title, url)


def repl(s):
    tmp = list(s)
    lookup = {'>', '<', '"'}
    for i, char in enumerate(tmp):
        if char in lookup:
            tmp[i] = ' '

    return ''.join(tmp).split()


def update_file(path, contents):
    if path.exists():
        old = path.read_text()
        if old != contents:
            print(f"updating {path}")
            path.write_text(contents)
    else:
        print(f"creating {path}")
        path.write_text(contents)


if __name__ == '__main__':
    main()
