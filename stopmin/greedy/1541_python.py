import sys

calculate = sys.stdin.readline().rstrip()
calculator = list()
for i in calculate:
    if i == '+':
        calculator.append(1)
    elif i == '-':
        calculator.append(-1)
calculate = calculate.split('+')
for i in range(len(calculate)):
    calculate[i] = calculate[i].split('-')
calculate = list(map(int,sum(calculate,[])))

for i in range(len(calculator)):
    if i+1 != len(calculator):
        if calculator[i] == -1 and calculator[i+1] == 1:
            calculator[i+1] = -1

ans = calculate[0]

for w in range(len(calculator)):
    ans += calculator[w]*calculate[w+1]
print(ans)

#---------------------------------------
result, num = 0, ''
minus = False
for n in input() +' ':
    if n.isdigit(): num += n
    else:
        if minus: result -= int(num)
        else: result += int(num)
        if n == '-': minus = True
        num = ''
print(result)

#----------------------------------------
ls = input().split('-')
sum = 0
minus = 0

for a in ls[0].split('+'):
    sum += int(a)

for i in ls[1:]:
    for j in i.split('+'):
        minus += int(j)

print(sum - minus)