#include<stdio.h>
bool map[1005][1005];
int prev_cnt[1005], cost[1005];
void F()
{
    int n, k, w;
    int i, j, now, max;
    int a, b;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) map[i][j] = false;
    for(i=1;i<=n;i++) { scanf("%d",&cost[i]); prev_cnt[i] = 0; }
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&a, &b);
        map[a][b]=true;
        prev_cnt[b]++;
    }
    scanf("%d",&w);

    for(i=0;i<n;i++)
    {
        for(j=1;j<=n;j++) if(prev_cnt[j] == 0) break;
        now = j;
        prev_cnt[now] = -1;
        max = 0;
        for(j=1;j<=n;j++) if(map[j][now] && max < cost[j]) max = cost[j];
        cost[now] += max;
        for(j=1;j<=n;j++) if(map[now][j]) prev_cnt[j]--;
    }
    printf("%d\n",cost[w]);
}
int main()
{
    int i,T;
    scanf("%d",&T);
    for(i=0;i<T;i++) F();
}