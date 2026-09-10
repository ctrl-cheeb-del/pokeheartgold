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
	.public BeginNormalPaletteFade
	.public HandleFadeUpdateFrame
	.public IsPaletteFadeFinished
	.public sub_0200FB70
	.public ResetVisibleHardwareWindows
	.public SetMasterBrightnessNeutral
	.public sub_0200FBF4
	.public sub_0200FC20
	.public sub_0200FC60
	.public sub_0200FCDC
	.public SetMasterBrightness
	.public HandleEndFade
	.public HandleFadeUpdateFrame
	.public IsPaletteFadeFinished
	.public ResetVisibleHardwareWindows
	.public SetMasterBrightnessNeutral
	.public sub_0200FBF4
	.public sub_0200FC20
	.public sub_0200FC60
	.public sub_0200FCDC
	.public SetMasterBrightness
	.public HandleEndFade

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
