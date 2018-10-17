global	_ft_strcat
extern	_ft_strlen

section .text

_ft_strcat:
	push rbp
	mov	rbp, rsp

	push rdi
	push rsi
	call _ft_strlen
	pop rsi
	pop rdi

	mov rcx, rdi
	add rdi, rax
	jmp can_iter

inc_and_iter:
	mov dl, byte[rsi]
	mov byte[rdi], dl
	inc rdi
	inc rsi

can_iter:
	cmp byte[rsi], 0
	jne inc_and_iter
	mov byte[rdi], 0

	mov rax, rcx
	mov	rsp, rbp
	pop	rbp
	ret
