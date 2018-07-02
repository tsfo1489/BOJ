n = int(input())
tmp = input().split()
li1 = []
for i in tmp :
    li1.append(int(i))
    
tmp = input().split()
li2 = []
for i in tmp :
    li2.append(int(i))

li1 = sorted(li1, reverse = True )
li2 = sorted(li2)
ans = 0
for i in range(n) :
    ans += li1[i]*li2[i]
print(ans)
