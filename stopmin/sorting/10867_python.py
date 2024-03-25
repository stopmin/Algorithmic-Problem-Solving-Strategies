import sys
input = sys.stdin.readline
num = int(input())
arr = set(list(map(int,input().split())))
arr = sorted(list(arr))
print(*arr)