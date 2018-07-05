#include <stdio.h>
int main()
{
	int T;
	unsigned int s,e;
    int distance;
    scanf("%d",&T);
	while(T--)
    {
		scanf("%u %u", &s, &e);
        distance = e-s;
		for(long long i=0;;i++)
		{
			if (i*i<distance && distance<=(i+1)*(i+1))
			{
				if(i*i+i>=distance) printf("%lld\n", 2*i);
				else printf("%lld\n", 2*i+1);
				break;
			}
		}
	}
}