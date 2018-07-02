#include<stdio.h>
int g[1005][1005],chk[1005][1005],n,m,ans[2][1005][1005];
struct QUEUE
{
    int x,y,a;
}q[1000005];
void F(int sx,int sy,int way)
{
    int i,j,f,r,x,y,k;
    f=r=0;
    k=1;
    x=sx;
    y=sy;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) chk[i][j]=0;
    while(1)
    {
        if(g[x-1][y]==0 && chk[x-1][y]==0 && x-1>0) { q[r].a=k+1; q[r].x=x-1; q[r++].y=y; chk[x-1][y]=1; }
        if(g[x+1][y]==0 && chk[x+1][y]==0 && x+1<n+1) { q[r].a=k+1; q[r].x=x+1; q[r++].y=y; chk[x+1][y]=1; }
        if(g[x][y-1]==0 && chk[x][y-1]==0 && y-1>0) { q[r].a=k+1; q[r].x=x; q[r++].y=y-1; chk[x][y-1]=1; }
        if(g[x][y+1]==0 && chk[x][y+1]==0 && y+1<m+1) { q[r].a=k+1; q[r].x=x; q[r++].y=y+1; chk[x][y+1]=1; }

        if(g[x-1][y]==1 && ans[way][x-1][y]==0 && x-1>0) ans[way][x-1][y]=k+1;
        if(g[x+1][y]==1 && ans[way][x+1][y]==0 && x+1<n+1) ans[way][x+1][y]=k+1;
        if(g[x][y-1]==1 && ans[way][x][y-1]==0 && y-1>0) ans[way][x][y-1]=k+1;
        if(g[x][y+1]==1 && ans[way][x][y+1]==0 && y+1<m+1) ans[way][x][y+1]=k+1;

        if(f==r) break;
        x=q[f].x;
        y=q[f].y;
        k=q[f++].a;
    }
}
int F1(int sx,int sy)
{
    int i,j,f,r,x,y,k;
    f=r=0;
    k=1;
    x=sx;
    y=sy;
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) chk[i][j]=0;
    while(1)
    {
        if(g[x-1][y]==0 && chk[x-1][y]==0 && x-1>0) { q[r].a=k+1; q[r].x=x-1; q[r++].y=y; chk[x-1][y]=k+1; }
        if(g[x+1][y]==0 && chk[x+1][y]==0 && x+1<n+1) { q[r].a=k+1; q[r].x=x+1; q[r++].y=y; chk[x+1][y]=k+1; }
        if(g[x][y-1]==0 && chk[x][y-1]==0 && y-1>0) { q[r].a=k+1; q[r].x=x; q[r++].y=y-1; chk[x][y-1]=k+1; }
        if(g[x][y+1]==0 && chk[x][y+1]==0 && y+1<m+1) { q[r].a=k+1; q[r].x=x; q[r++].y=y+1; chk[x][y+1]=k+1; }

        if(f==r) break;
        x=q[f].x;
        y=q[f].y;
        k=q[f++].a;
    }
    return chk[n][m];
}
int main()
{
    int i,j,min=9000000,k;
    freopen("input.txt","r",stdin);

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%1d",&g[i][j]);

    F(1,1,0);
    F(n,m,1);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(ans[0][i][j]!=0 && ans[1][i][j]!=0 && ans[0][i][j]+ans[1][i][j]<min) min=ans[0][i][j]+ans[1][i][j];
        }
    }
    k=F1(1,1);
    if(min==9000000 && k==0) printf("-1");
    else if(min>k && k!=0) printf("%d",k);
    else printf("%d",min-1);
}
