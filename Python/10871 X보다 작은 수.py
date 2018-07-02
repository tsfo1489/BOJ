tmp = input().split()
n = int(tmp[0])
x = int(tmp[1])
tmp =input().split()
for i in tmp :
    if int(i) < x:
        print(i,end = " ")
