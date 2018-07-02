#include<stdio.h>
#include<math.h>
#define MAX 1234567890
int l_tree[1200005], s_tree[1200005], depth[300005], n, c;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
void insert_tree(int node, int target, int x, int y)
{
	if (x == y) 
	{
		l_tree[node] = s_tree[node] = target; 
		return;
	}
	int mid = (x + y) / 2;
	if (target <= mid) insert_tree(node * 2, target, x, mid);
	else insert_tree(node * 2 + 1, target, mid + 1, y);
	l_tree[node] = max(l_tree[node * 2], l_tree[node * 2 + 1]);
	s_tree[node] = min(s_tree[node * 2], s_tree[node * 2 + 1]);
}
int query_l_tree(int node, int x, int y, int qx, int qy)
{
	if (qx <= x && y <= qy) return l_tree[node];
	if (y < qx || qy < x) return 0;
	int mid = (x + y) / 2, tmp1, tmp2;
	tmp1 = query_l_tree(node * 2, x, mid, qx, qy);
	tmp2 = query_l_tree(node * 2 + 1, mid + 1, y, qx, qy);
	return max(tmp1, tmp2);
}
int query_s_tree(int node, int x, int y, int qx, int qy)
{
	if (qx <= x && y <= qy) return s_tree[node];
	if (y < qx || qy < x) return MAX;
	int mid = (x + y) / 2, tmp1, tmp2;
	tmp1 = query_s_tree(node * 2, x, mid, qx, qy);
	tmp2 = query_s_tree(node * 2 + 1, mid + 1, y, qx, qy);
	return min(tmp1, tmp2);
}
int main()
{
	int i, j, tmp, left, right, n_;
	scanf("%d", &n);
	n_ = n;
	n = (int)pow(2.0, ceil(log2((double)n)));
	
	for (i = 1; i <= 2 * n; i++) s_tree[i] = MAX;
	for (i = 1; i <= n_; i++)
	{
		scanf("%d", &tmp);
		if (i == 1)
		{
			insert_tree(1, tmp, 1, n);
			printf("0\n");
			continue;
		}

		if (tmp == 1) left = 0;
		else left = query_l_tree(1, 1, n, 1, tmp - 1);

		if (tmp == n) right = MAX;
		else right = query_s_tree(1, 1, n, tmp + 1, n);

		if (left == 0) depth[tmp] = depth[right] + 1;
		else if (right == MAX) depth[tmp] = depth[left] + 1;
		else depth[tmp] = 1 + max(depth[left] , depth[right]);

		c += depth[tmp];
		insert_tree(1, tmp, 1, n);
		printf("%d\n", c);
	}
}