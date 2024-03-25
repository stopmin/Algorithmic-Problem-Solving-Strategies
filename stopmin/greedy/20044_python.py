import sys
n = int(sys.stdin.readline())
player = sorted(list(map(int,sys.stdin.readline().rstrip().split())))
reversed_player = player[::-1]
print(min(list(player[i]+reversed_player[i] for i in range(2*n))))