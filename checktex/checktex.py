#!/usr/local/bin/python
# -*- coding: iso-8859-2 -*-
#
# Wojciech Muła, 14.09.2004

import re
import sys

def checkTeX(filename):
	regexp  = re.compile(r"\\{|\\}|\\%|{|}|%")
	stack   = []
	linenum = 0
	file    = open(filename)

	for line in file:
		for match in regexp.finditer(line):
			if match.group() == '%':
				break
			elif match.group() == '{':
				stack.append( (linenum, match.start() ) )
			elif match.group() == '}':
				try:
					stack.pop()
				except IndexError:
					print "%s: extra closing bracket at line %d, column %d" % (filename, linenum+1, match.start()+1 )
					file.close()
					return
		linenum += 1

	for level, coords in enumerate(stack):
		line, column = coords
		print "%s: opened group -- level %d, line %d, column %d" % (filename, level, line+1, column+1)

	file.close()

if __name__ == '__main__':
	for file in sys.argv[1:]:
		try:
			checkTeX(file)
		except EnvironmentError:
			pass

# vim: ts=2 shiftwidth=2 nowrap
