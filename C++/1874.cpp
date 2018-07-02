#include<stdio.h>
#include<vector>
using namespace std;
int st[100005], n, top, cnt;
vector<int> arr;
int main()
{
	int i, j, tmp;
	scanf("%d", &n);
	cnt++;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		while (1)
		{
			if (st[top] < tmp)
			{
				st[++top] = cnt++;
				arr.push_back(1);
			}
			else if (st[top] == tmp)
			{
				arr.pop_back()
			}
		}
	}
}