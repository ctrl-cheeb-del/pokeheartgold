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
	.public ov05_0221DC60
	.public ov05_0221DE38
	.public ov05_0221E07C
	.public ov05_0221E274
	.public ov05_0221E390
	.public ov05_0221E42C
	.public ov05_0221E4C8
	.public ov05_0221E5E4
	.public ov05_0221E60C
	.public ov05_0221E714
	.public ov05_0221E74C


	thumb_func_start ov05_0221E624
ov05_0221E624: ; 0x0221E624
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	ldr r4, [sp, #0x3c]
	add r5, r0, #0
	add r7, r5, #0
	lsl r0, r4, #6
	add r7, #0x10
	str r0, [sp, #0x1c]
	str r1, [sp, #0x10]
	str r3, [sp, #0x14]
	ldr r6, [sp, #0x38]
	cmp r4, #3
	ldr r0, [r5]
	bhs _0221E64C
	ldr r0, [r0, #4]
	add r1, r4, #0
	bl Party_GetMonByIndex
	str r0, [sp, #0x18]
	b _0221E656
_0221E64C:
	ldr r0, [r0, #0xc]
	sub r1, r4, #3
	bl Party_GetMonByIndex
	str r0, [sp, #0x18]
_0221E656:
	add r1, r4, #0
	ldr r0, [sp, #0x10]
	add r1, #8
	bl NewString_ReadMsgData
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x18]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [sp, #0x14]
	mov r1, #0
	bl BufferBoxMonNickname
	ldr r0, [sp, #0x14]
	ldr r2, [sp, #0x20]
	add r1, r6, #0
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x20]
	bl String_Delete
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0221E708 ; =0x000F0E00
	add r2, r6, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r3, r1, #0
	add r0, r7, r0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0x18
	mul r0, r4
	add r2, r5, r0
	ldr r0, _0221E70C ; =0x00000222
	ldrb r1, [r2, r0]
	cmp r1, #0
	bne _0221E704
	sub r0, r0, #1
	ldrb r0, [r2, r0]
	cmp r0, #0
	bne _0221E6DC
	ldr r0, [sp, #0x10]
	mov r1, #0x1b
	add r2, r6, #0
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0xc1
	lsl r0, r0, #0xa
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r2, r6, #0
	add r0, r7, r0
	mov r3, #0x40
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_0221E6DC:
	cmp r0, #1
	bne _0221E704
	ldr r0, [sp, #0x10]
	mov r1, #0x1c
	add r2, r6, #0
	bl ReadMsgDataIntoString
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0221E710 ; =0x00050600
	add r2, r6, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	mov r3, #0x40
	add r0, r7, r0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
_0221E704:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221E708: .word 0x000F0E00
_0221E70C: .word 0x00000222
_0221E710: .word 0x00050600
	thumb_func_end ov05_0221E624
