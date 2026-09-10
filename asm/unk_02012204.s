	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02012204
sub_02012204: ; 0x02012204
	push {r4, r5, r6, lr}
	mov r1, #0
	add r6, r0, #0
	bl sub_02010EE0
	mov r2, #3
	lsl r2, r2, #8
	add r0, r0, r2
	mov r1, #0
	bl memset
	ldr r0, [r6, #0x10]
	sub r4, r0, #1
	bmi _02012236
	mov r0, #0x30
	add r5, r4, #0
	mul r5, r0
_02012226:
	ldr r1, [r6, #0xc]
	add r0, r6, #0
	add r1, r1, r5
	bl sub_02012238
	sub r5, #0x30
	sub r4, r4, #1
	bpl _02012226
_02012236:
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02012204
	thumb_func_start sub_02012238
sub_02012238: ; 0x02012238
	push {r4, r5, r6, lr}
	add r4, r1, #0
	mov r1, #0
	bl sub_02010EE0
	ldr r2, [r4]
	ldr r3, [r4, #8]
	asr r1, r2, #6
	lsr r1, r1, #0x19
	add r1, r2, r1
	asr r2, r1, #7
	asr r1, r3, #6
	ldr r5, [r4, #0xc]
	lsr r1, r1, #0x19
	add r1, r3, r1
	asr r3, r5, #6
	lsr r3, r3, #0x19
	add r3, r5, r3
	ldr r4, [r4, #4]
	asr r5, r3, #7
	asr r3, r4, #6
	lsr r3, r3, #0x19
	add r3, r4, r3
	asr r3, r3, #7
	asr r1, r1, #7
	cmp r3, r5
	bge _0201228E
	lsl r4, r3, #1
	lsl r1, r1, #0x10
	add r4, r0, r4
	lsl r0, r2, #0x10
	asr r6, r1, #0x10
	mov r1, #3
	mov r2, #0x12
	asr r0, r0, #0x10
	lsl r1, r1, #8
	lsl r2, r2, #6
_02012282:
	strh r0, [r4, r1]
	strh r6, [r4, r2]
	add r3, r3, #1
	add r4, r4, #2
	cmp r3, r5
	blt _02012282
_0201228E:
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02012238
	thumb_func_start sub_02012290
sub_02012290: ; 0x02012290
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x10]
	mov r6, #0
	cmp r0, #0
	ble _020122B4
	add r4, r6, #0
_0201229E:
	ldr r1, [r5, #0xc]
	add r0, r1, r4
	add r1, r1, r4
	add r1, #0x10
	bl sub_02010A8C
	ldr r0, [r5, #0x10]
	add r6, r6, #1
	add r4, #0x30
	cmp r6, r0
	blt _0201229E
_020122B4:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02012290
	thumb_func_start sub_020122B8
sub_020122B8: ; 0x020122B8
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r4, r1, #0
	mov r1, #0x38
	bl Heap_Alloc
	str r0, [r5, #0x14]
	mov r1, #0
	mov r2, #0x38
	bl memset
	ldr r0, [r5, #0x10]
	add r1, r4, #0
	str r0, [sp]
	ldr r0, [r5, #0x18]
	str r0, [sp, #4]
	ldr r0, [r5, #0x1c]
	str r0, [sp, #8]
	ldr r0, [r5, #0x20]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x14]
	ldr r2, [r5, #4]
	ldr r3, [r5, #8]
	bl sub_02012358
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_020122B8
	thumb_func_start sub_020122F8
sub_020122F8: ; 0x020122F8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	ldr r4, [r5, #0x14]
	cmp r0, #1
	beq _02012310
	cmp r0, #2
	beq _0201232C
	cmp r0, #3
	beq _0201234C
	b _02012350
_02012310:
	add r0, r4, #0
	bl sub_02012454
	cmp r0, #1
	bne _02012354
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x30]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02012354
_0201232C:
	add r0, r4, #0
	bl sub_020124AC
	add r0, r4, #0
	bl sub_02010EC8
	ldr r0, [r5, #0x14]
	bl Heap_Free
	add r0, r6, #0
	str r0, [r5, #0x14]
	ldr r0, [r5, #0xc]
	mov r6, #1
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02012354
_0201234C:
	mov r6, #1
	b _02012354
_02012350:
	bl GF_AssertFail
_02012354:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	thumb_func_end sub_020122F8
	thumb_func_start sub_02012358
sub_02012358: ; 0x02012358
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r4, r1, #0
	add r5, r0, #0
	mov r1, #0
	str r1, [r5, #0xc]
	ldrh r1, [r4]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	str r1, [r5, #0x10]
	ldrh r2, [r4, #2]
	ldrh r1, [r4]
	ldr r6, [sp, #0x40]
	ldr r3, [sp, #0x4c]
	sub r1, r2, r1
	str r1, [r5, #0x14]
	mov r1, #2
	add r2, r6, #0
	ldr r7, [sp, #0x44]
	bl sub_02010E64
	ldr r0, [sp, #0x18]
	mov r1, #0
	str r0, [r5, #0x18]
	ldr r0, [sp, #0x1c]
	str r1, [r5, #0x1c]
	str r0, [r5, #0x20]
	str r1, [r5, #0x24]
	ldr r0, [sp, #0x48]
	str r7, [r5, #0x30]
	str r0, [r5, #0x34]
	ldr r0, [sp, #0x4c]
	str r0, [r5, #0x2c]
	ldrh r0, [r4, #6]
	str r0, [r5, #0x28]
	add r0, r5, #0
	ldr r1, [r5, #0x1c]
	ldr r2, [r5, #0x18]
	add r0, #0xc
	bl sub_020125D4
	add r0, r5, #0
	bl sub_020124B0
	ldr r0, _02012448 ; =sub_02010F00
	ldr r2, _0201244C ; =0x000003FF
	add r1, r5, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r5, #0
	mov r1, #0
	bl sub_02010EE0
	str r0, [sp, #0x20]
	add r0, r5, #0
	mov r1, #1
	bl sub_02010EE0
	str r0, [sp, #0x24]
	mov r1, #3
	ldr r0, [sp, #0x20]
	str r6, [sp]
	lsl r1, r1, #8
	ldrsh r0, [r0, r1]
	mov r1, #0x12
	mov r3, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x20]
	str r3, [sp, #8]
	lsl r1, r1, #6
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x28]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	add r0, r7, #0
	bl sub_02010F84
	mov r1, #3
	ldr r0, [sp, #0x24]
	str r6, [sp]
	lsl r1, r1, #8
	ldrsh r0, [r0, r1]
	mov r1, #0x12
	lsl r1, r1, #6
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x24]
	mov r3, #1
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x28]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	add r0, r7, #0
	bl sub_02010F84
	ldr r3, [r5, #0x28]
	add r0, r7, #0
	mov r1, #3
	add r2, r6, #0
	bl sub_02011068
	ldr r0, [sp, #0x4c]
	ldr r2, _02012450 ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r5, #0x34]
	add r1, r5, #0
	add r3, r6, #0
	bl sub_0200FF88
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02012448: .word sub_02010F00
_0201244C: .word 0x000003FF
_02012450: .word sub_02010C38
	thumb_func_end sub_02012358
	thumb_func_start sub_02012454
sub_02012454: ; 0x02012454
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x24]
	add r1, r0, #1
	str r1, [r4, #0x24]
	ldr r0, [r4, #0x20]
	cmp r1, r0
	blt _0201249E
	mov r0, #0
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x1c]
	add r1, r0, #1
	ldr r0, [r4, #0x18]
	cmp r1, r0
	bgt _02012490
	str r1, [r4, #0x1c]
	add r0, r4, #0
	ldr r2, [r4, #0x18]
	add r0, #0xc
	bl sub_020125D4
	add r0, r4, #0
	bl sub_020124B0
	ldr r0, _020124A4 ; =sub_02010F00
	ldr r2, _020124A8 ; =0x000003FF
	add r1, r4, #0
	bl SysTask_CreateOnVWaitQueue
	b _0201249E
_02012490:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x2c]
	bl sub_0200FFB4
	mov r0, #1
	pop {r4, pc}
_0201249E:
	mov r0, #0
	pop {r4, pc}
	nop
_020124A4: .word sub_02010F00
_020124A8: .word 0x000003FF
	thumb_func_end sub_02012454
