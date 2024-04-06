import sys
li = sys.stdin.readline().rstrip().split('-')
for i in range(len(li)):
    li[i] = sum(list(map(int,li[i].split('+'))))
ans = li[0]*2
for w in li:
    ans -= w
print(ans)