	.include "asm/macros.inc"
	.public _0225D5C0
	.public _0225D5C4
	.public _0225D5C8
	.public _0225D62C
	.public _0225D630
	.public _0225D796
	.public _0225D82C
	.public _0225D830
	.public _0225D980
	.public _0225D984
	.public _0225D99C
	.public _0225D9A0
	.public _0225D9D4
	.public _0225DA7C
	.public _0225DA80
	.public _0225DA84
	.public _0225DCB2
	.public _0225DCCC
	.public _0225DCD0
	.public _0225DD64
	.public _0225DDA0
	.public _0225DDA4
	.public _0225DDA8
	.public _0225DDDE
	.public _0225DDE6
	.public _0225DDF4
	.public _0225DE02
	.public _0225DE18
	.public _0225DE22
	.public _0225DE56
	.public _0225DE6C
	.public _0225DE8E
	.public _0225DEA0
	.public _0225DEA8
	.public _0225DEB2
	.public _0225DEBA
	.public _0225DEEA
	.public _0225DF0A
	.public _0225DF2A
	.public _0225DF3A
	.public _0225DF50
	.public _0225DF62
	.public _0225DF68
	.public _0225DF6C
	.public _0225DF70
	.public _0225DF74
	.public _0225DF78
	.public _0225DF7C
	.public _0225DFB0
	.public _0225DFBC
	.public _0225DFC6
	.public _0225DFCA
	.public _0225DFE4
	.public _0225E00C
	.public _0225E05E
	.public _0225E070
	.public _0225E092
	.public _0225E0A2
	.public _0225E0F4
	.public _0225E0F8
	.public _0225E158
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D60C
	.public ov32_0225D788
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.public ov32_0225E168
	.public ov32_0225E178
	.public ov32_0225E188
	.public ov32_0225E1A4
	.public ov32_0225E1C0
	.public ov32_0225E1DC
	.public ov32_0225E204
	.public ov32_0225E24C
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D60C
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D788
	.public ov32_0225D834
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF80
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.include "overlay_32.inc"
	.include "global.inc"

	.text
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D834
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DF80

	thumb_func_start ov32_0225DB1C
ov32_0225DB1C: ; 0x0225DB1C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [sp, #0x30]
	add r6, r2, #0
	str r0, [sp]
	mov r0, #2
	add r4, r1, #0
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	add r2, r3, #0
	ldr r0, [r4]
	add r1, r6, #0
	mov r3, #1
	bl AddCharResObjFromOpenNarc
	str r0, [r5]
	bl SpriteTransfer_CreateCharTransferTask_AllocAtEnd
	ldr r0, [r5]
	bl sub_0200A740
	ldr r0, [sp, #0x34]
	ldr r2, [sp, #0x20]
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x2c]
	add r1, r6, #0
	str r0, [sp, #8]
	mov r0, #8
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	mov r3, #0
	bl AddPlttResObjFromOpenNarc
	str r0, [r5, #4]
	bl SpriteTransfer_CreatePlttTransferTask
	ldr r0, [r5, #4]
	bl sub_0200A740
	ldr r0, [sp, #0x38]
	ldr r2, [sp, #0x24]
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	ldr r0, [r4, #8]
	add r1, r6, #0
	mov r3, #1
	bl AddCellOrAnimResObjFromOpenNarc
	str r0, [r5, #8]
	ldr r0, [sp, #0x3c]
	ldr r2, [sp, #0x28]
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	ldr r0, [r4, #0xc]
	add r1, r6, #0
	mov r3, #1
	bl AddCellOrAnimResObjFromOpenNarc
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov32_0225DB1C


	thumb_func_start ov32_0225DBAC
ov32_0225DBAC: ; 0x0225DBAC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	add r7, r2, #0
	add r6, r3, #0
	bl GF2DGfxResObj_GetResID
	str r0, [sp, #0x2c]
	ldr r0, [r5, #4]
	bl GF2DGfxResObj_GetResID
	str r0, [sp, #0x30]
	ldr r0, [r5, #8]
	bl GF2DGfxResObj_GetResID
	str r0, [sp, #0x34]
	ldr r0, [r5, #0xc]
	bl GF2DGfxResObj_GetResID
	str r0, [sp]
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r6, [sp, #0x10]
	ldr r1, [r4]
	ldr r2, [sp, #0x30]
	str r1, [sp, #0x14]
	ldr r1, [r4, #4]
	ldr r3, [sp, #0x34]
	str r1, [sp, #0x18]
	ldr r1, [r4, #8]
	str r1, [sp, #0x1c]
	ldr r1, [r4, #0xc]
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	add r0, r7, #0
	bl CreateSpriteResourcesHeader
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov32_0225DBAC


	thumb_func_start ov32_0225DC0C
ov32_0225DC0C: ; 0x0225DC0C
	push {r4, r5, r6, lr}
	sub sp, #0x30
	add r5, r3, #0
	mov r3, #0x53
	add r4, r0, #0
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	lsl r6, r1, #2
	str r2, [sp, #4]
	str r0, [sp]
	ldrb r0, [r5]
	mov r2, #1
	lsl r2, r2, #0x14
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	ldrb r0, [r5, #1]
	lsl r0, r0, #0xc
	add r0, r0, r2
	lsr r2, r2, #8
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	str r2, [sp, #0x1c]
	add r2, sp, #0
	strh r0, [r2, #0x20]
	ldrb r0, [r5, #2]
	str r0, [sp, #0x24]
	mov r0, #2
	str r0, [sp, #0x28]
	mov r0, #8
	str r0, [sp, #0x2c]
	lsl r0, r3, #1
	add r4, r4, r0
	add r0, sp, #0
	bl Sprite_CreateAffine
	str r0, [r4, r6]
	ldrb r1, [r5, #3]
	ldr r0, [r4, r6]
	bl Sprite_SetAnimCtrlSeq
	add sp, #0x30
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov32_0225DC0C


	thumb_func_start ov32_0225DC68
ov32_0225DC68: ; 0x0225DC68
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r6, r0, #0
	mov r0, #7
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #1
	str r0, [sp, #0xc]
	ldr r0, _0225DCCC ; =0x00000781
	add r2, r1, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r1, #0xa2
	str r0, [sp, #0x18]
	lsl r1, r1, #2
	str r0, [sp, #0x1c]
	add r0, r6, r1
	sub r1, #0x10
	add r1, r6, r1
	mov r3, #4
	bl ov32_0225DB1C
	mov r1, #0xa2
	lsl r1, r1, #2
	add r0, r6, r1
	sub r1, #0x10
	add r1, r6, r1
	add r2, sp, #0x20
	mov r3, #1
	bl ov32_0225DBAC
	ldr r5, _0225DCD0 ; =ov32_0225E178
	mov r4, #0
	add r7, sp, #0x20
_0225DCB2:
	add r0, r6, #0
	add r1, r4, #0
	add r2, r7, #0
	add r3, r5, #0
	bl ov32_0225DC0C
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blo _0225DCB2
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_0225DCCC: .word 0x00000781
_0225DCD0: .word ov32_0225E178
	thumb_func_end ov32_0225DC68
