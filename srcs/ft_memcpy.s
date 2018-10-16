global	_ft_memcpy

section .text

_ft_memcpy:
	mov rax, rdi
	mov rcx, rdx
	rep movsb
	ret
