#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SPEED 10
#define PI 3.14159265

#define KYEL  "\x1B[33m"

struct operator
{
	double pos;
	double rotation;
	int fm;
	struct operator *modulator;
};


struct operator *ops;
int ops_count;
int pos_last;

int sinp(double d)
{
	double s = sin(d * (PI / 180));
	return (int) ((s * 100) * 0.8) + 80;

}

double sinc(double d)
{
	double s = sin(d * (PI / 180));
	return s;
}

void create_operator(int fm)
{
	(ops + ops_count)->fm = fm;
	(ops + ops_count)->pos = 0;
	(ops + ops_count)->rotation = 0;
	(ops + ops_count)->modulator = (ops_count > 0) ? &ops[(ops_count - 1)] : NULL;
	
	ops_count++;
}

void calc_modulator(struct operator *op)
{
	op->rotation += op->fm;
	if (op->modulator != NULL)
		op->rotation += (op->modulator->fm * op->modulator->pos);
	if (op->rotation > 360) op->rotation -= 360;
	op->pos = sinc(op->rotation);
}

void calc_carrier(struct operator *op)
{
	op->rotation += op->fm;
	if (op->modulator != NULL)
		op->rotation += (op->modulator->fm * op->modulator->pos);
	if (op->rotation > 360) op->rotation -= 360;
	pos_last = op->pos;
	op->pos = sinp(op->rotation);
}

void sleep_nano()
{
	struct timespec tp;
	tp.tv_nsec = (1000 * 1000 * SPEED);
	tp.tv_sec = 0;
	nanosleep(&tp, NULL);
}


int main(int argc, char** argv)
{
	if (argc == 1) return 1;
	ops = (struct operator*) malloc(sizeof(struct operator) * (argc - 1));
	ops_count = 0;
	pos_last = 80;
	for (int i = 1;i < argc;i++)
		create_operator(atoi(argv[i]));	

	struct operator *carrier = &ops[(ops_count - 1)];

	while(true)
	{
		for (int i = 0;i < (ops_count - 1);i++)
			calc_modulator(&ops[i]);
		calc_carrier(carrier);
		for (int i = 0; i < ((pos_last > carrier->pos) ? carrier->pos : pos_last); i++)
			printf(" ");
		printf("%sX", KYEL);
		for (int i = ((pos_last > carrier->pos) ? carrier->pos : pos_last); i < ((pos_last < carrier->pos) ? carrier->pos : pos_last); i++)
			printf("X");

		printf("\n");
		sleep_nano();
	}
	return 0;
}
