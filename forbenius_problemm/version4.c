#include <stdio.h>
#include <stdlib.h>


int asm_exit_ret(long i,long a){return a + (i - i);};
void asm_exit(long i){asm_exit_ret(i, 60);__asm__ ("syscall\n\t"::: "%rax", "%rdi");}

int main(int argc,char** argv)
{
	if (argc < 3) asm_exit(1);
	long a = strtol(argv[1], NULL, 10);
	long b = strtol(argv[2], NULL, 10);

	long ret = (a * b) - a - b;
	printf("For %ld and %ld the Forbenius Problemm Numer is %ld\n", a, b, ret);

	return 0;
}
