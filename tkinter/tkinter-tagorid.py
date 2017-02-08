# wm, 13.11.2006

from Tkinter import *

def comm_b1():
	canv.itemconfigure('red && !triangle', fill='white')

def comm_b2():
	canv.itemconfigure('square || circle', fill='white')

def comm_b3():
	canv.itemconfigure('blue && square', fill='white')

root = Tk()
canv = Canvas(root)
b1   = Button(root, text="red && !triangle", command=comm_b1)
b2   = Button(root, text="square || circle", command=comm_b2)
b3   = Button(root, text="blue && square",   command=comm_b3)
canv.pack()
b1.pack(side=LEFT)
b2.pack(side=LEFT)
b3.pack(side=LEFT)

from random import random, randint
for i in xrange(30):
	x = randint(0, 200)
	y = randint(0, 200)
	k = randint(0, 2)
	if k == 0:
		if random() > 0.5:
			tags = ('square', 'red')
			fill = 'red'
		else:
			tags = ('square', 'blue')
			fill = 'blue'

		canv.create_rectangle(x, y, x+20, y+20, tags=tags, fill=fill)
	elif k == 1:
		if random() > 0.5:
			tags = ('circle', 'red')
			fill = 'red'
		else:
			tags = ('circle', 'blue')
			fill = 'blue'

		canv.create_oval(x-10, y-10, x+10, y+10, tags=tags, fill=fill)
	elif k == 2:
		if random() > 0.5:
			tags = ('triangle', 'red')
			fill = 'red'
		else:
			tags = ('triangle', 'blue')
			fill = 'blue'
		canv.create_polygon(x-10, y, x+10, y, x, y+8.6, tags=tags, fill=fill)
		
root.mainloop()
