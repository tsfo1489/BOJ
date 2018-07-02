#include<stdio.h>
bool d[10005];
void D(int k)
{
	int cnt = 0;
	if (k > 10000) return;
	d[k] = true;
	cnt += k;
	while (k > 0)
	{
		cnt += k % 10;
		k = k / 10;
	}
	D(cnt);
}
int main()
{
	int i;
	for (i = 1; i <= 10000; i++)
	{
		if (!d[i]) {
			printf("%d\n", i);
			D(i);
		}
	}
}