#include<stdio.h>
long long arr[105];
int main()
{
    int T,n;
    scanf("%d",&T);
    arr[1] = arr[2] = arr[3] = 1;
    arr[4] = arr[5] = 2;
    for(int i=6;i<=100;i++) arr[i] = arr[i-1]+arr[i-5];
    while(T--)
    {
        scanf("%d",&n);
        printf("%lld\n",arr[n]);
    }
}