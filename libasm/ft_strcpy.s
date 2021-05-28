section .text
    global ft_strcpy

ft_strcpy : 
	mov rbx, 0
	mov rcx, 0
	jmp _corps

_incr : 
	inc rcx

_corps :
	mov bl, BYTE[rsi + rcx]
	mov BYTE[rdi + rcx], bl
	cmp bl, 0
	jne _incr

exit :
	mov rax, rdi
    ret
