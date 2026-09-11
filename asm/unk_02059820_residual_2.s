	.include "asm/macros.inc"
	.include "unk_02058AEC.inc"
	.include "global.inc"
	.text
	.public sub_0205993C
	thumb_func_start sub_02059A08
sub_02059A08: ; 0x02059A08
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	ldr r0, _02059AD0 ; =gSystem
	mov r1, #0x40
	ldr r0, [r0, #0x48]
	tst r1, r0
	beq _02059A32
	mov r0, #0x81
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bne _02059A28
	add r0, r4, #0
	add r0, #0x80
	ldrb r0, [r0]
	b _02059A28
_02059A28:
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x81
	strb r1, [r0]
	b _02059A94
_02059A32:
	mov r1, #0x80
	tst r1, r0
	beq _02059A56
	mov r0, #0x81
	ldrsb r1, [r4, r0]
	add r0, r4, #0
	add r0, #0x80
	ldrb r0, [r0]
	sub r0, r0, #1
	cmp r1, r0
	bne _02059A4C
	mov r1, #0
	b _02059A4E
_02059A4C:
	add r1, r1, #1
_02059A4E:
	add r0, r4, #0
	add r0, #0x81
	strb r1, [r0]
	b _02059A94
_02059A56:
	mov r1, #1
	tst r1, r0
	beq _02059A7C
	ldr r0, _02059AD4 ; =0x000005DC
	bl PlaySE
	mov r0, #0x81
	ldrsb r1, [r4, r0]
	add r4, #0x80
	ldrb r0, [r4]
	sub r0, r0, #1
	cmp r1, r0
	bge _02059A76
	add sp, #8
	mov r0, #1
	pop {r4, pc}
_02059A76:
	add sp, #8
	mov r0, #2
	pop {r4, pc}
_02059A7C:
	mov r1, #2
	tst r0, r1
	beq _02059A8E
	ldr r0, _02059AD4 ; =0x000005DC
	bl PlaySE
	add sp, #8
	mov r0, #2
	pop {r4, pc}
_02059A8E:
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_02059A94:
	ldr r0, _02059AD4 ; =0x000005DC
	bl PlaySE
	ldr r0, [r4, #0x7c]
	mov r1, #0x10
	str r1, [sp]
	ldrb r1, [r0, #8]
	mov r2, #0
	add r3, r2, #0
	lsl r1, r1, #0x13
	lsr r1, r1, #0x10
	str r1, [sp, #4]
	mov r1, #0xf
	bl FillWindowPixelRect
	mov r3, #0x81
	ldrsb r3, [r4, r3]
	ldr r0, [r4, #0x78]
	ldr r1, [r4, #0x7c]
	mov r2, #0
	lsl r3, r3, #4
	bl ListMenuUpdateCursorObj
	ldr r0, [r4, #0x7c]
	bl CopyWindowPixelsToVram_TextMode
	mov r0, #0
	add sp, #8
	pop {r4, pc}
	nop
_02059AD0: .word gSystem
_02059AD4: .word 0x000005DC
	thumb_func_end sub_02059A08
