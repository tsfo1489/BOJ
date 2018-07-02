#include<stdio.h>
#include<string.h>
char A[10005], B[10005];
int num_a[10], num_b[10];
int main()
{
	int i, j;
	int len_a, len_b;
	scanf("%s %s", A, B);
	len_a = strlen(A); len_b = strlen(B);
	for (i = 0; i < len_a; i++) num_a[A[i] - '0']++;
	for (i = 0; i < len_b; i++) num_b[B[i] - '0']++;
	long long ans = 0;
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) ans += i * j * num_a[i] * num_b[j];
	}
	printf("%lld", ans);
}