def collect(files):
	result = {}

	for filename in files
		proc = None
		for line in open(filename, 'rt'):
			if line.startswith('...'):
				time = int(line.split()[3])
				result[proc].append(time)
			else:
				proc = line.strip()
				if proc not in d:
					result[proc] = []

	return result


def display(result):
	for proc in sorted(result):
		vals = result[proc]
		print '%-15s %10d %10.0f %10d' % (proc, min(vals), sum(vals)/len(vals), max(vals))


def main():
	import sys

	result = collect(sys.argv[1:])
	display(result)


if __name__ == '__main__':
	main()
