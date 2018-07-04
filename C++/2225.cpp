#include<stdio.h>
long long arr[205][205];
int main()
{
    int N,K;
    int i,j,k;

    scanf("%d%d",&N,&K);
    arr[0][0] = 1;
    for(i=0;i<K;i++)
    {
        for(j=0;j<=N;j++)
        {
            for(k=0;k<=N;k++)
            {
                if(arr[i][j] == 0 || j+k > N) continue;
                arr[i+1][j+k] = (arr[i+1][j+k] + arr[i][j]) % 1000000000;
            }
        }
    }
    printf("%d",arr[K][N]);
}