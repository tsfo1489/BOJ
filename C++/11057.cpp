#include<iostream>
using namespace std;
int main()
{
	int n, i, j, sum;
	cin >> n;
	int d[1005][11] = { 0 };
	d[1][0] = d[1][1] = d[1][2] = d[1][3] = d[1][4] = 1;
	d[1][5] = d[1][6] = d[1][7] = d[1][8] = d[1][9] = 1;
	d[1][10] = 10;
	for (i = 2; i <= n; i++)
	{
		sum = 0;
		for (j = 0; j < 10; j++) {
			sum = (sum + d[i - 1][j]) % 10007;
			d[i][j] = sum % 10007;
			d[i][10] = (d[i][10] + d[i][j]) % 10007;
		}
	}
	cout << d[n][10];
}