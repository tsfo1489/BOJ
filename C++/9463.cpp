#include<stdio.h>
long long int r[100005],t[100005],tree[300005],ans;
void Ut(int node,int x,int y,int q)
{
    if(x==y) tree[node]=1;
    else
    {
        int mid=(x+y)/2;
        if(q<=mid) Ut(node*2,x,mid,q);
        else Ut(node*2+1,mid+1,y,q);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}
int St(int node,int x,int y,int sx,int sy)
{
    if(sx<=x && y<=sy) return tree[node];
    else
    {
        int mid=(x+y)/2,r1=0,r2=0;
        if(sx<=mid) r1=St(node*2,x,mid,sx,sy);
        if(sy>mid) r2=St(node*2+1,mid+1,y,sx,sy);
        return r1+r2;
    }
}
void operation()
{
    int n,i,j,a;
    scanf("%d",&n);
    for(i=1;i<=300004;i++) tree[i]=0;
    for(i=1;i<=100004;i++) r[i]=t[i]=0;
    ans=0;
    for(i=1;i<=n;i++) { scanf("%d",&a); t[a]=i; }
    for(i=1;i<=n;i++) { scanf("%d",&a); r[t[a]]=i; }

    for(i=1;i<=n;i++)
    {
        if(r[i]-1!=0) ans+=r[i]-1-St(1,1,n,1,r[i]-1);
        Ut(1,1,n,r[i]);
    }
    printf("%lld\n",ans);
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++) operation();
}
