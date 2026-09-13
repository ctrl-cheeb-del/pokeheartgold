#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FC41C
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021FA074
	.extern ov15_021FA0E4
	.extern ov15_021FA104
	.extern ov15_021FA170
	.extern ov15_021FA68C
	.extern ov15_021FA6C0
	.extern ov15_021FA73C
	.extern ov15_021FAC2C
	.extern ov15_021FB518
	.extern ov15_021FB680
	.extern ov15_021FBC6C
	.extern ov15_021FBC8C
	.extern ov15_021FBCAC
	.extern ov15_021FBD28
	.extern ov15_021FC224
	.extern ov15_021FC37C
	.extern ov15_021FC3E0
	.extern ov15_021FC3EC
	.extern ov15_021FD3C0
	.extern ov15_021FD3F0
	.extern ov15_021FD43C
	.extern ov15_021FD574
	.extern ov15_021FD774
	.extern ov15_021FD788
	.extern ov15_021FD7D0
	.extern ov15_021FD810
	.extern ov15_021FE17C
	.extern ov15_021FE1D0
	.extern ov15_021FE204
	.extern ov15_021FE3E0
	.extern ov15_021FE584
	.extern ov15_021FE5A4
	.extern ov15_021FE5C4
	.extern ov15_021FE620
	.extern ov15_021FE868

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
	thumb_func_start ov15_021FC41C
ov15_021FC41C: ; 0x021FC41C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r1, _021FC70C ; =gSystem
	mov r2, #0x40
	ldr r3, [r1, #0x4c]
	add r5, r0, #0
	mov r4, #0
	tst r2, r3
	beq _021FC43E
	ldr r0, _021FC710 ; =0x00000644
	add r4, r4, #1
	ldr r1, [r5, r0]
	lsl r2, r1, #2
	ldr r1, _021FC714 ; =ov15_02200640
	ldrb r1, [r1, r2]
	str r1, [r5, r0]
	b _021FC56E
_021FC43E:
	mov r2, #0x80
	tst r2, r3
	beq _021FC454
	ldr r0, _021FC710 ; =0x00000644
	add r4, r4, #1
	ldr r1, [r5, r0]
	lsl r2, r1, #2
	ldr r1, _021FC718 ; =ov15_02200641
	ldrb r1, [r1, r2]
	str r1, [r5, r0]
	b _021FC56E
_021FC454:
	mov r2, #0x20
	add r6, r3, #0
	tst r6, r2
	beq _021FC4AC
	ldr r1, _021FC710 ; =0x00000644
	ldr r3, _021FC71C ; =ov15_02200642
	ldr r1, [r5, r1]
	lsl r6, r1, #2
	ldrb r3, [r3, r6]
	cmp r3, #0xe
	bne _021FC484
	mov r1, #2
	str r1, [sp]
	mov r1, #0xe
	add r2, sp, #0xc
	add r3, r4, #0
	str r4, [sp, #4]
	bl ov15_021FA73C
	cmp r0, #1
	bne _021FC4D6
	add sp, #0x10
	mov r0, #0xe
	pop {r4, r5, r6, pc}
_021FC484:
	cmp r1, #0x10
	beq _021FC56E
	cmp r1, #0
	blt _021FC4A4
	cmp r1, #8
	bge _021FC4A4
	sub r2, #0x21
	bl ov15_021FA6C0
	ldr r1, _021FC710 ; =0x00000644
	ldr r2, [r5, r1]
	cmp r2, r0
	beq _021FC56E
	str r0, [r5, r1]
	add r4, r4, #1
	b _021FC56E
_021FC4A4:
	ldr r0, _021FC710 ; =0x00000644
	add r4, r4, #1
	str r3, [r5, r0]
	b _021FC56E
_021FC4AC:
	mov r2, #0x10
	tst r3, r2
	beq _021FC506
	ldr r1, _021FC710 ; =0x00000644
	ldr r2, _021FC720 ; =ov15_02200643
	ldr r1, [r5, r1]
	lsl r3, r1, #2
	ldrb r2, [r2, r3]
	cmp r2, #0xf
	bne _021FC4DE
	mov r1, #2
	str r1, [sp]
	add r2, sp, #8
	mov r1, #0xf
	add r2, #3
	add r3, r4, #0
	str r4, [sp, #4]
	bl ov15_021FA73C
	cmp r0, #1
	beq _021FC4D8
_021FC4D6:
	b _021FC77A
_021FC4D8:
	add sp, #0x10
	mov r0, #0xe
	pop {r4, r5, r6, pc}
_021FC4DE:
	cmp r1, #0x10
	beq _021FC56E
	cmp r1, #0
	blt _021FC4FE
	cmp r1, #8
	bge _021FC4FE
	mov r2, #1
	bl ov15_021FA6C0
	ldr r1, _021FC710 ; =0x00000644
	ldr r2, [r5, r1]
	cmp r2, r0
	beq _021FC56E
	str r0, [r5, r1]
	add r4, r4, #1
	b _021FC56E
_021FC4FE:
	ldr r0, _021FC710 ; =0x00000644
	add r4, r4, #1
	str r2, [r5, r0]
	b _021FC56E
_021FC506:
	ldr r3, [r1, #0x48]
	lsl r1, r2, #5
	tst r1, r3
	beq _021FC53A
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	sub r2, #0x11
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_021FA6C0
	add r1, r0, #0
	mov r0, #2
	str r0, [sp]
	add r0, r4, #0
	add r2, sp, #8
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, #2
	mov r3, #1
	bl ov15_021FA73C
	add sp, #0x10
	mov r0, #0xe
	pop {r4, r5, r6, pc}
_021FC53A:
	add r2, #0xf0
	add r1, r3, #0
	tst r1, r2
	beq _021FC56E
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r2, #1
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_021FA6C0
	add r1, r0, #0
	mov r0, #2
	str r0, [sp]
	add r0, r4, #0
	add r2, sp, #8
	str r0, [sp, #4]
	add r0, r5, #0
	add r2, #1
	mov r3, #1
	bl ov15_021FA73C
	add sp, #0x10
	mov r0, #0xe
	pop {r4, r5, r6, pc}
_021FC56E:
	ldr r1, _021FC710 ; =0x00000644
	ldr r0, [r5, r1]
	cmp r0, #0x11
	bne _021FC582
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x64
	ldrb r0, [r0]
	str r0, [r5, r1]
_021FC582:
	cmp r4, #0
	beq _021FC5A6
	ldr r0, _021FC724 ; =0x000005DC
	bl PlaySE
	ldr r1, _021FC710 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	ldr r1, _021FC710 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FA0E4
	add r0, r5, #0
	bl ov15_021FA170
_021FC5A6:
	mov r1, #0
	add r0, sp, #8
	strb r1, [r0]
	add r0, r5, #0
	bl ov15_021FAC2C
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	beq _021FC630
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_021FA104
	cmp r0, #0
	beq _021FC608
	cmp r4, #8
	bhs _021FC5EA
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_021FA68C
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _021FC608
	ldr r1, _021FC710 ; =0x00000644
	add r0, r5, #0
	str r4, [r5, r1]
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	b _021FC608
_021FC5EA:
	ldr r1, _021FC710 ; =0x00000644
	add r0, r5, #0
	str r4, [r5, r1]
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	ldr r0, _021FC710 ; =0x00000644
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FC608
	cmp r1, #0xd
	bgt _021FC608
	add r0, r5, #0
	bl ov15_021FA0E4
_021FC608:
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r4, #0
	add r2, sp, #8
	mov r3, #0
	bl ov15_021FA73C
	cmp r0, #1
	beq _021FC6B4
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r2, #4
	add r1, #0x68
	strh r2, [r1]
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FC630:
	ldr r0, _021FC70C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _021FC678
	mov r0, #2
	str r0, [sp]
	mov r3, #0
	ldr r1, _021FC710 ; =0x00000644
	str r3, [sp, #4]
	ldr r1, [r5, r1]
	add r0, r5, #0
	add r2, sp, #8
	bl ov15_021FA73C
	add r4, r0, #0
	ldr r0, _021FC710 ; =0x00000644
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FC662
	cmp r1, #0xd
	bgt _021FC662
	add r0, r5, #0
	bl ov15_021FA0E4
_021FC662:
	cmp r4, #1
	beq _021FC6B4
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #4
	add r0, #0x68
	strh r1, [r0]
	add sp, #0x10
	add r0, r4, #0
	pop {r4, r5, r6, pc}
_021FC678:
	mov r0, #2
	tst r1, r0
	beq _021FC6B4
	str r0, [sp]
	mov r3, #0
	add r0, r5, #0
	mov r1, #0x10
	add r2, sp, #8
	str r3, [sp, #4]
	bl ov15_021FA73C
	add r4, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #4
	add r0, #0x68
	strh r1, [r0]
	ldr r0, _021FC710 ; =0x00000644
	ldr r1, [r5, r0]
	cmp r1, #8
	blt _021FC6AE
	cmp r1, #0xd
	bgt _021FC6AE
	add r0, r5, #0
	bl ov15_021FA0E4
_021FC6AE:
	add sp, #0x10
	add r0, r4, #0
	pop {r4, r5, r6, pc}
_021FC6B4:
	add r0, sp, #8
	ldrb r0, [r0]
	cmp r0, #1
	bne _021FC778
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	add r0, #0x66
	ldrh r0, [r0]
	mov r2, #6
	bl GetItemAttr
	cmp r0, #0
	bne _021FC6E4
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x66
	ldrh r0, [r0]
	bl ItemIdIsNotJohtoBall
	cmp r0, #0
	bne _021FC75C
_021FC6E4:
	mov r2, #0xbd
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	sub r2, #0xc0
	ldr r2, [r5, r2]
	mov r1, #0
	add r2, #0x66
	ldrh r2, [r2]
	bl BufferItemName
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x2f
	bl NewString_ReadMsgData
	add r4, r0, #0
	mov r0, #0xbd
	ldr r1, _021FC728 ; =0x000005E4
	b _021FC72C
	.balign 4, 0
_021FC70C: .word gSystem
_021FC710: .word 0x00000644
_021FC714: .word ov15_02200640
_021FC718: .word ov15_02200641
_021FC71C: .word ov15_02200642
_021FC720: .word ov15_02200643
_021FC724: .word 0x000005DC
_021FC728: .word 0x000005E4
_021FC72C:
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r4, #0
	bl String_Delete
	add r0, r5, #0
	mov r1, #0
	bl ov15_021FEF48
	ldr r1, _021FC780 ; =0x00000616
	add sp, #0x10
	strb r0, [r5, r1]
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #5
	add r0, #0x68
	strh r1, [r0]
	mov r0, #0xf
	pop {r4, r5, r6, pc}
_021FC75C:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #4
	add r0, #0x68
	strh r1, [r0]
	add r0, r5, #0
	mov r1, #0x14
	mov r2, #0x29
	mov r3, #0x24
	bl ov15_021FD810
	add sp, #0x10
	pop {r4, r5, r6, pc}
_021FC778:
	mov r0, #0xe
_021FC77A:
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_021FC780: .word 0x00000616
	thumb_func_end ov15_021FC41C
