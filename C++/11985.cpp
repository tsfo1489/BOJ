#include<stdio.h>
int n, m, k, orange[20005];
struct Or
{
	int or_min = 2e9, or_max = 0;
	long long int d;
}box[20005][1005];
long long max(int a, int b) { return a > b ? a : b; }
long long min(int a, int b) { return a < b ? a : b; }
int main()
{
	int i, j;
	long long int last_min;
	scanf("%d%d%d", &n, &m, &k);
	for (i = 1; i <= n; i++) scanf("%d", &orange[i]);
	box[1][1].d = k;
	box[1][1].or_max = orange[1];
	box[1][1].or_min = orange[1];
	last_min = k;
	for (i = 2; i <= n; i++)
	{
		box[i][1].d = last_min + k;
		box[i][1].or_max = orange[i];
		box[i][1].or_min = orange[i];
		last_min = box[i][1].d;
		for (j = 2; j <= m; j++)
		{
			if (j > i) break;
			box[i][j].or_max = max(box[i - 1][j - 1].or_max, orange[i]);
			box[i][j].or_min = min(box[i - 1][j - 1].or_min, orange[i]);
			box[i][j].d = k + j * (box[i][j].or_max - box[i][j].or_min);
			last_min = min(last_min, box[i][j].d);
		}
	}
	printf("%lld", last_min);
}