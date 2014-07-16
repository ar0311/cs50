	.file	"mario.c"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	push	EBP
	mov	EBP, ESP
	push	EDI
	push	ESI
	sub	ESP, 48
	mov	DWORD PTR [EBP - 12], 0
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	mov	AL, 1
	cmp	DWORD PTR [EBP - 16], 23
	mov	BYTE PTR [EBP - 21], AL # 1-byte Spill
	jg	.LBB0_3
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	cmp	DWORD PTR [EBP - 16], 0
	setle	AL
	mov	BYTE PTR [EBP - 21], AL # 1-byte Spill
.LBB0_3:                                #   in Loop: Header=BB0_1 Depth=1
	mov	AL, BYTE PTR [EBP - 21] # 1-byte Reload
	test	AL, 1
	jne	.LBB0_4
	jmp	.LBB0_5
.LBB0_4:                                #   in Loop: Header=BB0_1 Depth=1
	lea	EAX, DWORD PTR [.L.str]
	mov	DWORD PTR [ESP], EAX
	call	printf
	mov	DWORD PTR [EBP - 28], EAX # 4-byte Spill
	call	GetInt
	mov	DWORD PTR [EBP - 16], EAX
	jmp	.LBB0_1
.LBB0_5:
	mov	DWORD PTR [EBP - 20], 2
.LBB0_6:                                # =>This Inner Loop Header: Depth=1
	cmp	DWORD PTR [EBP - 16], 0
	jle	.LBB0_8
# BB#7:                                 #   in Loop: Header=BB0_6 Depth=1
	lea	EAX, DWORD PTR [.L.str1]
	lea	ECX, DWORD PTR [.L.str2]
	lea	EDX, DWORD PTR [.L.str3]
	mov	ESI, DWORD PTR [EBP - 16]
	sub	ESI, 1
	mov	EDI, DWORD PTR [EBP - 20]
	mov	DWORD PTR [ESP], EAX
	mov	DWORD PTR [ESP + 4], ESI
	mov	DWORD PTR [ESP + 8], ECX
	mov	DWORD PTR [ESP + 12], EDI
	mov	DWORD PTR [ESP + 16], EDX
	call	printf
	mov	ECX, DWORD PTR [EBP - 16]
	add	ECX, 4294967295
	mov	DWORD PTR [EBP - 16], ECX
	mov	DWORD PTR [EBP - 32], EAX # 4-byte Spill
	jmp	.LBB0_6
.LBB0_8:
	mov	EAX, DWORD PTR [EBP - 12]
	add	ESP, 48
	pop	ESI
	pop	EDI
	pop	EBP
	ret
.Ltmp0:
	.size	main, .Ltmp0-main

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Height: "
	.size	.L.str, 9

	.type	.L.str1,@object         # @.str1
.L.str1:
	.asciz	 "%*s%*s\n"
	.size	.L.str1, 8

	.type	.L.str2,@object         # @.str2
.L.str2:
	.zero	1
	.size	.L.str2, 1

	.type	.L.str3,@object         # @.str3
.L.str3:
	.asciz	 "#"
	.size	.L.str3, 2


	.section	".note.GNU-stack","",@progbits
