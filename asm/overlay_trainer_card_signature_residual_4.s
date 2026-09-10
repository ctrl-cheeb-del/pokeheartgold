#include "msgdata/msg/msg_0252.h"
	.include "asm/macros.inc"
	.include "overlay_trainer_card_signature.inc"
	.include "global.inc"

	.text
	.public TrainerCardSignature_Exit
	.public TrainerCardSignature_Init
	.public TrainerCardSignature_Main
	.public _021E94AC
	.public ov52_021E83C4
	.public ov52_021E84CC
	.public ov52_021E85DC
	.public ov52_021E870C
	.public ov52_021E888C
	.public ov52_021E8994
	.public ov52_021E89D4
	.public ov52_021E8BDC
	.public ov52_021E8DC4
	.public ov52_021E8E64
	.public ov52_021E8F2C
	.public ov52_021E8FAC
	.public ov52_021E9124
	.public ov52_021E9158
	.public ov52_021E9260
	.public ov52_021E927C
	.public ov52_021E9300
	.public ov52_021E9364
	.public ov52_021E94B2
	.public ov52_021E94BA
	.public ov52_021E94CC
	.public ov52_021E94DC
	.public ov52_021E94EC
	.public ov52_021E9508
	.public ov52_021E9524
	.public ov52_021E9540
	.public ov52_021E955C
	.public ov52_021E9578
	.public ov52_021E95A0
	.public ov52_021E96C0
	.public ov52_021E837C
	.public ov52_021E83A4
	.public ov52_021E8568
	.public ov52_021E85A0
	.public ov52_021E86DC
	.public ov52_021E8B94
	.public ov52_021E8BD8
	.public ov52_021E8CBC
	.public ov52_021E8CDC
	.public ov52_021E8CF4
	.public ov52_021E8D3C
	.public ov52_021E8D64
	.public ov52_021E8D8C
	.public ov52_021E8EDC
	.public ov52_021E8EFC
	.public ov52_021E9218
	.public ov52_021E921C
	.public ov52_021E925C
	.public ov52_021E92E8
	.public ov52_021E9424
	.public ov52_021E9488

	thumb_func_start ov52_021E870C
ov52_021E870C: ; 0x021E870C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r7, r1, #0
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x27
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	add r1, r5, #0
	mov r0, #0x32
	add r1, #0x40
	mov r2, #0x27
	bl G2dRenderer_Init
	str r0, [r5, #0x3c]
	add r0, r5, #0
	mov r2, #1
	add r0, #0x40
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	mov r6, #0
	add r4, r5, #0
_021E8750:
	mov r0, #2
	add r1, r6, #0
	mov r2, #0x27
	bl Create2DGfxResObjMan
	mov r1, #0x5a
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #4
	blt _021E8750
	mov r0, #0
	str r0, [sp]
	mov r3, #1
	str r3, [sp, #4]
	mov r0, #0x27
	str r0, [sp, #8]
	add r0, r1, #0
	ldr r0, [r5, r0]
	add r1, r7, #0
	mov r2, #7
	bl AddCharResObjFromOpenNarc
	mov r1, #0x5e
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #0
	str r3, [sp]
	mov r2, #1
	str r2, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x27
	sub r1, #0xc
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r7, #0
	bl AddPlttResObjFromOpenNarc
	mov r1, #0x5f
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0xc
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #8
	mov r3, #1
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #6
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0xc
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #9
	mov r3, #1
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #1
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #7
	bl AddCharResObjFromOpenNarc
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r2, #1
	str r2, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0x27
	sub r1, #0x1c
	str r0, [sp, #0xc]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r3, #0
	bl AddPlttResObjFromOpenNarc
	mov r1, #0x63
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r3, #1
	str r3, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #8
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [r5, r1]
	mov r3, #1
	str r3, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x27
	sub r1, #0x1c
	str r0, [sp, #8]
	ldr r0, [r5, r1]
	add r1, r7, #0
	mov r2, #9
	bl AddCellOrAnimResObjFromOpenNarc
	mov r1, #0x65
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #0x1c
	ldr r0, [r5, r1]
	bl SpriteTransfer_CreateCharTransferTask
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateCharTransferTask
	mov r0, #0x5f
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov52_021E870C


	thumb_func_start ov52_021E888C
ov52_021E888C: ; 0x021E888C
	push {r3, r4, lr}
	sub sp, #0x5c
	mov r1, #0
	add r4, r0, #0
	str r1, [sp]
	sub r0, r1, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r2, #0x5a
	str r1, [sp, #0x10]
	lsl r2, r2, #2
	ldr r0, [r4, r2]
	add r3, r1, #0
	str r0, [sp, #0x14]
	add r0, r2, #4
	ldr r0, [r4, r0]
	str r0, [sp, #0x18]
	add r0, r2, #0
	add r0, #8
	ldr r0, [r4, r0]
	str r0, [sp, #0x1c]
	add r0, r2, #0
	add r0, #0xc
	ldr r0, [r4, r0]
	add r2, #0x30
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, r4, r2
	add r2, r1, #0
	str r1, [sp, #0x28]
	bl CreateSpriteResourcesHeader
	mov r1, #1
	mov r3, #0x5a
	str r1, [sp]
	sub r0, r1, #2
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	lsl r3, r3, #2
	ldr r2, [r4, r3]
	str r2, [sp, #0x14]
	add r2, r3, #4
	ldr r2, [r4, r2]
	str r2, [sp, #0x18]
	add r2, r3, #0
	add r2, #8
	ldr r2, [r4, r2]
	str r2, [sp, #0x1c]
	add r2, r3, #0
	add r2, #0xc
	ldr r2, [r4, r2]
	add r3, #0x54
	str r2, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, r4, r3
	add r2, r1, #0
	add r3, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r0, [r4, #0x3c]
	mov r2, #0
	str r0, [sp, #0x2c]
	mov r0, #0x66
	lsl r0, r0, #2
	add r1, r4, r0
	str r1, [sp, #0x30]
	mov r1, #1
	lsl r1, r1, #0xc
	add r0, #0x24
	str r2, [sp, #0x3c]
	str r1, [sp, #0x40]
	str r1, [sp, #0x44]
	str r1, [sp, #0x48]
	add r1, sp, #0x2c
	strh r2, [r1, #0x20]
	mov r1, #1
	add r0, r4, r0
	str r0, [sp, #0x30]
	mov r0, #0xe
	lsl r0, r0, #0x10
	str r0, [sp, #0x34]
	mov r0, #0xaf
	lsl r0, r0, #0xc
	str r0, [sp, #0x38]
	str r1, [sp, #0x50]
	str r1, [sp, #0x54]
	mov r1, #0x27
	add r0, sp, #0x2c
	str r1, [sp, #0x58]
	bl Sprite_CreateAffine
	mov r1, #0x25
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetPaletteOverride
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #2
	bl Sprite_SetPriority
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add sp, #0x5c
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov52_021E888C


	thumb_func_start ov52_021E8994
ov52_021E8994: ; 0x021E8994
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r4, r2, #0
	mov r0, #2
	mov r2, #0
	add r6, r1, #0
	add r7, r3, #0
	bl FontID_String_GetWidth
	add r3, r0, #0
	str r4, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	add r1, r7, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldrb r4, [r5, #7]
	add r0, r5, #0
	add r2, r6, #0
	lsl r4, r4, #3
	sub r4, r4, r3
	lsr r3, r4, #0x1f
	add r3, r4, r3
	asr r3, r3, #1
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov52_021E8994


	thumb_func_start ov52_021E89D4
ov52_021E89D4: ; 0x021E89D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0x28
	mov r1, #0xb5
	str r0, [sp, #0x10]
	lsl r1, r1, #2
	ldr r0, [r5]
	add r1, r5, r1
	mov r2, #0
	mov r3, #2
	bl AddWindowParameterized
	mov r0, #0xb5
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r0, #9
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #8
	mov r1, #0xb1
	lsl r1, r1, #2
	str r0, [sp, #8]
	mov r2, #1
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r0, [r5]
	add r1, r5, r1
	mov r3, #4
	bl AddWindowParameterized
	mov r0, #0xb1
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #2
	bl FillWindowPixelBuffer
	mov r0, #0x15
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, #0xc1
	mov r1, #0xb9
	str r0, [sp, #0x10]
	lsl r1, r1, #2
	ldr r0, [r5]
	add r1, r5, r1
	mov r2, #1
	mov r3, #0x1a
	bl AddWindowParameterized
	mov r0, #0xb9
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, _021E8B84 ; =0x000E0702
	mov r2, #1
	str r0, [sp]
	mov r0, #0xb9
	lsl r0, r0, #2
	ldr r1, [r5, #0x2c]
	add r0, r5, r0
	mov r3, #2
	bl ov52_021E8994
	mov r1, #2
	lsl r1, r1, #8
	bl DC_FlushRange
	mov r4, #0
	ldr r0, _021E8B88 ; =0x00005B9C
	str r4, [sp, #0x18]
	add r7, r4, #0
	add r6, r5, r0
_021E8A8A:
	mov r0, #0
	str r0, [sp]
	mov r0, #0xb9
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #4
	mov r2, #2
	add r3, r4, #0
	str r6, [sp, #4]
	bl sub_02013A50
	mov r1, #1
	add r0, r6, #0
	lsl r1, r1, #8
	bl DC_FlushRange
	mov r2, #1
	add r0, r6, #0
	add r1, r7, #0
	lsl r2, r2, #8
	bl GX_LoadOBJ
	mov r0, #1
	lsl r0, r0, #8
	add r7, r7, r0
	ldr r0, [sp, #0x18]
	add r4, r4, #4
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #2
	blt _021E8A8A
	mov r3, #2
	str r3, [sp]
	mov r0, #0x1c
	str r0, [sp, #4]
	mov r1, #0xbd
	lsl r1, r1, #2
	str r3, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	mov r0, #0xd1
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r1, r5, r1
	mov r2, #1
	bl AddWindowParameterized
	ldr r1, [r5, #0x30]
	mov r0, #1
	mov r2, #0
	bl FontID_String_GetWidth
	add r4, r0, #0
	mov r0, #0xbd
	lsl r0, r0, #2
	add r0, r5, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	mov r3, #0xe0
	sub r4, r3, r4
	lsr r3, r4, #0x1f
	add r3, r4, r3
	ldr r0, _021E8B8C ; =0x00010200
	str r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r0, #0xbd
	lsl r0, r0, #2
	ldr r2, [r5, #0x30]
	add r0, r5, r0
	mov r1, #1
	asr r3, r3, #1
	bl AddTextPrinterParameterizedWithColor
	mov r0, #0
	str r0, [sp, #0x14]
	mov r0, #0x9d
	lsl r0, r0, #2
	mov r7, #1
	mov r6, #3
	add r4, r5, r0
_021E8B32:
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xd
	str r0, [sp, #0xc]
	lsl r0, r7, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r1, r4, #0
	mov r2, #4
	mov r3, #5
	bl AddWindowParameterized
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x14]
	add r7, #0x14
	add r0, r0, #1
	add r6, r6, #4
	add r4, #0x10
	str r0, [sp, #0x14]
	cmp r0, #5
	blt _021E8B32
	mov r0, #0x9d
	lsl r0, r0, #2
	ldr r2, _021E8B90 ; =0x000E0D0F
	add r0, r5, r0
	mov r1, #0
	add r3, r5, #0
	bl ov52_021E925C
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_021E8B84: .word 0x000E0702
_021E8B88: .word 0x00005B9C
_021E8B8C: .word 0x00010200
_021E8B90: .word 0x000E0D0F
	thumb_func_end ov52_021E89D4
