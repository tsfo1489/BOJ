#include<stdio.h>
int d[1005];
int n;
int main()
{
    int i;
    scanf("%d",&n);
    d[0] = 1; d[1] = 1; d[2] = 3;
    for(i=3;i<=n;i++) d[i] = ((d[i-2] * 2) % 10007 + d[i-1]) % 10007;
    printf("%d",d[n]);
}