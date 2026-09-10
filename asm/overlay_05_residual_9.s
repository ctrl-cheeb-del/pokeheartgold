	.include "asm/macros.inc"
	.public ov05_0221BA00
	.public ov05_0221BA70
	.public ov05_0221BB00
	.public ov05_0221BB30
	.public ov05_0221BD28
	.public ov05_0221BE04
	.public ov05_0221BE80
	.public ov05_0221BF08
	.public ov05_0221C018
	.public ov05_0221C050
	.public ov05_0221C21C
	.public ov05_0221C430
	.public ov05_0221C558
	.public ov05_0221C568
	.public ov05_0221C5A8
	.public ov05_0221C5C4
	.public ov05_0221C6C8
	.public ov05_0221C7FC
	.public ov05_0221C80C
	.public ov05_0221C8A0
	.public ov05_0221C8E0
	.public ov05_0221C908
	.public ov05_0221CAB8
	.public ov05_0221CB70
	.public ov05_0221CC04
	.public ov05_0221CC58
	.public ov05_0221CC74
	.public ov05_0221CCF4
	.public ov05_0221CD24
	.public ov05_0221CDC4
	.public ov05_0221CE0C
	.public ov05_0221CE50
	.public ov05_0221CE88
	.public ov05_0221CEB8
	.public ov05_0221CFF0
	.public ov05_0221D020
	.public ov05_0221D054
	.public ov05_0221D094
	.public ov05_0221D140
	.public ov05_0221D228
	.public ov05_0221D240
	.public ov05_0221D318
	.public ov05_0221D3AC
	.public ov05_0221D414
	.public ov05_0221D4D0
	.public ov05_0221D530
	.public ov05_0221D5DC
	.public ov05_0221D664
	.public ov05_0221D690
	.public ov05_0221D6C4
	.public ov05_0221D7AC
	.public ov05_0221D890
	.public ov05_0221D904
	.public ov05_0221D9F0
	.public ov05_0221DAE0
	.public ov05_0221DB18
	.public ov05_0221DB4C
	.public ov05_0221DB70
	.public ov05_0221DB94
	.public ov05_0221DC34
	.public ov05_0221DC60
	.public ov05_0221DD08
	.public ov05_0221DDEC
	.public ov05_0221DE38
	.public ov05_0221DE6C
	.public ov05_0221DF38
	.public ov05_0221E07C
	.public ov05_0221E0A8
	.public ov05_0221E110
	.public ov05_0221E274
	.public ov05_0221E2D8
	.public ov05_0221E390
	.public ov05_0221E42C
	.public ov05_0221E4C8
	.public ov05_0221E564
	.public ov05_0221E5E4
	.public ov05_0221E60C
	.public ov05_0221E624
	.public ov05_0221E714
	.public ov05_0221E74C
	.public ov05_0221E7B8
	.public ov05_0221E8A8
	.public ov05_0221E944
	.public ov05_0221E9C4
	.public ov05_0221E9F8
	.public ov05_0221EA18
	.public ov05_0221EA38
	.public _0221EA54
	.public ov05_0221EA58
	.public ov05_0221EA60
	.public ov05_0221EA6C
	.public ov05_0221EA6D
	.public ov05_0221EA78
	.public ov05_0221EA88
	.public ov05_0221EA98
	.public ov05_0221EAAC
	.public ov05_0221EAC0
	.public ov05_0221EAD4
	.public ov05_0221EAEC
	.public ov05_0221EB04
	.public ov05_0221EB1C
	.public ov05_0221EB38
	.public ov05_0221EB54
	.public ov05_0221EB70
	.public ov05_0221EB8C
	.public ov05_0221EBA8
	.public ov05_0221EBC4
	.public ov05_0221EBE0
	.public ov05_0221EC00
	.public ov05_0221EC28
	.public ov05_0221EC5C
	.public ov05_0221EC98
	.public ov05_0221ECE4
	.public ov05_0221EDA4
	.public ov05_0221EF2C
	.include "overlay_05.inc"
	.include "global.inc"

	.text

	thumb_func_start ov05_0221D094
ov05_0221D094: ; 0x0221D094
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0x68
	ldr r1, [r1, #0x24]
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	ldr r2, [r5]
	mov r3, #1
	ldr r2, [r2, #0x24]
	add r4, r0, #0
	str r2, [sp, #0xc]
	ldr r2, [r5, #0xc]
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #4
	ldr r0, [r0, #0x24]
	mov r3, #1
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #2
	ldr r0, [r0, #0x24]
	add r3, r1, #0
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5]
	mov r1, #3
	ldr r0, [r0, #0x24]
	add r3, r1, #0
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r2, #0
	str r2, [sp]
	ldr r0, [r5]
	mov r1, #1
	ldr r0, [r0, #0x24]
	add r3, r2, #0
	str r0, [sp, #4]
	add r0, r4, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r1, #0
	ldr r0, [r5, #8]
	add r2, r1, #0
	mov r3, #0xa0
	bl PaletteData_LoadPaletteSlotFromHardware
	ldr r1, _0221D13C ; =0x000018C6
	mov r0, #1
	bl BG_SetMaskColor
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0221D13C: .word 0x000018C6
	thumb_func_end ov05_0221D094


	thumb_func_start ov05_0221D140
ov05_0221D140: ; 0x0221D140
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	ldr r0, _0221D21C ; =0x00000BA8
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0221D164
	ldr r0, [r4]
	cmp r0, #0
	beq _0221D164
	ldr r1, [r0]
	cmp r1, #0
	beq _0221D164
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	cmp r0, #0
	bne _0221D168
_0221D164:
	bl GF_AssertFail
_0221D168:
	ldr r0, [r4]
	ldr r1, [r0]
	mov r0, #0x13
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #0
	ldr r0, [r0, #0x24]
	mov r2, #1
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	mov r3, #0xf
	bl LoadUserFrameGfx2
	ldr r0, [r4, #8]
	mov r1, #0
	mov r2, #0xf0
	mov r3, #0x20
	bl PaletteData_LoadPaletteSlotFromHardware
	mov r1, #0
	str r1, [sp]
	ldr r0, [r4]
	mov r2, #0x1f
	ldr r0, [r0, #0x24]
	mov r3, #0xe
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	bl LoadUserFrameGfx1
	ldr r0, [r4, #8]
	mov r1, #0
	mov r2, #0xe0
	mov r3, #0x20
	bl PaletteData_LoadPaletteSlotFromHardware
	ldr r2, [r4]
	mov r1, #0x1a
	ldr r2, [r2, #0x24]
	mov r0, #0
	lsl r1, r1, #4
	bl LoadFontPal0
	ldr r0, [r4, #8]
	mov r1, #0
	mov r2, #0xd0
	mov r3, #0x20
	bl PaletteData_LoadPaletteSlotFromHardware
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x28
	ldr r1, _0221D220 ; =0x00000B88
	str r0, [sp, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r4, r1
	mov r2, #0
	mov r3, #2
	bl AddWindowParameterized
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x28
	ldr r1, _0221D224 ; =0x00000B98
	str r0, [sp, #0x10]
	ldr r0, [r4, #0xc]
	add r1, r4, r1
	mov r2, #0
	mov r3, #2
	bl AddWindowParameterized
	add sp, #0x14
	pop {r3, r4, pc}
	.balign 4, 0
_0221D21C: .word 0x00000BA8
_0221D220: .word 0x00000B88
_0221D224: .word 0x00000B98
	thumb_func_end ov05_0221D140
