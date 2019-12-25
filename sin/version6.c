#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

#define KYEL  "\x1B[33m"

#define FM 10

int sinp(double d)
{
	double s = sin(d * (PI / 180));
	return (int) ((s * 100) * 0.8) + 80;

}

int main(void)
{
	double od = 0;
	while(true)
		for (double d = 0;d < 360;d++, od += FM)
		{
			if (od > 360) od = 0;
			double s = sin(od * (PI / 180));
			d += s;
			int ps = sinp(d);
			for (int i = 0;i < ps;i++)
				printf(" ");
			printf("%sX\n", KYEL);
			struct timespec tp;
			tp.tv_nsec = (1000 * 1000 * 10);
			tp.tv_sec = 0;
			nanosleep(&tp, NULL);
		}
	return 0;
}
