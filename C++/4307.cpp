#include<stdio.h>
long long int fm(long long int a,long long int b) { return ( (a>b) ? a : b ); }
void operation()
{
    long long int l,n,i,mia=2e9,maa=0,k,min=0;
    scanf("%lld %lld",&l,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&k);
        if(k<mia) mia=k;
        if(k>maa) maa=k;
        if(k<=l/2 && min<k) min=k;
        if(k>l/2 && min<l-k) min=l-k;
    }
    printf("%lld ",min);
    k=fm(l-mia,maa);
    printf("%lld\n",k);
}
int main()
{
    int k,i;
    scanf("%d",&k);
    for(i=1;i<=k;i++) operation();
}
