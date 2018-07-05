#include <stdio.h>
bool table[1000001];
int main() {
	long long min, max;
	long long i, j, temp;
	int count = 0;

	scanf("%lld %lld", &min, &max);

	for (i = 2; i*i <= max; i++) 
    {
		j = i*i;
        temp = min;
		if (min % j)temp = min + j - min%j;
        for(;temp<=max;temp+=j) table[temp - min] = true;
	}
	for (i = 0; i <= max - min; i++) if (!table[i])count++;
	printf("%d\n", count);
}