#include<stdio.h>
#include<limits.h>
#include<queue>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
struct K
{
	int e, w;
	bool operator <(const K k)const {
		if (k.w<w) return 1;
		else return 0;
	}
};
priority_queue<K> min_heap;
vector<K> edge[300005];
int w[300005], chk[300005], s;
void heap_dijk(int n, int m)
{
	int i, j, k;
	struct K x;
	for (i = 1; i <= n; i++) w[i] = 10000000;
	w[s] = 0; chk[s] = 1;
	j = s;
	while (1)
	{
		k = edge[j].size();
		for (i = 0; i<k; i++)
		{
			if (w[j] + edge[j][i].w<w[edge[j][i].e])
			{
				w[edge[j][i].e] = w[j] + edge[j][i].w;
				x.e = edge[j][i].e; x.w = w[edge[j][i].e];
				min_heap.push(x);
			}
		}
		if (min_heap.empty()) break;
		while (1)
		{
			j = min_heap.top().e;
			min_heap.pop();
			if (chk[j] == 0) break;
		}
		chk[j] = 1;
	}
}
int main()
{
	int i, n, m, a, b, c;
	struct K x;
	scanf("%d %d", &n, &m);
	scanf("%d", &s);
	for (i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		x.e = b; x.w = c;
		edge[a].push_back(x);
	}
	heap_dijk(n, m);
	for (i = 1; i <= n; i++)
	{
		if (w[i] == 10000000) printf("INF\n");
		else printf("%d\n", w[i]);
	}
}
