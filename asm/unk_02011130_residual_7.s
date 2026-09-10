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
	thumb_func_start sub_02011DEC
sub_02011DEC: ; 0x02011DEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r4, r1, #0
	add r5, r0, #0
	ldrh r1, [r4, #2]
	ldrh r0, [r4]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	sub r0, r1, r0
	add r1, r2, #0
	ldr r6, [sp, #0x38]
	ldr r7, [sp, #0x3c]
	bl _s32_div_f
	str r0, [sp, #0x20]
	ldrb r1, [r4, #4]
	ldr r3, [sp, #0x44]
	add r0, r5, #0
	add r2, r6, #0
	bl sub_02010E64
	mov r0, #2
	lsl r0, r0, #0x12
	str r0, [r5, #0xc]
	ldrh r0, [r4]
	str r0, [r5, #0x10]
	ldr r0, [sp, #0x20]
	str r0, [r5, #0x14]
	ldr r0, [sp, #0x18]
	str r0, [r5, #0x18]
	ldr r0, [sp, #0x1c]
	str r0, [r5, #0x1c]
	mov r0, #0
	str r0, [r5, #0x20]
	ldr r0, [sp, #0x40]
	str r7, [r5, #0x28]
	str r0, [r5, #0x2c]
	ldr r0, [sp, #0x44]
	str r0, [r5, #0x30]
	ldrb r0, [r4, #7]
	str r0, [r5, #0x24]
	add r0, r5, #0
	bl sub_02011F10
	ldr r0, _02011EB4 ; =sub_02010F00
	ldr r2, _02011EB8 ; =0x000003FF
	add r1, r5, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r5, #0
	mov r1, #0
	bl sub_02010EE0
	mov r1, #0xf
	str r6, [sp]
	lsl r1, r1, #6
	ldrsh r1, [r0, r1]
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #0x15
	lsl r1, r1, #6
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x24]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #4]
	add r0, r7, #0
	bl sub_02010F84
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _02011E94
	ldr r3, [r5, #0x24]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	bl sub_02011068
	b _02011EA0
_02011E94:
	ldr r3, [r5, #0x24]
	add r0, r7, #0
	mov r1, #2
	add r2, r6, #0
	bl sub_02011068
_02011EA0:
	ldr r0, [sp, #0x44]
	ldr r2, _02011EBC ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r5, #0x2c]
	add r1, r5, #0
	add r3, r6, #0
	bl sub_0200FF88
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02011EB4: .word sub_02010F00
_02011EB8: .word 0x000003FF
_02011EBC: .word sub_02010C38
	thumb_func_end sub_02011DEC
