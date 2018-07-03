#include<stdio.h>
int data[1005], set[1005];
int n;
int main()
{
    int i,j,max;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&data[i]);
    for(i=1;i<=n;i++)
    {
        max = 0;
        for(j=0;j<i;j++) if(max < set[j] + data[i-j]) max = set[j] + data[i-j];
        set[i] = max;
    }
    printf("%d",set[n]);
}