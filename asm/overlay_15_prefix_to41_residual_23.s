#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FE4C8
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
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

	thumb_func_start ov15_021FE17C
ov15_021FE17C: ; 0x021FE17C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r7, r0, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	bne _021FE1C8
	add r5, r7, #0
	ldr r4, _021FE1CC ; =ov15_02200908
	mov r6, #0
	add r5, #0xb4
_021FE192:
	ldr r0, [r4, #4]
	add r1, r5, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	mov r2, #4
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r3, [r4]
	ldr r0, [r7]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	add r6, r6, #1
	add r4, #0xc
	add r5, #0x10
	cmp r6, #0xc
	blt _021FE192
_021FE1C8:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FE1CC: .word ov15_02200908
	thumb_func_end ov15_021FE17C


	thumb_func_start ov15_021FE1D0
ov15_021FE1D0: ; 0x021FE1D0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	beq _021FE200
	mov r6, #0
	add r4, r5, #0
	add r4, #0xb4
	add r7, r6, #0
_021FE1E4:
	add r0, r4, #0
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #0
	bl RemoveWindow
	add r0, r5, #0
	add r0, #0xb4
	add r6, r6, #1
	str r7, [r0]
	add r4, #0x10
	add r5, #0x10
	cmp r6, #0xc
	blt _021FE1E4
_021FE200:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov15_021FE1D0


	thumb_func_start ov15_021FE204
ov15_021FE204: ; 0x021FE204
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	mov r3, #0x5d
	lsl r3, r3, #2
	str r0, [sp, #0x14]
	ldr r0, [r0, r3]
	cmp r0, #0
	beq _021FE216
	b _021FE3BC
_021FE216:
	mov r0, #7
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	mov r2, #4
	str r2, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, _021FE3C0 ; =0x000002CF
	ldr r1, [sp, #0x14]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	add r1, r1, r3
	ldr r0, [r0]
	mov r3, #0xc
	bl AddWindowParameterized
	mov r1, #0x5d
	ldr r0, [sp, #0x14]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [sp, #0x14]
	ldr r4, _021FE3C4 ; =0x0000031B
	str r0, [sp, #0x18]
	add r0, #0xb4
	ldr r5, _021FE3C8 ; =ov15_022008E8
	mov r6, #0
	str r0, [sp, #0x18]
_021FE252:
	add r0, r6, #0
	add r0, #0xd
	lsl r7, r0, #4
	ldr r0, [r5, #4]
	ldr r1, [sp, #0x18]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xa
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ldr r3, [r5]
	ldr r0, [r0]
	lsl r3, r3, #0x18
	add r1, r1, r7
	mov r2, #4
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	ldr r0, [sp, #0x18]
	mov r1, #0
	add r0, r0, r7
	bl FillWindowPixelBuffer
	add r6, r6, #1
	add r4, #0x14
	add r5, #8
	cmp r6, #4
	blt _021FE252
	ldr r0, [sp, #0x14]
	ldr r4, _021FE3CC ; =0x000002FB
	str r0, [sp, #0x1c]
	add r0, #0xb4
	ldr r5, _021FE3D0 ; =ov15_022008D0
	mov r6, #0
	str r0, [sp, #0x1c]
_021FE2A8:
	add r0, r6, #0
	add r0, #0x11
	lsl r7, r0, #4
	ldr r0, [r5, #4]
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ldr r3, [r5]
	ldr r0, [r0]
	lsl r3, r3, #0x18
	add r1, r1, r7
	mov r2, #4
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	ldr r0, [sp, #0x1c]
	mov r1, #0
	add r0, r0, r7
	bl FillWindowPixelBuffer
	add r6, r6, #1
	add r4, r4, #6
	add r5, #8
	cmp r6, #3
	blt _021FE2A8
	mov r0, #0x15
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldr r0, _021FE3D4 ; =0x0000030D
	mov r2, #0x7d
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x14]
	lsl r2, r2, #2
	add r1, r1, r2
	ldr r0, [r0]
	mov r2, #4
	mov r3, #0xe
	bl AddWindowParameterized
	mov r1, #0x7d
	ldr r0, [sp, #0x14]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #1
	str r0, [sp]
	mov r0, #0x12
	str r0, [sp, #4]
	mov r2, #4
	mov r4, #0x81
	str r2, [sp, #8]
	mov r3, #0xb
	ldr r0, _021FE3C4 ; =0x0000031B
	str r3, [sp, #0xc]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x14]
	lsl r4, r4, #2
	ldr r0, [r0]
	add r1, r1, r4
	bl AddWindowParameterized
	ldr r0, [sp, #0x14]
	add r1, r4, #0
	add r0, r0, r1
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r3, #0
	str r3, [sp]
	mov r0, #9
	str r0, [sp, #4]
	mov r2, #4
	str r2, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldr r0, _021FE3D8 ; =0x00000363
	ldr r1, [sp, #0x14]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	add r4, #0x10
	ldr r0, [r0]
	add r1, r1, r4
	bl AddWindowParameterized
	mov r1, #0x85
	ldr r0, [sp, #0x14]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0xe
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldr r0, _021FE3DC ; =0x00000387
	mov r2, #0x89
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x14]
	lsl r2, r2, #2
	add r1, r1, r2
	ldr r0, [r0]
	mov r2, #4
	mov r3, #0x18
	bl AddWindowParameterized
	mov r1, #0x89
	ldr r0, [sp, #0x14]
	lsl r1, r1, #2
	add r0, r0, r1
	mov r1, #0
	bl FillWindowPixelBuffer
_021FE3BC:
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FE3C0: .word 0x000002CF
_021FE3C4: .word 0x0000031B
_021FE3C8: .word ov15_022008E8
_021FE3CC: .word 0x000002FB
_021FE3D0: .word ov15_022008D0
_021FE3D4: .word 0x0000030D
_021FE3D8: .word 0x00000363
_021FE3DC: .word 0x00000387
	thumb_func_end ov15_021FE204


	thumb_func_start ov15_021FE3E0
ov15_021FE3E0: ; 0x021FE3E0
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x5d
	lsl r1, r1, #2
	str r0, [sp]
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _021FE4C6
	ldr r5, [sp]
	mov r4, #0
	add r6, r5, #0
	add r6, #0xb4
_021FE3F6:
	add r0, r4, #0
	add r0, #0x11
	lsl r7, r0, #4
	add r0, r6, r7
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r6, r7
	bl RemoveWindow
	mov r0, #0x71
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r5, r0]
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #3
	blt _021FE3F6
	add r1, r0, #0
	ldr r0, [sp]
	add r1, #0x60
	add r0, r0, r1
	bl ClearWindowTilemapAndScheduleTransfer
	mov r1, #0x89
	ldr r0, [sp]
	lsl r1, r1, #2
	add r0, r0, r1
	bl RemoveWindow
	mov r1, #0x89
	ldr r0, [sp]
	mov r2, #0
	lsl r1, r1, #2
	str r2, [r0, r1]
	sub r1, #0x10
	add r0, r0, r1
	bl RemoveWindow
	mov r1, #0x85
	ldr r0, [sp]
	mov r2, #0
	lsl r1, r1, #2
	str r2, [r0, r1]
	sub r1, #0x10
	add r0, r0, r1
	bl RemoveWindow
	mov r1, #0x81
	ldr r0, [sp]
	mov r2, #0
	lsl r1, r1, #2
	str r2, [r0, r1]
	sub r1, #0x10
	add r0, r0, r1
	bl ClearWindowTilemapAndScheduleTransfer
	mov r1, #0x7d
	ldr r0, [sp]
	lsl r1, r1, #2
	add r0, r0, r1
	bl RemoveWindow
	ldr r0, [sp]
	mov r1, #0x7d
	add r6, r0, #0
	mov r5, #0
	lsl r1, r1, #2
	str r5, [r0, r1]
	add r4, r0, #0
	add r6, #0xb4
_021FE482:
	add r0, r5, #0
	add r0, #0xd
	lsl r7, r0, #4
	add r0, r6, r7
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r6, r7
	bl RemoveWindow
	mov r0, #0x61
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r5, r5, #1
	add r4, #0x10
	cmp r5, #4
	blt _021FE482
	add r1, r0, #0
	ldr r0, [sp]
	sub r1, #0x10
	add r0, r0, r1
	bl ClearWindowTilemapAndScheduleTransfer
	mov r1, #0x5d
	ldr r0, [sp]
	lsl r1, r1, #2
	add r0, r0, r1
	bl RemoveWindow
	mov r1, #0x5d
	ldr r0, [sp]
	mov r2, #0
	lsl r1, r1, #2
	str r2, [r0, r1]
_021FE4C6:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov15_021FE3E0


	thumb_func_start ov15_021FE4C8
ov15_021FE4C8: ; 0x021FE4C8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xe1
	mov r3, #6
	bl NewMsgDataFromNarc
	ldr r7, _021FE500 ; =0x000005F4
	add r6, r0, #0
	mov r4, #0
_021FE4DE:
	add r0, r6, #0
	add r1, r4, #0
	bl NewString_ReadMsgData
	lsl r1, r4, #2
	add r1, r5, r1
	str r0, [r1, r7]
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #8
	blo _021FE4DE
	add r0, r6, #0
	bl DestroyMsgData
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FE500: .word 0x000005F4
	thumb_func_end ov15_021FE4C8
