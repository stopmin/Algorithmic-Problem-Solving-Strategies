import sys
K, N = map(int,sys.stdin.readline().split())
string = list()
for _ in range(K):
    string.append(int(sys.stdin.readline().rstrip()))

ans = sum(string)//N

while True:
    tmp = 0
    for i in range(K):
        tmp += string[i]//ans
    if tmp == N:
        break
    else: 
        ans -= 1

print(ans)