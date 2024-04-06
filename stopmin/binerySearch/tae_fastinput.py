# 1. 빠른 입력 받기
import sys 
N = int(sys.stdin.readline().rstrip())
array = list(map(int, sys.stdin.readline().rstrip().split()))

# 2. 이진 탐색을 통해 고정점 찾기 => 이진탐색 : O(logN)
def find_fixed(start,end):
    if start > end:
        return 0
    mid = (start + end) // 2
    
    if mid == array[mid] : 
        return mid
    elif array[mid] < mid :
        find_fixed(mid+1,end)
    else : 
        find_fixed(start,mid-1)

print(find_fixed(0,N-1) if find_fixed(0,N-1) else -1) 
