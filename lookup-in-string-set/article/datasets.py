import os

def main():
    path = '../datasets'
    files = list(os.listdir(path))
    files.sort()
    for file in files:
        name = file[:-4]
        print("* - ``%s``" % name)
        print("  - %s" % wl(path + '/' + file))
        print("  - gperf tests")


def wl(path):
    with open(path) as f:
        return len(f.readlines())


if __name__ == '__main__':
    main()
