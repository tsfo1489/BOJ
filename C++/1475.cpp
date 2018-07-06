#include<stdio.h>
#include<string.h>
char arr[50];
int ans, cnt[10];
int main()
{
    int len,i,j;
    scanf("%s",arr); len = strlen(arr);
    for(i=0;i<len;i++)
    {
        j = arr[i]-'0';
        if(j == 9 && cnt[6] < cnt[9]) j = 6;
        if(j == 6 && cnt[6] > cnt[9]) j = 9;
        cnt[j]++;
        if(cnt[j] > ans) ans = cnt[j];
    }
    printf("%d",ans);   
}