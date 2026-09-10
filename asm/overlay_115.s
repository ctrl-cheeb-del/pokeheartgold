	.include "asm/macros.inc"
	.public _02260374
	.public ov115_0225F020
	.public ov115_0225F09C
	.public ov115_0225F0B4
	.public ov115_0225F158
	.public ov115_0225F1BC
	.public ov115_0225F220
	.public ov115_0225F704
	.public ov115_0225F728
	.public ov115_0225F74C
	.public ov115_0225F770
	.public ov115_0225F794
	.public ov115_0225F7B8
	.public ov115_0225F7DC
	.public ov115_0225F800
	.public ov115_0225F824
	.public ov115_0225F848
	.public ov115_0225F86C
	.public ov115_0225F890
	.public ov115_0225F8B4
	.public ov115_0225F8D8
	.public ov115_0225F8FC
	.public ov115_0225F920
	.public ov115_0225F944
	.public ov115_0225F968
	.public ov115_0225F978
	.public ov115_02260254
	.public ov115_022602C0
	.public ov115_022602E4
	.public ov115_02260308
	.public ov115_0226032C
	.public ov115_02260350
	.public ov115_02260388
	.public ov115_02260390
	.public ov115_02260398
	.public ov115_022603A0
	.public ov115_022603A8
	.public ov115_022603B0
	.public ov115_022603C4
	.public ov115_022603D8
	.public ov115_022603EC
	.public ov115_02260400
	.public ov115_02260414
	.public ov115_02260428
	.public ov115_0226043C
	.public ov115_02260450
	.public ov115_02260464
	.public ov115_02260478
	.public ov115_0226048C
	.public ov115_022604A0
	.public ov115_022604B4
	.public ov115_022604C8
	.public ov115_022604DC
	.include "overlay_115.inc"
	.include "global.inc"

	.text
	.public ov115_0225F09C
	.public ov115_0225F158
	.public ov115_0225F1BC
	.public ov115_0225F704
	.public ov115_0225F728
	.public ov115_0225F74C
	.public ov115_0225F770
	.public ov115_0225F794
	.public ov115_0225F7B8
	.public ov115_0225F7DC
	.public ov115_0225F800
	.public ov115_0225F824
	.public ov115_0225F848
	.public ov115_0225F86C
	.public ov115_0225F890
	.public ov115_0225F8B4
	.public ov115_0225F8D8
	.public ov115_0225F8FC
	.public ov115_0225F920
	.public ov115_0225F944
	.public ov115_0225F968
	.public ov115_022602C0
	.public ov115_022602E4
	.public ov115_02260308
	.public ov115_0226032C
	.public ov115_02260350

	thumb_func_start ov115_0225F020
ov115_0225F020: ; 0x0225F020
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r6, #0
	strh r6, [r5]
	add r4, r5, #0
	ldr r7, [sp, #0x28]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	strh r6, [r5, #2]
	add r4, #0x14
_0225F038:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	ldr r2, [sp, #0x10]
	add r3, r7, #0
	bl ov01_021F0718
	str r0, [r5, #4]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r5, #4]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	cmp r6, #3
	beq _0225F07E
	ldr r0, [r5, #4]
	mov r1, #2
	bl Sprite_SetAffineOverwriteMode
	ldr r0, [r5, #4]
	mov r1, #1
	bl Sprite_SetAnimCtrlSeq
	mov r1, #2
	lsl r1, r1, #0xc
	add r0, r4, #0
	lsr r2, r1, #1
	mov r3, #6
	bl ov01_021EFE70
	b _0225F08C
_0225F07E:
	mov r1, #1
	lsl r1, r1, #0xc
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #6
	bl ov01_021EFE70
_0225F08C:
	add r6, r6, #1
	add r5, r5, #4
	add r4, #0x14
	cmp r6, #4
	blt _0225F038
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov115_0225F020
