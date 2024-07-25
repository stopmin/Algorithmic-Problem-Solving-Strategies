def solution(targets):
    answer = 0

    targets.sort(key=lambda x:[x[1], x[0]])

    print(targets)
    s = e = 0

    for target in targets:
        if target[0] >= e:
            answer+=1
            print(target)
            e = target[1]

    return answer