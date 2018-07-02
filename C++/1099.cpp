#include<stdio.h>
#include<string.h>
int n,l,len[55],cost[55][55],s[55][55];
char m[55],tar[55][55];
void cmp(int num)
{
    int i,j,k,a[30],b[30];
    for(i=0;i<=l-len[num];i++)
    {
        k=0;
        for(j=0;j<30;j++) a[j]=b[j]=0;
        for(j=i;j<i+len[num];j++)
        {
            if(m[j]!=tar[num][j-i]) k++;
            a[m[j]-'a']++;
            b[tar[num][j-i]-'a']++;
        }
        for(j=0;j<30;j++) if(a[j]!=b[j]) break;
        if(j==30) cost[num][i+len[num]-1]=k;
        else cost[num][i+len[num]-1]=-1;
    }
}
int main()
{
    int i,j,sl[55]={0},k,min;
    freopen("input.txt","r",stdin);
    scanf("%s\n%d\n",m,&n);
    for(i=1;i<=n;i++) scanf("%s",tar[i]);

    l=strlen(m);
    sl[0]=9999999;
    for(i=1;i<=n;i++) { len[i]=strlen(tar[i]); if(len[i]<sl[i-1]) sl[i]=len[i]; else sl[i]=sl[i-1]; }
    for(i=1;i<=n;i++) cmp(i);

    for(i=1;i<=l;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(i<sl[n]) { s[i][j]=-1; continue; }
            min=999999;
            for(k=1;k<=n;k++)
            {
                if(j<len[k]) continue;
                if(s[i-len[k]][j-len[k]]!=-1 && cost[k][j-1]!=-1 && s[i-len[k]][j-len[k]]+cost[k][j-1]<min) min=s[i-len[k]][j-len[k]]+cost[k][j-1];
            }
            if(min!=999999) s[i][j]=min;
            else s[i][j]=-1;
        }
    }
    for(i=1;i<=l;i++) { for(j=1;j<=i;j++) printf("%2d ",s[i][j]); printf("\n"); }
    printf("%d",s[l][l]);
    return 0;
}
