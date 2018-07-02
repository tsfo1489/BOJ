#include<stdio.h>
int max(int a, int b) { return a > b ? a : b; }
long long city[100005][2], ans;
int n;
int main()
{
	int i, oil = 2e9;
	scanf("%d", &n);
	for (i = 1; i < n; i++) scanf("%lld", &city[i][0]);
	for (i = 1; i <= n; i++) scanf("%lld", &city[i][1]);

	for (i = 1; i < n; i++)
	{
		if (oil > city[i][1]) oil = city[i][1];
		ans += oil * city[i][0];
	}
	printf("%lld", ans);
}