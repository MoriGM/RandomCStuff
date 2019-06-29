#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int number = 0, result[] = {0, 0}; // result 0 = right, 1 = wrong
	printf("How many tries: ");
	scanf("%d", &number);
	
	srand(time(NULL));

	for (int i = 0;i < number;i++)
	{
		int arr[3] = {0, 0, 0};
		arr[rand() % 3] = 1;
		result[arr[rand() % 3]] += 1;
	}

	printf("Right: %d and Wrong: %d\n", result[0], result[1]);
	printf("You woud win %d%% times and lose %d%% times\n", ((result[0] * 100) / number), ((result[1] * 100) / number));
	
	return 0;
}
