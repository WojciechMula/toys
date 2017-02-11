import gtk
import gtk.gdk as gdk
import gobject

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
		count = 100
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


class DrawGrid(gtk.DrawingArea):
	def __init__(self, columns, data):
		gtk.DrawingArea.__init__(self)

		self.__draw_hlines	= False
		self.__draw_vlines	= False

		self.columns = columns
		self.data   = data
		self.h      = 24
		self.top    = 0
		self.height = len(data)*self.h
		self.width  = None

		self.top_pix	= 0
		self.left_pix	= 0

		self.do_layout()

		self.gc = None

	def set_enable_grid_lines(self, val):
		pass
		
	def get_enable_grid_lines(self):
		return self.__enable

	def do_layout(self):
		self.width = sum(item[0] for item in columns)

	def set_width(self, column, newwidth):
		item = self.columns[column]
		if item[0] != newwidth:
			print "here"
			self.columns[column] = (newwidth, item[1])
			self.queue_draw()

	def set_h_scroll(self, x):
		if self.left_pix != x:
			self.left_pix = x
			self.queue_draw()
	
	def set_v_scroll(self, y):
		self.top_pix = y
		self.queue_draw()

	def draw_area(self, row_start, row_end):
		y = - (self.top_pix % self.h)
		for i in xrange(row_start, row_end+1):
			x = -self.left_pix
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

	def draw_grid(self):
		wnd = self.window
		y   = - (self.top_pix % self.h)
		w   = self.allocation.width
		h   = self.allocation.height
		while y <= w:
			wnd.draw_line(self.gc, 0, y, w, y)
			y += self.h

		x = -self.left_pix
		for width, renderer in self.columns:
			wnd.draw_line(self.gc, x, 0, x, h)
			x += width

	def do_realize(self):
		gtk.DrawingArea.do_realize(self)
		gc = self.get_style().bg_gc[gtk.STATE_NORMAL]

		
		self.gc = gtk.gdk.GC(self.window)
		self.gc.copy(gc)
		self.gc.set_rgb_fg_color(gtk.gdk.Color(0xffff, 0xffff, 0xffff))

	def do_expose_event(self, event):
		t = self.top_pix / self.h
		b = (self.top_pix + self.allocation.height) / self.h
		print t, b, b-t+1
		self.draw_grid()
		self.draw_area(t, b)


gobject.type_register(DrawGrid)


class Header(gtk.Container):
	def __init__(self, grid_view = None):
		gtk.Container.__init__(self)
		self.grid_view = grid_view
		self.columns = []
		self.height = 45
		self.highlight = [None, 0, None, 0]
		self.dragging = False
		self.drag_dist = 10
		self.last_x = None
		self.gc = None
		self._changed = False
		self.total_width = 0
		self.x_scroll	= 0

		self.drag_cursor = gtk.gdk.Cursor(gtk.gdk.SB_H_DOUBLE_ARROW)

	def _do_layout(self):
		y = 0
		x = - self.x_scroll
		h = self.height
		for w, button in self.columns:
			R = gdk.Rectangle(x, y, w, h)
			button.size_allocate(R)
			x += w

		self.total_width = x

	def set_scroll(self, x):
		if x != self.x_scroll:
			self.x_scroll = x
			self._do_layout()
	
	def set_column_width(self, index, width):
		self.columns[index] = (width, self.columns[index][1])

	def get_right_edge(self, column_index):
		return self.get_left_edge(column_index) + self.columns[column_index][0]

	def get_left_edge(self, column_index):
		"returns x positon of left column"
		if column_index < 0:
			return 0

		return sum(width for width, _ in self.columns[:column_index])

	def add_column(self, title, width):
		b = gtk.Button(title)
		b.size_request()
		b.set_parent(self)
		b.index = len(self.columns)
		self.columns.append((width, b))
		self._changed = True
		
		b.add_events(gtk.gdk.POINTER_MOTION_MASK)
		b.connect("event", self.event)

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
				self._do_layout()
				try:
					self.on_dragging(self.highlight[0], self.highlight[2] + x)
				finally:
					return True
			elif event.type == gtk.gdk.BUTTON_RELEASE:
				try:
					self.on_end_drag(self.highlight[0], True)
				finally:
					self.dragging = False
					return True

			elif event.type == gtk.gdk.ENTER_NOTIFY or event.type == gtk.gdk.LEAVE_NOTIFY:
				return True

			elif event.type == gdk.KEY_PRESS:
				try:
					if event.keyval == gtk.keysyms.Escape:
						self.dragging = False
						self.on_end_drag(self.highlight[0], False)
				finally:
					return True
		else:
			if event.type == gtk.gdk.MOTION_NOTIFY:
				e = self.__column_edge(button, event)
				self.set_highlighted(button, e)
			elif event.type == gtk.gdk.BUTTON_PRESS and event.button == 1:
				if self.highlight[1] == +1:
					self.highlight[2] = self.get_left_edge(button.index)
					self.highlight[3] = self.columns[button.index][0]
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
		try:
			self.draw_line(x)
			self.set_column_width(button.index, x - button.allocation.x)
			self._do_layout()
		except:
			import traceback
			traceback.print_exc()
	
	def on_end_drag(self, button, accepted):
		if accepted:
			try:
				self.grid_view.set_width(button.index, button.allocation.width)
			except:
				import traceback
				traceback.print_exc()
		else:
			self.set_column_width(button.index, self.highlight[3])
			self._do_layout()
		
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


	def do_realize(self):
		# The do_realize method is responsible for creating GDK (windowing system)
		# resources. In this example we will create a new gdk.Window which we
		# then draw on
		
		# First set an internal flag telling that we're realized
		self.set_flags(gtk.REALIZED)
		
		# Create a new gdk.Window which we can draw on.
		# Also say that we want to receive exposure events by setting
		# the event_mask
		self.window = gdk.Window(
			self.get_parent_window(),
			width=self.allocation.width,
			height=self.allocation.height,
			window_type=gdk.WINDOW_CHILD,
			wclass=gdk.INPUT_OUTPUT,
			event_mask=self.get_events() | gdk.EXPOSURE_MASK | gdk.BUTTON_PRESS_MASK)
		
		# Associate the gdk.Window with ourselves, Gtk+ needs a reference
		# between the widget and the gdk window
		self.window.set_user_data(self)
		
		# Attach the style to the gdk.Window, a style contains colors and
		# GC contextes used for drawing
		self.style.attach(self.window)
		
		# The default color of the background should be what
		# the style (theme engine) tells us.
		self.style.set_background(self.window, gtk.STATE_NORMAL)
		self.window.move_resize(*self.allocation)

	def do_size_allocate(self, allocation):
		print "####allocation", allocation
		self.allocation = allocation
		if self.flags() & gtk.REALIZED:
			self.window.move_resize(*allocation)

		self._do_layout()
	
	def do_size_request(self, requisition):
		if self._changed:
			print "####request", requisition.width, requisition.height
			requisition.width = self.get_right_edge(-1)
			requisition.height = self.height
			self._changed = False

	def do_forall(self, internal, callback, data):
		#print internal, callback, data
		for w, button in self.columns:
			callback(button, data)		


gobject.type_register(Header)

class HeaderView(gtk.VBox):
	__gsignals__ = dict(set_scroll_adjustments=
                        (gobject.SIGNAL_RUN_LAST, None,
                         (gtk.Adjustment, gtk.Adjustment)))

	def __init__(self, header, gridview):
		gtk.VBox.__init__(self)
		self.header = header
		self.gridview = gridview
		self.hadjustment = None
		self.vadjustment = None

		vbox = self

		vbox.pack_start(header, expand=False)
		vbox.pack_start(gridview, expand=True)

	def h_value_changed(self, adjustment):
		print "h=", adjustment.value
		s = int(adjustment.value)
		self.header.set_scroll(s)
		self.gridview.set_h_scroll(s)
		pass
	
	def v_value_changed(self, adjustment):
		print "v=", adjustment.value
		s = int(adjustment.value)
		self.gridview.set_v_scroll(s)
		pass

	def do_size_allocate(self, allocation):
		gtk.VBox.do_size_allocate(self, allocation)
		self.hadjustment.page_size = allocation.width
		self.vadjustment.page_size = self.gridview.allocation.height

	def do_set_scroll_adjustments(self, hadjustment, vadjustment):
		self.hadjustment = hadjustment
		self.vadjustment = vadjustment

		hadjustment.set_all(0, 0, self.gridview.width, 1, 10, self.allocation.width)
		vadjustment.set_all(0, 0, self.gridview.height, 1, 10, self.allocation.height)
		
		hadjustment.connect("value-changed", self.h_value_changed)
		vadjustment.connect("value-changed", self.v_value_changed)


HeaderView.set_set_scroll_adjustments_signal('set-scroll-adjustments')

if __name__ == '__main__':

	H = Header()
	
	c = sqlite.connect('test')
	r = c.execute("SELECT * FROM files")
	columns = []
	for i, item in enumerate(r.description):
		renderer = gtk.CellRendererText()
		w = 150
		columns.append((w, renderer))

		H.add_column(item[0], w)
	
	#H.do_layout()
	r.close()
	
#	l = List(1000000)
	l = SQLiteQueryList(c, 'files', fetch_count=64)
	v = DrawGrid(columns, l)
	H.grid_view = v

	HV = HeaderView(H, v)

	sw = gtk.ScrolledWindow()
	sw.set_shadow_type(gtk.SHADOW_ETCHED_IN)
	sw.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
	sw.set_size_request(840, 400)

	sw.add(HV)
	
	def print_cell_renderer(*args):
		for w, r in columns:
			print r.get_size(v)

		print H.allocation

	b1 = gtk.Button("")
	b1.connect("clicked", print_cell_renderer)
	
	d = gtk.Dialog()
	d.vbox.pack_start(sw, expand=True, fill=True)
	d.vbox.pack_start(b1, expand=False, fill=False)
	d.show_all()

	# run	
	d.run()
	print "rows fetched: %d of %d" % (len(l.L), l.count)

# vim: ts=4 sw=4
