import sys
from collections import Counter
M = int(sys.stdin.readline())
A = sys.stdin.readline().split()
N = int(sys.stdin.readline())
B = sys.stdin.readline().split()

C = Counter(A)
print(' '.join(f'{C[m]}' if m in C else '0' for m in B))

print(Counter(C))