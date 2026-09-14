	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E6704
	.extern ov87_021E6B38
	.extern ov87_021E6BA8
	.extern ov87_021E6C04
	.extern ov87_021E79C4
	.extern ov87_021E7A04
	.extern ov87_021E7A2C
	.extern ov87_021E7F6C
	.extern ov87_021E7FD4
	.extern ov87_021E7FE0
	.extern ov87_021E7FEC
	.extern ov87_021E80C0
	.extern ov87_021E81A0
	.extern ov87_021E82E4
	.public ov87_021E68DC

	.text

thumb_func_start ov87_021E68DC
ov87_021E68DC: ; 0x021E68DC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0xcf
	mov r1, #0x7a
	bl NARC_New
	mov r1, #0xe
	lsl r1, r1, #6
	str r0, [r5, r1]
	add r0, r5, #0
	bl ov87_021E6B38
	add r0, r5, #0
	bl ov87_021E6BA8
	mov r1, #0x1b
	mov r0, #1
	lsl r2, r1, #4
	mov r3, #0x7a
	bl NewMsgDataFromNarc
	str r0, [r5, #0x38]
	mov r0, #0x7a
	bl MessageFormat_New
	str r0, [r5, #0x3c]
	mov r0, #0x96
	lsl r0, r0, #2
	mov r1, #0x7a
	bl String_New
	str r0, [r5, #0x40]
	mov r0, #0x96
	lsl r0, r0, #2
	mov r1, #0x7a
	bl String_New
	mov r1, #0x1a
	str r0, [r5, #0x44]
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x7a
	bl LoadFontPal0
	mov r1, #0x1a
	mov r0, #4
	lsl r1, r1, #4
	mov r2, #0x7a
	bl LoadFontPal0
	mov r1, #6
	mov r0, #0
	lsl r1, r1, #6
	mov r2, #0x7a
	bl LoadFontPal1
	mov r1, #6
	mov r0, #4
	lsl r1, r1, #6
	mov r2, #0x7a
	bl LoadFontPal1
	mov r0, #2
	mov r1, #0x7a
	bl FontID_Alloc
	mov r0, #0xf
	mov r1, #0xe
	mov r2, #0
	mov r3, #0x7a
	bl MessagePrinter_New
	mov r1, #0x16
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r1, r5, #0
	ldr r0, [r5, #0x58]
	add r1, #0x5c
	bl ov87_021E80C0
	mov r0, #0
	mov r1, #1
	mov r2, #0xc
	mov r3, #0x7a
	bl sub_020163E0
	str r0, [r5, #0x34]
	add r0, r5, #0
	bl ov87_021E79C4
	add r0, r5, #0
	bl ov87_021E7A04
	add r0, r5, #0
	bl ov87_021E7A2C
	bl GfGfx_BothDispOn
	mov r7, #0
	mov r6, #0x1a
	add r4, r5, #0
_021E69A8:
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, #0x5b
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	add r2, r7, #0
	mov r3, #0x3c
	bl ov87_021E7F6C
	mov r1, #0xbe
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #0
	bl ov87_021E7FD4
	add r7, r7, #1
	add r6, #0x2a
	add r4, r4, #4
	cmp r7, #4
	blt _021E69A8
	ldr r4, _021E6ACC ; =ov87_021E82E4
	mov r7, #0
	add r6, r5, #0
_021E69E8:
	ldrh r0, [r4, #2]
	mov r1, #1
	mov r2, #0
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xa
	str r0, [sp, #0xc]
	mov r0, #0x5b
	lsl r0, r0, #2
	ldrh r3, [r4]
	add r0, r5, r0
	bl ov87_021E7F6C
	mov r1, #0xc2
	lsl r1, r1, #2
	str r0, [r6, r1]
	add r0, r1, #0
	ldr r0, [r6, r0]
	mov r1, #0
	bl ov87_021E7FD4
	add r7, r7, #1
	add r4, r4, #4
	add r6, r6, #4
	cmp r7, #9
	blt _021E69E8
	add r0, r5, #0
	bl ov87_021E6704
	ldr r4, _021E6AD0 ; =ov87_021E81A0
	mov r7, #0
	add r6, r5, #0
_021E6A2E:
	ldrh r0, [r4, #2]
	mov r1, #2
	add r2, r7, #0
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r0, #0x5b
	lsl r0, r0, #2
	ldrh r3, [r4]
	add r0, r5, r0
	bl ov87_021E7F6C
	mov r1, #0xcb
	lsl r1, r1, #2
	str r0, [r6, r1]
	add r0, r1, #0
	mov r1, #0
	ldrsh r2, [r4, r1]
	mov r1, #1
	lsl r1, r1, #8
	sub r1, r2, r1
	mov r2, #2
	ldrsh r2, [r4, r2]
	ldr r0, [r6, r0]
	bl ov87_021E7FEC
	mov r0, #0xcb
	lsl r0, r0, #2
	add r1, r7, #0
	ldr r0, [r6, r0]
	add r1, #0x14
	bl ov87_021E7FE0
	add r7, r7, #1
	add r4, r4, #4
	add r6, r6, #4
	cmp r7, #4
	blt _021E6A2E
	mov r0, #0x38
	str r0, [sp]
	mov r2, #0
	str r2, [sp, #4]
	str r2, [sp, #8]
	mov r0, #0xa
	str r0, [sp, #0xc]
	mov r0, #0x5b
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #4
	mov r3, #0x26
	bl ov87_021E7F6C
	mov r1, #0xd7
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	mov r1, #0
	bl ov87_021E7FD4
	ldr r2, _021E6AD4 ; =0x04000304
	ldr r0, _021E6AD8 ; =0xFFFF7FFF
	ldrh r1, [r2]
	and r0, r1
	strh r0, [r2]
	bl sub_020210BC
	mov r0, #1
	bl sub_02021148
	ldr r0, _021E6ADC ; =ov87_021E6C04
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6ACC: .word ov87_021E82E4
_021E6AD0: .word ov87_021E81A0
_021E6AD4: .word 0x04000304
_021E6AD8: .word 0xFFFF7FFF
_021E6ADC: .word ov87_021E6C04
	thumb_func_end ov87_021E68DC
