n = int(input())
data = []
for i in range(n) :
    tmp = input().split()
    data.append([int(tmp[0]),int(tmp[1]),int(tmp[2])])
ans = [data[0]]
for i in range(1,n) :
    tmp0 = min(ans[i-1][1],ans[i-1][2])
    tmp1 = min(ans[i-1][0],ans[i-1][2])
    tmp2 = min(ans[i-1][0],ans[i-1][1])
    tmp = [tmp0 + data[i][0],tmp1 + data[i][1],tmp2 + data[i][2]]
    ans.append(tmp)
print(min(ans[n-1][0],ans[n-1][1],ans[n-1][2]))
