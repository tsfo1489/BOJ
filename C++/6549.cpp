#include<stdio.h>
long long int st[1000001][2], k[1000001];
int main()
{
	int top = 0, i, n;
	long long int ans = 0;

	while (1)
	{
		top = 0;
		ans = 0;
		scanf("%d", &n);
		if (n == 0) break;
		for (i = 0; i < n; i++) scanf("%lld", &k[i]);

		st[top][0] = 0;
		st[top++][1] = k[0];
		for (i = 1; i<n; i++)
		{
			if (st[top - 1][1] <= k[i])
			{
				st[top][0] = i;
				st[top++][1] = k[i];
			}
			else
			{
				while (1)
				{
					if (st[top - 1][1]>k[i])
					{
						if (ans < (i - st[--top][0])*st[top][1]) ans = (i - st[top][0])*st[top][1];
					}
					else { st[top++][1] = k[i]; break; }
				}
			}
		}
		while (1)
		{
			if (st[top - 1][1]>0)
			{
				if (ans < (n - st[--top][0])*st[top][1]) ans = (n - st[top][0])*st[top][1];
			}
			else { st[top++][1] = 0; break; }
		}
		printf("%lld\n", ans);
	}
}
