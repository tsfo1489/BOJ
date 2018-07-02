#include<stdio.h>
int dy[1005], n;
int main()
{
	int i, j;
	scanf("%d", &n);
	dy[1] = 1; dy[2] = 2;
	for (i = 3; i <= n; i++) dy[i] = (dy[i - 1] + dy[i - 2]) % 10007;
	printf("%d", dy[n]);
}