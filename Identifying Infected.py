import sys
from collections import defaultdict

class Graph:
	def __init__(self, vertices):
		self.vertices = vertices
		self.graph = defaultdict(list)

	def add_edge(self, a,b):
		self.graph[a].append(b)
		self.graph[b].append(a)

	def print_graph(self):
		print(self.graph)

	def find_infections(self, source, destination, path=[]):
		graph = self.graph 
		path = path + [source]
		if source == destination:
			return [path]
		if source not in graph:
			return []
		paths = []
		for vertex in graph[source]:
			if vertex not in path:
				extended_paths = self.find_infections(vertex, destination, path)
				for p in extended_paths: 
					paths.append(p)
		return paths


n,m = list(map(int,sys.stdin.readline().strip().split()))
mygraph = Graph(n)
while m:
	a,b = list(map(int,sys.stdin.readline().strip().split()))
	mygraph.add_edge(a,b)
	m -= 1 
q = list(map(int,sys.stdin.readline().strip().split()))[0]
while q:
	f,s = list(map(int,sys.stdin.readline().strip().split()))
	infections = mygraph.find_infections(f,s)
	visited = {}
	for i in range(1,n+1):
		visited[str(i)] = 0
	for infection in infections:
		for node in infection:
			visited[str(node)] += 1
			
	visited = sorted(visited.items(), reverse=True, key=lambda x: x[1])
	count = 0
	maxc = visited[0][1]
	for vertex in visited:
		if vertex[1] == maxc:
			count += 1
	print(count)
	q -= 1
