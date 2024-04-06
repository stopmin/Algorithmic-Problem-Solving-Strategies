import math
for _ in range(int(input())):
    start, end = map(int,input().split())
    print(math.comb(end,start))