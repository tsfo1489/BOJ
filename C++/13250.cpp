#include<stdio.h>
double arr[1000005];
int main()
{
    int i,j,n;
    arr[0] = 0.0;
    arr[1] = 1.0;
    for(i=2;i<=6;i++) { for(j=i-1;j>=0;j--) arr[i] += (arr[j] + 1) * 1.0 / 6.0; arr[i] += 1.0*(6-i)/6.0; }
    scanf("%d",&n);
    for(i=7;i<=n;i++)
    {
        for(j=1;j<=6;j++) arr[i] += (arr[i-j]+1)/6.0;
    }
    printf("%.10lf",arr[n]);
}