global	_ft_isalnum

section .text

_ft_isalnum:
; digit
	cmp edi, 48
	jl ret_false
	cmp edi, 58
	jl ret_false

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
