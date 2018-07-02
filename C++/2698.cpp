#include<iostream>
using namespace std;
void F(int n, int k)
{
	int d[105][105][2] = { 0 }; // d[i][j][k]:k로 끝나고 j개의 인접된 비트를 가지며 i의 길이
	int i, j;
	d[1][0][0] = 1;
	d[1][0][1] = 1;
	for (i = 2; i <= n; i++)
	{
		d[i][0][1] = d[i - 1][0][0];
		d[i][0][0] = d[i - 1][0][1] + d[i - 1][0][0];
		for (j = 1; j <= k; j++)
		{
			d[i][j][0] = d[i - 1][j][0] + d[i - 1][j][1];
			d[i][j][1] = d[i - 1][j][0] + d[i - 1][j - 1][1];
		}
	}
	cout << d[n][k][0] + d[n][k][1] << endl;
}
int main()
{
	int t, n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		F(n, k);
	}
}