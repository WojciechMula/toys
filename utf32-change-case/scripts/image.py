from io import StringIO
from pathlib import Path

N = 4
spacing = 2
padding = 5

BACKGROUND  = "255 255 255"
UNUSED      = "200 200 200"
ONE_CODE    = "0 0 255"
TWO_CODES   = "0 255 0"
THREE_CODES = "255 0 0"


def mkimage(conv):
    def hline(n, color):
        row.extend([color] * n)

    image = []
    for hi in range(0, 0x1ff+1):
        row = []
        hline(padding, BACKGROUND)
        for lo in range(0, 0xff+1):
            src_code = (hi << 8) | lo
            src = chr(src_code)
            dst = conv(src)

            color = UNUSED
            if src != dst:
                if len(dst) == 1:
                    color = ONE_CODE
                elif len(dst) == 2:
                    color = TWO_CODES
                elif len(dst) == 3:
                    color = THREE_CODES

            if lo > 0:
                hline(spacing, BACKGROUND)

            hline(N, color)
        else:
            hline(padding, BACKGROUND)

        image.append(row)

    return image


def ppm(conv):
    lines = mkimage(conv)

    def render_line(line):
        return ' '.join(line) + '\n'

    width  = len(lines[0])
    height = len(lines) * N + (len(lines) - 1) * spacing + 2 * padding

    f = StringIO()
    f.write(f"P3\n{width} {height}\n255\n")

    background = [BACKGROUND] * width
    background = render_line(background)

    for _ in range(padding):
        f.write(background)

    for i, line in enumerate(lines):
        if i > 0:
            for _ in range(spacing):
                f.write(background)

        line = render_line(line)
        for _ in range(N):
            f.write(line)

    for _ in range(padding):
        f.write(background)

    return f.getvalue()


def main():
    out = Path("upper.ppm")
    out.write_text(ppm(lambda s: s.upper()))

    out = Path("lower.ppm")
    out.write_text(ppm(lambda s: s.lower()))


if __name__ == '__main__':
    main()
