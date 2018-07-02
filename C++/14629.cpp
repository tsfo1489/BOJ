#include<stdio.h>
#pragma warning(disable:4996)
int cnt[10], n_num;
long long int n, ans, ans_val;
long long int abs(long long int a) { return a < 0 ? -1 * a : a; }
FILE *A = fopen("input.txt", "r");
FILE *B = fopen("out2.txt", "w");
void loop(long long int k)
{
	if (abs(k - n) < ans_val)
	{
		ans = k;
		ans_val = abs(k - n);
	}
	else if (abs(k - n) == ans_val && ans > k)
	{
		ans = k;
		ans_val = abs(k - n);
	}
	int i;
	for (i = 0; i <= 9; i++)
	{
		if (cnt[i] == 0)
		{
			cnt[i] = 1;
			loop(k * 10 + i);
			cnt[i] = 0;
		}
	}
}
int main()
{
	fscanf(A,"%lld", &n);
	long long int k = n;
	ans_val = 9876543211;
	while (k > 0) { k /= 10; n_num++; }
	if (n > 9876543210) {
		printf("9876543210");
		return 0;
	}
	loop(0);
	fprintf(B,"%lld", ans);
}