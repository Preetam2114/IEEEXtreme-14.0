import sys

def genstones(n,states):
	state = list(range(1,n+1))
	num_states = n
	spells = 0
	stones = {}
	flag = False
	while True:
		state = [states[i-1] for i in state]
		state = list(set(state))
		l = len(state)
		spells += 1
		if l>= num_states:
			flag=True
			break
		num_states = l
		stones[l] = spells
	return stones

n = list(map(int,sys.stdin.readline().strip().split()))[0]
states = list(map(int,sys.stdin.readline().strip().split()))
q = list(map(int,sys.stdin.readline().strip().split()))[0]
stones = genstones(n,states)
print(stones)
for _ in range(q):
	k = list(map(int,sys.stdin.readline().strip().split()))[0]
	try:
		print(stones[k])
	except KeyError:
		print(-1)