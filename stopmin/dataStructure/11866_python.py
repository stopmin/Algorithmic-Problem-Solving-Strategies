N, K = map(int,input().split())
nums = list(range(1,N+1))

turn = K-1
ans = []

while True:
    ans.append(nums[turn])
    nums = nums[:turn] + nums[turn+1:]
    if not nums: 
        break
    turn = ( turn + K - 1 ) % len(nums)
print('<'+', '.join(list(map(str,ans)))+'>')