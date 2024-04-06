import sys
for _ in range(int(sys.stdin.readline().rstrip())):
    cases_num = int(sys.stdin.readline().rstrip())
    clothes_type = list()
    clothes = list()
    cnt = []
    for _ in range(cases_num):
        name, type = sys.stdin.readline().rstrip().split()
        clothes.append(name)
        if type in clothes_type:
            cnt[clothes_type.index(type)] += 1
        else:
            clothes_type.append(type)
            cnt.append(0)
    ans = 1
    for w in cnt:
        ans = ans * (w+2)
    print(ans-1)