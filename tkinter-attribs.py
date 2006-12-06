from Tkinter import *
from random  import randint, random

def tag_lower(self):
	try:
		item = canv.find_withtag('current')[0]
		canv.tag_lower(item, 'all')
		print canv.itemcget(item, 'outline')
	except IndexError:
		pass

def tag_raise(self):
	try:
		item = canv.find_withtag('current')[0]
		canv.tag_raise(item, 'all')
	except IndexError:
		pass

root = Tk()
canv =  Canvas(root)
canv.bind('<1>', tag_raise)
canv.bind('<3>', tag_lower)
canv.pack()
for i in xrange(50):
	x = randint(0, 200)
	y = randint(0, 200)
	w = randint(2, 4)*12
	
	if random() > 0.8:
		state = 'disabled'
	else:
		state = 'normal'

	canv.create_rectangle(x, y, x+w, y+w, state=state, 
		outline         = 'black',
		activeoutline   = 'red',
		disabledoutline = 'blue',
		dash		= ".-",
		activewidth     = 3,

		fill		= '#ddd',
		activefill	= '#fff',
		disabledfill	= '#999',
	)

root.mainloop()
