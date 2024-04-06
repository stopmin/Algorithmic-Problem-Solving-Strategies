N,W,H = map(int,input().split())


long = (W**2+H**2)**(1/2)

for _ in range(N):
    tmp = int(input())
    if tmp<=long:
        print('DA')
    else:
        print('NE')