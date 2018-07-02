#include<stdio.h>
int map[105][105],q[10005][2],chk[105][105],h,w;
char aa[105][105]={0};
void sc()
{
    int i,j;
    freopen("input.txt","r",stdin);

    scanf("%d %d\n",&h,&w);

    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            scanf("%c",&aa[i][j]);
            if(aa[i][j]=='.') continue;
            else if(aa[i][j]=='/') map[i+1][j]=map[i][j+1]=1;
            else if(aa[i][j]==92) map[i][j]=map[i+1][j+1]=1;
        }
        scanf("\n");
    }
}
bool cdr(int sx,int sy) { return (aa[sx][sy]!='.') ? false : true; }
bool cdl(int sx,int sy) { return (aa[sx][sy-1]!='.') ? false : true; }
bool cur(int sx,int sy) { return (aa[sx-1][sy]!='.') ? false : true; }
bool cul(int sx,int sy) { return (aa[sx-1][sy-1]!='.') ? false : true; }
int main()
{
    int i,j,hap=0,k,f,r,x,y;
    sc();
    x=y=1;
    f=r=1;
    while(1)
    {
        if(map[x+1][y]==0 && chk[x+1][y]==0 && x+1<=h+2) { q[r][0]=x+1; q[r++][1]=y; chk[x+1][y]=1; }
        if(map[x-1][y]==0 && chk[x-1][y]==0 && x-1>=0) { q[r][0]=x-1; q[r++][1]=y; chk[x-1][y]=1; }
        if(map[x][y+1]==0 && chk[x][y+1]==0 && y+1<=w+2) { q[r][0]=x; q[r++][1]=y+1; chk[x][y+1]=1; }
        if(map[x][y-1]==0 && chk[x][y-1]==0 && y-1>=0) { q[r][0]=x; q[r++][1]=y-1; chk[x][y-1]=1; }

        if(map[x+1][y+1]==0 && chk[x+1][y+1]==0 && x<h+2 && y<w+2 && cdr(x,y)) { q[r][0]=x+1; q[r++][1]=y+1; chk[x+1][y+1]=1; }
        if(map[x+1][y-1]==0 && chk[x+1][y-1]==0 && x<h+2 && y>=1 && cdl(x,y)) {q[r][0]=x+1; q[r++][1]=y-1; chk[x+1][y-1]=1; }
        if(map[x-1][y+1]==0 && chk[x-1][y+1]==0 && x>=1 && y<w+2 && cur(x,y)) { q[r][0]=x-1; q[r++][1]=y+1; chk[x-1][y+1]=1; }
        if(map[x-1][y-1]==0 && chk[x-1][y-1]==0 && x>=1 && y>=1 && cul(x,y)) { q[r][0]=x-1; q[r++][1]=y-1; chk[x-1][y-1]=1; }
        if(f==r) break;
        x=q[f][0];
        y=q[f++][1];
    }
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            if(chk[i][j]+chk[i+1][j]+chk[i][j+1]+chk[i+1][j+1]==1) hap+=1;
            if(chk[i][j]+chk[i+1][j]+chk[i][j+1]+chk[i+1][j+1]==0) hap+=2;
        }
    }
    printf("%d",hap/2);
}
