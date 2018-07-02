#include<stdio.h>
#include<math.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int n,fen[20];
double d[70000];
double T(int a, int b, int c)
{
	double s;
	s = (double)(a + b + c) / 2.0;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}
int main()
{
	int i, j, k, x, y, ip, jp, kp;
	double ans;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &fen[i]);
	sort(fen + 1, fen + n + 1);
	for (x = 1; x < (int)pow(2, n) ; x++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = i+1; j <= n; j++)
			{
				for (k = j+1; k <= n; k++)
				{
					ip = (1 << (i - 1)) & x; jp = (1 << (j - 1)) & x; kp = (1 << (k - 1)) & x;
					if (ip == 1 << (i - 1) && jp == 1 << (j - 1) && kp == 1 << (k - 1) && fen[i]+fen[j]>fen[k])
					{
						y = x ^ ((ip | jp) | kp);
						d[x] = max(d[y] + T(fen[i], fen[j], fen[k]),d[x]);
					}
				}
			}
		}
	}
	printf("%.15f", d[(int)pow(2, n)-1]);
}