import sys
card = int(sys.stdin.readline())
two = 2

if card == 1 or card == 2: print(card);exit()
else:
    while True:
        if card>two*2: two*=2
        else: break  
print((card-two)*2)

#2 2 2-1 * 2
#3 2 3-2 * 2
#4 4 4-2 * 2
#5 2 5-4 * 2
#6 4 6-4 * 2
#7 6 7-4 * 2
#8 8 8-4 * 2
#9 2 9-8 * 2
#10 4
#11 6