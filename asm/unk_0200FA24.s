	.include "asm/macros.inc"
	.include "unk_0200FA24.inc"
	.include "global.inc"

	.rodata

	.public sFadeFuncPtrs
sFadeFuncPtrs:
	.word FadeFunc_00
	.word FadeFunc_01
	.word FadeFunc_02
	.word FadeFunc_03
	.word FadeFunc_04
	.word FadeFunc_05
	.word FadeFunc_06
	.word FadeFunc_07
	.word FadeFunc_08
	.word FadeFunc_09
	.word FadeFunc_10
	.word FadeFunc_11
	.word FadeFunc_12
	.word FadeFunc_13
	.word FadeFunc_14
	.word FadeFunc_15
	.word FadeFunc_16
	.word FadeFunc_17
	.word FadeFunc_18
	.word FadeFunc_19
	.word FadeFunc_20
	.word FadeFunc_21
	.word FadeFunc_22
	.word FadeFunc_23
	.word FadeFunc_24
	.word FadeFunc_25
	.word FadeFunc_26
	.word FadeFunc_27
	.word FadeFunc_28
	.word FadeFunc_29
	.word FadeFunc_30
	.word FadeFunc_31
	.word FadeFunc_32
	.word FadeFunc_33
	.word FadeFunc_34
	.word FadeFunc_35
	.word FadeFunc_36
	.word FadeFunc_37
	.word FadeFunc_38
	.word FadeFunc_39
	.word FadeFunc_40
	.word FadeFunc_41
	.word FadeFunc_42

	.bss

	.public _021D0EF4
_021D0EF4:
	.space 0x4

	.public _021D0EF8
_021D0EF8:
	.space 0x4

	.public _021D0EFC
_021D0EFC:
	.space 0xC

	.public _021D0F08
_021D0F08:
	.space 0x30

	.public _021D0F38
_021D0F38:
	.space 0x30

	.public _021D0F68
_021D0F68:
	.space 0x18

	.public _021D0F80
_021D0F80:
	.space 0xB4

	.public _021D1034
_021D1034:
	.space 0x14

	.text

	thumb_func_start BeginNormalPaletteFade
BeginNormalPaletteFade: ; 0x0200FA24
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	ldr r0, [sp, #0x30]
	add r4, r1, #0
	add r7, r2, #0
	add r6, r3, #0
	cmp r0, #0
	bne _0200FA3A
	bl GF_AssertFail
_0200FA3A:
	ldr r0, [sp, #0x34]
	cmp r0, #0
	bne _0200FA44
	bl GF_AssertFail
_0200FA44:
	ldr r0, _0200FB00 ; =_021D1034
	ldrh r0, [r0, #0xc]
	cmp r0, #0
	beq _0200FA50
	bl GF_AssertFail
_0200FA50:
	ldr r0, _0200FB04 ; =_021D0EF4
	bl sub_020100C4
	ldr r1, _0200FB04 ; =_021D0EF4
	add r0, r5, #0
	bl sub_0200FE14
	ldr r0, _0200FB08 ; =_021D0F68
	bl sub_0200FEB0
	ldr r0, _0200FB04 ; =_021D0EF4
	add r1, r6, #0
	bl sub_02010018
	add r5, r0, #0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, _0200FB0C ; =_021D0F80
	ldr r2, [sp, #0x30]
	str r0, [sp, #0xc]
	ldr r0, _0200FB08 ; =_021D0F68
	ldr r3, [sp, #0x34]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x38]
	add r1, r4, #0
	str r0, [sp, #0x14]
	ldr r0, _0200FB10 ; =_021D0F08
	str r5, [sp, #0x18]
	bl sub_0200FE84
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _0200FB0C ; =_021D0F80
	ldr r2, [sp, #0x30]
	str r0, [sp, #0xc]
	ldr r0, _0200FB08 ; =_021D0F68
	ldr r3, [sp, #0x34]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x38]
	add r1, r7, #0
	str r0, [sp, #0x14]
	ldr r0, _0200FB14 ; =_021D0F38
	str r5, [sp, #0x18]
	bl sub_0200FE84
	ldr r0, _0200FB00 ; =_021D1034
	mov r1, #1
	strh r1, [r0, #0xc]
	ldr r0, _0200FB18 ; =_021D0EF8
	ldr r1, _0200FB10 ; =_021D0F08
	bl FadeWork_UpdateFrame
	ldr r0, _0200FB1C ; =_021D0EFC
	ldr r1, _0200FB14 ; =_021D0F38
	bl FadeWork_UpdateFrame
	ldr r0, _0200FB20 ; =_021D0EF4
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _0200FAE2
	ldr r0, _0200FB04 ; =_021D0EF4
	add r0, #0x14
	bl sub_02010064
	ldr r1, _0200FB24 ; =0x0000014E
	ldr r0, _0200FB04 ; =_021D0EF4
	mov r2, #1
	strb r2, [r0, r1]
_0200FAE2:
	ldr r0, _0200FB04 ; =_021D0EF4
	ldr r0, [r0, #0x10]
	cmp r0, #0
	beq _0200FAFA
	ldr r0, _0200FB04 ; =_021D0EF4
	add r0, #0x44
	bl sub_02010064
	ldr r1, _0200FB28 ; =0x0000014F
	ldr r0, _0200FB04 ; =_021D0EF4
	mov r2, #1
	strb r2, [r0, r1]
_0200FAFA:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_0200FB00: .word _021D1034
_0200FB04: .word _021D0EF4
_0200FB08: .word _021D0F68
_0200FB0C: .word _021D0F80
_0200FB10: .word _021D0F08
_0200FB14: .word _021D0F38
_0200FB18: .word _021D0EF8
_0200FB1C: .word _021D0EFC
_0200FB20: .word _021D0EF4
_0200FB24: .word 0x0000014E
_0200FB28: .word 0x0000014F
	thumb_func_end BeginNormalPaletteFade
	thumb_func_start HandleFadeUpdateFrame
HandleFadeUpdateFrame: ; 0x0200FB2C
	push {r4, lr}
	ldr r0, _0200FB54 ; =_021D1034
	ldr r4, _0200FB58 ; =_021D0EF4
	ldrh r0, [r0, #0xc]
	cmp r0, #0
	beq _0200FB50
	add r1, r4, #0
	add r2, r4, #0
	add r0, r4, #0
	add r1, #0x14
	add r2, #0x44
	bl DoFadeUpdateFrame
	cmp r0, #1
	bne _0200FB50
	add r0, r4, #0
	bl HandleEndFade
_0200FB50:
	pop {r4, pc}
	nop
_0200FB54: .word _021D1034
_0200FB58: .word _021D0EF4
	thumb_func_end HandleFadeUpdateFrame
	thumb_func_start IsPaletteFadeFinished
IsPaletteFadeFinished: ; 0x0200FB5C
	ldr r0, _0200FB6C ; =_021D1034
	ldrh r0, [r0, #0xc]
	cmp r0, #0
	bne _0200FB68
	mov r0, #1
	bx lr
_0200FB68:
	mov r0, #0
	bx lr
	.balign 4, 0
_0200FB6C: .word _021D1034
	thumb_func_end IsPaletteFadeFinished
	thumb_func_start sub_0200FB70
sub_0200FB70: ; 0x0200FB70
	push {r3, lr}
	ldr r0, _0200FBBC ; =_021D0F68
	mov r1, #0
	bl sub_0200FF5C
	ldr r0, _0200FBBC ; =_021D0F68
	mov r1, #1
	bl sub_0200FF5C
	ldr r0, _0200FBC0 ; =_021D0EF4
	ldr r1, [r0, #4]
	cmp r1, #0
	beq _0200FB8E
	mov r1, #2
	str r1, [r0, #0x20]
_0200FB8E:
	ldr r0, _0200FBC0 ; =_021D0EF4
	ldr r1, [r0, #8]
	cmp r1, #0
	beq _0200FB9A
	mov r1, #2
	str r1, [r0, #0x50]
_0200FB9A:
	ldr r0, _0200FBC4 ; =_021D0EF8
	ldr r1, _0200FBC8 ; =_021D0F08
	bl FadeWork_UpdateFrame
	ldr r0, _0200FBCC ; =_021D0EFC
	ldr r1, _0200FBD0 ; =_021D0F38
	bl FadeWork_UpdateFrame
	ldr r0, _0200FBD4 ; =_021D1034
	mov r1, #0
	strh r1, [r0, #0xc]
	strb r1, [r0, #0xe]
	strb r1, [r0, #0xf]
	ldr r0, _0200FBD8 ; =_021D0EF4
	bl sub_020100C4
	pop {r3, pc}
	.balign 4, 0
_0200FBBC: .word _021D0F68
_0200FBC0: .word _021D0EF4
_0200FBC4: .word _021D0EF8
_0200FBC8: .word _021D0F08
_0200FBCC: .word _021D0EFC
_0200FBD0: .word _021D0F38
_0200FBD4: .word _021D1034
_0200FBD8: .word _021D0EF4
	thumb_func_end sub_0200FB70
	thumb_func_start ResetVisibleHardwareWindows
ResetVisibleHardwareWindows: ; 0x0200FBDC
	ldr r3, _0200FBE4 ; =sub_020131F4
	add r1, r0, #0
	mov r0, #0
	bx r3
	.balign 4, 0
_0200FBE4: .word sub_020131F4
	thumb_func_end ResetVisibleHardwareWindows
	thumb_func_start SetMasterBrightnessNeutral
SetMasterBrightnessNeutral: ; 0x0200FBE8
	ldr r3, _0200FBF0 ; =SetMasterBrightness
	mov r1, #0
	bx r3
	nop
_0200FBF0: .word SetMasterBrightness
	thumb_func_end SetMasterBrightnessNeutral
	thumb_func_start sub_0200FBF4
sub_0200FBF4: ; 0x0200FBF4
	ldr r2, _0200FC10 ; =0x0000FFFF
	cmp r1, r2
	bne _0200FBFE
	ldr r1, _0200FC14 ; =_021D1034
	ldrh r1, [r1, #0x10]
_0200FBFE:
	ldr r2, _0200FC18 ; =0x00007FFF
	cmp r1, r2
	bne _0200FC08
	mov r1, #0x10
	b _0200FC0C
_0200FC08:
	mov r1, #0xf
	mvn r1, r1
_0200FC0C:
	ldr r3, _0200FC1C ; =SetMasterBrightness
	bx r3
	.balign 4, 0
_0200FC10: .word 0x0000FFFF
_0200FC14: .word _021D1034
_0200FC18: .word 0x00007FFF
_0200FC1C: .word SetMasterBrightness
	thumb_func_end sub_0200FBF4
	thumb_func_start sub_0200FC20
sub_0200FC20: ; 0x0200FC20
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _0200FC54 ; =0x0000FFFF
	cmp r4, r0
	bne _0200FC2E
	ldr r0, _0200FC58 ; =_021D1034
	ldrh r4, [r0, #0x10]
_0200FC2E:
	ldr r0, _0200FC5C ; =0x00007FFF
	cmp r4, r0
	bne _0200FC38
	mov r5, #0x10
	b _0200FC3C
_0200FC38:
	mov r5, #0xf
	mvn r5, r5
_0200FC3C:
	mov r0, #0
	add r1, r5, #0
	bl SetMasterBrightness
	mov r0, #1
	add r1, r5, #0
	bl SetMasterBrightness
	ldr r0, _0200FC58 ; =_021D1034
	strh r4, [r0, #0x10]
	pop {r3, r4, r5, pc}
	nop
_0200FC54: .word 0x0000FFFF
_0200FC58: .word _021D1034
_0200FC5C: .word 0x00007FFF
	thumb_func_end sub_0200FC20
	thumb_func_start sub_0200FC60
sub_0200FC60: ; 0x0200FC60
	push {r0, r1, r2, r3}
	push {r3, r4, lr}
	sub sp, #0xc
	add r1, sp, #0x18
	ldrh r2, [r1, #4]
	add r4, r0, #0
	ldr r0, _0200FCD0 ; =0x0000FFFF
	cmp r2, r0
	bne _0200FC78
	ldr r0, _0200FCD4 ; =_021D1034
	ldrh r0, [r0, #0x10]
	strh r0, [r1, #4]
_0200FC78:
	cmp r4, #0
	add r0, sp, #0x1c
	bne _0200FC88
	mov r1, #0
	mov r2, #2
	bl GX_LoadBGPltt
	b _0200FC90
_0200FC88:
	mov r1, #0
	mov r2, #2
	bl GXS_LoadBGPltt
_0200FC90:
	ldr r0, _0200FCD8 ; =_021D0F80
	mov r1, #1
	add r2, r4, #0
	bl sub_02013424
	mov r2, #0
	ldr r0, _0200FCD8 ; =_021D0F80
	mov r1, #0x3f
	add r3, r2, #0
	str r4, [sp]
	bl sub_02013440
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	ldr r0, _0200FCD8 ; =_021D0F80
	add r2, r1, #0
	add r3, r1, #0
	str r4, [sp, #8]
	bl sub_02013488
	ldr r0, _0200FCD8 ; =_021D0F80
	mov r1, #0x20
	mov r2, #0
	add r3, r4, #0
	bl sub_02013468
	add sp, #0xc
	pop {r3, r4}
	pop {r3}
	add sp, #0x10
	bx r3
	.balign 4, 0
_0200FCD0: .word 0x0000FFFF
_0200FCD4: .word _021D1034
_0200FCD8: .word _021D0F80
	thumb_func_end sub_0200FC60
	thumb_func_start sub_0200FCDC
sub_0200FCDC: ; 0x0200FCDC
	push {r0, r1, r2, r3}
	push {r3, lr}
	add r0, sp, #8
	mov r1, #0
	mov r2, #2
	bl GX_LoadBGPltt
	add r0, sp, #8
	mov r1, #0
	mov r2, #2
	bl GXS_LoadBGPltt
	pop {r3}
	pop {r3}
	add sp, #0x10
	bx r3
	thumb_func_end sub_0200FCDC
	thumb_func_start SetMasterBrightness
SetMasterBrightness: ; 0x0200FCFC
	push {r3, lr}
	cmp r0, #0
	bne _0200FD0A
	; GX_SetMasterBrightness(a1);
	ldr r0, _0200FD14 ; =0x0400006C
	bl GXx_SetMasterBrightness_
	pop {r3, pc}
_0200FD0A:
	; GXS_SetMasterBrightness(a1);
	ldr r0, _0200FD18 ; =0x0400106C
	bl GXx_SetMasterBrightness_
	pop {r3, pc}
	nop
_0200FD14: .word 0x0400006C
_0200FD18: .word 0x0400106C
	thumb_func_end SetMasterBrightness
	thumb_func_start HandleEndFade
HandleEndFade: ; 0x0200FD1C
	push {r4, lr}
	mov r1, #0x53
	add r4, r0, #0
	mov r2, #0
	lsl r1, r1, #2
	strh r2, [r4, r1]
	bl sub_0201002C
	mov r1, #0x15
	lsl r1, r1, #4
	strh r0, [r4, r1]
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0200FD4C
	add r0, r4, #0
	add r0, #0x14
	bl sub_02010094
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	bne _0200FD4C
	ldr r0, _0200FD70 ; =_021D1034
	mov r1, #0
	strb r1, [r0, #0xe]
_0200FD4C:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	beq _0200FD66
	add r0, r4, #0
	add r0, #0x44
	bl sub_02010094
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	bne _0200FD66
	ldr r0, _0200FD70 ; =_021D1034
	mov r1, #0
	strb r1, [r0, #0xf]
_0200FD66:
	add r0, r4, #0
	bl sub_020100C4
	pop {r4, pc}
	nop
_0200FD70: .word _021D1034
	thumb_func_end HandleEndFade
