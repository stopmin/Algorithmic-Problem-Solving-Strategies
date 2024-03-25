import sys
input = sys.stdin.readline

N = int(input())
length = list(map(int,input().split())) #거리          
pay = list(map(int,input().split())) #가격

ans = 0
before = pay[0]
for i in range(N-1):
    if length[i]*pay[i] >= length[i]*before:
        ans += length[i]*before
    else:
        ans += length[i]*pay[i]
    before = min(before,pay[i])
        
print(ans)