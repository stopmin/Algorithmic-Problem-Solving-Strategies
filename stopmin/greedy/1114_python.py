import sys
document = sys.stdin.readline().rstrip()
find = sys.stdin.readline().rstrip()
ans = 0
while True:
    tmp = document.find(find)
    if  tmp == -1:
        break
    document = document[:tmp] + '0'*len(find) +document[tmp+len(find):]
    ans += 1
print(ans)