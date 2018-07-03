#include<stdio.h>
#include<algorithm>
using namespace std;
int d[10005], n, k, coin[105];
int min(int a, int b) { return a < b ? a : b; }
int main()
{
	int i, j;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) scanf("%d", &coin[i]);
	sort(coin + 1, coin + n + 1);
	for (i = 1; i <= k; i++)
	{
        d[i] = 2e9;
        for(j=1;j<=n;j++) if(i >= coin[j]) d[i] = min(d[i], d[i-coin[j]] + 1);
	}
	if (d[k] == 2e9) printf("-1");
	else printf("%d", d[k]);
}