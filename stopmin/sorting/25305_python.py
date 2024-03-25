import sys
input = sys.stdin.readline
A, B = map(int,input().split())
arr = list(map(int,input().split()))
arr.sort()
arr.reverse()
print(arr[B-1])