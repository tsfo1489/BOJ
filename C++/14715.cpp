#include <stdio.h>
#include<math.h>
int factorization(int n)
{
	int p = 2;
	int primes[500];
	int index = 0;
	int i;

	while (n != 1) 
	{
		if (n%p == 0) 
		{
			n = n / p;
			primes[index] = p;
			index++;
			p = 2;
		}
		else 
		{
			p++;
		}
	}
	return index;
}

int main(void) 
{
	int n;
	scanf("%d", &n);
	printf("%d",(int)ceil(log2(factorization(n))));
	return 0;
}
