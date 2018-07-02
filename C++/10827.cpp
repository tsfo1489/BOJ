#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
long long int s[1505], un;
int exp, dot;
char in[15];
int main()
{
	scanf("%s %d", in, &exp);
	int i, j, l=0;
	for (i = 0; i < strlen(in); i++)
	{
		if (in[i] == '.')
		{
			dot = strlen(in) - i - 1;
			continue;
		}
		un = (un * 10) + (in[i] - '0');
		l++;
	}
	s[1] = un;
	for (i = 1; i <= l; i++)
	{
		s[i + 1] += s[i] / 10;
		s[i] = s[i] % 10;
	}
	for (i = 2; i <= exp; i++)
	{
		for (j = 1; j <= 1500; j++) s[j] = s[j] * un;
		for (j = 1; j <= 1500; j++)
		{
			s[j + 1] += s[j] / 10;
			s[j] = s[j] % 10;
		}
	}
	for (i = 1500; i >= 1; i--) if (s[i] != 0) break;
	if (i <= dot * exp)
	{
		printf("0.");
		for (i = dot * exp; i >= 1; i--) printf("%d", s[i]);
	}
	else
	{
		for (i = i; i >= 1; i--)
		{
			if (dot * exp == i) printf(".");
			printf("%d", s[i]);
		}
	}
}