global	_ft_bzero

section .text

_ft_bzero:
	xor rax, rax
	jmp cmp_length

inc_and_iter:
	mov byte[rdi], 0
	inc rax
	inc rdi

cmp_length:
	cmp rsi, rax
	jne inc_and_iter
	ret
