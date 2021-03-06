#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_hall(int arr[], int pick)
{
	for (int i = 0;i < 3;i++)
		if (i != pick && arr[i] == 0)
			return i;
	return 0;
}

int main(void)
{
	int number = 0, result[] = {0, 0}; // result 0 = wrong, 1 = right
	printf("How many tries: ");
	scanf("%d", &number);
	
	srand(time(NULL));

	for (int i = 0;i < number;i++)
	{
		int arr[3] = {0, 0, 0};
		arr[rand() % 3] = 1;
		int pick = rand() % 3, monty = get_hall(arr, pick);
		int pos = 3 - (((pick + 1) + (monty + 1)) % 3);
		result[arr[pos - 1]] += 1;
	}

	printf("Right: %d and Wrong: %d\n", result[1], result[0]);
	printf("You woud win %d%% times and lose %d%% times\n", ((result[1] * 100) / number), ((result[0] * 100) / number));
	
	return 0;
}
