#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"

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
			int pc = sinp(d + 180);
			for (int i = 0;i < ((ps > pc ? ps : pc) + 1);i++)
			{
				printf(" ");
				if (i == ps) printf("%sX", KYEL);
				if (i == pc) printf("%sY", KBLU);

			}
			printf("\n");
			struct timespec tp;
			tp.tv_nsec = (1000 * 1000 * 3);
			tp.tv_sec = 0;
			nanosleep(&tp, NULL);
		}
	return 0;
}
