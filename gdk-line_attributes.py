# -*- coding: iso-8859-2 -*-
#
# PyGTK line attributes demo: join, bevel and capjoin styles, and also dashes
# 
# Author: Wojciech Muła
# e-mail: wojciech_mula@poczta.onet.pl
# www:    http://0x80.pl/
#
# Initial version: 2010-01-20
#
# License: public domain

import gtk

class GUI:
	pass

def str2int_def(s, default):
	try:
		return int(s)
	except ValueError:
		return default

class MainWindow(object):
	def __init__(self, points):
		X = [x for (x, y) in points]
		Y = [y for (x, y) in points]
		minx = min(X)
		miny = min(Y)
		maxx = max(X)
		maxy = max(Y)

		self.orig_points    = [(x-minx, y-minx) for (x, y) in points]
		self.points = self.orig_points[:]
		self.points_bb = (maxx-minx, maxy-miny)
		self.gc = None
		self.__create_gui()
	
	def run(self):
		self.gui.root.show()
		while True:
			try:
				gtk.main()
				return
			except KeyboardInterrupt:
				print "Ctrl-C detected, exiting"
				return
			except:
				import traceback
				traceback.print_exc()
				return
		pass

	def on_root_destroy(*args):
		gtk.main_quit()

	def on_drawing_size_allocate(self, widget, allocation):
		w1, h1 = allocation.width, allocation.height
		w, h   = self.points_bb
			
		shift = 40
		if self.gc:
			shift  = min(shift, shift/2 + self.gc.line_width)

		sx = float(w)/(w1 - 4*shift)
		sy = float(h)/(h1 - 4*shift)
		s  = 1.0/max(sx, sy)
		self.points = []
		for (x, y) in self.orig_points:
			pt = (int(shift + x*s), int(shift + y*s))
			self.points.append(pt)
		pass
	
	def on_drawing_expose_event(self, window, event):
		wnd = self.gui.drawing.window
		wnd.draw_lines(self.gc, self.points)

		if self.gui.draw_line.get_active():
			wnd.draw_lines(self.gc2, self.points)
				
		return True


	def on_line_attribute_change(self, *args):
		gui = self.gui
		self.gc.set_line_attributes(
			str2int_def(gui.line_width.get_text(), self.gc.line_width),
			getattr(gtk.gdk, gui.line_style.get_active_text()),
			getattr(gtk.gdk, gui.cap_style.get_active_text()),
			getattr(gtk.gdk, gui.join_style.get_active_text()),
		)
		
		self.gui.drawing.queue_draw()


	def on_dashes_change(self, *args):
		gui = self.gui
		try:
			do = int(gui.dash_offset.get_text())
		except ValueError:
			return

		try:
			tmp = gui.dash_list.get_text().replace(",", " ").split()
			dl = map(int, tmp)
		except ValueError:
			return

		self.gc.set_dashes(do, dl)
		self.gui.drawing.queue_draw()
	

	def on_draw_line_change(self, *args):
		self.gui.drawing.queue_draw()


	def __create_gui(self):
		gui = GUI

		gui.root = gtk.Window(gtk.WINDOW_TOPLEVEL)
		gui.root.resize(800, 600)
		gui.root.set_title("PyGTK demo - line styles")
		gui.root.connect("destroy", self.on_root_destroy)

		gui.drawing = gtk.DrawingArea()
		gui.drawing.set_size_request(*self.points_bb)
		gui.drawing.connect("expose_event", self.on_drawing_expose_event)
		gui.drawing.connect("size_allocate", self.on_drawing_size_allocate)

		def cb_from_const(name_prefix):
			cb = gtk.combo_box_new_text()
			for name in (name for name in dir(gtk.gdk) if name.startswith(name_prefix)):
				cb.append_text(name)
			else:
				cb.set_active(0)

			return cb

		gui.line_style	= cb_from_const("LINE_")
		gui.cap_style	= cb_from_const("CAP_")
		gui.join_style	= cb_from_const("JOIN_")
		gui.line_width	= gtk.Entry()
		gui.dash_offset	= gtk.Entry()
		gui.dash_list	= gtk.Entry()

		for item in [gui.line_width, gui.line_style, gui.cap_style, gui.join_style]:
			item.connect("changed", self.on_line_attribute_change)

		for item in [gui.dash_offset, gui.dash_list]:
			item.connect("changed", self.on_dashes_change)

		gui.draw_line	= gtk.CheckButton("Draw thick line")
		gui.draw_line.connect("clicked", self.on_draw_line_change)

		vbox = gtk.VBox()
		hbox = gtk.HBox()
		items = [
			"Line style",	gui.line_style,
			"Cap style",	gui.cap_style,
			"Join style",	gui.join_style,
			"Line width",	gui.line_width,
			"Dash offset",	gui.dash_offset,
			"Dash list",	gui.dash_list,
			gui.draw_line
		]

		for item in items:
			if type(item) is str:
				item = gtk.Label(item)
			vbox.pack_start(item, fill=True, expand=False)

		#
		hbox.pack_start(vbox, fill=True, expand=False)
		hbox.pack_end(gui.drawing, fill=True, expand=True)

		gui.root.add(hbox)
		gui.root.show_all()
		
		wnd = gui.drawing.window
		
		style = gui.drawing.get_style()
		self.gc = gtk.gdk.GC(wnd)
		self.gc2 = gtk.gdk.GC(wnd)
		self.gc.copy(style.fg_gc[gtk.STATE_NORMAL])
		self.gc2 = gtk.gdk.GC(wnd)
		self.gc2.set_rgb_fg_color(gtk.gdk.color_parse("red"));

		self.gui = gui


if __name__ == '__main__':
	import sys

	points = [(50, 50), (300, 100), (150, 400), (300, 300)]
	if len(sys.argv) > 1:
		points = []
		for i in xrange(1, len(sys.argv), 2):
			x = int(sys.argv[i])
			y = int(sys.argv[i+1])
			points.append((x, y))

	main = MainWindow(points)
	main.run()

# eof
