global	_ft_memset

section .text

_ft_memset:
	mov rax, rdi
	push rax
	mov rcx, rdx
	mov eax, esi
	rep stosb
	pop rax
	ret
