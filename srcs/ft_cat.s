global	_ft_cat

section .text

_ft_cat:
	push rbp
	mov	rbp, rsp

	cmp edi, 0xFFFFFFFF
	je exit

	sub rsp, 0x428

	mov qword [rsp+0], rdi ; store fd

read:
	mov rax, 0x02000003
	mov rdi, qword [rsp+0] ; fd
	lea rsi, [rel rsp+16]
	mov rdx, 0x418
	syscall
	jc exit

print:
	mov qword[rsp+8], rax
	mov rdx, rax
	mov rax, 0x02000004
	mov rdi, 1
	lea rsi, [rel rsp+16] ; buffer
	syscall

	jc exit

	cmp qword[rsp+8], 0
	jne read

exit:
	mov	rsp, rbp
	pop	rbp
	ret
