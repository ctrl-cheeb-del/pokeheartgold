	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02012A90
sub_02012A90: ; 0x02012A90
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x31
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r6, #0
	cmp r0, #0
	ble _02012ACA
	mov r7, #0x31
	add r4, r6, #0
	lsl r7, r7, #4
_02012AA6:
	mov r0, #0xc3
	lsl r0, r0, #2
	mov r2, #0xc6
	mov r3, #0xc5
	ldr r0, [r5, r0]
	lsl r2, r2, #2
	lsl r3, r3, #2
	ldr r2, [r5, r2]
	ldr r3, [r5, r3]
	add r0, r0, r4
	add r1, r5, #0
	bl sub_02012ACC
	ldr r0, [r5, r7]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, r0
	blt _02012AA6
_02012ACA:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02012A90
	thumb_func_start sub_02012ACC
sub_02012ACC: ; 0x02012ACC
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldrb r6, [r7]
	ldrb r4, [r7, #1]
	add r5, r1, #0
	add r1, r3, #0
	sub r0, r4, r6
	mul r0, r2
	bl _s32_div_f
	add r0, r0, r6
	cmp r6, r4
	bhi _02012AEC
	add r1, r6, #0
	ldrh r6, [r7, #2]
	b _02012AFC
_02012AEC:
	ldrh r2, [r7, #2]
	add r1, r4, #0
	add r4, r6, #0
	cmp r2, #0
	bne _02012AFA
	mov r6, #1
	b _02012AFC
_02012AFA:
	mov r6, #0
_02012AFC:
	cmp r1, r4
	bge _02012B1A
	mov r2, #0
	mov r3, #1
_02012B04:
	cmp r1, r0
	bne _02012B12
	cmp r6, #0
	bne _02012B10
	add r6, r3, #0
	b _02012B12
_02012B10:
	add r6, r2, #0
_02012B12:
	strb r6, [r5, r1]
	add r1, r1, #1
	cmp r1, r4
	blt _02012B04
_02012B1A:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02012ACC
	thumb_func_start sub_02012B1C
sub_02012B1C: ; 0x02012B1C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r4, r1, #0
	mov r1, #0xe2
	ldr r0, [r5, #0x20]
	lsl r1, r1, #2
	bl Heap_Alloc
	mov r2, #0xe2
	str r0, [r5, #0x14]
	mov r1, #0
	lsl r2, r2, #2
	bl memset
	ldrb r1, [r4, #0xb]
	ldr r0, [r5, #0x14]
	cmp r1, #0
	ldr r1, [r5, #0x10]
	bne _02012B5E
	str r1, [sp]
	ldr r1, [r5, #0x18]
	str r1, [sp, #4]
	ldr r1, [r5, #0x1c]
	str r1, [sp, #8]
	ldr r1, [r5, #0x20]
	str r1, [sp, #0xc]
	ldr r2, [r5, #4]
	ldr r3, [r5, #8]
	add r1, r4, #0
	bl sub_02012BE8
	b _02012B76
_02012B5E:
	str r1, [sp]
	ldr r1, [r5, #0x18]
	str r1, [sp, #4]
	ldr r1, [r5, #0x1c]
	str r1, [sp, #8]
	ldr r1, [r5, #0x20]
	str r1, [sp, #0xc]
	ldr r2, [r5, #4]
	ldr r3, [r5, #8]
	add r1, r4, #0
	bl sub_02012CDC
_02012B76:
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02012B1C
	thumb_func_start sub_02012B80
sub_02012B80: ; 0x02012B80
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r1, [r5, #0xc]
	mov r4, #0
	ldr r0, [r5, #0x14]
	cmp r1, #1
	beq _02012B98
	cmp r1, #2
	beq _02012BC4
	cmp r1, #3
	beq _02012BD6
	b _02012BDA
_02012B98:
	ldr r1, _02012BE4 ; =0x00000386
	ldrb r1, [r0, r1]
	cmp r1, #0
	bne _02012BA8
	add r1, r5, #0
	bl sub_02012C68
	b _02012BAE
_02012BA8:
	add r1, r5, #0
	bl sub_02012D4C
_02012BAE:
	cmp r0, #1
	bne _02012BDE
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x18]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02012BDE
_02012BC4:
	bl Heap_Free
	add r0, r4, #0
	str r0, [r5, #0x14]
	ldr r0, [r5, #0xc]
	mov r4, #1
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02012BDE
_02012BD6:
	mov r4, #1
	b _02012BDE
_02012BDA:
	bl GF_AssertFail
_02012BDE:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	nop
_02012BE4: .word 0x00000386
	thumb_func_end sub_02012B80
	thumb_func_start sub_02012BE8
sub_02012BE8: ; 0x02012BE8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r1, #0
	add r6, r2, #0
	add r5, r0, #0
	lsl r0, r6, #0xc
	ldr r2, [r4, #0x14]
	add r7, r3, #0
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	add r2, r0, #0
	mov r0, #2
	mov r3, #0
	lsl r0, r0, #0xa
	add r0, r2, r0
	adc r1, r3
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	asr r2, r0, #0xc
	mov r0, #0xe1
	sub r1, r6, r2
	lsl r0, r0, #2
	strb r1, [r5, r0]
	sub r1, r0, #4
	str r4, [r5, r1]
	ldrb r1, [r4, #0xb]
	add r0, r0, #2
	add r3, r7, #0
	strb r1, [r5, r0]
	ldr r0, [sp, #0x20]
	add r1, r4, #0
	str r0, [sp]
	ldr r0, [sp, #0x24]
	str r0, [sp, #4]
	add r0, r5, #0
	bl sub_020117A0
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _02012C4C
	ldrb r3, [r4, #0xb]
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x20]
	mov r1, #1
	bl sub_02011068
	b _02012C58
_02012C4C:
	ldrb r3, [r4, #0xb]
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x20]
	mov r1, #2
	bl sub_02011068
_02012C58:
	ldr r0, _02012C64 ; =0x00000385
	mov r1, #0
	strb r1, [r5, r0]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02012C64: .word 0x00000385
	thumb_func_end sub_02012BE8
	thumb_func_start sub_02012C68
sub_02012C68: ; 0x02012C68
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r1, #0
	ldr r1, _02012CD8 ; =0x00000385
	add r5, r0, #0
	ldrb r1, [r5, r1]
	mov r6, #0
	cmp r1, #0
	beq _02012C84
	cmp r1, #1
	beq _02012CBA
	cmp r1, #2
	beq _02012CD0
	b _02012CD2
_02012C84:
	bl sub_020117FC
	cmp r0, #1
	bne _02012CD2
	ldr r2, _02012CD8 ; =0x00000385
	ldrb r0, [r5, r2]
	sub r1, r2, #5
	add r0, r0, #1
	strb r0, [r5, r2]
	ldr r0, [r4, #0x10]
	sub r2, r2, #1
	str r0, [sp]
	ldr r0, [r4, #0x18]
	str r0, [sp, #4]
	ldr r0, [r4, #0x1c]
	str r0, [sp, #8]
	ldr r0, [r4, #0x20]
	str r0, [sp, #0xc]
	ldr r1, [r5, r1]
	add r0, r5, #0
	ldrb r2, [r5, r2]
	ldr r3, [r4, #8]
	add r0, #0x4c
	add r1, #0xc
	bl sub_02012940
	b _02012CD2
_02012CBA:
	add r0, #0x4c
	bl sub_02012A2C
	cmp r0, #1
	bne _02012CD2
	ldr r0, _02012CD8 ; =0x00000385
	mov r6, #1
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	b _02012CD2
_02012CD0:
	mov r6, #1
_02012CD2:
	add r0, r6, #0
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02012CD8: .word 0x00000385
	thumb_func_end sub_02012C68
	thumb_func_start sub_02012CDC
sub_02012CDC: ; 0x02012CDC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	add r6, r2, #0
	add r5, r0, #0
	lsl r0, r6, #0xc
	ldr r2, [r4, #0x14]
	add r7, r3, #0
	asr r1, r0, #0x1f
	asr r3, r2, #0x1f
	bl _ll_mul
	add r2, r0, #0
	mov r0, #2
	mov r3, #0
	lsl r0, r0, #0xa
	add r0, r2, r0
	adc r1, r3
	lsl r1, r1, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	mov r1, #0xe1
	asr r0, r0, #0xc
	lsl r1, r1, #2
	strb r0, [r5, r1]
	ldrb r0, [r5, r1]
	sub r2, r6, r0
	sub r0, r1, #4
	str r4, [r5, r0]
	add r0, r1, #2
	ldrb r3, [r4, #0xb]
	sub r1, r1, #4
	strb r3, [r5, r0]
	ldr r0, [sp, #0x28]
	add r3, r7, #0
	str r0, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xc]
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r0, #0x4c
	add r1, #0xc
	bl sub_02012940
	ldr r0, _02012D48 ; =0x00000385
	mov r1, #0
	strb r1, [r5, r0]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02012D48: .word 0x00000385
	thumb_func_end sub_02012CDC
	thumb_func_start sub_02012D4C
sub_02012D4C: ; 0x02012D4C
	push {r4, r5, r6, lr}
	sub sp, #8
	add r4, r1, #0
	ldr r1, _02012DD4 ; =0x00000385
	add r5, r0, #0
	ldrb r1, [r5, r1]
	mov r6, #0
	cmp r1, #0
	beq _02012D68
	cmp r1, #1
	beq _02012DB8
	cmp r1, #2
	beq _02012DCC
	b _02012DCE
_02012D68:
	add r0, #0x4c
	bl sub_02012A2C
	cmp r0, #1
	bne _02012DCE
	ldr r2, _02012DD4 ; =0x00000385
	ldrb r0, [r5, r2]
	sub r1, r2, #5
	add r0, r0, #1
	strb r0, [r5, r2]
	ldr r0, [r4, #0x10]
	sub r2, r2, #1
	str r0, [sp]
	ldr r0, [r4, #0x18]
	str r0, [sp, #4]
	ldrb r2, [r5, r2]
	ldr r1, [r5, r1]
	ldr r3, [r4, #8]
	add r0, r5, #0
	bl sub_020117A0
	mov r0, #0xe
	lsl r0, r0, #6
	ldr r3, [r5, r0]
	ldrb r0, [r3, #8]
	cmp r0, #0
	ldr r0, [r4, #0x18]
	bne _02012DAC
	ldrb r3, [r3, #0xb]
	ldr r2, [r4, #0x10]
	mov r1, #1
	bl sub_02011068
	b _02012DCE
_02012DAC:
	ldrb r3, [r3, #0xb]
	ldr r2, [r4, #0x10]
	mov r1, #2
	bl sub_02011068
	b _02012DCE
_02012DB8:
	bl sub_020117FC
	cmp r0, #1
	bne _02012DCE
	ldr r0, _02012DD4 ; =0x00000385
	mov r6, #1
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	b _02012DCE
_02012DCC:
	mov r6, #1
_02012DCE:
	add r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02012DD4: .word 0x00000385
	thumb_func_end sub_02012D4C
