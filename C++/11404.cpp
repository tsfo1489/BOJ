#include<stdio.h>
#include<string.h>
#include<limits.h>
#pragma warning(disable:4996)
long long int map[205][205];
int min(int a, int b) { return a > b ? b : a; }
int main()
{
	int a, b, c, n, s, m, i, j, k;
	scanf("%d\n%d", &n, &m);
	for (i = 1; i <= m; i++) 
	{ 
		scanf("%d %d %d", &a, &b, &c); 
		if (map[a][b] != 0) map[a][b] = min(c, map[a][b]);
		else map[a][b] = c; 
	}
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) if (map[i][j] == 0 && i != j) map[i][j] = 2e9;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (map[i][j]>map[i][k] + map[k][j]) map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	for (i = 1; i <= n; i++) { for (j = 1; j <= n; j++) printf("%lld ", map[i][j]); printf("\n"); }
}
