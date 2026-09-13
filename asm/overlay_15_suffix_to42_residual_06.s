#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text

	.public _022004EC
	.public _02201300
	.public _02201480
	.public ov15_021FEA5C
	.public ov15_021FEB64
	.public ov15_021FEB84
	.public ov15_021FECA0
	.public ov15_021FECC4
	.public ov15_021FECD8
	.public ov15_021FED24
	.public ov15_021FED3C
	.public ov15_021FED58
	.public ov15_021FED60
	.public ov15_021FEDEC
	.public ov15_021FEEA4
	.public ov15_021FEF48
	.public ov15_021FF004
	.public ov15_021FF058
	.public ov15_021FF068
	.public ov15_021FF0FC
	.public ov15_021FF1E0
	.public ov15_021FF29C
	.public ov15_021FF364
	.public ov15_021FF4EC
	.public ov15_021FF560
	.public ov15_021FF6BC
	.public ov15_021FF758
	.public ov15_021FF7AC
	.public ov15_021FF7C4
	.public ov15_021FF7FC
	.public ov15_021FF834
	.public ov15_021FF844
	.public ov15_021FF850
	.public ov15_021FF894
	.public ov15_021FF8D4
	.public ov15_021FF950
	.public ov15_021FF964
	.public ov15_021FFECC
	.public ov15_021FFF24
	.public ov15_021FFF34
	.public ov15_021FFFDC
	.public ov15_02200030
	.public ov15_0220005C
	.public ov15_02200140
	.public ov15_022001C4
	.public ov15_0220023C
	.public ov15_02200294
	.public ov15_022002B4
	.public ov15_022002EC
	.public ov15_02200300
	.public ov15_02200428
	.public ov15_02200458
	.public ov15_022004DC
	.public ov15_022004F4
	.public ov15_02200500
	.public ov15_0220050C
	.public ov15_02200518
	.public ov15_02200528
	.public ov15_02200529
	.public ov15_0220052A
	.public ov15_0220052B
	.public ov15_0220053C
	.public ov15_02200584
	.public ov15_02200585
	.public ov15_02200586
	.public ov15_02200587
	.public ov15_022005CC
	.public ov15_02200618
	.public ov15_02200640
	.public ov15_02200641
	.public ov15_02200642
	.public ov15_02200643
	.public ov15_022006CC
	.public ov15_022006E8
	.public ov15_02200704
	.public ov15_02200720
	.public ov15_0220073C
	.public ov15_02200758
	.public ov15_02200774
	.public ov15_02200790
	.public ov15_022008B0
	.public ov15_022008D0
	.public ov15_022008E8
	.public ov15_02200908
	.public ov15_02201304
	.public ov15_02201314
	.public ov15_02201328
	.public ov15_02201340
	.public ov15_02201368
	.public ov15_022013A8
	.public ov15_02201468
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
	.extern ov15_021FE17C
	.extern ov15_021FE1D0
	.extern ov15_021FE204
	.extern ov15_021FE3E0
	.extern ov15_021FE584
	.extern ov15_021FE5A4
	.extern ov15_021FE5C4
	.extern ov15_021FE620
	.extern ov15_021FE914
	.extern ov15_021FE990
	.public ov15_021FE9F0
	.public ov15_021FEA5C
	.public ov15_021FEB64
	.public ov15_021FEB84
	.public ov15_021FECA0
	.public ov15_021FECC4
	.public ov15_021FECD8
	.public ov15_021FED24
	.public ov15_021FED3C
	.public ov15_021FED58
	.public ov15_021FED60
	.public ov15_021FEDEC
	.public ov15_021FEEA4
	.public ov15_021FEF48
	.public ov15_021FEFC4
	.public ov15_021FF004
	.public ov15_021FF058
	.public ov15_021FF068
	.public ov15_021FF0FC
	.public ov15_021FF1E0
	.public ov15_021FF29C
	.public ov15_021FF320
	.public ov15_021FF364
	.public ov15_021FF4EC
	.public ov15_021FF560
	.public ov15_021FF570
	.public ov15_021FF66C
	.public ov15_021FF6BC
	.public ov15_021FF758
	.public ov15_021FF7AC
	.public ov15_021FF7C4
	.public ov15_021FF7FC
	.public ov15_021FF834
	.public ov15_021FF844
	.public ov15_021FF850
	.public ov15_021FF894
	.public ov15_021FF8D4
	.public ov15_021FF8F0
	.public ov15_021FF950
	.public ov15_021FF964
	.public ov15_021FF97C
	.public ov15_021FFA40
	.public ov15_021FFAD0
	.public ov15_021FFDD8
	.public ov15_021FFEC0
	.public ov15_021FFECC
	.public ov15_021FFF24
	.public ov15_021FFF34
	.public ov15_021FFFDC
	.public ov15_02200030
	.public ov15_0220005C
	.public ov15_022000F4
	.public ov15_02200140
	.public ov15_022001C4
	.public ov15_0220023C
	.public ov15_02200294
	.public ov15_022002B4
	.public ov15_022002EC
	.public ov15_02200300
	.public ov15_02200428
	.public ov15_02200458
	.public ov15_022004DC
	.extern _022004EC
	.extern ov15_022004F4
	.extern ov15_02200500
	.extern ov15_0220050C
	.extern ov15_02200518
	.extern ov15_02200528
	.extern ov15_02200529
	.extern ov15_0220052A
	.extern ov15_0220052B
	.extern ov15_0220053C
	.extern ov15_02200550
	.extern ov15_02200568
	.extern ov15_02200584
	.extern ov15_02200585
	.extern ov15_02200586
	.extern ov15_02200587
	.extern ov15_022005A8
	.extern ov15_022005CC
	.extern ov15_022005F0
	.extern ov15_02200618
	.extern ov15_02200640
	.extern ov15_02200641
	.extern ov15_02200642
	.extern ov15_02200643
	.extern ov15_02200684
	.extern ov15_022006CC
	.extern ov15_022006E8
	.extern ov15_02200704
	.extern ov15_02200720
	.extern ov15_0220073C
	.extern ov15_02200758
	.extern ov15_02200774
	.extern ov15_02200790
	.extern ov15_022008B0
	.extern ov15_022008B8
	.extern ov15_022008C8
	.extern ov15_022008D0
	.extern ov15_022008E8
	.extern ov15_02200908
	.extern ov15_02200998
	.extern ov15_022009A0
	.extern ov15_022009A8
	.extern ov15_022009BC
	.extern ov15_022009D4
	.extern ov15_022009D5
	.extern ov15_022009D6
	.extern ov15_022009D7
	.extern ov15_022009F4
	.extern ov15_02200A14
	.extern ov15_02200A34
	.extern ov15_02200A35
	.extern ov15_02200A36
	.extern ov15_02200A37
	.extern ov15_02200A58
	.extern ov15_02200A88
	.extern ov15_02200AB8
	.extern ov15_02200AB9
	.extern ov15_02200ABA
	.extern ov15_02200ABB
	.extern ov15_02200B0C
	.extern _02201300
	.extern ov15_02201304
	.extern ov15_02201314
	.extern ov15_02201328
	.extern ov15_02201340
	.extern ov15_02201368
	.extern ov15_022013A8
	.extern ov15_02201468
	.extern _02201480

thumb_func_start ov15_021FF320
ov15_021FF320: ; 0x021FF320
	push {r4, r5, r6, r7}
	add r3, r1, #0
	add r1, r2, #0
	ldr r2, _021FF360 ; =ov15_022008C8
	mov r5, #0
	ldrb r6, [r2, r3]
	add r4, r5, #0
	cmp r6, #0
	ble _021FF35A
	ldr r7, [r0]
	ldrb r2, [r2, r3]
	add r0, r7, #0
	add r6, r5, #0
	add r1, r1, #1
_021FF33C:
	ldrh r3, [r0]
	cmp r3, #0
	beq _021FF350
	add r3, r7, r6
	ldrh r3, [r3, #2]
	cmp r3, #0
	beq _021FF350
	add r5, r5, #1
	cmp r5, r1
	beq _021FF35A
_021FF350:
	add r4, r4, #1
	add r0, r0, #4
	add r6, r6, #4
	cmp r4, r2
	blt _021FF33C
_021FF35A:
	add r0, r4, #0
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
_021FF360: .word ov15_022008C8
	thumb_func_end ov15_021FF320

thumb_func_start ov15_021FF364
ov15_021FF364: ; 0x021FF364
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r5, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	str r1, [sp, #0x10]
	add r2, r0, #4
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	str r3, [sp, #0x14]
	mul r0, r1
	add r0, r2, r0
	mov r1, #6
	str r0, [sp, #0x24]
	ldrb r2, [r0, #9]
	ldrsh r0, [r0, r1]
	sub r0, r2, r0
	str r0, [sp, #0x20]
	cmp r0, #6
	ble _021FF392
	str r1, [sp, #0x20]
_021FF392:
	ldr r0, _021FF4DC ; =0x0000068A
	ldrb r0, [r5, r0]
	cmp r0, #0
	bne _021FF3A2
	mov r0, #0
	str r0, [sp, #0x18]
	mov r4, #6
	b _021FF3A8
_021FF3A2:
	mov r0, #6
	str r0, [sp, #0x18]
	mov r4, #0
_021FF3A8:
	ldr r1, _021FF4DC ; =0x0000068A
	mov r0, #1
	ldrb r2, [r5, r1]
	eor r0, r2
	strb r0, [r5, r1]
	add r0, r5, #0
	bl ov15_021FE17C
	mov r0, #0
	add r7, r5, #0
	ldr r6, [sp, #0x18]
	str r0, [sp, #0x2c]
	add r7, #0xb4
_021FF3C2:
	lsl r0, r6, #4
	add r0, r7, r0
	mov r1, #0
	bl FillWindowPixelBuffer
	lsl r0, r4, #4
	add r0, r7, r0
	bl ClearWindowTilemapAndScheduleTransfer
	ldr r0, [sp, #0x2c]
	add r6, r6, #1
	add r0, r0, #1
	add r4, r4, #1
	str r0, [sp, #0x2c]
	cmp r0, #6
	blt _021FF3C2
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r0, #0
	add r1, #0x64
	ldrb r1, [r1]
	str r0, [sp, #0x28]
	ldr r0, [sp, #0x24]
	ldr r2, [sp, #0x10]
	bl ov15_021FF320
	add r4, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x64
	ldrb r1, [r0]
	ldr r0, _021FF4E0 ; =ov15_022008C8
	ldrb r0, [r0, r1]
	cmp r4, r0
	bge _021FF4BE
	lsl r0, r4, #2
	str r0, [sp, #0x1c]
	add r7, r5, r0
	add r0, r5, #0
	str r0, [sp, #0x30]
	add r0, #0xb4
	ldr r6, [sp, #0x18]
	str r0, [sp, #0x30]
_021FF41C:
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x1c]
	ldr r0, [r0]
	ldr r2, [sp, #0x1c]
	add r1, r0, r1
	ldrh r0, [r0, r2]
	cmp r0, #0
	beq _021FF4A2
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq _021FF4A2
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bne _021FF450
	ldr r1, [sp, #0x30]
	lsl r2, r6, #4
	add r1, r1, r2
	mov r2, #0x35
	str r4, [sp]
	lsl r2, r2, #4
	ldr r2, [r7, r2]
	ldr r3, [sp, #0x24]
	add r0, r5, #0
	bl ov15_021FF570
	b _021FF494
_021FF450:
	ldr r0, _021FF4E4 ; =0x00000672
	ldrb r0, [r5, r0]
	cmp r4, r0
	bne _021FF470
	ldr r1, [sp, #0x30]
	lsl r2, r6, #4
	add r1, r1, r2
	mov r2, #0x35
	str r4, [sp]
	lsl r2, r2, #4
	ldr r2, [r7, r2]
	ldr r3, [sp, #0x24]
	add r0, r5, #0
	bl ov15_021FF570
	b _021FF494
_021FF470:
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FF4E8 ; =0x00010200
	mov r2, #0x35
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	lsl r2, r2, #4
	ldr r0, [sp, #0x30]
	lsl r1, r6, #4
	add r0, r0, r1
	mov r1, #0
	ldr r2, [r7, r2]
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
_021FF494:
	ldr r0, [sp, #0x28]
	add r6, r6, #1
	add r1, r0, #1
	ldr r0, [sp, #0x20]
	str r1, [sp, #0x28]
	cmp r1, r0
	bge _021FF4BE
_021FF4A2:
	ldr r0, [sp, #0x1c]
	add r4, r4, #1
	add r0, r0, #4
	str r0, [sp, #0x1c]
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r7, r7, #4
	add r0, #0x64
	ldrb r1, [r0]
	ldr r0, _021FF4E0 ; =ov15_022008C8
	ldrb r0, [r0, r1]
	cmp r4, r0
	blt _021FF41C
_021FF4BE:
	mov r4, #0
	add r5, #0xb4
_021FF4C2:
	ldr r0, [sp, #0x18]
	lsl r0, r0, #4
	add r0, r5, r0
	bl ScheduleWindowCopyToVram
	ldr r0, [sp, #0x18]
	add r4, r4, #1
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r4, #6
	blt _021FF4C2
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FF4DC: .word 0x0000068A
_021FF4E0: .word ov15_022008C8
_021FF4E4: .word 0x00000672
_021FF4E8: .word 0x00010200
	thumb_func_end ov15_021FF364

thumb_func_start ov15_021FF4EC
ov15_021FF4EC: ; 0x021FF4EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	mov r0, #0x8d
	add r7, r2, #0
	lsl r0, r0, #2
	ldr r2, [r6, r0]
	add r5, r6, #0
	add r0, r2, #4
	add r2, #0x64
	str r0, [sp, #4]
	ldrb r2, [r2]
	mov r0, #0xc
	add r7, r7, r1
	mul r0, r2
	str r0, [sp, #8]
	mov r4, #0
	add r5, #0xb4
_021FF510:
	add r0, r5, #0
	bl ClearWindowTilemapAndScheduleTransfer
	add r4, r4, #1
	add r5, #0x10
	cmp r4, #6
	blt _021FF510
	add r0, r6, #0
	bl ov15_021FE1D0
	add r0, r6, #0
	add r0, #0x64
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r6, #0
	bl ov15_021FE204
	lsl r2, r7, #2
	add r3, r6, r2
	mov r2, #0x35
	mov r1, #0x5d
	lsl r1, r1, #2
	str r7, [sp]
	lsl r2, r2, #4
	ldr r2, [r3, r2]
	ldr r4, [sp, #4]
	ldr r3, [sp, #8]
	add r0, r6, #0
	add r1, r6, r1
	add r3, r4, r3
	bl ov15_021FF570
	mov r0, #0x5d
	lsl r0, r0, #2
	add r0, r6, r0
	bl ScheduleWindowCopyToVram
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov15_021FF4EC
