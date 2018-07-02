#include<stdio.h>
#include<math.h>
int s[600005],n,k=1;
int main()
{
    int i,j,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        a=i;
        for(j=(int)log10(a)+1;j>=1;j--)
        {
            s[k++]=a/((int)pow(10,j-1));
            a=a%((int)pow(10,j-1));
            printf("%d",s[k-1]);
        }
    }
}
