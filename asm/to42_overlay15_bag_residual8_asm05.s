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
