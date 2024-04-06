import sys
nums = []
for _ in range(int(input())):
    num = int(sys.stdin.readline().rstrip())
    if num==0:
        nums.pop()
    else:
        nums.append(num)
print(sum(nums))