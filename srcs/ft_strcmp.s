global	_ft_strcmp
extern	_ft_strlen

section .text

_ft_strcmp:
	xor rax, rax
	cmp rdi, 0
	je str1_null
	cmp rsi, 0
	je str2_null

while:
	mov al, byte[rdi]
	cmp byte[rdi], 0
	je str1_end_or_not_equal
	cmp al, byte[rsi]
	jne str1_end_or_not_equal
	inc rdi
	inc rsi
	jmp while

str1_null:
	cmp rsi, 0
	je exit
	jmp str1_end_or_not_equal

str2_null:
	mov al, byte[rdi]
	ret

str1_end_or_not_equal:
	sub al, byte[rsi]
	jb exit_neg

exit:
	ret

exit_neg:
	movsx eax, al
	ret
