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

	thumb_func_start ov05_0221BB30
ov05_0221BB30: ; 0x0221BB30
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	bl ov05_0221E9F8
	cmp r0, #0
	bne _0221BB40
	b _0221BD08
_0221BB40:
	ldr r2, _0221BD0C ; =0x00000BBC
	ldr r0, [r4, r2]
	cmp r0, #8
	bhi _0221BBBA
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221BB54: ; jump table
	.short _0221BD08 - _0221BB54 - 2 ; case 0
	.short _0221BB66 - _0221BB54 - 2 ; case 1
	.short _0221BBA6 - _0221BB54 - 2 ; case 2
	.short _0221BBC4 - _0221BB54 - 2 ; case 3
	.short _0221BC5C - _0221BB54 - 2 ; case 4
	.short _0221BC98 - _0221BB54 - 2 ; case 5
	.short _0221BD08 - _0221BB54 - 2 ; case 6
	.short _0221BCD8 - _0221BB54 - 2 ; case 7
	.short _0221BD08 - _0221BB54 - 2 ; case 8
_0221BB66:
	add r0, r4, #0
	bl ov05_0221E9C4
	ldr r2, _0221BD10 ; =0x00000BAC
	mov r1, #0
	ldr r0, [r4, r2]
	add r2, #8
	ldr r2, [r4, r2]
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	ldr r2, _0221BD14 ; =0x00000B88
	str r3, [sp, #4]
	add r0, r4, r2
	str r3, [sp, #8]
	add r2, #0x2c
	ldr r2, [r4, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0221BD18 ; =0x00000BB8
	str r0, [r4, r1]
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _0221BD0C ; =0x00000BBC
	mov r1, #2
	add sp, #0xc
	str r1, [r4, r0]
	pop {r3, r4, pc}
_0221BBA6:
	add r0, r2, #0
	add r0, #0xc
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0221BBBA
	ldr r0, _0221BD1C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	bne _0221BBBC
_0221BBBA:
	b _0221BD08
_0221BBBC:
	mov r0, #3
	add sp, #0xc
	str r0, [r4, r2]
	pop {r3, r4, pc}
_0221BBC4:
	add r0, r2, #0
	add r0, #0x10
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0221BBE0
	add r0, r2, #0
	sub r0, #0x10
	sub r2, #8
	ldr r0, [r4, r0]
	ldr r2, [r4, r2]
	mov r1, #2
	bl ReadMsgDataIntoString
	b _0221BBF0
_0221BBE0:
	add r0, r2, #0
	sub r0, #0x10
	sub r2, #8
	ldr r0, [r4, r0]
	ldr r2, [r4, r2]
	mov r1, #1
	bl ReadMsgDataIntoString
_0221BBF0:
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, _0221BD20 ; =0x00000B98
	mov r2, #0
	add r0, r4, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	ldr r0, _0221BD20 ; =0x00000B98
	mov r1, #0
	add r0, r4, r0
	mov r2, #1
	mov r3, #0xf
	bl DrawFrameAndWindow2
	mov r3, #0
	str r3, [sp]
	ldr r2, _0221BD20 ; =0x00000B98
	str r3, [sp, #4]
	add r0, r4, r2
	str r3, [sp, #8]
	add r2, #0x1c
	ldr r2, [r4, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0221BD18 ; =0x00000BB8
	mov r2, #0x1f
	str r0, [r4, r1]
	mov r0, #1
	str r0, [sp]
	ldr r0, [r4]
	ldr r1, _0221BD24 ; =ov05_0221EA58
	ldr r0, [r0, #0x24]
	mov r3, #0xe
	str r0, [sp, #4]
	ldr r0, [r4, #0xc]
	bl CreateYesNoMenu
	mov r1, #0x2f
	lsl r1, r1, #6
	str r0, [r4, r1]
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _0221BD0C ; =0x00000BBC
	mov r1, #4
	add sp, #0xc
	str r1, [r4, r0]
	pop {r3, r4, pc}
_0221BC5C:
	ldr r1, [r4]
	add r0, r2, #4
	ldr r0, [r4, r0]
	ldr r1, [r1, #0x24]
	bl Handle2dMenuInput_DeleteOnFinish
	cmp r0, #0
	beq _0221BC78
	mov r1, #1
	mvn r1, r1
	cmp r0, r1
	beq _0221BC88
	add sp, #0xc
	pop {r3, r4, pc}
_0221BC78:
	ldr r0, _0221BD0C ; =0x00000BBC
	mov r1, #5
	str r1, [r4, r0]
	mov r1, #0
	add r0, r0, #4
	add sp, #0xc
	str r1, [r4, r0]
	pop {r3, r4, pc}
_0221BC88:
	ldr r0, _0221BD0C ; =0x00000BBC
	mov r1, #1
	str r1, [r4, r0]
	mov r1, #0
	add r0, r0, #4
	add sp, #0xc
	str r1, [r4, r0]
	pop {r3, r4, pc}
_0221BC98:
	add r0, r4, #0
	bl ov05_0221E9C4
	ldr r2, _0221BD10 ; =0x00000BAC
	mov r1, #5
	ldr r0, [r4, r2]
	add r2, #8
	ldr r2, [r4, r2]
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	ldr r2, _0221BD14 ; =0x00000B88
	str r3, [sp, #4]
	add r0, r4, r2
	str r3, [sp, #8]
	add r2, #0x2c
	ldr r2, [r4, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0221BD18 ; =0x00000BB8
	str r0, [r4, r1]
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _0221BD0C ; =0x00000BBC
	mov r1, #6
	add sp, #0xc
	str r1, [r4, r0]
	pop {r3, r4, pc}
_0221BCD8:
	add r0, r2, #4
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0221BCF0
	ldr r1, [r4]
	ldr r1, [r1, #0x24]
	bl Clear2dMenuWindowAndDelete
	mov r0, #0x2f
	mov r1, #0
	lsl r0, r0, #6
	str r1, [r4, r0]
_0221BCF0:
	ldr r0, _0221BD14 ; =0x00000B88
	mov r1, #0
	add r0, r4, r0
	bl ClearFrameAndWindow2
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _0221BD0C ; =0x00000BBC
	mov r1, #8
	str r1, [r4, r0]
_0221BD08:
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_0221BD0C: .word 0x00000BBC
_0221BD10: .word 0x00000BAC
_0221BD14: .word 0x00000B88
_0221BD18: .word 0x00000BB8
_0221BD1C: .word gSystem
_0221BD20: .word 0x00000B98
_0221BD24: .word ov05_0221EA58
	thumb_func_end ov05_0221BB30


	thumb_func_start ov05_0221BD28
ov05_0221BD28: ; 0x0221BD28
	push {r3, r4, r5, lr}
	ldr r1, _0221BDE0 ; =0x04000050
	add r4, r0, #0
	mov r0, #0
	strh r0, [r1]
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r1, #1
	lsl r1, r1, #0x1a
	ldr r0, [r1]
	ldr r2, _0221BDE4 ; =0xFFFFE0FF
	ldr r5, _0221BDE8 ; =0x04000304
	and r0, r2
	str r0, [r1]
	ldr r0, _0221BDEC ; =0x04001000
	add r1, #0x50
	ldr r3, [r0]
	and r2, r3
	str r2, [r0]
	ldrh r3, [r5]
	lsr r2, r5, #0xb
	add r0, #0x50
	orr r2, r3
	strh r2, [r5]
	mov r2, #0
	strh r2, [r1]
	strh r2, [r0]
	bl ov05_0221BB00
	ldr r0, [r4]
	ldr r0, [r0, #0x24]
	bl BgConfig_Alloc
	str r0, [r4, #0xc]
	ldr r0, [r4]
	ldr r0, [r0, #0x24]
	bl PaletteData_Init
	str r0, [r4, #8]
	ldr r3, [r4]
	mov r1, #0
	ldr r3, [r3, #0x24]
	lsr r2, r5, #0x11
	bl PaletteData_AllocBuffers
	mov r0, #4
	mov r1, #0
	bl BG_SetMaskColor
	ldr r0, _0221BDF0 ; =0x00000B82
	mov r3, #0
	strb r3, [r4, r0]
	sub r1, r0, #1
	mov r2, #8
	strb r2, [r4, r1]
	sub r0, r0, #2
	strb r3, [r4, r0]
	ldr r1, [r4]
	add r0, r1, #0
	add r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0221BDBE
	cmp r0, #1
	beq _0221BDC4
	cmp r0, #2
	beq _0221BDCA
	b _0221BDDC
_0221BDBE:
	ldr r0, _0221BDF4 ; =ov05_0221EAC0
	str r0, [r4, #4]
	b _0221BDDC
_0221BDC4:
	ldr r0, _0221BDF8 ; =ov05_0221EA98
	str r0, [r4, #4]
	b _0221BDDC
_0221BDCA:
	add r1, #0x2a
	ldrb r0, [r1]
	cmp r0, #3
	bne _0221BDD8
	ldr r0, _0221BDFC ; =ov05_0221EC28
	str r0, [r4, #4]
	b _0221BDDC
_0221BDD8:
	ldr r0, _0221BE00 ; =ov05_0221EC98
	str r0, [r4, #4]
_0221BDDC:
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0221BDE0: .word 0x04000050
_0221BDE4: .word 0xFFFFE0FF
_0221BDE8: .word 0x04000304
_0221BDEC: .word 0x04001000
_0221BDF0: .word 0x00000B82
_0221BDF4: .word ov05_0221EAC0
_0221BDF8: .word ov05_0221EA98
_0221BDFC: .word ov05_0221EC28
_0221BE00: .word ov05_0221EC98
	thumb_func_end ov05_0221BD28


	thumb_func_start ov05_0221BE04
ov05_0221BE04: ; 0x0221BE04
	push {r4, lr}
	ldr r1, _0221BE78 ; =0x00000B82
	add r4, r0, #0
	ldrb r2, [r4, r1]
	cmp r2, #0
	beq _0221BE1A
	cmp r2, #1
	beq _0221BE26
	cmp r2, #2
	beq _0221BE32
	b _0221BE6C
_0221BE1A:
	bl ov05_0221DB94
	add r0, r4, #0
	bl ov05_0221DC60
	b _0221BE6C
_0221BE26:
	bl ov05_0221E07C
	add r0, r4, #0
	bl ov05_0221E274
	b _0221BE6C
_0221BE32:
	mov r2, #0
	strb r2, [r4, r1]
	mov r2, #0x20
	sub r1, r1, #1
	strb r2, [r4, r1]
	bl ov05_0221DD08
	add r0, r4, #0
	bl ov05_0221E5E4
	add r0, r4, #0
	bl ov05_0221E944
	add r0, r4, #0
	bl ov05_0221DE38
	bl sub_0203A880
	ldr r1, [r4]
	mov r0, #0
	ldr r1, [r1, #0x24]
	bl sub_020880CC
	ldr r0, _0221BE7C ; =ov05_0221CE88
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #1
	pop {r4, pc}
_0221BE6C:
	ldr r0, _0221BE78 ; =0x00000B82
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_0221BE78: .word 0x00000B82
_0221BE7C: .word ov05_0221CE88
	thumb_func_end ov05_0221BE04


	thumb_func_start ov05_0221BE80
ov05_0221BE80: ; 0x0221BE80
	push {r4, lr}
	ldr r1, _0221BF00 ; =0x00000B82
	add r4, r0, #0
	ldrb r1, [r4, r1]
	cmp r1, #0
	beq _0221BE96
	cmp r1, #1
	beq _0221BEAA
	cmp r1, #2
	beq _0221BEC4
	b _0221BEF2
_0221BE96:
	mov r1, #1
	mov r2, #0
	bl ov05_0221CEB8
	add r0, r4, #0
	bl ov05_0221D094
	bl ov05_0221D228
	b _0221BEF2
_0221BEAA:
	mov r1, #0
	add r2, r1, #0
	bl ov05_0221D6C4
	add r0, r4, #0
	bl ov05_0221D240
	bl sub_0203A880
	add r0, r4, #0
	bl ov05_0221D9F0
	b _0221BEF2
_0221BEC4:
	ldr r1, [r4]
	mov r0, #0
	ldr r1, [r1, #0x24]
	bl sub_020880CC
	ldr r0, _0221BF04 ; =ov05_0221CE88
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	ldr r1, _0221BF00 ; =0x00000B82
	mov r0, #0
	strb r0, [r4, r1]
	mov r2, #8
	sub r0, r1, #6
	strb r2, [r4, r0]
	sub r0, r1, #5
	mov r2, #4
	strb r2, [r4, r0]
	mov r0, #0x10
	sub r1, #0xe
	str r0, [r4, r1]
	mov r0, #1
	pop {r4, pc}
_0221BEF2:
	ldr r0, _0221BF00 ; =0x00000B82
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	mov r0, #0
	pop {r4, pc}
	nop
_0221BF00: .word 0x00000B82
_0221BF04: .word ov05_0221CE88
	thumb_func_end ov05_0221BE80


	thumb_func_start ov05_0221BF08
ov05_0221BF08: ; 0x0221BF08
	push {r3, r4, r5, lr}
	ldr r1, _0221C000 ; =0x00000B82
	add r5, r0, #0
	ldrb r1, [r5, r1]
	cmp r1, #0
	beq _0221BF1E
	cmp r1, #1
	beq _0221BF7A
	cmp r1, #2
	beq _0221BF92
	b _0221BFF2
_0221BF1E:
	mov r1, #0
	mov r2, #1
	bl ov05_0221CEB8
	add r0, r5, #0
	bl ov05_0221D094
	add r0, r5, #0
	bl ov05_0221D140
	bl ov05_0221D228
	ldr r2, [r5]
	mov r0, #7
	ldr r1, [r2]
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	ldr r1, [r2, #0x24]
	add r2, sp, #0
	mov r3, #0
	bl sub_0202FD28
	ldr r1, [sp]
	ldr r0, _0221C004 ; =0x00000BCC
	mov r4, #0
	str r1, [r5, r0]
	add r0, r0, #4
	str r4, [r5, r0]
_0221BF56:
	add r0, r4, #0
	bl sub_02034818
	cmp r0, #0
	beq _0221BF72
	bl PlayerProfile_GetVersion
	cmp r0, #0
	bne _0221BF72
	mov r0, #0xbd
	mov r1, #1
	lsl r0, r0, #4
	str r1, [r5, r0]
	b _0221BFF2
_0221BF72:
	add r4, r4, #1
	cmp r4, #8
	blt _0221BF56
	b _0221BFF2
_0221BF7A:
	mov r1, #0x1f
	mvn r1, r1
	add r2, r1, #0
	add r2, #0x10
	bl ov05_0221D6C4
	add r0, r5, #0
	bl ov05_0221D7AC
	bl sub_0203A880
	b _0221BFF2
_0221BF92:
	ldr r1, [r5]
	mov r0, #0
	ldr r1, [r1, #0x24]
	bl sub_020880CC
	ldr r0, _0221C008 ; =ov05_0221CE88
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	ldr r2, _0221C000 ; =0x00000B82
	mov r0, #0
	strb r0, [r5, r2]
	mov r3, #4
	sub r1, r2, #6
	strb r3, [r5, r1]
	sub r1, r2, #5
	mov r3, #2
	strb r3, [r5, r1]
	mov r1, #0xc
	sub r2, #0xe
	str r1, [r5, r2]
	ldr r3, [r5]
	ldr r2, _0221C00C ; =0x0000027E
	ldr r3, [r3, #0x24]
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	ldr r1, _0221C010 ; =0x00000BAC
	str r0, [r5, r1]
	ldr r0, [r5]
	ldr r0, [r0, #0x24]
	bl MessageFormat_New
	mov r1, #0xbb
	lsl r1, r1, #4
	str r0, [r5, r1]
	ldr r1, [r5]
	mov r0, #5
	ldr r1, [r1, #0x24]
	lsl r0, r0, #6
	bl String_New
	ldr r1, _0221C014 ; =0x00000BB4
	str r0, [r5, r1]
	mov r0, #1
	add r1, #8
	str r0, [r5, r1]
	pop {r3, r4, r5, pc}
_0221BFF2:
	ldr r0, _0221C000 ; =0x00000B82
	ldrb r1, [r5, r0]
	add r1, r1, #1
	strb r1, [r5, r0]
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0221C000: .word 0x00000B82
_0221C004: .word 0x00000BCC
_0221C008: .word ov05_0221CE88
_0221C00C: .word 0x0000027E
_0221C010: .word 0x00000BAC
_0221C014: .word 0x00000BB4
	thumb_func_end ov05_0221BF08
