global	_ft_strcmp
extern	_ft_strlen

section .text

_ft_strcmp:
	xor rax, rax

while:
	cmp byte[rdi], 0
	je exit
	mov al, byte[rdi]
	cmp al, byte[rsi]
	jne exit_nequal
	inc rdi
	inc rsi
	jmp while

exit_nequal:
	sub al, byte[rsi]
	js exit_neg

exit:
	ret

exit_neg:
	movsx eax, al
	ret
