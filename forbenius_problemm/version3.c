#include <stdio.h>
#include <stdlib.h>

void asm_exit(long i)
{
	__asm__ (
		"movq $60, %%rax\n\t"
		"syscall\n\t"
		:: "r" (i) : "%rax", "%rdi");
}

int main(int argc,char** argv)
{
	if (argc < 3) asm_exit(1);
	long a = strtol(argv[1], NULL, 10);
	long b = strtol(argv[2], NULL, 10);

	long ret = (a * b) - a - b;
	printf("For %ld and %ld the Forbenius Problemm Numer is %ld\n", a, b, ret);

	return 0;
}
