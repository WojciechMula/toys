import gtk
import gtk.gdk as gdk
import gobject

class Fixed(gtk.Container):
	def __init__(self):
		gtk.Container.__init__(self)
		self._children = []
		self._changed  = False

	def max_xy(self):
		X = 0
		Y = 0
		for x, y, child in self._children:
			w, h = child.size_request()
			X = max(X, x+w)
			Y = max(Y, y+h)

		return X, Y

	def put(self, x, y, widget):
		widget.set_parent(self)
		self._children.append((x, y, widget))
		self._changed = True

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
    
	def do_unrealize(self):
		self.window.set_user_data(None)

	def do_size_allocate(self, allocation):
#		print 'allocate###', allocation
		self.allocation = allocation

		if self.flags() & gtk.REALIZED:
			self.window.move_resize(*allocation)

		for x, y, child in self._children:
			w, h = child.size_request()
			child.size_allocate(gdk.Rectangle(x, y, w, h))

	def do_size_request(self, requisition):
		if self._changed:
			print "####request", requisition.width, requisition.height
			X, Y = self.max_xy()
			requisition.width = X
			requisition.height = Y
			self._changed = False

	def do_forall(self, internal, callback, data):
		for _, _, child in self._children:
			callback(child, data)		


gobject.type_register(Fixed)

if __name__ == '__main__':

	F = Fixed()
	F.put(50, 50, gtk.Button("Button 1"))
	F.put(150, 90, gtk.Button("Button 2"))

	def foo(widget):
		print "fooo"
		#F.do_size_allocate(F.allocation)

	b = gtk.Button("Click!")
	b.connect("clicked", foo)

	hbox = gtk.HBox()
	hbox.pack_start(gtk.Button("Unused"))
	hbox.pack_start(F, expand=True, fill=True)
	hbox.pack_start(b, expand=False, fill=False)
	
	d = gtk.Dialog()
	d.vbox.pack_start(hbox)
	d.vbox.pack_start(gtk.Button("Test"))
	d.show_all()

	# run	
	d.run()

# vim: ts=4 sw=4
