import gtk

class MaskedEntry(gtk.Entry):
	def __init__(self):
		gtk.Entry.__init__(self)
		self.pattern = None
		self.cur = None
		self.curmap = None
		self.set_overwrite_mode(True)
		self.connect("key_press_event", self.__on_key_press)

	def __move_cursor(self, delta):
		return self.__set_cursor(self.cur + delta)


	def __set_cursor(self, pos):
		if pos < 0:
			return False

		try:
			index = self.set_position(self.curmap[pos])
			self.cur = pos
			return True
		except IndexError:
			return False


	def __repl_char(self, index, c):
		self.insert_text(c, index)
		self.delete_text(index+1, index+2)

	
	def __on_key_press(self, widget, event):
		c = event.string
		k = event.keyval
		if len(c) == 1:
			try:
				index = self.curmap[self.cur]
				if c in self.pattern[index][2]:
					self.__repl_char(index, c)
					self.__move_cursor(+1)
			except IndexError:
				pass
		elif k == gtk.keysyms.Left:
			self.__move_cursor(-1)
		elif k == gtk.keysyms.Right:
			self.__move_cursor(+1)
		elif k == gtk.keysyms.Delete:
			try:
				index = self.curmap[self.cur]
				item  = self.pattern[index]
				if item[0] is not None:
					self.__repl_char(index, item[1])
					self.__move_cursor(+1)
			except IndexError:
				pass
		elif k == gtk.keysyms.BackSpace:
			if self.__move_cursor(-1):
				try:
					index = self.curmap[self.cur]
					item  = self.pattern[index]
					if item[0] is not None:
						self.__repl_char(index, item[1])
				except IndexError:
					pass
		elif k == gtk.keysyms.Home:
			self.__set_cursor(0)
		elif k == gtk.keysyms.End:
			self.__set_cursor(len(self.curmap)-1)
				
		return True


	def set_mask(self, *args):
		self.pattern = []
		self.curmap = []

		text = ""
		empty = set()
		for item in args:
			if type(item) is str:
				for c in item:
					self.pattern.append((None, c, empty))

				text += item
			else:
				n = len(item)
				if n == 2:	# no group name
					item = ('__default__',) + item
				elif n == 3:
					pass
				else:
					raise ValueError("Invalid tuple '%s'" % item)

				self.pattern.append(item)
				self.curmap.append(len(text))
				text += item[1]

		self.cur  = 0
		self.set_property('text', text)
		self.__set_cursor(0)

	def get_group_names(self):
		def unique(L):
			L1 = []
			s = set()
			for x in L:
				if x not in s:
					L1.append(x)
					s.add(x)

			return L1

		return unique((item[0] for item in self.pattern if item[0] is not None))
	
	def get_groups(self):
		d = {}
		text = self.get_text()
		for i, (group, defchar, allowed_set) in enumerate(self.pattern):
			if group is None:
				continue

			if group not in d:
				d[group] = ""

			d[group] += text[i]
			
		return d

	def get_group(self, group):
		try:
			return self.get_groups()[group]
		except KeyError:
			raise KeyError("No such group '%s'" % group)
	
	def set_group(self, _group, string):
		it = iter(string)
		for i, (group, defchar, allowed_set) in enumerate(self.pattern):
			if group == _group:
				try:
					c = it.next()
					if c not in allowed_set:
						c = defchar
				except StopIteration:
					c = defchar

				self.__repl_char(i, c)
		pass

if __name__ == '__main__':
	m = MaskedEntry()
	m.set_size_request(500, -1)

	Y = ('year',	'_', set("1234567890"))
	M = ('month',	'_', set("1234567890"))
	D = ('day',		'_', set("1234567890"))

	m.set_mask("Year: ", Y, Y, Y, Y, " month: ", M, M, " and day: ", D, D, " rest of text")
	print m.get_group_names()

	def print_groups(*args):
		for k, v in m.get_groups().iteritems():
			print "%s =>'%s'" % (k, v)
	
	b1 = gtk.Button("_Get groups")
	b1.connect("clicked", print_groups)
	
	def set_groups(*args):
		m.set_group('year', '1981')
		m.set_group('month', '05')
		m.set_group('day', '12')
	
	b2 = gtk.Button("_Set groups (1981-05-12)")
	b2.connect("clicked", set_groups)


	d = gtk.Dialog()
	d.vbox.pack_start(m)
	d.vbox.pack_start(b1)
	d.vbox.pack_start(b2)
	d.show_all()

	# run	
	d.run()

# vim: ts=4 sw=4
