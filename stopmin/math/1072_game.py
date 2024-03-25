

def Z(X,Y):
    return (Y*100)//X

# X,Y가 주어졌을 때, 형택이가 게임을 최소 몇 번 더 해야 Z가 변하는지 구하는 프로그램을 작성하여라.
X, Y = map(int,input().split())
initial = Z(X,Y)
# X: 게임 횟수 Y: 이긴 게임(Z%) 형택이의 승률
if initial >= 99: print(-1); exit()

start = 1
end = X
mid = (start+end)//2

while(start < end):
    if Z(X+mid,Y+mid) == initial: 
        start = mid + 1
    else:
        end = mid
    mid = (start+end)//2
print(mid)