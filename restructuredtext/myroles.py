from docutils.parsers.rst.roles import set_classes, nodes, register_canonical_role
from docutils.parsers.rst import Directive
from docutils.parsers.rst.directives import register_directive, flag, class_option
from asciidiag import make_converter
import x86doc

def plwiki_link_role(role, rawtext, text, lineno, inliner, options={}, content=[]):
    set_classes(options)
    ref, text = wikilink(text, 'pl')
    return [nodes.reference(rawtext, nodes.unescape(text), refuri=ref, **options)], []

def enwiki_link_role(role, rawtext, text, lineno, inliner, options={}, content=[]):
    set_classes(options)
    ref, text = wikilink(text, 'en')
    return [nodes.reference(rawtext, nodes.unescape(text), refuri=ref, **options)], []

def x86doc_link_role(role, rawtext, text, lineno, inliner, options={}, content=[]):
    set_classes(options)

    name, sep, title = text.partition('|')
    name = name.upper()
    if sep == '':
        title = name

    url, _ = x86doc.OPCODES[name]
    uri = f"{x86doc.URL}/{url}"

    return [nodes.reference(rawtext, nodes.unescape(title), refuri=uri, **options)], []

def inlinemath_role(role, rawtext, text, lineno, inliner, options={}, content=[]):
    set_classes(options)
    node = nodes.raw(rawtext, simplemath(text), **options)
    node['classes'] = ['math']
    node['format']  = 'html'
    return [node], []

def centermath_role(role, rawtext, text, lineno, inliner, options={}, content=[]):
    set_classes(options)
    node = nodes.raw(rawtext, simplemath(text), **options)
    node['classes'] = ['cmath']
    node['format']  = 'html'
    return [node], []


ascii_diag = make_converter()

class AsciiDiag(Directive):
    has_content = True
    optional_arguments = 2;
    option_spec = {
        'notransform': flag,
        'class': class_option,
    }

    def run(self):
        set_classes(self.options)

        cssclass  = ' '.join(self.options.get('classes', ['asciidiag']))
        transform = 'notransform' not in self.options

        node = nodes.raw('', ascii_diag(self.content, cssclass, transform), **self.options)
        node['format']  = 'html'
        node['classes'] = ['asciidiag']

        return [node]


register_canonical_role('math',   inlinemath_role)
register_canonical_role('cmath',  centermath_role)
register_canonical_role('plwiki', plwiki_link_role)
register_canonical_role('enwiki', enwiki_link_role)
register_canonical_role('x86',    x86doc_link_role)
register_directive('asciidiag', AsciiDiag)


#=== wiki links =========================================================

def wikilink(text, wikilang="pl"):
    """Produces a link to wikipedia"""
    tmp = text.split('|', 2)
    if len(tmp) == 1:
        tmp     = tmp[0].strip()
        article = tmp.replace(' ', '_')
        title   = tmp
    else: # len 2
        article = tmp[0].strip().replace(' ', '_')
        title   = tmp[1].strip()

    # pair: full url, link title
    return ("http://%s.wikipedia.org/wiki/%s" % (wikilang, article), title)


#=== Math expression rendering to HTML ==================================

class Trie(object):
    "Trie with minimal function set"
    def __init__(self):
        self.next = {}
        self.val = None


    def add_word(self, word, value):
        assert value is not None
        node = self
        for c in word:
            if c not in node.next:
                node.next[c] = Trie()
            node = node.next[c]

        node.val = value


    def longest_prefix(self, word):
        node  = self
        last  = 0
        value = None
        for i, c in enumerate(word):
            if c in node.next:
                node = node.next[c]
                if node.val is not None:
                    last  = i+1
                    value = node.val
            else:
                break

        if last:
            return (last, value)
        else:
            return None


subst = Trie()
keep = [
    "sin", "asin", "arcsin",
    "cos", "acos", "arccos",
    "tan", "atan", "arctan", "atan2",
    "cot", "acot", "arccot",
    "tg", "arctg", "ctg", "arcctg",
    "log", "ln", "det",
    "ceil", "floor", "round",
    "min", "max", " mod ",
]
repl = [
    ('\\ ', ' '),
    ('\\{', '{'),
    ('\\}', '}'),
    ('\\_', '_'),
    ('\\^', '^'),

    ('=',   ' = '),
    ('=/=', ' &ne; '),
    ('!=',  ' &ne; '),
    ('+/-', ' &plusmn; '),

    ('<',   ' &lt '),
    ('>',   ' &gt '),
    ('<=',  ' &le; '),
    ('>=',  ' &ge; '),

    ('<->', ' &harr; '),
    ('->',  ' &rarr; '),
    ('<-',  ' &larr; '),

    ('<=>', ' &hArr; '),
    ('==>', ' &rArr; '),
    ('<==', ' &lArr; '),

    ('-',      ' &minus; '),
    ('*',      ' &sdot; '),
    ('\\cdot', ' &sdot; '),
    ('+',      ' + '),
    ('/',      '/'),
    (':=',     ' := '),
    ('%',      ' mod '),

    (r'\in',    '&isin;'),
    (r'\notin', '&notin;'),
    (r'\sqrt',  '&radic;'),
    (r'\div',   '&divide;'),
    (r'\approx', ' &approx; '),

    (';',   '; '),
    (',',   ', '),
    ('...', '&hellip;'),
    ('PI',  '&pi;'),
    ('1/2', '&frac12;'),
    ('1/4', '&frac14;'),
    ('3/4', '&frac34;'),
]

for word in keep:
    subst.add_word(word, word)
    subst.add_word("\\"+word, word)
for key, value in repl:
    subst.add_word(key, value)


def process_expression(s):
    n = len(s)
    i = 0
    result = []
    while i < n:
        if s[i] == '}':
            i = i + 1
            break
        k, sk = process_part(s[i:])
        if k:
            result.append(sk)
            i = i + k

    return (i, ''.join(result))


def process_part(s):
    if len(s) == 0:
        return (0, "")

    c = s[0]
    if c == '{':
        l, s = process_expression(s[1:])
        return (l+1, s)
    elif c == '}':
        return (1, "")
    elif c == '_':
        l, s = process_part(s[1:])
        return (l+1, "<sub>" + s + "</sub>")
    elif c == '^':
        l, s = process_part(s[1:])
        return (l+1, "<sup>" + s + "</sup>")

    v = subst.longest_prefix(s)
    if v is not None:
        return v

    def consume(s, pred):
        n = len(s)
        i = 0
        while i < n:
            if not pred(s[i]): break
            i += 1

        if i:
            return (i, s[:i])
        else:
            return None

    v = consume(s, lambda c: c.isspace())
    if v is not None:
        return (v[0], "") # eat whitespaces

    v = consume(s, lambda c: c.isdigit())
    if v is not None:
        return v

    v = consume(s, lambda c: c.islower())
    if v is not None:
        return (v[0], "<i>" + v[1] + "</i>")

    return (1, s[0])


def simplemath(string):
    """
    Uses simple LaTeX-like syntax - supports subscript and superscripts,
    and does some additional replacements.  Small letters are italized.
    """
    return process_expression(string)[1]
