import sys
N, M = map(int,sys.stdin.readline().rstrip().split())

pocketmon = list(sys.stdin.readline().rstrip() for _ in range(N))

for _ in range(M):
    x = sys.stdin.readline().rstrip()
    if str.isdigit(x):
        print(pocketmon[int(x)-1])
    else:
        print(pocketmon.index(x)+1)
        