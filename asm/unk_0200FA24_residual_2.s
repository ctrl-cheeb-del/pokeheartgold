	.include "asm/macros.inc"
	.include "unk_0200FA24.inc"
	.include "global.inc"

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
