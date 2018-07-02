#include<stdio.h>
struct Point{
    int x;
    int y;
};
int F()
{
    struct Point start, end;
    int n,x,y,rad,i;
    int ans=0;
    scanf("%d%d%d%d",&start.x, &start.y, &end.x, &end.y);
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&rad);
        int tmp_start = (start.x - x)*(start.x - x) + (start.y - y)*(start.y - y) - rad*rad;
        int tmp_end = (end.x - x)*(end.x - x) + (end.y - y)*(end.y - y) - rad*rad;

        if((tmp_start ^ tmp_end) < 0) ans++;
    }
    return ans;
}
int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++) printf("%d\n",F());
}