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

	thumb_func_start ov05_0221C908
ov05_0221C908: ; 0x0221C908
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	bl ov05_0221E9F8
	cmp r0, #0
	bne _0221C920
	ldr r1, _0221CA9C ; =0x00000B81
	mov r0, #1
	add sp, #0xc
	strb r0, [r4, r1]
	pop {r3, r4, pc}
_0221C920:
	mov r0, #0xbd
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	cmp r1, #0
	bne _0221C938
	sub r0, #0x10
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0221C938
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, pc}
_0221C938:
	ldr r0, _0221CAA0 ; =0x00000BBC
	ldr r1, [r4, r0]
	cmp r1, #5
	bne _0221C946
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, pc}
_0221C946:
	cmp r1, #6
	beq _0221C960
	cmp r1, #5
	beq _0221C960
	cmp r1, #7
	beq _0221C960
	cmp r1, #8
	beq _0221C960
	mov r1, #7
	str r1, [r4, r0]
	mov r1, #0xff
	sub r0, #0x3a
	strb r1, [r4, r0]
_0221C960:
	ldr r0, _0221CAA4 ; =0x00000B82
	ldrb r1, [r4, r0]
	cmp r1, #0
	beq _0221C972
	cmp r1, #1
	beq _0221C9B0
	cmp r1, #2
	beq _0221CA4A
	b _0221CA68
_0221C972:
	add r0, r4, #0
	bl ov05_0221E9C4
	ldr r2, _0221CAA8 ; =0x00000BAC
	mov r1, #8
	ldr r0, [r4, r2]
	add r2, #8
	ldr r2, [r4, r2]
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	ldr r2, _0221CAAC ; =0x00000B88
	str r3, [sp, #4]
	add r0, r4, r2
	str r3, [sp, #8]
	add r2, #0x2c
	ldr r2, [r4, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0221CAB0 ; =0x00000BB8
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov05_0221EA18
	ldr r0, _0221CAA4 ; =0x00000B82
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0221CA8C
_0221C9B0:
	add r2, r0, #2
	add r0, r0, #4
	ldr r1, [r4]
	add r2, r4, r2
	str r2, [sp]
	add r0, r4, r0
	str r0, [sp, #4]
	ldr r2, [r1]
	mov r0, #7
	add r1, #0x2c
	lsl r0, r0, #6
	ldr r0, [r2, r0]
	mov r2, #0
	ldrb r1, [r1]
	add r3, r2, #0
	bl sub_0202FE14
	cmp r0, #2
	bne _0221C9EC
	ldr r2, _0221CAA8 ; =0x00000BAC
	mov r1, #6
	ldr r0, [r4, r2]
	add r2, #8
	ldr r2, [r4, r2]
	bl ReadMsgDataIntoString
	ldr r0, _0221CAB4 ; =0x0000061A
	bl PlaySE
	b _0221C9FE
_0221C9EC:
	cmp r0, #3
	bne _0221CA8C
	ldr r2, _0221CAA8 ; =0x00000BAC
	mov r1, #7
	ldr r0, [r4, r2]
	add r2, #8
	ldr r2, [r4, r2]
	bl ReadMsgDataIntoString
_0221C9FE:
	add r0, r4, #0
	bl ov05_0221EA38
	mov r0, #0xd8
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, _0221CAAC ; =0x00000B88
	mov r2, #0
	add r0, r4, r0
	mov r1, #0xf
	add r3, r2, #0
	bl FillWindowPixelRect
	mov r3, #0
	str r3, [sp]
	ldr r2, _0221CAAC ; =0x00000B88
	str r3, [sp, #4]
	add r0, r4, r2
	str r3, [sp, #8]
	add r2, #0x2c
	ldr r2, [r4, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0221CAB0 ; =0x00000BB8
	mov r2, #0
	str r0, [r4, r1]
	add r0, r1, #0
	sub r0, #0x37
	strb r2, [r4, r0]
	add r0, r1, #0
	sub r0, #0x36
	ldrb r0, [r4, r0]
	sub r1, #0x36
	add r0, r0, #1
	strb r0, [r4, r1]
	b _0221CA8C
_0221CA4A:
	sub r1, r0, #1
	ldrb r1, [r4, r1]
	add r2, r1, #1
	sub r1, r0, #1
	strb r2, [r4, r1]
	ldrb r1, [r4, r1]
	cmp r1, #0x1e
	bls _0221CA8C
	mov r2, #0
	sub r1, r0, #1
	strb r2, [r4, r1]
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0221CA8C
_0221CA68:
	add r0, r0, #6
	add r0, r4, r0
	mov r1, #0
	bl ClearFrameAndWindow2
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _0221CAA4 ; =0x00000B82
	mov r1, #0
	strb r1, [r4, r0]
	mov r1, #0x15
	sub r0, r0, #1
	strb r1, [r4, r0]
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_0221CA8C:
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	nop
_0221CA9C: .word 0x00000B81
_0221CAA0: .word 0x00000BBC
_0221CAA4: .word 0x00000B82
_0221CAA8: .word 0x00000BAC
_0221CAAC: .word 0x00000B88
_0221CAB0: .word 0x00000BB8
_0221CAB4: .word 0x0000061A
	thumb_func_end ov05_0221C908


	thumb_func_start ov05_0221CAB8
ov05_0221CAB8: ; 0x0221CAB8
	push {r3, r4, lr}
	sub sp, #0xc
	ldr r1, _0221CB5C ; =0x00000B82
	add r4, r0, #0
	ldrb r1, [r4, r1]
	cmp r1, #0
	beq _0221CACC
	cmp r1, #1
	beq _0221CB34
	b _0221CB4A
_0221CACC:
	bl ov05_0221E9F8
	cmp r0, #0
	bne _0221CADC
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
_0221CADC:
	add r0, r4, #0
	bl ov05_0221E9C4
	ldr r2, _0221CB60 ; =0x00000BAC
	mov r1, #9
	ldr r0, [r4, r2]
	add r2, #8
	ldr r2, [r4, r2]
	bl ReadMsgDataIntoString
	mov r3, #0
	str r3, [sp]
	ldr r2, _0221CB64 ; =0x00000B88
	str r3, [sp, #4]
	add r0, r4, r2
	str r3, [sp, #8]
	add r2, #0x2c
	ldr r2, [r4, r2]
	mov r1, #1
	bl AddTextPrinterParameterized
	ldr r1, _0221CB68 ; =0x00000BB8
	str r0, [r4, r1]
	mov r0, #0x3e
	bl sub_02037AC0
	ldr r0, _0221CB6C ; =0x00000BC8
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0221CB2A
	add r0, r4, #0
	bl ov05_0221E9F8
	cmp r0, #1
	bne _0221CB2A
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
_0221CB2A:
	ldr r0, _0221CB5C ; =0x00000B82
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _0221CB4E
_0221CB34:
	mov r0, #0x3e
	bl sub_02037B38
	cmp r0, #0
	beq _0221CB4E
	ldr r0, _0221CB5C ; =0x00000B82
	mov r1, #0
	strb r1, [r4, r0]
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_0221CB4A:
	bl GF_AssertFail
_0221CB4E:
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_0221CB5C: .word 0x00000B82
_0221CB60: .word 0x00000BAC
_0221CB64: .word 0x00000B88
_0221CB68: .word 0x00000BB8
_0221CB6C: .word 0x00000BC8
	thumb_func_end ov05_0221CAB8


	thumb_func_start ov05_0221CB70
ov05_0221CB70: ; 0x0221CB70
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	bl ov05_0221CCF4
	cmp r0, #1
	ldr r0, [r4]
	bne _0221CBB2
	add r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #1
	bne _0221CB9E
	mov r0, #0x30
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r1, #0
	ldr r0, [r4, #8]
	mov r2, #0x40
	add r3, r1, #0
	bl PaletteData_CopyPalette
	b _0221CBE2
_0221CB9E:
	mov r1, #0
	str r1, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r2, #0x40
	add r3, r1, #0
	bl PaletteData_CopyPalette
	b _0221CBE2
_0221CBB2:
	add r0, #0x2a
	ldrb r0, [r0]
	cmp r0, #1
	bne _0221CBCE
	mov r1, #0
	str r1, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	ldr r0, [r4, #8]
	mov r2, #0x40
	add r3, r1, #0
	bl PaletteData_CopyPalette
	b _0221CBE2
_0221CBCE:
	mov r0, #0x30
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r1, #0
	ldr r0, [r4, #8]
	mov r2, #0x40
	add r3, r1, #0
	bl PaletteData_CopyPalette
_0221CBE2:
	ldr r0, [r4, #8]
	mov r1, #1
	bl PaletteData_SetSelectedBufferAll
	ldr r0, _0221CBFC ; =0x0000071B
	bl PlaySE
	ldr r0, _0221CC00 ; =0x00000B81
	mov r1, #0x40
	strb r1, [r4, r0]
	mov r0, #1
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
_0221CBFC: .word 0x0000071B
_0221CC00: .word 0x00000B81
	thumb_func_end ov05_0221CB70


	thumb_func_start ov05_0221CC04
ov05_0221CC04: ; 0x0221CC04
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0221CC50 ; =0x00000B82
	ldrb r0, [r4, r0]
	cmp r0, #0
	bne _0221CC16
	ldr r0, _0221CC54 ; =0x00000719
	bl PlaySE
_0221CC16:
	ldr r1, _0221CC50 ; =0x00000B82
	ldrb r0, [r4, r1]
	cmp r0, #0x10
	bne _0221CC2C
	mov r0, #0
	strb r0, [r4, r1]
	mov r2, #0x40
	sub r0, r1, #1
	strb r2, [r4, r0]
	mov r0, #1
	pop {r4, pc}
_0221CC2C:
	add r0, r0, #1
	strb r0, [r4, r1]
	ldrb r2, [r4, r1]
	mov r1, #0x10
	add r0, r4, #0
	sub r1, r1, r2
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	bl ov05_0221E564
	ldr r1, _0221CC50 ; =0x00000B82
	add r0, r4, #0
	ldrb r1, [r4, r1]
	bl ov05_0221DE6C
	mov r0, #0
	pop {r4, pc}
	nop
_0221CC50: .word 0x00000B82
_0221CC54: .word 0x00000719
	thumb_func_end ov05_0221CC04
