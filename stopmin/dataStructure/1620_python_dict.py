import sys
N, M = map(int,sys.stdin.readline().rstrip().split())

pocketmon = {}
for i in range(N):
    pocketmon[i+1] = sys.stdin.readline().rstrip()
pocketmon_reversed = {v:k for k,v in pocketmon.items()}

for _ in range(M):
    x = sys.stdin.readline().rstrip()
    if x.isdigit():
        print(pocketmon[int(x)])
    else:
        print(pocketmon_reversed[x])
        