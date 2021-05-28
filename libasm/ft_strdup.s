section .text
	global ft_strdup
	extern ft_strlen
	extern malloc

ft_strdup :
	cmp rdi, 0
	je exit
	mov rbx, rdi
	call ft_strlen
	mov rdi, rax
	mov rdx, rax
	inc rdi
	call malloc
	cmp rax, 0
	je exit
	mov rdx, rax
	mov rdi, rbx
	call ft_strlen
	mov rdi, rax
	mov rax, rdx
loop :	
	
	mov dl, BYTE[rbx + rdi]
	mov BYTE[rax + rdi], dl
	dec rdi
	cmp rdi, -1
	jne loop
	ret

exit :
	mov rax, 0
	ret	
