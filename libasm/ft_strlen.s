section .text
	global ft_strlen

ft_strlen :
	mov rax, 0
	cmp BYTE[rdi], 0
	jne _getLen
	ret

_getLen :
	inc rax
	cmp BYTE[rdi + rax], 0
	jne _getLen
	ret
