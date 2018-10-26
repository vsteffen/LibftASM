global	_ft_putstr
extern	_ft_strlen

section .text

_ft_putstr:
	cmp rdi, 0
	je ptr_is_null
	push rdi
	call _ft_strlen
	pop rdi

; print rdi
	mov rdx, rax ; 3rd arg
	mov rax, 0x02000004 ; syscall
	mov rsi, rdi ; 2nd arg
	mov rdi, 1 ; 1st arg
	syscall
	ret

ptr_is_null:
	mov rax, 0x02000004
	mov rdi, 1
	lea rsi, [rel null_print]
	mov rdx, 6
	syscall
	ret

section .data
	null_print: db "(null)"
