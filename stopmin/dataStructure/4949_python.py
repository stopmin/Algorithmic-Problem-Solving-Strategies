import sys
while True:
    string = sys.stdin.readline().rstrip()
    if string == '.':
        break
    chaos = []
    temp = True
    for i in string:
        if i == '(' or i == '[':
            chaos.append(i)
        elif i == ')':
            if not chaos or chaos[-1] == '[':
                temp = False
                break
            elif chaos[-1] == '(':
                chaos.pop()
        elif i == ']':
            if not chaos or chaos[-1] == '(':
                temp = False
                break
            elif chaos[-1] == '[':
                chaos.pop()
    if temp == True and not chaos:
        print('yes')
    else:
        print('no')
