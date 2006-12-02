# wm, 6.11.2006

from Tkinter import *

def set(*ignored):
	canv.itemconfig(line, arrowshape=(d1.get(), d2.get(), d3.get()))

root  = Tk()
frame = Frame(root)
d1    = IntVar()
d2    = IntVar()
d3    = IntVar()
d1.trace_variable('w', set)
d2.trace_variable('w', set)
d3.trace_variable('w', set)

m     = 50
sd1   = Scale(frame, from_=-m, to=m, orient=HORIZONTAL, variable=d1)
sd2   = Scale(frame, from_=-m, to=m, orient=HORIZONTAL, variable=d2)
sd3   = Scale(frame, from_=0,  to=m, orient=HORIZONTAL, variable=d3)
sd1.pack(fill=X)
sd2.pack(fill=X)
sd3.pack(fill=X)


canv  = Canvas(root, background='white')
canv .pack(side=LEFT, fill=BOTH)
frame.pack(side=RIGHT, fill=X)

line = canv.create_line(m, 2.5*m, m+200, 2.5*m, arrow=BOTH)

d1.set(3)
d2.set(8)
d3.set(10)
root.mainloop()
