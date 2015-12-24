import sys

try:
    import ctypes
    dll = ctypes.windll.kernel32
except AttributeError:
    dll = None


windows_color = {
    'darkblue'    : 1,
    'darkgreen'   : 2,
    'darkteal'    : 3,
    'darkred'     : 4,
    'darkpink'    : 5,
    'darkyellow'  : 6,
    'gray'        : 7,
    'darkgray'    : 8,
    'blue'        : 9,
    'green'       : 10,
    'teal'        : 11,
    'red'         : 12,
    'pink'        : 13,
    'yellow'      : 14,
    'white'       : 15,
    ''            : 7,
    'normal'      : 7,
}


if dll is not None:

    class WindowsConsole:

        def __init__(self):
            STD_OUTPUT_HANDLE = -11
            self.hnd = dll.GetStdHandle(STD_OUTPUT_HANDLE)

        def color(self, number):
            dll.SetConsoleTextAttribute(self.hnd, number)


    con = WindowsConsole()

else:

    class DummyConsole:

        def color(self, number):
            pass

    con = DummyConsole()


def print_colored(string):

    def process(s):
        head, tmp  = s.split('{', 1)
        name, tail = tmp.split('}', 1)

        sys.stdout.write(head)

        try:
            con.color(windows_color[name.lower()])
        except KeyError:
            pass # don't panic, just colors

        return tail

    s = string
    while s:
        s = process(s)


if __name__ == '__main__':
    print_colored('Hello {red}World{yellow}!{green} Test{}     {Blue}Great!{}')

