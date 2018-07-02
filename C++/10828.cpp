#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
vector<int> st;
int main()
{
	int n, i,a;
	char str[10];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("\n%s", str);
		if (str[0] == 'p' && str[1] == 'u')
		{
			scanf("%d", &a);
			st.push_back(a);
		}
		if (str[0] == 't')
		{
			if (st.size() == 0) printf("-1\n");
			else printf("%d\n", st.back());
		}
		if (str[0] == 's')
		{
			printf("%d\n", st.size());
		}
		if (str[0] == 'p' && str[1] == 'o')
		{
			if (st.size() == 0) printf("-1\n");
			else { printf("%d\n", st.back()); st.pop_back(); }
		}
		if (str[0] == 'e')
		{
			printf("%d\n", st.empty());
		}
	}
}