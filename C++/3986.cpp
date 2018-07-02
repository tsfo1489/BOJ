#include<stdio.h>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
vector<int> st;
char str[100005];
int main()
{
	int i, j, n, len, ans = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("\n%s", str);
		len = strlen(str);
		for (j = 0; j < len; j++)
		{
			if (st.empty()) st.push_back(str[j] - 'A');
			else if (st.back() != str[j] - 'A') st.push_back(str[j] - 'A');
			else st.pop_back();
		}
		if (st.empty()) ans++;
		st.clear();
	}
	printf("%d", ans);
}