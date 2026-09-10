	.include "asm/macros.inc"
	.include "unk_02012DD8.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_02012E6C
sub_02012E6C: ; 0x02012E6C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r4, r1, #0
	ldr r6, [sp, #0x38]
	str r3, [sp, #0x1c]
	str r2, [sp, #0x18]
	ldrb r1, [r4, #8]
	ldr r3, [sp, #0x44]
	add r2, r6, #0
	add r5, r0, #0
	ldr r7, [sp, #0x3c]
	bl sub_02010E64
	ldr r0, _02012F44 ; =0x007FFF80
	mov r1, #0
	str r0, [r5, #0x14]
	ldrsh r1, [r4, r1]
	lsr r0, r0, #7
	str r1, [r5, #0xc]
	mov r1, #2
	ldrsh r1, [r4, r1]
	str r1, [r5, #0x10]
	ldr r1, [r4, #4]
	str r1, [r5, #0x18]
	ldr r1, [r4, #4]
	str r1, [r5, #0x1c]
	ldr r1, [sp, #0x18]
	bl _s32_div_f
	str r0, [r5, #0x20]
	ldr r0, [sp, #0x18]
	str r0, [r5, #0x24]
	ldr r0, [sp, #0x1c]
	str r0, [r5, #0x28]
	mov r0, #0
	str r0, [r5, #0x2c]
	ldr r0, [sp, #0x40]
	str r7, [r5, #0x44]
	str r0, [r5, #0x48]
	ldr r0, [sp, #0x44]
	str r0, [r5, #0x30]
	ldrb r0, [r4, #0xb]
	str r0, [r5, #0x34]
	ldrb r0, [r4, #8]
	str r0, [r5, #0x38]
	str r6, [r5, #0x3c]
	mov r0, #1
	str r0, [r5, #0x40]
	add r0, r5, #0
	bl sub_020131AC
	ldr r0, _02012F48 ; =sub_02010F00
	ldr r2, _02012F4C ; =0x000003FF
	add r1, r5, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r5, #0
	mov r1, #0
	bl sub_02010EE0
	mov r1, #3
	str r6, [sp]
	lsl r1, r1, #8
	ldrsh r1, [r0, r1]
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #0x12
	lsl r1, r1, #6
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x34]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #9]
	ldrb r2, [r4, #0xa]
	ldrb r3, [r4, #8]
	add r0, r7, #0
	bl sub_02010F84
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _02012F22
	ldr r3, [r5, #0x34]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	bl sub_02011068
	b _02012F2E
_02012F22:
	ldr r3, [r5, #0x34]
	add r0, r7, #0
	mov r1, #2
	add r2, r6, #0
	bl sub_02011068
_02012F2E:
	ldr r0, [sp, #0x44]
	ldr r2, _02012F50 ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r5, #0x48]
	add r1, r5, #0
	add r3, r6, #0
	bl sub_0200FF88
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02012F44: .word 0x007FFF80
_02012F48: .word sub_02010F00
_02012F4C: .word 0x000003FF
_02012F50: .word sub_02010C38
	thumb_func_end sub_02012E6C
