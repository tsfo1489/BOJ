#include<stdio.h>
int n;
int F()
{
    int i=1,hap=0,s=0;
    while(1)
    {
        s+=i-1;
        hap+=4*s+1;
        if(n<hap) break;
        i++;
    }
    return i-1;
}
int main()
{
    scanf("%d",&n);
    printf("%d",F());
}
