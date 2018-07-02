#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[100005], n;
int b_search(int x, int y, int tar)
{
	if (x == y)
	{
		if (arr[x] == tar) return 1;
		else return 0;
	}
	int mid = (x + y) / 2;
	if (tar <= arr[mid]) return b_search(x, mid, tar);
	else return b_search(mid + 1, y, tar);
}
int main()
{
	int i, tar, m;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + n + 1);
	scanf("%d", &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d", &tar);
		printf("%d\n", b_search(1, n, tar));
	}
}