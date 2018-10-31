global	_ft_strdup
extern	_ft_strlen
extern	_ft_memcpy
extern	_malloc

section .text

_ft_strdup:
	push rbp
	mov	rbp, rsp
	sub rsp, 0x10

	mov qword[rsp+8], rdi
	call _ft_strlen
	inc rax
	mov qword[rsp+0], rax ; store length in stack

; malloc call
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je exit

; ft_memcpy call
	mov rdi, rax
	mov rsi, qword[rsp+8]
	mov rdx, qword[rsp+0]
	call _ft_memcpy

exit:
	mov	rsp, rbp
	pop	rbp
	ret
