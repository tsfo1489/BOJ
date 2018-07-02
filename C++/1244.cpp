#include<iostream>
using namespace std;
namespace M
{
	void F(int k, int* arr, int n)
	{
		for (int i = k; i <= n; i += k)
		{
			arr[i] = 1-arr[i];
		}
	}
}
namespace W
{
	void F(int k, int* arr, int n)
	{
		for (int i = 0; k + i <= n && k - i > 0; i++)
		{
			if (arr[k - i] == arr[k + i]) arr[k - i] = arr[k + i] = 1 - arr[k + i];
			else break;
		}
	}
}
int main()
{
	int i, n, m, a, b;
	cin >> n;
	int arr[105];
	for (i = 1; i <= n; i++) cin >> arr[i];
	cin >> m;
	for (i = 1; i <= m; i++)
	{
		cin >> a >> b;
		if (a == 1) M::F(b, arr, n);
		else W::F(b, arr, n);
	}
	for (i = 1; i <= n; i++)
	{
		cout << arr[i] << " ";
		if (i % 20 == 0) cout << "\n";
	}
}
