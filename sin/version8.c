#define _POSIX_C_SOURCE 199309L


#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

int saw_down_pos(double s)
{
	return (int) (s / 4.8);
}

int main(void)
{
	while(true)
		for (double d = 0;d < 360;d++)
		{
			int p = saw_down_pos(d);
			for (int i = 0;i < p;i++)
				printf(" ");
			printf("0\n");
			struct timespec tp;
			tp.tv_nsec = (1000 * 1000 * 4);
			tp.tv_sec = 0;
			nanosleep(&tp, NULL);
		}
	return 0;
}
