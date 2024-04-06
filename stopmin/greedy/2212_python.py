import sys
N = int(sys.stdin.readline().rstrip())
K = int(sys.stdin.readline().rstrip())
X = sorted(list(map(int,sys.stdin.readline().rstrip().split())))

if K >= N:
    print(0)
    sys.exit()

dist = []
for i in range(1,N):
    dist.append(X[i]-X[i-1])

dist.sort(reverse=True)
for _ in range(K-1):
    dist.pop(0)
print(sum(dist))