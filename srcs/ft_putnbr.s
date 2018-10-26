global	_ft_putnbr
extern _ft_putchar

section .text

_ft_putnbr:
	push rbp
	mov	rbp, rsp
	sub rsp, 0x20

	mov rsi, 8 ; pos str
	mov r9, 1 ; nb numeral ; r10 use to resave it
	mov r8, 1 ; pow 10
	xor r11, r11 ; length for sign '-'
	mov qword [rsp+0], rdi ; store nb
	mov rax, 0x8000000000000000
	bt rdi, 63
	jc add_neg_sign
	jmp count_numeral

add_neg_sign:
	neg rdi
	; mov byte [rsp+31], 1
	mov byte [rsp+rsi], 45
	mov qword [rsp+0], rdi
	inc rsi
	inc r11

count_numeral:
	cmp qword [rsp+0], 10
	jl before_while
	xor rdx, rdx
	mov rax, qword [rsp+0]
	mov rcx, 10
	div rcx
	mov qword [rsp+0], rax
	inc r9
	jmp count_numeral

before_while:
	mov qword [rsp+0], rdi
	mov r10, r9 ; to save nb numeral

get_pow_numeral:
	cmp r9, 1
	je while
	mov rax, 10
	mul r8
	mov r8, rax
	dec r9
	jmp get_pow_numeral

while:
	cmp r8, 1
	je last_digit

; div number by pow
	xor rdx, rdx
	mov rax, qword [rsp+0]
	mov rcx, r8
	div rcx
	mov qword [rsp+0], rax

	mov byte[rsp+rsi], al
	add byte[rsp+rsi], 48

;remove pow digit (ex: 423 /100 -> 23 / 100)
	mov rax, r8
	mul qword[rsp+0]
	sub rdi, rax

; div pow by 10
	xor rdx, rdx
	mov rax, r8
	mov rcx, 10
	div rcx
	mov r8, rax

	inc rsi
	mov qword [rsp+0], rdi
	jmp while

last_digit:
	mov rax, qword[rsp+0]
	mov byte[rsp+rsi], al
	add byte[rsp+rsi], 48

print_nb:
	mov rax, 0x02000004
	mov rdi, 1
	mov rsi, rsp
	add rsi, 8
	add r10, r11
	mov rdx, r10
	syscall

exit:
	mov	rsp, rbp
	pop	rbp
	ret
