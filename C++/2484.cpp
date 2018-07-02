#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int k[5];
int calc()
{
	int chk[7], i;
	for (i = 1; i <= 4; i++) chk[k[i]]++;
	for (i = 1; i <= 6; i++)
	{
		if (k[i] == 4) return 50000 + 5000 * i;
		if (k[i] == 3) return 10000 + 1000 * i;
	}
}
int main()
{
	int i, j, n;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= 4; j++) scanf("%d", &k[i]);
	}

}