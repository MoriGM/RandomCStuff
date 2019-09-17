#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <pthread.h>

uint64_t try = 0, max = 0, x = 0;

void *check_flips(void* arg)
{
	while(try++ < x)
	{
		uint64_t count = 1;
		while(rand() % 2) count++;
		if (count > max) max = count;
	}
}

uint64_t powll(uint64_t a, uint64_t b)
{
	uint64_t ret = 1;
	for (uint64_t i = 0; i < b;i++)
		ret *= a;
	return ret;
}

int main(int argc, char** argv)
{
	if (argc <= 2) exit(1);
	x = strtol(argv[1], NULL, 10);
	int cpu = atoi(argv[2]);

	srand(time(NULL));	

	pthread_t threads[cpu];

	for (int i = 0;i < cpu;i++)
		pthread_create(&threads[i], NULL, &check_flips, NULL);

	for (int i = 0;i < cpu;i++)
		pthread_join(threads[i], NULL);

	printf("You woud win as maximum %lu\n", powll(2, max));
	printf("Count of right flips is %ld\n", max);

	return 0;
}
