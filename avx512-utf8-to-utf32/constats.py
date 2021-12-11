#!/usr/bin/env python3


def print_rotate_left():
    idx = list(range(16))
    for _ in range(16):
        print("{%s}," % (', '.join('%2d' % v for v in idx)))
        z = idx[-1]
        del idx[-1]
        idx = [z] + idx


def main():
    print_rotate_left()


if __name__ == '__main__':
    main()
