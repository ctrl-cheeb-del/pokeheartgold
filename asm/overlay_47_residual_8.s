	.include "asm/macros.inc"
	.include "overlay_47.inc"
	.include "global.inc"
	.include "overlay47_exact_bank.inc"

	.text
	.public ov47_02258A14
	.public ov47_02258A1C
	.public ov47_02258A60
	.public ov47_02258A80
	.public ov47_02258A8C
	.public ov47_02258B8C
	.public ov47_02258C44
	.public ov47_02258CC0
	.public ov47_02258CEC
	.public ov47_02258D18
	.public ov47_02258D44
	.public ov47_02258D78
	.public ov47_02258DA8
	.public ov47_02258DB4
	.public ov47_022591F8
	.public ov47_0225921C
	.public ov47_02259228
	.public ov47_02259278
	.public ov47_022592B4
	.public ov47_02259318
	.public ov47_02259384
	.public ov47_022593A0
	.public ov47_022593B4
	.public ov47_022593CC
	.public ov47_02259404
	.public ov47_02259430
	.public ov47_02259448
	.public ov47_0225945C
	.public ov47_0225946C
	.public ov47_02259968
	.public ov47_0225999C
	.public ov47_02259B30
	.public ov47_02259D24
	.public ov47_02259D40
	.public ov47_02259D58
	.public ov47_02259DA4
	.public ov47_02259DCC

	thumb_func_start ov47_02259B74
ov47_02259B74: ; 0x02259B74
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	add r6, r0, #0
	ldr r0, [r6, #0x64]
	cmp r0, #0x14
	blt _02259B86
	add sp, #0x2c
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02259B86:
	add r1, r0, #1
	mov r0, #0x50
	str r1, [r6, #0x64]
	mul r0, r1
	mov r1, #0x14
	bl _s32_div_f
	str r0, [sp, #0x24]
	mov r0, #0
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r6, [sp, #0x18]
_02259B9E:
	ldr r0, [sp, #0x18]
	ldr r2, [r0, #0x74]
	ldr r0, [r0, #0x68]
	cmp r0, r2
	bne _02259BB0
	ldr r0, [sp, #0x1c]
	add r0, r0, #1
	str r0, [sp, #0x1c]
	b _02259C18
_02259BB0:
	ldr r1, [sp, #0x24]
	cmp r2, r1
	blt _02259BBE
	sub r4, r1, r0
	add r2, r1, #0
	ldr r1, [sp, #0x18]
	b _02259BC2
_02259BBE:
	ldr r1, [sp, #0x18]
	sub r4, r2, r0
_02259BC2:
	mov r5, #0
	str r2, [r1, #0x68]
	cmp r4, #0
	ble _02259C0C
	ldr r1, [sp, #0x20]
	add r0, r0, #4
	add r1, r1, #2
	lsl r7, r1, #4
	str r0, [sp, #0x28]
_02259BD4:
	mov r0, #1
	lsl r0, r0, #8
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	add r1, r6, #0
	add r0, r0, r5
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	mov r0, #0x10
	str r0, [sp, #0x14]
	add r1, #0x84
	ldr r1, [r1]
	add r0, r6, r7
	ldr r1, [r1, #0x14]
	mov r2, #0xf7
	mov r3, #0x10
	bl BlitBitmapRectToWindow
	add r5, r5, #1
	cmp r5, r4
	blt _02259BD4
_02259C0C:
	ldr r0, [sp, #0x20]
	add r0, r0, #2
	lsl r0, r0, #4
	add r0, r6, r0
	bl ScheduleWindowCopyToVram
_02259C18:
	ldr r0, [sp, #0x18]
	add r0, r0, #4
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	add r0, r0, #1
	str r0, [sp, #0x20]
	cmp r0, #3
	blt _02259B9E
	ldr r0, [sp, #0x1c]
	cmp r0, #3
	bne _02259C34
	add sp, #0x2c
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_02259C34:
	mov r0, #0
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov47_02259B74


	thumb_func_start ov47_02259C3C
ov47_02259C3C: ; 0x02259C3C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	mov r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	add r7, r0, #0
	str r4, [sp, #8]
	mov r0, #5
	str r3, [sp, #0xc]
	lsl r0, r0, #6
	ldr r0, [r2, r0]
	str r1, [sp, #0x10]
	ldr r2, [r2]
	mov r1, #0xcb
	add r3, r4, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r5, r7, #0
	add r6, r4, #0
_02259C62:
	add r0, r5, #0
	add r1, r6, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	bl CopyWindowToVram
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #6
	blt _02259C62
	ldr r1, [sp, #0x10]
	ldr r3, _02259C88 ; =0x00050600
	add r0, r7, #0
	mov r2, #0x77
	bl ov47_0225999C
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02259C88: .word 0x00050600
	thumb_func_end ov47_02259C3C


	thumb_func_start ov47_02259C8C
ov47_02259C8C: ; 0x02259C8C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #1
	add r7, r2, #0
	str r1, [sp]
	lsl r0, r0, #8
	add r1, r7, #0
	bl String_New
	str r0, [r5, #0x10]
	mov r6, #0
	add r4, r5, #0
_02259CA4:
	mov r0, #1
	lsl r0, r0, #8
	add r1, r7, #0
	bl String_New
	str r0, [r4, #0x14]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #3
	blt _02259CA4
	ldr r0, [sp]
	cmp r0, #1
	bne _02259CC2
	mov r6, #0
	b _02259CC4
_02259CC2:
	mov r6, #4
_02259CC4:
	add r0, r6, #2
	bl ov45_0222F544
	str r0, [r5, #8]
	add r0, r6, #1
	bl ov45_0222F544
	str r0, [r5]
	add r0, r6, #0
	bl ov45_0222F544
	str r0, [r5, #4]
	add r0, r6, #3
	bl ov45_0222F544
	str r0, [r5, #0xc]
	cmp r0, #1
	bne _02259D20
	add r0, r6, #0
	bl ov45_0222F628
	add r4, r0, #0
	bne _02259CF6
	bl GF_AssertFail
_02259CF6:
	ldr r0, [r5, #0x10]
	add r1, r4, #0
	bl CopyU16ArrayToString
	mov r4, #0
	add r7, r6, #1
_02259D02:
	add r0, r7, r4
	bl ov45_0222F628
	add r6, r0, #0
	bne _02259D10
	bl GF_AssertFail
_02259D10:
	ldr r0, [r5, #0x14]
	add r1, r6, #0
	bl CopyU16ArrayToString
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #3
	blt _02259D02
_02259D20:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov47_02259C8C
