#include <stdio.h>

#define SIZE 13

int main(void)
{
	int x = 0;
	for (int i = SIZE; i > 0;i -= 2)
	{
		for (int a = 0; a < x;a++)
			printf(" ");
		for (int a = 0;a < i;a++)
			printf("*");
		printf("\n");
		x++;
	}
	return 0;
}
