max = int(input())
N = int(input())
ans = 0
for i in range(N):
    A,B = map(int,input().split())
    ans += A*B

if ans == max:
    print("Yes")
else:
    print("No")