#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

uint64_t powll(uint64_t a, uint64_t b)
{
	uint64_t ret = 1;
	for (uint64_t i = 0; i < b;i++)
		ret *= a;
	return ret;
}

int main(int argc, char** argv)
{
	if (argc <= 1)
		exit(1);
	int x = atoi(argv[1]), max = 0;

	srand(time(NULL));	

	for (int i = 0;i < x;i++)
	{
		int count = 1;
		while(rand() % 2) count++;
		if (count > max)
			max = count;
	}

	printf("You woud win as maximum %lu\n", powll(2, max));
	printf("Count of right flips is %d\n", max);

	return 0;
}
