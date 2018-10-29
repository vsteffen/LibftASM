global	_ft_putstr
extern	_ft_strlen

section .text

_ft_putstr:
	push rbp
	mov	rbp, rsp

	cmp rdi, 0
	je ptr_is_null
	push rdi
	push rdi ; stack align
	call _ft_strlen
	pop rdi
	pop rdi

; print rdi
	mov rdx, rax ; 3rd arg
	mov rax, 0x02000004 ; syscall
	mov rsi, rdi ; 2nd arg
	mov rdi, 1 ; 1st arg
	syscall
	jmp exit

ptr_is_null:
	mov rax, 0x02000004
	mov rdi, 1
	lea rsi, [rel null_print]
	mov rdx, 6
	syscall

exit:
	mov	rsp, rbp
	pop	rbp
	ret

section .data
	null_print: db "(null)"
