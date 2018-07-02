#include<stdio.h>
#include<algorithm>
struct E
{
    int a,b,dis;
}edge[20005];
int n,ml,md,sh[1005];
int Bellman()
{
    int i,j,x,chk=0;
    for(i=1;i<=n;i++) sh[i]=2e9;
    sh[1]=0;
    for(i=1;i<=n;i++) for(j=1;j<=ml+md;j++) { if(sh[edge[j].b]>sh[edge[j].a]+edge[j].dis) { sh[edge[j].b]=sh[edge[j].a]+edge[j].dis; if(i==n) chk=1; } }
    return chk;
}
bool cmp(E a,E b)
{
    if(a.a<b.a) return true;
    else return false;
}
int main()
{
    int i;
    scanf("%d %d %d",&n,&ml,&md);
    for(i=1;i<=ml;i++) scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].dis);
    for(i=1;i<=md;i++) { scanf("%d %d %d",&edge[i+ml].b,&edge[i+ml].a,&edge[i+ml].dis); edge[i+ml].dis*=-1; }
    std::sort(edge+1,edge+ml+md+1,cmp);
    if(Bellman()==1) printf("-1");
    else if(sh[n]<0 || sh[n]==2e9) printf("-2");
    else printf("%d",sh[n]);
}
