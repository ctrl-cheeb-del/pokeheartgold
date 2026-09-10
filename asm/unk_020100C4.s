	.include "asm/macros.inc"
	.include "unk_0200FA24.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020100C4
sub_020100C4: ; 0x020100C4
	push {r4, lr}
	add r4, r0, #0
	add r2, r4, #0
	mov r1, #0x14
	mov r0, #0
_020100CE:
	strb r0, [r2]
	add r2, r2, #1
	sub r1, r1, #1
	bne _020100CE
	add r0, r4, #0
	add r0, #0x14
	mov r1, #0
	mov r2, #0x30
	bl memset
	add r0, r4, #0
	add r0, #0x44
	mov r1, #0
	mov r2, #0x30
	bl memset
	add r2, r4, #0
	add r2, #0x74
	mov r1, #0x18
	mov r0, #0
_020100F6:
	strb r0, [r2]
	add r2, r2, #1
	sub r1, r1, #1
	bne _020100F6
	add r4, #0x8c
	add r0, r4, #0
	mov r1, #0
	mov r2, #0xc0
	bl memset
	pop {r4, pc}
	thumb_func_end sub_020100C4
