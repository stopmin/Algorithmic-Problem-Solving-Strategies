N, M = map(int,input().split())
arr = []
arr_min = []

for i in range(N):
    a = input()
    arr.append(a)

for i in range(N-7):
    for j in range(M-7):
        case1 = 0
        case2 = 0
        for a in range(i,i+8):
            for b in range(j,j+8):
                if (a+b)%2 == 0:
                    if arr[a][b] != 'W':
                        case1 += 1
                    else:
                        case2 += 1
                else:
                    if arr[a][b] != 'B':
                        case1 += 1
                    else:
                        case2 += 1
        arr_min.append(case1)
        arr_min.append(case2)

print(min(arr_min))


