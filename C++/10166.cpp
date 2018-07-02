#include<stdio.h>
#include<algorithm>
using namespace std;
int d1, d2, n;
struct Angle
{
	int a, b; //a=분모, b=분자
}angle[4000005];
bool cmp(Angle x, Angle y)
{
	if ((double)x.a / x.b < (double)y.a / y.b) return true;
	else return false;
}
int GCD(int a, int b) { return a % b == 0 ? b : GCD(b, a%b); }
void add(int x, int y)
{
	int g = GCD(x, y);
	angle[++n].a = y / g;
	angle[n].b = x / g;
}
int main()
{
	int i, j, cnt = 1;
	scanf("%d%d", &d1, &d2);
	for (i = d1; i <= d2; i++)
	{
		for (j = 1; j <= i; j++)
		{
			add(i, j);
		}
	}
	sort(angle + 1, angle + n + 1, cmp);
	for (i = 2; i <= n; i++)
	{
		if (angle[i].a != angle[i - 1].a || angle[i].b != angle[i - 1].b) cnt++;
	}
	printf("%d", cnt);
}