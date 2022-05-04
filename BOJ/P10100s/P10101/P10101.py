a = int(input())
b = int(input())
c = int(input())

if a == b and b == c:
    print('Equilateral')
elif a+b+c == 180 and (a == b or b == c or  c == a):
    print('Isosceles')
elif a+b+c == 180:
    print('Scalene')
else:
    print('Error')
