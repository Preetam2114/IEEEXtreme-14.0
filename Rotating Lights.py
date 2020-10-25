import sys
from collections import deque

n, t = list(map(int,sys.stdin.readline().strip().split()))
pos = list(map(int,sys.stdin.readline().strip().split()))
lights = ''.join([str(1) if i in pos else str(0) for i in range(t)])
positions = [lights]
count = 0
for _ in range(t):
	shift = lights[-1]
	lights = shift + lights[:-1]
	if lights not in positions:
		positions.append(lights)
		count += 1
print(count)