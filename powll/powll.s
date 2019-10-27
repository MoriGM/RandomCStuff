.global powll
.text

powll:
	push %rsi
	mov $1, %rax
	jmp powll_LC100

powll_LC0:
	dec %rsi
	mul %rdi

powll_LC100:
	cmp $0, %rsi
	jne powll_LC0

	pop %rsi	

	ret
