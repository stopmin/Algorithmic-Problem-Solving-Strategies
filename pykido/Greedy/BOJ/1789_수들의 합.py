N = int(input())

sum = 0
cnt = 0
for i in range(1 , N + 1) : 
  if (sum + i) > N : 
    break 
  else :
    sum += i 
    cnt += 1

print(cnt)
