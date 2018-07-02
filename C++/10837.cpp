#include<stdio.h>
int d[1005][1005], k;
int Chk(int a, int b, int order)
{
	if (order == 0)
	{
		if (a == b) return 1;
		else
		{
			if (k - a >= a - b) return 1;
			else return 0;
		}
	}
	else if (order == 1)
	{
		if (b <= a) return 1;
		else
		{
			if (k - b - 1 >= b - a) return 1;
			else return 0;
		}
	}
}
int main()
{
	int i, j;
	int c, a, b;

	scanf("%d%d", &k, &c);
	d[0][0] = 1;
	for (i = 1; i <= k; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (Chk(i - 1, j, 0) & d[i - 1][j]) d[i][j] = 1;
		}
		for (j = 0; j <= i; j++)
		{
			if (Chk(j, i - 1, 1) & d[j][i - 1]) d[j][i] = 1;
		}
	}
	for (i = 1; i <= c; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", d[a][b]);
	}
}