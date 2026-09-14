#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FA170
	.public ov15_021FA1BC
	.public ov15_021FA4F8
	.public ov15_021FA578
	.public ov15_021FA620
	.public ov15_021FA68C
	.public ov15_021FA6C0
	.public ov15_021FA73C
	.public ov15_021FA93C
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021F9F08
	.extern ov15_021FA044
	.extern ov15_021FA070
	.extern ov15_021FA074
	.extern ov15_021FA0E4
	.extern ov15_021FA104
	.extern ov15_021FAC2C
	.extern ov15_021FAC40
	.extern ov15_021FAD80
	.extern ov15_021FB14C
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
	.extern ov15_021FD404
	.extern ov15_021FD574
	.extern ov15_021FD774
	.extern ov15_021FD7D0
	.extern ov15_021FD810
	.extern ov15_021FDAF4
	.extern ov15_021FDF88
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

	thumb_func_start ov15_021FA73C
ov15_021FA73C: ; 0x021FA73C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	add r7, r2, #0
	mov r6, #1
	cmp r1, #0x10
	bls _021FA74A
	b _021FA92A
_021FA74A:
	add r2, r1, r1
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021FA756: ; jump table
	.short _021FA778 - _021FA756 - 2 ; case 0
	.short _021FA778 - _021FA756 - 2 ; case 1
	.short _021FA778 - _021FA756 - 2 ; case 2
	.short _021FA778 - _021FA756 - 2 ; case 3
	.short _021FA778 - _021FA756 - 2 ; case 4
	.short _021FA778 - _021FA756 - 2 ; case 5
	.short _021FA778 - _021FA756 - 2 ; case 6
	.short _021FA778 - _021FA756 - 2 ; case 7
	.short _021FA856 - _021FA756 - 2 ; case 8
	.short _021FA856 - _021FA756 - 2 ; case 9
	.short _021FA856 - _021FA756 - 2 ; case 10
	.short _021FA856 - _021FA756 - 2 ; case 11
	.short _021FA856 - _021FA756 - 2 ; case 12
	.short _021FA856 - _021FA756 - 2 ; case 13
	.short _021FA8C4 - _021FA756 - 2 ; case 14
	.short _021FA892 - _021FA756 - 2 ; case 15
	.short _021FA8F6 - _021FA756 - 2 ; case 16
_021FA778:
	bl ov15_021FA68C
	sub r1, r6, #2
	cmp r0, r1
	bne _021FA786
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_021FA786:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	add r1, r2, #0
	add r1, #0x64
	ldrb r1, [r1]
	cmp r0, r1
	bne _021FA7A0
	ldr r1, [sp, #0x1c]
	cmp r1, #0
	bne _021FA7A0
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_021FA7A0:
	add r2, #0x64
	strb r0, [r2]
	add r0, r4, #0
	bl ov15_021F9F08
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r2, r0, #4
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r5, r2, r0
	add r0, r4, #0
	bl ov15_021FA074
	mov r1, #0
	add r2, r0, #0
	add r0, r4, #0
	add r3, r1, #0
	bl ov15_021FD574
	mov r2, #6
	ldrsh r1, [r5, r2]
	add r0, r4, #0
	sub r2, r2, #7
	mov r3, #0
	bl ov15_021FF364
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_02200030
	mov r2, #6
	ldrb r1, [r5, #9]
	ldrsh r2, [r5, r2]
	add r0, r4, #0
	mov r3, #0
	bl ov15_021FF6BC
	add r0, r4, #0
	bl ov15_021FA074
	add r2, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	mov r3, #1
	bl ov15_02200140
	mov r2, #0x8d
	lsl r2, r2, #2
	ldr r2, [r4, r2]
	add r0, r4, #0
	add r2, #0x64
	ldrb r2, [r2]
	mov r1, #1
	bl ov15_021FD404
	ldr r0, _021FA930 ; =0x000005DC
	bl PlaySE
	add r0, r4, #0
	bl ov15_021FA170
	ldr r0, _021FA934 ; =0x00000644
	ldr r1, [r4, r0]
	cmp r1, #8
	blt _021FA838
	add r0, r4, #0
	bl ov15_021FA0E4
_021FA838:
	add r0, r4, #0
	bl ov15_021FDF88
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	ldr r0, _021FA938 ; =0x00000808
	add r1, #0x64
	ldrb r1, [r1]
	add r0, r4, r0
	mov r2, #7
	add r1, r1, #1
	bl ov15_021FDAF4
	b _021FA92A
_021FA856:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	sub r1, #8
	add r3, r2, #0
	add r3, #0x64
	ldrb r5, [r3]
	mov r3, #0xc
	add r0, r2, #4
	mul r3, r5
	add r3, r0, r3
	mov r0, #6
	ldrsh r0, [r3, r0]
	add r0, r0, r1
	ldrb r1, [r3, #9]
	cmp r0, r1
	bge _021FA88A
	ldr r1, [r3]
	lsl r0, r0, #2
	ldrh r0, [r1, r0]
	add r2, #0x66
	strh r0, [r2]
	ldr r0, _021FA930 ; =0x000005DC
	strb r6, [r7]
	bl PlaySE
_021FA88A:
	add r0, r4, #0
	bl ov15_021FA170
	b _021FA92A
_021FA892:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	add r0, r2, #0
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r0, r2, r0
	ldrb r0, [r0, #0xd]
	cmp r0, #6
	bls _021FA92A
	ldr r0, _021FA930 ; =0x000005DC
	bl PlaySE
	mov r0, #0x1e
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x12
	mov r2, #9
	mov r3, #8
	bl ov15_021FD7D0
	add r6, r0, #0
	b _021FA92A
_021FA8C4:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	add r0, r2, #0
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r0, r2, r0
	ldrb r0, [r0, #0xd]
	cmp r0, #6
	bls _021FA92A
	ldr r0, _021FA930 ; =0x000005DC
	bl PlaySE
	mov r0, #0x1f
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x11
	mov r2, #9
	mov r3, #8
	bl ov15_021FD7D0
	add r6, r0, #0
	b _021FA92A
_021FA8F6:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	mov r3, #0
	add r2, #0x66
	strh r3, [r2]
	ldr r1, [r4, r1]
	mov r2, #5
	add r1, #0x68
	strh r2, [r1]
	ldr r1, [sp, #0x1c]
	bl ov15_021FD774
	mov r0, #SEQ_SE_GS_GEARCANCEL>>6
	lsl r0, r0, #6
	bl PlaySE
	mov r0, #0x24
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x13
	mov r2, #9
	mov r3, #8
	bl ov15_021FD7D0
	add r6, r0, #0
_021FA92A:
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FA930: .word 0x000005DC
_021FA934: .word 0x00000644
_021FA938: .word 0x00000808
	thumb_func_end ov15_021FA73C
