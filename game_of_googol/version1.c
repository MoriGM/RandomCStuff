#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M_E 2.71828
#define MAX_TEST 100
#define MAX_COUNT 100

unsigned int powi(unsigned int a, unsigned int b)
{
	unsigned int ret = 1;
	for (unsigned int i = 0; i < b;i++)
		ret *= a;
	return ret;
}

unsigned int define_array(unsigned int* arr)
{
	unsigned int max = 0;
	for (int i = 0; i < MAX_COUNT;i++)
	{
		arr[i] = rand() % powi(2, 20);
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int main(void)
{
	srand(time(NULL));
	int result[2] = {0, 0}; // lose, win
	for (int test = 0; test < MAX_TEST;test++)
	{
		unsigned int *arr = malloc(sizeof(unsigned int) * MAX_COUNT);
		unsigned int max_arr = define_array(arr);
		unsigned int max = 0, try_count = (int) ((MAX_COUNT / M_E) + 0.99999), my_max = MAX_COUNT;
		for (unsigned int i = 0; i < try_count;i++) if (max < arr[i]) max = arr[i];
		for (unsigned int i = try_count;i < MAX_COUNT;i++)
			if (max < arr[i])
			{
				my_max = arr[i];
				break;
			}

		result[my_max == max_arr] += 1;
		free(arr);
	}
	printf("Try's:%d Loses:%d Wins: %d\n", MAX_TEST, result[0], result[1]);
	printf("You woud win %d%% times and lose %d%%\n", ((result[1] * 100) / MAX_TEST), ((result[0] * 100) / MAX_TEST));
	
	return 0;
}
