import sys
import re
import subprocess

def main(paths):
	freq = {}
	instructions = load_instructions('instruction.txt')

	n = len(paths)
	try:
		for index, path in enumerate(paths):
			sys.stderr.write('%d/%d: %s\n' % (index+1, n, path))

			lines = disassemble(path)
			if lines is not None:
				update_freq(freq, lines, instructions)
	finally:
		print_freq(freq)


def disassemble(path):
	args = [
		'objdump',
		'-d',
		'--no-show-raw-insn',
		path
	]

	proc = subprocess.Popen(args, stdout=subprocess.PIPE)
	res  = proc.communicate()[0]
	if proc.wait() == 0:
		return res.splitlines()


def load_instructions(path):
	result = set()
	for line in open(path, 'rt'):
		line = line.strip()
		if not line or line[0] in ['#']:
			continue

		result.add(line.lower())

	return result


def update_freq(freq, lines, known_instructions):
	for line in lines:
		line   = line.strip()
		fields = line.split()

		if len(fields) == 0:
			continue

		if not re.match('^\d+:$', fields[0]):
			continue

		fields.pop(0)
		instruction = fields[0]
		if instruction in known_instructions:
			freq[instruction] = freq.get(instruction, 0) + 1
		else:
			sys.stderr.write("ERROR: unknown instruction '%s'\n" % instruction)
			sys.stderr.write(" line: " + line + "\n");

	return freq


def print_freq(freq):
	L = freq.items()
	L.sort(key=lambda k: k[1], reverse=True)

	total = sum(count for instruction, count in L)

	for instruction, count in L:
		print "%20s %10d %10.2f%%" % (instruction, count, (100.0*count)/total)



if __name__ == '__main__':
	if len(sys.argv) > 1:
		main(sys.argv[1:])
	else:
		sys.stderr.write("usage: %s list-of-paths\n" % sys.argv[0])
