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

	thumb_func_start ov15_021FA12C
ov15_021FA12C: ; 0x021FA12C
	push {r3, r4}
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r3, [r0, r1]
	add r1, r3, #0
	add r1, #0x64
	ldrb r2, [r1]
	mov r1, #0xc
	add r3, r3, #4
	mul r1, r2
	add r1, r3, r1
	mov r3, #6
	ldrsh r4, [r1, r3]
	ldr r3, _021FA168 ; =0x00000644
	ldr r0, [r0, r3]
	add r3, r4, r0
	ldr r0, _021FA16C ; =ov15_022008B0
	sub r3, #8
	ldrb r0, [r0, r2]
	cmp r0, r3
	bhi _021FA15C
	mov r0, #0
	pop {r3, r4}
	bx lr
_021FA15C:
	ldr r1, [r1]
	lsl r0, r3, #2
	ldrh r0, [r1, r0]
	pop {r3, r4}
	bx lr
	nop
_021FA168: .word 0x00000644
_021FA16C: .word ov15_022008B0
	thumb_func_end ov15_021FA12C


	thumb_func_start ov15_021FA170
ov15_021FA170: ; 0x021FA170
	push {r4, lr}
	ldr r1, _021FA1B8 ; =0x00000644
	add r4, r0, #0
	ldr r2, [r4, r1]
	cmp r2, #8
	blt _021FA19C
	cmp r2, #0xd
	bgt _021FA19C
	bl ov15_021FA12C
	add r2, r0, #0
	beq _021FA192
	add r0, r4, #0
	add r1, r4, #4
	bl ov15_021FECA0
	pop {r4, pc}
_021FA192:
	add r0, r4, #0
	add r1, r4, #4
	bl ov15_021FECC4
	pop {r4, pc}
_021FA19C:
	cmp r2, #0
	blt _021FA1AE
	cmp r2, #7
	bgt _021FA1AE
	add r0, r4, #0
	add r1, r4, #4
	bl ov15_021FECD8
	pop {r4, pc}
_021FA1AE:
	add r0, r4, #0
	add r1, r4, #4
	bl ov15_021FECC4
	pop {r4, pc}
	.balign 4, 0
_021FA1B8: .word 0x00000644
	thumb_func_end ov15_021FA170


	thumb_func_start ov15_021FA1BC
ov15_021FA1BC: ; 0x021FA1BC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r1, _021FA4A4 ; =gSystem
	mov r2, #0x40
	ldr r3, [r1, #0x4c]
	add r5, r0, #0
	mov r4, #0
	tst r2, r3
	beq _021FA1DE
	ldr r0, _021FA4A8 ; =0x00000644
	add r4, r4, #1
	ldr r1, [r5, r0]
	lsl r2, r1, #2
	ldr r1, _021FA4AC ; =ov15_02200640
	ldrb r1, [r1, r2]
	str r1, [r5, r0]
	b _021FA38C
_021FA1DE:
	mov r2, #0x80
	tst r2, r3
	beq _021FA1F4
	ldr r0, _021FA4A8 ; =0x00000644
	add r4, r4, #1
	ldr r1, [r5, r0]
	lsl r2, r1, #2
	ldr r1, _021FA4B0 ; =ov15_02200641
	ldrb r1, [r1, r2]
	str r1, [r5, r0]
	b _021FA38C
_021FA1F4:
	mov r2, #0x20
	add r6, r3, #0
	tst r6, r2
	beq _021FA246
	ldr r1, _021FA4A8 ; =0x00000644
	ldr r3, _021FA4B4 ; =ov15_02200642
	ldr r1, [r5, r1]
	lsl r6, r1, #2
	ldrb r3, [r3, r6]
	cmp r3, #0xe
	bne _021FA21E
	mov r1, #2
	str r1, [sp]
	mov r1, #0xe
	add r2, sp, #0xc
	mov r3, #1
	str r4, [sp, #4]
	bl ov15_021FA73C
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FA21E:
	cmp r1, #0x10
	beq _021FA274
	cmp r1, #0
	blt _021FA23E
	cmp r1, #8
	bge _021FA23E
	sub r2, #0x21
	bl ov15_021FA6C0
	ldr r1, _021FA4A8 ; =0x00000644
	ldr r2, [r5, r1]
	cmp r2, r0
	beq _021FA274
	str r0, [r5, r1]
	add r4, r4, #1
	b _021FA38C
_021FA23E:
	ldr r0, _021FA4A8 ; =0x00000644
	add r4, r4, #1
	str r3, [r5, r0]
	b _021FA38C
_021FA246:
	mov r2, #0x10
	tst r3, r2
	beq _021FA29A
	ldr r1, _021FA4A8 ; =0x00000644
	ldr r2, _021FA4B8 ; =ov15_02200643
	ldr r1, [r5, r1]
	lsl r3, r1, #2
	ldrb r2, [r2, r3]
	cmp r2, #0xf
	bne _021FA270
	mov r1, #2
	str r1, [sp]
	add r2, sp, #8
	mov r1, #0xf
	add r2, #3
	mov r3, #1
	str r4, [sp, #4]
	bl ov15_021FA73C
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FA270:
	cmp r1, #0x10
	bne _021FA276
_021FA274:
	b _021FA38C
_021FA276:
	cmp r1, #0
	blt _021FA292
	cmp r1, #8
	bge _021FA292
	mov r2, #1
	bl ov15_021FA6C0
	ldr r1, _021FA4A8 ; =0x00000644
	ldr r2, [r5, r1]
	cmp r2, r0
	beq _021FA38C
	str r0, [r5, r1]
	add r4, r4, #1
	b _021FA38C
_021FA292:
	ldr r0, _021FA4A8 ; =0x00000644
	add r4, r4, #1
	str r2, [r5, r0]
	b _021FA38C
_021FA29A:
	ldr r3, [r1, #0x48]
	lsl r1, r2, #5
	tst r1, r3
	beq _021FA314
	ldr r1, _021FA4A8 ; =0x00000644
	ldr r1, [r5, r1]
	cmp r1, #0
	blt _021FA2E6
	cmp r1, #8
	bge _021FA2E6
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	sub r2, #0x11
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_021FA6C0
	ldr r1, _021FA4A8 ; =0x00000644
	str r0, [r5, r1]
	ldr r1, [r5, r1]
	add r0, r5, #0
	bl ov15_021FFECC
	mov r0, #2
	str r0, [sp]
	add r0, r4, #0
	str r0, [sp, #4]
	ldr r1, _021FA4A8 ; =0x00000644
	add r2, sp, #8
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r2, #2
	mov r3, #1
	bl ov15_021FA73C
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FA2E6:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r2, #0
	add r1, #0x64
	ldrb r1, [r1]
	add r0, r5, #0
	mvn r2, r2
	bl ov15_021FA6C0
	add r1, r0, #0
	mov r0, #2
	str r0, [sp]
	mov r0, #0
	add r2, sp, #8
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, #2
	mov r3, #1
	bl ov15_021FA73C
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FA314:
	add r2, #0xf0
	add r1, r3, #0
	tst r1, r2
	beq _021FA38C
	ldr r1, _021FA4A8 ; =0x00000644
	ldr r1, [r5, r1]
	cmp r1, #0
	blt _021FA360
	cmp r1, #8
	bge _021FA360
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r2, #1
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_021FA6C0
	ldr r1, _021FA4A8 ; =0x00000644
	str r0, [r5, r1]
	ldr r1, [r5, r1]
	add r0, r5, #0
	bl ov15_021FFECC
	mov r0, #2
	str r0, [sp]
	add r0, r4, #0
	str r0, [sp, #4]
	ldr r1, _021FA4A8 ; =0x00000644
	add r2, sp, #8
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r2, #1
	mov r3, #1
	bl ov15_021FA73C
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FA360:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r1, #0x64
	ldrb r1, [r1]
	mov r2, #1
	bl ov15_021FA6C0
	add r1, r0, #0
	mov r0, #2
	str r0, [sp]
	mov r0, #0
	add r2, sp, #8
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, #1
	mov r3, #1
	bl ov15_021FA73C
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FA38C:
	ldr r1, _021FA4A8 ; =0x00000644
	ldr r0, [r5, r1]
	cmp r0, #0x11
	bne _021FA3A0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x64
	ldrb r0, [r0]
	str r0, [r5, r1]
_021FA3A0:
	cmp r4, #0
	beq _021FA3C4
	ldr r0, _021FA4BC ; =0x000005DC
	bl PlaySE
	ldr r1, _021FA4A8 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	ldr r1, _021FA4A8 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FA0E4
	add r0, r5, #0
	bl ov15_021FA170
_021FA3C4:
	mov r1, #0
	add r0, sp, #8
	strb r1, [r0]
	add r0, r5, #0
	bl ov15_021FAC2C
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _021FA440
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_021FA104
	cmp r0, #0
	beq _021FA426
	cmp r4, #8
	bhs _021FA408
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_021FA68C
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _021FA426
	ldr r1, _021FA4A8 ; =0x00000644
	add r0, r5, #0
	str r4, [r5, r1]
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	b _021FA426
_021FA408:
	ldr r1, _021FA4A8 ; =0x00000644
	add r0, r5, #0
	str r4, [r5, r1]
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	ldr r0, _021FA4A8 ; =0x00000644
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FA426
	cmp r1, #0xd
	bgt _021FA426
	add r0, r5, #0
	bl ov15_021FA0E4
_021FA426:
	mov r0, #2
	str r0, [sp]
	mov r3, #1
	add r0, r5, #0
	add r1, r4, #0
	add r2, sp, #8
	str r3, [sp, #4]
	bl ov15_021FA73C
	cmp r0, #1
	beq _021FA4DA
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FA440:
	ldr r0, _021FA4A4 ; =gSystem
	mov r3, #1
	ldr r1, [r0, #0x48]
	add r0, r1, #0
	tst r0, r3
	beq _021FA47E
	mov r0, #2
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r1, _021FA4A8 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	add r2, sp, #8
	bl ov15_021FA73C
	add r4, r0, #0
	ldr r0, _021FA4A8 ; =0x00000644
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FA474
	cmp r1, #0xd
	bgt _021FA474
	add r0, r5, #0
	bl ov15_021FA0E4
_021FA474:
	cmp r4, #1
	beq _021FA4DA
	add sp, #0x10
	add r0, r4, #0
	pop {r4, r5, r6, pc}
_021FA47E:
	mov r0, #2
	tst r1, r0
	beq _021FA4DA
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #0x10
	add r2, sp, #8
	bl ov15_021FA73C
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #0
	bl ov15_021FD774
	ldr r0, _021FA4A8 ; =0x00000644
	b _021FA4C0
	nop
_021FA4A4: .word gSystem
_021FA4A8: .word 0x00000644
_021FA4AC: .word ov15_02200640
_021FA4B0: .word ov15_02200641
_021FA4B4: .word ov15_02200642
_021FA4B8: .word ov15_02200643
_021FA4BC: .word 0x000005DC
_021FA4C0:
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FA4D0
	cmp r1, #0xd
	bgt _021FA4D0
	add r0, r5, #0
	bl ov15_021FA0E4
_021FA4D0:
	cmp r4, #1
	beq _021FA4DA
	add sp, #0x10
	add r0, r4, #0
	pop {r4, r5, r6, pc}
_021FA4DA:
	add r0, sp, #8
	ldrb r0, [r0]
	cmp r0, #1
	bne _021FA4F2
	add r0, r5, #0
	mov r1, #0x14
	mov r2, #0x29
	mov r3, #0x1b
	bl ov15_021FD810
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FA4F2:
	mov r0, #1
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end ov15_021FA1BC


	thumb_func_start ov15_021FA4F8
ov15_021FA4F8: ; 0x021FA4F8
	push {r3, r4, r5, r6, r7, lr}
	mov r1, #0x8d
	add r5, r0, #0
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r6, r1, #4
	add r1, #0x64
	ldrb r2, [r1]
	mov r1, #0xc
	add r7, r2, #0
	mul r7, r1
	mov r2, #0
	mov r1, #2
	add r3, r2, #0
	add r4, r6, r7
	bl ov15_021FD574
	ldr r2, _021FA574 ; =0x00000644
	mov r1, #6
	ldr r2, [r5, r2]
	ldrsh r1, [r4, r1]
	add r0, r5, #0
	sub r2, #8
	bl ov15_021FF4EC
	ldr r1, _021FA574 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	sub r1, #8
	bl ov15_022002B4
	add r0, r5, #0
	bl ov15_021FB14C
	mov r0, #6
	ldrsh r3, [r4, r0]
	ldr r0, _021FA574 ; =0x00000644
	ldr r1, [r6, r7]
	ldr r2, [r5, r0]
	add r2, r3, r2
	sub r2, #8
	lsl r2, r2, #2
	ldrh r2, [r1, r2]
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r1, #0x66
	strh r2, [r1]
	mov r2, #6
	ldrsh r3, [r4, r2]
	ldr r2, [r5, r0]
	ldr r1, [r6, r7]
	add r2, r3, r2
	sub r2, #8
	lsl r2, r2, #2
	add r1, r1, r2
	ldrh r1, [r1, #2]
	add r0, #0x3e
	strh r1, [r5, r0]
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FA574: .word 0x00000644
	thumb_func_end ov15_021FA4F8


	thumb_func_start ov15_021FA578
ov15_021FA578: ; 0x021FA578
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r3, r0, #4
	add r0, #0x64
	ldrb r2, [r0]
	mov r0, #0xc
	mul r0, r2
	add r4, r3, r0
	cmp r1, #0
	ble _021FA5A8
	mov r0, #6
	ldrsh r0, [r4, r0]
	add r1, r0, #6
	ldrb r0, [r4, #9]
	cmp r1, r0
	bge _021FA5A2
	strh r1, [r4, #6]
	b _021FA5C2
_021FA5A2:
	mov r0, #0
	strh r0, [r4, #6]
	b _021FA5C2
_021FA5A8:
	mov r1, #6
	ldrsh r0, [r4, r1]
	sub r0, r0, #6
	bmi _021FA5B4
	strh r0, [r4, #6]
	b _021FA5C2
_021FA5B4:
	ldrb r0, [r4, #9]
	sub r0, r0, #1
	bl _s32_div_f
	mov r1, #6
	mul r1, r0
	strh r1, [r4, #6]
_021FA5C2:
	ldr r0, _021FA618 ; =0x00000671
	ldrb r0, [r5, r0]
	cmp r0, #1
	bne _021FA5E0
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_021FAD80
	ldr r1, _021FA61C ; =0x0000066C
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FFF34
	mov r0, #3
	pop {r3, r4, r5, pc}
_021FA5E0:
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_021FA6F4
	add r0, r5, #0
	bl ov15_021FA170
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x65
	ldrb r0, [r0]
	cmp r0, #1
	beq _021FA60A
	cmp r0, #2
	beq _021FA606
	cmp r0, #3
	beq _021FA60E
	b _021FA612
_021FA606:
	mov r0, #0x10
	pop {r3, r4, r5, pc}
_021FA60A:
	mov r0, #0xe
	pop {r3, r4, r5, pc}
_021FA60E:
	mov r0, #0x1a
	pop {r3, r4, r5, pc}
_021FA612:
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_021FA618: .word 0x00000671
_021FA61C: .word 0x0000066C
	thumb_func_end ov15_021FA578


	thumb_func_start ov15_021FA620
ov15_021FA620: ; 0x021FA620
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _021FA648 ; =0x00000614
	ldrb r2, [r4, r0]
	mov r0, #0xa
	add r1, r2, #0
	mul r1, r0
	mov r0, #0x5a
	sub r0, r0, r1
	add r1, r2, #1
	bl _s32_div_f
	add r1, r0, #6
	ldr r0, _021FA64C ; =0x00000617
	strb r1, [r4, r0]
	ldrb r1, [r4, r0]
	add r0, r0, #1
	add r1, r1, #4
	strb r1, [r4, r0]
	pop {r4, pc}
	.balign 4, 0
_021FA648: .word 0x00000614
_021FA64C: .word 0x00000617
	thumb_func_end ov15_021FA620


	thumb_func_start ov15_021FA650
ov15_021FA650: ; 0x021FA650
	push {r4, lr}
	ldr r1, _021FA680 ; =gSystem
	ldr r2, [r1, #0x48]
	mov r1, #2
	lsl r1, r1, #0xc
	tst r1, r2
	beq _021FA67C
	ldr r3, _021FA684 ; =_02201480
	ldr r1, [r3]
	add r4, r1, #1
	ldr r1, _021FA688 ; =_02201300
	str r4, [r3]
	ldr r2, [r1]
	cmp r4, r2
	blt _021FA672
	mov r1, #0
	str r1, [r3]
_021FA672:
	ldr r3, _021FA684 ; =_02201480
	mov r1, #1
	ldr r3, [r3]
	bl ov15_021FD574
_021FA67C:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_021FA680: .word gSystem
_021FA684: .word _02201480
_021FA688: .word _02201300
	thumb_func_end ov15_021FA650


	thumb_func_start ov15_021FA68C
ov15_021FA68C: ; 0x021FA68C
	push {r4, r5}
	mov r2, #0x8d
	lsl r2, r2, #2
	ldr r5, [r0, r2]
	mov r3, #0
	add r2, r5, #0
	add r4, r3, #0
_021FA69A:
	ldrb r0, [r2, #0xc]
	cmp r1, r0
	bne _021FA6AE
	add r0, r5, r4
	ldr r0, [r0, #4]
	cmp r0, #0
	beq _021FA6AE
	add r0, r3, #0
	pop {r4, r5}
	bx lr
_021FA6AE:
	add r3, r3, #1
	add r2, #0xc
	add r4, #0xc
	cmp r3, #8
	blt _021FA69A
	mov r0, #0
	mvn r0, r0
	pop {r4, r5}
	bx lr
	thumb_func_end ov15_021FA68C


	thumb_func_start ov15_021FA6C0
ov15_021FA6C0: ; 0x021FA6C0
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r1, #0
	add r6, r2, #0
	mov r4, #0
_021FA6CA:
	add r5, r5, r6
	bpl _021FA6D2
	mov r5, #7
	b _021FA6D8
_021FA6D2:
	cmp r5, #8
	bne _021FA6D8
	mov r5, #0
_021FA6D8:
	add r0, r7, #0
	add r1, r5, #0
	bl ov15_021FA68C
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	bne _021FA6EE
	add r4, r4, #1
	cmp r4, #8
	blt _021FA6CA
_021FA6EE:
	add r0, r5, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov15_021FA6C0


	thumb_func_start ov15_021FA6F4
ov15_021FA6F4: ; 0x021FA6F4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov15_021FA074
	mov r1, #0
	add r2, r0, #0
	add r0, r5, #0
	add r3, r1, #0
	bl ov15_021FD574
	mov r2, #6
	ldrsh r1, [r4, r2]
	add r0, r5, #0
	sub r2, r2, #7
	mov r3, #0
	bl ov15_021FF364
	mov r2, #6
	ldrb r1, [r4, #9]
	ldrsh r2, [r4, r2]
	add r0, r5, #0
	mov r3, #0
	bl ov15_021FF6BC
	add r0, r5, #0
	bl ov15_021FA074
	add r2, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	mov r3, #1
	bl ov15_02200140
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov15_021FA6F4


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


	thumb_func_start ov15_021FA93C
ov15_021FA93C: ; 0x021FA93C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _021FAA10 ; =0x00000619
	add r4, r5, r0
	bl System_GetTouchHeld
	cmp r0, #0
	bne _021FA958
	ldrb r1, [r4, #7]
	mov r0, #0x70
	bic r1, r0
	mov r0, #0x10
	orr r0, r1
	strb r0, [r4, #7]
_021FA958:
	add r0, r5, #0
	bl ov15_021FAC40
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _021FA96E
	ldrb r0, [r4]
	cmp r6, r0
	beq _021FA97A
_021FA96E:
	ldrb r1, [r4, #7]
	mov r0, #0xf
	bic r1, r0
	mov r0, #1
	orr r0, r1
	strb r0, [r4, #7]
_021FA97A:
	add r0, r5, #0
	bl ov15_021FAA18
	cmp r0, #0
	bne _021FA9FE
	ldrb r0, [r4, #7]
	lsl r0, r0, #0x19
	lsr r0, r0, #0x1d
	cmp r0, #1
	bne _021FA9FE
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _021FA9FE
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrb r1, [r4]
	add r0, #0x64
	strb r1, [r0]
	lsl r0, r6, #0x18
	ldrb r1, [r4]
	lsr r0, r0, #0x18
	cmp r1, r0
	bls _021FA9B4
	mov r0, #0
	strb r0, [r4, #1]
	strb r0, [r4, #2]
	b _021FA9C6
_021FA9B4:
	cmp r1, r0
	bhs _021FA9C2
	mov r0, #1
	strb r0, [r4, #1]
	mov r0, #0
	strb r0, [r4, #2]
	b _021FA9C6
_021FA9C2:
	mov r0, #2
	strb r0, [r4, #1]
_021FA9C6:
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	strb r0, [r4]
	ldrb r2, [r4, #7]
	mov r1, #0xf
	bic r2, r1
	strb r2, [r4, #7]
	ldrb r2, [r4, #7]
	mov r1, #0x70
	bic r2, r1
	strb r2, [r4, #7]
	mov r1, #0
	strb r1, [r4, #4]
	mov r1, #0x67
	lsl r1, r1, #4
	strb r0, [r5, r1]
	add r0, r5, #0
	bl ov15_021FF950
	mov r1, #0x67
	lsl r1, r1, #4
	ldrb r1, [r5, r1]
	ldr r0, _021FAA14 ; =0x00000808
	mov r2, #7
	add r0, r5, r0
	add r1, r1, #1
	bl ov15_021FDAF4
_021FA9FE:
	add r0, r5, #0
	bl ov15_021FAB34
	add r0, r5, #0
	bl ov15_021FF964
	mov r0, #0
	pop {r4, r5, r6, pc}
	nop
_021FAA10: .word 0x00000619
_021FAA14: .word 0x00000808
	thumb_func_end ov15_021FA93C


	thumb_func_start ov15_021FAA18
ov15_021FAA18: ; 0x021FAA18
	push {r3, r4, r5, lr}
	ldr r1, _021FAB28 ; =gSystem
	add r5, r0, #0
	ldr r0, _021FAB2C ; =0x00000619
	ldr r2, [r1, #0x48]
	mov r1, #0x20
	add r4, r5, r0
	tst r1, r2
	beq _021FAAA6
	sub r1, r0, #5
	ldrb r1, [r5, r1]
	cmp r1, #1
	bne _021FAA36
	mov r0, #1
	pop {r3, r4, r5, pc}
_021FAA36:
	sub r0, #0x3d
	bl PlaySE
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrb r1, [r4]
	add r0, #0x64
	strb r1, [r0]
	ldrb r0, [r4]
	cmp r0, #0
	beq _021FAA5C
	sub r0, r0, #1
	strb r0, [r4]
	mov r0, #0x67
	lsl r0, r0, #4
	ldrb r1, [r5, r0]
	sub r1, r1, #1
	b _021FAA6A
_021FAA5C:
	ldr r0, _021FAB30 ; =0x00000614
	ldrb r1, [r5, r0]
	sub r1, r1, #1
	strb r1, [r4]
	ldrb r1, [r5, r0]
	add r0, #0x5c
	sub r1, r1, #1
_021FAA6A:
	strb r1, [r5, r0]
	mov r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #1]
	ldrb r1, [r4, #7]
	mov r0, #0x70
	bic r1, r0
	mov r0, #0x10
	orr r0, r1
	strb r0, [r4, #7]
	ldrb r1, [r4, #7]
	mov r0, #0xf
	bic r1, r0
	mov r0, #1
	orr r0, r1
	strb r0, [r4, #7]
	ldrb r1, [r4, #7]
	mov r0, #0x80
	bic r1, r0
	strb r1, [r4, #7]
	ldrb r0, [r4, #4]
	cmp r0, #3
	beq _021FAA9C
	mov r0, #4
	strb r0, [r4, #4]
_021FAA9C:
	add r0, r5, #0
	bl ov15_021FF950
	mov r0, #1
	pop {r3, r4, r5, pc}
_021FAAA6:
	mov r1, #0x10
	tst r1, r2
	beq _021FAB24
	sub r1, r0, #5
	ldrb r1, [r5, r1]
	cmp r1, #1
	bne _021FAAB8
	mov r0, #1
	pop {r3, r4, r5, pc}
_021FAAB8:
	sub r0, #0x3d
	bl PlaySE
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldrb r1, [r4]
	add r0, #0x64
	strb r1, [r0]
	ldrb r0, [r4]
	ldr r1, _021FAB30 ; =0x00000614
	add r2, r0, #1
	ldrb r0, [r5, r1]
	cmp r2, r0
	bge _021FAAE2
	add r0, r1, #0
	strb r2, [r4]
	add r0, #0x5c
	ldrb r0, [r5, r0]
	add r0, r0, #1
	b _021FAAE6
_021FAAE2:
	mov r0, #0
	strb r0, [r4]
_021FAAE6:
	add r1, #0x5c
	strb r0, [r5, r1]
	mov r0, #0
	strb r0, [r4, #2]
	mov r0, #1
	strb r0, [r4, #1]
	ldrb r2, [r4, #7]
	mov r1, #0x70
	bic r2, r1
	mov r1, #0x10
	orr r1, r2
	strb r1, [r4, #7]
	ldrb r2, [r4, #7]
	mov r1, #0xf
	bic r2, r1
	orr r0, r2
	strb r0, [r4, #7]
	ldrb r1, [r4, #7]
	mov r0, #0x80
	bic r1, r0
	strb r1, [r4, #7]
	ldrb r0, [r4, #4]
	cmp r0, #3
	beq _021FAB1A
	mov r0, #4
	strb r0, [r4, #4]
_021FAB1A:
	add r0, r5, #0
	bl ov15_021FF950
	mov r0, #1
	pop {r3, r4, r5, pc}
_021FAB24:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FAB28: .word gSystem
_021FAB2C: .word 0x00000619
_021FAB30: .word 0x00000614
	thumb_func_end ov15_021FAA18


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
