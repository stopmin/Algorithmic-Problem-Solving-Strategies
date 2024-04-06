import sys
num = int(sys.stdin.readline())
region = list(map(int,sys.stdin.readline().split()))
money = int(sys.stdin.readline())

region = sorted(region)
start, end = 1, region[-1]

while start <= end:
    mid = (start + end) // 2
    cnt = 0
    for w in region:
        if w >= mid:
            cnt += mid
        else: 
            cnt += w
    if cnt <= money:
        start = mid + 1
    else:
        end = mid - 1
print(end)