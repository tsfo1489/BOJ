#include<stdio.h>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
struct S
{
	int l, r;
}s[1005];
bool cmp(S a, S b)
{
	if (a.r < b.r) return true;
	else if (a.r == b.r && a.l < b.l) return true;
	else return false;
}
int F(int n, int m)
{
	int i, j, p, ans = 0, chk[1005] = { 0 };
	for (i = 1; i <= m; i++)
	{
		p = s[i].l;
		while (1)
		{
			if (s[i].l <= p && p <= s[i].r && chk[p] == 0) { ans++; chk[p]++;  break; }
			if (p > s[i].r) break;
			p++;
		}
	}
	return ans;
}
int main()
{
	int i, j, q, n, m;
	freopen("input.txt", "r", stdin);
	scanf("%d", &q);
	for (i = 1; i <= q; i++)
	{
		memset(s, 0, sizeof(s));
		scanf("%d %d", &n, &m);
		for (j = 1; j <= m; j++) scanf("%d %d", &s[j].l, &s[j].r);
		sort(s + 1, s + m + 1, cmp);
		printf("%d\n", F(n, m));
	}
}