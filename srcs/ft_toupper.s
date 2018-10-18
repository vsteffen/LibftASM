global	_ft_toupper

section .text

_ft_toupper:
	mov eax, edi
	cmp edi, 97
	jl exit
	cmp edi, 122
	jg exit
	sub eax, 32

exit:
	ret
