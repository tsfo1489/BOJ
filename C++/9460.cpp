#include<stdio.h>
#include<algorithm>
int k,n,ans;
struct M
{
    int x,y;
}pt[10005];
bool cmp(M a,M b)
{
    if(a.x<b.x) return true;
    else return false;
}
void ANS(int as)
{
    if(as%2==1) printf("%d.5\n",as/2);
    else printf("%d.0\n",as/2);
}
bool CHK(int wid);
void bs(int l,int r)
{
    int mid=(l+r)/2;
    bool o=CHK(mid);
    if(o)
    {
        ans=mid;
        if(l==r) ANS(l);
        else if(l!=r) bs(l,mid);
    }
    else if(l==r) ANS(ans);
    else bs(mid+1,r);
}
void operation()
{
    int i,j,max=-100000005,min=100000005;
    for(i=1;i<=n;i++) pt[i].x=pt[i].y=0;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++) { scanf("%d %d",&pt[i].x,&pt[i].y); pt[i].x*=2; pt[i].y*=2; if(pt[i].y>max) max=pt[i].y; if(pt[i].y<min) min=pt[i].y; }
    std::sort(pt+1,pt+n+1,cmp);
    bs(0,(max-min)/2);
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++) operation();
}
bool CHK(int wid)
{
    int i,max,min,a=1;
    max=min=pt[1].y;
    for(i=2;i<=n;i++)
    {
        if(pt[i].y>max) max=pt[i].y;
        if(pt[i].y<min) min=pt[i].y;
        if((max-min)/2>wid) { max=min=pt[i].y; a++; }
        if(a>k) return false;
    }
    return true;
}
