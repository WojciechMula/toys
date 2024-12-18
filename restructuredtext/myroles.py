from roles_aux import wikilink, simplemath, py_getdef
from docutils.parsers.rst.roles import set_classes, nodes, register_canonical_role

def plwiki_link_role(role, rawtext, text, lineno, inliner, options={}, content=[]):
	set_classes(options)
	ref, text = wikilink(text, 'pl')
	return [nodes.reference(rawtext, nodes.unescape(text), refuri=ref, **options)], []

def enwiki_link_role(role, rawtext, text, lineno, inliner, options={}, content=[]):
	set_classes(options)
	ref, text = wikilink(text, 'en')
	return [nodes.reference(rawtext, nodes.unescape(text), refuri=ref, **options)], []

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


register_canonical_role('math',   inlinemath_role)
register_canonical_role('cmath',  centermath_role)
register_canonical_role('plwiki', plwiki_link_role)
register_canonical_role('enwiki', enwiki_link_role)
