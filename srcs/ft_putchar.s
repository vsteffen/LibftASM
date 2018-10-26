global	_ft_putchar

section .text

_ft_putchar:
	push rbp
	mov	rbp, rsp

	sub rsp, 0x10

	mov byte [rsp], dil
	mov rax, 0x02000004
	mov rdi, 1
	mov rsi, rsp
	mov rdx, 1
	syscall

	mov	rsp, rbp
	pop	rbp
	ret
