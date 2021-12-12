#!/usr/bin/env python3

from pathlib import Path

def main():
    rootdir = Path('.')

    def input_files():
        for path in rootdir.glob('*.*'):
            if path.suffix in ('.html', '.txt'):
                yield path
        
    text = ''
    for path in input_files():
        text += path.read_text(encoding='utf8')

    for encoding in ('utf8', 'utf16', 'utf32'):
        path = rootdir / f'combined.{encoding}'
        print(f"Writing {path}")
        path.write_text(text, encoding=encoding)


if __name__ == '__main__':
    main()
