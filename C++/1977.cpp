#include<stdio.h>
#include<math.h>
int F(int n)
{
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (n == i*i) return 1;
	}
	return 0;
}
int main()
{
	int n, m, i;
	int sum = 0, min = 10001;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++)
	{
		if (F(i) == 1)
		{
			sum += i;
			if (min > i) min = i;
		}
	}
	if (min == 10001) printf("-1");
	else printf("%d\n%d", sum, min);
}