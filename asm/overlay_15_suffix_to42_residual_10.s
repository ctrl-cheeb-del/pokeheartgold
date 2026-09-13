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

thumb_func_start ov15_021FF8F0
ov15_021FF8F0: ; 0x021FF8F0
	push {r4, r5, r6, lr}
	sub sp, #8
	add r6, r2, #0
	add r5, r0, #0
	add r4, r1, #0
	add r0, r6, #0
	mov r1, #1
	bl GetItemIndexMapping
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FF948 ; =0x0000C0FC
	mov r1, #0x92
	add r0, r4, r0
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x12
	bl SpriteSystem_ReplaceCharResObj
	add r0, r6, #0
	mov r1, #2
	bl GetItemIndexMapping
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _021FF94C ; =0x0000C0FB
	mov r1, #0x92
	add r0, r4, r0
	lsl r1, r1, #2
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x12
	bl SpriteSystem_ReplacePlttResObj
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_021FF948: .word 0x0000C0FC
_021FF94C: .word 0x0000C0FB
	thumb_func_end ov15_021FF8F0
