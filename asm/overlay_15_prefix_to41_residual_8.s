#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FAD80
	.public ov15_021FAE48
	.public ov15_021FAFFC
	.public ov15_021FB060
	.public ov15_021FB14C
	.public ov15_021FB518
	.public ov15_021FB5AC
	.public ov15_021FB604
	.public ov15_021FB654
	.public ov15_021FB700
	.extern BagApp_TryUseItemInPlace
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021F9F08
	.extern ov15_021FA074
	.extern ov15_021FA098
	.extern ov15_021FA0E4
	.extern ov15_021FAC2C
	.extern ov15_021FB830
	.extern ov15_021FBBB0
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

	thumb_func_start ov15_021FAC48
ov15_021FAC48: ; 0x021FAC48
	push {r3, r4, r5, lr}
	mov r1, #0x8d
	add r5, r0, #0
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	add r3, r1, #4
	add r1, #0x64
	ldrb r2, [r1]
	mov r1, #0xc
	mul r1, r2
	add r3, r3, r1
	ldr r1, _021FAD20 ; =0x00000671
	mov r2, #1
	strb r2, [r5, r1]
	mov r2, #6
	ldrsh r3, [r3, r2]
	add r2, r1, #0
	sub r2, #0x2d
	ldr r2, [r5, r2]
	add r1, r1, #1
	add r2, r3, r2
	sub r2, #8
	strb r2, [r5, r1]
	bl ov15_021FED60
	add r0, r5, #0
	bl ov15_021FB114
	add r0, r5, #0
	bl ov15_02200294
	add r0, r5, #0
	bl ov15_021FF560
	mov r0, #0x61
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov15_021FF7AC
	add r0, r5, #0
	bl ov15_021FED58
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r0, #4
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r4, r2, r0
	add r0, r5, #0
	bl ov15_021FA074
	ldr r3, _021FAD24 ; =0x00000644
	add r2, r0, #0
	ldr r3, [r5, r3]
	add r0, r5, #0
	mov r1, #1
	sub r3, #8
	bl ov15_021FD574
	ldr r2, _021FAD24 ; =0x00000644
	mov r1, #6
	ldr r2, [r5, r2]
	ldrsh r1, [r4, r1]
	add r0, r5, #0
	sub r2, #8
	mov r3, #1
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
	mov r3, #0
	bl ov15_02200140
	mov r2, #6
	ldrsh r3, [r4, r2]
	ldr r2, _021FAD24 ; =0x00000644
	add r0, r5, #0
	ldr r2, [r5, r2]
	add r1, r4, #0
	add r2, r3, r2
	sub r2, #8
	bl ov15_022001C4
	ldr r1, _021FAD24 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	ldr r0, _021FAD24 ; =0x00000644
	ldr r1, [r5, r0]
	add r0, #0x28
	sub r1, #8
	str r1, [r5, r0]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FAD20: .word 0x00000671
_021FAD24: .word 0x00000644
	thumb_func_end ov15_021FAC48


	thumb_func_start ov15_021FAD28
ov15_021FAD28: ; 0x021FAD28
	ldr r1, _021FAD6C ; =gSystem
	mov r2, #0x40
	ldr r1, [r1, #0x48]
	tst r2, r1
	beq _021FAD3C
	lsl r1, r0, #2
	ldr r0, _021FAD70 ; =ov15_02200584
	ldrb r0, [r0, r1]
	sub r0, #8
	bx lr
_021FAD3C:
	mov r2, #0x80
	tst r2, r1
	beq _021FAD4C
	lsl r1, r0, #2
	ldr r0, _021FAD74 ; =ov15_02200585
	ldrb r0, [r0, r1]
	sub r0, #8
	bx lr
_021FAD4C:
	mov r2, #0x20
	tst r2, r1
	beq _021FAD5C
	lsl r1, r0, #2
	ldr r0, _021FAD78 ; =ov15_02200586
	ldrb r0, [r0, r1]
	sub r0, #8
	bx lr
_021FAD5C:
	mov r2, #0x10
	tst r1, r2
	beq _021FAD6A
	lsl r1, r0, #2
	ldr r0, _021FAD7C ; =ov15_02200587
	ldrb r0, [r0, r1]
	sub r0, #8
_021FAD6A:
	bx lr
	.balign 4, 0
_021FAD6C: .word gSystem
_021FAD70: .word ov15_02200584
_021FAD74: .word ov15_02200585
_021FAD78: .word ov15_02200586
_021FAD7C: .word ov15_02200587
	thumb_func_end ov15_021FAD28


	thumb_func_start ov15_021FAD80
ov15_021FAD80: ; 0x021FAD80
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov15_021FA074
	add r6, r0, #0
	add r0, r5, #0
	bl ov15_021FA098
	add r3, r0, #0
	add r0, r5, #0
	mov r1, #1
	add r2, r6, #0
	bl ov15_021FD574
	add r0, r5, #0
	bl ov15_021FA098
	mov r1, #6
	add r2, r0, #0
	ldrsh r1, [r4, r1]
	add r0, r5, #0
	mov r3, #1
	bl ov15_021FF364
	ldr r2, _021FADE4 ; =0x00000672
	add r0, r5, #0
	ldrb r2, [r5, r2]
	add r1, r4, #0
	bl ov15_022001C4
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r3, [r5, r0]
	add r0, r3, #0
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	add r2, r1, #0
	mul r2, r0
	add r3, r3, r2
	mov r2, #0xa
	ldrb r1, [r3, #0xd]
	ldrsh r2, [r3, r2]
	add r0, r5, #0
	mov r3, #0
	bl ov15_021FF6BC
	pop {r4, r5, r6, pc}
	nop
_021FADE4: .word 0x00000672
	thumb_func_end ov15_021FAD80


	thumb_func_start ov15_021FADE8
ov15_021FADE8: ; 0x021FADE8
	push {r4, r5, r6, lr}
	mov r4, #0
	add r5, r1, #0
	add r6, r0, #0
	mvn r4, r4
	cmp r5, #8
	bhi _021FAE3A
	add r1, r5, r5
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021FAE02: ; jump table
	.short _021FAE14 - _021FAE02 - 2 ; case 0
	.short _021FAE14 - _021FAE02 - 2 ; case 1
	.short _021FAE14 - _021FAE02 - 2 ; case 2
	.short _021FAE14 - _021FAE02 - 2 ; case 3
	.short _021FAE14 - _021FAE02 - 2 ; case 4
	.short _021FAE14 - _021FAE02 - 2 ; case 5
	.short _021FAE30 - _021FAE02 - 2 ; case 6
	.short _021FAE34 - _021FAE02 - 2 ; case 7
	.short _021FAE38 - _021FAE02 - 2 ; case 8
_021FAE14:
	bl ov15_021FA074
	cmp r0, r5
	ble _021FAE28
	ldr r0, _021FAE40 ; =0x0000066C
	ldr r4, [r6, r0]
	sub r0, #0x90
	bl PlaySE
	b _021FAE3A
_021FAE28:
	ldr r0, _021FAE44 ; =0x000005F3
	bl PlaySE
	b _021FAE3A
_021FAE30:
	mov r4, #0xe
	b _021FAE3A
_021FAE34:
	mov r4, #0xf
	b _021FAE3A
_021FAE38:
	sub r4, r4, #1
_021FAE3A:
	add r0, r4, #0
	pop {r4, r5, r6, pc}
	nop
_021FAE40: .word 0x0000066C
_021FAE44: .word 0x000005F3
	thumb_func_end ov15_021FADE8


	thumb_func_start ov15_021FAE48
ov15_021FAE48: ; 0x021FAE48
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r4, #0
	add r2, r0, #4
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mvn r4, r4
	mul r0, r1
	add r7, r2, r0
	ldr r0, _021FAFE4 ; =0x0000066C
	ldr r0, [r5, r0]
	bl ov15_021FAD28
	lsl r0, r0, #0x10
	ldr r2, _021FAFE4 ; =0x0000066C
	lsr r1, r0, #0x10
	ldr r0, [r5, r2]
	cmp r0, r1
	beq _021FAE9C
	ldr r0, _021FAFE8 ; =0x0000FFFA
	add r0, r1, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	cmp r0, #1
	bhi _021FAE8C
	add r0, r5, #0
	bl ov15_021FADE8
	add r4, r0, #0
	b _021FAE9C
_021FAE8C:
	str r1, [r5, r2]
	ldr r1, [r5, r2]
	add r0, r5, #0
	bl ov15_021FFF34
	ldr r0, _021FAFEC ; =0x000005DC
	bl PlaySE
_021FAE9C:
	add r0, r5, #0
	mov r1, #2
	bl ov15_021FAC2C
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _021FAF04
	cmp r6, #8
	bne _021FAEC6
	add r0, r5, #0
	add r1, r6, #0
	bl ov15_021FADE8
	add r4, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	bl ov15_021FFF34
	b _021FAF24
_021FAEC6:
	sub r0, r6, #6
	cmp r0, #1
	bhi _021FAED8
	add r0, r5, #0
	add r1, r6, #0
	bl ov15_021FADE8
	add r4, r0, #0
	b _021FAF24
_021FAED8:
	ldr r0, _021FAFE4 ; =0x0000066C
	str r6, [r5, r0]
	add r0, r5, #0
	bl ov15_021FA074
	cmp r0, r6
	bls _021FAEF2
	add r0, r5, #0
	add r1, r6, #0
	bl ov15_021FADE8
	add r4, r0, #0
	b _021FAEF8
_021FAEF2:
	ldr r0, _021FAFF0 ; =0x000005F3
	bl PlaySE
_021FAEF8:
	ldr r1, _021FAFE4 ; =0x0000066C
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FFF34
	b _021FAF24
_021FAF04:
	ldr r0, _021FAFF4 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _021FAF1C
	ldr r1, _021FAFE4 ; =0x0000066C
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FADE8
	add r4, r0, #0
	b _021FAF24
_021FAF1C:
	mov r0, #2
	tst r1, r0
	beq _021FAF24
	sub r4, r0, #4
_021FAF24:
	mov r0, #1
	mvn r0, r0
	cmp r4, r0
	bhi _021FAF3E
	bhs _021FAF46
	cmp r4, #0xf
	bhi _021FAFAC
	cmp r4, #0xe
	blo _021FAFAC
	beq _021FAF70
	cmp r4, #0xf
	beq _021FAF8E
	b _021FAFAC
_021FAF3E:
	add r0, r0, #1
	cmp r4, r0
	beq _021FAFE0
	b _021FAFAC
_021FAF46:
	mov r0, #SEQ_SE_GS_GEARCANCEL>>6
	lsl r0, r0, #6
	bl PlaySE
	ldr r0, _021FAFF8 ; =0x00000672
	mov r1, #6
	ldrb r0, [r5, r0]
	bl _s32_div_f
	mov r1, #6
	mul r1, r0
	strh r1, [r7, #6]
	mov r0, #0x20
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0x13
	mov r2, #9
	mov r3, #8
	bl ov15_021FD7D0
	pop {r3, r4, r5, r6, r7, pc}
_021FAF70:
	ldrb r0, [r7, #9]
	cmp r0, #6
	bls _021FAFE0
	ldr r0, _021FAFEC ; =0x000005DC
	bl PlaySE
	mov r0, #0x1f
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0x11
	mov r2, #9
	mov r3, #8
	bl ov15_021FD7D0
	pop {r3, r4, r5, r6, r7, pc}
_021FAF8E:
	ldrb r0, [r7, #9]
	cmp r0, #6
	bls _021FAFE0
	ldr r0, _021FAFEC ; =0x000005DC
	bl PlaySE
	mov r0, #0x1e
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0x12
	mov r2, #9
	mov r3, #8
	bl ov15_021FD7D0
	pop {r3, r4, r5, r6, r7, pc}
_021FAFAC:
	ldr r0, _021FAFEC ; =0x000005DC
	bl PlaySE
	ldr r1, _021FAFF8 ; =0x00000672
	mov r2, #6
	ldrb r0, [r5, r1]
	sub r1, r1, #6
	ldrsh r2, [r7, r2]
	ldr r1, [r5, r1]
	add r1, r2, r1
	cmp r0, r1
	bne _021FAFD2
	add r0, r5, #0
	mov r1, #0x14
	mov r2, #0x29
	mov r3, #0x21
	bl ov15_021FD810
	pop {r3, r4, r5, r6, r7, pc}
_021FAFD2:
	add r0, r5, #0
	mov r1, #0x14
	mov r2, #0x2a
	mov r3, #0x21
	bl ov15_021FD810
	pop {r3, r4, r5, r6, r7, pc}
_021FAFE0:
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FAFE4: .word 0x0000066C
_021FAFE8: .word 0x0000FFFA
_021FAFEC: .word 0x000005DC
_021FAFF0: .word 0x000005F3
_021FAFF4: .word gSystem
_021FAFF8: .word 0x00000672
	thumb_func_end ov15_021FAE48


	thumb_func_start ov15_021FAFFC
ov15_021FAFFC: ; 0x021FAFFC
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r4, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	add r0, r1, #0
	add r0, #0x64
	ldrb r3, [r0]
	mov r0, #0xc
	add r1, r1, #4
	mul r0, r3
	add r5, r1, r0
	mov r0, #6
	ldr r1, _021FB05C ; =0x0000066C
	ldrsh r6, [r5, r0]
	ldr r2, [r4, r1]
	add r1, r1, #6
	add r2, r6, r2
	lsl r2, r2, #0x10
	ldrb r1, [r4, r1]
	lsr r2, r2, #0x10
	cmp r1, r2
	beq _021FB050
	str r0, [sp]
	ldr r0, [r5]
	bl MoveItemSlotInList
	add r0, r4, #0
	bl ov15_021F9F08
	ldr r1, _021FB05C ; =0x0000066C
	ldr r2, [r4, r1]
	add r0, r1, #0
	add r2, #8
	sub r0, #0x28
	str r2, [r4, r0]
	sub r1, #0x28
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov15_021FA0E4
_021FB050:
	add r0, r4, #0
	bl ov15_021FB060
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_021FB05C: .word 0x0000066C
	thumb_func_end ov15_021FAFFC


	thumb_func_start ov15_021FB060
ov15_021FB060: ; 0x021FB060
	push {r3, r4, r5, lr}
	mov r1, #0xd2
	add r5, r0, #0
	mov r3, #0
	lsl r1, r1, #2
	str r3, [r5, r1]
	ldr r1, _021FB10C ; =0x00000671
	strb r3, [r5, r1]
	add r2, r1, #1
	strb r3, [r5, r2]
	add r1, r1, #3
	str r3, [r5, r1]
	bl ov15_021FB114
	add r0, r5, #0
	bl ov15_021F9F08
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r0, #4
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r4, r2, r0
	add r0, r5, #0
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
	add r0, r5, #0
	bl ov15_021FED24
	ldr r1, _021FB110 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_021FB10C: .word 0x00000671
_021FB110: .word 0x00000644
	thumb_func_end ov15_021FB060


	thumb_func_start ov15_021FB114
ov15_021FB114: ; 0x021FB114
	push {r4, lr}
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r2, [r0, r1]
	add r4, r2, #4
	add r2, #0x64
	ldrb r3, [r2]
	mov r2, #0xc
	mul r2, r3
	add r3, r4, r2
	ldr r2, _021FB148 ; =0x00000671
	ldrb r2, [r0, r2]
	cmp r2, #0
	beq _021FB146
	ldrh r2, [r3, #4]
	add r1, #0x1c
	ldr r0, [r0, r1]
	sub r2, r2, #1
	lsl r2, r2, #4
	add r2, #0x10
	lsl r2, r2, #0x10
	mov r1, #0xb1
	asr r2, r2, #0x10
	bl ManagedSprite_SetPositionXY
_021FB146:
	pop {r4, pc}
	.balign 4, 0
_021FB148: .word 0x00000671
	thumb_func_end ov15_021FB114


	thumb_func_start ov15_021FB14C
ov15_021FB14C: ; 0x021FB14C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r1, _021FB370 ; =_022004EC
	add r4, r0, #0
	ldrb r2, [r1]
	add r0, sp, #0
	strb r2, [r0]
	ldrb r2, [r1, #1]
	strb r2, [r0, #1]
	ldrb r2, [r1, #2]
	strb r2, [r0, #2]
	ldrb r2, [r1, #3]
	ldrb r1, [r1, #4]
	strb r2, [r0, #3]
	strb r1, [r0, #4]
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, #0x66
	ldrh r0, [r0]
	mov r2, #6
	bl LoadItemDataOrGfx
	add r7, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	add r3, r4, #0
	add r0, r2, #0
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r0, r2, r0
	ldrb r5, [r0, #0xc]
	mov r2, #0
	mov r0, #0x7f
	add r1, r2, #0
	lsl r0, r0, #4
_021FB19C:
	add r2, r2, #1
	str r1, [r3, r0]
	add r3, r3, #4
	cmp r2, #5
	blt _021FB19C
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	add r0, r1, #0
	add r0, #0x65
	ldrb r0, [r0]
	cmp r0, #0
	beq _021FB1B8
	b _021FB2F8
_021FB1B8:
	add r0, r1, #0
	add r0, #0x76
	ldrh r0, [r0]
	lsl r0, r0, #0x10
	lsr r2, r0, #0x11
	ldr r0, _021FB374 ; =0x0000FFFE
	add r0, r2, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	cmp r0, #1
	bhi _021FB1E8
	add r0, r1, #0
	add r0, #0x64
	ldrb r2, [r0]
	mov r0, #0xc
	mul r0, r2
	add r0, r1, r0
	ldrb r0, [r0, #0xc]
	cmp r0, #5
	bne _021FB280
	mov r1, #2
	add r0, sp, #0
	strb r1, [r0]
	b _021FB280
_021FB1E8:
	add r0, r7, #0
	mov r1, #6
	bl GetItemAttr_PreloadedItemData
	cmp r0, #0
	beq _021FB280
	mov r2, #0x8d
	lsl r2, r2, #2
	ldr r1, [r4, r2]
	sub r2, #0x72
	add r0, r1, #0
	add r0, #0x66
	ldrh r0, [r0]
	cmp r0, r2
	bne _021FB21C
	add r2, r1, #0
	add r2, #0x76
	ldrh r2, [r2]
	lsl r2, r2, #0x1f
	lsr r2, r2, #0x1f
	cmp r2, #1
	bne _021FB21C
	mov r1, #1
	add r0, sp, #0
	strb r1, [r0]
	b _021FB280
_021FB21C:
	add r2, r1, #0
	add r2, #0x64
	ldrb r3, [r2]
	mov r2, #0xc
	mul r2, r3
	add r2, r1, r2
	ldrb r3, [r2, #0xc]
	cmp r3, #5
	bne _021FB236
	mov r1, #2
	add r0, sp, #0
	strb r1, [r0]
	b _021FB280
_021FB236:
	ldr r2, _021FB378 ; =0x000001C1
	cmp r0, r2
	bne _021FB244
	mov r1, #4
	add r0, sp, #0
	strb r1, [r0]
	b _021FB280
_021FB244:
	cmp r3, #4
	bne _021FB25A
	ldr r0, [r1, #0x70]
	bl Leftover_CanPlantBerry
	cmp r0, #1
	bne _021FB25A
	mov r1, #3
	add r0, sp, #0
	strb r1, [r0]
	b _021FB280
_021FB25A:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	sub r0, #0x3e
	add r1, #0x66
	ldrh r1, [r1]
	cmp r1, r0
	bne _021FB27A
	bl SoundSys_GetGBSoundsState
	cmp r0, #1
	bne _021FB27A
	mov r1, #0xf
	add r0, sp, #0
	strb r1, [r0]
	b _021FB280
_021FB27A:
	mov r1, #0
	add r0, sp, #0
	strb r1, [r0]
_021FB280:
	add r0, r7, #0
	mov r1, #3
	bl GetItemAttr_PreloadedItemData
	cmp r0, #0
	bne _021FB2AE
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x66
	ldrh r0, [r0]
	bl ItemIdIsNotJohtoBall
	cmp r0, #1
	bne _021FB2A4
	mov r1, #8
	add r0, sp, #0
	strb r1, [r0, #2]
_021FB2A4:
	cmp r5, #3
	beq _021FB2AE
	mov r1, #5
	add r0, sp, #0
	strb r1, [r0, #1]
_021FB2AE:
	add r0, r7, #0
	mov r1, #4
	bl GetItemAttr_PreloadedItemData
	cmp r0, #0
	beq _021FB310
	mov r0, #0x8e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Bag_GetRegisteredItem1
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	add r2, #0x66
	ldrh r2, [r2]
	cmp r2, r0
	beq _021FB2E8
	add r0, r1, #4
	ldr r0, [r4, r0]
	bl Bag_GetRegisteredItem2
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r1, #0x66
	ldrh r1, [r1]
	cmp r1, r0
	bne _021FB2F0
_021FB2E8:
	mov r1, #7
	add r0, sp, #0
	strb r1, [r0, #1]
	b _021FB310
_021FB2F0:
	mov r1, #6
	add r0, sp, #0
	strb r1, [r0, #1]
	b _021FB310
_021FB2F8:
	cmp r0, #6
	bne _021FB310
	add r1, #0x66
	ldrh r1, [r1]
	add r0, r5, #0
	bl ov15_021FD3F0
	cmp r0, #1
	bne _021FB310
	mov r1, #0xe
	add r0, sp, #0
	strb r1, [r0]
_021FB310:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x65
	ldrb r0, [r0]
	cmp r0, #6
	beq _021FB32C
	cmp r5, #3
	beq _021FB32C
	cmp r5, #4
	beq _021FB32C
	mov r1, #0xc
	add r0, sp, #0
	strb r1, [r0, #3]
_021FB32C:
	mov r3, #0x7f
	mov r1, #0xb
	add r0, sp, #0
	strb r1, [r0, #4]
	ldr r6, _021FB37C ; =ov15_02201368
	mov r2, #0
	add r0, sp, #0
	add r1, r4, #0
	lsl r3, r3, #4
_021FB33E:
	ldrb r5, [r0]
	cmp r5, #0xff
	beq _021FB34A
	lsl r5, r5, #2
	ldr r5, [r6, r5]
	str r5, [r1, r3]
_021FB34A:
	add r2, r2, #1
	add r0, r0, #1
	add r1, r1, #4
	cmp r2, #5
	blt _021FB33E
	add r0, r4, #0
	add r1, sp, #0
	mov r2, #5
	bl ov15_021FEB84
	add r0, r4, #0
	add r1, sp, #0
	bl ov15_021FB380
	add r0, r7, #0
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021FB370: .word _022004EC
_021FB374: .word 0x0000FFFE
_021FB378: .word 0x000001C1
_021FB37C: .word ov15_02201368
	thumb_func_end ov15_021FB14C


	thumb_func_start ov15_021FB380
ov15_021FB380: ; 0x021FB380
	push {r3, r4, r5, lr}
	add r4, r1, #0
	ldr r1, _021FB3E8 ; =0x0000066C
	add r5, r0, #0
	mov r2, #0
	str r2, [r5, r1]
	ldr r2, [r5, r1]
	ldr r1, _021FB3EC ; =ov15_02201468
	ldrb r1, [r1, r2]
	bl ov15_021FFECC
	add r0, r5, #0
	add r1, r4, #0
	bl ov15_0220023C
	mov r0, #0x61
	mov r1, #3
	lsl r0, r0, #2
	lsl r1, r1, #8
	ldrb r2, [r4]
	add r0, r5, r0
	add r1, r5, r1
	bl ov15_021FF758
	mov r0, #0x65
	mov r1, #3
	lsl r0, r0, #2
	lsl r1, r1, #8
	ldrb r2, [r4, #1]
	add r0, r5, r0
	add r1, r5, r1
	bl ov15_021FF758
	mov r0, #0x69
	mov r1, #3
	lsl r0, r0, #2
	lsl r1, r1, #8
	ldrb r2, [r4, #2]
	add r0, r5, r0
	add r1, r5, r1
	bl ov15_021FF758
	mov r0, #0x6d
	mov r1, #3
	lsl r0, r0, #2
	lsl r1, r1, #8
	ldrb r2, [r4, #3]
	add r0, r5, r0
	add r1, r5, r1
	bl ov15_021FF758
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FB3E8: .word 0x0000066C
_021FB3EC: .word ov15_02201468
	thumb_func_end ov15_021FB380


	thumb_func_start ov15_021FB3F0
ov15_021FB3F0: ; 0x021FB3F0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _021FB4F8 ; =0x0000066C
	mov r2, #0x40
	ldr r1, [r5, r0]
	ldr r0, _021FB4FC ; =gSystem
	add r4, r1, #0
	ldr r0, [r0, #0x48]
	tst r2, r0
	beq _021FB40C
	ldr r0, _021FB500 ; =ov15_02200528
	lsl r2, r1, #2
	ldrb r4, [r0, r2]
	b _021FB434
_021FB40C:
	mov r2, #0x80
	tst r2, r0
	beq _021FB41A
	ldr r0, _021FB504 ; =ov15_02200529
	lsl r2, r1, #2
	ldrb r4, [r0, r2]
	b _021FB434
_021FB41A:
	mov r2, #0x20
	tst r2, r0
	beq _021FB428
	ldr r0, _021FB508 ; =ov15_0220052A
	lsl r2, r1, #2
	ldrb r4, [r0, r2]
	b _021FB434
_021FB428:
	mov r2, #0x10
	tst r0, r2
	beq _021FB434
	ldr r0, _021FB50C ; =ov15_0220052B
	lsl r2, r1, #2
	ldrb r4, [r0, r2]
_021FB434:
	cmp r4, r1
	beq _021FB452
	ldr r0, _021FB4F8 ; =0x0000066C
	ldr r1, _021FB510 ; =ov15_02201468
	str r4, [r5, r0]
	ldrb r1, [r1, r4]
	add r0, r5, #0
	bl ov15_021FFECC
	ldr r0, _021FB514 ; =0x000005DC
	bl PlaySE
	mov r0, #0
	mvn r0, r0
	pop {r4, r5, r6, pc}
_021FB452:
	add r0, r5, #0
	mov r1, #1
	bl ov15_021FAC2C
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _021FB4A4
	add r0, r5, #0
	mov r1, #1
	bl ov15_021FD774
	ldr r0, _021FB4F8 ; =0x0000066C
	ldr r1, _021FB510 ; =ov15_02201468
	str r6, [r5, r0]
	ldrb r1, [r1, r6]
	add r0, r5, #0
	bl ov15_021FFECC
	cmp r6, #4
	bne _021FB48C
	mov r0, #SEQ_SE_GS_GEARCANCEL>>6
	lsl r0, r0, #6
	bl PlaySE
	mov r0, #1
	mvn r0, r0
	pop {r4, r5, r6, pc}
_021FB48C:
	lsl r0, r6, #2
	add r1, r5, r0
	mov r0, #0x7f
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _021FB4F2
	ldr r0, _021FB514 ; =0x000005DC
	bl PlaySE
	add r0, r6, #0
	pop {r4, r5, r6, pc}
_021FB4A4:
	ldr r0, _021FB4FC ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _021FB4DE
	lsl r0, r4, #2
	add r1, r5, r0
	mov r0, #0x7f
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _021FB4CE
	ldr r0, _021FB514 ; =0x000005DC
	bl PlaySE
	add r0, r5, #0
	mov r1, #0
	bl ov15_021FD774
	add r0, r4, #0
	pop {r4, r5, r6, pc}
_021FB4CE:
	cmp r4, #4
	bne _021FB4F2
	ldr r0, _021FB514 ; =0x000005DC
	bl PlaySE
	mov r0, #1
	mvn r0, r0
	pop {r4, r5, r6, pc}
_021FB4DE:
	mov r0, #2
	tst r0, r1
	beq _021FB4F2
	mov r0, #SEQ_SE_GS_GEARCANCEL>>6
	lsl r0, r0, #6
	bl PlaySE
	mov r0, #1
	mvn r0, r0
	pop {r4, r5, r6, pc}
_021FB4F2:
	mov r0, #0
	mvn r0, r0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021FB4F8: .word 0x0000066C
_021FB4FC: .word gSystem
_021FB500: .word ov15_02200528
_021FB504: .word ov15_02200529
_021FB508: .word ov15_0220052A
_021FB50C: .word ov15_0220052B
_021FB510: .word ov15_02201468
_021FB514: .word 0x000005DC
	thumb_func_end ov15_021FB3F0


	thumb_func_start ov15_021FB518
ov15_021FB518: ; 0x021FB518
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl ov15_021F9F08
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r2, r0, #4
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r4, r2, r0
	add r0, r5, #0
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
	mov r3, #0
	bl ov15_02200140
	ldr r1, _021FB5A8 ; =0x00000644
	add r0, r5, #0
	ldr r1, [r5, r1]
	bl ov15_021FFECC
	add r0, r5, #0
	mov r1, #1
	bl ov15_021F9C78
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FB5A8: .word 0x00000644
	thumb_func_end ov15_021FB518


	thumb_func_start ov15_021FB5AC
ov15_021FB5AC: ; 0x021FB5AC
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	bl ov15_021FB3F0
	add r1, r0, #0
	mov r0, #1
	mvn r0, r0
	cmp r1, r0
	beq _021FB5C8
	add r0, r0, #1
	cmp r1, r0
	beq _021FB5F8
	b _021FB5DC
_021FB5C8:
	mov r0, #0x1c
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x13
	mov r2, #9
	mov r3, #8
	bl ov15_021FD7D0
	add sp, #4
	pop {r3, r4, pc}
_021FB5DC:
	ldr r0, _021FB600 ; =0x00000948
	mov r2, #9
	str r1, [r4, r0]
	add r1, #0x1c
	mov r0, #0x1d
	lsl r1, r1, #0x18
	str r0, [sp]
	add r0, r4, #0
	lsr r1, r1, #0x18
	mov r3, #8
	bl ov15_021FD7D0
	add sp, #4
	pop {r3, r4, pc}
_021FB5F8:
	mov r0, #4
	add sp, #4
	pop {r3, r4, pc}
	nop
_021FB600: .word 0x00000948
	thumb_func_end ov15_021FB5AC


	thumb_func_start ov15_021FB604
ov15_021FB604: ; 0x021FB604
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl ov15_02200294
	add r0, r5, #0
	bl ov15_021FF560
	mov r0, #0x61
	lsl r0, r0, #2
	add r0, r5, r0
	bl ov15_021FF7AC
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r4, [r5, r0]
	add r0, r5, #0
	bl ov15_021FA074
	add r1, r4, #4
	add r4, #0x64
	add r2, r0, #0
	ldrb r4, [r4]
	mov r3, #0xc
	add r0, r5, #0
	mul r3, r4
	add r1, r1, r3
	mov r3, #0
	bl ov15_02200140
	add r0, r5, #0
	bl ov15_021FE868
	add r0, r5, #0
	bl ov15_021FED3C
	add r0, r5, #0
	bl ov15_021FB518
	mov r0, #1
	pop {r3, r4, r5, pc}
	thumb_func_end ov15_021FB604


	thumb_func_start ov15_021FB654
ov15_021FB654: ; 0x021FB654
	push {r4, lr}
	add r4, r0, #0
	bl ov15_02200294
	mov r0, #0x61
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov15_021FF7AC
	ldr r1, _021FB67C ; =0x00000948
	add r0, r4, #0
	ldr r1, [r4, r1]
	lsl r1, r1, #2
	add r2, r4, r1
	mov r1, #0x7f
	lsl r1, r1, #4
	ldr r1, [r2, r1]
	blx r1
	pop {r4, pc}
	nop
_021FB67C: .word 0x00000948
	thumb_func_end ov15_021FB654


	thumb_func_start ov15_021FB680
ov15_021FB680: ; 0x021FB680
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	mov r1, #0
	bl ov15_021FD788
	add r0, r4, #0
	bl ov15_021FFF24
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #6
	add r0, #0x66
	ldrh r0, [r0]
	add r2, r1, #0
	bl GetItemAttr
	add r1, r0, #0
	lsl r1, r1, #0x10
	mov r0, #2
	lsr r1, r1, #0x10
	bl GetItemFieldUseFunc
	add r1, r0, #0
	beq _021FB6EE
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r0, [r0, #0x70]
	blx r1
	add r3, r0, #0
	beq _021FB6EE
	mov r2, #0x8f
	mov r0, #6
	lsl r2, r2, #2
	str r0, [sp]
	ldr r0, [r4, r2]
	sub r2, #8
	ldr r2, [r4, r2]
	ldr r1, _021FB6F8 ; =0x000005E4
	add r2, #0x66
	ldrh r2, [r2]
	ldr r1, [r4, r1]
	bl GetItemUseErrorMessage
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FEF48
	ldr r1, _021FB6FC ; =0x00000616
	add sp, #4
	strb r0, [r4, r1]
	mov r0, #0xc
	pop {r3, r4, pc}
_021FB6EE:
	add r0, r4, #0
	bl ov15_021FB784
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_021FB6F8: .word 0x000005E4
_021FB6FC: .word 0x00000616
	thumb_func_end ov15_021FB680


	thumb_func_start ov15_021FB700
ov15_021FB700: ; 0x021FB700
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _021FB778 ; =0x00000616
	ldrb r0, [r4, r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021FB772
	ldr r0, _021FB77C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	bne _021FB722
	ldr r0, _021FB780 ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	beq _021FB772
_021FB722:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x65
	ldrb r0, [r0]
	cmp r0, #3
	beq _021FB736
	add r0, r4, #0
	bl ov15_021FED3C
_021FB736:
	add r0, r4, #0
	add r0, #0x34
	mov r1, #1
	bl ClearFrameAndWindow2
	add r0, r4, #0
	add r0, #0x34
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #4
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	mov r1, #1
	bl ov15_021FD788
	add r0, r4, #0
	bl ov15_021FB518
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x65
	ldrb r0, [r0]
	cmp r0, #3
	bne _021FB76E
	mov r0, #0x1a
	pop {r4, pc}
_021FB76E:
	mov r0, #1
	pop {r4, pc}
_021FB772:
	mov r0, #0xc
	pop {r4, pc}
	nop
_021FB778: .word 0x00000616
_021FB77C: .word gSystem
_021FB780: .word gSystem + 0x40
	thumb_func_end ov15_021FB700


	thumb_func_start ov15_021FB784
ov15_021FB784: ; 0x021FB784
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	add r3, r1, #4
	add r1, #0x64
	ldrb r2, [r1]
	mov r1, #0xc
	mul r1, r2
	add r3, r3, r1
	ldr r1, _021FB80C ; =0x0000067B
	mov r2, #0
	strb r2, [r4, r1]
	ldrb r2, [r3, #8]
	cmp r2, #3
	bne _021FB7B0
	ldr r2, _021FB810 ; =ov15_021FB830
	add r0, r1, #1
	str r2, [r4, r0]
	mov r0, #0xd
	pop {r4, pc}
_021FB7B0:
	ldr r2, [r4, r0]
	sub r1, #0x97
	ldr r0, [r2]
	add r2, #0x66
	ldrh r2, [r2]
	ldr r1, [r4, r1]
	mov r3, #6
	bl TryFormatRegisteredKeyItemUseMessage
	cmp r0, #1
	bne _021FB7D6
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FEF48
	ldr r1, _021FB814 ; =0x00000616
	strb r0, [r4, r1]
	mov r0, #0xc
	pop {r4, pc}
_021FB7D6:
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	add r1, #0x66
	ldrh r1, [r1]
	bl BagApp_TryUseItemInPlace
	cmp r0, #1
	bne _021FB7F4
	ldr r1, _021FB818 ; =ov15_021FBBB0
	ldr r0, _021FB81C ; =0x0000067C
	str r1, [r4, r0]
	mov r0, #0xd
	pop {r4, pc}
_021FB7F4:
	mov r0, #1
	mov r1, #6
	bl sub_020880CC
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r0, #0x68
	strh r1, [r0]
	mov r0, #0x25
	pop {r4, pc}
	.balign 4, 0
_021FB80C: .word 0x0000067B
_021FB810: .word ov15_021FB830
_021FB814: .word 0x00000616
_021FB818: .word ov15_021FBBB0
_021FB81C: .word 0x0000067C
	thumb_func_end ov15_021FB784
