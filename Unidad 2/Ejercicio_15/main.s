	.file	"main.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "se\0"
.LC1:
	.ascii "rt\0"
.LC2:
	.ascii "archtext.txt\0"
.LC3:
	.ascii "Nro Linea: %d - Pos: %d\12\0"
.LC4:
	.ascii "PAUSE\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB17:
	.file 1 "D:/Facultad en Cuarentena/Programacion I/Ejercicios/Unidad 2/Ejercicio_15/main.c"
	.loc 1 4 1
	.cfi_startproc
	pushq	%rbp
	.seh_pushreg	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.cfi_def_cfa_register 6
	subq	$192, %rsp
	.seh_stackalloc	192
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	.loc 1 4 1
	call	__main
.LVL0:
	.loc 1 5 5
	call	generarArchivo
	.loc 1 6 5
	call	agregarTexto
	.loc 1 15 32
	leaq	.LC0(%rip), %rax
	movq	%rax, -24(%rbp)
	.loc 1 16 9
	movl	$1, -12(%rbp)
	.loc 1 16 37
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	strlen
	.loc 1 16 27
	movl	%eax, -28(%rbp)
	.loc 1 18 10
	leaq	.LC1(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	fopen
	movq	%rax, -40(%rbp)
	.loc 1 20 7
	cmpq	$0, -40(%rbp)
	jne	.L3
	.loc 1 21 9
	movl	$1, %ecx
	call	exit
.L6:
	.loc 1 25 14
	movl	$0, -148(%rbp)
	.loc 1 26 15
	leaq	-144(%rbp), %rax
	movq	%rax, -8(%rbp)
	.loc 1 28 14
	jmp	.L4
.L5:
	.loc 1 30 13
	movl	-148(%rbp), %edx
	movl	-12(%rbp), %eax
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	.loc 1 31 19
	movl	-28(%rbp), %eax
	cltq
	addq	%rax, -8(%rbp)
	.loc 1 32 18
	movl	-148(%rbp), %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -148(%rbp)
.L4:
	.loc 1 28 45
	movq	24(%rbp), %rax
	addq	$8, %rax
	.loc 1 28 25
	movq	(%rax), %rdx
	leaq	-148(%rbp), %rcx
	movq	-8(%rbp), %rax
	movq	%rcx, %r8
	movq	%rax, %rcx
	call	Mystrstr
	movq	%rax, -8(%rbp)
	.loc 1 28 14
	cmpq	$0, -8(%rbp)
	jne	.L5
	.loc 1 35 15
	addl	$1, -12(%rbp)
.L3:
	.loc 1 23 11
	movq	-40(%rbp), %rdx
	leaq	-144(%rbp), %rax
	movq	%rdx, %r8
	movl	$100, %edx
	movq	%rax, %rcx
	call	fgets
	.loc 1 23 10
	testq	%rax, %rax
	jne	.L6
	.loc 1 38 5
	leaq	.LC4(%rip), %rcx
	call	system
	.loc 1 40 12
	movl	$0, %eax
	.loc 1 41 1
	addq	$192, %rsp
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.seh_endproc
.Letext0:
	.file 2 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/crtdefs.h"
	.file 3 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/stdio.h"
	.file 4 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/stdlib.h"
	.file 5 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/malloc.h"
	.file 6 "C:/Program Files/CodeBlocks/MinGW/x86_64-w64-mingw32/include/ctype.h"
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0x954
	.word	0x4
	.secrel32	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.ascii "GNU C17 8.1.0 -mtune=core2 -march=nocona -g\0"
	.byte	0xc
	.ascii "D:\\Facultad en Cuarentena\\Programacion I\\Ejercicios\\Unidad 2\\Ejercicio_15\\main.c\0"
	.ascii "D:\\\\Facultad en Cuarentena\\\\Programacion I\\\\Ejercicios\\\\Unidad 2\\\\Ejercicio_15\0"
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
	.byte	0x2
	.byte	0x62
	.byte	0x18
	.long	0x130
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.ascii "short unsigned int\0"
	.uleb128 0x4
	.long	0x130
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.ascii "long int\0"
	.uleb128 0x5
	.ascii "pthreadlocinfo\0"
	.byte	0x2
	.word	0x1a8
	.byte	0x28
	.long	0x176
	.uleb128 0x6
	.byte	0x8
	.long	0x17c
	.uleb128 0x7
	.ascii "threadlocaleinfostruct\0"
	.word	0x160
	.byte	0x2
	.word	0x1bc
	.byte	0x10
	.long	0x326
	.uleb128 0x8
	.secrel32	.LASF0
	.byte	0x2
	.word	0x1bd
	.byte	0x7
	.long	0x14b
	.byte	0
	.uleb128 0x9
	.ascii "lc_codepage\0"
	.byte	0x2
	.word	0x1be
	.byte	0x10
	.long	0x473
	.byte	0x4
	.uleb128 0x9
	.ascii "lc_collate_cp\0"
	.byte	0x2
	.word	0x1bf
	.byte	0x10
	.long	0x473
	.byte	0x8
	.uleb128 0x9
	.ascii "lc_handle\0"
	.byte	0x2
	.word	0x1c0
	.byte	0x11
	.long	0x483
	.byte	0xc
	.uleb128 0x9
	.ascii "lc_id\0"
	.byte	0x2
	.word	0x1c1
	.byte	0x9
	.long	0x4a8
	.byte	0x24
	.uleb128 0x9
	.ascii "lc_category\0"
	.byte	0x2
	.word	0x1c7
	.byte	0x5
	.long	0x4b8
	.byte	0x48
	.uleb128 0xa
	.ascii "lc_clike\0"
	.byte	0x2
	.word	0x1c8
	.byte	0x7
	.long	0x14b
	.word	0x108
	.uleb128 0xa
	.ascii "mb_cur_max\0"
	.byte	0x2
	.word	0x1c9
	.byte	0x7
	.long	0x14b
	.word	0x10c
	.uleb128 0xa
	.ascii "lconv_intl_refcount\0"
	.byte	0x2
	.word	0x1ca
	.byte	0x8
	.long	0x46d
	.word	0x110
	.uleb128 0xa
	.ascii "lconv_num_refcount\0"
	.byte	0x2
	.word	0x1cb
	.byte	0x8
	.long	0x46d
	.word	0x118
	.uleb128 0xa
	.ascii "lconv_mon_refcount\0"
	.byte	0x2
	.word	0x1cc
	.byte	0x8
	.long	0x46d
	.word	0x120
	.uleb128 0xa
	.ascii "lconv\0"
	.byte	0x2
	.word	0x1cd
	.byte	0x11
	.long	0x4cf
	.word	0x128
	.uleb128 0xa
	.ascii "ctype1_refcount\0"
	.byte	0x2
	.word	0x1ce
	.byte	0x8
	.long	0x46d
	.word	0x130
	.uleb128 0xa
	.ascii "ctype1\0"
	.byte	0x2
	.word	0x1cf
	.byte	0x13
	.long	0x4d5
	.word	0x138
	.uleb128 0xa
	.ascii "pctype\0"
	.byte	0x2
	.word	0x1d0
	.byte	0x19
	.long	0x4db
	.word	0x140
	.uleb128 0xa
	.ascii "pclmap\0"
	.byte	0x2
	.word	0x1d1
	.byte	0x18
	.long	0x4e1
	.word	0x148
	.uleb128 0xa
	.ascii "pcumap\0"
	.byte	0x2
	.word	0x1d2
	.byte	0x18
	.long	0x4e1
	.word	0x150
	.uleb128 0xa
	.ascii "lc_time_curr\0"
	.byte	0x2
	.word	0x1d3
	.byte	0x1a
	.long	0x50d
	.word	0x158
	.byte	0
	.uleb128 0x5
	.ascii "pthreadmbcinfo\0"
	.byte	0x2
	.word	0x1a9
	.byte	0x25
	.long	0x33e
	.uleb128 0x6
	.byte	0x8
	.long	0x344
	.uleb128 0xb
	.ascii "threadmbcinfostruct\0"
	.uleb128 0xc
	.ascii "localeinfo_struct\0"
	.byte	0x10
	.byte	0x2
	.word	0x1ac
	.byte	0x10
	.long	0x39a
	.uleb128 0x9
	.ascii "locinfo\0"
	.byte	0x2
	.word	0x1ad
	.byte	0x12
	.long	0x15e
	.byte	0
	.uleb128 0x9
	.ascii "mbcinfo\0"
	.byte	0x2
	.word	0x1ae
	.byte	0x12
	.long	0x326
	.byte	0x8
	.byte	0
	.uleb128 0x5
	.ascii "_locale_tstruct\0"
	.byte	0x2
	.word	0x1af
	.byte	0x3
	.long	0x359
	.uleb128 0xc
	.ascii "tagLC_ID\0"
	.byte	0x6
	.byte	0x2
	.word	0x1b3
	.byte	0x10
	.long	0x402
	.uleb128 0x9
	.ascii "wLanguage\0"
	.byte	0x2
	.word	0x1b4
	.byte	0x12
	.long	0x130
	.byte	0
	.uleb128 0x9
	.ascii "wCountry\0"
	.byte	0x2
	.word	0x1b5
	.byte	0x12
	.long	0x130
	.byte	0x2
	.uleb128 0x9
	.ascii "wCodePage\0"
	.byte	0x2
	.word	0x1b6
	.byte	0x12
	.long	0x130
	.byte	0x4
	.byte	0
	.uleb128 0x5
	.ascii "LC_ID\0"
	.byte	0x2
	.word	0x1b7
	.byte	0x3
	.long	0x3b3
	.uleb128 0xd
	.byte	0x20
	.byte	0x2
	.word	0x1c2
	.byte	0x3
	.long	0x461
	.uleb128 0x9
	.ascii "locale\0"
	.byte	0x2
	.word	0x1c3
	.byte	0xb
	.long	0x461
	.byte	0
	.uleb128 0x9
	.ascii "wlocale\0"
	.byte	0x2
	.word	0x1c4
	.byte	0xe
	.long	0x467
	.byte	0x8
	.uleb128 0x8
	.secrel32	.LASF0
	.byte	0x2
	.word	0x1c5
	.byte	0xa
	.long	0x46d
	.byte	0x10
	.uleb128 0x9
	.ascii "wrefcount\0"
	.byte	0x2
	.word	0x1c6
	.byte	0xa
	.long	0x46d
	.byte	0x18
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0xed
	.uleb128 0x6
	.byte	0x8
	.long	0x120
	.uleb128 0x6
	.byte	0x8
	.long	0x14b
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "unsigned int\0"
	.uleb128 0xe
	.long	0x493
	.long	0x493
	.uleb128 0xf
	.long	0xf5
	.byte	0x5
	.byte	0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.ascii "long unsigned int\0"
	.uleb128 0xe
	.long	0x402
	.long	0x4b8
	.uleb128 0xf
	.long	0xf5
	.byte	0x5
	.byte	0
	.uleb128 0xe
	.long	0x411
	.long	0x4c8
	.uleb128 0xf
	.long	0xf5
	.byte	0x5
	.byte	0
	.uleb128 0xb
	.ascii "lconv\0"
	.uleb128 0x6
	.byte	0x8
	.long	0x4c8
	.uleb128 0x6
	.byte	0x8
	.long	0x130
	.uleb128 0x6
	.byte	0x8
	.long	0x146
	.uleb128 0x6
	.byte	0x8
	.long	0x4f8
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.ascii "unsigned char\0"
	.uleb128 0x4
	.long	0x4e7
	.uleb128 0xb
	.ascii "__lc_time_data\0"
	.uleb128 0x6
	.byte	0x8
	.long	0x4fd
	.uleb128 0x10
	.ascii "_iobuf\0"
	.byte	0x30
	.byte	0x3
	.byte	0x1a
	.byte	0xa
	.long	0x5a3
	.uleb128 0x11
	.ascii "_ptr\0"
	.byte	0x3
	.byte	0x1b
	.byte	0xb
	.long	0x461
	.byte	0
	.uleb128 0x11
	.ascii "_cnt\0"
	.byte	0x3
	.byte	0x1c
	.byte	0x9
	.long	0x14b
	.byte	0x8
	.uleb128 0x11
	.ascii "_base\0"
	.byte	0x3
	.byte	0x1d
	.byte	0xb
	.long	0x461
	.byte	0x10
	.uleb128 0x11
	.ascii "_flag\0"
	.byte	0x3
	.byte	0x1e
	.byte	0x9
	.long	0x14b
	.byte	0x18
	.uleb128 0x11
	.ascii "_file\0"
	.byte	0x3
	.byte	0x1f
	.byte	0x9
	.long	0x14b
	.byte	0x1c
	.uleb128 0x11
	.ascii "_charbuf\0"
	.byte	0x3
	.byte	0x20
	.byte	0x9
	.long	0x14b
	.byte	0x20
	.uleb128 0x11
	.ascii "_bufsiz\0"
	.byte	0x3
	.byte	0x21
	.byte	0x9
	.long	0x14b
	.byte	0x24
	.uleb128 0x11
	.ascii "_tmpfname\0"
	.byte	0x3
	.byte	0x22
	.byte	0xb
	.long	0x461
	.byte	0x28
	.byte	0
	.uleb128 0x3
	.ascii "FILE\0"
	.byte	0x3
	.byte	0x24
	.byte	0x19
	.long	0x513
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
	.uleb128 0x12
	.ascii "__imp___mb_cur_max\0"
	.byte	0x4
	.byte	0x73
	.byte	0x10
	.long	0x46d
	.uleb128 0xe
	.long	0x461
	.long	0x5fd
	.uleb128 0xf
	.long	0xf5
	.byte	0
	.byte	0
	.uleb128 0x12
	.ascii "_sys_errlist\0"
	.byte	0x4
	.byte	0xac
	.byte	0x2b
	.long	0x5ed
	.uleb128 0x12
	.ascii "_sys_nerr\0"
	.byte	0x4
	.byte	0xad
	.byte	0x29
	.long	0x14b
	.uleb128 0x13
	.ascii "__imp___argc\0"
	.byte	0x4
	.word	0x119
	.byte	0x10
	.long	0x46d
	.uleb128 0x13
	.ascii "__imp___argv\0"
	.byte	0x4
	.word	0x11d
	.byte	0x13
	.long	0x650
	.uleb128 0x6
	.byte	0x8
	.long	0x656
	.uleb128 0x6
	.byte	0x8
	.long	0x461
	.uleb128 0x13
	.ascii "__imp___wargv\0"
	.byte	0x4
	.word	0x121
	.byte	0x16
	.long	0x673
	.uleb128 0x6
	.byte	0x8
	.long	0x679
	.uleb128 0x6
	.byte	0x8
	.long	0x467
	.uleb128 0x13
	.ascii "__imp__environ\0"
	.byte	0x4
	.word	0x127
	.byte	0x13
	.long	0x650
	.uleb128 0x13
	.ascii "__imp__wenviron\0"
	.byte	0x4
	.word	0x12c
	.byte	0x16
	.long	0x673
	.uleb128 0x13
	.ascii "__imp__pgmptr\0"
	.byte	0x4
	.word	0x132
	.byte	0x12
	.long	0x656
	.uleb128 0x13
	.ascii "__imp__wpgmptr\0"
	.byte	0x4
	.word	0x137
	.byte	0x15
	.long	0x679
	.uleb128 0x13
	.ascii "__imp__osplatform\0"
	.byte	0x4
	.word	0x13c
	.byte	0x19
	.long	0x6fa
	.uleb128 0x6
	.byte	0x8
	.long	0x473
	.uleb128 0x13
	.ascii "__imp__osver\0"
	.byte	0x4
	.word	0x141
	.byte	0x19
	.long	0x6fa
	.uleb128 0x13
	.ascii "__imp__winver\0"
	.byte	0x4
	.word	0x146
	.byte	0x19
	.long	0x6fa
	.uleb128 0x13
	.ascii "__imp__winmajor\0"
	.byte	0x4
	.word	0x14b
	.byte	0x19
	.long	0x6fa
	.uleb128 0x13
	.ascii "__imp__winminor\0"
	.byte	0x4
	.word	0x150
	.byte	0x19
	.long	0x6fa
	.uleb128 0x12
	.ascii "_amblksiz\0"
	.byte	0x5
	.byte	0x35
	.byte	0x17
	.long	0x473
	.uleb128 0x12
	.ascii "__imp__pctype\0"
	.byte	0x6
	.byte	0x2b
	.byte	0x1c
	.long	0x787
	.uleb128 0x6
	.byte	0x8
	.long	0x4d5
	.uleb128 0x12
	.ascii "__imp__wctype\0"
	.byte	0x6
	.byte	0x3b
	.byte	0x1c
	.long	0x787
	.uleb128 0x12
	.ascii "__imp__pwctype\0"
	.byte	0x6
	.byte	0x47
	.byte	0x1c
	.long	0x787
	.uleb128 0xe
	.long	0x4f8
	.long	0x7c5
	.uleb128 0x14
	.byte	0
	.uleb128 0x4
	.long	0x7ba
	.uleb128 0x12
	.ascii "__newclmap\0"
	.byte	0x6
	.byte	0x50
	.byte	0x1e
	.long	0x7c5
	.uleb128 0x12
	.ascii "__newcumap\0"
	.byte	0x6
	.byte	0x51
	.byte	0x1e
	.long	0x7c5
	.uleb128 0x12
	.ascii "__ptlocinfo\0"
	.byte	0x6
	.byte	0x52
	.byte	0x19
	.long	0x15e
	.uleb128 0x12
	.ascii "__ptmbcinfo\0"
	.byte	0x6
	.byte	0x53
	.byte	0x19
	.long	0x326
	.uleb128 0x12
	.ascii "__globallocalestatus\0"
	.byte	0x6
	.byte	0x54
	.byte	0xe
	.long	0x14b
	.uleb128 0x12
	.ascii "__locale_changed\0"
	.byte	0x6
	.byte	0x55
	.byte	0xe
	.long	0x14b
	.uleb128 0x12
	.ascii "__initiallocinfo\0"
	.byte	0x6
	.byte	0x56
	.byte	0x28
	.long	0x17c
	.uleb128 0x12
	.ascii "__initiallocalestructinfo\0"
	.byte	0x6
	.byte	0x57
	.byte	0x1a
	.long	0x39a
	.uleb128 0x15
	.ascii "main\0"
	.byte	0x1
	.byte	0x3
	.byte	0x5
	.long	0x14b
	.quad	.LFB17
	.quad	.LFE17-.LFB17
	.uleb128 0x1
	.byte	0x9c
	.long	0x945
	.uleb128 0x16
	.ascii "argc\0"
	.byte	0x1
	.byte	0x3
	.byte	0xe
	.long	0x14b
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x16
	.ascii "argv\0"
	.byte	0x1
	.byte	0x3
	.byte	0x1a
	.long	0x656
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x17
	.ascii "pf\0"
	.byte	0x1
	.byte	0xe
	.byte	0xb
	.long	0x945
	.uleb128 0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x17
	.ascii "buffer\0"
	.byte	0x1
	.byte	0xf
	.byte	0xa
	.long	0x94b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -160
	.uleb128 0x17
	.ascii "puntB\0"
	.byte	0x1
	.byte	0xf
	.byte	0x18
	.long	0x461
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x17
	.ascii "subC\0"
	.byte	0x1
	.byte	0xf
	.byte	0x20
	.long	0x461
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x17
	.ascii "nLinea\0"
	.byte	0x1
	.byte	0x10
	.byte	0x9
	.long	0x14b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x17
	.ascii "posL\0"
	.byte	0x1
	.byte	0x10
	.byte	0x15
	.long	0x14b
	.uleb128 0x3
	.byte	0x91
	.sleb128 -164
	.uleb128 0x17
	.ascii "tamSubC\0"
	.byte	0x1
	.byte	0x10
	.byte	0x1b
	.long	0x14b
	.uleb128 0x2
	.byte	0x91
	.sleb128 -44
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x5a3
	.uleb128 0x18
	.long	0xed
	.uleb128 0xf
	.long	0xf5
	.byte	0x63
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
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x16
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
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0x5
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
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
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0xd
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
	.uleb128 0x38
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x10
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
	.uleb128 0x11
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
	.uleb128 0x12
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
	.uleb128 0x13
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
	.uleb128 0x14
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x15
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
	.uleb128 0x2116
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x16
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
	.uleb128 0x17
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
	.uleb128 0x18
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
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
.LASF0:
	.ascii "refcount\0"
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	generarArchivo;	.scl	2;	.type	32;	.endef
	.def	agregarTexto;	.scl	2;	.type	32;	.endef
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	Mystrstr;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	system;	.scl	2;	.type	32;	.endef
