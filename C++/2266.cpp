#include<stdio.h>
int n,k,d[505][505];
int main()
{
    int i,j,x,min,max;
    scanf("%d %d",&n,&k);

    for(i=1;i<=n;i++) { d[i][1]=i; d[1][i]=1; }

    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            min=2e9; max=0;
            for(x=1;x<i;x++)
            {
                if(d[x][j]+1<d[i-x-1][j]+1) max=d[i-x-1][j]+1;
                else max=d[x][j]+1;
                if(max<min) min=max;
            }
            d[i][j]=min;
        }
    }
    printf("%d",d[n][k]);
}
