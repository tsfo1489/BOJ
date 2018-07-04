#include<stdio.h>
int d[25][10005];
int coin[25];
void F()
{
    int n,m,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&coin[i]);
    scanf("%d",&m);
    for(i=0;i<=n;i++) for(j=0;j<=m;j++) d[i][j] = 0;
    d[0][0]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(d[i][j] == 0) continue;
            for(int k = j; k <= m; k += coin[i]) d[i+1][k] += d[i][j];
        }
    }
    printf("%d\n",d[n][m]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) F();
}