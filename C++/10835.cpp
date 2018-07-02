#include<stdio.h>
int n;
int left[2005], right[2005], d[2005][2005];
int max(int a, int b) { return a > b ? a : b; }
int main()
{
	int i, j;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (i = n; i >= 1; i--) scanf("%d", &left[i]);
	for (i = n; i >= 1; i--) scanf("%d", &right[i]);

	if (left[1] > right[1]) d[1][1] = right[1];
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			d[i + 1][j + 1] = max(d[i+1][j+1], d[i][j]);
			d[i + 1][j] = max(d[i + 1][j], d[i][j]);
			if (left[i] > right[j + 1]) d[i][j + 1] = max(d[i][j + 1], right[j + 1] + d[i][j]);
		}
	}
	printf("%d", d[n][n]);
}