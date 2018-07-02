#include<stdio.h>
#include<queue>
using namespace std;
#define K 1000000007
void T()
{
	int n;
	int i, j;
	long long tmp, a, b;
	priority_queue<long long> slime;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &tmp);
		slime.push(tmp);
	}
	while (slime.size() > 1)
	{
		a = slime.top();
		slime.pop();
		b = slime.top();
		slime.pop();
		slime.push(a*b);
	}
	printf("%lld", slime.top() % K);
}
int main()
{
	int i, t;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) T();
}