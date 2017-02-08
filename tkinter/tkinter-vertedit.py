# wm, 1.12.2006

from Tkinter import *

def motion(event):
	try:
		index = canvas.index('line', "@%f,%f" % (event.x, event.y))
		x, y  = canvas.coords('line')[index:index+2]
		r     = 3
		canvas.coords('point', x-r, y-r, x+r, y+r)
	except ValueError:
		# line is "empty"
		pass

def insert_pt(event):
	index = canvas.index('line', "@%f,%f" % (event.x, event.y))
	canvas.insert('line', index, (event.x, event.y))

def append_pt(event):
	canvas.insert('line', 'end', (event.x, event.y))

def replace_pt(event):
	index = canvas.index('line', "@%f,%f" % (event.x, event.y))
	canvas.insert('line', index, (event.x, event.y))
	canvas.dchars('line', index+2)
	canvas.event_generate('<Motion>', x=event.x, y=event.y)

def delete_pt(event):
	index = canvas.index('line', "@%f,%f" % (event.x, event.y))
	canvas.dchars('line', index)
	canvas.event_generate('<Motion>', x=event.x, y=event.y)

def deleol_pt(event):
	index = canvas.index('line', "@%f,%f" % (event.x, event.y))
	canvas.dchars('line', index, 'end')
	canvas.event_generate('<Motion>', x=event.x, y=event.y)

root   = Tk()
canvas = Canvas(root, bg='white')

canvas.create_line(100, 100, 120, 100, fill='blue', tag='line')
canvas.create_oval(-10, -10, -5, -5, tag='point', fill='white')

canvas.bind('<Motion>',			motion)
canvas.bind('<Button-1>',		insert_pt)
canvas.bind('<Control-Button-1>',	append_pt)
canvas.bind('<Shift-Button-1>',		replace_pt)
canvas.bind('<Button-3>',		delete_pt)
canvas.bind('<Control-Button-3>',	deleol_pt)

canvas.pack(fill=BOTH, expand=1)

root.mainloop()
