global	_ft_puts
extern	_write


section .text

_ft_puts:
	cmp rdi, 0				; if rdi ptr == \0
	je is_null
	mov r8, rdi				; save rdi address
	xor r9, r9				; set count to 0

compare:
	cmp byte[rdi], 0		; if rdi ptr == \0
	je print
	jmp add_count

add_count:
	inc r9
	inc rdi					; set next char
	jmp compare

print:
	mov rdi, r8				; get initial ptr of rdi
	mov rax, 0x02000004		; system call for write
	mov rsi, rdi			; address of string to output
	mov rdi, 1				; file handle 1 is stdout
	mov rdx, r9				; number of bytes
	syscall
	mov rax, 0x02000004		; system call for write
	mov rdi, 1				; file handle 1 is stdout
	lea rsi, [rel newline]	; print \n
	mov rdx, 1
	syscall
	ret

is_null:
	mov rax, 0x02000004		; system call for write
	mov rdi, 1				; file handle 1 is stdout
	lea rsi, [rel null_print] ; address of string to output
	mov rdx, 7				; number of bytes
	syscall
	ret

section .data
	newline: db 10
	null_print: db "(null)", 10
