# 입력 받기
str_lst = list(input())

num = 0
result_lst = []
for i in range(len(str_lst)) :
  if str_lst[i] >= '0' and str_lst[i] <= '9' : # str_lst[i].isdig()도 가능
    num += int(str_lst[i])
  else : 
    result_lst.append(str_lst[i])

result_lst.sort()
result = ''.join(map(str, result_lst))
print(result + str(num))
