import gtk

class List(object):
	def __init__(self, count):
		self.count = count

	def __len__(self):
		return self.count

	def get_row(self, row):
		return None

	def get_item(self, row, col):
		print "get_data(%d, %d)" % (row, col)
		return "(%d, %d)" % (row, col)


import sqlite3 as sqlite

class SQLiteQueryList(List):
	def __init__(self, db, tablename, fields='*', where=None, fetch_count=256):
		self.L = []
		
		SQLquery = "SELECT %s FROM %s" % (fields, tablename)
		if where:
			SQLquery += " WHERE " + where

		count = db.execute("SELECT COUNT(*) FROM %s" % tablename).fetchone()[0]
		self.cursor = db.execute(SQLquery)
		self.fetch_count = fetch_count

		List.__init__(self, count)

	def get_row(self, row):
		try:
			return self.L[row]
		except IndexError:
			d = row - len(self.L) + 1
			d = (d + self.fetch_count - 1)/self.fetch_count
			print "fetching %d rows" % (d*self.fetch_count)
			self.L.extend(self.cursor.fetchmany(d*self.fetch_count))

			try:
				return self.L[row]
			except:
				print len(self.L), row
				raise

	def get_item(self, row, col):
		return self.get_row(row)[col]


class GridView(gtk.DrawingArea):
	def __init__(self, columns, data):
		gtk.DrawingArea.__init__(self)

		self.columns = columns
		self.data   = data
		self.h      = 24
		self.top    = 0
		self.height = len(data)*self.h
		self.width  = None

		self.do_layout()

		self.connect("expose_event", self.on_expose)
		self.gc = None

	def do_layout(self):
		self.width = sum(item[0] for item in columns)
		self.set_size_request(self.width, self.height)

	def set_width(self, column, newwidth):
		item = self.columns[column]
		if item[0] != newwidth:
			print "here"
			self.columns[column] = (newwidth, item[1])
			self.queue_draw()
		
	def on_expose(self, window, event):
		a = event.area
		f = a[1]/self.h
		k = a[3]/self.h
		print "expose", a, f, k
		y = f*self.h
		for i in xrange(f, f+k+1):
			x = 0
			for j, (w, renderer) in enumerate(self.columns):
				r = gtk.gdk.Rectangle(x, y, w, self.h)
				background_area = r
				cell_area = r
				expose_area = cell_area
				renderer.set_property("text", self.data.get_item(i, j))
				renderer.render(
					self.window,
					self,
					background_area,
					cell_area,
					expose_area,
					gtk.CELL_RENDERER_PRELIT
				)
				x += w

			y += self.h

		if self.gc is None:
			gc = self.get_style().bg_gc[gtk.STATE_NORMAL]
			self.gc = gtk.gdk.GC(self.window)
			self.gc.copy(gc)
			self.gc.set_rgb_fg_color(gtk.gdk.Color(255*256,0,255*256))


class Header(gtk.Fixed):
	def __init__(self, grid_view = None):
		gtk.Fixed.__init__(self)
		self.grid_view = grid_view
		self.columns = []
		self.height = 24
		self.highlight = [None, 0, None]
		self.dragging = False
		self.drag_dist = 10
		self.last_x = None
		self.gc = None

		self.drag_cursor = gtk.gdk.Cursor(gtk.gdk.SB_H_DOUBLE_ARROW)


	def do_layout(self):
		y = 0
		x = 0
		for label in self.columns:
			w, _ = label.get_size_request()
			self.move(label, x, y)
			x += w
	
	def set_column_width(self, index, width):
		self.columns[index].set_size_request(width, self.height)

	def get_right_edge(self, column_index):
		return self.get_left_edge(column_index) + self.columns[column_index].allocation[2]

	def get_left_edge(self, column_index):
		"returns x positon of left column"
		if column_index < 0:
			return 0


		s = sum(column.allocation.width for column in self.columns[:column_index])
		print column_index, s

		return s

	def add_column(self, title, width):
		e = gtk.Button(title)
		e.set_size_request(width, self.height)
		e.index = len(self.columns)
		self.columns.append(e)
		self.put(e, 0, 0)
		
		e.add_events(gtk.gdk.POINTER_MOTION_MASK)
		e.connect("event", self.event)

	def __column_edge(self, widget, event):
		if event.x <= self.drag_dist:
			return -1
		elif widget.allocation.width - event.x <= self.drag_dist:
			return +1
		else:
			return 0

	def set_highlighted(self, button, edge):
		if self.highlight[0] != button:
			if self.highlight[1] != 0:
				self.highlight[0].window.set_cursor(None)

			self.highlight[0] = button
			if edge:
				button.window.set_cursor(self.drag_cursor)
			else:
				button.window.set_cursor(None)

		elif edge != self.highlight[1]:
			self.highlight[1] = edge
			if edge:
				button.window.set_cursor(self.drag_cursor)
			else:
				button.window.set_cursor(None)
		pass
	
	def event(self, button, event):
		if self.dragging:
			if event.type == gtk.gdk.MOTION_NOTIFY:
				button = self.highlight[0]
				x = int(event.x)
				button.set_size_request(x, self.height)
				self.do_layout()
				try:
					self.on_dragging(self.highlight[0], self.highlight[2] + x)
				finally:
					return True
			elif event.type == gtk.gdk.BUTTON_RELEASE:
				try:
					self.on_end_drag(self.highlight[0], None)
				finally:
					self.dragging = False
					return True

			elif event.type == gtk.gdk.ENTER_NOTIFY or event.type == gtk.gdk.LEAVE_NOTIFY:
				return True
		else:
			if event.type == gtk.gdk.MOTION_NOTIFY:
				e = self.__column_edge(button, event)
				self.set_highlighted(button, e)
			elif event.type == gtk.gdk.BUTTON_PRESS and event.button == 1:
				if self.highlight[1] == +1:
					self.highlight[2] = self.get_left_edge(button.index)
					self.dragging = True
					try:
						self.on_start_drag(self.highlight[0], self.highlight[2] + int(event.x))
					finally:
						return True

	def on_start_drag(self, button, x):
		self.last_x == None
		self.draw_line(x)
		pass

	def on_dragging(self, button, x):
		self.draw_line(x)
		selg
		pass
	
	def on_end_drag(self, button, x):
		try:
			self.grid_view.set_width(button.index, button.allocation.width)
		except:
			import traceback
			traceback.print_exc()
		
		self.draw_line(-100)
		self.last_x = None
		pass

	def draw_line(self, x):
		if not self.grid_view:
			return

		window = self.grid_view.window
		if self.gc is None:
			self.gc = gtk.gdk.GC(window)
			self.gc.copy(self.grid_view.gc)
			self.gc.set_function(gtk.gdk.XOR)
			self.gc.line_width = 3

		y = 1000
		print self.last_x, x
		if self.last_x is not None:
			window.draw_line(self.gc, self.last_x, 0, self.last_x, y)

		window.draw_line(self.gc, x, 0, x, y)
		self.last_x = x


if __name__ == '__main__':

	H = Header()
	
	c = sqlite.connect('test')
	r = c.execute("SELECT * FROM files")
	columns = []
	for item in r.description:
		renderer = gtk.CellRendererText()
		columns.append(
			(150, renderer)
		)

		H.add_column(item[0], 150)
	
	H.do_layout()
	r.close()
	
#	l = List(1000000)
	l = SQLiteQueryList(c, 'files', fetch_count=64)
	v = GridView(columns, l)
	H.grid_view = v

	sw = gtk.ScrolledWindow()
	sw.set_shadow_type(gtk.SHADOW_ETCHED_IN)
	sw.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
	sw.set_size_request(640,300)
	sw.add_with_viewport(v)
	
	sw2 = gtk.ScrolledWindow()
	sw2.set_shadow_type(gtk.SHADOW_ETCHED_IN)
	sw2.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
	sw2.set_size_request(640,300)
	sw2.add_with_viewport(H)


	def print_cell_renderer(*args):
		for w, r in columns:
			print r.get_size(v)

	b1 = gtk.Button("")
	b1.connect("clicked", print_cell_renderer)
	
	d = gtk.Dialog()
	d.vbox.pack_start(sw2, expand=False, fill=False)
	d.vbox.pack_start(sw)
	d.vbox.pack_start(b1, expand=False, fill=False)
	d.show_all()

	# run	
	d.run()
	print "rows fetched: %d of %d" % (len(l.L), l.count)

# vim: ts=4 sw=4
