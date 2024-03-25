for _ in range(int(input())):
    A, B = map(int,input().split())
    step = 1
    distance = B - A - 1
    ans = 1 # 제일 처음 위치에 무조건 한 칸 와야하니깐 1로 표시
    canWalk = {step}
    #print(distance)
    while(distance):
        if (distance - step - step - 1 >= 0): # 더 멀리 갈 수 있다면 가도 된다.
            distance = distance - step - step - 1
            step += 1 
            ans += 2
            canWalk.add(step)
            #print("더 멀리!")
        elif (distance - step > 0): 
            # step = step
            ans += 1
            distance -= step
            #print('잉 그대로')
        elif (distance in canWalk):
            ans += 1
            #print('그 안에서')
            distance = 0
        #print(distance)
        #print(distance)
        #print(canWalk)
        #print("***")
    print(ans)