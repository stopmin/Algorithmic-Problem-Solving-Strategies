import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T) :
    n = int(input())
    cloth_dict = {}
    for _ in range(n) :
        cloth = list(input().split())
        if cloth[1] in cloth_dict :
            cloth_dict[cloth[1]].append(cloth[0])
        else :
            cloth_dict[cloth[1]] = [cloth[0]]

    result = 1
    for i in cloth_dict : ## cloth_dict.keys()와 같다
        result *= len(cloth_dict[i]) + 1

    print(result - 1)