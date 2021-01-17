	.cpu cortex-m3
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"code.c"
	.text
	.align	1
	.global	main
	.arch armv7-m
	.syntax unified
	.thumb
	.thumb_func
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	sub	sp, sp, #12
	add	r7, sp, #0
	ldr	r3, .L5
	movs	r2, #16
	str	r2, [r3]
	ldr	r3, .L5+4
	movs	r2, #1
	str	r2, [r3]
	ldr	r3, .L5+8
	mov	r2, #256
	str	r2, [r3]
	ldr	r3, .L5
	movw	r2, #16388
	str	r2, [r3]
	ldr	r3, .L5+12
	mov	r2, #1200
	str	r2, [r3]
	ldr	r3, .L5+16
	movs	r2, #208
	str	r2, [r3]
	ldr	r3, .L5+20
	movw	r2, #8204
	str	r2, [r3]
.L4:
	nop
.L2:
	ldr	r3, .L5+24
	ldr	r3, [r3]
	and	r3, r3, #32
	cmp	r3, #0
	beq	.L2
	ldr	r3, .L5+28
	ldr	r3, [r3]
	strb	r3, [r7, #7]
	ldr	r3, .L5+28
	movs	r2, #88
	str	r2, [r3]
	nop
.L3:
	ldr	r3, .L5+24
	ldr	r3, [r3]
	and	r3, r3, #128
	cmp	r3, #0
	beq	.L3
	b	.L4
.L6:
	.align	2
.L5:
	.word	1073877016
	.word	1073811460
	.word	1073811468
	.word	1073809412
	.word	1073821704
	.word	1073821708
	.word	1073821696
	.word	1073821700
	.size	main, .-main
	.ident	"GCC: (GNU Tools for Arm Embedded Processors 8-2019-q3-update) 8.3.1 20190703 (release) [gcc-8-branch revision 273027]"
