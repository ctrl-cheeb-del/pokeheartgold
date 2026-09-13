#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
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

	thumb_func_start ov15_021FE5C4
ov15_021FE5C4: ; 0x021FE5C4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, _021FE618 ; =0x0000FFFF
	add r6, r1, #0
	cmp r6, r0
	beq _021FE5E6
	mov r0, #0x82
	mov r1, #6
	bl String_New
	add r1, r6, #0
	mov r2, #6
	add r4, r0, #0
	bl GetItemDescIntoString
	b _021FE5F4
_021FE5E6:
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x61
	bl NewString_ReadMsgData
	add r4, r0, #0
_021FE5F4:
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE61C ; =0x000F0E00
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #4
	mov r3, #0x14
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_021FE618: .word 0x0000FFFF
_021FE61C: .word 0x000F0E00
	thumb_func_end ov15_021FE5C4


	thumb_func_start ov15_021FE620
ov15_021FE620: ; 0x021FE620
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r4, r5, #0
	add r0, r1, #0
	add r4, #0x14
	bl TMHMGetMove
	str r0, [sp, #0x10]
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x65
	bl NewString_ReadMsgData
	mov r1, #0
	add r6, r0, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE860 ; =0x000F0E00
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x59
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE860 ; =0x000F0E00
	mov r1, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r2, r6, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x5c
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE860 ; =0x000F0E00
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r3, #0x48
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x5a
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE860 ; =0x000F0E00
	add r2, r6, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r3, #0xa8
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x5b
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE860 ; =0x000F0E00
	mov r1, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r2, r6, #0
	mov r3, #0xa8
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	ldr r0, [sp, #0x10]
	mov r1, #0
	bl GetMoveMaxPP
	add r7, r0, #0
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x5d
	bl NewString_ReadMsgData
	add r6, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0xbd
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	add r2, r7, #0
	mov r3, #2
	bl BufferIntegerAsString
	mov r0, #0xbd
	ldr r1, _021FE864 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl StringExpandPlaceholders
	add r0, r6, #0
	bl String_Delete
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE860 ; =0x000F0E00
	mov r1, #0
	str r0, [sp, #8]
	ldr r2, _021FE864 ; =0x000005E4
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r3, #0x30
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x10]
	mov r1, #2
	bl GetMoveAttr
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	cmp r7, #1
	bhi _021FE790
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x19
	bl NewString_ReadMsgData
	b _021FE79C
_021FE790:
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x5e
	bl NewString_ReadMsgData
_021FE79C:
	mov r1, #0
	add r6, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0xbd
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r7, #0
	mov r3, #3
	bl BufferIntegerAsString
	mov r0, #0xbd
	ldr r1, _021FE864 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl StringExpandPlaceholders
	add r0, r6, #0
	bl String_Delete
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE860 ; =0x000F0E00
	ldr r2, _021FE864 ; =0x000005E4
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r3, #0xe8
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x10]
	mov r1, #4
	bl GetMoveAttr
	lsl r0, r0, #0x10
	lsr r7, r0, #0x10
	bne _021FE800
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x19
	bl NewString_ReadMsgData
	b _021FE80C
_021FE800:
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x5e
	bl NewString_ReadMsgData
_021FE80C:
	mov r1, #0
	add r6, r0, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0xbd
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r7, #0
	mov r3, #3
	bl BufferIntegerAsString
	mov r0, #0xbd
	ldr r1, _021FE864 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r6, #0
	bl StringExpandPlaceholders
	add r0, r6, #0
	bl String_Delete
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _021FE860 ; =0x000F0E00
	mov r1, #0
	str r0, [sp, #8]
	ldr r2, _021FE864 ; =0x000005E4
	str r1, [sp, #0xc]
	ldr r2, [r5, r2]
	add r0, r4, #0
	mov r3, #0xe8
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl ScheduleWindowCopyToVram
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FE860: .word 0x000F0E00
_021FE864: .word 0x000005E4
	thumb_func_end ov15_021FE620
