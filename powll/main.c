#include <stdio.h>

extern unsigned long long powll(unsigned long long a, unsigned long long b);

int main(void)
{
	for (unsigned long long i = 0; i < 32;i++)
		printf("%llu\n", powll(2, i));
	return 0;
}
