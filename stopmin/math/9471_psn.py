for _ in range(int(input())):
    P, M = map(int,input().split())

    if M % 10 == 0:
        period = 15 * 10 ** (M/10 - 1)

    print(P, round(period))