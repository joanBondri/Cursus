section .text
	extern __errno_location
	global ft_write

ft_write :
	
	cmp edi, 0
	jl _exit
	mov rax, 1
	syscall
	cmp rax, 0
	jl	_exit_sys
	mov rax, rdx
	ret

_exit :
	mov rax, -1
	ret

_exit_sys :
	mov rsi, rax
	neg rsi
	call __errno_location
	mov [rax], rsi
	mov rax, -1
	ret
