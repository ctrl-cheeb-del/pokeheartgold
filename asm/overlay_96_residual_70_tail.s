	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	.public ov96_021FA0E8

	thumb_func_start ov96_021FA0E8
ov96_021FA0E8: ; 0x021FA0E8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	ldr r5, [sp, #0x60]
	str r0, [sp]
	ldr r4, [sp, #0x64]
	mov r0, #0
	strh r0, [r4]
	add r6, r1, #0
	strh r0, [r4, #2]
	mov r1, #0x30
	strh r1, [r4, #4]
	mov r1, #5
	lsl r1, r1, #6
	strh r1, [r4, #6]
	add r1, r4, #0
	str r2, [sp, #4]
	strb r5, [r4, #0x18]
	mov r2, #1
	add r1, #0x68
	strh r2, [r1]
	mov r1, #0xfe
	lsl r1, r1, #0x16
	str r1, [r4, #0x64]
	strb r0, [r4, #8]
	add r0, r3, #0
	add r1, r5, #0
	bl ov96_021FC0D0
	str r0, [r4, #0x20]
	cmp r5, #0
	beq _021FA130
	cmp r5, #1
	beq _021FA13A
	cmp r5, #2
	beq _021FA144
	b _021FA14C
_021FA130:
	mov r0, #0
	strh r0, [r4, #0x14]
	mov r0, #4
	strh r0, [r4, #0x16]
	b _021FA14C
_021FA13A:
	mov r0, #1
	strh r0, [r4, #0x14]
	mov r0, #5
	strh r0, [r4, #0x16]
	b _021FA14C
_021FA144:
	mov r0, #2
	strh r0, [r4, #0x14]
	mov r0, #6
	strh r0, [r4, #0x16]
_021FA14C:
	cmp r5, #0
	beq _021FA15A
	cmp r5, #1
	beq _021FA162
	cmp r5, #2
	beq _021FA16A
	b _021FA172
_021FA15A:
	mov r0, #0x30
	mov r1, #0
	str r0, [sp, #8]
	b _021FA17A
_021FA162:
	mov r0, #0x80
	mov r1, #1
	str r0, [sp, #8]
	b _021FA17A
_021FA16A:
	mov r0, #0xd0
	mov r1, #2
	str r0, [sp, #8]
	b _021FA17A
_021FA172:
	bl GF_AssertFail
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
_021FA17A:
	lsl r1, r1, #0x18
	ldr r0, [sp, #0x5c]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [sp, #0xc]
	bl ov96_021EAA20
	ldr r1, [sp, #0xc]
	str r1, [r4, #0x24]
	bl ov96_021E8BB0
	str r0, [sp, #0x10]
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	add r2, r5, #0
	bl ov96_021E60D8
	add r7, r0, #0
	ldrb r0, [r7, #2]
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	add r0, r4, #0
	add r0, #0x5c
	strh r1, [r0]
	ldrb r0, [r7, #2]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r1, [r0, #0x14]
	add r0, r4, #0
	add r0, #0x5e
	strh r1, [r0]
	add r0, r4, #0
	ldrb r1, [r7, #2]
	add r0, #0x58
	strb r1, [r0]
	ldr r0, [sp]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp]
	add r2, r5, #0
	bl ov96_021E60C0
	bl ov96_021E6138
	sub r0, r0, #1
	lsl r2, r0, #3
	ldr r1, [sp, #4]
	ldr r3, [sp, #4]
	ldr r1, [r1, r2]
	add r2, r3, r2
	ldr r0, [sp, #0xc]
	ldr r2, [r2, #4]
	bl ov96_021EAF70
	bl ov96_021E6104
	add r1, r0, #0
	ldr r0, [sp, #0xc]
	bl ov96_021EAF6C
	ldrb r0, [r7, #1]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #0x3c]
	bl _fflt
	ldr r1, _021FA338 ; =0x41200000
	bl _fdiv
	str r0, [r4, #0x50]
	ldrb r0, [r7, #4]
	lsl r0, r0, #2
	add r0, r6, r0
	ldr r0, [r0, #0x28]
	bl _fflt
	ldr r1, _021FA33C ; =0x42C80000
	bl _fdiv
	str r0, [r4, #0x54]
	ldr r0, [sp, #0x10]
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _021FA236
	mov r0, #2
	lsl r0, r0, #0x10
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
	b _021FA23E
_021FA236:
	mov r0, #1
	lsl r0, r0, #0x10
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
_021FA23E:
	mov r3, #0x78
	str r3, [r4, #0x3c]
	add r2, r3, #0
	add r3, #0x98
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #8]
	add r2, r2, r3
	bl ov96_021EAF94
	ldr r0, [sp, #0xc]
	mov r1, #1
	bl ov96_021EAC0C
	ldr r0, [sp, #0xc]
	mov r1, #4
	bl ov96_021EABA8
	ldr r0, [sp, #0xc]
	mov r1, #2
	bl ov96_021EABE0
	ldr r0, [sp, #0xc]
	add r1, sp, #0x38
	bl ov96_021EABF4
	ldr r0, [sp, #0x58]
	mov r1, #0x66
	mov r2, #5
	bl ov96_021EB4F4
	str r0, [r4, #0x44]
	bl ov96_021EB5B8
	mov r1, #0x12
	ldr r2, [r4, #0x3c]
	lsl r1, r1, #4
	add r1, r2, r1
	str r1, [r4, #0x40]
	mov r1, #0
	str r1, [sp, #0x34]
	ldr r1, [sp, #8]
	add r6, r0, #0
	lsl r5, r1, #0xc
	str r5, [sp, #0x2c]
	ldr r1, [r4, #0x40]
	lsl r1, r1, #0xc
	str r1, [sp, #0x30]
	add r1, sp, #0x2c
	bl Sprite_SetMatrix
	ldr r0, [r4, #0x44]
	mov r1, #1
	mov r2, #0
	bl ov96_021EB52C
	add r0, r6, #0
	mov r1, #3
	bl Sprite_SetDrawPriority
	ldr r0, [sp, #0x58]
	mov r1, #0x68
	mov r2, #7
	bl ov96_021EB4F4
	str r0, [r4, #0x48]
	bl ov96_021EB5B8
	mov r1, #0
	add r6, r0, #0
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0
	str r0, [sp, #0x28]
	mov r0, #0x6b
	lsl r0, r0, #0xe
	str r0, [sp, #0x24]
	add r0, r6, #0
	add r1, sp, #0x20
	str r5, [sp, #0x20]
	bl Sprite_SetMatrix
	add r0, r6, #0
	mov r1, #4
	bl Sprite_SetDrawPriority
	add r0, r6, #0
	mov r1, #2
	bl Sprite_SetAffineOverwriteMode
	ldr r0, [sp, #0x58]
	mov r1, #0x69
	mov r2, #8
	bl ov96_021EB4F4
	str r0, [r4, #0x4c]
	bl ov96_021EB5B8
	mov r1, #0
	add r6, r0, #0
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0
	str r0, [sp, #0x1c]
	mov r0, #0x62
	lsl r0, r0, #0xe
	str r0, [sp, #0x18]
	str r5, [sp, #0x14]
	add r0, r6, #0
	add r1, sp, #0x14
	bl Sprite_SetMatrix
	mov r1, #1
	ldr r0, [r4, #0x4c]
	add r2, r1, #0
	bl ov96_021EB52C
	add r0, r6, #0
	mov r1, #2
	bl Sprite_SetDrawPriority
	mov r0, #0xfe
	lsl r0, r0, #0x16
	str r0, [r4, #0xc]
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FA338: .word 0x41200000
_021FA33C: .word 0x42C80000
	thumb_func_end ov96_021FA0E8
