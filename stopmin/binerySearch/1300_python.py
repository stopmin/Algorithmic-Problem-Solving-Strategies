import sys
N = int(sys.stdin.readline().rstrip())
K = int(sys.stdin.readline().rstrip())

start = 1
end = N*N
while (start<=end):
    mid = (start+end)//2

    cnt = 0
    for i in range(1,N+1):
        cnt += min (mid//i,N)
    
    if cnt >= K:
        end = mid -1
    else:
        start = mid + 1
print(start)