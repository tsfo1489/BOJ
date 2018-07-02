#include<stdio.h>
int finger[6][6], n;
bool S(int a, int b)
{
	if (a == 1 && b == 3) return false;
	if (a == 3 && b == 1) return false;
	if (a == 1 && b == 4) return false;
	if (a == 4 && b == 1) return false;
	if (a == 3 && b == 4) return false;
	if (a == 4 && b == 3) return false;
	return true;
}
int main()
{
	int i, j, a, b, k = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d",&a,&b);
		if (S(a, b)) k = 1;
	}
	if (k == 1 || n < 3) printf("Woof-meow-tweet-squeek");
	else printf("Wa-pa-pa-pa-pa-pa-pow!");
	return 0;
}