import sys
import uvint
import io
from pathlib import Path


def main():
    path = Path(sys.argv[1])
    out  = Path(sys.argv[2])
    with open(out, 'wb') as f:
        decompress(f, path.read_bytes())


def decompress(file, buf):

    input = io.BytesIO(buf)

    def read_uvint():
        return uvint.decode_from_file(input)

    def read_string(length):
        s = input.read(length)
        #assert len(s) == length

        return s

    # read symbol table
    symbols = []
    while True:
        length = read_uvint()
        if length == 0:
            break

        symbols.append(read_string(length))

    # decode message
    n = len(buf)
    while input.tell() < n:
        proc = 100 * (n - len(buf)) / n

        cmd = read_uvint()
        if cmd < 128:
            # raw string of length 0..127
            file.write(read_string(cmd))
        else:
            # symbol
            symbol = cmd - 128
            file.write(symbols[symbol])

if __name__ == '__main__':
    main()
