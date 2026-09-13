#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FDC88
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
	.extern ov15_021FDB2C
	.extern ov15_021FDD54
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

	thumb_func_start ov15_021FDC88
ov15_021FDC88: ; 0x021FDC88
	push {r4, r5, lr}
	sub sp, #0x3c
	ldr r4, _021FDD34 ; =ov15_022005CC
	add r5, r0, #0
	add r3, sp, #0x18
	mov r2, #4
_021FDC94:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021FDC94
	ldr r0, [r4]
	add r2, sp, #0xc
	str r0, [r3]
	ldr r3, _021FDD38 ; =ov15_022004F4
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	ldr r1, _021FDD3C ; =0x00000615
	str r0, [r2]
	ldr r0, _021FDD40 ; =0x00000808
	ldrb r1, [r5, r1]
	add r0, r5, r0
	bl ov15_021FDB2C
	ldr r3, _021FDD44 ; =0x0000091C
	ldr r2, _021FDD48 ; =0x00000818
	ldrb r0, [r5, r3]
	add r1, r2, #0
	add r3, r3, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r5, r2]
	add r1, #0xf8
	str r0, [sp, #8]
	add r0, r2, #0
	add r0, #0xec
	add r2, #0xfc
	ldrh r3, [r5, r3]
	ldr r1, [r5, r1]
	add r0, r5, r0
	add r2, r5, r2
	bl Camera_Init_FromTargetDistanceAndAngle
	bl Thunk_G3X_Reset
	bl Camera_PushLookAtToNNSGlb
	ldr r0, _021FDD4C ; =0x0000081C
	add r4, r5, r0
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	lsl r0, r0, #2
	add r0, r4, r0
	add r0, #0xa0
	ldr r0, [r0]
	bl ov15_021FDD54
	add r0, r4, #0
	add r0, #0xe4
	ldr r0, [r0]
	lsl r0, r0, #2
	add r0, r4, r0
	add r0, #0xc0
	ldr r0, [r0]
	bl ov15_021FDD54
	add r0, r4, #0
	add r0, #0xe0
	ldr r0, [r0]
	bl ov15_021FDD54
	ldr r1, _021FDD50 ; =0x00000934
	add r0, r4, #0
	add r1, r5, r1
	add r2, sp, #0x18
	add r3, sp, #0xc
	bl GF3dRender_DrawModel
	mov r0, #0
	add r1, r0, #0
	bl RequestSwap3DBuffers
	add sp, #0x3c
	pop {r4, r5, pc}
	.balign 4, 0
_021FDD34: .word ov15_022005CC
_021FDD38: .word ov15_022004F4
_021FDD3C: .word 0x00000615
_021FDD40: .word 0x00000808
_021FDD44: .word 0x0000091C
_021FDD48: .word 0x00000818
_021FDD4C: .word 0x0000081C
_021FDD50: .word 0x00000934
	thumb_func_end ov15_021FDC88
