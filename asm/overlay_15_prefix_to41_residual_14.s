#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FC01C
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021FA074
	.extern ov15_021FB518
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
	.extern ov15_021FD788
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

	thumb_func_start ov15_021FC01C
ov15_021FC01C: ; 0x021FC01C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, _021FC134 ; =0x00000804
	ldr r0, [r5, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _021FC03A
	cmp r0, #2
	beq _021FC0CE
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	b _021FC12E
_021FC03A:
	add r0, r5, #0
	bl ov15_021FF058
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x36
	bl NewString_ReadMsgData
	add r4, r0, #0
	mov r0, #0x1a
	lsl r0, r0, #6
	ldrsh r0, [r5, r0]
	cmp r0, #1
	bne _021FC06E
	mov r2, #0xbd
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	sub r2, #0xc0
	ldr r2, [r5, r2]
	mov r1, #0
	add r2, #0x66
	ldrh r2, [r2]
	bl BufferItemName
	b _021FC082
_021FC06E:
	mov r2, #0xbd
	lsl r2, r2, #2
	ldr r0, [r5, r2]
	sub r2, #0xc0
	ldr r2, [r5, r2]
	mov r1, #0
	add r2, #0x66
	ldrh r2, [r2]
	bl BufferItemNamePlural
_021FC082:
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	mov r2, #0x1a
	mov r0, #0xbd
	str r1, [sp, #4]
	lsl r2, r2, #6
	lsl r0, r0, #2
	ldrsh r2, [r5, r2]
	ldr r0, [r5, r0]
	mov r3, #3
	bl BufferIntegerAsString
	mov r0, #0xbd
	ldr r1, _021FC138 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl StringExpandPlaceholders
	add r0, r4, #0
	bl String_Delete
	add r0, r5, #0
	add r0, #0x34
	mov r1, #0xf
	bl FillWindowPixelBuffer
	add r0, r5, #0
	mov r1, #0
	bl ov15_021FEF48
	ldr r1, _021FC13C ; =0x00000616
	add sp, #8
	strb r0, [r5, r1]
	mov r0, #0xa
	pop {r3, r4, r5, pc}
_021FC0CE:
	add r0, r5, #0
	bl ov15_021FF058
	add r0, r5, #0
	add r0, #0x34
	mov r1, #1
	bl ClearFrameAndWindow2
	add r0, r5, #0
	add r0, #0x34
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r5, #4
	bl ScheduleWindowCopyToVram
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
	mov r1, #1
	bl ov15_021FD788
	add r0, r5, #0
	bl ov15_021FB518
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, pc}
_021FC12E:
	mov r0, #9
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FC134: .word 0x00000804
_021FC138: .word 0x000005E4
_021FC13C: .word 0x00000616
	thumb_func_end ov15_021FC01C
