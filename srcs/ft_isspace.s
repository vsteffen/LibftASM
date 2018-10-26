global	_ft_isspace

section .text

_ft_isspace:
	cmp edi, 32
	je ret_true
	cmp edi, 9
	jl ret_false
	cmp edi, 13
	jg ret_false
	jmp ret_true

ret_false:
	xor rax, rax
	ret

ret_true:
	mov rax, 1
	ret
