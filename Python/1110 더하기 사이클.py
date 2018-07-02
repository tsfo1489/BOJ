n = int(input())
k = [0,0]
for i in range(2,n+1) :
    tmp = 10 ** 6 + 1
    if i % 3 == 0 :
        tmp = min(tmp, k[i//3])
    if i % 2 == 0 :
        tmp = min(tmp, k[i//2])
    tmp = min(tmp, k[i - 1])
    k.append(tmp + 1)
print(k[n])
