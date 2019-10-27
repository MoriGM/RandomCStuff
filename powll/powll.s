.global powll
.text

powll:
	push %rbx
	mov $1, %rax
	mov $0, %rbx
	jmp powll_LC100

powll_LC0:
	inc %rbx
	mul %rdi

powll_LC100:
	cmp %rsi, %rbx
	jb powll_LC0

	pop %rbx	

	ret
