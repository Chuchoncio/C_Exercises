	.file	"main.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.globl	MyStrCLen
	.def	MyStrCLen;	.scl	2;	.type	32;	.endef
	.seh_proc	MyStrCLen
MyStrCLen:
.LFB17:
	.file 1 "D:/Facultad en Cuarentena/Programacion I/Ejercicios/Unidad 2/Ejercicio_16/main.c"
	.loc 1 4 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, %eax
	movb	%al, 24(%rbp)
	.loc 1 9 11
	movq	16(%rbp), %rax
	movq	%rax, -8(%rbp)
	.loc 1 10 9
	movl	$0, -12(%rbp)
	.loc 1 12 10
	jmp	.L2
.L4:
	.loc 1 14 14
	addl	$1, -12(%rbp)
	.loc 1 15 12
	addq	$1, -8(%rbp)
.L2:
	.loc 1 12 11
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 12 10
	testb	%al, %al
	je	.L3
	.loc 1 12 19 discriminator 1
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 12 16 discriminator 1
	cmpb	$32, %al
	jne	.L4
.L3:
	.loc 1 18 12
	movl	-12(%rbp), %eax
	.loc 1 19 1
	addq	$16, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "rt\0"
.LC1:
	.ascii "archtext.txt\0"
.LC2:
	.ascii "Ingrese subcadena: \0"
	.align 8
.LC3:
	.ascii "Formadas por una sola letra: %d\12Formadas por una cantidad par de letras: %d\12Comienzan con 'n': %d\12Comienzan con %s: %d\12Tienen mas de tres vocales: %d\12Comienzan y terminan con vocales: %d\12Contienen digitos: %d\12Solo estan formadas por digitos: %d\12Son palindromos: %d\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB18:
	.loc 1 29 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	subq	$304, %rsp
	.seh_stackalloc	304
	.cfi_def_cfa_offset 320
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.cfi_def_cfa 6, 192
	.seh_endprologue
	.loc 1 29 1
	call	__main
.LVL0:
	.loc 1 32 9
	movl	$0, 148(%rbp)
	.loc 1 32 30
	movl	$0, 144(%rbp)
	.loc 1 33 9
	movl	$0, 140(%rbp)
	.loc 1 33 29
	movl	$0, 136(%rbp)
	.loc 1 34 9
	movl	$0, 132(%rbp)
	.loc 1 34 31
	movl	$0, 128(%rbp)
	.loc 1 35 9
	movl	$0, 124(%rbp)
	.loc 1 35 30
	movl	$0, 120(%rbp)
	.loc 1 36 9
	movl	$0, 116(%rbp)
	.loc 1 37 9
	movl	$0, 112(%rbp)
	.loc 1 37 33
	movl	$0, 108(%rbp)
	.loc 1 37 50
	movl	$0, 104(%rbp)
	.loc 1 38 9
	movl	$0, 100(%rbp)
	.loc 1 38 26
	movl	$0, 92(%rbp)
	.loc 1 40 10
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, 80(%rbp)
	.loc 1 42 7
	cmpq	$0, 80(%rbp)
	jne	.L7
	.loc 1 43 9
	movl	$1, %ecx
	call	exit
.L7:
	.loc 1 45 5
	leaq	.LC2(%rip), %rcx
	call	puts
	.loc 1 46 5
	leaq	71(%rbp), %rax
	movq	%rax, %rcx
	call	gets
	.loc 1 48 17
	leaq	71(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	.loc 1 48 15
	movl	%eax, 76(%rbp)
	.loc 1 52 10
	jmp	.L8
.L27:
	.loc 1 54 17
	leaq	-32(%rbp), %rax
	movq	%rax, 160(%rbp)
	.loc 1 55 17
	leaq	71(%rbp), %rax
	movq	%rax, 168(%rbp)
	.loc 1 57 22
	movq	160(%rbp), %rax
	movl	$32, %edx
	movq	%rax, %rcx
	call	MyStrCLen
	movl	%eax, 92(%rbp)
	.loc 1 58 24
	movq	160(%rbp), %rax
	movl	$32, %edx
	movq	%rax, %rcx
	call	strchr
	.loc 1 58 21
	subq	$1, %rax
	movq	%rax, 152(%rbp)
	.loc 1 60 14
	jmp	.L9
.L20:
	.loc 1 62 25
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 62 16
	movzbl	(%rax), %eax
	.loc 1 62 15
	cmpb	$32, %al
	jne	.L10
	.loc 1 62 48 discriminator 1
	movq	160(%rbp), %rax
	addq	$1, %rax
	.loc 1 62 39 discriminator 1
	movzbl	(%rax), %eax
	.loc 1 62 36 discriminator 1
	cmpb	$32, %al
	jne	.L10
	.loc 1 63 32
	addl	$1, 148(%rbp)
.L10:
	.loc 1 65 16
	movq	152(%rbp), %rax
	movzbl	(%rax), %edx
	.loc 1 65 32
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 65 15
	cmpb	%al, %dl
	jne	.L11
	.loc 1 67 28
	subq	$1, 152(%rbp)
	.loc 1 68 30
	movl	$1, 96(%rbp)
	jmp	.L12
.L11:
	.loc 1 71 30
	movl	$0, 96(%rbp)
.L12:
	.loc 1 73 16
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 73 15
	cmpb	$110, %al
	jne	.L13
	.loc 1 73 44 discriminator 1
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 73 35 discriminator 1
	movzbl	(%rax), %eax
	.loc 1 73 32 discriminator 1
	cmpb	$32, %al
	jne	.L13
	.loc 1 74 31
	addl	$1, 140(%rbp)
.L13:
	.loc 1 76 16
	movq	160(%rbp), %rax
	movzbl	(%rax), %edx
	.loc 1 76 28
	movq	168(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 76 15
	cmpb	%al, %dl
	jne	.L14
	.loc 1 77 24
	addq	$1, 168(%rbp)
	jmp	.L15
.L14:
	.loc 1 78 21
	movq	168(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 78 20
	testb	%al, %al
	jne	.L15
	.loc 1 79 33
	addl	$1, 136(%rbp)
.L15:
	.loc 1 81 19
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 15
	cmpb	$65, %al
	je	.L16
	.loc 1 81 40 discriminator 1
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 36 discriminator 1
	cmpb	$69, %al
	je	.L16
	.loc 1 81 61 discriminator 2
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 57 discriminator 2
	cmpb	$73, %al
	je	.L16
	.loc 1 81 82 discriminator 3
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 78 discriminator 3
	cmpb	$79, %al
	je	.L16
	.loc 1 81 103 discriminator 4
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 99 discriminator 4
	cmpb	$85, %al
	je	.L16
	.loc 1 81 124 discriminator 5
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 120 discriminator 5
	cmpb	$97, %al
	je	.L16
	.loc 1 81 145 discriminator 6
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 141 discriminator 6
	cmpb	$101, %al
	je	.L16
	.loc 1 81 166 discriminator 7
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 162 discriminator 7
	cmpb	$105, %al
	je	.L16
	.loc 1 81 187 discriminator 8
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 183 discriminator 8
	cmpb	$111, %al
	je	.L16
	.loc 1 81 208 discriminator 9
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 81 16 discriminator 9
	cmpb	$117, %al
	je	.L16
	.loc 1 82 28
	addl	$1, 108(%rbp)
.L16:
	.loc 1 84 25
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 84 16
	movzbl	(%rax), %eax
	.loc 1 84 15
	cmpb	$32, %al
	jne	.L17
	.loc 1 84 42 discriminator 1
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 36 discriminator 1
	cmpb	$65, %al
	je	.L17
	.loc 1 84 63 discriminator 2
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 59 discriminator 2
	cmpb	$69, %al
	je	.L17
	.loc 1 84 84 discriminator 3
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 80 discriminator 3
	cmpb	$73, %al
	je	.L17
	.loc 1 84 105 discriminator 4
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 101 discriminator 4
	cmpb	$79, %al
	je	.L17
	.loc 1 84 126 discriminator 5
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 122 discriminator 5
	cmpb	$85, %al
	je	.L17
	.loc 1 84 147 discriminator 6
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 143 discriminator 6
	cmpb	$97, %al
	je	.L17
	.loc 1 84 168 discriminator 7
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 164 discriminator 7
	cmpb	$101, %al
	je	.L17
	.loc 1 84 189 discriminator 8
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 185 discriminator 8
	cmpb	$105, %al
	je	.L17
	.loc 1 84 210 discriminator 9
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 206 discriminator 9
	cmpb	$111, %al
	je	.L17
	.loc 1 84 231 discriminator 10
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 84 36 discriminator 10
	cmpb	$117, %al
	je	.L17
	.loc 1 85 29
	movl	$1, 104(%rbp)
.L17:
	.loc 1 87 19
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 87 15
	cmpb	$47, %al
	jle	.L18
	.loc 1 87 39 discriminator 1
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 87 16 discriminator 1
	cmpb	$57, %al
	jle	.L19
.L18:
	.loc 1 88 28
	addl	$1, 100(%rbp)
.L19:
	.loc 1 90 20
	addl	$1, 112(%rbp)
	.loc 1 91 20
	addq	$1, 160(%rbp)
.L9:
	.loc 1 60 15
	movq	160(%rbp), %rax
	movzbl	(%rax), %eax
	.loc 1 60 14
	cmpb	$32, %al
	jne	.L20
	.loc 1 94 24
	movl	112(%rbp), %eax
	andl	$1, %eax
	.loc 1 94 11
	testl	%eax, %eax
	jne	.L21
	.loc 1 95 27
	addl	$1, 144(%rbp)
.L21:
	.loc 1 97 11
	cmpl	$3, 108(%rbp)
	jle	.L22
	.loc 1 98 29
	addl	$1, 132(%rbp)
.L22:
	.loc 1 100 11
	cmpl	$0, 104(%rbp)
	je	.L23
	.loc 1 100 39 discriminator 1
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 30 discriminator 1
	movzbl	(%rax), %eax
	.loc 1 100 24 discriminator 1
	cmpb	$65, %al
	je	.L23
	.loc 1 100 64 discriminator 2
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 55 discriminator 2
	movzbl	(%rax), %eax
	.loc 1 100 51 discriminator 2
	cmpb	$69, %al
	je	.L23
	.loc 1 100 89 discriminator 3
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 80 discriminator 3
	movzbl	(%rax), %eax
	.loc 1 100 76 discriminator 3
	cmpb	$73, %al
	je	.L23
	.loc 1 100 114 discriminator 4
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 105 discriminator 4
	movzbl	(%rax), %eax
	.loc 1 100 101 discriminator 4
	cmpb	$79, %al
	je	.L23
	.loc 1 100 139 discriminator 5
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 130 discriminator 5
	movzbl	(%rax), %eax
	.loc 1 100 126 discriminator 5
	cmpb	$85, %al
	je	.L23
	.loc 1 100 164 discriminator 6
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 155 discriminator 6
	movzbl	(%rax), %eax
	.loc 1 100 151 discriminator 6
	cmpb	$97, %al
	je	.L23
	.loc 1 100 189 discriminator 7
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 180 discriminator 7
	movzbl	(%rax), %eax
	.loc 1 100 176 discriminator 7
	cmpb	$101, %al
	je	.L23
	.loc 1 100 214 discriminator 8
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 205 discriminator 8
	movzbl	(%rax), %eax
	.loc 1 100 201 discriminator 8
	cmpb	$105, %al
	je	.L23
	.loc 1 100 239 discriminator 9
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 230 discriminator 9
	movzbl	(%rax), %eax
	.loc 1 100 226 discriminator 9
	cmpb	$111, %al
	je	.L23
	.loc 1 100 264 discriminator 10
	movq	160(%rbp), %rax
	subq	$1, %rax
	.loc 1 100 255 discriminator 10
	movzbl	(%rax), %eax
	.loc 1 100 24 discriminator 10
	cmpb	$117, %al
	je	.L23
	.loc 1 101 28
	addl	$1, 128(%rbp)
.L23:
	.loc 1 103 11
	movl	92(%rbp), %eax
	cmpl	100(%rbp), %eax
	jne	.L24
	.loc 1 104 29
	addl	$1, 120(%rbp)
	jmp	.L25
.L24:
	.loc 1 105 16
	cmpl	$0, 100(%rbp)
	jle	.L25
	.loc 1 106 28
	addl	$1, 124(%rbp)
.L25:
	.loc 1 108 11
	cmpl	$0, 96(%rbp)
	je	.L26
	.loc 1 109 30
	addl	$1, 116(%rbp)
.L26:
	.loc 1 111 20
	movl	$0, 92(%rbp)
	.loc 1 112 21
	movl	$0, 108(%rbp)
	.loc 1 113 17
	movl	$0, 112(%rbp)
	.loc 1 115 17
	movl	76(%rbp), %eax
	cltq
	negq	%rax
	addq	%rax, 168(%rbp)
	.loc 1 116 16
	addq	$1, 160(%rbp)
.L8:
	.loc 1 52 11
	movq	80(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %r8
	movl	$100, %edx
	movq	%rax, %rcx
	call	fgets
	.loc 1 52 10
	testq	%rax, %rax
	jne	.L27
	.loc 1 119 5
	movl	140(%rbp), %r8d
	movl	144(%rbp), %ecx
	movl	148(%rbp), %edx
	movl	116(%rbp), %eax
	movl	%eax, 80(%rsp)
	movl	120(%rbp), %eax
	movl	%eax, 72(%rsp)
	movl	124(%rbp), %eax
	movl	%eax, 64(%rsp)
	movl	128(%rbp), %eax
	movl	%eax, 56(%rsp)
	movl	132(%rbp), %eax
	movl	%eax, 48(%rsp)
	movl	136(%rbp), %eax
	movl	%eax, 40(%rsp)
	leaq	71(%rbp), %rax
	movq	%rax, 32(%rsp)
	movl	%r8d, %r9d
	movl	%ecx, %r8d
	leaq	.LC3(%rip), %rcx
	call	printf
	.loc 1 134 5
	movq	80(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	.loc 1 136 12
	movl	$0, %eax
	.loc 1 137 1
	addq	$304, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, -296
	ret
	.cfi_endproc
.LFE18:
	.seh_endproc
.Letext0:
	.file 2 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/stdio.h"
	.file 3 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/crtdefs.h"
	.file 4 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/stdlib.h"
	.file 5 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/malloc.h"
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0x6b4
	.word	0x4
	.secrel32	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.ascii "GNU C17 8.1.0 -mtune=core2 -march=nocona -g\0"
	.byte	0xc
	.ascii "D:\\Facultad en Cuarentena\\Programacion I\\Ejercicios\\Unidad 2\\Ejercicio_16\\main.c\0"
	.ascii "D:\\\\Facultad en Cuarentena\\\\Programacion I\\\\Ejercicios\\\\Unidad 2\\\\Ejercicio_16\0"
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.secrel32	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.ascii "char\0"
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.ascii "long long unsigned int\0"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.ascii "long long int\0"
	.uleb128 0x3
	.ascii "wchar_t\0"
	.byte	0x3
	.byte	0x62
	.byte	0x18
	.long	0x130
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0x4
	.byte	0x8
	.long	0xed
	.uleb128 0x4
	.byte	0x8
	.long	0x120
	.uleb128 0x4
	.byte	0x8
	.long	0x146
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "long unsigned int\0"
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.ascii "unsigned char\0"
	.uleb128 0x5
	.ascii "_iobuf\0"
	.byte	0x30
	.byte	0x2
	.byte	0x1a
	.byte	0xa
	.long	0x231
	.uleb128 0x6
	.ascii "_ptr\0"
	.byte	0x2
	.byte	0x1b
	.byte	0xb
	.long	0x159
	.byte	0
	.uleb128 0x6
	.ascii "_cnt\0"
	.byte	0x2
	.byte	0x1c
	.byte	0x9
	.long	0x146
	.byte	0x8
	.uleb128 0x6
	.ascii "_base\0"
	.byte	0x2
	.byte	0x1d
	.byte	0xb
	.long	0x159
	.byte	0x10
	.uleb128 0x6
	.ascii "_flag\0"
	.byte	0x2
	.byte	0x1e
	.byte	0x9
	.long	0x146
	.byte	0x18
	.uleb128 0x6
	.ascii "_file\0"
	.byte	0x2
	.byte	0x1f
	.byte	0x9
	.long	0x146
	.byte	0x1c
	.uleb128 0x6
	.ascii "_charbuf\0"
	.byte	0x2
	.byte	0x20
	.byte	0x9
	.long	0x146
	.byte	0x20
	.uleb128 0x6
	.ascii "_bufsiz\0"
	.byte	0x2
	.byte	0x21
	.byte	0x9
	.long	0x146
	.byte	0x24
	.uleb128 0x6
	.ascii "_tmpfname\0"
	.byte	0x2
	.byte	0x22
	.byte	0xb
	.long	0x159
	.byte	0x28
	.byte	0
	.uleb128 0x3
	.ascii "FILE\0"
	.byte	0x2
	.byte	0x24
	.byte	0x19
	.long	0x1a1
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.ascii "double\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x4
	.ascii "float\0"
	.uleb128 0x2
	.byte	0x10
	.byte	0x4
	.ascii "long double\0"
	.uleb128 0x7
	.ascii "__imp___mb_cur_max\0"
	.byte	0x4
	.byte	0x73
	.byte	0x10
	.long	0x165
	.uleb128 0x8
	.long	0x159
	.long	0x28b
	.uleb128 0x9
	.long	0xf5
	.byte	0
	.byte	0
	.uleb128 0x7
	.ascii "_sys_errlist\0"
	.byte	0x4
	.byte	0xac
	.byte	0x2b
	.long	0x27b
	.uleb128 0x7
	.ascii "_sys_nerr\0"
	.byte	0x4
	.byte	0xad
	.byte	0x29
	.long	0x146
	.uleb128 0xa
	.ascii "__imp___argc\0"
	.byte	0x4
	.word	0x119
	.byte	0x10
	.long	0x165
	.uleb128 0xa
	.ascii "__imp___argv\0"
	.byte	0x4
	.word	0x11d
	.byte	0x13
	.long	0x2de
	.uleb128 0x4
	.byte	0x8
	.long	0x2e4
	.uleb128 0x4
	.byte	0x8
	.long	0x159
	.uleb128 0xa
	.ascii "__imp___wargv\0"
	.byte	0x4
	.word	0x121
	.byte	0x16
	.long	0x301
	.uleb128 0x4
	.byte	0x8
	.long	0x307
	.uleb128 0x4
	.byte	0x8
	.long	0x15f
	.uleb128 0xa
	.ascii "__imp__environ\0"
	.byte	0x4
	.word	0x127
	.byte	0x13
	.long	0x2de
	.uleb128 0xa
	.ascii "__imp__wenviron\0"
	.byte	0x4
	.word	0x12c
	.byte	0x16
	.long	0x301
	.uleb128 0xa
	.ascii "__imp__pgmptr\0"
	.byte	0x4
	.word	0x132
	.byte	0x12
	.long	0x2e4
	.uleb128 0xa
	.ascii "__imp__wpgmptr\0"
	.byte	0x4
	.word	0x137
	.byte	0x15
	.long	0x307
	.uleb128 0xa
	.ascii "__imp__osplatform\0"
	.byte	0x4
	.word	0x13c
	.byte	0x19
	.long	0x388
	.uleb128 0x4
	.byte	0x8
	.long	0x16b
	.uleb128 0xa
	.ascii "__imp__osver\0"
	.byte	0x4
	.word	0x141
	.byte	0x19
	.long	0x388
	.uleb128 0xa
	.ascii "__imp__winver\0"
	.byte	0x4
	.word	0x146
	.byte	0x19
	.long	0x388
	.uleb128 0xa
	.ascii "__imp__winmajor\0"
	.byte	0x4
	.word	0x14b
	.byte	0x19
	.long	0x388
	.uleb128 0xa
	.ascii "__imp__winminor\0"
	.byte	0x4
	.word	0x150
	.byte	0x19
	.long	0x388
	.uleb128 0x7
	.ascii "_amblksiz\0"
	.byte	0x5
	.byte	0x35
	.byte	0x17
	.long	0x16b
	.uleb128 0xb
	.ascii "main\0"
	.byte	0x1
	.byte	0x1c
	.byte	0x5
	.long	0x146
	.quad	.LFB18
	.quad	.LFE18-.LFB18
	.uleb128 0x1
	.byte	0x9c
	.long	0x630
	.uleb128 0xc
	.ascii "subCad\0"
	.byte	0x1
	.byte	0x1e
	.byte	0xa
	.long	0x630
	.uleb128 0x3
	.byte	0x91
	.sleb128 -121
	.uleb128 0xc
	.ascii "pSubCad\0"
	.byte	0x1
	.byte	0x1e
	.byte	0x16
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xc
	.ascii "buffer\0"
	.byte	0x1
	.byte	0x1e
	.byte	0x1f
	.long	0x640
	.uleb128 0x3
	.byte	0x91
	.sleb128 -224
	.uleb128 0xc
	.ascii "pBuffer\0"
	.byte	0x1
	.byte	0x1e
	.byte	0x2d
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xc
	.ascii "pFinPalabra\0"
	.byte	0x1
	.byte	0x1e
	.byte	0x37
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xc
	.ascii "pf\0"
	.byte	0x1
	.byte	0x1f
	.byte	0xb
	.long	0x650
	.uleb128 0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0xc
	.ascii "cantPalUnaLetra\0"
	.byte	0x1
	.byte	0x20
	.byte	0x9
	.long	0x146
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0xc
	.ascii "cantPalCantPar\0"
	.byte	0x1
	.byte	0x20
	.byte	0x1e
	.long	0x146
	.uleb128 0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xc
	.ascii "cantPalComConN\0"
	.byte	0x1
	.byte	0x21
	.byte	0x9
	.long	0x146
	.uleb128 0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0xc
	.ascii "cantPalComConCad\0"
	.byte	0x1
	.byte	0x21
	.byte	0x1d
	.long	0x146
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xc
	.ascii "cantPalTresVocal\0"
	.byte	0x1
	.byte	0x22
	.byte	0x9
	.long	0x146
	.uleb128 0x2
	.byte	0x91
	.sleb128 -60
	.uleb128 0xc
	.ascii "cantPalCyTVocal\0"
	.byte	0x1
	.byte	0x22
	.byte	0x1f
	.long	0x146
	.uleb128 0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xc
	.ascii "cantPalConDigit\0"
	.byte	0x1
	.byte	0x23
	.byte	0x9
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -68
	.uleb128 0xc
	.ascii "cantPalSoloDigit\0"
	.byte	0x1
	.byte	0x23
	.byte	0x1e
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0xc
	.ascii "cantPalPalindromo\0"
	.byte	0x1
	.byte	0x24
	.byte	0x9
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -76
	.uleb128 0xc
	.ascii "paridad\0"
	.byte	0x1
	.byte	0x25
	.byte	0x9
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0xc
	.ascii "tamSubCad\0"
	.byte	0x1
	.byte	0x25
	.byte	0x16
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -116
	.uleb128 0xc
	.ascii "tresVocales\0"
	.byte	0x1
	.byte	0x25
	.byte	0x21
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -84
	.uleb128 0xc
	.ascii "comConVocal\0"
	.byte	0x1
	.byte	0x25
	.byte	0x32
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -88
	.uleb128 0xc
	.ascii "cantDigitos\0"
	.byte	0x1
	.byte	0x26
	.byte	0x9
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -92
	.uleb128 0xc
	.ascii "cantLetras\0"
	.byte	0x1
	.byte	0x26
	.byte	0x1a
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -100
	.uleb128 0xc
	.ascii "esPalindromo\0"
	.byte	0x1
	.byte	0x26
	.byte	0x2a
	.long	0x146
	.uleb128 0x3
	.byte	0x91
	.sleb128 -96
	.byte	0
	.uleb128 0x8
	.long	0xed
	.long	0x640
	.uleb128 0x9
	.long	0xf5
	.byte	0x4
	.byte	0
	.uleb128 0x8
	.long	0xed
	.long	0x650
	.uleb128 0x9
	.long	0xf5
	.byte	0x63
	.byte	0
	.uleb128 0x4
	.byte	0x8
	.long	0x231
	.uleb128 0xd
	.ascii "MyStrCLen\0"
	.byte	0x1
	.byte	0x3
	.byte	0x5
	.long	0x146
	.quad	.LFB17
	.quad	.LFE17-.LFB17
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xe
	.ascii "cad\0"
	.byte	0x1
	.byte	0x3
	.byte	0x15
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xe
	.ascii "c\0"
	.byte	0x1
	.byte	0x3
	.byte	0x1f
	.long	0xed
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0xc
	.ascii "str\0"
	.byte	0x1
	.byte	0x9
	.byte	0xb
	.long	0x159
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xc
	.ascii "cantC\0"
	.byte	0x1
	.byte	0xa
	.byte	0x9
	.long	0x146
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.byte	0
	.section	.debug_abbrev,"dr"
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1b
	.uleb128 0x8
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"dr"
	.long	0x2c
	.word	0x2
	.secrel32	.Ldebug_info0
	.byte	0x8
	.byte	0
	.word	0
	.word	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	gets;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	strchr;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
