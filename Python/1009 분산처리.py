n = int(input())
for i in range(n):
    tmp = input().split()
    ori_a = int(tmp[0])%10
    b = int(tmp[1])
    count = []
    dic = {}
    k = 1
    a = ori_a
    while a not in count :
        count.append(a)
        dic[k] = a
        k += 1
        a = (a*ori_a) % 10
    k = k-1
    b = b % k
    if b == 0 :
        b = k
    if dic[b] == 0 :
        print(10)
    else :
        print(dic[b])
