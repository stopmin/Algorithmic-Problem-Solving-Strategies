import sys
N, M = map(int,sys.stdin.readline().rstrip().split())
trees = list(map(int,sys.stdin.readline().rstrip().split()))

start, end = 1,max(trees)

while start <= end:
    mid = (start + end) // 2
    tree = 0
    for w in trees:
        if w>mid:
            tree += (w-mid) 
        if tree > M:
            break                   #절단된 나무를 추가하는 중에 이미 M을 넘어버린 경우 중단한다.
    if tree >= M:
        start = mid + 1
    else:
        end = mid - 1

print(end)