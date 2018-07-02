#include<stdio.h>
int d[100005],chk[100005],q[100005];
int main()
{
    int x,i,n,k,f,r;
    scanf("%d %d",&n,&k);
    f=r=0;
    x=n;
    while(1)
    {
        if(chk[x-1]==0 && x-1>=0) { q[r++]=x-1; chk[x-1]=chk[x]+1; }
        if(chk[x+1]==0 && x+1<=100000) { q[r++]=x+1; chk[x+1]=chk[x]+1; }
        if(chk[2*x]==0 && 2*x<=100000) { q[r++]=2*x; chk[2*x]=chk[x]+1; }

        if(x==k) { printf("%d",chk[x]); break; }
        if(f==r) break;
        x=q[f++];
    }
}
