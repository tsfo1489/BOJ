#include<stdio.h>
int arr[55];
int main()
{
    int min,max;
    int n,tmp;
    min = 2e9; max = 0;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&tmp);
        if(tmp < min) min = tmp;
        if(tmp > max) max = tmp;
    }
    printf("%d",min*max);
}