# wm, 6.12.2006

from Tkinter import *
from sys     import stdout
from random  import randint

def see(canvas, item):
	x1, y1, x2, y2 = canvas.bbox(item)
	cx = (x1+x2)/2
	cy = (y1+y2)/2

	xo = canvas.canvasx(0)
	yo = canvas.canvasy(0)
	w  = canvas.winfo_width()
	h  = canvas.winfo_height()
	
	canvas.scan_mark(int(cx), int(cy))
	canvas.scan_dragto(int(xo + w/2), int(yo + h/2), 1)

def center(event):
	canv.itemconfigure(ALL,  fill='blue')
	item = canv.find_withtag(CURRENT)[0]
	canv.itemconfigure(item, fill='green')
	see(canv, item)

dragging = False
def start_drag(event):
	global dragging
	canv.scan_mark(event.x, event.y)
	dragging = True

def stop_drag(event):
	global dragging
	dragging = False

def drag(event):
	if not dragging: return
	if event.state & 0x004:
		canv.scan_dragto(event.x, event.y, 2)
	else:
		canv.scan_dragto(event.x, event.y, 1)

root = Tk()
canv = Canvas(root, width=640, height=480)
canv.focus_set()
canv.pack(fill=BOTH, expand=1)

canv.bind('<ButtonPress-1>',	start_drag)
canv.bind('<ButtonRelease-1>',	stop_drag)
canv.bind('<Motion>',		drag)

canv.tag_bind(ALL, '<Button-1>', center)
n = 40
for i in xrange(n):
	x, y = randint(0, 640), randint(0, 480)
	w, h = randint(5, 20), randint(5, 20)
	canv.create_rectangle(x-w, y-h, x+w, y+h, fill='blue')

root.mainloop()
