import sys
import math
c,n,p,w = list(map(int,sys.stdin.readline().strip().split()))
w1 = w

pockets = []
t = 0
while w:
	if w > p:
		pockets.append(p)
		w -= p
	else:
		pockets.append(w)
		w = 0

flag = False
if c > w1:
	flag = True
	print(0)

m = len(pockets)
while not flag:
	if c in pockets:
		ind = pockets.index(c)
		pockets.pop(ind)
		t += 1
	else:
		mini = min(pockets)
		ind = pockets.index(mini)
		if mini < c:
			for i,pile in enumerate(pockets):
				indp = m
				if pile>=mini and i!=ind:
					indp = pockets.index(pile)
					break
			if indp == m:
				print(t)
				flag = True
				break
			pockets[indp] = p-(c-mini)
			pockets.pop(ind)
			t += 1
		else:
			if m < n:
				pockets[ind] -= c
				m += 1
				t += 1
			else:
				print(t)
				flag = True