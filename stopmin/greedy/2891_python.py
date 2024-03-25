N,S,R = map(int, input().split())
broken = list(map(int, input().split()))
extra = list(map(int, input().split()))
cnt = S

for i in extra:
  if i in broken:
    broken.remove(i)
    extra.remove(i)
    cnt -= 1

for i in broken:
  for j in extra:
    if j-1 <= i <= j+1:
      extra.remove(j)
      cnt -= 1
      break
    elif j+1 < i:
      break
print(cnt)