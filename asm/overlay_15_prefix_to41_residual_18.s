#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FD404
	.public ov15_021FD43C
	.public ov15_021FD574
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021FA098
	.extern ov15_021FB680
	.extern ov15_021FBC6C
	.extern ov15_021FBC8C
	.extern ov15_021FBCAC
	.extern ov15_021FC224
	.extern ov15_021FC37C
	.extern ov15_021FC3E0
	.extern ov15_021FC3EC
	.extern ov15_021FD3C0
	.extern ov15_021FD3F0
	.extern ov15_021FE17C
	.extern ov15_021FE1D0
	.extern ov15_021FE204
	.extern ov15_021FE3E0
	.extern ov15_021FE584
	.extern ov15_021FE5A4
	.extern ov15_021FE5C4
	.extern ov15_021FE620

	.public Bag_Exit
	.public Bag_Init
	.public Bag_Main
	.public ov15_021F9C78
	.public ov15_021FB680
	.public ov15_021FBC6C
	.public ov15_021FBC8C
	.public ov15_021FBCAC
	.public ov15_021FC224
	.public ov15_021FC37C
	.public ov15_021FC3E0
	.public ov15_021FC3EC
	.public ov15_021FD3C0
	.public ov15_021FD3F0
	.public ov15_021FE17C
	.public ov15_021FE1D0
	.public ov15_021FE204
	.public ov15_021FE3E0
	.public ov15_021FE584
	.public ov15_021FE5A4
	.public ov15_021FE5C4
	.public ov15_021FE620
	.extern _022004EC
	.extern _02201300
	.extern _02201480
	.extern ov15_021FEA5C
	.extern ov15_021FEB64
	.extern ov15_021FEB84
	.extern ov15_021FECA0
	.extern ov15_021FECC4
	.extern ov15_021FECD8
	.extern ov15_021FED24
	.extern ov15_021FED3C
	.extern ov15_021FED58
	.extern ov15_021FED60
	.extern ov15_021FEDEC
	.extern ov15_021FEEA4
	.extern ov15_021FEF48
	.extern ov15_021FF004
	.extern ov15_021FF058
	.extern ov15_021FF068
	.extern ov15_021FF0FC
	.extern ov15_021FF1E0
	.extern ov15_021FF29C
	.extern ov15_021FF364
	.extern ov15_021FF4EC
	.extern ov15_021FF560
	.extern ov15_021FF6BC
	.extern ov15_021FF758
	.extern ov15_021FF7AC
	.extern ov15_021FF7C4
	.extern ov15_021FF7FC
	.extern ov15_021FF834
	.extern ov15_021FF844
	.extern ov15_021FF850
	.extern ov15_021FF894
	.extern ov15_021FF8D4
	.extern ov15_021FF950
	.extern ov15_021FF964
	.extern ov15_021FFECC
	.extern ov15_021FFF24
	.extern ov15_021FFF34
	.extern ov15_021FFFDC
	.extern ov15_02200030
	.extern ov15_0220005C
	.extern ov15_02200140
	.extern ov15_022001C4
	.extern ov15_0220023C
	.extern ov15_02200294
	.extern ov15_022002B4
	.extern ov15_022002EC
	.extern ov15_02200300
	.extern ov15_02200428
	.extern ov15_02200458
	.extern ov15_022004DC
	.extern ov15_022004F4
	.extern ov15_02200500
	.extern ov15_0220050C
	.extern ov15_02200518
	.extern ov15_02200528
	.extern ov15_02200529
	.extern ov15_0220052A
	.extern ov15_0220052B
	.extern ov15_0220053C
	.extern ov15_02200584
	.extern ov15_02200585
	.extern ov15_02200586
	.extern ov15_02200587
	.extern ov15_022005CC
	.extern ov15_02200618
	.extern ov15_02200640
	.extern ov15_02200641
	.extern ov15_02200642
	.extern ov15_02200643
	.extern ov15_022006CC
	.extern ov15_022006E8
	.extern ov15_02200704
	.extern ov15_02200720
	.extern ov15_0220073C
	.extern ov15_02200758
	.extern ov15_02200774
	.extern ov15_02200790
	.extern ov15_022008B0
	.extern ov15_022008D0
	.extern ov15_022008E8
	.extern ov15_02200908
	.extern ov15_02201304
	.extern ov15_02201314
	.extern ov15_02201328
	.extern ov15_02201340
	.extern ov15_02201368
	.extern ov15_022013A8
	.extern ov15_02201468

	thumb_func_start ov15_021FD404
ov15_021FD404: ; 0x021FD404
	push {r3, r4, r5, lr}
	lsl r1, r1, #2
	add r1, r0, r1
	ldr r0, _021FD438 ; =0x00000694
	cmp r2, #7
	ldr r0, [r1, r0]
	ldr r5, [r0, #0xc]
	bgt _021FD434
	lsl r4, r2, #5
	add r0, r5, r4
	mov r1, #0
	mov r2, #0x20
	bl GXS_LoadBGPltt
	add r0, r5, r4
	mov r1, #0x20
	mov r2, #0x40
	bl GXS_LoadBGPltt
	add r0, r5, r4
	mov r1, #0x60
	mov r2, #0x20
	bl GXS_LoadBGPltt
_021FD434:
	pop {r3, r4, r5, pc}
	nop
_021FD438: .word 0x00000694
	thumb_func_end ov15_021FD404


	thumb_func_start ov15_021FD43C
ov15_021FD43C: ; 0x021FD43C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r1, [sp, #0x10]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r6, r0, #0
	add r4, r2, #0
	bl GetBgTilemapBuffer
	str r0, [sp, #0x14]
	cmp r4, #6
	beq _021FD4B6
	ldr r1, _021FD4BC ; =ov15_022013A8
	lsl r0, r4, #5
	add r5, r1, r0
	ldr r0, [sp, #0x10]
	mov r7, #0
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
_021FD462:
	ldrb r0, [r5]
	cmp r0, #1
	bne _021FD48E
	ldrb r0, [r5, #4]
	add r1, r4, #0
	str r0, [sp]
	ldrb r0, [r5, #5]
	str r0, [sp, #4]
	ldrb r0, [r5, #6]
	str r0, [sp, #8]
	ldrb r3, [r5, #2]
	ldrb r2, [r5, #1]
	add r0, r6, #0
	lsl r3, r3, #5
	add r2, r2, r3
	lsl r3, r2, #1
	ldr r2, [sp, #0x14]
	add r2, r2, r3
	ldrb r3, [r5, #3]
	bl LoadRectToBgTilemapRect
	b _021FD4AE
_021FD48E:
	cmp r0, #2
	bne _021FD4AE
	ldrb r0, [r5, #4]
	add r1, r4, #0
	mov r2, #0
	str r0, [sp]
	ldrb r0, [r5, #5]
	str r0, [sp, #4]
	ldrb r0, [r5, #6]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldrb r3, [r5, #3]
	add r0, r6, #0
	bl FillBgTilemapRect
_021FD4AE:
	add r7, r7, #1
	add r5, #8
	cmp r7, #4
	blt _021FD462
_021FD4B6:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FD4BC: .word ov15_022013A8
	thumb_func_end ov15_021FD43C


	thumb_func_start ov15_021FD4C0
ov15_021FD4C0: ; 0x021FD4C0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r1, [sp, #0x10]
	lsl r1, r1, #0x18
	add r5, r2, #0
	lsr r1, r1, #0x18
	add r6, r0, #0
	str r3, [sp, #0x14]
	bl GetBgTilemapBuffer
	str r0, [sp, #0x18]
	sub r0, r5, #1
	ldr r1, _021FD56C ; =ov15_02201340
	lsl r0, r0, #3
	add r5, r1, r0
	ldr r0, [sp, #0x10]
	mov r4, #0
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
_021FD4E6:
	ldrb r0, [r5, #1]
	add r1, r7, #0
	mov r2, #0
	str r0, [sp]
	ldrb r0, [r5, #2]
	str r0, [sp, #4]
	ldrb r0, [r5, #3]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldrb r3, [r5]
	add r0, r6, #0
	bl FillBgTilemapRect
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #2
	blt _021FD4E6
	mov r1, #0
	ldr r0, [sp, #0x14]
	mvn r1, r1
	cmp r0, r1
	beq _021FD566
	ldr r1, _021FD570 ; =ov15_02201328
	lsl r0, r0, #2
	add r3, r1, r0
	ldr r0, [sp, #0x14]
	cmp r0, #1
	ldrb r0, [r3, #1]
	bhi _021FD546
	str r0, [sp]
	ldrb r0, [r3, #2]
	ldr r1, [sp, #0x10]
	mov r4, #6
	str r0, [sp, #4]
	ldrb r0, [r3, #3]
	lsl r1, r1, #0x18
	ldr r2, [sp, #0x18]
	str r0, [sp, #8]
	lsl r4, r4, #8
	ldrb r3, [r3]
	add r0, r6, #0
	lsr r1, r1, #0x18
	add r2, r2, r4
	bl LoadRectToBgTilemapRect
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
_021FD546:
	str r0, [sp]
	ldrb r0, [r3, #2]
	ldr r1, [sp, #0x10]
	mov r4, #0x1b
	str r0, [sp, #4]
	ldrb r0, [r3, #3]
	lsl r1, r1, #0x18
	ldr r2, [sp, #0x18]
	str r0, [sp, #8]
	lsl r4, r4, #6
	ldrb r3, [r3]
	add r0, r6, #0
	lsr r1, r1, #0x18
	add r2, r2, r4
	bl LoadRectToBgTilemapRect
_021FD566:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_021FD56C: .word ov15_02201340
_021FD570: .word ov15_02201328
	thumb_func_end ov15_021FD4C0


	thumb_func_start ov15_021FD574
ov15_021FD574: ; 0x021FD574
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	add r4, r0, #0
	add r6, r2, #0
	add r7, r3, #0
	cmp r5, #4
	bls _021FD588
	bl GF_AssertFail
_021FD588:
	cmp r5, #4
	bls _021FD58E
	b _021FD770
_021FD58E:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FD59A: ; jump table
	.short _021FD5A4 - _021FD59A - 2 ; case 0
	.short _021FD62E - _021FD59A - 2 ; case 1
	.short _021FD6C6 - _021FD59A - 2 ; case 2
	.short _021FD70C - _021FD59A - 2 ; case 3
	.short _021FD740 - _021FD59A - 2 ; case 4
_021FD5A4:
	mov r0, #6
	str r0, [sp]
	mov r0, #0xf
	mov r1, #0x2b
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4]
	ldr r3, [r3, #8]
	mov r1, #5
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4]
	mov r1, #5
	bl GetBgTilemapBuffer
	ldr r1, [sp, #4]
	ldr r1, [r1, #8]
	bl DC_FlushRange
	ldr r0, [r4]
	mov r1, #5
	add r2, r6, #0
	bl ov15_021FD43C
	ldr r0, [r4]
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	mov r0, #6
	str r0, [sp]
	mov r0, #0xf
	mov r1, #0x27
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	add r3, r1, #0
	bl ov15_0220005C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021FD62E:
	mov r0, #6
	str r0, [sp]
	mov r0, #0xf
	mov r1, #0x2c
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4]
	ldr r3, [r3, #8]
	mov r1, #5
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4]
	mov r1, #5
	bl GetBgTilemapBuffer
	ldr r1, [sp, #4]
	ldr r1, [r1, #8]
	bl DC_FlushRange
	ldr r0, [r4]
	mov r1, #5
	add r2, r6, #0
	add r3, r7, #0
	bl ov15_021FD4C0
	ldr r0, [r4]
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	mov r0, #6
	str r0, [sp]
	mov r0, #0xf
	mov r1, #0x2a
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	add r0, r4, #0
	bl ov15_02200294
	add r0, r4, #0
	bl ov15_021FA098
	add r2, r0, #0
	add r0, r4, #0
	add r1, r6, #0
	mov r3, #0
	bl ov15_0220005C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021FD6C6:
	mov r0, #6
	str r0, [sp]
	mov r0, #0xf
	mov r1, #0x2d
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	ldr r0, [r4]
	mov r1, #5
	add r2, r6, #0
	bl ov15_021FD43C
	ldr r0, [r4]
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021FD70C:
	mov r0, #6
	str r0, [sp]
	mov r0, #0xf
	mov r1, #0x34
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021FD740:
	mov r0, #6
	str r0, [sp]
	mov r0, #0xf
	mov r1, #0x35
	mov r2, #0
	add r3, sp, #4
	bl GfGfxLoader_GetScrnData
	ldr r3, [sp, #4]
	add r5, r0, #0
	add r2, r3, #0
	ldr r0, [r4]
	ldr r3, [r3, #8]
	mov r1, #6
	add r2, #0xc
	bl BG_LoadScreenTilemapData
	ldr r0, [r4]
	mov r1, #6
	bl ScheduleBgTilemapBufferTransfer
	add r0, r5, #0
	bl Heap_Free
_021FD770:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov15_021FD574
