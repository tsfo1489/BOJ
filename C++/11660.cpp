#include<stdio.h>
int arr[1030][1030], sum[1030][1030], x[1030][1030];
int n, m;
void Sum()
{
	int i, j;
	int sum1, sum2;
	for (i = 1; i <= n; i++)
	{
		sum1 = 0;
		for (j = 1; j <= n; j++)
		{
			sum1 += arr[i][j];
			x[i][j] = sum1;
		}
	}
	int t = 1;
	int x1 = 1, y1 = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			sum[i][j] = sum[i - 1][j] + x[i][j];
		}
	}
}
int main()
{
	int i, j, x1, y1, x2, y2;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) scanf("%d",&arr[i][j]);
	Sum();
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++) printf("%2d ", sum[i][j]);
		printf("\n");
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x2][y1 - 1] - sum[x1 - 1][y2]);
	}
}