import math
zero = str(math.factorial(int(input())))
cnt = 0
for i in reversed(zero):
    if i == '0':
        cnt += 1
    else:
        print(cnt)
        break