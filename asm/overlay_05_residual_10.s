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

	thumb_func_start ov05_0221D240
ov05_0221D240: ; 0x0221D240
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r4, _0221D310 ; =ov05_0221EB04
	add r3, sp, #0
	add r6, r0, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r1, r2, #0
	add r0, r6, #0
	mov r2, #0x15
	bl ov05_0221CD24
	add r0, r6, #0
	bl ov05_0221D318
	ldr r4, _0221D314 ; =ov05_0221EDA4
	mov r7, #0
	add r5, r6, #0
_0221D26E:
	add r0, r6, #0
	add r1, r4, #0
	bl ov05_0221CDC4
	mov r1, #0x66
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r7, r7, #1
	add r4, #0x1c
	add r5, r5, #4
	cmp r7, #0xc
	blo _0221D26E
	mov r1, #0
	mov r2, #0xff
	add r0, r6, #0
	mvn r2, r2
	add r3, r1, #0
	bl ov05_0221D3AC
	mov r2, #0xff
	add r0, r6, #0
	mov r1, #1
	mvn r2, r2
	mov r3, #0
	bl ov05_0221D3AC
	mov r1, #2
	add r2, r1, #0
	add r0, r6, #0
	add r2, #0xfe
	mov r3, #0
	bl ov05_0221D3AC
	mov r1, #3
	add r2, r1, #0
	add r0, r6, #0
	add r2, #0xfd
	mov r3, #0
	bl ov05_0221D3AC
	add r0, r6, #0
	bl ov05_0221D4D0
	mov r0, #0x21
	mov r1, #0xc
	lsl r0, r0, #4
	str r1, [r6, r0]
	add r0, r6, #0
	bl ov05_0221D5DC
	mov r1, #0
	mov r2, #0xff
	add r0, r6, #0
	mvn r2, r2
	add r3, r1, #0
	bl ov05_0221D664
	mov r2, #0xff
	add r0, r6, #0
	mov r1, #1
	mvn r2, r2
	mov r3, #0
	bl ov05_0221D664
	mov r1, #2
	add r2, r1, #0
	add r0, r6, #0
	add r2, #0xfe
	mov r3, #0
	bl ov05_0221D664
	mov r1, #3
	add r2, r1, #0
	add r0, r6, #0
	add r2, #0xfd
	mov r3, #0
	bl ov05_0221D664
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221D310: .word ov05_0221EB04
_0221D314: .word ov05_0221EDA4
	thumb_func_end ov05_0221D240


	thumb_func_start ov05_0221D318
ov05_0221D318: ; 0x0221D318
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #8
	ldr r1, [r1, #0x24]
	bl NARC_New
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _0221D3A8 ; =0x0000B807
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0xd0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _0221D3A8 ; =0x0000B807
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x68
	mov r3, #8
	bl SpriteSystem_LoadPlttResObj
	mov r0, #1
	str r0, [sp]
	ldr r0, _0221D3A8 ; =0x0000B807
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0xcf
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #1
	str r0, [sp]
	ldr r0, _0221D3A8 ; =0x0000B807
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #0xd1
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0221D3A8: .word 0x0000B807
	thumb_func_end ov05_0221D318


	thumb_func_start ov05_0221D3AC
ov05_0221D3AC: ; 0x0221D3AC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r4, _0221D408 ; =_0221EA54
	str r2, [sp]
	ldrb r5, [r4]
	str r3, [sp, #4]
	add r3, sp, #8
	strb r5, [r3]
	ldrb r5, [r4, #1]
	add r2, sp, #8
	mov r7, #0
	strb r5, [r3, #1]
	ldrb r5, [r4, #2]
	ldrb r4, [r4, #3]
	add r6, r0, r1
	strb r5, [r3, #2]
	strb r4, [r3, #3]
	ldrb r2, [r2, r1]
	add r4, r7, #0
	lsl r2, r2, #2
	add r5, r0, r2
_0221D3D6:
	ldr r1, _0221D40C ; =0x00000B64
	mov r0, #0x66
	ldrb r1, [r6, r1]
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r1, r4
	ldr r1, [sp]
	add r1, r1, r2
	ldr r2, _0221D410 ; =0x00000B68
	lsl r1, r1, #0x10
	ldrb r3, [r6, r2]
	ldr r2, [sp, #4]
	asr r1, r1, #0x10
	add r2, r2, r3
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
	add r7, r7, #1
	add r4, #0x13
	add r5, r5, #4
	cmp r7, #3
	blo _0221D3D6
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221D408: .word _0221EA54
_0221D40C: .word 0x00000B64
_0221D410: .word 0x00000B68
	thumb_func_end ov05_0221D3AC


	thumb_func_start ov05_0221D414
ov05_0221D414: ; 0x0221D414
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	add r0, r1, #0
	str r1, [sp]
	str r2, [sp, #4]
	add r7, r3, #0
	bl Party_GetCount
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r5, #0
	ldr r0, [sp, #4]
	add r4, r5, #0
	cmp r0, #0
	ble _0221D4CC
	lsl r0, r7, #2
	add r6, r6, r0
_0221D43A:
	lsl r0, r4, #2
	add r1, r6, r0
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	ldr r0, [sp, #8]
	cmp r0, r4
	bls _0221D4C0
	ldr r0, [sp]
	add r1, r4, #0
	bl Party_GetMonByIndex
	mov r1, #5
	mov r2, #0
	add r7, r0, #0
	bl GetMonData
	cmp r0, #0
	beq _0221D4C0
	add r0, r7, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _0221D4C0
	add r0, r7, #0
	bl Pokemon_GetStatusIconId
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #6
	bne _0221D494
	lsl r0, r5, #2
	add r1, r6, r0
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #3
	bl ManagedSprite_SetAnim
	b _0221D4BA
_0221D494:
	cmp r0, #7
	beq _0221D4AA
	lsl r0, r5, #2
	add r1, r6, r0
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #2
	bl ManagedSprite_SetAnim
	b _0221D4BA
_0221D4AA:
	lsl r0, r5, #2
	add r1, r6, r0
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #1
	bl ManagedSprite_SetAnim
_0221D4BA:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
_0221D4C0:
	add r0, r4, #1
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	ldr r0, [sp, #4]
	cmp r4, r0
	blt _0221D43A
_0221D4CC:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov05_0221D414


	thumb_func_start ov05_0221D4D0
ov05_0221D4D0: ; 0x0221D4D0
	push {r4, lr}
	add r4, r0, #0
	ldr r2, [r4]
	add r1, r2, #0
	add r1, #0x29
	ldrb r1, [r1]
	cmp r1, #0
	ldr r1, [r2, #4]
	bne _0221D4FA
	mov r2, #6
	mov r3, #0
	bl ov05_0221D414
	ldr r1, [r4]
	mov r2, #6
	ldr r1, [r1, #8]
	add r0, r4, #0
	add r3, r2, #0
	bl ov05_0221D414
	pop {r4, pc}
_0221D4FA:
	mov r2, #3
	mov r3, #0
	bl ov05_0221D414
	ldr r1, [r4]
	mov r2, #3
	ldr r1, [r1, #0xc]
	add r0, r4, #0
	add r3, r2, #0
	bl ov05_0221D414
	ldr r1, [r4]
	add r0, r4, #0
	ldr r1, [r1, #8]
	mov r2, #3
	mov r3, #6
	bl ov05_0221D414
	ldr r1, [r4]
	add r0, r4, #0
	ldr r1, [r1, #0x10]
	mov r2, #3
	mov r3, #9
	bl ov05_0221D414
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov05_0221D4D0


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


	thumb_func_start ov05_0221D5DC
ov05_0221D5DC: ; 0x0221D5DC
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4]
	mov r0, #8
	ldr r1, [r1, #0x24]
	bl FontSystem_NewInit
	ldr r1, _0221D658 ; =0x00000B44
	str r0, [r4, r1]
	ldr r2, [r4]
	add r0, r4, #0
	ldr r2, [r2, #0x14]
	mov r1, #0
	bl ov05_0221D530
	ldr r2, [r4]
	add r0, r4, #0
	ldr r2, [r2, #0x18]
	mov r1, #2
	bl ov05_0221D530
	ldr r2, [r4]
	add r0, r2, #0
	add r0, #0x29
	ldrb r0, [r0]
	cmp r0, #1
	bne _0221D62A
	ldr r2, [r2, #0x1c]
	add r0, r4, #0
	mov r1, #1
	bl ov05_0221D530
	ldr r2, [r4]
	add r0, r4, #0
	ldr r2, [r2, #0x20]
	mov r1, #3
	bl ov05_0221D530
	pop {r4, pc}
_0221D62A:
	ldr r2, [r2, #0x14]
	add r0, r4, #0
	mov r1, #1
	bl ov05_0221D530
	ldr r2, [r4]
	add r0, r4, #0
	ldr r2, [r2, #0x18]
	mov r1, #3
	bl ov05_0221D530
	ldr r0, _0221D65C ; =0x00000B4C
	mov r1, #0
	ldr r0, [r4, r0]
	bl TextOBJ_SetSpritesDrawFlag
	ldr r0, _0221D660 ; =0x00000B54
	mov r1, #0
	ldr r0, [r4, r0]
	bl TextOBJ_SetSpritesDrawFlag
	pop {r4, pc}
	nop
_0221D658: .word 0x00000B44
_0221D65C: .word 0x00000B4C
_0221D660: .word 0x00000B54
	thumb_func_end ov05_0221D5DC


	thumb_func_start ov05_0221D664
ov05_0221D664: ; 0x0221D664
	push {r3, r4, r5, lr}
	add r5, r1, #0
	add r1, r2, #0
	add r2, r3, #0
	add r4, r0, #0
	lsl r0, r5, #2
	add r0, r4, r0
	ldr r3, _0221D68C ; =0x00000B48
	add r4, r4, r5
	add r5, r3, #0
	ldr r0, [r0, r3]
	add r5, #0x24
	add r3, #0x28
	ldrb r5, [r4, r5]
	ldrb r3, [r4, r3]
	add r1, r1, r5
	add r2, r2, r3
	bl sub_020136B4
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0221D68C: .word 0x00000B48
	thumb_func_end ov05_0221D664


	thumb_func_start ov05_0221D690
ov05_0221D690: ; 0x0221D690
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r0, [r7]
	add r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0221D6BA
	ldr r6, _0221D6BC ; =0x00000B48
	mov r4, #0
	add r5, r7, #0
_0221D6A4:
	ldr r0, [r5, r6]
	bl FontOAM_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blo _0221D6A4
	ldr r0, _0221D6C0 ; =0x00000B44
	ldr r0, [r7, r0]
	bl sub_020135AC
_0221D6BA:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221D6BC: .word 0x00000B48
_0221D6C0: .word 0x00000B44
	thumb_func_end ov05_0221D690


	thumb_func_start ov05_0221D6C4
ov05_0221D6C4: ; 0x0221D6C4
	push {r3, r4, r5, r6}
	ldr r3, [r0]
	add r3, #0x29
	ldrb r3, [r3]
	cmp r3, #1
	ldr r3, _0221D7A8 ; =0x00000B64
	bne _0221D74E
	mov r4, #0x14
	add r5, r1, #0
	strb r4, [r0, r3]
	add r5, #0x92
	add r4, r3, #4
	strb r5, [r0, r4]
	mov r5, #0x51
	add r4, r3, #1
	strb r5, [r0, r4]
	add r5, r1, #0
	add r5, #0xa2
	add r4, r3, #5
	strb r5, [r0, r4]
	mov r5, #0x80
	add r4, r3, #2
	strb r5, [r0, r4]
	add r5, r2, #0
	add r5, #0x2c
	add r4, r3, #6
	strb r5, [r0, r4]
	mov r5, #0xbd
	add r4, r3, #3
	strb r5, [r0, r4]
	add r5, r2, #0
	add r5, #0x3c
	add r4, r3, #7
	strb r5, [r0, r4]
	add r4, r3, #0
	mov r5, #0xb
	add r4, #8
	strb r5, [r0, r4]
	add r5, r1, #0
	add r4, r3, #0
	add r5, #0x78
	add r4, #0xc
	strb r5, [r0, r4]
	add r4, r3, #0
	mov r5, #0x4c
	add r4, #9
	strb r5, [r0, r4]
	add r4, r3, #0
	add r1, #0x88
	add r4, #0xd
	strb r1, [r0, r4]
	add r1, r3, #0
	mov r4, #0x77
	add r1, #0xa
	strb r4, [r0, r1]
	add r4, r2, #0
	add r1, r3, #0
	add r4, #0x12
	add r1, #0xe
	strb r4, [r0, r1]
	add r1, r3, #0
	mov r4, #0xb8
	add r1, #0xb
	strb r4, [r0, r1]
	add r2, #0x22
	add r3, #0xf
	strb r2, [r0, r3]
	pop {r3, r4, r5, r6}
	bx lr
_0221D74E:
	mov r4, #0x18
	strb r4, [r0, r3]
	add r4, r1, #0
	add r4, #0xa0
	lsl r4, r4, #0x18
	lsr r4, r4, #0x18
	add r5, r3, #4
	strb r4, [r0, r5]
	mov r6, #0x51
	add r5, r3, #1
	strb r6, [r0, r5]
	add r5, r3, #5
	strb r4, [r0, r5]
	mov r5, #0x88
	add r4, r3, #2
	strb r5, [r0, r4]
	add r4, r2, #0
	add r4, #0x30
	lsl r4, r4, #0x18
	lsr r4, r4, #0x18
	add r5, r3, #6
	strb r4, [r0, r5]
	mov r6, #0xc1
	add r5, r3, #3
	strb r6, [r0, r5]
	add r5, r3, #7
	strb r4, [r0, r5]
	add r4, r3, #0
	mov r5, #0xf
	add r4, #8
	strb r5, [r0, r4]
	add r4, r3, #0
	add r1, #0x86
	add r4, #0xc
	strb r1, [r0, r4]
	add r1, r3, #0
	mov r4, #0x80
	add r1, #0xa
	strb r4, [r0, r1]
	add r2, #0x16
	add r3, #0xe
	strb r2, [r0, r3]
	pop {r3, r4, r5, r6}
	bx lr
	nop
_0221D7A8: .word 0x00000B64
	thumb_func_end ov05_0221D6C4


	thumb_func_start ov05_0221D7AC
ov05_0221D7AC: ; 0x0221D7AC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	ldr r4, _0221D888 ; =ov05_0221EAD4
	add r3, sp, #0
	add r6, r0, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r1, r2, #0
	add r0, r6, #0
	mov r2, #0x17
	bl ov05_0221CD24
	add r0, r6, #0
	bl ov05_0221D318
	add r0, r6, #0
	bl ov05_0221D890
	ldr r4, _0221D88C ; =ov05_0221EDA4
	mov r7, #0
	add r5, r6, #0
_0221D7E0:
	add r0, r6, #0
	add r1, r4, #0
	bl ov05_0221CDC4
	mov r1, #0x66
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r7, r7, #1
	add r4, #0x1c
	add r5, r5, #4
	cmp r7, #0xe
	blo _0221D7E0
	mov r1, #0
	mov r2, #0xff
	add r0, r6, #0
	mvn r2, r2
	add r3, r1, #0
	bl ov05_0221D3AC
	mov r2, #0xff
	add r0, r6, #0
	mov r1, #1
	mvn r2, r2
	mov r3, #0
	bl ov05_0221D3AC
	mov r1, #2
	add r2, r1, #0
	add r0, r6, #0
	add r2, #0xfe
	mov r3, #0
	bl ov05_0221D3AC
	mov r1, #3
	add r2, r1, #0
	add r0, r6, #0
	add r2, #0xfd
	mov r3, #0
	bl ov05_0221D3AC
	add r0, r6, #0
	bl ov05_0221D4D0
	add r0, r6, #0
	bl ov05_0221D904
	add r0, r6, #0
	bl ov05_0221D5DC
	mov r1, #0
	mov r2, #0xff
	add r0, r6, #0
	mvn r2, r2
	add r3, r1, #0
	bl ov05_0221D664
	mov r2, #0xff
	add r0, r6, #0
	mov r1, #1
	mvn r2, r2
	mov r3, #0
	bl ov05_0221D664
	mov r1, #2
	add r2, r1, #0
	add r0, r6, #0
	add r2, #0xfe
	mov r3, #0
	bl ov05_0221D664
	mov r1, #3
	add r2, r1, #0
	add r0, r6, #0
	add r2, #0xfd
	mov r3, #0
	bl ov05_0221D664
	mov r0, #0x21
	mov r1, #0xe
	lsl r0, r0, #4
	str r1, [r6, r0]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221D888: .word ov05_0221EAD4
_0221D88C: .word ov05_0221EDA4
	thumb_func_end ov05_0221D7AC


	thumb_func_start ov05_0221D890
ov05_0221D890: ; 0x0221D890
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0x68
	ldr r1, [r1, #0x24]
	bl NARC_New
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _0221D900 ; =0x0000B808
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #5
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221D900 ; =0x0000B808
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #6
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	mov r0, #0
	str r0, [sp]
	ldr r0, _0221D900 ; =0x0000B808
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	mov r3, #7
	bl SpriteSystem_LoadAnimResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_0221D900: .word 0x0000B808
	thumb_func_end ov05_0221D890


	thumb_func_start ov05_0221D904
ov05_0221D904: ; 0x0221D904
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	ldr r0, [r4]
	add r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #3
	bne _0221D946
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl ManagedSprite_SetAnim
	pop {r4, pc}
_0221D946:
	bl ov05_0221CCF4
	cmp r0, #1
	ldr r0, [r4]
	bne _0221D994
	add r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #1
	bne _0221D976
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x30
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xd0
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
	b _0221D9D6
_0221D976:
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xd0
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x30
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
	b _0221D9D6
_0221D994:
	add r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #1
	bne _0221D9BA
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xd0
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x30
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
	b _0221D9D6
_0221D9BA:
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x30
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0xd0
	mov r2, #0x48
	bl ManagedSprite_SetPositionXY
_0221D9D6:
	mov r0, #0x72
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetAnim
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ManagedSprite_SetAnim
	pop {r4, pc}
	thumb_func_end ov05_0221D904


	thumb_func_start ov05_0221D9F0
ov05_0221D9F0: ; 0x0221D9F0
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	mov r0, #2
	mov r1, #0
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r4]
	mov r2, #4
	ldr r0, [r0, #0x24]
	add r3, r1, #0
	bl GF_3DVramMan_Create
	ldr r1, _0221DAC8 ; =0x00000B58
	ldr r2, _0221DACC ; =0x04000060
	str r0, [r4, r1]
	ldrh r1, [r2]
	ldr r0, _0221DAD0 ; =0xFFFFCFFF
	and r1, r0
	mov r0, #8
	orr r0, r1
	strh r0, [r2]
	bl sub_02014DA0
	ldr r0, [r4]
	mov r1, #0x12
	ldr r0, [r0, #0x24]
	lsl r1, r1, #0xa
	bl Heap_Alloc
	mov r2, #0xb6
	lsl r2, r2, #4
	str r0, [r4, r2]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4]
	mov r3, #0x12
	ldr r0, [r0, #0x24]
	ldr r1, _0221DAD4 ; =ov05_0221DB70
	str r0, [sp, #4]
	ldr r0, _0221DAD8 ; =ov05_0221DB4C
	ldr r2, [r4, r2]
	lsl r3, r3, #0xa
	bl sub_02014DB4
	ldr r1, _0221DADC ; =0x00000B5C
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	bl sub_02015524
	add r2, r0, #0
	mov r0, #1
	mov r1, #0xe1
	lsl r0, r0, #0xc
	lsl r1, r1, #0xe
	bl Camera_SetPerspectiveClippingPlane
	ldr r2, [r4]
	mov r0, #0x3b
	ldr r2, [r2, #0x24]
	mov r1, #2
	bl sub_02015264
	add r1, r0, #0
	ldr r0, _0221DADC ; =0x00000B5C
	mov r2, #0xa
	ldr r0, [r4, r0]
	mov r3, #1
	bl sub_0201526C
	mov r1, #0
	ldr r0, _0221DADC ; =0x00000B5C
	add r2, r1, #0
	ldr r0, [r4, r0]
	add r3, r1, #0
	bl sub_02015494
	ldr r0, _0221DADC ; =0x00000B5C
	mov r2, #0
	ldr r0, [r4, r0]
	mov r1, #1
	add r3, r2, #0
	bl sub_02015494
	ldr r0, _0221DADC ; =0x00000B5C
	mov r2, #0
	ldr r0, [r4, r0]
	mov r1, #2
	add r3, r2, #0
	bl sub_02015494
	ldr r0, _0221DADC ; =0x00000B5C
	mov r2, #0
	ldr r0, [r4, r0]
	mov r1, #3
	add r3, r2, #0
	bl sub_02015494
	ldr r0, _0221DADC ; =0x00000B5C
	mov r2, #0
	ldr r0, [r4, r0]
	mov r1, #4
	add r3, r2, #0
	bl sub_02015494
	add sp, #8
	pop {r4, pc}
	nop
_0221DAC8: .word 0x00000B58
_0221DACC: .word 0x04000060
_0221DAD0: .word 0xFFFFCFFF
_0221DAD4: .word ov05_0221DB70
_0221DAD8: .word ov05_0221DB4C
_0221DADC: .word 0x00000B5C
	thumb_func_end ov05_0221D9F0
