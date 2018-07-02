#include<stdio.h>
int n, dy[10005][3], wine[10005];
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &wine[i]);
	dy[1][1] = wine[1];
	dy[2][0] = wine[1];
	dy[2][1] = wine[2];
	dy[2][2] = wine[1] + wine[2];
	for (i = 3; i <= n; i++)
	{
		dy[i][0] = max(max(dy[i - 1][0], dy[i - 1][1]), dy[i - 1][2]);
		dy[i][1] = max(max(dy[i - 2][1], dy[i - 2][2]), max(dy[i - 2][0], dy[i - 1][0])) + wine[i];
		dy[i][2] = dy[i - 1][1] + wine[i];
	}
	printf("%d", max(dy[n][0], max(dy[n][1], dy[n][2])));
}