# -*- coding: iso-8859-2 -*-
#
# reST roles helpers
#
# Wojciech Muła, http://0x80.pl/
# Public domain
#
# $Date: 2007-03-26 19:56:15 $, $Revision: 1.7 $


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
	('=/=',	' &ne; '),
	('!=',	' &ne; '),
	('+/-',	' &plusmn; '),
	
	('<',	' &lt '),
	('>',	' &gt '),
	('<=',	' &le; '),
	('>=',	' &ge; '),
	
	('<->',	' &harr; '),
	('->',	' &rarr; '),
	('<-',	' &larr; '),

	('<=>',	' &hArr; '),
	('==>',	' &rArr; '),
	('<==',	' &lArr; '),

	('-',	   ' &minus; '),
	('*',	   ' &sdot; '),
	('\\cdot', ' &sdot; '),
	('+',      ' + '),
	('/',      '/'),
	(':=',     ' := '),
	('%',      ' mod '),
	
	(r'\in',	'&isin;'),
	(r'\notin',	'&notin;'),
	(r'\sqrt',	'&radic;'),
	(r'\div',	'&divide;'),
	(r'\approx', ' &approx; '),
	
	(';',	'; '),
	(',',	', '),
	('...',	'&hellip;'),
	('PI',  '&pi;'),
	('1/2',	'&frac12;'),
	('1/4',	'&frac14;'),
	('3/4',	'&frac34;'),
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



#=== Python code snippets ===============================================
import re

def py_getdef(filename, pattern, numbers=True):
	f = open(filename, 'r')
	lines = [(lineno+1, line.rstrip()) for (lineno, line) in enumerate(f)]

	for block in pattern.replace('\t',' ').split(' '):
		kind, name = block.split(':')
		lines = py_grep(lines, name.strip(), kind.strip())
	f.close()

	if numbers:
		return '\n'.join("%4d %s" % item for item in lines)
	else:
		return '\n'.join( (line for (lineno,line) in lines) )

def py_grep(list, name, type="def"):
	regexp = re.compile("^\s*%s\s+%s" % (type, name))

	for i, (lineno, line) in enumerate(list):
		if regexp.match(line):
			return py_getblock(list[i:])
	return []

def py_getblock(code):
	if len(code) == 0:
		return []

	def get_indention(line, expandtabs=True):
		"""Get line's indention"""
		l = len(line)
		if expandtabs:
			t = len(line.expandtabs().lstrip())
			return l-t
		else:
			t = len(line.lstrip())
			return l-t
	
	initial_indent = get_indention(code[0][1])
	result = [code[0]]
	for lineno, line in code[1:]:
		indent = get_indention(line)
		if line != '' and indent == initial_indent:
			break
		else:
			result.append( (lineno, line) )
	
	while len(result) and result[-1][1] == '':
		result.pop()
	
	return result


#print py_getdef('roles_aux.py', 'def:py_grep')
#print py_getdef('roles_aux.py', 'def:py_getblock def:get_indention')

# vim: ts=4 sw=4
