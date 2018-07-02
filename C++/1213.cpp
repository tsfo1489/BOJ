#include<stdio.h>
#include<string.h>
int main()
{
    int a[30]={0},i,len,cnt=0,j,k;
    char m[60];
    scanf("%s",m);
    len=strlen(m);
    for(i=0;i<len;i++) a[m[i]-'A'+1]++;
    for(i=1;i<=26;i++) cnt+=a[i]%2;
    if(cnt>1) { printf("I'm Sorry Hansoo"); return 0; }
    if(cnt==1)
    {
        for(i=1;i<=26;i++)
        {
            if(a[i]%2==1)
            {
                for(j=1;j<=a[i]/2;j++) printf("%c",i+'A'-1);
                k=i;
                continue;
            }
            for(j=1;j<=a[i]/2;j++) printf("%c",i+'A'-1);
        }
        printf("%c",k+'A'-1);
    }
    else
    {
        for(i=1;i<=26;i++)
        {
            for(j=1;j<=a[i]/2;j++) printf("%c",i+'A'-1);
        }
    }
    for(i=26;i>=1;i--)
    {
        if(a[i]==1) continue;
        for(j=1;j<=a[i]/2;j++) printf("%c",i+'A'-1);
    }
}
