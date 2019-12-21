#define _POSIX_C_SOURCE 199309L


#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

int main(void)
{
	while(true)
		for (double d = 0;d < 360;d++)
		{
			double s = cos(d * (PI / 180));
			int p = (int) ((s * 100) / 1.33) + 75;
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
