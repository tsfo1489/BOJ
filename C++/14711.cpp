#include<stdio.h>
int game_map[1005][1005], n;
int flip_map[1005][1005];
char tmp[1005];
void F(int i)
{
	int j;
	for (j = 1; j <= n; j++)
	{
		if (flip_map[i - 1][j] % 2 == 1)
		{
			game_map[i][j] = 1;
			flip_map[i - 1][j]++;
			flip_map[i][j - 1]++;
			flip_map[i][j + 1]++;
			flip_map[i + 1][j]++;
		}
	}
	for (j = 1; j <= n; j++)
	{
		game_map[i][j] ? printf("#") : printf(".");
	}
	printf("\n");
	if (i == n) return;
	else F(i + 1);
}
int main()
{
	int i;
	scanf("%d",&n);
	scanf("%s", tmp + 1);
	for (i = 1; i <= n; i++) 
		if (tmp[i] == '#') 
		{
			flip_map[0][i] = 1;
		}
	F(1);
}