
start,end = map(int,input().split())

table = [True] * (end-s tart+1)
answer = end - start + 1
for i in range(2,int(end**0.5+1)):
    square = i*i
    for j in range(((start-1)//square+1) * square, end+ 1, square):
        if table[j - start]:
            table[j - start] = False
            answer -= 1
                
print(answer)