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

	thumb_func_start ov12_02237F18
ov12_02237F18: ; 0x02237F18
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, r5, #0
	bl OverlayManager_GetArgs
	add r7, r0, #0
	bl sub_02026E8C
	add r5, r0, #0
	bl GetMainBgPlttAddr
	add r1, r0, #0
	mov r0, #0
	add r2, r5, #0
	bl MIi_CpuClear16
	bl sub_02026E9C
	add r5, r0, #0
	bl GetSubBgPlttAddr
	add r1, r0, #0
	mov r0, #0
	add r2, r5, #0
	bl MIi_CpuClear16
	bl ov12_02239644
	str r0, [r4]
	bl HBlankInterruptDisable
	mov r0, #4
	mov r1, #5
	bl FontID_Alloc
	mov r0, #0xe
	mov r1, #2
	mov r2, #0xf
	mov r3, #5
	bl MessagePrinter_New
	mov r1, #0x6a
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r2, [r4, r1]
	add r0, r1, #4
	str r2, [r4, r0]
	mov r0, #5
	bl PaletteData_Init
	str r0, [r4, #0x28]
	mov r1, #1
	bl PaletteData_SetAutoTransparent
	mov r2, #2
	ldr r0, [r4, #0x28]
	mov r1, #0
	lsl r2, r2, #8
	mov r3, #5
	bl PaletteData_AllocBuffers
	mov r1, #1
	ldr r0, [r4, #0x28]
	lsl r2, r1, #9
	mov r3, #5
	bl PaletteData_AllocBuffers
	mov r2, #7
	ldr r0, [r4, #0x28]
	mov r1, #2
	lsl r2, r2, #6
	mov r3, #5
	bl PaletteData_AllocBuffers
	mov r2, #2
	ldr r0, [r4, #0x28]
	mov r1, #3
	lsl r2, r2, #8
	mov r3, #5
	bl PaletteData_AllocBuffers
	mov r0, #5
	bl BgConfig_Alloc
	str r0, [r4, #4]
	mov r0, #5
	mov r1, #3
	bl AllocWindows
	str r0, [r4, #8]
	mov r6, #0
	add r5, r4, #0
_02237FD8:
	mov r1, #0x32
	mov r0, #5
	lsl r1, r1, #6
	bl Heap_Alloc
	mov r1, #0x1d
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r6, r6, #1
	add r5, #0x10
	cmp r6, #4
	blt _02237FD8
	mov r0, #0x40
	mov r1, #5
	bl GF_CreateVramTransferManager
	mov r0, #7
	mov r1, #5
	bl NARC_New
	add r5, r0, #0
	mov r0, #8
	mov r1, #5
	bl NARC_New
	add r6, r0, #0
	add r0, r4, #0
	bl ov12_0223BFC0
	add r1, r0, #0
	add r0, r4, #0
	bl BattleSystem_GetTrainerGender
	add r3, r0, #0
	mov r0, #7
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	add r1, r6, #0
	str r0, [sp]
	add r0, r5, #0
	add r2, r4, #0
	bl BattleInput_NewInit
	mov r1, #0x67
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r5, #0
	bl NARC_Delete
	add r0, r6, #0
	bl NARC_Delete
	ldr r1, [r4, #4]
	add r0, r4, #0
	bl ov12_022387AC
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
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	mov r2, #1
	mov r3, #2
	bl AddWindowParameterized
	ldr r0, [r4, #8]
	mov r1, #0xff
	bl FillWindowPixelBuffer
	ldr r0, [r4, #8]
	mov r1, #0
	mov r2, #1
	mov r3, #0xa
	bl DrawFrameAndWindow2
	mov r0, #5
	bl SpriteSystem_Alloc
	add r1, r4, #0
	add r1, #0x90
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x90
	ldr r0, [r0]
	ldr r1, _02238314 ; =ov12_0226C060
	ldr r2, _02238318 ; =ov12_0226C018
	mov r3, #0x20
	bl SpriteSystem_Init
	ldr r1, _0223831C ; =0x00100010
	mov r0, #1
	bl G2dRenderer_SetObjCharTransferReservedRegion
	mov r0, #1
	bl G2dRenderer_SetPlttTransferReservedRegion
	add r0, r4, #0
	add r0, #0x90
	ldr r0, [r0]
	bl SpriteManager_New
	add r1, r4, #0
	add r1, #0x94
	str r0, [r1]
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x90
	add r1, #0x94
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #0x80
	bl SpriteSystem_InitSprites
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x90
	add r1, #0x94
	ldr r0, [r0]
	ldr r1, [r1]
	ldr r2, _02238320 ; =ov12_0226C02C
	bl SpriteSystem_InitManagerWithCapacities
	add r0, r4, #0
	add r0, #0x90
	ldr r0, [r0]
	bl SpriteSystem_GetRenderer
	mov r2, #0x11
	mov r1, #0
	lsl r2, r2, #0x10
	bl G2dRenderer_SetSubSurfaceCoords
	mov r0, #0x67
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl BattleInput_LoadDefaultResources
	mov r0, #7
	mov r1, #5
	bl NARC_New
	add r6, r0, #0
	mov r0, #8
	mov r1, #5
	bl NARC_New
	add r5, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r3, #0
	mov r2, #0x67
	str r3, [sp, #4]
	lsl r2, r2, #2
	ldr r2, [r4, r2]
	add r0, r6, #0
	add r1, r5, #0
	bl BattleInput_ChangeMenu
	mov r1, #0x67
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r5, #0
	bl BattleInput_LoadBallGaugeResources
	add r0, r6, #0
	bl NARC_Delete
	add r0, r5, #0
	bl NARC_Delete
	mov r0, #5
	bl PokepicManager_Create
	add r1, r4, #0
	add r1, #0x88
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	mov r1, #0
	mov r2, #0xc0
	bl PokepicManager_SetPlttBaseAddrAndSize
	add r0, r4, #0
	bl BattleSystem_HpBar_Init
	bl ov12_022396F0
	mov r0, #5
	bl ov07_0221BEDC
	add r1, r4, #0
	add r1, #0x8c
	str r0, [r1]
	add r0, r4, #0
	bl ov12_022389B8
	bl sub_020210BC
	mov r0, #4
	bl sub_02021148
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xc5
	mov r3, #5
	bl NewMsgDataFromNarc
	str r0, [r4, #0xc]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #3
	mov r3, #5
	bl NewMsgDataFromNarc
	str r0, [r4, #0x10]
	mov r0, #5
	bl MessageFormat_New
	str r0, [r4, #0x14]
	mov r0, #5
	lsl r0, r0, #6
	mov r1, #5
	bl String_New
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x28]
	mov r1, #0
	bl PaletteData_GetUnfadedBuf
	ldr r1, _02238324 ; =0x00002228
	mov r2, #0xe0
	add r1, r4, r1
	bl MIi_CpuCopy16
	ldr r0, [r4, #0x28]
	mov r1, #2
	bl PaletteData_GetUnfadedBuf
	ldr r1, _02238328 ; =0x00002308
	mov r2, #0xe0
	add r1, r4, r1
	bl MIi_CpuCopy16
	add r0, r4, #0
	bl ov12_0223B52C
	mov r1, #0
	lsl r6, r0, #2
	str r1, [sp]
	mov r0, #0x70
	str r0, [sp, #4]
	ldr r3, _0223832C ; =0x00002404
	mov r5, #0xc
	ldr r3, [r4, r3]
	ldr r0, [r4, #0x28]
	mul r5, r3
	ldr r3, _02238330 ; =ov12_0226C1C8
	mov r2, #2
	add r3, r3, r5
	ldr r3, [r6, r3]
	lsl r3, r3, #0x10
	lsr r3, r3, #0x10
	bl PaletteData_FillPaletteInBuffer
	mov r0, #0xc0
	str r0, [sp]
	add r0, #0x40
	str r0, [sp, #4]
	ldr r3, _0223832C ; =0x00002404
	mov r5, #0xc
	ldr r3, [r4, r3]
	ldr r0, [r4, #0x28]
	mul r5, r3
	ldr r3, _02238330 ; =ov12_0226C1C8
	mov r1, #0
	add r3, r3, r5
	ldr r3, [r6, r3]
	mov r2, #2
	lsl r3, r3, #0x10
	lsr r3, r3, #0x10
	bl PaletteData_FillPaletteInBuffer
	mov r0, #0
	str r0, [sp]
	mov r0, #0xdf
	str r0, [sp, #4]
	ldr r3, _0223832C ; =0x00002404
	mov r5, #0xc
	ldr r3, [r4, r3]
	mov r1, #2
	mul r5, r3
	ldr r3, _02238330 ; =ov12_0226C1C8
	ldr r0, [r4, #0x28]
	add r3, r3, r5
	ldr r3, [r6, r3]
	add r2, r1, #0
	lsl r3, r3, #0x10
	lsr r3, r3, #0x10
	bl PaletteData_FillPaletteInBuffer
	mov r1, #0
	mov r0, #0xa0
	str r0, [sp]
	mov r0, #0xc0
	str r0, [sp, #4]
	ldr r0, [r4, #0x28]
	add r2, r1, #0
	add r3, r1, #0
	bl PaletteData_FillPaletteInBuffer
	mov r2, #0
	str r2, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [r4, #0x28]
	mov r1, #1
	add r3, r2, #0
	bl PaletteData_FillPaletteInBuffer
	mov r2, #0
	str r2, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [r4, #0x28]
	ldr r3, _02238334 ; =0x0000FFFF
	mov r1, #3
	bl PaletteData_FillPaletteInBuffer
	ldr r0, [r4, #0x28]
	mov r1, #0
	mov r2, #0xb
	mov r3, #5
	bl sub_020163E0
	mov r1, #0x1b
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #1
	bl sub_0201649C
	ldr r0, _02238338 ; =ov12_02239810
	ldr r2, _0223833C ; =0x0000EA60
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0x1c]
	ldr r0, _02238340 ; =ov12_02239854
	ldr r2, _02238344 ; =0x0000C350
	add r1, r4, #0
	bl SysTask_CreateOnMainQueue
	str r0, [r4, #0x20]
	mov r2, #0x4b
	ldr r0, _02238348 ; =ov12_0223998C
	add r1, r4, #0
	lsl r2, r2, #4
	bl SysTask_CreateOnVBlankQueue
	str r0, [r4, #0x24]
	mov r1, #0x32
	ldr r0, _0223834C ; =0x00002438
	mvn r1, r1
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov12_0223A620
	add r0, r4, #0
	bl BattleSystem_GetBagCursor
	bl BagCursor_Battle_Init
	mov r0, #5
	mov r1, #4
	mov r2, #0
	bl sub_02016EDC
	mov r1, #0x72
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #4
	mov r1, #5
	bl sub_02020654
	mov r1, #0x73
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, _02238350 ; =0x0000240C
	ldr r1, [r4, r0]
	mov r0, #0x10
	tst r0, r1
	beq _0223830E
	mov r0, #0x6f
	ldr r1, _02238354 ; =0x00002484
	mov r5, #0
	lsl r0, r0, #2
_02238300:
	add r2, r7, r5
	ldrb r3, [r2, r0]
	add r2, r4, r5
	add r5, r5, #1
	strb r3, [r2, r1]
	cmp r5, #4
	blt _02238300
_0223830E:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_02238314: .word ov12_0226C060
_02238318: .word ov12_0226C018
_0223831C: .word 0x00100010
_02238320: .word ov12_0226C02C
_02238324: .word 0x00002228
_02238328: .word 0x00002308
_0223832C: .word 0x00002404
_02238330: .word ov12_0226C1C8
_02238334: .word 0x0000FFFF
_02238338: .word ov12_02239810
_0223833C: .word 0x0000EA60
_02238340: .word ov12_02239854
_02238344: .word 0x0000C350
_02238348: .word ov12_0223998C
_0223834C: .word 0x00002438
_02238350: .word 0x0000240C
_02238354: .word 0x00002484
	thumb_func_end ov12_02237F18
