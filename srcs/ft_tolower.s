global	_ft_tolower

section .text

_ft_tolower:
	mov eax, edi
	cmp edi, 65
	jl exit
	cmp edi, 90
	jg exit
	add eax, 32

exit:
	ret
