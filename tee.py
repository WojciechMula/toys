if __name__ == '__main__':
	import sys

	def open(filename):
		try:
			return file(filename, 'wb')
		except:
			return None

	files = [sys.stdout]
	for filename in sys.argv[1:]:
		f = open(filename)
		if f:
			files.append(f)

	
	while True:
		data = sys.stdin.read(1024)
		if not data:
			break;

		for file in files:
			try:
				file.write(data)
			except:
				sys.stderr.write("write error to %s\n" % file.name)
		#for
	#while
		
