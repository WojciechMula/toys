#

import Tkinter
from Tkconstants import *

__all__ = ['ColorPicker']

HTMLcolors = [
"#000000", "#c0c0c0", "#808080", "#ffffff",
"#800000", "#ff0000", "#800080", "#ff00ff",
"#008000", "#00ff00", "#808000", "#ffff00",
"#000080", "#0000ff", "#008080", "#00ffff"
]

class ColorPicker(Tkinter.Frame):

	def __init__(self, width, height, *args, **kwargs):
		Tkinter.Frame.__init__(self, *args, **kwargs)
		self.canvas = Tkinter.Canvas(
			self,
			takefocus	= 0,
			width		= width,
			height		= height
		)
		self.canvas.bind('<Configure>', self.reshape)
		self.canvas.pack(fill=BOTH)

		self.width = 4	# highlight width
		self.canvas.tag_bind(ALL, '<Button-1>', self.select)
		self.items = [
			self.canvas.create_rectangle(
				0, 0,
				0, 0,
				fill	= HTMLcolors[i],
				outline	= 'lightgray',
				width	= self.width, 
			)
			for i in xrange(16)
		]
		self.color = None
		self.highlight_item(self.items[3])


	def highlight_item(self, item):
		color = self.canvas.itemcget(item, 'fill')
		if color == self.color:
			return
		self.canvas.itemconfigure(ALL,  outline=self.canvas['bg'])
		self.canvas.itemconfigure(item, outline='black')
		self.canvas.tag_raise(item, ALL)
		self.color = color
	
	def select(self, event):
		try:
			self.highlight_item( self.canvas.find_withtag(CURRENT)[0] )
		except IndexError:
			return

	def reshape(self, event):
		w, h   = event.width, event.height
		dw     = float(int((w-(self.width/2*5))/4))
		dh     = float(int((h-(self.width/2*5))/4))
		c      = 0
		coords = self.canvas.coords
		dx = dy = self.width
		for i in range(4):
			for j in range(4):
				coords(
					self.items[c],
					i*dw + dx,
					j*dh + dy,
					(i+1)*dw + dx,
					(j+1)*dh + dy
				)
				c += 1

# vim: ts=4 sw=4
