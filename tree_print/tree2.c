#include <stdio.h>

#define SIZE 13

int main(void)
{
	int x = 1;
	for (int i = 0; i < SIZE;i += 2)
	{
		for (int a = SIZE; a > i;a -= 2)
			printf(" ");
		for (int a = 0;a < x;a++)
			printf("**");
		printf("\n");
		x++;
	}
	return 0;
}
