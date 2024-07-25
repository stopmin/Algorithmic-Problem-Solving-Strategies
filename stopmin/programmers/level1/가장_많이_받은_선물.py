def solution(friends, gifts):
    answer = 0
    gift_count = [ [0]*len(friends) for _ in range(len(friends))]
    # gift_count[x][y]: x -> y에게 주다.
    # 곧, x의 전체 합을 구하면 줬던 횟수를 모두 계산할 수 있음ㅇㅇ 받았던 횟수는 gift_count[][x]로 조회 가능!

    for gift in gifts:
        a,b = gift.split()
        gift_count[friends.index(a)][friends.index(b)] += 1

    for i in range(len(friends),0,-1):
        gift = 0
        for j in range(len(friends),0,-1):
            if(friends[i-1]==friends[j-1]):
                continue
            if gift_count[i-1][j-1] - gift_count[j-1][i-1] > 0:
                gift += 1
            elif gift_count[i-1][j-1] == gift_count[j-1][i-1]:
                if calculate_rate(gift_count, i-1) > calculate_rate(gift_count, j-1):
                    gift += 1


        if gift > answer:
            answer = gift

    return answer

def calculate_rate(gift_count, x):
    plus = sum(gift_count[x])
    minus = 0
    for i in range(len(gift_count)):
        minus += gift_count[i][x]
    return plus - minus
