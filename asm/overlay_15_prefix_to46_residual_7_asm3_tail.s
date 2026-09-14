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

	thumb_func_start ov15_021FAB34
ov15_021FAB34: ; 0x021FAB34
	push {r3, r4, r5, lr}
	ldr r1, _021FAC28 ; =0x00000619
	add r5, r0, #0
	add r4, r5, r1
	ldrb r1, [r4, #2]
	cmp r1, #0
	beq _021FAB4C
	cmp r1, #1
	beq _021FAB58
	cmp r1, #2
	beq _021FAC20
	b _021FAC24
_021FAB4C:
	mov r0, #0
	strb r0, [r4, #3]
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
	b _021FAC24
_021FAB58:
	ldrb r1, [r4, #3]
	cmp r1, #8
	bhs _021FAB64
	add r0, r1, #1
	strb r0, [r4, #3]
	b _021FAC24
_021FAB64:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	ldrb r2, [r4]
	add r1, #0x64
	strb r2, [r1]
	bl ov15_021F9F08
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	add r0, r5, #0
	add r2, r1, #0
	add r2, #0x64
	ldrb r3, [r2]
	mov r2, #0xc
	mul r2, r3
	add r1, r1, r2
	mov r2, #0xa
	ldrsh r1, [r1, r2]
	sub r2, #0xb
	mov r3, #0
	bl ov15_021FF364
	add r0, r5, #0
	bl ov15_021FA074
	mov r1, #0
	add r2, r0, #0
	add r0, r5, #0
	add r3, r1, #0
	bl ov15_021FD574
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_02200030
	mov r2, #0x8d
	lsl r2, r2, #2
	ldr r2, [r5, r2]
	add r0, r5, #0
	add r2, #0x64
	ldrb r2, [r2]
	mov r1, #1
	bl ov15_021FD404
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r3, [r5, r0]
	add r0, r3, #0
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	add r0, r3, #0
	add r1, r3, #0
	add r0, #0xa
	add r1, #8
	add r0, r0, r2
	add r1, r1, r2
	add r2, r3, r2
	ldrb r2, [r2, #0xd]
	bl ov15_021FA044
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r3, [r5, r0]
	add r0, r3, #0
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	add r0, r3, #0
	add r1, r3, #0
	add r0, #0xa
	add r1, #8
	add r0, r0, r2
	add r1, r1, r2
	add r2, r3, r2
	ldrb r2, [r2, #0xd]
	mov r3, #6
	bl ov15_021FA070
	ldrb r0, [r4, #2]
	add r0, r0, #1
	strb r0, [r4, #2]
	mov r0, #1
	pop {r3, r4, r5, pc}
_021FAC20:
	mov r0, #1
	pop {r3, r4, r5, pc}
_021FAC24:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FAC28: .word 0x00000619
	thumb_func_end ov15_021FAB34
