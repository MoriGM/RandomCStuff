#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#define START_COIN_COUNT 10
#define REMOVED_COIN_COUNT 1

struct circle
{
	char face;
	int count;
};

int main(void)
{
	/*
 	* 7 = Best Win | 100000 Coin's
 	* L = Lose | 0 Coin's
 	* W = Win | 1000 Coin's
 	* Z = Zonk (Goat) | 10 Coin's
 	* 1 = 1 Coin's
 	* H = 100 Coin's
 	*/
	struct circle circles[] = {{face:'7', count:100000}, {face:'L', count:0}, {face:'W', count:1000}, {face:'Z', count:10}, {face:'1', count:1}, {face:'H', count:100}};
	long coin_count = START_COIN_COUNT;
	
	srand(time(NULL));

	do
	{
		printf("You have %d Coin's, do you want to turn the wheel Y/N\n", coin_count);
		char tmp_char = '\0';
		scanf("%c%c", &tmp_char);
		if (tmp_char == 'N' || tmp_char == 'n') break;
		if (tmp_char != 'Y' && tmp_char != 'y') continue;
		unsigned char spin_first = (rand() % 24) + 1, spin_second = (rand() % 24) + 1, spin_third = (rand() % 24) + 1;
		unsigned char sfc = 0, ssc = 0, stc = 0;
		while (spin_first > sfc || spin_second > ssc || spin_third > stc)
		{
			printf("\r%c %c %c", circles[sfc % 6].face, circles[ssc % 6].face, circles[stc % 6].face);
			if (spin_first >= sfc) sfc++;
			if (spin_second >= sfc) ssc++;
			if (spin_third >= sfc) stc++;
			fflush(stdout);
			sleep(1);
		}
		bool is_row = (sfc == ssc && stc == ssc);
		if (is_row)
			printf("\nYou got three %c in a row. You won %d Coin's\n", circles[sfc % 6].face, circles[sfc % 6].count);
		else
			printf("\nYou won nothing\n");
		coin_count -= REMOVED_COIN_COUNT;
		if (is_row) coin_count += circles[sfc % 6].count;
	}
	while (coin_count > 0);
	
	printf("Your total amount of coin's is %d\n", coin_count);	

	return 0;
}
