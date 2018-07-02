#include<stdio.h>
int string[2005], dy[2005][2005], n, t;
int main()
{
	int i, j, s, e;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &string[i]);
	dy[1][1] = 1;
	for (i = 1; i <= n; i++)
	{
		dy[i][i] = 1;
		if (string[i + 1] == string[i]) dy[i][i + 1] = 1;
	}
	for (i = n; i >= 1; i--)
	{
		for (j = i + 2; j <= n; j++)
		{
			dy[i][j] = (string[i] == string[j]) & (dy[i + 1][j - 1]);
		}
	}
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%d%d", &s, &e);
		printf("%d\n", dy[s][e]);
	}
}