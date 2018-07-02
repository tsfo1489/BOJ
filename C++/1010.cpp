#include<stdio.h>
long long int dy[40][40], n;
int main()
{
	int i, j, a, b;
	scanf("%lld", &n);
	dy[0][0] = 1;
	for (i = 1; i <= 30; i++)
	{
		dy[i][1] = 1;
		for (j = 1; j <= i; j++)
		{
			dy[i][j] = dy[i - 1][j] + dy[i - 1][j - 1];
		}
	}
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%lld\n", dy[b + 1][a + 1]);
	}
}