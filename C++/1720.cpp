#include<stdio.h>
int main()
{
    int k[50]={0},n,i,a,b;
    scanf("%d",&n);
    k[0]=1;
    k[1]=1;
    for(i=2;i<=n;i++) k[i]=k[i-1]+k[i-2]*2;
    if(n%2==1) a=k[n/2];
    else a=k[n/2]+2*k[n/2-1];
    k[n]-=a;
    printf("%d",k[n]/2+a);
}
