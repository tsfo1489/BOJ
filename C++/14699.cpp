#include<stdio.h>
#include<vector>
using namespace std;
vector<int> edge[5005];
int	n;
int height[5005], way[5005];
int max(int a, int b) { return a > b ? a : b; }
int DFS(int k)
{
	if (way[k] != 0) return way[k];
	int i, large = 0;

	for (i = 0; i < edge[k].size(); i++)
	{
		large = max(large, DFS(edge[k][i]));
	}
	way[k] = large + 1;
	return way[k];
}
int main()
{
	int i, m, a, b;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) scanf("%d", &height[i]);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		if (height[a] > height[b]) edge[b].push_back(a);
		else edge[a].push_back(b);
	}
	for (i = 1; i <= n; i++)
	{
		printf("%d\n", DFS(i));
	}
}