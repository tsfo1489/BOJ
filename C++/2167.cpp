#include<stdio.h>
int map[305][305], n, m;
int main()
{
	int i, j, tmp;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) 
	{
		scanf("%d", &tmp);
		map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + tmp;
	}
	int T;
	int x1,y1,x2,y2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",map[x2][y2] - map[x1-1][y2] - map[x2][y1-1] + map[x1-1][y1-1]);
	}
}