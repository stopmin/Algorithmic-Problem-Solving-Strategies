import sys
N, C = map(int,sys.stdin.readline().split())
house = [int(sys.stdin.readline()) for _ in range(N)]
house = sorted(house)

start = 1
end = house[-1] - house[0]
result = 0

while (start <= end):
    mid  = (start+end) // 2
    mile = house[0]
    count = 1
    for i in range(1,N):
        if house[i] >= mile + mid:
            mile = house[i]
            count += 1
    if count >= C:
        start = mid + 1
        result = mid
    else:
        end = mid - 1
print(result)