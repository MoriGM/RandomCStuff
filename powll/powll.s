.global powll
.text

powll:
	push %rbx
	mov $1, %rax
	mov $0, %rbx
	jmp powll_LC100

powll_LC0:
	inc %r10
	mul %rdi

powll_LC100:
	cmp %rsi, %r10
	jb powll_LC0

	pop %rbx	

	ret
