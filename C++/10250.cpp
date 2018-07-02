#include<stdio.h>
int main()
{
	int i, t, n, h, w, floor, room;
	scanf("%d", &t);
	for (i = 1; i <= t; i++)
	{
		scanf("%d%d%d", &h, &w, &n);
		floor = n % h;
		if (floor == 0) floor = h;
		room = n / h;
		if (n % h != 0) room += 1;
		printf("%d%02d\n", floor, room);
	}
}