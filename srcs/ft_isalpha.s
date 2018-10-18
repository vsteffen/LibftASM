global	_ft_isalpha

section .text

_ft_isalpha:
; upper
	cmp edi, 65
	jl ret_false
	cmp edi, 91
	jl ret_true

; lower
	cmp edi, 97
	jl ret_false
	cmp edi, 122
	jg ret_false

ret_true:
	mov rax, 1
	ret

ret_false:
	xor rax, rax
	ret
