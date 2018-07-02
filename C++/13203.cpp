#include<stdio.h>
char str[200005], qstr[200005], name[10];
void F()
{
	int n, m, q, i;
	scanf("%d %d %d", &n, &m, &q);
	scanf("\n%s", str);
	scanf("\n%s", name);
	for (i = 1; i <= q; i++)
	{
		scanf("\n%s", qstr);
	}
}
int main()
{
	int t, i, j;
	scanf("%d", &t);
	scanf("\n");
	for (i = 1; i <= t; i++) F();
}