section .text
	global ft_read
	extern __errno_location

ft_read :
	cmp edi, 0
	jl _exit
	mov rax, 0	
	syscall
	cmp rax, 0
	jl _exit_sys
	mov rax, rdx
	ret

_exit_sys :
	mov rdi, rax
	neg rdi
	call __errno_location
	mov [rax], rdi

_exit :
	mov rax, -1
	ret
