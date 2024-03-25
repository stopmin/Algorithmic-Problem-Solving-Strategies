import sys

input = sys.stdin.readline

A, B = map(int,input().split())
C = A//B
print(C)
print(A-C*B)