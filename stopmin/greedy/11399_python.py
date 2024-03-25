import sys
num = int(sys.stdin.readline())
time = list(map(int,sys.stdin.readline().rstrip().split()))
time = sorted(time)
ans = 0
for i in range(num):
    ans += time[i]*(num-i)
print(ans)