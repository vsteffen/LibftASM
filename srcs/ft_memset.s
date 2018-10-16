global	_ft_memset

section .text

_ft_memset:
	mov rax, rdi
	mov rcx, rdx
	mov al, sil
	rep stosb
	ret
