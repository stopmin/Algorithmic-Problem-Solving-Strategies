import sys
input = sys.stdin.readline

num = int(input())
time = list()
time_table = [True]*(num+1)

for i in range(num):
    time.append(list(map(int,input().split())))
time.sort(key= lambda x: (x[1]-x[0]))
print(time)