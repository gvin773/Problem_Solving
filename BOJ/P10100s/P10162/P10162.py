t = int(input())
a = t//300
b = t%300//60
c = t%300%60//10
if(t%10):
    print(-1)
else:
    print(a, b, c)
