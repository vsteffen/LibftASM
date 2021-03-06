global	_ft_puts
extern	_ft_strlen

section .text

_ft_puts:
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

; print \n
	mov rax, 0x02000004
	mov rdi, 1
	lea rsi, [rel newline]
	mov rdx, 1
	syscall
	jmp exit

ptr_is_null:
	mov rax, 0x02000004
	mov rdi, 1
	lea rsi, [rel null_print]
	mov rdx, 7
	syscall

exit:
	mov	rsp, rbp
	pop	rbp
	ret

section .data
	newline: db 10
	null_print: db "(null)", 10
