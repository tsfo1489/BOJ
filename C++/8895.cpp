#include<stdio.h>
long long int map[21][21][21];
void O()
{
    int n,l,r,i,j,k;
    scanf("%d %d %d",&n,&l,&r);
    map[1][1][1]=1;
    for(k=2;k<=n;k++) for(i=1;i<=l;i++) for(j=1;j<=r;j++) map[k][i][j]=map[k-1][i-1][j]+map[k-1][i][j-1]+map[k-1][i][j]*(k-2);
    printf("%lld\n",map[n][l][r]);
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++) O();
}
