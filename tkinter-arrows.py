# wm, 6.11.2006

from Tkinter import *

root = Tk()
canv = Canvas(root, background='white')
canv.pack(fill=BOTH, expand=1)

dy = 20
y  = dy
for j in [0, 15]:
	for i in xrange(5, 30, 5):
		canv.create_line(10, y, 10+200, y,
		     arrow=BOTH, arrowshape=(i, j, 8))
		y += dy

while True:
	try:
		root.mainloop()
		break
	except KeyboardInterrupt:
		pass
	
