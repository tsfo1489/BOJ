#include<stdio.h>
#include<math.h>
struct M
{
    int num,data,d;
}tree[2050];
int power(int k)
{
    int n1;
    n1=pow(2,(double)k);
    return (int)n1;
}
int main()
{
    int k,n,i,j;
    freopen("input.txt","r",stdin);
    scanf("%d",&k);
    n=power(k);
    for(i=1;i<n;i++) { scanf("%d",&tree[i].data); tree[i].num=i; tree[i].d=k; }
    for(i=k;i>=1;i--)
    {
        for(j=1;j<n;j++)
        {
            if(tree[j].num%power(k-i)==0 && tree[j].num%power(k-i+1)==0) tree[j].d--;
        }
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<n;j++) if(tree[j].d==i) printf("%d ",tree[j].data);
        printf("\n");
    }
}
