#include<stdio.h>
#include<math.h>
#pragma warning(disable:4996)
long long int gcd, lcm, x, y, z;
long long int GCD(int a, int b)
{
	if (a % b == 0) return b;
	return GCD(b, a % b);
}
int main()
{
	long long int i, k;
	scanf("%lld %lld", &gcd, &lcm);
	z= lcm / gcd;
	for (i = (long long int)ceil(sqrt((double)z)); i <= z; i++)
	{
		if (z%i == 0)
		{
			k = GCD(i, z / i);
			if (k == 1)
			{
				printf("%lld %lld", gcd*z / i, gcd*i);
				return 0;
			}
		}

	}
}