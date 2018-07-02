#include<stdio.h>
#define MOD 1000000007
int n;
long long d1[1000005];
long long d2[1000005];
int main()
{
	int i;
	scanf("%d", &n);
	d1[1] = 2;
	d1[2] = 7;
	d1[3] = 22;
	d2[3] = 1;
	for (i = 4; i <= n; i++)
	{
		d2[i] = (d2[i - 1] + d1[i - 3]) % MOD;
		d1[i] = (d1[i - 1] * 2 + d1[i - 2] * 3 + d2[i] * 2) % MOD;
	}
	printf("%d", d1[n]);
}