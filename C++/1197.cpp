#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
struct E
{
	int s, e, w;
}edge[100005];
bool cmp(E a, E b)
{
	return a.w < b.w;
}
int v, e, root[10005];
long long int ans;
int Find(int st)
{
	if (root[st] == -1) return st;
	root[st] = Find(root[st]);
	return root[st];
}
void Kruskal()
{
	int i, j, a, b;
	for (i = 1; i <= e; i++)
	{
		if (root[edge[i].s] == 0 && root[edge[i].e] == 0) 
		{ 
			root[edge[i].s] = -1; 
			root[edge[i].e] = edge[i].s; 
			ans += edge[i].w;
			continue;
		}
		else if (root[edge[i].s] != 0 && root[edge[i].e] == 0) 
		{ 
			root[edge[i].e] = edge[i].s; 
			ans += edge[i].w;
			continue;
		}
		else if (root[edge[i].s] == 0 && root[edge[i].e] != 0) 
		{ 
			root[edge[i].s] = edge[i].e; 
			ans += edge[i].w; 
			continue;
		}
		a = Find(edge[i].s); b = Find(edge[i].e);
		if (root[edge[i].s] != 0 && root[edge[i].e] != 0 && a != b) 
		{ 
			root[b] = a;
			ans += edge[i].w; 
		}
	}
}
int main()
{
	int i;
	scanf("%d %d", &v, &e);

	for (i = 1; i <= e; i++) scanf("%d %d %d", &edge[i].s, &edge[i].e, &edge[i].w);
	sort(edge + 1, edge + e + 1, cmp);
	Kruskal();
	printf("%lld",ans);
}