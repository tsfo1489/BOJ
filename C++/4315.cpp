#include<stdio.h>
#include<stdlib.h>
struct E
{
    int m,b,sn;
}node[10005];
int map[10005],ans,f,r;
void M(int n)
{
    int i,j,k,a;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        scanf("%d %d",&node[k].b,&node[k].sn);
        for(j=1;j<=node[k].sn;j++)
        {
            scanf("%d",&a);
            node[a].m=k;
        }
        if(node[k].sn==0) map[r++]=k;
    }
}
void BFS(int n)
{
    int x,chk[10005]={0};
    x=map[0];
    chk[x]=1;
    f=1;
    while(1)
    {
        node[node[x].m].b=node[node[x].m].b+(node[x].b-1);
        ans+=abs(node[x].b-1);
        node[node[x].m].sn--;
        if(node[node[x].m].sn==0) { map[r++]=node[x].m; chk[node[x].m]=1; }
        if(f==r) break;
        if(node[x].m==0) break;
        x=map[f++];
    }
}
int main()
{
    int n,i,j,top;
    freopen("input.txt","r",stdin);
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        M(n);
        BFS(n);
        printf("%d\n",ans);
        ans=0;
        for(i=0;i<n;i++) map[i]=0;
        f=r=0;
    }
}
