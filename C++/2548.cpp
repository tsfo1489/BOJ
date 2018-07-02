#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[20005], n;
int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	sort(arr + 1, arr + n + 1);
	printf("%d", arr[(n + 1) / 2]);
}