	.include "asm/macros.inc"
	.include "unk_0205AC88.inc"
	.include "global.inc"

	.public _020FC824

	.text

	thumb_func_start sub_0205AD9C
sub_0205AD9C: ; 0x0205AD9C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	mov r5, #0
	str r0, [sp]
	str r3, [sp, #4]
	cmp r2, #0
	bne _0205ADD0
	ldr r0, _0205AE9C ; =_020FC824
	lsl r1, r1, #1
	ldrh r4, [r0, r1]
	ldr r0, [sp]
	mov r6, #3
	add r0, #0xc
	str r0, [sp]
_0205ADB8:
	ldr r0, [sp]
	add r1, r4, #0
	add r2, r6, #0
	bl sub_0205AEA0
	add r5, r5, #1
	add r4, r4, #1
	cmp r5, #4
	blt _0205ADB8
	add sp, #0x14
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_0205ADD0:
	add r0, r2, #0
	str r0, [sp, #0xc]
	add r0, #0x50
	str r0, [sp, #0xc]
	add r0, #0x30
	str r0, [sp, #0xc]
	ldr r0, [r2, #0x50]
	mov r2, #0x18
	add r3, r1, #0
	mul r3, r2
	ldr r2, [sp]
	add r2, r2, r3
	ldr r2, [r2, #0x18]
	cmp r0, r2
	beq _0205AE14
	ldr r0, _0205AE9C ; =_020FC824
	lsl r1, r1, #1
	ldrh r4, [r0, r1]
	ldr r0, [sp]
	mov r6, #3
	add r0, #0xc
	str r0, [sp]
_0205ADFC:
	ldr r0, [sp]
	add r1, r4, #0
	add r2, r6, #0
	bl sub_0205AEA0
	add r5, r5, #1
	add r4, r4, #1
	cmp r5, #4
	blt _0205ADFC
	add sp, #0x14
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_0205AE14:
	ldr r0, _0205AE9C ; =_020FC824
	lsl r1, r1, #1
	ldrh r7, [r0, r1]
	ldr r0, [sp, #0xc]
	add r6, r5, #0
	str r0, [sp, #8]
	ldr r0, [sp]
	str r0, [sp, #0x10]
	add r0, #0xc
	str r0, [sp, #0x10]
_0205AE28:
	mov r0, #0x18
	add r1, r7, #0
	mul r1, r0
	ldr r0, [sp]
	add r4, r0, r1
	ldrb r0, [r4, #0xd]
	cmp r0, #0
	beq _0205AE42
	cmp r0, #2
	beq _0205AE68
	cmp r0, #4
	beq _0205AE82
	b _0205AE86
_0205AE42:
	ldr r0, [sp, #0xc]
	add r1, r0, r6
	ldrb r0, [r1, #0x18]
	cmp r0, #0
	beq _0205AE86
	mov r0, #2
	strb r0, [r4, #0xc]
	ldrb r1, [r1, #0x18]
	mov r0, #0x7f
	and r0, r1
	strb r0, [r4, #0x14]
	ldr r1, [sp, #8]
	ldr r0, [sp, #4]
	ldr r1, [r1]
	bl PalPad_PlayerIdIsFriendOrMutual
	strb r0, [r4, #0xe]
	mov r5, #1
	b _0205AE86
_0205AE68:
	ldr r0, [sp, #0xc]
	add r0, r0, r6
	ldrb r0, [r0, #0x18]
	cmp r0, #0
	bne _0205AE7E
	ldr r0, [sp, #0x10]
	add r1, r7, #0
	mov r2, #3
	bl sub_0205AEA0
	b _0205AE86
_0205AE7E:
	mov r5, #1
	b _0205AE86
_0205AE82:
	mov r0, #0
	strb r0, [r4, #0xc]
_0205AE86:
	ldr r0, [sp, #8]
	add r6, r6, #1
	add r0, r0, #4
	add r7, r7, #1
	str r0, [sp, #8]
	cmp r6, #4
	blt _0205AE28
	add r0, r5, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_0205AE9C: .word _020FC824
	thumb_func_end sub_0205AD9C
