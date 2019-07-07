#include <stdio.h>

#define SIZE 13

int main(void)
{
	int x = 1;
	for (int i = 0; i < SIZE;i += 2)
	{
		for (int a = 0; a < ((SIZE - i) / 2);a++)
			printf(" ");
		for (int a = SIZE;a > (SIZE - (i + 1));a--)
			printf("*");
		printf("\n");
		x++;
	}
	return 0;
}
