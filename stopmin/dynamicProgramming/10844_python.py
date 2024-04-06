import sys
input = sys.stdin.readline

n = int(sys.stdin.readline())

stairs = [[0]*10 for _ in range(n+1)]
stairs[1] = [0,1,1,1,1,1,1,1,1,1]

for i in range(2,n+1):
    stairs[i][0] = stairs[i-1][1]
    stairs[i][9] = stairs[i-1][8]
    for j in range(1,9):
        stairs[i][j] = stairs[i-1][j-1] + stairs[i-1][j+1]
print(sum(stairs[n])%1000000000)