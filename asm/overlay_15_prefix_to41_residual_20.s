#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FDAF4
	.public ov15_021FDB2C
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

	thumb_func_start ov15_021FDAF4
ov15_021FDAF4: ; 0x021FDAF4
	push {r4, r5}
	mov r4, #0x4a
	lsl r4, r4, #2
	add r3, r4, #2
	ldrh r5, [r0, r4]
	ldrh r3, [r0, r3]
	cmp r5, r3
	bne _021FDB22
	add r3, r4, #0
	sub r3, #8
	ldr r5, [r0, r3]
	add r3, r4, #0
	sub r3, #0xc
	str r5, [r0, r3]
	add r3, r4, #0
	sub r3, #8
	str r1, [r0, r3]
	mov r1, #0
	strh r1, [r0, r4]
	add r1, r4, #2
	strh r2, [r0, r1]
	pop {r4, r5}
	bx lr
_021FDB22:
	sub r2, r4, #4
	str r1, [r0, r2]
	pop {r4, r5}
	bx lr
	.balign 4, 0
	thumb_func_end ov15_021FDAF4


	thumb_func_start ov15_021FDB2C
ov15_021FDB2C: ; 0x021FDB2C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	mov r0, #0x90
	add r2, r1, #0
	add r1, r0, #0
	ldr r3, _021FDC64 ; =ov15_02200790
	mul r2, r0
	add r1, #0x98
	add r4, r3, r2
	ldrh r2, [r5, r1]
	add r1, r0, #0
	add r1, #0x9a
	ldrh r1, [r5, r1]
	cmp r2, r1
	beq _021FDC28
	add r1, r0, #0
	add r1, #0x98
	ldrh r1, [r5, r1]
	add r2, r1, #1
	add r1, r0, #0
	add r1, #0x98
	strh r2, [r5, r1]
	add r1, r0, #0
	add r1, #0x8c
	add r0, #0x90
	ldr r1, [r5, r1]
	ldr r0, [r5, r0]
	lsl r1, r1, #4
	lsl r0, r0, #4
	str r1, [sp, #8]
	ldrh r7, [r4, r1]
	ldrh r1, [r4, r0]
	str r0, [sp, #4]
	sub r0, r1, r7
	bpl _021FDB76
	neg r0, r0
_021FDB76:
	cmp r1, r7
	bhs _021FDB80
	mov r1, #0
	mvn r1, r1
	b _021FDB82
_021FDB80:
	mov r1, #1
_021FDB82:
	mov r2, #2
	lsl r2, r2, #0xe
	cmp r0, r2
	ble _021FDB94
	lsl r2, r2, #1
	sub r0, r2, r0
	mov r2, #0
	mvn r2, r2
	mul r1, r2
_021FDB94:
	cmp r1, #0
	ldr r2, _021FDC68 ; =0x0000012A
	ble _021FDBB0
	ldrh r1, [r5, r2]
	str r1, [sp]
	sub r1, r2, #2
	ldrh r6, [r5, r1]
	ldr r1, [sp]
	bl _s32_div_f
	mul r0, r6
	add r0, r7, r0
	str r0, [sp, #0x14]
	b _021FDBC4
_021FDBB0:
	ldrh r1, [r5, r2]
	str r1, [sp]
	sub r1, r2, #2
	ldrh r6, [r5, r1]
	ldr r1, [sp]
	bl _s32_div_f
	mul r0, r6
	sub r0, r7, r0
	str r0, [sp, #0x14]
_021FDBC4:
	ldr r0, [sp, #8]
	ldr r1, [sp]
	add r0, r4, r0
	ldrh r7, [r0, #2]
	ldr r0, [sp, #4]
	add r0, r4, r0
	ldrh r0, [r0, #2]
	sub r0, r0, r7
	bl _s32_div_f
	mul r0, r6
	add r0, r7, r0
	str r0, [sp, #0x10]
	ldr r0, [sp, #8]
	ldr r1, [sp]
	add r0, r4, r0
	ldr r7, [r0, #8]
	ldr r0, [sp, #4]
	add r0, r4, r0
	ldr r0, [r0, #8]
	sub r0, r0, r7
	bl _s32_div_f
	mul r0, r6
	add r0, r7, r0
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	ldr r1, [sp]
	add r0, r4, r0
	ldr r7, [r0, #0xc]
	ldr r0, [sp, #4]
	add r0, r4, r0
	ldr r0, [r0, #0xc]
	sub r0, r0, r7
	bl _s32_div_f
	mul r0, r6
	add r1, r7, r0
	mov r0, #0x43
	lsl r0, r0, #2
	ldr r2, [sp, #0x14]
	add r3, r0, #2
	strh r2, [r5, r0]
	ldr r2, [sp, #0x10]
	strh r2, [r5, r3]
	sub r3, r0, #4
	ldr r2, [sp, #0xc]
	add r0, #0x24
	str r2, [r5, r3]
	str r1, [r5, r0]
_021FDC28:
	mov r1, #0x4a
	lsl r1, r1, #2
	add r0, r1, #2
	ldrh r2, [r5, r1]
	ldrh r0, [r5, r0]
	cmp r2, r0
	bne _021FDC60
	sub r0, r1, #4
	mov r2, #0
	ldr r0, [r5, r0]
	mvn r2, r2
	cmp r0, r2
	beq _021FDC60
	add r0, r1, #0
	sub r0, #8
	ldr r3, [r5, r0]
	add r0, r1, #0
	sub r0, #0xc
	str r3, [r5, r0]
	sub r0, r1, #4
	ldr r3, [r5, r0]
	add r0, r1, #0
	sub r0, #8
	str r3, [r5, r0]
	sub r0, r1, #4
	str r2, [r5, r0]
	mov r0, #0
	strh r0, [r5, r1]
_021FDC60:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FDC64: .word ov15_02200790
_021FDC68: .word 0x0000012A
	thumb_func_end ov15_021FDB2C
