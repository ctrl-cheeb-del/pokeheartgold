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

	thumb_func_start ov05_0221D530
ov05_0221D530: ; 0x0221D530
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	add r4, r0, #0
	mov r0, #0
	add r5, r4, #0
	str r0, [sp]
	str r0, [sp, #4]
	add r7, r2, #0
	add r5, #0x10
	add r6, r1, #0
	ldr r0, [r4, #0xc]
	add r1, r5, #0
	mov r2, #8
	mov r3, #2
	bl AddTextWindowTopLeftCorner
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0xc1
	lsl r0, r0, #0xa
	str r0, [sp, #8]
	add r0, r5, #0
	add r2, r7, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	ldr r0, _0221D5D0 ; =0x00000B44
	ldr r0, [r4, r0]
	str r0, [sp, #0x10]
	mov r0, #0x65
	str r5, [sp, #0x14]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl SpriteManager_GetSpriteList
	str r0, [sp, #0x18]
	mov r0, #0x65
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, _0221D5D4 ; =0x0000B807
	bl SpriteManager_FindPlttResourceProxy
	mov r1, #0x3e
	lsl r2, r6, #4
	lsl r1, r1, #4
	sub r1, r1, r2
	lsl r1, r1, #5
	str r0, [sp, #0x1c]
	mov r0, #0
	str r1, [sp, #0x24]
	mov r1, #2
	str r0, [sp, #0x20]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x34]
	mov r0, #1
	str r1, [sp, #0x30]
	str r0, [sp, #0x38]
	ldr r0, [r4]
	lsl r6, r6, #2
	ldr r0, [r0, #0x24]
	str r0, [sp, #0x3c]
	ldr r0, _0221D5D8 ; =0x00000B48
	add r4, r4, r0
	add r0, sp, #0x10
	bl sub_020135D8
	str r0, [r4, r6]
	ldr r0, [r4, r6]
	mov r1, #0
	bl TextOBJ_SetPaletteNum
	add r0, r5, #0
	bl RemoveWindow
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221D5D0: .word 0x00000B44
_0221D5D4: .word 0x0000B807
_0221D5D8: .word 0x00000B48
	thumb_func_end ov05_0221D530
