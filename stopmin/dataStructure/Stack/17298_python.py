import sys
input = sys.stdin.readline
n = int(input())
arr = list(map(int,input().split()))
answer = [-1 for _ in range(n)]
stack = []

for i in range(n):
    while stack and arr[stack[-1]] < arr[i]:
        answer[stack.pop()] = arr[i]
    stack.append(i)

print(*answer)