#include<stdio.h>
#pragma warning(disable:4996)
char a[10];
int chk()
{
	int x, i, max=0;
	char m;
	x = 1; m = a[0];
	for (i = 1; i < 8; i++)
	{
		if (x > max) max = x;
		if (a[i - 1] == a[i]) x++;
		else { x = 1; m = a[i]; }
	}
	return max;
}
int main()
{
	int i;
	scanf("%s", a);
	printf("%d\n", chk());
	scanf("\n%s", a);
	printf("%d\n", chk());
	scanf("\n%s", a);
	printf("%d\n", chk());
}