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

	.public ov15_021FAC48
	.public ov15_021FAD28
	.public ov15_021FAD80
	.public ov15_021FADE8
	.public ov15_021FAE48
	.public ov15_021FAFFC
	.public ov15_021FB060
	.public ov15_021FB114
	.public ov15_021FB14C
	.public ov15_021FB380
	.public ov15_021FB3F0
	.public ov15_021FB518
	.public ov15_021FB5AC
	.public ov15_021FB604
	.public ov15_021FB654
	.public ov15_021FB680
	.public ov15_021FB700
	.public ov15_021FB784

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
