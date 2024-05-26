import json
from sys import stdin

x = ''
for line in stdin:
    x += line

data = json.loads(x)

idx = 1
for user in data:
    print(user['id'] + '\t' + user['password'])

# print(data)
