N = int(input())
length = list(map(int,input().split()))
gas = list(map(int,input().split()))

min_gas = 0
before = gas[0]
for i in range(N-1):
    if gas[i]>before:
        min_gas += length[i]*before
    else:
        min_gas += length[i]*gas[i]
    before = min(before,gas[i])
print(min_gas)