#include "config.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_12_022378C0.inc"
	.include "global.inc"

	.text
	.public _0226BFD8
	.public ov12_02237D00
	.public ov12_02237ED0
	.public ov12_02237F18
	.public ov12_02238358
	.public ov12_0223843C
	.public ov12_022387AC
	.public ov12_022389B8
	.public ov12_02238A68
	.public ov12_02239664
	.public ov12_02239730
	.public ov12_022397E4
	.public ov12_02239854
	.public ov12_022399D4
	.public ov12_02239C28
	.public ov12_0223A0D4
	.public ov12_0223A260
	.public ov12_0223A3F0
	.public ov12_0223A664
	.public ov12_0226BFDC
	.public ov12_0226BFE0
	.public ov12_0226BFE8
	.public ov12_0226BFF8
	.public ov12_0226C008
	.public ov12_0226C018
	.public ov12_0226C02C
	.public ov12_0226C044
	.public ov12_0226C060
	.public ov12_0226C080
	.public ov12_0226C0A8
	.public ov12_0226C0D0
	.public ov12_0226C0F8
	.public ov12_0226C120
	.public ov12_0226C174
	.public ov12_0226C1C8
	.public ov12_0226C2DC

	.public ov12_02238A30
	.public ov12_02238A64
	.public ov12_022395BC
	.public ov12_02239644
	.public ov12_022396E8
	.public ov12_022396F0
	.public ov12_02239810
	.public ov12_0223998C
	.public ov12_022399BC
	.public ov12_0223A088
	.public ov12_0223A218
	.public ov12_0223A3A8
	.public ov12_0223A5E4
	.public ov12_0223A620
	.public ov12_0223A7A0

	thumb_func_start ov12_022399D4
ov12_022399D4: ; 0x022399D4
	push {r4, r5, r6, lr}
	sub sp, #0x68
	add r4, r1, #0
	ldr r1, _02239C00 ; =0x00001028
	mov r2, #5
	bl OverlayManager_CreateAndGetData
	add r5, r0, #0
	ldr r0, _02239C04 ; =0x00001020
	str r4, [r5]
	mov r2, #0
	strb r2, [r5, r0]
	add r1, r0, #1
	strb r2, [r5, r1]
	add r0, r0, #2
	strh r2, [r5, r0]
	mov r0, #5
	bl PaletteData_Init
	str r0, [r5, #0xc]
	mov r1, #1
	bl PaletteData_SetAutoTransparent
	mov r2, #2
	ldr r0, [r5, #0xc]
	mov r1, #0
	lsl r2, r2, #8
	mov r3, #5
	bl PaletteData_AllocBuffers
	mov r1, #0
	mov r0, #1
	str r1, [sp]
	lsl r0, r0, #8
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	mov r2, #2
	add r3, r1, #0
	bl PaletteData_FillPaletteInBuffer
	mov r0, #5
	bl BgConfig_Alloc
	str r0, [r5, #4]
	mov r0, #5
	mov r1, #1
	bl AllocWindows
	str r0, [r5, #8]
	add r0, r5, #0
	bl sub_02074EC4
	bl GfGfx_DisableEngineAPlanes
	ldr r6, _02239C08 ; =ov12_0226C080
	add r3, sp, #0x40
	mov r2, #5
_02239A46:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02239A46
	add r0, sp, #0x40
	bl GfGfx_SetBanks
	mov r1, #6
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x18
	lsl r2, r2, #0x12
	bl MIi_CpuClear32
	mov r1, #0x62
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x14
	lsl r2, r2, #0x10
	bl MIi_CpuClear32
	mov r1, #0x19
	mov r2, #1
	mov r0, #0
	lsl r1, r1, #0x16
	lsl r2, r2, #0x12
	bl MIi_CpuClear32
	mov r1, #0x66
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x14
	lsl r2, r2, #0x10
	bl MIi_CpuClear32
	mov r1, #5
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x18
	lsl r2, r2, #8
	bl MIi_CpuClear16
	ldr r6, _02239C0C ; =ov12_0226BFF8
	add r3, sp, #0x30
	add r2, r3, #0
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r6, _02239C10 ; =ov12_0226C044
	add r3, sp, #0x14
	ldmia r6!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r6]
	mov r1, #1
	str r0, [r3]
	ldr r0, [r5, #4]
	mov r3, #0
	bl InitBgFromTemplate
	ldr r0, [r5, #4]
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Options_GetFrame
	add r4, r0, #0
	lsl r0, r4, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #5
	str r0, [sp, #4]
	mov r1, #1
	ldr r0, [r5, #4]
	add r2, r1, #0
	mov r3, #0xa
	bl sub_0200EB80
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xb0
	str r0, [sp, #8]
	ldr r0, [r5, #0xc]
	mov r1, #0x10
	mov r2, #8
	mov r3, #5
	bl PaletteData_LoadNarc
	add r0, r4, #0
	bl sub_0200E640
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xa0
	str r0, [sp, #8]
	ldr r0, [r5, #0xc]
	mov r1, #0x26
	mov r3, #5
	bl PaletteData_LoadNarc
	mov r1, #0
	mov r0, #1
	str r1, [sp]
	lsl r0, r0, #8
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	add r2, r1, #0
	add r3, r1, #0
	bl PaletteData_FillPaletteInBuffer
	bl GfGfx_BothDispOn
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r2, _02239C14 ; =0x04000304
	mov r3, #2
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	mov r0, #0x1f
	str r0, [sp, #0x10]
	ldr r0, [r5, #4]
	ldr r1, [r5, #8]
	mov r2, #1
	bl AddWindowParameterized
	ldr r0, [r5, #8]
	mov r1, #0xff
	bl FillWindowPixelBuffer
	ldr r0, [r5, #8]
	mov r1, #0
	mov r2, #1
	mov r3, #0xa
	bl DrawFrameAndWindow2
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xc5
	mov r3, #5
	bl NewMsgDataFromNarc
	add r4, r0, #0
	mov r0, #1
	lsl r0, r0, #8
	mov r1, #5
	bl String_New
	add r6, r0, #0
	ldr r1, _02239C18 ; =0x0000039B
	add r0, r4, #0
	add r2, r6, #0
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [r5, #8]
	mov r1, #1
	add r2, r6, #0
	bl AddTextPrinterParameterized
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	bl DestroyMsgData
	ldr r0, _02239C1C ; =ov12_022397E4
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x10
	str r0, [sp]
	mov r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [r5, #0xc]
	ldr r2, _02239C20 ; =0x0000FFFF
	mov r1, #5
	bl PaletteData_BeginPaletteFade
	ldr r0, [r5, #8]
	mov r1, #1
	bl WaitingIcon_New
	ldr r1, _02239C24 ; =0x00001024
	str r0, [r5, r1]
	bl ov12_0223A7A0
	add sp, #0x68
	pop {r4, r5, r6, pc}
	nop
_02239C00: .word 0x00001028
_02239C04: .word 0x00001020
_02239C08: .word ov12_0226C080
_02239C0C: .word ov12_0226BFF8
_02239C10: .word ov12_0226C044
_02239C14: .word 0x04000304
_02239C18: .word 0x0000039B
_02239C1C: .word ov12_022397E4
_02239C20: .word 0x0000FFFF
_02239C24: .word 0x00001024
	thumb_func_end ov12_022399D4


	thumb_func_start ov12_02239C28
ov12_02239C28: ; 0x02239C28
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r1, [r4, #4]
	mov r0, #5
	bl sub_020399FC
	ldr r0, _02239F2C ; =0x00001021
	mov r7, #0
	ldrb r1, [r4, r0]
	cmp r1, #0x21
	bls _02239C46
	b _0223A06C
_02239C46:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02239C52: ; jump table
	.short _02239C96 - _02239C52 - 2 ; case 0
	.short _02239CAC - _02239C52 - 2 ; case 1
	.short _02239CC0 - _02239C52 - 2 ; case 2
	.short _02239CD0 - _02239C52 - 2 ; case 3
	.short _02239D0A - _02239C52 - 2 ; case 4
	.short _02239FE2 - _02239C52 - 2 ; case 5
	.short _02239D22 - _02239C52 - 2 ; case 6
	.short _02239D3C - _02239C52 - 2 ; case 7
	.short _02239FE2 - _02239C52 - 2 ; case 8
	.short _02239D50 - _02239C52 - 2 ; case 9
	.short _02239D6C - _02239C52 - 2 ; case 10
	.short _02239FE2 - _02239C52 - 2 ; case 11
	.short _02239D80 - _02239C52 - 2 ; case 12
	.short _02239D9A - _02239C52 - 2 ; case 13
	.short _02239FE2 - _02239C52 - 2 ; case 14
	.short _02239DAE - _02239C52 - 2 ; case 15
	.short _02239DC8 - _02239C52 - 2 ; case 16
	.short _02239FE2 - _02239C52 - 2 ; case 17
	.short _02239DDC - _02239C52 - 2 ; case 18
	.short _02239DF6 - _02239C52 - 2 ; case 19
	.short _02239FE2 - _02239C52 - 2 ; case 20
	.short _02239E0A - _02239C52 - 2 ; case 21
	.short _02239E4E - _02239C52 - 2 ; case 22
	.short _02239FE2 - _02239C52 - 2 ; case 23
	.short _02239E8A - _02239C52 - 2 ; case 24
	.short _02239EBE - _02239C52 - 2 ; case 25
	.short _02239FE2 - _02239C52 - 2 ; case 26
	.short _02239EF8 - _02239C52 - 2 ; case 27
	.short _02239F38 - _02239C52 - 2 ; case 28
	.short _02239FE2 - _02239C52 - 2 ; case 29
	.short _02239F74 - _02239C52 - 2 ; case 30
	.short _02239FA8 - _02239C52 - 2 ; case 31
	.short _02239FE2 - _02239C52 - 2 ; case 32
	.short _0223A052 - _02239C52 - 2 ; case 33
_02239C96:
	add r0, r7, #0
	bl SetMasterBrightnessNeutral
	mov r0, #1
	bl sub_02037930
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239CAC:
	ldr r0, [r4, #0xc]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _02239D5A
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239CC0:
	mov r0, #0x32
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239CD0:
	mov r0, #0x32
	bl sub_02037B38
	cmp r0, #0
	beq _02239CF2
	mov r0, #0x33
	bl sub_02037AC0
	ldr r0, _02239F30 ; =0x00001022
	add r1, r7, #0
	strh r1, [r4, r0]
	sub r1, r0, #1
	ldrb r1, [r4, r1]
	sub r0, r0, #1
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239CF2:
	ldr r0, _02239F30 ; =0x00001022
	ldrh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	ldrh r1, [r4, r0]
	ldr r0, _02239F34 ; =0x00000708
	cmp r1, r0
	bls _02239D5A
	mov r0, #1
	bl sub_02039AD8
	b _0223A06C
_02239D0A:
	mov r1, #5
	add r0, r4, #0
	lsl r1, r1, #6
	bl sub_02075074
	cmp r0, #1
	bne _02239D5A
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239D22:
	add r0, r4, #0
	bl sub_020750E0
	cmp r0, #1
	bne _02239D5A
	mov r0, #0x34
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239D3C:
	add r0, r4, #0
	bl sub_02075108
	cmp r0, #1
	bne _02239D5A
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239D50:
	add r0, r4, #0
	bl sub_0207514C
	cmp r0, #1
	beq _02239D5C
_02239D5A:
	b _0223A06C
_02239D5C:
	mov r0, #0x35
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239D6C:
	add r0, r4, #0
	bl sub_02075178
	cmp r0, #1
	bne _02239E66
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239D80:
	add r0, r4, #0
	bl sub_020751B8
	cmp r0, #1
	bne _02239E66
	mov r0, #0x36
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239D9A:
	add r0, r4, #0
	bl sub_020751DC
	cmp r0, #1
	bne _02239E66
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239DAE:
	add r0, r4, #0
	bl sub_02075220
	cmp r0, #1
	bne _02239E66
	mov r0, #0x37
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239DC8:
	add r0, r4, #0
	bl sub_02075248
	cmp r0, #1
	bne _02239E66
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239DDC:
	add r0, r4, #0
	bl sub_0207527C
	cmp r0, #1
	bne _02239E66
	mov r0, #0x38
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239DF6:
	add r0, r4, #0
	bl sub_020752D8
	cmp r0, #1
	bne _02239E66
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239E0A:
	ldr r1, [r4]
	ldr r2, [r1]
	mov r1, #0x80
	tst r1, r2
	bne _02239E1A
	mov r1, #0x21
	strb r1, [r4, r0]
	b _0223A06C
_02239E1A:
	bl sub_0203769C
	cmp r0, #0
	beq _02239E32
	mov r0, #0x39
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239E32:
	add r0, r4, #0
	mov r1, #1
	bl sub_0207531C
	cmp r0, #1
	bne _02239E66
	mov r0, #0x39
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239E4E:
	mov r1, #1
	sub r0, r0, #1
	strb r1, [r4, r0]
	bl sub_0203769C
	cmp r0, #0
	beq _02239E72
	mov r0, #0x39
	bl sub_02037B38
	cmp r0, #1
	beq _02239E68
_02239E66:
	b _0223A06C
_02239E68:
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239E72:
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x39
	bl sub_02075350
	cmp r0, #1
	bne _02239F68
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239E8A:
	bl sub_0203769C
	cmp r0, #0
	beq _02239EA2
	mov r0, #0x3a
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239EA2:
	add r0, r4, #0
	mov r1, #3
	bl sub_0207531C
	cmp r0, #1
	bne _02239F68
	mov r0, #0x3a
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239EBE:
	mov r1, #1
	sub r0, r0, #1
	strb r1, [r4, r0]
	bl sub_0203769C
	cmp r0, #0
	beq _02239EE0
	mov r0, #0x3a
	bl sub_02037B38
	cmp r0, #1
	bne _02239F68
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239EE0:
	add r0, r4, #0
	mov r1, #3
	mov r2, #0x3a
	bl sub_02075350
	cmp r0, #1
	bne _02239F68
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239EF8:
	bl sub_0203769C
	cmp r0, #0
	beq _02239F10
	mov r0, #0x3b
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239F10:
	add r0, r4, #0
	mov r1, #1
	bl sub_020753A8
	cmp r0, #1
	bne _02239F68
	mov r0, #0x3b
	bl sub_02037AC0
	ldr r0, _02239F2C ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
	.balign 4, 0
_02239F2C: .word 0x00001021
_02239F30: .word 0x00001022
_02239F34: .word 0x00000708
_02239F38:
	mov r1, #1
	sub r0, r0, #1
	strb r1, [r4, r0]
	bl sub_0203769C
	cmp r0, #0
	beq _02239F5A
	mov r0, #0x3b
	bl sub_02037B38
	cmp r0, #1
	bne _02239F68
	ldr r0, _0223A074 ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239F5A:
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x3b
	bl sub_020753D4
	cmp r0, #1
	beq _02239F6A
_02239F68:
	b _0223A06C
_02239F6A:
	ldr r0, _0223A074 ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239F74:
	bl sub_0203769C
	cmp r0, #0
	beq _02239F8C
	mov r0, #0x3c
	bl sub_02037AC0
	ldr r0, _0223A074 ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239F8C:
	add r0, r4, #0
	mov r1, #3
	bl sub_020753A8
	cmp r0, #1
	bne _0223A06C
	mov r0, #0x3c
	bl sub_02037AC0
	ldr r0, _0223A074 ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239FA8:
	mov r1, #1
	sub r0, r0, #1
	strb r1, [r4, r0]
	bl sub_0203769C
	cmp r0, #0
	beq _02239FCA
	mov r0, #0x3c
	bl sub_02037B38
	cmp r0, #1
	bne _0223A06C
	ldr r0, _0223A074 ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239FCA:
	add r0, r4, #0
	mov r1, #3
	mov r2, #0x3c
	bl sub_020753D4
	cmp r0, #1
	bne _0223A06C
	ldr r0, _0223A074 ; =0x00001021
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0223A06C
_02239FE2:
	bl sub_02037454
	ldr r1, _0223A078 ; =0x00001020
	ldrb r2, [r4, r1]
	cmp r2, r0
	bne _0223A038
	add r0, r1, #1
	ldrb r0, [r4, r0]
	cmp r0, #0x14
	bne _0223A008
	add r6, r7, #0
	add r5, r4, #0
_02239FFA:
	ldr r0, [r5, #0x10]
	bl Heap_Free
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #4
	blt _02239FFA
_0223A008:
	ldr r0, _0223A078 ; =0x00001020
	mov r3, #0
	strb r3, [r4, r0]
	add r1, r0, #2
	strh r3, [r4, r1]
	add r1, r0, #1
	ldrb r1, [r4, r1]
	add r2, r1, #1
	add r1, r0, #1
	strb r2, [r4, r1]
	add r0, r0, #1
	ldrb r0, [r4, r0]
	cmp r0, #0x21
	bne _0223A06C
	str r3, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	str r3, [sp, #8]
	ldr r0, [r4, #0xc]
	ldr r2, _0223A07C ; =0x0000FFFF
	mov r1, #5
	bl PaletteData_BeginPaletteFade
	b _0223A06C
_0223A038:
	add r0, r1, #2
	ldrh r0, [r4, r0]
	add r2, r0, #1
	add r0, r1, #2
	strh r2, [r4, r0]
	ldrh r1, [r4, r0]
	ldr r0, _0223A080 ; =0x00000708
	cmp r1, r0
	bls _0223A06C
	mov r0, #1
	bl sub_02039AD8
	b _0223A06C
_0223A052:
	ldr r0, [r4, #0xc]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _0223A06C
	ldr r0, _0223A084 ; =0x00001024
	mov r7, #1
	ldr r0, [r4, r0]
	bl sub_0200F450
	mov r0, #0
	bl sub_02037930
_0223A06C:
	add r0, r7, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_0223A074: .word 0x00001021
_0223A078: .word 0x00001020
_0223A07C: .word 0x0000FFFF
_0223A080: .word 0x00000708
_0223A084: .word 0x00001024
	thumb_func_end ov12_02239C28
