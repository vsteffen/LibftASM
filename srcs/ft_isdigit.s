global	_ft_isdigit

section .text

_ft_isdigit:
	cmp edi, 48
	jl ret_false
	cmp edi, 57
	jg ret_false
	mov rax, 1
	ret

ret_false:
	xor rax, rax
	ret
