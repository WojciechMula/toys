# wm, 30.11.2006

from Tkinter import *

BIT_SHIFT	= 0x001
BIT_CAPSLOCK	= 0x002
BIT_CONTROL	= 0x004
BIT_LEFT_ALT	= 0x008
BIT_NUMLOCK	= 0x010
BIT_RIGHT_ALT	= 0x080
BIT_MB_1	= 0x100
BIT_MB_2	= 0x200
BIT_MB_3	= 0x400

descripton = [
	(BIT_CAPSLOCK,	'CapsLock'),
	(BIT_NUMLOCK,	'NumLock'),
	(BIT_SHIFT,	'Shift'),
	(BIT_CONTROL,	'Ctrl'),
	(BIT_LEFT_ALT,	'AltL'),
	(BIT_RIGHT_ALT,	'AltR'),
	(BIT_MB_1,	'B1'),
	(BIT_MB_2,	'B2'),
	(BIT_MB_3,	'B3'),
]

from sys import stdout
def e(event):
	s = []
	for bit, dsc in descripton:
		if bit & event.state:
			s.append(dsc)
		else:
			s.append(' '*len(dsc))

	print "%s\r" % ' '.join(s),
	stdout.flush()

root = Tk()
root.bind('<Motion>', e)
root.mainloop()
