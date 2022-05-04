x = sorted(map(int, input().split()))
if(x[0] == x[1] and x[1] == x[2]):
    print(2)
elif(x[0]**2 + x[1]**2 == x[2]**2):
    print(1)
else:
    print(0)
