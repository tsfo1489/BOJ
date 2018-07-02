#include<stdio.h>
long long int a,b,sh[50]={0};
long long int F(long long int k)
{
    long long int num[51]={0},ans=0;
    int i,n;
    for(i=1;i<=49;i++) if(k<sh[i]) break;
    if(i==50) n=49;
    else n=i-1;
    for(i=n;i>=0;i--) num[i]=k/sh[i];
    for(i=0;i<=n;i++) ans+=sh[i]*(num[i]-num[i+1]);
    return ans;
}
int main()
{
    int i;
    scanf("%lld %lld",&a,&b);
    sh[0]=1;
    for(i=1;i<=49;i++) sh[i]=sh[i-1]*2;
    printf("%lld",F(b)-F(a-1));
    return 0;
}
