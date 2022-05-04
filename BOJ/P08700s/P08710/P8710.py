k, w, m = map(int, input().split())
if(k >= w):
    print(0)
else:
    print(int(not not ((w-k)%m)) + (w-k)//m)
