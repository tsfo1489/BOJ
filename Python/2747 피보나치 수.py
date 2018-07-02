import math
n = int(input())
r5 = math.sqrt(5)
k = (1 / r5) * (((1+r5)/2)**n - ((1-r5)/2)**n)
k = k%1000000
print(k)
