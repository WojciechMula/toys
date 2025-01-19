LIGHT_BOXES = """
         +--+----+   +--+----+   +--+----+  +--+----+
         |  |    |   |  |    |   |  |    |  |  |    |
         +--+----+   +--+----+   |  |    |  |  |    |
                     |  |    |   +--+----+  |  |    |
                     +--+----+              +--+----+

"""

DOUBLE_BOXES = """

         +==+====+   +==+====+   +==+====+  +==+====+
         #  #    #   #  #    #   #  #    #  #  #    #
         +==+====+   +==+====+   #  #    #  #  #    #
                     #  #    #   +==+====+  #  #    #
                     +==+====+              +==+====+

"""

MIXED_BOXES_1 = """
         +==+====+   +==+====+   +==+====+  +==+====+
         |  |    |   |  |    |   |  |    |  |  |    |
         +==+====+   +==+====+   |  |    |  |  |    |
                     |  |    |   +==+====+  |  |    |
                     +==+====+              +==+====+
"""

MIXED_BOXES_2 = """
         +--+----+   +--+----+   +--+----+  +--+----+
         #  #    #   #  #    #   #  #    #  #  #    #
         +--+----+   +--+----+   #  #    #  #  #    #
                     #  #    #   +--+----+  #  #    #
                     +--+----+              +--+----+
"""

ROUNDED_BOXES = r"""

    /-----\   /-----\   /-----\
    |     |   |     |   |     |
    \-----/   +-----+   |     |
              |     |   |     |
              \-----/   \-----/

"""

ARROWS = r"""


                  ^ ^
    ->     <-     | |  |
    -->    <--      |  | |
    --->   <---        | | |
                       v v v
"""


DASHED = r"""

    +---+..+----..
    | Z |  | Aaa
    +---+..+----..

"""


DEMO1 = """
b: blue
r: red
g: green
R: lightred
B: lightblue
G: lightgreen
*: bold


      +==+====+     +---- baz
^                         bbb
      #  #    #     | +-- bit #2
^                         rrrrrrrr
      +==+====+     | |
                    v v
    +----------+----------+==========+
    | 10001000 | 01011110 | 10000001 #  <---- bar
^     bbbgggrr      * *     bbbbgggg
    |          +===+      |          #
    |          |   |      |          #
    +==========+---+------+----------+
         ^
         |              +--+----+
         |              |  |    | <-+
         |              +--+----+   |
         |                         this
      fooooooo
^     bbbbbbbb


        -----> RGB <---
^              RGB

"""


def main():
    tests = [
        LIGHT_BOXES,
        DOUBLE_BOXES,
        MIXED_BOXES_1,
        MIXED_BOXES_2,
        ROUNDED_BOXES,
        ARROWS,
        DASHED,
        DEMO1,
    ]

    for test in tests:
        lines = test.splitlines()
        canvas, styles = parse(lines, unindent=True)
        rules = RuleMatcher(all_rules)
        transformed = apply_rules(canvas, rules)

        if styles:
            print_ansi(transformed, styles)
        else:
            transformed.dump()


def make_converter():
    rules = RuleMatcher(all_rules)

    def convert(lines, cssclass, transform):
        canvas, styles = parse(lines, unindent=True)
        if transform:
            transformed = apply_rules(canvas, rules)
        else:
            transformed = canvas

        def callback(styles):
            if styles is None:
                return '</span>'

            css = []
            for style in styles:
                if style == 'bold':
                    css.append('font-weight: bold')
                elif style == 'italic':
                    css.append('font-style: italic')
                else:
                    css.append(f'color: {style}')

            return '<span style="%s">' % ('; '.join(css))

        apply_html_entities(transformed)
        s  = f'<pre class="{cssclass}">'
        s += '\n'.join(apply_styles(transformed, styles, callback))
        s += '</pre>'

        return s

    return convert


html_entities = {
    '&' : '&amp;',
    '<' : '&lt;',
    '>' : '&gt;',
    '"' : '&quot;',
    "'" : '&apos;',
}

def apply_html_entities(canvas):
    for line in canvas.lines:
        for i in range(len(line)):
            line[i] = html_entities.get(line[i], line[i])


def apply_rules(canvas, rules):
    transformed = Canvas()
    transformed.lines = []
    transformed.attributes = canvas.attributes

    for y, line in enumerate(canvas.lines):
        copy = line[:]
        for x, char in enumerate(line):
            repl = rules.match(canvas, x, y)
            if repl is not None:
                copy[x] = repl

        transformed.lines.append(copy)

    return transformed


def parse(lines, unindent):
    while lines:
        if lines[0] != '':
            break
        else:
            lines = lines[1:]

    while lines:
        if lines[-1] != '':
            break
        else:
            lines = lines[:-1]

    styles = parse_styles(lines)
    canvas = parse_drawing(lines[len(styles):], styles, unindent)

    return (canvas, styles)


def parse_styles(lines):
    style = {}
    for line in lines:
        name, sep, val = line.partition(':')
        if sep == '':
            break

        name = name.strip()
        val  = val.strip()

        if len(name) != 1:
            break

        if name in style:
            raise ValueError(f"style '{name}' defined twice")

        s = {s.strip() for s in val.split(',')}
        s.discard('')
        style[name] = s

    return style


def parse_drawing(lines, styles, unindent):
    canvas = Canvas()
    canvas.lines = []
    canvas.attributes = []

    indent = min(len(line) - len(line.lstrip()) for line in lines if line)
    if indent:
        lines = [line[indent:] for line in lines]

    for line in lines:
        if line and line[0] == '^':
            canvas.attributes[-1] = parse_attributes(line, styles)
        else:
            canvas.lines.append(line)
            canvas.attributes.append([])

    assert len(canvas.lines) == len(canvas.attributes)

    if unindent:
        indent = min(len(line) - len(line.lstrip()) for line in canvas.lines if line)
        for i in range(len(canvas.lines)):
            canvas.lines[i] = list(canvas.lines[i][indent:])
            canvas.attributes[i] = canvas.attributes[i][indent:]

    return canvas


def parse_attributes(line, styles):
    tmp = [None] * len(line)
    for i, char in enumerate(line):
        if char not in ('^', ' '):
            assert char in styles, (char, styles)
            tmp[i] = char

    return tmp


class Canvas:
    def __getitem__(self, xy):
        try:
            x, y = xy
            if x < 0 or y < 0:
                return ' '
            return self.lines[y][x]
        except IndexError:
            return ' '

    def dump(self):
        for line in self.lines:
            print('"%s"' % (''.join(line)))


class Rule:
    def __init__(self, coords, char, repl):
        self.coords = coords
        self.repl   = repl
        self.char   = char

    def match(self, canvas, x, y):
        for (dx, dy, char) in self.coords:
            if canvas[x + dx, y + dy] != char:
                return False

        return True

    def dump(self):
        tmp = {}
        for (dx, dy, char) in self.coords:
            tmp[(dx + 1, dy + 1)] = char

        print()
        for y in range(3):
            print('"', end='')
            for x in range(3):
                print(tmp.get((x, y), ' '), end='')

            if y == 1:
                print('" =>', self.repl)
            else:
                print('"')

    def __len__(self):
        return len(self.coords)


def mkrule(prev, curr, next, repl):
    assert len(prev) == 3
    assert len(curr) == 3
    assert len(next) == 3
    assert len(repl) == 1

    coords = []
    for (dy, row) in enumerate([prev, curr, next], -1):
        for (dx, char) in enumerate(row, -1):
            if char != ' ':
                coords.append((dx, dy, char))

    return Rule(coords, curr[1], repl)


all_rules = [
    # arrows
    mkrule(
        "   ",
        " <-",
        "   ", '◀'
    ),
    mkrule(
        "   ",
        "-> ",
        "   ", '▶'
    ),
    mkrule(
        " | ",
        " v ",
        "   ", '▼'
    ),
    mkrule(
        "   ",
        " ^ ",
        " | ", '▲'
    ),
    mkrule(
        "   ",
        "<- ",
        "   ", '─'
    ),
    mkrule(
        "   ",
        " ->",
        "   ", '─'
    ),
    mkrule(
        " ^ ",
        " | ",
        "   ", '│'
    ),
    mkrule(
        "   ",
        " | ",
        " v ", '│'
    ),

    # lines
    mkrule(
        "   ",
        " -+",
        "   ", '─'
    ),
    mkrule(
        "   ",
        " -+",
        "   ", '─'
    ),
    mkrule(
        " + ",
        " | ",
        "   ", '│'
    ),
    mkrule(
        "   ",
        " | ",
        " + ", '│'
    ),


    # half lines
    mkrule(
        "   ",
        "-- ",
        "   ", '╴'
    ),
    mkrule(
        "   ",
        " --",
        "   ", '╶'
    ),
    mkrule(
        " | ",
        " | ",
        "   ", '╵'
    ),
    mkrule(
        " | ",
        " | ",
        "   ", '╷'
    ),

    # rounded boxes
    mkrule(
        " | ",
        " \\-",
        "   ", '╰'
    ),
    mkrule(
        " | ",
        "-/ ",
        "   ", '╯'
    ),
    mkrule(
        "   ",
        " /-",
        " | ", '╭'
    ),
    mkrule(
        "   ",
        "-\\ ",
        " | ", '╮'
    ),

    mkrule(
        "|  ",
        "\\- ",
        "   ", '─'
    ),
    mkrule(
        "   ",
        "/- ",
        "|  ", '─'
    ),
    mkrule(
        "   ",
        " -\\",
        "  |", '─'
    ),
    mkrule(
        "  |",
        " -/",
        "   ", '─'
    ),

    mkrule(
        "   ",
        " | ",
        " \\-", '│'
    ),
    mkrule(
        "   ",
        " | ",
        "-/ ", '│'
    ),
    mkrule(
        "-\\ ",
        " | ",
        "   ", '│'
    ),
    mkrule(
        " /-",
        " | ",
        "   ", '│'
    ),

    # light boxes
    mkrule(
        "   ",
        "---",
        "   ", '─'
    ),
    mkrule(
        "   ",
        "+--",
        "|  ", '─'
    ),
    mkrule(
        "|  ",
        "+--",
        "   ", '─'
    ),
    mkrule(
        "|  ",
        "+--",
        "|  ", '─'
    ),
    mkrule(
        "   ",
        "--+",
        "  |", '─'
    ),
    mkrule(
        "  |",
        "--+",
        "   ", '─'
    ),
    mkrule(
        "  |",
        "--+",
        "  |", '─'
    ),
    mkrule(
        " | ",
        " | ",
        " | ", '│'
    ),
    mkrule(
        " + ",
        " | ",
        " | ", '│'
    ),
    mkrule(
        " + ",
        " | ",
        " + ", '│'
    ),
    mkrule(
        " | ",
        " | ",
        " + ", '│'
    ),
    mkrule(
        "   ",
        " +-",
        " | ", '┌'
    ),
    mkrule(
        "   ",
        "-+ ",
        " | ", '┐'
    ),
    mkrule(
        " | ",
        "-+ ",
        "   ", '┘'
    ),
    mkrule(
        " | ",
        " +-",
        "   ", '└'
    ),
    mkrule(
        " | ",
        "-+-",
        "   ", '┴'
    ),
    mkrule(
        "   ",
        "-+-",
        " | ", '┬'
    ),
    mkrule(
        " | ",
        "-+-",
        " | ", '┼'
    ),
    mkrule(
        " | ",
        " +-",
        " | ", '├'
    ),
    mkrule(
        " | ",
        "-+ ",
        " | ", '┤'
    ),

    # double boxes
    mkrule(
        "   ",
        "===",
        "   ", '═'
    ),
    mkrule(
        "   ",
        "+==",
        "#  ", '═'
    ),
    mkrule(
        "#  ",
        "+==",
        "   ", '═'
    ),
    mkrule(
        "#  ",
        "+==",
        "#  ", '═'
    ),
    mkrule(
        "   ",
        "==+",
        "  #", '═'
    ),
    mkrule(
        "  #",
        "==+",
        "   ", '═'
    ),
    mkrule(
        "  #",
        "==+",
        "  #", '═'
    ),
    mkrule(
        " # ",
        " # ",
        " # ", '║'
    ),
    mkrule(
        " + ",
        " # ",
        " # ", '║'
    ),
    mkrule(
        " + ",
        " # ",
        " + ", '║'
    ),
    mkrule(
        " # ",
        " # ",
        " + ", '║'
    ),
    mkrule(
        "   ",
        " +=",
        " # ", '╔'
    ),
    mkrule(
        "   ",
        "=+ ",
        " # ", '╗'
    ),
    mkrule(
        " # ",
        "=+ ",
        "   ", '╝'
    ),
    mkrule(
        " # ",
        " +=",
        "   ", '╚'
    ),
    mkrule(
        " # ",
        "=+=",
        "   ", '╩'
    ),
    mkrule(
        "   ",
        "=+=",
        " # ", '╦'
    ),
    mkrule(
        " # ",
        "=+=",
        " # ", '╬'
    ),
    mkrule(
        " # ",
        " +=",
        " # ", '╠'
    ),
    mkrule(
        " # ",
        "=+ ",
        " # ", '╣'
    ),

    # boxes: horizontal double, vertical light
    mkrule(
        "   ",
        " +=",
        " | ", '╒'
    ),
    mkrule(
        " | ",
        " +=",
        "   ", '╘'
    ),
    mkrule(
        " | ",
        "=+ ",
        "   ", '╛'
    ),
    mkrule(
        "   ",
        "=+ ",
        " | ", '╕'
    ),
    mkrule(
        "   ",
        "=+=",
        " | ", '╤'
    ),
    mkrule(
        " | ",
        "=+=",
        "   ", '╧'
    ),
    mkrule(
        " | ",
        " +=",
        " | ", '╞'
    ),
    mkrule(
        " | ",
        "=+ ",
        " | ", '╡'
    ),
    mkrule(
        " | ",
        "=+=",
        " | ", '╪'
    ),

    ###
    mkrule(
        "   ",
        "+= ",
        "|  ", '═'
    ),
    mkrule(
        "|  ",
        "+= ",
        "   ", '═'
    ),
    mkrule(
        "  |",
        " =+",
        "   ", '═'
    ),
    mkrule(
        "   ",
        " =+",
        "  |", '═'
    ),
    mkrule(
        "  |",
        " =+",
        "  |", '═'
    ),
    mkrule(
        "|  ",
        "+= ",
        "|  ", '═'
    ),

    # boxes: horizontal light, vertical double
    mkrule(
        "   ",
        " +-",
        " # ", '╓'
    ),
    mkrule(
        " # ",
        " +-",
        "   ", '╙'
    ),
    mkrule(
        " # ",
        "-+ ",
        "   ", '╜'
    ),
    mkrule(
        "   ",
        "-+ ",
        " # ", '╖'
    ),
    mkrule(
        " # ",
        " +-",
        " # ", '╟'
    ),
    mkrule(
        " # ",
        "-+ ",
        " # ", '╢'
    ),
    mkrule(
        " # ",
        "-+-",
        " # ", '╫'
    ),
    mkrule(
        "   ",
        "-+-",
        " # ", '╥'
    ),
    mkrule(
        " # ",
        "-+-",
        "   ", '╨'
    ),
    mkrule(
        "   ",
        "+--",
        "#  ", '─'
    ),
    mkrule(
        "#  ",
        "+--",
        "   ", '─'
    ),
    mkrule(
        "#  ",
        "+--",
        "#  ", '─'
    ),
    mkrule(
        "   ",
        "--+",
        "  #", '─'
    ),
    mkrule(
        "  #",
        "--+",
        "   ", '─'
    ),
    mkrule(
        "  #",
        "--+",
        "  #", '─'
    ),

    # dashed
    mkrule(
        "   ",
        "-+.",
        " | ", '┬'
    ),
    mkrule(
        "   ",
        ".+-",
        " | ", '┬'
    ),
    mkrule(
        " | ",
        "-+.",
        "   ", '┴'
    ),
    mkrule(
        " | ",
        ".+-",
        "   ", '┴'
    ),
    mkrule(
        "   ",
        "+..",
        "   ", '┈'
    ),
    mkrule(
        "   ",
        "+.+",
        "   ", '┈'
    ),
    mkrule(
        "   ",
        "..+",
        "   ", '┈'
    ),
    mkrule(
        "   ",
        "-..",
        "   ", '┈'
    ),
    mkrule(
        "   ",
        ".. ",
        "   ", '┈'
    ),
    mkrule(
        "   ",
        "...",
        "   ", '┈'
    ),
    mkrule(
        "   ",
        " ..",
        "   ", '┈'
    ),
]


class RuleMatcher:
    def __init__(self, rules):
        self.lookup = {}
        for rule in rules:
            if rule.char not in self.lookup:
                self.lookup[rule.char] = []

            self.lookup[rule.char].append(rule)

        for rule_list in self.lookup.values():
            rule_list.sort(key=lambda rule: len(rule), reverse=True)

    def match(self, canvas, x, y):
        char = canvas[x, y]
        try:
            rule_list = self.lookup[char]
        except KeyError:
            return None

        for rule in rule_list:
            if rule.match(canvas, x, y):
                return rule.repl


def apply_styles(canvas, styles, callback):
    result = []
    for (chars, attributes) in zip(canvas.lines, canvas.attributes):
        line = ''
        prev_style = None
        for i, char in enumerate(chars):
            try:
                curr_style = attributes[i]
            except IndexError:
                curr_style = None

            if prev_style != curr_style:
                if prev_style is not None:
                    line += callback(None)

                if curr_style is not None:
                    line += callback(styles[curr_style])

                prev_style = curr_style

            line += char

        if prev_style is not None:
            line += callback(None)

        result.append(line)

    return result


def print_ansi(canvas, styles):
    console_codes = {
        None            : '\033[0m',
        'black'         : '\033[30m',
        'red'           : '\033[31m',
        'green'         : '\033[32m',
        'brown'         : '\033[33m',
        'blue'          : '\033[34m',
        'magenta'       : '\033[35m',
        'cyan'          : '\033[36m',
        'white'         : '\033[37m',
        'lightblack'    : '\033[90m',
        'lightred'      : '\033[91m',
        'lightgreen'    : '\033[92m',
        'lightbrown'    : '\033[93m',
        'lightblue'     : '\033[94m',
        'lightmagenta'  : '\033[95m',
        'lightcyan'     : '\033[96m',
        'lightwhite'    : '\033[97m',
        'bold'          : '\033[1m',
    }

    def callback(style):
        if style is None:
            return console_codes[None]

        return ''.join(console_codes[item] for item in style)

    res = apply_styles(canvas, styles, callback)
    for line in res:
        print(line)


if __name__ == '__main__':
    main()
