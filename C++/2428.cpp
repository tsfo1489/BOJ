#include<stdio.h>
#include<algorithm>
/*
struct S
{
    double fs;
    int num,st;
}s[200010];*/
int n;
long long int ans,s[100010];/*
bool C(const S &a,const S &b)
{
    if(a.fs<b.fs) return true;
    else if(a.fs==b.fs && a.st>b.st) return true;
    else if(a.fs==b.fs && a.st<=b.st && a.num<b.num) return true;
    else return false;
}
void cpl()
{
    int i,j;
    for(i=1;i<=2*n;i++)
    {
        b2[i]=b2[i-1];
        if(s[i].st==2) { b2[i]++; cp[s[i].num]=i; }
        if(s[i].st==1) { ans+=b2[i]-b2[cp[s[i].num]]; }
    }
}
int main()
{
    int i,j,a;
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(i=1;i<=n;i++) { scanf("%d",&a); s[i].st=1; s[i].fs=a*1.0; s[i].num=i; s[i+n].st=2*1.0; s[i+n].fs=s[i].fs*0.9; s[i+n].num=i; }
    std::sort(s+1,s+2*n+1,C);
    cpl();
    for(i=1;i<=n*2;i++) printf("%g %d %d   %lld   %lld\n",s[i].fs,s[i].st,s[i].num,b2[i],cp[s[i].num]);
    printf("%lld",ans);
}*/
int main()
{
    int i,j,f,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&s[i]);
    f=1;
    std::sort(s+1,s+n+1);
    for(r=2;r<=n;r++)
    {
        while(1)
        {
            if(s[f]*10>=s[r]*9) break;
            if(f==r) break;
            f++;
        }
        ans+=r-f;
    }
    printf("%lld",ans);
}
