global _start

section .data
	msg db "Hello, world!", 0x0a
	len equ $ - msg

section .text
_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, msg
	mov edx, len
	int 0x80 		; system call
	mov eax, 1
	mov ebx, 0
	int 0x80
	
