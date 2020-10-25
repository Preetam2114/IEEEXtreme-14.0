'''
Contest     : IEEEXtreme
Team Name   : AlgoExperts
Question    : Magical Stones I
Created on  : Saturday, 24th October 2020 4:12:00 pm
'''


import sys

if 'PyPy' in sys.version:
    from _continuation import continulet
else:
    import threading


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

def main():
    n = list(map(int,sys.stdin.readline().strip().split()))[0]
    states = list(map(int,sys.stdin.readline().strip().split()))
    q = list(map(int,sys.stdin.readline().strip().split()))[0]
    stones = genstones(n,states)
    for _ in range(q):
        k = list(map(int,sys.stdin.readline().strip().split()))[0]
        try:
            print(stones[k])
        except KeyError:
            print(-1)


if __name__ == '__main__':
    if 'PyPy' in sys.version:

        def bootstrap(cont):
            call, arg = cont.switch()
            while True:
                call, arg = cont.switch(to=continulet(lambda _, f, args: f(*args), call, arg))

        cont = continulet(bootstrap)
        cont.switch()

        main()

    else:
        sys.setrecursionlimit(1 << 30)
        threading.stack_size(1 << 27)

        main_thread = threading.Thread(target=main)
        main_thread.start()
        main_thread.join()
