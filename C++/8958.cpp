#include<stdio.h>
#include<string.h>
void F()
{
    char arr[100];
    int i,k;
    int ans = 0;
    scanf("%s",arr);
    k=0;
    for(i=0;i<strlen(arr);i++)
    {
        if(arr[i] != 'O') k = 0;
        else k++;
        ans += k;
    }
    printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) F();
}