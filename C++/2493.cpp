#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
struct T
{
	long long int h;
	int i;
};
vector<T> st;
int main()
{
	int n,i;
	long long int a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &a);
		while (1)
		{
			if (st.size() == 0) break;
			if (st.back().h < a) st.pop_back();
			else break;
		}
		if (st.size() == 0) printf("0 ");
		else printf("%d ", st.back().i);
		st.push_back({ a,i });
	}
}