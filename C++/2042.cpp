#include<stdio.h>
#include<math.h>
long long int n, m, k;
long long int itree[3000020], u0[1000005];
void build_itree(int node, int x, int y)
{
	if (x == y) itree[node] = u0[x];
	else
	{
		int mid = (x + y) / 2;
		build_itree(node * 2, x, mid);
		build_itree(node * 2 + 1, mid + 1, y);
		itree[node] = itree[node * 2] + itree[node * 2 + 1];
	}
}
void update_itree(int node, int x, int y, int q, long long int nval)
{
	if (x == y) itree[node] = u0[x] = nval;
	else
	{
		int mid = (x + y) / 2;
		if (q <= mid) update_itree(node * 2, x, mid, q, nval);
		else update_itree(node * 2 + 1, mid + 1, y, q, nval);
		itree[node] = itree[node * 2] + itree[node * 2 + 1];
	}
}
long long int query_itree(int node, int x, int y, int qx, int qy)
{
	if (qx <= x && y <= qy) return itree[node];
	else
	{
		int mid = (x + y) / 2;
		int ret1 = 0, ret2 = 0;
		if (qx <= mid) ret1 = query_itree(node * 2, x, mid, qx, qy);
		if (mid < qy) ret2 = query_itree(node * 2 + 1, mid + 1, y, qx, qy);
		return ret1+ret2;
	}
}
int main()
{
	long long int i, a, b, o, j, mn;
	scanf("%lld %lld %lld", &n, &m, &k);
	mn = pow(2, (ceil(log2((float)n))));
	for (i = 1; i <= n; i++) scanf("%lld\n", &u0[i]);
	
	build_itree(1, 1, mn);
	for (i = 1; i <= m + k; i++)
	{
		scanf("%lld %lld %lld", &o, &a, &b);
		if (o == 1) 
		{
			update_itree(1, 1, mn, a, b);
		}
		else if (o == 2) printf("%lld\n", query_itree(1, 1, mn, a, b));
	}
}
