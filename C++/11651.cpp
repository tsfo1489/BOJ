#include<stdio.h>
#include<algorithm>
using namespace std;
struct Coor
{
	int x, y;
}map[100005];
bool cmp(Coor a, Coor b)
{
	if (a.y < b.y) return true;
	else if (a.y == b.y && a.x < b.x) return true;
	else return false;
}
int n;
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d %d", &map[i].x, &map[i].y);
	sort(map + 1, map + n + 1, cmp);
	for (i = 1; i <= n; i++) printf("%d %d\n", map[i].x, map[i].y);
}