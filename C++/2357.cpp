#include<stdio.h>
#include<math.h>
int tree[300005][2], n, m;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
struct K { int M, m; };
void insert_tree(int node, int x, int y, int target, int val)
{
	if (x == y) { tree[node][0] = tree[node][1] = val; return; }
	int mid = (x + y) / 2;
	if (target <= mid) insert_tree(node * 2, x, mid, target, val);
	else insert_tree(node * 2 + 1, mid + 1, y, target, val);
	tree[node][0] = max(tree[node * 2][0], tree[node * 2 + 1][0]);
	tree[node][1] = min(tree[node * 2][1], tree[node * 2 + 1][1]);
}
struct K query_tree(int node, int x, int y, int tx, int ty)
{
	struct K tmp1, tmp2, tmp;
	int t1, t2;
	tmp1.M = 0;
	tmp1.m = 2e9;
	tmp2 = tmp1;
	if (ty < x || y < tx) return tmp1;
	int mid = (x + y) / 2;
	tmp1 = query_tree(node * 2, x, mid, tx, ty);
	tmp2 = query_tree(node * 2 + 1, mid + 1, y, tx, ty);
	tmp.M = max(tmp1.M, tmp2.M);
	tmp.m = min(tmp1.m, tmp2.m);
	return tmp;
}
int main()
{
	int i, a, b;
	struct K k;
	scanf("%d %d", &n, &m);

	int n_init = n, tmp;
	n = (int)pow(2, ceil(log2((double)n)));
	for (i = 1; i <= 2 * n_init; i++) tree[i][1] = 2e9;
	for (i = 1; i <= n_init; i++)
	{
		scanf("%d", &tmp);
		insert_tree(1, 1, n, i, tmp);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d", &a, &b);
		k = query_tree(1, 1, n, a, b);
		printf("%d %d\n", k.M, k.m);
	}
}