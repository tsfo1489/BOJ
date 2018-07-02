#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> adj[1005];
int a[1005], b[1005], n, m;
bool visited[1005];
bool dfs(int A)
{
	int i, B;
	visited[A] = true;
	for (i = 0; i < adj[A].size(); i++)
	{
		B = adj[A][i];
		if (b[B] == 0 || (!visited[b[B]] && dfs(b[B])))
		{
			a[A] = B;
			b[B] = A;
			return true;
		}
	}
	return false;
}
int main()
{
	int i, j, match = 0;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		int s;
		scanf("%d", &s);
		for (j = 1; j <= s; j++)
		{
			int k;
			scanf("%d", &k);
			adj[i].push_back(k);
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			fill(visited + 1, visited + n + 1, false);
			if (dfs(i)) match++;
		}
	}
	printf("%d", match);
}