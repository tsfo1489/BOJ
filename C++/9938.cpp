#include<stdio.h>
#include<vector>
#define MAX 300005
#pragma warning(disable:4996)
int par[MAX], num[MAX], s[MAX], n, l, k = 1; //s는 칸수 num은 가지고 있는 술의 수
int find(int x)
{
	if (par[x] == x) return x;
	return par[x] = find(par[x]);
}
void unite(int a,int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;

	par[b] = a;
}
int main()
{
	int i, j, a, b, x, y;
	freopen("input.txt", "r", stdin);
	scanf("%d %d",&n, &l);
	for (i = 1; i <= l; i++) { par[i] = i; s[i] = 1; }
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &a, &b);
		x = find(a); y = find(b);
		if (x == y)
		{
			if (num[x] < s[x])
			{
				num[x]++;
				printf("LADICA\n");
			}
			else printf("SMECE\n");
		}
		else
		{
			if (num[x] + num[y] < s[x] + s[y])
			{
				unite(a, b);
				num[x] += num[y] + 1; num[y] = 0;
				s[x] += s[y]; s[y] = 0;
				printf("LADICA\n");
			}
			else printf("SMECE\n");
		}
	}
	return 0;
}