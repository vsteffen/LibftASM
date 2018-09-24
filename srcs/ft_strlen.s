global	_ft_strlen

section .text

_ft_strlen:
	xor rax, rax
	jmp cmp_null_char

inc_and_iter:
	inc rax
	inc rdi

cmp_null_char:
	cmp byte[rdi], 0
	jne inc_and_iter
	ret
