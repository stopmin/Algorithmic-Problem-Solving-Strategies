# 내 풀이
N = list(map(int,str(input())))

left_sum = 0
right_sum = 0
for i in range( len(N) // 2 ) : 
  left_sum += N[i]
  right_sum += N[len(N) - i - 1]

if left_sum == right_sum : 
  print("LUCKY")
else : 
  print("READY")
