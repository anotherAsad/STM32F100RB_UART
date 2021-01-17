.cpu cortex-m3
.thumb

.global _start
.global main

_start:
	.word	0x20002000
	.word	reset+1
reset:
	bl		main
	b		reset
