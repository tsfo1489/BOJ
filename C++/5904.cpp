#include<stdio.h>
int s[30];
char F(int k,int n)
{
    if(k==0)
    {
        if(n==1) return 'm';
        else return 'o';
    }
    if(n<=s[k-1]) return F(k-1,n);
    else if(n<=s[k-1]+k+3)
    {
        if(n==s[k-1]+1) return 'm';
        else return 'o';
    }
    else return F(k-1,n-(s[k-1]+k+3));
}
int main()
{
    int n,i;
    scanf("%d",&n);
    s[0]=3;
    for(i=1;i<=28;i++) s[i]=s[i-1]*2+i+3;
    printf("%c",F(29,n));
}
