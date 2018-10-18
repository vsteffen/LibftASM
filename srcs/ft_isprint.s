global	_ft_isprint

section .text

_ft_isprint:
	cmp edi, 32
	jl ret_false
	cmp edi, 126
	jg ret_false
	mov rax, 1
	ret

ret_false:
	xor rax, rax
	ret
