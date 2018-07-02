#include<stdio.h>
int dy[305][305], n, m;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int Cut(int n, int m)
{
	int i, tmp; 
	if (n > m)
	{
		tmp = n;
		n = m;
		m = tmp;
	}

	tmp = 2e9;

	if (dy[n][m] != -1) return dy[n][m];

	for (i = 1; i <= m / 2; i++)
	{
		tmp = min(Cut(i, n) + Cut(m - i, n), tmp) + 1;
	}
	dy[n][m] = tmp;
	return dy[n][m];
}
int main()
{
	int i, j;
	scanf("%d %d", &n, &m);
	if (n > m)
	{
		int tmp = n;
		n = m;
		m = tmp;
	}
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) dy[i][j] = -1;
	dy[1][1] = 0;
	printf("%d",Cut(n, m));
}