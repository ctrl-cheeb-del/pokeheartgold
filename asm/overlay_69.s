	.include "asm/macros.inc"
	.public GeonetGlobe_Init
	.public GeonetGlobe_Main
	.public GeonetGlobe_Exit
	.public ov69_021E60F8
	.public ov69_021E6118
	.public ov69_021E6138
	.public ov69_021E623C
	.public ov69_021E62B0
	.public ov69_021E6300
	.public ov69_021E6308
	.public ov69_021E645C
	.public ov69_021E64CC
	.public ov69_021E67B8
	.public ov69_021E6810
	.public ov69_021E68D8
	.public ov69_021E68EC
	.public ov69_021E6994
	.public ov69_021E6A54
	.public ov69_021E6A8C
	.public ov69_021E6B5C
	.public ov69_021E6C14
	.public ov69_021E6C30
	.public ov69_021E6D5C
	.public ov69_021E6E88
	.public ov69_021E6F48
	.public ov69_021E6F8C
	.public ov69_021E6FE8
	.public ov69_021E706C
	.public ov69_021E70A8
	.public ov69_021E7120
	.public ov69_021E7198
	.public ov69_021E737C
	.public ov69_021E7408
	.public ov69_021E7520
	.public ov69_021E758C
	.public ov69_021E75A0
	.public ov69_021E75F8
	.public _021E7644
	.public ov69_021E764C
	.public ov69_021E7654
	.public ov69_021E765C
	.public ov69_021E7664
	.public ov69_021E766C
	.public ov69_021E7674
	.public ov69_021E767C
	.public ov69_021E7688
	.public ov69_021E7698
	.public ov69_021E76B0
	.public ov69_021E76CC
	.public ov69_021E76E8
	.public ov69_021E7708
	.public ov69_021E7728
	.public ov69_021E774C
	.public ov69_021E7770
	.public ov69_021E7794
	.public ov69_021E77B8
	.include "overlay_69.inc"
	.include "global.inc"

	.text
	.public GeonetGlobe_Exit
	.public ov69_021E6300
	.public ov69_021E67B8
	.public ov69_021E68D8
	.public ov69_021E6A54
	.public ov69_021E6C14
	.public ov69_021E6F48
	.public ov69_021E6F8C
	.public ov69_021E706C
	.public ov69_021E758C
	.public ov69_021E75F8
	.public GeonetGlobe_Init


	thumb_func_start GeonetGlobe_Main
GeonetGlobe_Main: ; 0x021E5A34
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r5]
	cmp r0, #0xe
	beq _021E5A60
	cmp r0, #0xf
	beq _021E5A60
	cmp r0, #0x10
	beq _021E5A60
	bl System_GetTouchNew
	cmp r0, #0
	beq _021E5A60
	ldr r0, _021E5D7C ; =gSystem
	mov r1, #1
	str r1, [r0, #0x5c]
_021E5A60:
	ldr r0, [r5]
	cmp r0, #0x12
	bls _021E5A68
	b _021E6028
_021E5A68:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5A74: ; jump table
	.short _021E5A9A - _021E5A74 - 2 ; case 0
	.short _021E5B0A - _021E5A74 - 2 ; case 1
	.short _021E5B18 - _021E5A74 - 2 ; case 2
	.short _021E5B3A - _021E5A74 - 2 ; case 3
	.short _021E5B60 - _021E5A74 - 2 ; case 4
	.short _021E5BAC - _021E5A74 - 2 ; case 5
	.short _021E5BD6 - _021E5A74 - 2 ; case 6
	.short _021E5C10 - _021E5A74 - 2 ; case 7
	.short _021E5C4C - _021E5A74 - 2 ; case 8
	.short _021E5CA8 - _021E5A74 - 2 ; case 9
	.short _021E5CF8 - _021E5A74 - 2 ; case 10
	.short _021E5D54 - _021E5A74 - 2 ; case 11
	.short _021E5D68 - _021E5A74 - 2 ; case 12
	.short _021E5DE0 - _021E5A74 - 2 ; case 13
	.short _021E5E30 - _021E5A74 - 2 ; case 14
	.short _021E5EB4 - _021E5A74 - 2 ; case 15
	.short _021E5FCC - _021E5A74 - 2 ; case 16
	.short _021E5FDC - _021E5A74 - 2 ; case 17
	.short _021E5FFE - _021E5A74 - 2 ; case 18
_021E5A9A:
	ldr r3, [r4]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xba
	bl NewMsgDataFromNarc
	ldr r1, _021E5D80 ; =0x0000C070
	str r0, [r4, r1]
	ldr r1, [r4]
	mov r0, #0x7b
	bl NARC_New
	add r6, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	bl ov69_021E6E88
	add r0, r4, #0
	add r1, r6, #0
	bl ov69_021E64CC
	add r0, r6, #0
	bl NARC_Delete
	mov r0, #0
	ldr r1, _021E5D84 ; =0x0000C2FC
	add r3, r0, #0
	str r0, [r4, r1]
	mov r1, #6
	str r1, [sp]
	mov r1, #1
	str r1, [sp, #4]
	ldr r2, [r4]
	str r2, [sp, #8]
	add r2, r1, #0
	bl BeginNormalPaletteFade
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #1
	str r0, [r5]
	b _021E6028
_021E5B0A:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E5BEC
	mov r0, #2
	str r0, [r5]
	b _021E6028
_021E5B18:
	add r0, r4, #0
	mov r1, #0
	mov r2, #1
	bl ov69_021E6810
	cmp r0, #1
	bne _021E5BEC
	ldr r0, _021E5D88 ; =0x0000C324
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _021E5B34
	mov r0, #3
	str r0, [r5]
	b _021E6028
_021E5B34:
	mov r0, #0xe
	str r0, [r5]
	b _021E6028
_021E5B3A:
	mov r1, #1
	add r0, r4, #0
	add r2, r1, #0
	bl ov69_021E6810
	cmp r0, #1
	bne _021E5BEC
	ldr r0, _021E5D8C ; =ov69_021E7698
	ldr r1, _021E5D90 ; =0x0000C024
	str r0, [sp]
	ldr r2, _021E5D94 ; =_021E7644
	ldr r3, _021E5D98 ; =ov69_021E76E8
	add r0, r4, #0
	add r1, r4, r1
	bl ov69_021E68EC
	mov r0, #4
	str r0, [r5]
	b _021E6028
_021E5B60:
	ldr r0, _021E5D9C ; =0x0000C064
	ldr r0, [r4, r0]
	bl ListMenu_ProcessInput
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _021E5BEC
	add r0, r4, #0
	bl ov69_021E6A54
	ldr r0, _021E5DA0 ; =0x000005DC
	bl PlaySE
	add r0, r6, #2
	cmp r0, #4
	bhi _021E5B9A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5B90: ; jump table
	.short _021E5BA6 - _021E5B90 - 2 ; case 0
	.short _021E5B9A - _021E5B90 - 2 ; case 1
	.short _021E5B9A - _021E5B90 - 2 ; case 2
	.short _021E5BA0 - _021E5B90 - 2 ; case 3
	.short _021E5BA6 - _021E5B90 - 2 ; case 4
_021E5B9A:
	mov r0, #0xe
	str r0, [r5]
	b _021E6028
_021E5BA0:
	mov r0, #5
	str r0, [r5]
	b _021E6028
_021E5BA6:
	mov r0, #0x11
	str r0, [r5]
	b _021E6028
_021E5BAC:
	add r0, r4, #0
	mov r1, #2
	mov r2, #1
	bl ov69_021E6810
	cmp r0, #1
	bne _021E5BEC
	ldr r0, [r4]
	ldr r1, _021E5DA4 ; =ov69_021E7664
	str r0, [sp]
	ldr r0, _021E5DA8 ; =0x0000C010
	ldr r2, _021E5DAC ; =0x000001D9
	ldr r0, [r4, r0]
	mov r3, #7
	bl Std_CreateYesNoMenu
	ldr r1, _021E5DB0 ; =0x0000C06C
	str r0, [r4, r1]
	mov r0, #6
	str r0, [r5]
	b _021E6028
_021E5BD6:
	ldr r0, _021E5DB0 ; =0x0000C06C
	ldr r1, [r4]
	ldr r0, [r4, r0]
	bl Handle2dMenuInput_DeleteOnFinish
	cmp r0, #0
	beq _021E5BEE
	mov r1, #1
	mvn r1, r1
	cmp r0, r1
	beq _021E5C0A
_021E5BEC:
	b _021E6028
_021E5BEE:
	mov r0, #0xc3
	lsl r0, r0, #8
	ldr r1, [r4, r0]
	cmp r1, #1
	bne _021E5C04
	mov r1, #0x67
	add r0, #0x2c
	str r1, [r4, r0]
	mov r0, #9
	str r0, [r5]
	b _021E6028
_021E5C04:
	mov r0, #7
	str r0, [r5]
	b _021E6028
_021E5C0A:
	mov r0, #3
	str r0, [r5]
	b _021E6028
_021E5C10:
	add r0, r4, #0
	mov r1, #3
	mov r2, #1
	bl ov69_021E6810
	cmp r0, #1
	bne _021E5CB6
	ldr r1, _021E5DB4 ; =0x0000C32C
	mov r0, #0
	str r0, [r4, r1]
	bl LocationGmmDatGetDistrictNameMsgIdsPtr
	add r6, r0, #0
	mov r0, #0
	bl LocationGmmDatGetDistrictCount
	ldr r1, _021E5DB8 ; =0x0000031E
	ldr r2, _021E5DBC ; =ov69_021E7674
	str r1, [sp]
	ldr r1, _021E5D90 ; =0x0000C024
	str r6, [sp, #4]
	str r0, [sp, #8]
	ldr r3, _021E5DC0 ; =ov69_021E7708
	add r0, r4, #0
	add r1, r4, r1
	bl ov69_021E6994
	mov r0, #8
	str r0, [r5]
	b _021E6028
_021E5C4C:
	ldr r0, _021E5D9C ; =0x0000C064
	ldr r0, [r4, r0]
	bl ListMenu_ProcessInput
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _021E5CB6
	add r0, r4, #0
	bl ov69_021E6A54
	ldr r0, _021E5DA0 ; =0x000005DC
	bl PlaySE
	mov r0, #1
	mvn r0, r0
	cmp r6, r0
	beq _021E5C7A
	mov r0, #0
	bl LocationGmmDatGetDistrictNameMsgIdsPtr
	ldrb r6, [r0, r6]
_021E5C7A:
	mov r0, #1
	mvn r0, r0
	cmp r6, r0
	beq _021E5CA2
	ldr r0, _021E5DB4 ; =0x0000C32C
	str r6, [r4, r0]
	ldr r0, [r4, r0]
	bl ov69_021E758C
	cmp r0, #1
	bne _021E5C96
	mov r0, #9
	str r0, [r5]
	b _021E6028
_021E5C96:
	ldr r0, _021E5DC4 ; =0x0000C330
	mov r1, #0
	str r1, [r4, r0]
	mov r0, #0xb
	str r0, [r5]
	b _021E6028
_021E5CA2:
	mov r0, #3
	str r0, [r5]
	b _021E6028
_021E5CA8:
	add r0, r4, #0
	mov r1, #4
	mov r2, #1
	bl ov69_021E6810
	cmp r0, #1
	beq _021E5CB8
_021E5CB6:
	b _021E6028
_021E5CB8:
	ldr r0, _021E5DC4 ; =0x0000C330
	mov r1, #0
	str r1, [r4, r0]
	sub r0, r0, #4
	ldr r0, [r4, r0]
	bl LocationGmmDatIndexGetByCountryMsgNo
	add r6, r0, #0
	bl LocationGmmDatGetGmmNo
	add r7, r0, #0
	add r0, r6, #0
	bl LocationGmmDatGetDistrictNameMsgIdsPtr
	str r0, [sp, #0x10]
	add r0, r6, #0
	bl LocationGmmDatGetDistrictCount
	ldr r1, [sp, #0x10]
	str r7, [sp]
	str r1, [sp, #4]
	ldr r1, _021E5D90 ; =0x0000C024
	str r0, [sp, #8]
	ldr r2, _021E5DBC ; =ov69_021E7674
	ldr r3, _021E5DC0 ; =ov69_021E7708
	add r0, r4, #0
	add r1, r4, r1
	bl ov69_021E6994
	mov r0, #0xa
	str r0, [r5]
	b _021E6028
_021E5CF8:
	ldr r0, _021E5D9C ; =0x0000C064
	ldr r0, [r4, r0]
	bl ListMenu_ProcessInput
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _021E5DF6
	add r0, r4, #0
	bl ov69_021E6A54
	ldr r0, _021E5DA0 ; =0x000005DC
	bl PlaySE
	mov r0, #1
	mvn r0, r0
	cmp r6, r0
	beq _021E5D2C
	ldr r0, _021E5DB4 ; =0x0000C32C
	ldr r0, [r4, r0]
	bl LocationGmmDatIndexGetByCountryMsgNo
	bl LocationGmmDatGetDistrictNameMsgIdsPtr
	ldrb r6, [r0, r6]
_021E5D2C:
	mov r0, #1
	mvn r0, r0
	cmp r6, r0
	beq _021E5D3E
	ldr r0, _021E5DC4 ; =0x0000C330
	str r6, [r4, r0]
	mov r0, #0xb
	str r0, [r5]
	b _021E6028
_021E5D3E:
	mov r0, #0xc3
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _021E5D4E
	mov r0, #3
	str r0, [r5]
	b _021E6028
_021E5D4E:
	mov r0, #7
	str r0, [r5]
	b _021E6028
_021E5D54:
	ldr r2, _021E5DB4 ; =0x0000C32C
	add r0, r4, #0
	ldr r1, [r4, r2]
	add r2, r2, #4
	ldr r2, [r4, r2]
	bl ov69_021E6B5C
	mov r0, #0xc
	str r0, [r5]
	b _021E6028
_021E5D68:
	add r0, r4, #0
	mov r1, #5
	mov r2, #1
	bl ov69_021E6810
	cmp r0, #1
	bne _021E5DF6
	ldr r0, [r4]
	ldr r1, _021E5DA4 ; =ov69_021E7664
	b _021E5DC8
	.balign 4, 0
_021E5D7C: .word gSystem
_021E5D80: .word 0x0000C070
_021E5D84: .word 0x0000C2FC
_021E5D88: .word 0x0000C324
_021E5D8C: .word ov69_021E7698
_021E5D90: .word 0x0000C024
_021E5D94: .word _021E7644
_021E5D98: .word ov69_021E76E8
_021E5D9C: .word 0x0000C064
_021E5DA0: .word 0x000005DC
_021E5DA4: .word ov69_021E7664
_021E5DA8: .word 0x0000C010
_021E5DAC: .word 0x000001D9
_021E5DB0: .word 0x0000C06C
_021E5DB4: .word 0x0000C32C
_021E5DB8: .word 0x0000031E
_021E5DBC: .word ov69_021E7674
_021E5DC0: .word ov69_021E7708
_021E5DC4: .word 0x0000C330
_021E5DC8:
	str r0, [sp]
	ldr r0, _021E6034 ; =0x0000C010
	ldr r2, _021E6038 ; =0x000001D9
	ldr r0, [r4, r0]
	mov r3, #7
	bl Std_CreateYesNoMenu
	ldr r1, _021E603C ; =0x0000C06C
	str r0, [r4, r1]
	mov r0, #0xd
	str r0, [r5]
	b _021E6028
_021E5DE0:
	ldr r0, _021E603C ; =0x0000C06C
	ldr r1, [r4]
	ldr r0, [r4, r0]
	bl Handle2dMenuInput_DeleteOnFinish
	cmp r0, #0
	beq _021E5DF8
	mov r1, #1
	mvn r1, r1
	cmp r0, r1
	beq _021E5E24
_021E5DF6:
	b _021E6028
_021E5DF8:
	add r0, r4, #0
	bl ov69_021E6C14
	ldr r2, _021E6040 ; =0x0000C32C
	ldr r0, [r4, #4]
	ldr r1, [r4, r2]
	add r2, r2, #4
	ldr r2, [r4, r2]
	bl WiFiHistory_SetPlayerGlobeInfo
	ldr r0, _021E6040 ; =0x0000C32C
	add r1, r0, #0
	ldr r2, [r4, r0]
	sub r1, #8
	str r2, [r4, r1]
	add r1, r0, #4
	ldr r1, [r4, r1]
	sub r0, r0, #4
	str r1, [r4, r0]
	mov r0, #0xe
	str r0, [r5]
	b _021E6028
_021E5E24:
	add r0, r4, #0
	bl ov69_021E6C14
	mov r0, #3
	str r0, [r5]
	b _021E6028
_021E5E30:
	mov r1, #0xc3
	lsl r1, r1, #8
	ldr r0, [r4, r1]
	cmp r0, #1
	bne _021E5E4C
	add r0, r1, #0
	add r0, #0x34
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _021E5E4C
	mov r2, #0
	add r0, r1, #4
	strh r2, [r4, r0]
	b _021E5E52
_021E5E4C:
	ldr r0, _021E6044 ; =0x0000C304
	mov r1, #1
	strh r1, [r4, r0]
_021E5E52:
	add r0, r4, #0
	bl ov69_021E6F8C
	add r0, r4, #0
	bl ov69_021E62B0
	add r0, r4, #0
	bl ov69_021E6FE8
	add r0, r4, #0
	bl ov69_021E706C
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, _021E6048 ; =0x0000C014
	mov r2, #0
	add r0, r4, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r0, _021E604C ; =0x0000C034
	ldr r2, _021E6038 ; =0x000001D9
	add r0, r4, r0
	mov r1, #0
	mov r3, #7
	bl DrawFrameAndWindow1
	ldr r0, _021E6050 ; =0x0000C324
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021E5E9C
	add r0, r4, #0
	bl ov69_021E6A8C
_021E5E9C:
	add r0, r4, #0
	bl ov69_021E6D5C
	ldr r0, _021E6054 ; =0x0000C338
	mov r1, #0
	str r1, [r4, r0]
	mov r1, #1
	sub r0, #0x40
	str r1, [r4, r0]
	mov r0, #0xf
	str r0, [r5]
	b _021E6028
_021E5EB4:
	ldr r0, _021E6058 ; =0x0000C2E8
	ldrh r6, [r4, r0]
	add r0, r4, #0
	bl ov69_021E6308
	add r0, r4, #0
	add r1, sp, #0x14
	bl ov69_021E6C30
	cmp r0, #0
	ldr r0, _021E605C ; =0x0000C044
	beq _021E5EDA
	ldr r2, _021E6038 ; =0x000001D9
	add r0, r4, r0
	mov r1, #0
	mov r3, #7
	bl DrawFrameAndWindow1
	b _021E5EE2
_021E5EDA:
	add r0, r4, r0
	mov r1, #0
	bl sub_0200E5D4
_021E5EE2:
	ldr r0, _021E6060 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	add r2, r1, #0
	tst r2, r0
	bne _021E5EF8
	ldr r2, _021E6064 ; =0x0000C308
	ldr r2, [r4, r2]
	add r3, r2, #0
	tst r3, r0
	beq _021E5F48
_021E5EF8:
	ldr r0, _021E604C ; =0x0000C034
	mov r1, #0
	add r0, r4, r0
	bl sub_0200E5D4
	ldr r0, _021E605C ; =0x0000C044
	mov r1, #0
	add r0, r4, r0
	bl sub_0200E5D4
	ldr r0, _021E6068 ; =0x000005DD
	bl PlaySE
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, _021E6048 ; =0x0000C014
	mov r2, #0
	add r0, r4, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r0, _021E6050 ; =0x0000C324
	ldr r1, [r4, r0]
	cmp r1, #0
	bne _021E5F3C
	mov r1, #2
	sub r0, #0x2c
	str r1, [r4, r0]
	mov r0, #3
	str r0, [r5]
	b _021E6028
_021E5F3C:
	add r0, r4, #0
	bl ov69_021E6C14
	mov r0, #0x11
	str r0, [r5]
	b _021E6028
_021E5F48:
	lsl r3, r0, #9
	tst r3, r1
	bne _021E5F54
	lsl r0, r0, #9
	tst r0, r2
	beq _021E5F76
_021E5F54:
	ldr r0, _021E6054 ; =0x0000C338
	ldr r3, [r4, r0]
	cmp r3, #0
	bne _021E5F76
	mov r1, #1
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov69_021E6D5C
	ldr r0, _021E6054 ; =0x0000C338
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _021E6028
	ldr r0, _021E6068 ; =0x000005DD
	bl PlaySE
	b _021E6028
_021E5F76:
	ldr r0, _021E606C ; =0x00000403
	add r3, r1, #0
	tst r3, r0
	bne _021E5F84
	sub r0, r0, #3
	tst r0, r2
	beq _021E5F98
_021E5F84:
	ldr r0, _021E6054 ; =0x0000C338
	ldr r2, [r4, r0]
	cmp r2, #1
	bne _021E5F98
	mov r1, #0
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov69_021E6D5C
	b _021E6028
_021E5F98:
	ldr r2, _021E6060 ; =gSystem
	add r0, r4, #0
	ldr r2, [r2, #0x44]
	bl ov69_021E7198
	cmp r0, #1
	bne _021E5FB8
	ldr r0, _021E6054 ; =0x0000C338
	ldr r1, [r4, r0]
	cmp r1, #1
	bne _021E5FB8
	mov r1, #0
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov69_021E6D5C
_021E5FB8:
	ldr r0, _021E6058 ; =0x0000C2E8
	ldrh r0, [r4, r0]
	cmp r6, r0
	beq _021E6028
	mov r0, #0x10
	str r0, [r5]
	ldr r0, _021E6070 ; =0x000005D9
	bl PlaySE
	b _021E6028
_021E5FCC:
	add r0, r4, #0
	bl ov69_021E737C
	cmp r0, #1
	bne _021E6028
	mov r0, #0xf
	str r0, [r5]
	b _021E6028
_021E5FDC:
	ldr r1, _021E6074 ; =0x0000C2FC
	mov r0, #0
	str r0, [r4, r1]
	mov r1, #6
	str r1, [sp]
	mov r1, #1
	str r1, [sp, #4]
	ldr r1, [r4]
	add r2, r0, #0
	str r1, [sp, #8]
	add r1, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #0x12
	str r0, [r5]
	b _021E6028
_021E5FFE:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E6028
	ldr r0, _021E6078 ; =0x0000C2F8
	mov r1, #1
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov69_021E67B8
	add r0, r4, #0
	bl ov69_021E6F48
	ldr r0, _021E607C ; =0x0000C070
	ldr r0, [r4, r0]
	bl DestroyMsgData
	mov r0, #0
	str r0, [r5]
	mov r0, #1
	str r0, [sp, #0xc]
_021E6028:
	add r0, r4, #0
	bl ov69_021E7408
	ldr r0, [sp, #0xc]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E6034: .word 0x0000C010
_021E6038: .word 0x000001D9
_021E603C: .word 0x0000C06C
_021E6040: .word 0x0000C32C
_021E6044: .word 0x0000C304
_021E6048: .word 0x0000C014
_021E604C: .word 0x0000C034
_021E6050: .word 0x0000C324
_021E6054: .word 0x0000C338
_021E6058: .word 0x0000C2E8
_021E605C: .word 0x0000C044
_021E6060: .word gSystem
_021E6064: .word 0x0000C308
_021E6068: .word 0x000005DD
_021E606C: .word 0x00000403
_021E6070: .word 0x000005D9
_021E6074: .word 0x0000C2FC
_021E6078: .word 0x0000C2F8
_021E607C: .word 0x0000C070
	thumb_func_end GeonetGlobe_Main
