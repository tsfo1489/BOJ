#include<stdio.h>
int max(int a, int b) { return a > b ? a : b; }
int dy[1005][1005], n, m, map[1005][1005];
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			dy[i][j] = max( max(dy[i - 1][j], dy[i - 1][j - 1]), dy[i][j - 1]) + map[i][j];
		}
	}
	printf("%d", dy[n][m]);
}
