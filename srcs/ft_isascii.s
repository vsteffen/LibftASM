global	_ft_isascii

section .text

_ft_isascii:
	cmp edi, 0
	jl ret_false
	cmp edi, 127
	jg ret_false
	mov rax, 1
	ret

ret_false:
	xor rax, rax
	ret
