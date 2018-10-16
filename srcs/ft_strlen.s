global	_ft_strlen

section .text

_ft_strlen:
	xor rcx, rcx
	not rcx
	xor al, al
	repne scasb
	not rcx
	mov rax, rcx
	dec rax
	ret
