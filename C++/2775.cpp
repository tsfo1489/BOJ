#include<stdio.h>
long long arr[20][20];
int main()
{
    int T;
    int i,j;
    for(i=1;i<=14;i++) arr[0][i] = i;
    for(i=1;i<=14;i++)
    {
        for(j=0;j<=14;j++) arr[i][j] = arr[i][j-1] + arr[i-1][j];
    }
    
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&i,&j);
        printf("%d\n",arr[i][j]);
    }
    
}