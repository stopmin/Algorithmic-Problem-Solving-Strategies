import sys

X, Y, W, S = map(int,sys.stdin.readline().rstrip().split())

X, Y = max(X,Y), min(X,Y)

def path(X,Y,W,S):
    ans = min((X+Y)*W,S*X)
    return ans

if X == Y:
    print(path(X,Y,W,S))


else:
    if (X-Y)%2 == 0:
        tmp = min((X-Y)*W,S*(X-Y))
        print(path(Y,Y,W,S)+tmp)
    else:
        tmp = min((X-Y)*W,S*(X-Y-1)+W)
        print(path(Y,Y,W,S)+tmp)