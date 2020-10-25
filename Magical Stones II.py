import sys

def genstones(n,white,black):
	seq = ''
	l = 0
	if len(set(white)) != n:
		state = list(set(white))
		l = len(state)
		seq += 'W'
	elif len(set(black)) != n:
		state = list(set(black))
		l = len(state)
		seq += 'B'
	else:
		return 'impossible'
	states = []
	while True:
		#print(state)
		ws = list(set([white[i-1] for i in state]))
		bs = list(set([black[i-1] for i in state]))
		if len(ws) < len(bs):
			state = list(set(ws))
			l = len(state)
			seq += 'W'
		elif len(bs) < len(ws):
			state = list(set(bs))
			l = len(state)
			seq += 'B'
		else:
			if len(ws) <= l and ws not in states:
				state = list(set(ws))
				l = len(state)
				states.append(ws)
				seq += 'W'
			elif len(bs) <= l and bs not in states:
				state = list(set(bs))
				l = len(state)
				seq += 'B'
			else:
				break
	if len(state) != 1:
		return 'impossible'
	return seq

t = list(map(int,sys.stdin.readline().strip().split()))[0]
for _ in range(t):
	n = list(map(int,sys.stdin.readline().strip().split()))[0]
	white = list(map(int,sys.stdin.readline().strip().split()))
	black = list(map(int,sys.stdin.readline().strip().split()))
	stones = genstones(n,white,black)
	print(stones)