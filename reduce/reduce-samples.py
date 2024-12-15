# wm, 14.03.2007

def groupby(seq, value=lambda x: x):
	def aux((vp, L), curr):
		vc = value(curr)
		if vp == vc:
			L[-1].append(curr)
		else:
			L.append([curr])
		return (vc, L)
	
	return reduce(aux, seq, (aux, []))[1]


def groupby2(seq, value=lambda x: x):
	def aux((vp, L), curr):
		vc = value(curr)
		if vp == vc:
			L[-1][1].append(curr)
		else:
			L.append( (vc, [curr]) )
		return (vc, L)
	
	return reduce(aux, seq, (aux, []))[1]


def groupby3(seq, cmpfun=lambda x, y: x == y):
	def aux((prev, L), curr):
		if cmpfun(prev, curr):
			L[-1].append(curr)
		else:
			L.append([curr])
		return (curr, L)
	
	return reduce(aux, seq, (aux, []) )[1]


def flatten(seq):
	def aux(L, Li):
		L.extend(Li)
		return L
	return reduce(aux, seq, [])


def partition(seq, pred=bool):
	def aux((L1, L2), item):
		if pred(item):
			L1.append(item)
		else:
			L2.append(item)
		return (L1, L2)

	return reduce(aux, seq, ([], []))


def unzip2(seq):
	def aux((L1, L2), (x1, x2)):
		L1.append(x1)
		L2.append(x2)
		return (L1, L2)

	return reduce(aux, seq, ([], []))
