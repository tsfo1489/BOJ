import math
n = int(input())
for i in range(n) :
    tmp = input().split()
    x1 = int(tmp[0])
    y1 = int(tmp[1])
    r1 = int(tmp[2])
    x2 = int(tmp[3])
    y2 = int(tmp[4])
    r2 = int(tmp[5])
    dis = (x1-x2)**2 + (y1-y2)**2
    dis = math.sqrt(dis)
    if dis == 0 and r1 == r2 :
        print(-1)
    elif dis == r1 + r2 or abs(r1-r2) == dis:
        print(1)
    elif dis < r1 + r2 and dis > abs(r1-r2) :
        print(2)
    else :
        print(0)
        
    
