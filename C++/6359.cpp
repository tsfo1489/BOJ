#include<stdio.h>
#include<math.h>
int arr[105];
int main()
{
    for(int i=1;i<=10;i++) for(int j=i*i;j<=100;j++) arr[j]++;
    int T,tmp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&tmp);
        printf("%d\n",arr[tmp]);
    }
}