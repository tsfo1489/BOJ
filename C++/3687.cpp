#include<stdio.h>
long long dp[105]={ 0,0,1,7,4,2,6,8,10,18,22 };
int main()
{
    int T,n;
    int i,j;
    long long tmp;
    scanf("%d",&T);
    for(i=11;i<=100;i++)
    {  
        if(i%7 == 1)
        {
            tmp = 10;
            for(j=1;j<i/7;j++) tmp = tmp*10 + 8;
        }
        if(i%7 == 2)
        {
            tmp = 1;
            for(j=0;j<i/7;j++) tmp = tmp*10 + 8;
        }
        if(i%7 == 3)
        {
            tmp = 200;
            for(j=2;j<i/7;j++) tmp = tmp*10 + 8;
        }
        if(i%7 == 4)
        {
            tmp = 20;
            for(j=1;j<i/7;j++) tmp = tmp*10 + 8;
        }
        if(i%7 == 5)
        {
            tmp = 2;
            for(j=0;j<i/7;j++) tmp = tmp*10 + 8;
        }
        if(i%7 == 6)
        {
            tmp = 6;
            for(j=0;j<i/7;j++) tmp = tmp*10 + 8;
        }
        if(i%7 == 0)
        {
            tmp = 8;
            for(j=1;j<i/7;j++) tmp = tmp*10 + 8;
        }
        dp[i] = tmp;
    }
    while(T--)
    {
        scanf("%d",&n);
        printf("%lld ",dp[n]);
        if(n % 2 == 1)
        {
            printf("7");
            for(i=1;i<n/2;i++) printf("1");
        }
        else for(i=1;i<=n/2;i++) printf("1");
        printf("\n");
    }
}