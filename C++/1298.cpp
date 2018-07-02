#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> adj[105];
int student[105], laptop[5005], n, m;
bool visited[5005];
bool dfs(int A)
{
	visited[A] = true;
	int i;
	for (i = 0; i < adj[A].size(); i++)
	{
		if (laptop[adj[A][i]] == 0 || ( !visited[laptop[adj[A][i]]] && dfs(laptop[adj[A][i]]) ) )
		{
			student[A] = adj[A][i];
			laptop[adj[A][i]] = A;
			return true;
		}
	}
	return false;
}
int main()
{
	int i, j, match = 0;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	for (i = 1; i <= n; i++)
	{
		fill(visited + 1, visited + n + 1, 0);
		if (dfs(i))
		{
			match++;
		}
	}
	printf("%d", match);
}