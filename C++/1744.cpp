#include<stdio.h>
#include<algorithm>
int a[10005],n;
int fmin(int a,int b)
{
    if(a>b) return b;
    else return a;
}
int main()
{
    int i,j,mi=0,ze=0,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    std::sort(a+1,a+n+1);
    for(i=1;i<=n;i++) { if(a[i]<0) mi++; if(a[i]==0) ze++; }
    for(i=n;i>=1;i--)
    {
        if(a[i]==1) ans+=a[i];
        else if(a[i]>0)
        {
            if(a[i-1]<=1) { ans+=a[i]; continue; }
            else { ans+=a[i]*a[i-1]; i--; }
        }
        else if(a[i]==0) continue;
        else if(a[i]<0) break;
    }
    for(i=1;i<=mi-(mi%2);i++)
    {
        if(i+1>mi-(mi%2)) ans+=a[i];
        else { ans+=a[i]*a[i+1]; i++; }
    }
    if(mi%2==1 && ze==0) ans+=a[i];
    printf("%d",ans);
}
