
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

	value = float(field)
	
	name = classify(value)
	dict[name] = dict.get(name, 0) + 1;


def load(filename):
	cpp = {}
	c   = {}

	for lines in open(filename):
		fields = lines.split()
		if fields[0] != 'custom:':
			continue
		
		update(cpp, fields[5])
		update(c,   fields[9])

	return cpp, c


def print_summary(dict, width = 50):
	n = max(map(len, classes))
	s = sum(dict.values())

	for cls in classes:
		k    = dict[cls]
		perc = k/float(s)
		bar  = '=' * max(1, int(perc * width))
		print '%*s: %5d  (%5.2f%%) %s' % (n, cls, k, 100.0 * perc, bar)


if __name__ == '__main__':
	cpp, c = load('demo');

	print

	print("custom vs std::string::find")
	print('-' * 76)
	print_summary(cpp)

	print

	print("custom vs strlen")
	print('-' * 76)
	print_summary(c)
