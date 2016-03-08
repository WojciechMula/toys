# -*- coding: iso-8859-2 -*-
# $Date: 2009-03-02 21:05:04 $, $Revision: 1.4 $
#
# TreeModel that encapsulates any python sequence of other seqences of same size
# 
# Author: Wojciech Muła
# e-mail: wojciech_mula@poczta.onet.pl
# www:    http://0x80.pl/
#
# Initial release: 2010-01-24
#
# License: public domain

import gtk

class PythonListModel(gtk.GenericTreeModel):
	"TreeModel that encapsulates any python sequence of other seqences of same size"

	def __init__(self, L, types=None):
		"""
		L - list of rows
		types -  list of types of row, for example [int, str, bool, int]
		         if types is None, then this list is derived from first
				 row of sequence
		"""
		self.L = L
		if types is None:
			if len(L) == 0:
				raise ValueError("If arg. types is None, then sequece must not be empty")

			row = L[0]
			if isinstance(row, (list, tuple)):
				self.__types = tuple(type(item) for item in row)
			else:
				self.__types = (type(row),)
		else:
			self.__types = tuple(types)
		
		gtk.GenericTreeModel.__init__(self)
	
	def on_get_flags(self):
		return gtk.TREE_MODEL_LIST_ONLY | gtk.TREE_MODEL_ITERS_PERSIST

	def on_get_n_columns(self):
		return len(self.__types)

	def on_get_column_type(self, index):
		return self.__types[index]

	def on_get_iter(self, path):
		return path[0]

	def on_get_path(self, rowref):
		return self.L[rowref]

	def on_get_value(self, rowref, column):
		return self.L[rowref][column]

	def on_iter_next(self, rowref):
		index = rowref + 1
		if index < len(self.L):
			return index
		else:
			return None

	def on_iter_children(self, parent):
		if parent is None:
			return 0
		else:
			return None

	def on_iter_has_child(self, rowref):
		return False

	def on_iter_n_children(self, rowref):
		if iter is None:
			return len(self.L)
		else:
			return 0

	def on_iter_nth_child(self, parent, n):
		if parent is None and n >= 0 and n < len(self.L):
			return n
		else:
			return None

	def on_iter_parent(self, child):
		return None

	pass


if __name__ == '__main__':
	# prepare data
	s = ["kot", "pies", "drzewo"]
	L = []
	for i in xrange(64):
		L.append((i, s[i % len(s)], True))

	p = PythonListModel(L)

	# prepare view
	d = gtk.Dialog()
	l = gtk.TreeView()
	l.set_model(p)

	for i, title in enumerate(['index', 'string', 'bool']):
		r = gtk.CellRendererText()
		c = gtk.TreeViewColumn(title, r, text=i)
		l.append_column(c)
	
	sw = gtk.ScrolledWindow()
	sw.set_shadow_type(gtk.SHADOW_ETCHED_IN)
	sw.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
	sw.set_size_request(640,300)
	sw.add(l)

	d.vbox.pack_start(sw)
	d.show_all()

	# run	
	d.run()

# vim: ts=4 sw=4 nowrap noexpandtab
