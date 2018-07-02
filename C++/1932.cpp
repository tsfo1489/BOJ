#include<stdio.h>
int n, map[505][505];
int max(int a, int b) { return a>b ? a : b; }
int main()
{
	int i, j, tmp, k = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			scanf("%d", &tmp);
			map[i][j] = max(map[i - 1][j], map[i - 1][j - 1]) + tmp;
			if (i == n)
			{
				k = max(k, map[i][j]);
			}
		}
	}
	printf("%d", k);
}