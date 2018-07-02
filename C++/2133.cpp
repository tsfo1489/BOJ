#include<stdio.h>
int d[35];
int main()
{
	int i, j, n;
	scanf("%d", &n);
	d[2] = 3;
	for (i = 4; i <= n; i += 2)
	{
		d[i] += 2;
		for (j = 4; i - j >= 2; j += 2)
		{
			d[i] += d[i - j] * 2;
		}
		d[i] += d[i - 2] * 3;
	}
	printf("%d", d[n]);
}