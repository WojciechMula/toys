#!/usr/bin/env python3
from pathlib import Path
from io import StringIO
import sys

def main():
    base_url1 = sys.argv[1].removesuffix('/')
    html1     = Path(sys.argv[2])
    base_url2 = sys.argv[3].removesuffix('/')
    html2     = Path(sys.argv[4])
    py        = Path(sys.argv[5])

    data = {}
    for (name, url, title) in parse_henk(html1):
        if name not in data:
            data[name] = Struct()

        struct = data[name]
        struct.url1  = url
        struct.title = title

    for (name, url, title) in parse_felix(html2):
        if name not in data:
            data[name] = Struct()

        struct = data[name]
        struct.url2  = url
        if struct.title is None:
            struct.title = title

    f = StringIO()
    def writeln(s):
        f.write(s + '\n')

    writeln(f'URL1 = "{base_url1}"')
    writeln(f'URL2 = "{base_url2}"')
    writeln("OPCODES = {")
    for name, struct in data.items():
        if struct.url1 is not None:
            writeln(f' "{name}": (URL1, "{struct.url1}"),')
        elif struct.url2 is not None:
            writeln(f' "{name}": (URL2, "{struct.url2}"),')
    writeln("}")

    update_file(Path("x86doc.py"), f.getvalue())


class Struct:
    def __init__(self):
       self.url1 = None
       self.url2 = None
       self.title = None


def parse_henk(path):
    s = path.read_text()

    for row in parse_html_table(s):
        cols = list(parse_html_row(row))

        link_name, description = cols[0], cols[1]
        link, name = parse_link(link_name)
        yield (name, link, description)


def parse_felix(path):
    s = path.read_text()
    for row in parse_html_table(s):
        cols = list(parse_html_row(row))
        if len(cols) == 2:
            link_name, description = cols
            link, name = parse_link(link_name)
            yield (name, link, description)


def parse_link(s):
    # <a href="link">title</a> => (link, title)
    s = s.replace("'", '"')
    (_, link,  s) = cut(s, 'href="', '"')
    (_, title, s) = cut(s, '>', '<')

    return (link, title)


def parse_delimited(s, sep1, sep2):
    while s:
        item = cut(s, sep1, sep2)
        if item is None:
            break

        (_, val, after) = item
        s = after

        yield val


def parse_html_table(s):
    yield from parse_delimited(s, '<tr>', '</tr>')


def parse_html_row(s):
    yield from parse_delimited(s, '<td>', '</td>')


def cut(s, sep1, sep2):
    before, sep, after = s.partition(sep1)
    if not sep:
        return None

    between, sep, after = after.partition(sep2)
    assert sep

    return (before, between, after)


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
