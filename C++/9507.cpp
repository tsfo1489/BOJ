#include<stdio.h>
long long arr[70];
int main()
{
    arr[0] = arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=4;i<=67;i++) arr[i] = arr[i-1]+ arr[i-2]+ arr[i-3]+ arr[i-4];
    int T,tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&tmp);
        printf("%lld\n",arr[tmp]);
    }
}