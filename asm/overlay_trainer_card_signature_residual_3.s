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

	thumb_func_start ov52_021E85DC
ov52_021E85DC: ; 0x021E85DC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r6, r0, #0
	ldr r4, [r6]
	mov r0, #0x60
	add r5, r1, #0
	mov r1, #0
	str r0, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, r1, #0
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0x40
	str r0, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #2
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r1, #0x1a
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x27
	bl LoadFontPal1
	mov r1, #0x1a
	mov r0, #4
	lsl r1, r1, #4
	mov r2, #0x27
	bl LoadFontPal1
	mov r0, #1
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x27
	bl BG_ClearCharDataRange
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x27
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #3
	add r2, r4, #0
	mov r3, #2
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x27
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #5
	add r2, r4, #0
	mov r3, #2
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x27
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #4
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x27
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #6
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	ldr r0, [r6, #0xc]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0
	mov r2, #1
	mov r3, #0xa
	bl LoadUserFrameGfx2
	mov r1, #0
	str r1, [sp]
	mov r0, #0x27
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0x1f
	mov r3, #0xb
	bl LoadUserFrameGfx1
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end ov52_021E85DC
