x = []
y = []
for _ in range(3):
    a, b = map(int,input().split())
    x.append(a)
    y.append(b)

for i in x:
    if x.count(i) == 1:
        print(i,end=" ")
for j in y:
    if y.count(j) == 1:
        print(j)