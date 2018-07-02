#include<stdio.h>
#include<string.h>
int t[3005][3005];
char x[3005],y[3005];
int main()
{
    int a,b,c,i,j,n,m,k;
    freopen("input.txt","r",stdin);
    scanf("%d %d %d",&a,&b,&c);
    scanf("%s\n%s",x,y);
    n=strlen(x); m=strlen(y);

    for(i=n;i>=1;i--) { x[i]=x[i-1]; t[i][0]=b*i; }
    for(i=m;i>=1;i--) { y[i]=y[i-1]; t[0][i]=b*i; }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            k=-999999999;
            if(x[i]==y[j] && t[i-1][j-1]+a>k) k=t[i-1][j-1]+a;
            if(x[i]!=y[j] && t[i-1][j-1]+a>k) k=t[i-1][j-1]+c;
            if(t[i-1][j]+b>k) k=t[i-1][j]+b;
            if(t[i][j-1]+b>k) k=t[i][j-1]+b;
            t[i][j]=k;
        }
    }
    printf("%d",t[n][m]);
}
