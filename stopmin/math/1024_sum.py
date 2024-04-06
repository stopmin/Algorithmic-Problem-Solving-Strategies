N, L = map(int,input().split())
isAns = False
for i in range(L,N):
    if (N-i)%i == 0:
        isAns = True
        print(N,i)
print(isAns)