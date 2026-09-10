	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	.public sub_02011130
	.public sub_0201164C
	.public sub_0201169C
	.public sub_020116EC
	.public sub_02011744
	.public sub_020117A0
	.public sub_020117FC
	.public sub_02011884
	.public sub_020118BC
	.public sub_02011918
	.public sub_020119F4
	.public sub_02011A44
	.public sub_02011AD8
	.public sub_02011B5C
	.public sub_02011B94
	.public sub_02011BF0
	.public sub_02011CB8
	.public sub_02011D08
	.public sub_02011D60
	.public sub_02011D98
	.public sub_02011DEC
	.public sub_02011EC0
	.public sub_02011F10
	.public sub_02011FF8
	.public sub_02012030
	.public sub_02012090
	.public sub_020121A4
	thumb_func_start sub_02011F10
sub_02011F10: ; 0x02011F10
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x110
	add r4, r0, #0
	mov r1, #0
	bl sub_02010EE0
	str r0, [sp]
	ldr r0, [r4, #0x10]
	ldr r2, [r4, #0xc]
	asr r0, r0, #4
	lsl r1, r0, #2
	ldr r0, _02011FF0 ; =FX_SinCosTable_
	asr r3, r2, #0x1f
	ldrsh r0, [r0, r1]
	asr r1, r0, #0x1f
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	asr r7, r1, #0xc
	lsl r0, r7, #1
	mov r1, #0x15
	bl _s32_div_f
	add r0, r0, #1
	lsl r0, r0, #1
	mov r1, #0xb4
	sub r2, r1, r0
	ldr r0, _02011FF4 ; =0x0000FFFF
	add r1, #0xb4
	mul r0, r2
	bl _s32_div_f
	lsr r1, r0, #0x1f
	add r1, r0, r1
	asr r4, r1, #1
	mov r1, #1
	add r0, r4, #0
	lsl r1, r1, #8
	bl sub_02010A54
	asr r0, r0, #0xc
	str r0, [sp, #4]
	cmp r0, #0xc0
	blt _02011F7C
	bl GF_AssertFail
_02011F7C:
	ldr r2, [sp, #4]
	add r0, r4, #0
	add r1, sp, #0xc
	mov r3, #0
	bl sub_02010A00
	ldr r5, [sp]
	mov r4, #0
_02011F8C:
	ldr r0, [sp, #4]
	add r1, r4, #1
	sub r0, r0, r1
	add r6, r7, #0
	cmp r0, #0
	ble _02011FA4
	lsl r1, r0, #2
	add r0, sp, #0xc
	ldr r0, [r0, r1]
	cmp r0, r7
	ble _02011FA4
	add r6, r0, #0
_02011FA4:
	mov r0, #0x80
	neg r1, r6
	bl sub_02010A7C
	str r0, [sp, #8]
	mov r0, #0x80
	add r1, r6, #0
	bl sub_02010A7C
	ldr r1, [sp, #8]
	lsl r0, r0, #0x10
	lsl r1, r1, #0x10
	asr r2, r1, #0x10
	mov r1, #3
	lsl r1, r1, #8
	strh r2, [r5, r1]
	asr r1, r0, #0x10
	mov r0, #0x12
	lsl r0, r0, #6
	strh r1, [r5, r0]
	mov r0, #0xbf
	sub r0, r0, r4
	lsl r3, r0, #1
	ldr r0, [sp]
	add r4, r4, #1
	add r0, r0, r3
	mov r3, #3
	lsl r3, r3, #8
	strh r2, [r0, r3]
	mov r2, #0x12
	lsl r2, r2, #6
	add r5, r5, #2
	strh r1, [r0, r2]
	cmp r4, #0x60
	blt _02011F8C
	add sp, #0x1fc
	add sp, #0x110
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02011FF0: .word FX_SinCosTable_
_02011FF4: .word 0x0000FFFF
	thumb_func_end sub_02011F10
