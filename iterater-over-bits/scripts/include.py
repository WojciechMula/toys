import sys

def cat(path):
    with open(path, 'rt') as f:
        sys.stdout.write(f.read())

INCLUDE='include '

def main(path):
    with open(path, 'rt') as f:
        for line in f:
            if line.startswith('include '):
                path = line.split()[1]
                cat(path)
            else:
                sys.stdout.write(line)


if __name__ == '__main__':
    main(sys.argv[1])
