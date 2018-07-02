#include<stdio.h>
long long int dy[105][105], map[105][105], n;
int main()
{
	int i, j;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++)for (j = 1; j <= n; j++) scanf("%lld", &map[i][j]);
	dy[1][1] = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (map[i][j] == 0) break;
			if (i + map[i][j] <= n)
			{
				dy[i + map[i][j]][j] += dy[i][j];
			}
			if (j + map[i][j] <= n)
			{
				dy[i][j + map[i][j]] += dy[i][j];
			}
		}
	}
	printf("%lld", dy[n][n]);
}