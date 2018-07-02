#include<iostream>
using namespace std;
int main()
{
	int i, max=-1005, n, sum=0, num, neg_max = -1005;
	bool chk = false;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> num;
		sum += num;
		if (num >= 0) chk = true;
		if (sum < 0) sum = 0;
		if (sum > max) max = sum;
		if (num > neg_max) neg_max = num;
	}
	if (!chk) cout << neg_max;
	else cout << max;
	return 0;
}