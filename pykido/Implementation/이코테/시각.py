## 내 풀이
N = int(input())

h = 0
m = 0
s = 0
cnt = 0

while h != (N + 1):
  s += 1
  m += s // 60
  h += m // 60

  s = s % 60
  m = m % 60
  h = h % 24

  if '3' in str(h) + str(m) + str(s):
    cnt += 1

print(cnt)



## 동빈좌 풀이 
# H를 입력 받기
h = int(input())

count = 0
for i in range(h + 1) :
  for j in range(60) :
    for k in range(60) :
      # 매 시각 안에 '3'이 포함되어 있다면 카운트 증가 
      if '3' in str(i) + str(j) + str(k) : 
        count += 1

print(count)
