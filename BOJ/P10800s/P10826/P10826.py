n = int(input())
if n <= 1:
    print(n)
elif n == 2:
    print(1)
else:
    a1 = 1
    a2 = 1
    for i in range(3, n+1):
        t = a2
        a2 = a1+a2
        a1 = t
    print(a2)
