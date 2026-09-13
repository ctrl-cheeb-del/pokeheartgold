	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225E898
	.extern ov93_0225EA6C
	.extern ov93_0225EA98
	.extern ov93_0225EAE0
	.extern ov93_0225EB38
	.extern ov93_0225EB70
	.extern ov93_0225EDB8
	.extern ov93_0225EDE8
	.extern ov93_0225EDFC

	thumb_func_start ov93_0225E898
ov93_0225E898: ; 0x0225E898
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	mov r1, #0x91
	add r5, r0, #0
	mov r0, #0
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r5, #0x20]
	cmp r0, #2
	bne _0225E8D8
	ldr r0, _0225EA38 ; =0x00001758
	add r2, r1, #0
	ldr r3, [r5, r0]
	sub r2, #0x38
	str r3, [r4, r2]
	add r2, r0, #4
	ldr r3, [r5, r2]
	add r2, r1, #0
	sub r2, #0x34
	str r3, [r4, r2]
	add r2, r0, #0
	add r2, #8
	ldr r3, [r5, r2]
	add r2, r1, #0
	sub r2, #0x30
	str r3, [r4, r2]
	add r0, #0xc
	ldr r0, [r5, r0]
	sub r1, #0x2c
	str r0, [r4, r1]
	b _0225E920
_0225E8D8:
	ldr r0, _0225EA3C ; =0x00002FB8
	ldr r2, [r5, r0]
	cmp r2, #0
	beq _0225E8E8
	add r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _0225E900
_0225E8E8:
	mov r1, #0x83
	lsl r1, r1, #2
	mov r2, #0
	str r2, [r4, r1]
	add r0, r1, #4
	str r2, [r4, r0]
	add r0, r1, #0
	add r0, #8
	str r2, [r4, r0]
	add r1, #0xc
	str r2, [r4, r1]
	b _0225E920
_0225E900:
	ldr r2, _0225EA40 ; =gSystem + 0x40
	add r0, r1, #0
	ldrh r3, [r2, #0x20]
	sub r0, #0x38
	str r3, [r4, r0]
	add r0, r1, #0
	ldrh r3, [r2, #0x22]
	sub r0, #0x34
	str r3, [r4, r0]
	add r0, r1, #0
	ldrh r3, [r2, #0x26]
	sub r0, #0x30
	sub r1, #0x2c
	str r3, [r4, r0]
	ldrh r0, [r2, #0x24]
	str r0, [r4, r1]
_0225E920:
	add r0, r4, #0
	bl ov93_0225F370
	mov r0, #0x85
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0225E946
	add r0, r4, #0
	bl ov93_0225EB38
	ldr r0, [r4, #0x20]
	cmp r0, #0
	bne _0225E946
	bne _0225E946
	mov r0, #0x9d
	mov r1, #0
	lsl r0, r0, #2
	strb r1, [r4, r0]
_0225E946:
	add r0, r4, #0
	bl ov93_0225F44C
	add r0, r4, #0
	bl ov93_0225EB70
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov93_0225FB6C
	mov r0, #0x9a
	lsl r0, r0, #2
	ldrsh r1, [r4, r0]
	cmp r1, #0
	ble _0225E97C
	add r1, #8
	strh r1, [r4, r0]
	ldrsh r1, [r4, r0]
	cmp r1, #0x1e
	ble _0225E976
	mov r1, #0x1e
	strh r1, [r4, r0]
_0225E976:
	add r0, r4, #0
	bl ov93_0225EDFC
_0225E97C:
	ldr r0, _0225EA44 ; =0x00002FBC
	ldr r1, [r5, r0]
	cmp r1, #0
	bne _0225EA34
	sub r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _0225EA34
	mov r2, #0x91
	lsl r2, r2, #2
	ldr r1, [r4, r2]
	cmp r1, #0
	ble _0225EA34
	add r0, r2, #0
	add r0, #0x18
	ldr r0, [r4, r0]
	add r2, #0xdc
	mov r7, #0
	cmp r0, r2
	bge _0225E9C4
	add r0, r4, #0
	bl ov93_0225EDB8
	cmp r0, #1
	bne _0225E9D4
	mov r0, #0x9a
	mov r1, #8
	lsl r0, r0, #2
	strh r1, [r4, r0]
	add r1, r7, #0
	add r0, #0xd
	strb r1, [r4, r0]
	ldr r0, _0225EA48 ; =0x0000058E
	bl PlaySE
	b _0225E9D4
_0225E9C4:
	add r0, r4, #0
	bl ov93_0225EDE8
	mov r0, #0x9a
	add r1, r7, #0
	lsl r0, r0, #2
	strh r1, [r4, r0]
	mov r7, #1
_0225E9D4:
	mov r1, #0x91
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov93_0225EA6C
	add r6, r0, #0
	cmp r7, #1
	bne _0225E9F2
	mov r0, #0x19
	mul r0, r6
	mov r1, #0x64
	bl _s32_div_f
	add r6, r6, r0
_0225E9F2:
	ldr r1, _0225EA4C ; =0x00002FC8
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r2, r6, #0
	add r3, sp, #0
	bl ov93_02260F14
	add r0, r5, #0
	add r1, sp, #0
	bl ov93_02260F3C
	add r0, r5, #0
	add r1, sp, #0
	bl ov93_0225FEC4
	mov r1, #0x91
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov93_0225EA98
	mov r2, #0x91
	lsl r2, r2, #2
	ldr r2, [r4, r2]
	add r0, r5, #0
	add r1, r4, #0
	add r3, r7, #0
	bl ov93_0225EAE0
	mov r0, #0x91
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
_0225EA34:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225EA38: .word 0x00001758
_0225EA3C: .word 0x00002FB8
_0225EA40: .word gSystem + 0x40
_0225EA44: .word 0x00002FBC
_0225EA48: .word 0x0000058E
_0225EA4C: .word 0x00002FC8
	thumb_func_end ov93_0225E898
