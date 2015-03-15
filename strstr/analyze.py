
classes = [
	'slower',
	'same speed',
	'2.00 - 2.99 faster',
	'3.00 - 3.99 faster',
	'4.00 - 4.99 faster',
	'5.00 - 5.99 faster',
	'6.00 - ...  faster',
]

def update(dict, field):
	def classify(value):
		if value < 0.0:
			return classes[0]
		if value == 1.0:
			return classes[1]
		if 2.0 <= value < 3.0:
			return classes[2]
		if 3.0 <= value < 4.0:
			return classes[3]
		if 4.0 <= value < 5.0:
			return classes[4]
		if 5.0 <= value < 6.0:
			return classes[5]
		if 6.0 <= value:
			return classes[6]

	if field == 'speed':
		value = 1.0
	elif field == 'inf':
		value = 1e6; # close enough :)
	else:
		value = float(field)

	name = classify(value)
	dict[name] = dict.get(name, 0) + 1;


def load(file):
	cpp = {}
	c   = {}

	for lines in file:
		fields = lines.split()

		if fields[1].endswith('libc:'):
			update(c,   fields[-1])

		if fields[1].endswith('c++:'):
			update(cpp, fields[-1])



	return cpp, c


def print_summary(dict, width = 50):
	n = max(map(len, classes))
	total = sum(dict.values())

	def print_class(cls):
		if cls in dict:
			count = dict[cls]
			perc  = count/float(total)
			bar  = '=' * max(1, int(perc * width))
			print '%*s: %5d  (%5.2f%%) %s' % (n, cls, count, 100.0 * perc, bar)
		else:
			print '%*s: N/A' % (n, cls)

	for cls in classes:
		print_class(cls);


if __name__ == '__main__':
	import sys
	cpp, c = load(sys.stdin);

	print

	print("custom vs std::string::find")
	print('-' * 76)
	print_summary(cpp)

	print

	print("custom vs strlen")
	print('-' * 76)
	print_summary(c)
