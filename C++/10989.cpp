#include<stdio.h>
int arr[10005];
int main()
{
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++) { scanf("%d",&a); arr[a]++; }
    for(int i=1;i<=10000;i++) while(arr[i]--) printf("%d\n",i);
}