#include<stdio.h>
int map[305][305], d[305][305], n, m;
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) scanf("%d", &map[i][j]);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			d[i][j]=map[i][j]+d[i-1][j]
		}
	}

}