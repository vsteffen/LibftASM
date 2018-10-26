global	_ft_atoi
extern	_ft_isspace
extern	_ft_isdigit

section .text

_ft_atoi:
	push rbp
	mov	rbp, rsp

	mov r8, rdi ; array
	xor r9, r9 ; sign
	xor r10, r10 ; result

find_number:
	movsx edi, byte[r8]
	call _ft_isspace
	cmp rax, 0
	je get_sign
	cmp r8, 0
	je get_sign
	inc r8
	jmp find_number

get_sign:
	cmp byte[r8], 43
	je mov_after_sign
	cmp byte[r8], 45
	je sign_neg
	jmp extract_number

sign_neg:
	mov r9, 1

mov_after_sign:
	inc r8

extract_number:
	movsx edi, byte[r8]
	call _ft_isdigit
	cmp rax, 0
	je redetect_sign
	cmp r8, 0
	je redetect_sign

	mov rax, 10
	mul r10
	movsx r10, byte[r8]
	sub r10, 48
	add r10, rax

	inc r8
	jmp extract_number

redetect_sign:
	mov rax, r10
	cmp r9, 1
	jne exit
	neg rax

exit:
	mov	rsp, rbp
	pop	rbp
	ret
