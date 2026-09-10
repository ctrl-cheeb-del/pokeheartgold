	.include "asm/macros.inc"
	.public _02260374
	.public ov115_0225F020
	.public ov115_0225F09C
	.public ov115_0225F0B4
	.public ov115_0225F158
	.public ov115_0225F1BC
	.public ov115_0225F220
	.public ov115_0225F704
	.public ov115_0225F728
	.public ov115_0225F74C
	.public ov115_0225F770
	.public ov115_0225F794
	.public ov115_0225F7B8
	.public ov115_0225F7DC
	.public ov115_0225F800
	.public ov115_0225F824
	.public ov115_0225F848
	.public ov115_0225F86C
	.public ov115_0225F890
	.public ov115_0225F8B4
	.public ov115_0225F8D8
	.public ov115_0225F8FC
	.public ov115_0225F920
	.public ov115_0225F944
	.public ov115_0225F968
	.public ov115_0225F978
	.public ov115_02260254
	.public ov115_022602C0
	.public ov115_022602E4
	.public ov115_02260308
	.public ov115_0226032C
	.public ov115_02260350
	.public ov115_02260388
	.public ov115_02260390
	.public ov115_02260398
	.public ov115_022603A0
	.public ov115_022603A8
	.public ov115_022603B0
	.public ov115_022603C4
	.public ov115_022603D8
	.public ov115_022603EC
	.public ov115_02260400
	.public ov115_02260414
	.public ov115_02260428
	.public ov115_0226043C
	.public ov115_02260450
	.public ov115_02260464
	.public ov115_02260478
	.public ov115_0226048C
	.public ov115_022604A0
	.public ov115_022604B4
	.public ov115_022604C8
	.public ov115_022604DC
	.include "overlay_115.inc"
	.include "global.inc"

	.text
	.public ov115_0225F09C
	.public ov115_0225F158
	.public ov115_0225F1BC
	.public ov115_0225F704
	.public ov115_0225F728
	.public ov115_0225F74C
	.public ov115_0225F770
	.public ov115_0225F794
	.public ov115_0225F7B8
	.public ov115_0225F7DC
	.public ov115_0225F800
	.public ov115_0225F824
	.public ov115_0225F848
	.public ov115_0225F86C
	.public ov115_0225F890
	.public ov115_0225F8B4
	.public ov115_0225F8D8
	.public ov115_0225F8FC
	.public ov115_0225F920
	.public ov115_0225F944
	.public ov115_0225F968
	.public ov115_022602C0
	.public ov115_022602E4
	.public ov115_02260308
	.public ov115_0226032C
	.public ov115_02260350

	thumb_func_start ov115_0225F978
ov115_0225F978: ; 0x0225F978
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	add r6, r0, #0
	ldr r0, [r6]
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r4, [r6, #0xc]
	cmp r0, #0xe
	bls _0225F98E
	bl _0226021C
_0225F98E:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225F99A: ; jump table
	.short _0225F9B8 - _0225F99A - 2 ; case 0
	.short _0225FAC6 - _0225F99A - 2 ; case 1
	.short _0225FBAE - _0225F99A - 2 ; case 2
	.short _0225FBC8 - _0225F99A - 2 ; case 3
	.short _0225FBE4 - _0225F99A - 2 ; case 4
	.short _0225FC0E - _0225F99A - 2 ; case 5
	.short _0225FD78 - _0225F99A - 2 ; case 6
	.short _0225FE4E - _0225F99A - 2 ; case 7
	.short _0225FE80 - _0225F99A - 2 ; case 8
	.short _0225FF02 - _0225F99A - 2 ; case 9
	.short _0225FF26 - _0225F99A - 2 ; case 10
	.short _0225FF4A - _0225F99A - 2 ; case 11
	.short _0225FF88 - _0225F99A - 2 ; case 12
	.short _02260102 - _0225F99A - 2 ; case 13
	.short _022601A8 - _0225F99A - 2 ; case 14
_0225F9B8:
	add r0, r1, #0
	mov r1, #0xc5
	lsl r1, r1, #2
	bl Heap_Alloc
	mov r2, #0xc5
	str r0, [r6, #0xc]
	mov r1, #0
	lsl r2, r2, #2
	bl memset
	ldr r4, [r6, #0xc]
	mov r1, #0xa
	add r0, r4, #0
	add r0, #0x5c
	mov r2, #4
	bl ov01_021F05C4
	ldr r0, [r6, #0x10]
	bl ov115_0225F968
	cmp r0, #0
	bne _0225FA16
	mov r0, #1
	str r0, [sp]
	mov r0, #0xd0
	str r0, [sp, #4]
	mov r0, #0xd1
	str r0, [sp, #8]
	mov r2, #0xd2
	str r2, [sp, #0xc]
	ldr r0, _0225FD58 ; =0x000927C0
	add r1, r4, #0
	str r0, [sp, #0x10]
	add r2, #0xc6
	ldr r0, [r6, #0x20]
	add r1, #0x5c
	add r2, r4, r2
	mov r3, #0xcf
	bl ov01_021F0614
	mov r0, #0xc1
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r1, #0xcf
	b _0225FA44
_0225FA16:
	mov r0, #1
	str r0, [sp]
	mov r0, #0xd4
	str r0, [sp, #4]
	mov r0, #0xd5
	str r0, [sp, #8]
	mov r2, #0xd6
	str r2, [sp, #0xc]
	ldr r0, _0225FD58 ; =0x000927C0
	add r1, r4, #0
	str r0, [sp, #0x10]
	add r2, #0xc2
	ldr r0, [r6, #0x20]
	add r1, #0x5c
	add r2, r4, r2
	mov r3, #0xd3
	bl ov01_021F0614
	mov r0, #0xc1
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r1, #0xd3
_0225FA44:
	add r0, r0, #4
	str r1, [r4, r0]
	ldr r0, [sp, #0x18]
	mov r2, #0x73
	ldrh r3, [r0]
	mov r0, #1
	add r1, r4, #0
	str r0, [sp]
	add r0, r3, #1
	str r0, [sp, #4]
	add r0, r3, #2
	str r0, [sp, #8]
	add r0, r3, #3
	str r0, [sp, #0xc]
	ldr r0, _0225FD5C ; =0x000927C1
	lsl r2, r2, #2
	str r0, [sp, #0x10]
	ldr r0, [r6, #0x20]
	add r1, #0x5c
	add r2, r4, r2
	bl ov01_021F0614
	mov r0, #0xc
	str r0, [sp]
	mov r0, #0x30
	str r0, [sp, #4]
	mov r0, #0x31
	str r0, [sp, #8]
	mov r0, #0x32
	str r0, [sp, #0xc]
	ldr r0, _0225FD60 ; =0x000927C2
	mov r2, #2
	str r0, [sp, #0x10]
	ldr r3, [sp, #0x18]
	add r1, r4, #0
	lsl r2, r2, #8
	ldrb r3, [r3, #2]
	ldr r0, [r6, #0x20]
	add r1, #0x5c
	add r2, r4, r2
	bl ov01_021F0614
	mov r0, #1
	str r0, [sp]
	mov r0, #0x3c
	str r0, [sp, #4]
	mov r0, #0x3d
	str r0, [sp, #8]
	mov r0, #0x3e
	str r0, [sp, #0xc]
	ldr r0, _0225FD64 ; =0x000927C3
	mov r2, #0x8d
	str r0, [sp, #0x10]
	add r1, r4, #0
	lsl r2, r2, #2
	ldr r0, [r6, #0x20]
	add r1, #0x5c
	add r2, r4, r2
	mov r3, #0x3b
	bl ov01_021F0614
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FAC6:
	mov r1, #2
	lsl r1, r1, #0xc
	add r0, sp, #0x2c
	add r2, r1, #0
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x66
	lsl r0, r0, #2
	add r0, r4, r0
	str r0, [sp, #0x1c]
	str r0, [sp, #0x24]
	add r0, r4, #0
	str r0, [sp, #0x28]
	add r0, #0x5c
	mov r7, #0
	add r5, r4, #0
	str r0, [sp, #0x28]
_0225FAEA:
	cmp r7, #3
	bge _0225FAF6
	mov r0, #0
	ldr r1, [sp, #0x1c]
	str r0, [sp, #0x20]
	b _0225FB06
_0225FAF6:
	sub r1, r7, #1
	mov r0, #0x34
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #0x24]
	add r1, r0, r2
	mov r0, #1
	str r0, [sp, #0x20]
_0225FB06:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r2, #0
	ldr r0, [sp, #0x28]
	add r3, r2, #0
	bl ov01_021F0718
	mov r1, #0x9a
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [sp, #0x20]
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetPriority
	ldr r0, [sp, #0x1c]
	add r7, r7, #1
	add r0, #0x34
	add r5, r5, #4
	str r0, [sp, #0x1c]
	cmp r7, #4
	blt _0225FAEA
	mov r2, #0x9a
	mov r0, #0
	lsl r2, r2, #2
	str r0, [sp]
	ldr r0, [r4, r2]
	add r2, #0xa0
	ldr r1, [sp, #0x14]
	ldr r2, [r4, r2]
	mov r3, #0xe
	bl ov115_02260254
	mov r0, #0
	str r0, [sp]
	ldr r2, [sp, #0x18]
	mov r0, #0x9b
	lsl r0, r0, #2
	ldrh r2, [r2]
	ldr r0, [r4, r0]
	ldr r1, [sp, #0x14]
	mov r3, #0xe
	bl ov115_02260254
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #6
	lsl r0, r0, #0x10
	str r0, [sp]
	ldr r0, [sp, #0x14]
	mov r2, #0x29
	add r1, r4, #0
	mov r3, #2
	lsl r2, r2, #4
	str r0, [sp, #4]
	add r0, r4, r2
	sub r2, #0x5c
	add r1, #0x5c
	add r2, r4, r2
	lsl r3, r3, #0x12
	bl ov115_0225F020
	ldr r0, [r6, #0x10]
	bl ov01_021F0DDC
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FBAE:
	mov r1, #0x10
	mov r0, #1
	add r2, r1, #0
	add r3, r6, #4
	str r0, [sp]
	bl ov01_021EFCF8
	mov r0, #0
	str r0, [r6, #8]
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FBC8:
	ldr r0, [r6, #8]
	add r0, r0, #1
	str r0, [r6, #8]
	cmp r0, #8
	bne _0225FBD6
	bl ov01_021F0E74
_0225FBD6:
	ldr r0, [r6, #4]
	cmp r0, #0
	beq _0225FBEC
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FBE4:
	bl ov01_021F0E90
	cmp r0, #1
	beq _0225FBEE
_0225FBEC:
	b _0226021C
_0225FBEE:
	ldr r0, [r6, #0x20]
	mov r1, #0x97
	bl ov01_021F0F08
	mov r0, #8
	str r0, [sp]
	ldr r0, _0225FD68 ; =0x04000050
	mov r1, #1
	mov r2, #0x1e
	mov r3, #0
	bl G2x_SetBlendAlpha_
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FC0E:
	mov r0, #6
	mov r2, #0xe
	mov r3, #5
	str r0, [sp]
	ldr r1, _0225FD6C ; =0xFFF80000
	add r0, r4, #0
	lsl r2, r2, #0xe
	lsl r3, r3, #0x10
	bl ov01_021EFEC8
	mov r2, #0x17
	ldr r1, [r4]
	add r0, sp, #0x38
	lsl r2, r2, #0xe
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xe
	add r1, r1, r0
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x38]
	lsl r0, r0, #2
	add r0, r1, r0
	str r0, [sp, #0x38]
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r1, #6
	add r0, r4, #0
	mov r2, #0x32
	str r1, [sp]
	ldr r3, _0225FD70 ; =0xFFFB0000
	add r0, #0x30
	lsl r1, r1, #0x12
	lsl r2, r2, #0xe
	bl ov01_021EFEC8
	mov r2, #0x17
	ldr r1, [r4, #0x30]
	add r0, sp, #0x38
	lsl r2, r2, #0xe
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x9b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xe
	add r1, r1, r0
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x38]
	lsl r0, r0, #2
	sub r0, r1, r0
	str r0, [sp, #0x38]
	mov r0, #0x9d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #0x9b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x9d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [sp, #0x14]
	mov r1, #0x10
	str r0, [sp, #4]
	ldr r0, [r6, #0x20]
	mov r2, #0
	mov r3, #0x40
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0xd
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	mov r2, #2
	str r2, [sp, #8]
	mov r1, #0xbd
	lsl r1, r1, #2
	str r2, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, [r6, #0x10]
	add r1, r4, r1
	ldr r0, [r0, #8]
	mov r3, #0x15
	bl AddWindowParameterized
	mov r0, #0xbd
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x14]
	ldrh r0, [r0, #6]
	bl ov115_0225F158
	mov r1, #0
	add r5, r0, #0
	str r1, [sp]
	ldr r0, _0225FD74 ; =0x00010200
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0xbd
	lsl r0, r0, #2
	add r0, r4, r0
	add r2, r5, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl String_Delete
	mov r0, #3
	str r0, [r6, #4]
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
	.balign 4, 0
_0225FD58: .word 0x000927C0
_0225FD5C: .word 0x000927C1
_0225FD60: .word 0x000927C2
_0225FD64: .word 0x000927C3
_0225FD68: .word 0x04000050
_0225FD6C: .word 0xFFF80000
_0225FD70: .word 0xFFFB0000
_0225FD74: .word 0x00010200
_0225FD78:
	ldr r0, [r6, #4]
	cmp r0, #0
	ble _0225FD9C
	sub r0, r0, #1
	str r0, [r6, #4]
	bne _0225FDA6
	mov r0, #3
	bl ov01_021F0FB8
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	b _0225FDA6
_0225FD9C:
	mov r0, #0x29
	lsl r0, r0, #4
	add r0, r4, r0
	bl ov115_0225F0B4
_0225FDA6:
	add r0, r4, #0
	bl ov01_021EFF28
	mov r2, #0x17
	ldr r1, [r4]
	add r0, sp, #0x38
	lsl r2, r2, #0xe
	mov r3, #0
	bl ov01_021F074C
	add r5, sp, #0x38
	mov r2, #0x9e
	lsl r2, r2, #2
	add r3, r4, r2
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	sub r2, #0x10
	str r0, [r3]
	ldr r0, [r4, r2]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xe
	add r1, r1, r0
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x38]
	lsl r0, r0, #2
	add r0, r1, r0
	str r0, [sp, #0x38]
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	add r0, r4, #0
	add r0, #0x30
	bl ov01_021EFF28
	mov r2, #0x17
	add r7, r0, #0
	ldr r1, [r4, #0x30]
	add r0, sp, #0x38
	lsl r2, r2, #0xe
	mov r3, #0
	bl ov01_021F074C
	add r5, sp, #0x38
	mov r2, #0xa1
	lsl r2, r2, #2
	add r3, r4, r2
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	sub r2, #0x18
	str r0, [r3]
	ldr r0, [r4, r2]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xe
	add r1, r1, r0
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x38]
	lsl r0, r0, #2
	sub r0, r1, r0
	str r0, [sp, #0x38]
	mov r0, #0x9d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	cmp r7, #1
	bne _0225FF3C
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FE4E:
	mov r0, #0x29
	lsl r0, r0, #4
	add r0, r4, r0
	bl ov115_0225F0B4
	add r5, r0, #0
	bl ov01_021F1044
	cmp r5, #0
	beq _0225FF3C
	cmp r0, #0
	beq _0225FF3C
	add r0, r4, #0
	add r0, #0x48
	mov r1, #0
	mov r2, #0x10
	mov r3, #3
	bl ov01_021EFE34
	bl ov01_021F1060
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FE80:
	add r0, r4, #0
	add r0, #0x48
	bl ov01_021EFE44
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0x48
	bl ov01_021F0DC8
	cmp r5, #1
	bne _0225FF3C
	mov r3, #0
	mov r2, #0x9a
	str r3, [sp]
	lsl r2, r2, #2
	ldr r0, [r4, r2]
	add r2, #0xa0
	ldr r1, [sp, #0x14]
	ldr r2, [r4, r2]
	bl ov115_02260254
	mov r3, #0
	mov r0, #0x9b
	ldr r2, [sp, #0x18]
	str r3, [sp]
	lsl r0, r0, #2
	ldrh r2, [r2]
	ldr r0, [r4, r0]
	ldr r1, [sp, #0x14]
	bl ov115_02260254
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x27
	lsl r0, r0, #4
	mov r1, #2
	ldr r0, [r4, r0]
	lsl r1, r1, #0xc
	bl Sprite_SetAnimSpeed
	mov r0, #0x9d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x9d
	lsl r0, r0, #2
	mov r1, #2
	ldr r0, [r4, r0]
	lsl r1, r1, #0xc
	bl Sprite_SetAnimSpeed
	ldr r0, [r6, #0x20]
	mov r1, #0x98
	bl ov01_021F0F08
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FF02:
	add r0, r4, #0
	add r0, #0x48
	mov r1, #0x10
	mov r2, #0
	mov r3, #6
	bl ov01_021EFE34
	mov r0, #4
	bl ov01_021F0FB8
	mov r0, #0
	mov r1, #1
	bl SetBgPriority
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FF26:
	add r0, r4, #0
	add r0, #0x48
	bl ov01_021EFE44
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0x48
	bl ov01_021F0DC8
	cmp r5, #1
	beq _0225FF3E
_0225FF3C:
	b _0226021C
_0225FF3E:
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	mov r0, #8
	str r0, [r6, #4]
	b _0226021C
_0225FF4A:
	ldr r0, [r6, #4]
	cmp r0, #0
	ble _0225FF56
	sub r0, r0, #1
	str r0, [r6, #4]
	b _0226021C
_0225FF56:
	add r0, r2, #0
	ldrb r0, [r0, #3]
	mov r1, #0
	ldr r2, _02260248 ; =0xFFFFE000
	str r0, [sp]
	add r0, r4, #0
	add r3, r1, #0
	bl ov01_021EFEC8
	ldr r0, [sp, #0x18]
	mov r1, #0
	ldrb r0, [r0, #3]
	ldr r2, _02260248 ; =0xFFFFE000
	add r3, r1, #0
	str r0, [sp]
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021EFEC8
	mov r0, #0
	str r0, [r6, #4]
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_0225FF88:
	ldr r0, [r6, #4]
	add r0, r0, #1
	str r0, [r6, #4]
	add r0, r4, #0
	bl ov01_021EFF28
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021EFF28
	ldr r1, [r6, #4]
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	add r0, sp, #0x38
	bne _0225FFD0
	mov r2, #0x9e
	lsl r2, r2, #2
	ldr r3, [r4, r2]
	ldr r1, [r4]
	add r2, r2, #4
	add r1, r3, r1
	ldr r3, [r4, r2]
	ldr r2, [r4, #0x18]
	add r2, r3, r2
	mov r3, #0
	bl ov01_021F074C
	b _0225FFE8
_0225FFD0:
	mov r2, #0x9e
	lsl r2, r2, #2
	ldr r3, [r4, r2]
	ldr r1, [r4]
	add r2, r2, #4
	sub r1, r3, r1
	ldr r3, [r4, r2]
	ldr r2, [r4, #0x18]
	sub r2, r3, r2
	mov r3, #0
	bl ov01_021F074C
_0225FFE8:
	cmp r5, #0
	beq _0225FFFC
	mov r0, #0x9e
	lsl r0, r0, #2
	add r3, sp, #0x38
	add r2, r4, r0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
_0225FFFC:
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xe
	add r1, r1, r0
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x38]
	lsl r0, r0, #2
	add r0, r1, r0
	str r0, [sp, #0x38]
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	ldr r1, [r6, #4]
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	add r0, sp, #0x38
	bne _02260058
	mov r2, #0xa1
	lsl r2, r2, #2
	ldr r3, [r4, r2]
	ldr r1, [r4]
	add r2, r2, #4
	sub r1, r3, r1
	ldr r3, [r4, r2]
	ldr r2, [r4, #0x18]
	sub r2, r3, r2
	mov r3, #0
	bl ov01_021F074C
	b _02260070
_02260058:
	mov r2, #0xa1
	lsl r2, r2, #2
	ldr r3, [r4, r2]
	ldr r1, [r4]
	add r2, r2, #4
	add r1, r3, r1
	ldr r3, [r4, r2]
	ldr r2, [r4, #0x18]
	add r2, r3, r2
	mov r3, #0
	bl ov01_021F074C
_02260070:
	cmp r5, #0
	beq _02260084
	mov r0, #0xa1
	lsl r0, r0, #2
	add r3, sp, #0x38
	add r2, r4, r0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
_02260084:
	mov r0, #0x9b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xe
	add r1, r1, r0
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x38]
	lsl r0, r0, #2
	sub r0, r1, r0
	str r0, [sp, #0x38]
	mov r0, #0x9d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	cmp r5, #0
	bne _022600B4
	b _0226021C
_022600B4:
	ldr r0, [r6]
	mov r1, #0
	add r0, r0, #1
	str r0, [r6]
	mov r0, #4
	bl GfGfx_EngineATogglePlanes
	mov r2, #3
	mov r0, #0x10
	lsl r2, r2, #0x12
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0
	lsr r3, r2, #3
	bl ov01_021EFEC8
	mov r0, #0x10
	mov r2, #3
	str r0, [sp]
	add r0, r4, #0
	lsl r2, r2, #0x12
	add r0, #0x18
	mov r1, #0
	lsr r3, r2, #3
	bl ov01_021EFEC8
	mov r0, #8
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	mov r1, #0
	str r0, [sp, #8]
	ldr r3, _0226024C ; =0x00007FFF
	mov r0, #3
	add r2, r1, #0
	bl BeginNormalPaletteFade
	b _0226021C
_02260102:
	add r0, r4, #0
	bl ov01_021EFF28
	add r0, r4, #0
	add r0, #0x18
	bl ov01_021EFF28
	mov r2, #0x9e
	lsl r2, r2, #2
	ldr r3, [r4, r2]
	ldr r1, [r4]
	add r2, r2, #4
	sub r1, r3, r1
	ldr r3, [r4, r2]
	ldr r2, [r4, #0x18]
	add r0, sp, #0x38
	sub r2, r3, r2
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x9a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xe
	add r1, r1, r0
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x38]
	lsl r0, r0, #2
	add r0, r1, r0
	str r0, [sp, #0x38]
	mov r0, #0x27
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r2, #0xa1
	lsl r2, r2, #2
	ldr r3, [r4, r2]
	ldr r1, [r4]
	add r2, r2, #4
	add r1, r3, r1
	ldr r3, [r4, r2]
	ldr r2, [r4, #0x18]
	add r0, sp, #0x38
	add r2, r3, r2
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x9b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #1
	ldr r1, [sp, #0x3c]
	lsl r0, r0, #0xe
	add r1, r1, r0
	str r1, [sp, #0x3c]
	ldr r1, [sp, #0x38]
	lsl r0, r0, #2
	sub r0, r1, r0
	str r0, [sp, #0x38]
	mov r0, #0x9d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0226021C
	ldr r0, [r6]
	add r0, r0, #1
	str r0, [r6]
	b _0226021C
_022601A8:
	ldr r1, _0226024C ; =0x00007FFF
	mov r0, #1
	bl sub_0200FBF4
	ldr r1, [r6, #0x14]
	cmp r1, #0
	beq _022601BA
	mov r0, #1
	str r0, [r1]
_022601BA:
	mov r0, #0x29
	lsl r0, r0, #4
	add r0, r4, r0
	bl ov115_0225F09C
	mov r0, #0xbd
	lsl r0, r0, #2
	add r0, r4, r0
	bl RemoveWindow
	mov r7, #0x9a
	mov r6, #0
	add r5, r4, #0
	lsl r7, r7, #2
_022601D6:
	ldr r0, [r5, r7]
	bl Sprite_Delete
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #4
	blt _022601D6
	mov r0, #0x66
	lsl r0, r0, #2
	add r7, r4, #0
	mov r6, #0
	add r5, r4, r0
	add r7, #0x5c
_022601F0:
	add r0, r7, #0
	add r1, r5, #0
	bl ov01_021F06EC
	add r6, r6, #1
	add r5, #0x34
	cmp r6, #4
	blt _022601F0
	add r4, #0x5c
	add r0, r4, #0
	bl ov01_021F05F4
	bl ov01_021F1060
	bl ov01_021F0EC0
	ldr r0, _02260250 ; =0x04000050
	mov r1, #0
	strh r1, [r0]
	add sp, #0x44
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0226021C:
	ldr r0, [r6]
	cmp r0, #0xe
	beq _02260242
	ldr r0, [r4, #0x5c]
	bl SpriteList_RenderAndAnimateSprites
	ldr r0, [r6]
	cmp r0, #4
	ble _02260242
	bl Thunk_G3X_Reset
	bl ov01_021F1008
	bl ov01_021F0EAC
	mov r0, #0
	add r1, r0, #0
	bl RequestSwap3DBuffers
_02260242:
	mov r0, #0
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02260248: .word 0xFFFFE000
_0226024C: .word 0x00007FFF
_02260250: .word 0x04000050
	thumb_func_end ov115_0225F978


	thumb_func_start ov115_02260254
ov115_02260254: ; 0x02260254
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r1, #0
	add r7, r0, #0
	add r6, r2, #0
	add r0, r5, #0
	mov r1, #0x20
	str r3, [sp, #4]
	bl Heap_Alloc
	add r4, r0, #0
	mov r0, #0x6d
	add r1, r6, #0
	add r2, sp, #8
	add r3, r5, #0
	bl GfGfxLoader_GetPlttData
	add r5, r0, #0
	add r0, sp, #0x10
	ldrh r0, [r0, #0x10]
	add r1, r4, #0
	mov r2, #0x10
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r3, [sp, #4]
	ldr r0, [r0, #0xc]
	bl BlendPalette
	add r0, r7, #0
	bl Sprite_GetPaletteProxy
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #0x20
	bl DC_FlushRange
	add r0, r6, #0
	mov r1, #1
	bl NNS_G2dGetImagePaletteLocation
	add r1, r0, #0
	add r0, r4, #0
	mov r2, #0x20
	bl GX_LoadOBJPltt
	add r0, r4, #0
	bl Heap_Free
	add r0, r5, #0
	bl Heap_Free
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov115_02260254
