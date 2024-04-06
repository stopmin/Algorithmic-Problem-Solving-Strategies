from itertools import combinations
import sys
for _ in range(int(sys.stdin.readline())):
    dot = []
    tmp = 0
    for _ in range(4):
        dot.append(list(map(int,sys.stdin.readline().rstrip().split())))
    ans = list(combinations(dot,2))
    cnt = list()
    for i in ans:
        cnt.append((i[0][0]-i[1][0])**2 + (i[0][1]-i[1][1])**2)
    if len(set(cnt)) == 2:
        print(1)
    else:
        print(0)