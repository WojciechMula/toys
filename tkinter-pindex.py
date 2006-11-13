# wm, 12.11.2006

from Tkinter import *
from random  import randint

def motion(event):
	i      = canv.index(poly, "@%f,%f" % (event.x, event.y))
	xi, yi = points[i], points[i+1]
	canv.itemconfig(point, state='normal')

	r = 4
	canv.coords(point, xi-r, yi-r, xi+r, yi+r)

if __name__ == '__main__':
	root = Tk()
	canv = Canvas(root)
	canv.pack()

	n      = 10
	points = [randint(10, 190) for i in xrange(2*n)]
	poly   = canv.create_line(*points)
	point  = canv.create_oval(0,0,0,0, state='hidden', fill='white')

	canv.bind('<Motion>', motion)
	root.mainloop()
