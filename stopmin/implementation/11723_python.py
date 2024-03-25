import sys
ans = set()

for _ in range(int(input())):
    rule = sys.stdin.readline().rstrip().split()
    if len(rule) == 1:
        if rule[0] == 'empty':
            ans = set()
        else:
            ans = {'1','2','3','4','5','6','7','8','9','10','11','12','13','14','15','16','17','18','19','20'}
    else:
        if rule[0] == 'add':
            ans.add(rule[1])
        elif rule[0] == 'remove':
            ans.discard(rule[1])
        elif rule[0] == 'check':
            if rule[1] in ans:
                print(1)
            else:
                print(0)
        else:
            if rule[1] in ans:
                ans.discard(rule[1])
            else:
                ans.add(rule[1])