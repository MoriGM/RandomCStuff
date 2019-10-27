.global powll
.text

powll:
	push %rsi
	mov $1, %rax
	xor $0, %rsi

	jmp powll_LC100

powll_LC0:
	dec %rsi
	mul %rdi

powll_LC100:
	jnz powll_LC0

	pop %rsi	

	ret
