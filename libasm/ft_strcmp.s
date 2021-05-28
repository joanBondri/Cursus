section .text
	global ft_strcmp

ft_strcmp :
	mov rax, 0
	cmp rdi, 0
	je frexit
	cmp rsi, 0
	je frexit
	dec rdi
	dec rsi
	jmp _cmpLoop
	ret

_cmpLoop :
	inc rdi
	inc rsi
	cmp BYTE[rdi], 0
	je end
	cmp BYTE[rsi], 0
	je end
	mov cl, BYTE[rdi]
	mov dl, BYTE[rsi]
	cmp cl, dl
	je _cmpLoop
	call end

end : 
	movzx rcx, BYTE[rdi]
	movzx rdx, BYTE[rsi]
	mov rax, rcx
	sub rax, rdx
	ret
frexit :
	mov rax, -1
	ret
