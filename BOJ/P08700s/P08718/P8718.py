x, k = map(int, input().split())

x = x*1000
k = k*1000

c1 = int(k + k*2 + k*4)
c2 = int(k/2 + k + k*2)
c3 = int(k/4 + k/2 + k)

if(c1 <= x):
    print(c1)
elif(c2 <= x):
    print(c2)
elif(c3 <= x):
    print(c3)
else:
    print(0)
