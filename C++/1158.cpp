#include<stdio.h>
int chk[5005];
int main()
{
	int n, m, i, cnt, a = 0;
	scanf("%d%d", &n, &m);
	i = 1; cnt = 1;
	printf("<");
	while (1)
	{
		if (chk[i] == 0)
		{
			if (cnt % m == 0)
			{
				a++;
				chk[i] = 1;
				printf("%d", i);
				if (a == n) break;
				printf(", ");
			}
			cnt++;
		}
		i++;
		if (i > n) i = 1;
	}
	printf(">");
}