from sys import stdin

for _ in range(3):
    n = int(stdin.readline())
    sum = 0
    for _ in range(n):
        x = int(stdin.readline())
        sum += x
    if sum == 0: print(0)
    elif sum > 0: print('+')
    else: print('-')
