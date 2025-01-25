#!/usr/bin/env python3

import sys
from pathlib import Path

def main():
    src = Path(sys.argv[1])
    dst = Path(sys.argv[2])

    text = src.read_text(encoding='utf8')
    text = text.lower()

    old = ''
    if dst.exists():
        old = dst.read_text(encoding='utf32')

    if text != old:
        print(f"Writing {dst}")
        dst.write_text(text, encoding='utf32')


if __name__ == '__main__':
    main()
