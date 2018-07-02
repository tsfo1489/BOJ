#include<stdio.h>
int main()
{
	int i, a, b, c, n, ans = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		if (i < 100) ans++;
		if (i >= 100 && i <= 999)
		{
			a = i / 100;
			b = (i / 10) % 10;
			c = i % 10;
			if (b - a == c - b) ans++;
		}
	}
	printf("%d", ans);
}