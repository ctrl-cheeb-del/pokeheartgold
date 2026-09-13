#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021F9DB4
	.public ov15_021F9EA8
	.public ov15_021F9F08
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021F9D8C
	.extern ov15_021F9D9C
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

	thumb_func_start ov15_021F9DB4
ov15_021F9DB4: ; 0x021F9DB4
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r7, r0]
	mov r5, #0
	add r1, #0x64
	strb r5, [r1]
	ldr r0, [r7, r0]
	add r4, r0, #4
	ldr r0, [r0, #0x6c]
	cmp r0, #0
	bne _021F9E12
	add r2, r5, #0
	mov r1, #0xc
_021F9DD2:
	add r0, r5, #0
	mul r0, r1
	add r3, r4, r0
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021F9DE2
	strh r2, [r3, #4]
	strh r2, [r3, #6]
_021F9DE2:
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #8
	blo _021F9DD2
	mov r2, #0
	mov r1, #0xc
_021F9DF0:
	add r0, r2, #0
	mul r0, r1
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021F9E06
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	add r0, #0x64
	strb r2, [r0]
	pop {r3, r4, r5, r6, r7, pc}
_021F9E06:
	add r0, r2, #1
	lsl r0, r0, #0x10
	lsr r2, r0, #0x10
	cmp r2, #8
	blo _021F9DF0
	pop {r3, r4, r5, r6, r7, pc}
_021F9E12:
	mov r0, #0xc
	mul r0, r5
	add r6, r4, r0
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _021F9E3E
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	ldrb r1, [r6, #8]
	add r2, sp, #0
	ldr r0, [r0, #0x6c]
	add r2, #1
	add r3, sp, #0
	bl BagCursor_Field_PocketGetPosition
	add r0, sp, #0
	ldrb r0, [r0, #1]
	strh r0, [r6, #4]
	add r0, sp, #0
	ldrb r0, [r0]
	strh r0, [r6, #6]
_021F9E3E:
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #8
	blo _021F9E12
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	ldr r0, [r0, #0x6c]
	bl BagCursor_Field_GetPocket
	mov r1, #0xc
	mul r1, r0
	ldr r1, [r4, r1]
	cmp r1, #0
	bne _021F9E7A
	mov r3, #0
	mov r2, #0xc
_021F9E62:
	add r1, r3, #0
	mul r1, r2
	ldr r1, [r4, r1]
	cmp r1, #0
	beq _021F9E70
	add r0, r3, #0
	b _021F9E7A
_021F9E70:
	add r1, r3, #1
	lsl r1, r1, #0x10
	lsr r3, r1, #0x10
	cmp r3, #8
	blo _021F9E62
_021F9E7A:
	mov r1, #0
	mov r2, #0xc
_021F9E7E:
	add r3, r1, #0
	mul r3, r2
	add r5, r4, r3
	ldr r3, [r4, r3]
	cmp r3, #0
	beq _021F9E9C
	ldrb r3, [r5, #8]
	cmp r0, r3
	bne _021F9E9C
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	add r0, #0x64
	strb r1, [r0]
	pop {r3, r4, r5, r6, r7, pc}
_021F9E9C:
	add r1, r1, #1
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	cmp r1, #8
	blo _021F9E7E
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov15_021F9DB4


	thumb_func_start ov15_021F9EA8
ov15_021F9EA8: ; 0x021F9EA8
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	ldr r0, [r1, #0x6c]
	cmp r0, #0
	beq _021F9F06
	add r0, r1, #4
	str r0, [sp]
	mov r4, #0
	add r5, r0, #0
	mov r7, #6
_021F9EC2:
	ldr r0, [r5]
	cmp r0, #0
	beq _021F9EE2
	mov r0, #0x8d
	lsl r0, r0, #2
	ldrh r2, [r5, #4]
	ldrsh r3, [r5, r7]
	ldr r0, [r6, r0]
	lsl r2, r2, #0x18
	lsl r3, r3, #0x18
	ldrb r1, [r5, #8]
	ldr r0, [r0, #0x6c]
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl BagCursor_Field_PocketSetPosition
_021F9EE2:
	add r4, r4, #1
	add r5, #0xc
	cmp r4, #8
	blo _021F9EC2
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r1, [r6, r0]
	ldr r0, [r1, #0x6c]
	add r1, #0x64
	ldrb r2, [r1]
	mov r1, #0xc
	add r3, r2, #0
	mul r3, r1
	ldr r1, [sp]
	add r1, r1, r3
	ldrb r1, [r1, #8]
	bl BagCursor_Field_SetPocket
_021F9F06:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov15_021F9EA8


	thumb_func_start ov15_021F9F08
ov15_021F9F08: ; 0x021F9F08
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r1, #0x8d
	lsl r1, r1, #2
	str r0, [sp]
	ldr r0, [r0, r1]
	add r2, r0, #4
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r4, r2, r0
	ldrb r1, [r4, #8]
	cmp r1, #3
	bne _021F9F82
	ldr r0, _021FA000 ; =ov15_022008B0
	mov r6, #0
	ldrb r0, [r0, r1]
	cmp r0, #0
	bls _021F9F7E
	ldr r0, [sp]
	add r5, r6, #0
	str r0, [sp, #4]
	add r7, r0, #0
_021F9F38:
	ldr r0, [r4]
	ldrh r3, [r0, r5]
	add r1, r0, r5
	cmp r3, #0
	beq _021F9F7E
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq _021F9F7E
	mov r0, #0xbf
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0x35
	ldr r2, [sp, #4]
	lsl r1, r1, #4
	ldr r1, [r2, r1]
	add r2, r3, #0
	mov r3, #6
	bl ov15_021F9D9C
	ldr r0, [r4]
	add r6, r6, #1
	ldrh r1, [r0, r5]
	ldr r0, _021FA004 ; =0x000006A4
	add r5, r5, #4
	strh r1, [r7, r0]
	ldr r0, [sp, #4]
	ldrb r1, [r4, #8]
	add r0, r0, #4
	str r0, [sp, #4]
	ldr r0, _021FA000 ; =ov15_022008B0
	add r7, r7, #2
	ldrb r0, [r0, r1]
	cmp r6, r0
	blo _021F9F38
_021F9F7E:
	strb r6, [r4, #9]
	b _021F9FDC
_021F9F82:
	ldr r0, _021FA000 ; =ov15_022008B0
	mov r6, #0
	ldrb r0, [r0, r1]
	cmp r0, #0
	bls _021F9FDA
	ldr r0, [sp]
	add r5, r6, #0
	str r0, [sp, #8]
	add r7, r0, #0
_021F9F94:
	ldr r0, [r4]
	ldrh r3, [r0, r5]
	add r1, r0, r5
	cmp r3, #0
	beq _021F9FDA
	ldrh r0, [r1, #2]
	cmp r0, #0
	beq _021F9FDA
	mov r0, #0xbe
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0x35
	ldr r2, [sp, #8]
	lsl r1, r1, #4
	ldr r1, [r2, r1]
	add r2, r3, #0
	mov r3, #6
	bl ov15_021F9D8C
	ldr r0, [r4]
	add r6, r6, #1
	ldrh r1, [r0, r5]
	ldr r0, _021FA004 ; =0x000006A4
	add r5, r5, #4
	strh r1, [r7, r0]
	ldr r0, [sp, #8]
	ldrb r1, [r4, #8]
	add r0, r0, #4
	str r0, [sp, #8]
	ldr r0, _021FA000 ; =ov15_022008B0
	add r7, r7, #2
	ldrb r0, [r0, r1]
	cmp r6, r0
	blo _021F9F94
_021F9FDA:
	strb r6, [r4, #9]
_021F9FDC:
	ldrb r0, [r4, #9]
	cmp r0, #0
	bne _021F9FE6
	mov r1, #0
	b _021F9FF2
_021F9FE6:
	sub r0, r0, #1
	mov r1, #6
	bl _s32_div_f
	mov r1, #6
	mul r1, r0
_021F9FF2:
	mov r0, #6
	ldrsh r0, [r4, r0]
	cmp r0, r1
	ble _021F9FFC
	strh r1, [r4, #6]
_021F9FFC:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021FA000: .word ov15_022008B0
_021FA004: .word 0x000006A4
	thumb_func_end ov15_021F9F08
