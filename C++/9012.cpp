#include<stdio.h>
#include<string.h>
void VPS()
{
    char arr[55];
    scanf("%s",arr);
    int cnt = 0;
    for(int i=0;i<strlen(arr);i++) 
    {
        if(arr[i] == '(') cnt++;
        else cnt--;
        if(cnt < 0) break;
    }
    if(cnt != 0) printf("NO\n");
    else printf("YES");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--) {
        VPS();
    }
}