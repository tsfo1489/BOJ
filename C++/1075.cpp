#include<stdio.h>
long long n;
int f;
int main()
{
    int i;
    scanf("%lld %d",&n,&f);
    n /= 100;
    n *= 100;
    for(i=0;i<=99;i++)
    {
        if((n + i)%f == 0) break;
    }
    printf("%02d",i);
}