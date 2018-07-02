n = int(input())
li = []
for i in range(n) :
    li.append(int(input()))
dy = [ [li[0], li[0]], [li[1], li[0]+li[1]]]
for i in range(2,n) :
    tmp = [0,0]
    tmp[0] = max(dy[i-2]) + li[i]
    tmp[1] = dy[i-1][0] + li[i]
    dy.append(tmp)
print(max(dy[n-1]))
