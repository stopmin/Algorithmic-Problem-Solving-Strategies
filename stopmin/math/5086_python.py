import sys
input = sys.stdin.readline

while True:
    A,B = map(int,input().split())
    if A == 0 and B == 0:
        break
    elif A%B == 0:
        print('multiple')
    elif B%A == 0:
        print('factor')
    else:
        print('neither')