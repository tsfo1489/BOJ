#include<stdio.h>
int ctry[1005][3];
int main()
{
	int n, i, j, k, tmp, ans = 1;
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		scanf("%d%d%d", &ctry[tmp][0], &ctry[tmp][1], &ctry[tmp][2]);
	}
	for (i = 1; i <= n; i++)
	{	
		if (ctry[i][0] > ctry[k][0]) ans++;
		else if (ctry[i][0] == ctry[k][0] && ctry[i][1] > ctry[k][1]) ans++;
		else if (ctry[i][1] == ctry[k][1] && ctry[i][2] > ctry[k][2]) ans++;
	}
	printf("%d", ans);
}