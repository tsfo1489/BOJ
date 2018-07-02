#include<stdio.h>
int main()
{
	int hour, min, i, j, re_h = 0, re_min = 0;
	scanf("%d %d", &hour, &min);
	for (i = 0; i <= 720; i++)
	{
		if (re_h == hour && re_min == min)
		{
			printf("O");
			return 0;
		}
		re_h++;
		re_min+=12;
		re_h = re_h % 360;
		re_min = re_min % 360;
	}
	if (re_h == hour && re_min == min)
	{
		printf("O");
		return 0;
	}
	printf("X");
	return 0;
}