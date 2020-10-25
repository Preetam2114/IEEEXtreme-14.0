import re
import sys
from collections import OrderedDict

# Read Data
stop_words = sys.stdin.readline().strip().split(';')
stop_words = [word.lower() for word in stop_words]
index_words = sys.stdin.readline().strip().split(';')
response = list(sys.stdin.readlines())

# Process
cleaned_text = ' '.join([data.strip() for data in response])
special_tags = ['<title>','<abstract>','<body>']
weights = {'<title>':5, '<abstract>':3, '<body>':1}
scores = {}
for word in index_words:
	scores[word] = 0

total_l = 0
for tag in special_tags:
	tagend = '</'+tag[1:]
	start = re.search(tag, cleaned_text).end()
	end = re.search(tagend, cleaned_text).start()
	data = cleaned_text[start:end].strip().split()
	cdata = []
	for i,word in enumerate(data):
		cleaned = re.sub('<[^<]+?>', '', word)
		cleaned = cleaned.lower()
		if cleaned not in stop_words:
			cleaned = re.sub(r'[^\w\s]', '', cleaned)
			if len(cleaned) >= 4:
				cdata.append(cleaned)
	l = len(cdata)
	total_l += l
	count = 0
	for word in index_words:
		scores[word] += cdata.count(word)*weights[tag]

for tag in scores:
	scores[tag] = scores[tag]/total_l*100

densities = list(set(scores.values()))
densities = sorted(densities,reverse=True)
densities = densities[:3]
top3 = {}
for density in densities:
	top3[density] = []
for name,score in scores.items():
	if score >= densities[-1]:
		top3[score].append(name)


top3 = OrderedDict(sorted(top3.items(), reverse=True)) 
for score in top3.items():
	for word in score[1]:
		print(f'{word}: %.9f'%score[0])