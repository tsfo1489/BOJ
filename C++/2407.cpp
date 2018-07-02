#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
long long sol[100005];
long long min(long long x, long long y) { return x > y ? y : x; }
long long max(long long x, long long y) { return x < y ? y : x; }
long long absl(long long x) { return x < 0 ? -1 * x : x; }
long long b_search(int x, int y, long long tar)
{
	if (x == y)	return x;
	int mid = (x + y) / 2;
	if (sol[mid] >= tar) return b_search(x, mid, tar);
	else return b_search(mid + 1, y, tar);
}
int main()
{
	int i, k;
	long long a, b;
	a = b = 1000000000;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%lld", &sol[i]);
	sort(sol + 1, sol + n + 1);

	for (i = 1; i <= n; i++)
	{
		k = b_search(1, n, sol[i] * -1);
		if (absl(sol[i] + sol[k]) < absl(a + b) && i != k)
		{
			a = sol[i];
			b = sol[k];
		}
		if (k > 1)
		{
			k--;
			if (absl(sol[i] + sol[k]) < absl(a + b) && i != k)
			{
				a = sol[i];
				b = sol[k];
			}
			k++;
		}
		if (k < n)
		{
			k++;
			if (absl(sol[i] + sol[k]) < absl(a + b) && i != k)
			{
				a = sol[i];
				b = sol[k];
			}
			k--;
		}
	}
	printf("%lld %lld", min(a, b), max(a, b));
}
