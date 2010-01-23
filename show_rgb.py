import gtk
import gobject

class CellColorRenderer(gtk.GenericCellRenderer):

	red   = gobject.property(type=int, default=0)
	green = gobject.property(type=int, default=0)
	blue  = gobject.property(type=int, default=0)

	def __init__(self):
		gtk.GenericCellRenderer.__init__(self)
		self.gc = None

	def on_get_size(self, widget, cell_area):
		return (0, 0, 24*2, 24)

	def on_render(self, window, widget, background_area, cell_area, expose_area, flags):
		if self.gc is None:
			self.gc = gtk.gdk.GC(window)

		# fill
		color = gtk.gdk.Color(red=self.red*256, green=self.green*256, blue=self.blue*256)
		self.gc.set_rgb_fg_color(color)
		window.draw_rectangle(self.gc, True, cell_area[0], cell_area[1], cell_area[2], cell_area[3]);

		# draw outline
		self.gc.set_rgb_fg_color(gtk.gdk.Color())
		window.draw_rectangle(self.gc, False, cell_area[0], cell_area[1], cell_area[2], cell_area[3]);

	def on_activate(self, event, widget, path, background_area, cell_area, flags):
		pass

	def on_start_editing(self, event, widget, path, background_area, cell_area, flags):
		pass


class CellHexColorRenderer(gtk.CellRendererText):
	red   = gobject.property(type=int, default=0)
	green = gobject.property(type=int, default=0)
	blue  = gobject.property(type=int, default=0)

	def __init__(self):
		gtk.CellRendererText.__init__(self)

	def do_render(self, *args):
		self.set_property('text', "#%02x%02x%02x" % (self.red, self.green, self.blue))
		gtk.CellRendererText.do_render(self, *args)

class GUI:
	pass


class MainWindow(object):
	def __init__(self, rgb_path):
		def parse_rgb(iterable):
			result = []
			for line in iterable:
				line = line.strip()
				if not line or line[0] == '!':
					continue # skip empty line and lines starting with '!'

				# each line has format:
				# red green blue name
				# where r, g, b are numbers, name is a string
				fields = line.split()
				if len(fields) < 4:
					continue

				yield (int(fields[0]), int(fields[1]), int(fields[2]), ' '.join(fields[3:]))
			pass

		colors = list(parse_rgb(open(rgb_path, 'rt')))
		self.__create_gui(rgb_path, colors)
		
		pass

	def run(self):
		self.gui.root.show()
		while True:
			try:
				gtk.main()
				return
			except KeyboardInterrupt:
				print "Ctrl-C detected, bye!"
				return
			except:
				import traceback
				traceback.print_exc()
				return

	def on_root_delete(self, window, event):
		gtk.main_quit()

	def __create_gui(self, rgb_path, colors):
		gui = GUI()
		
		gui.root = gtk.Window(gtk.WINDOW_TOPLEVEL)
		gui.root.resize(640, 480)
		gui.root.set_title("%s: %d color(s)" % (rgb_path, len(colors)))

		gui.root.connect("delete_event", self.on_root_delete)

		# columns: red, green, blue, name
		ls = gtk.ListStore(int, int, int, str)
		for item in colors:
			ls.append(item)

		gui.tree = gtk.TreeView()
		gui.tree.set_model(ls)

		# five columns
		# 1 - color: composition of three components!
		renderer = CellColorRenderer()
		column = gtk.TreeViewColumn('Preview', renderer, red=0, green=1, blue=2)
		gui.tree.append_column(column)
		
		# 2 - hex view: rendered from three components!
		renderer = CellHexColorRenderer()
		column = gtk.TreeViewColumn('Hex', renderer, red=0, green=1, blue=2)
		gui.tree.append_column(column)

		# 3,4,5,6 - default view, as text
		for i, name in enumerate(['Red', 'Green', 'Blue', 'Color name']):
			renderer = gtk.CellRendererText()
			column = gtk.TreeViewColumn(name, renderer, text=i)
			gui.tree.append_column(column)


		sw = gtk.ScrolledWindow()
		sw.set_shadow_type(gtk.SHADOW_ETCHED_IN)
		sw.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
		sw.add(gui.tree)

		gui.root.add(sw)
		gui.root.show_all()

		self.gui = gui

if __name__ == '__main__':
	import sys
	import os

	filename = '/etc/X11/rgb.txt'
	if len(sys.argv) > 1:
		filename = sys.argv[1]

	if not os.path.exists(filename):
		sys.stderr.write("File '%s' does not exists" % filename)
		sys.exit(1)

	main = MainWindow(filename)
	main.run()

