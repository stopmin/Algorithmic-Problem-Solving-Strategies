def solution(babbling):
    answer = 0
    array = babbling

    token = ["aya","ye","woo","ma"]

    for i in range(len(array)):
        truth = [False] * len(array[i]) 
        for j in range(len(token)):
            if token[j] in array[i]:
                for k in range(array[i].find(token[j]), array[i].find(token[j]) + len(token[j])):
                    truth[k] = True
        if len(set(truth)) == 1 and truth[0] == True: answer += 1

            
    return answer

