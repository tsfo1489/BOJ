n = int(input())
k = [[0,0],[1,0]]
for i in range(2,n+1) :
    k.append([k[i-1][1],k[i-1][0]+k[i-1][1]])
print(sum(k[n]))
