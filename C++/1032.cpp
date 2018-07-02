#include<string.h>
#include<stdio.h>
char tmp[55];
char chk[55];
bool ans[55];
int main()
{
    int n,i,j;
    int len;
    scanf("%d",&n);
    scanf("%s",tmp);
    len = strlen(tmp);
    strcpy(chk,tmp);
    for(i=1;i<n;i++)
    {
        scanf("%s",tmp);
        for(j=0;j<len;j++) if(chk[j] != tmp[j]) ans[j] = true;
    }
    for(j=0;j<len;j++) { ans[j] ? printf("?") : printf("%c",chk[j]) ; }
}