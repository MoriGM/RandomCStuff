#define _POSIX_C_SOURCE 199309L


#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

int sinp(double d)
{
	double s = sin(d * (PI / 180));
	return (int) ((s * 100) * 0.8) + 80;

}

int cosp(double d)
{
	double s = cos(d * (PI / 180));
	return (int) ((s * 100) * 0.8) + 80;

}


int main(void)
{
	while(true)
		for (double d = 0;d < 360;d++)
		{
			int ps = sinp(d);
			int pc = cosp(d);
			for (int i = 0;i < ps;i++)
				printf(" ");
			printf("X\n");
			for (int i = 0;i < pc;i++)
				printf(" ");
			printf("Y\n");
			struct timespec tp;
			tp.tv_nsec = (1000 * 1000 * 3);
			tp.tv_sec = 0;
			nanosleep(&tp, NULL);
		}
	return 0;
}
