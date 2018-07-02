#include<iostream>
using namespace std;
int d[100][11];
int main()
{
	int i, j, n;
	d[1][1] = d[1][2] = d[1][3] = d[1][4] = 1;
	d[1][5] = d[1][6] = d[1][7] = d[1][8] = d[1][9] = 1;
	d[1][10] = 9;
	cin >> n;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			if (j > 0) d[i][j] = (d[i][j] + d[i - 1][j - 1]) % 1000000000;
			if (j < 9) d[i][j] = (d[i][j] + d[i - 1][j + 1]) % 1000000000;
		}
		for (j = 0; j <= 9; j++)
		{
			d[i][10] = (d[i][10] + d[i][j]) % 1000000000;
		}
	}
	cout << d[n][10];
}