#include<stdio.h>
#include<string.h>
int string[2505], dy[2505][2505], n, t, mem[2505];
char str[2505];
int F(int s)
{
	int i, min = 2e9;
	if (s == n) return 1;
	if (dy[s][n]) return 1;
	if (mem[s]) return mem[s];
	for (i = s; i < n; i++)
	{
		if (!dy[s][i]) continue;
		int tmp = 1 + F(i + 1);
		if (min > tmp) min = tmp;
	}
	mem[s] = min;
	return min;
}
int main()
{
	int i, j, s, e;
	scanf("%s", str);
	n = strlen(str);
	for (i = 1; i <= n; i++) string[i] = str[i] - 'A' + 1;
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
	printf("%d", F(1));
}