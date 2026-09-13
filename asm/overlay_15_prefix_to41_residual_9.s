#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public BagApp_TryUseItemInPlace
	.public ov15_021FB830
	.extern BagApp_GetRepelStepCountAddr
	.extern BagApp_GetSaveRoamers
	.extern BagApp_SetFlute
	.extern BagApp_ToggleGBSounds
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

	thumb_func_start ov15_021FB830
ov15_021FB830: ; 0x021FB830
	push {r3, r4, r5, lr}
	ldr r1, _021FB9C0 ; =0x0000067B
	add r4, r0, #0
	ldrb r0, [r4, r1]
	cmp r0, #3
	bhi _021FB936
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021FB848: ; jump table
	.short _021FB850 - _021FB848 - 2 ; case 0
	.short _021FB8AC - _021FB848 - 2 ; case 1
	.short _021FB90C - _021FB848 - 2 ; case 2
	.short _021FB926 - _021FB848 - 2 ; case 3
_021FB850:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x66
	ldrh r0, [r0]
	bl TMHMGetMove
	add r5, r0, #0
	mov r0, #0xbd
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	add r2, r5, #0
	bl BufferMoveName
	add r0, r5, #0
	bl MoveIsHM
	cmp r0, #1
	ldr r2, _021FB9C4 ; =0x000005E4
	bne _021FB88A
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	ldr r2, [r4, r2]
	mov r1, #0x3c
	bl ReadMsgDataIntoString
	b _021FB898
_021FB88A:
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	ldr r2, [r4, r2]
	mov r1, #0x3b
	bl ReadMsgDataIntoString
_021FB898:
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FEF48
	ldr r1, _021FB9C8 ; =0x00000616
	strb r0, [r4, r1]
	mov r0, #1
	add r1, #0x65
	strb r0, [r4, r1]
	b _021FB9BA
_021FB8AC:
	sub r1, #0x65
	ldrb r0, [r4, r1]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021FB936
	ldr r0, _021FB9CC ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	bne _021FB8CA
	ldr r0, _021FB9D0 ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	beq _021FB9BA
_021FB8CA:
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x3d
	bl NewString_ReadMsgData
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0x34
	mov r1, #0xf
	bl FillWindowPixelBuffer
	mov r0, #0xbd
	ldr r1, _021FB9C4 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FEF48
	ldr r1, _021FB9C8 ; =0x00000616
	strb r0, [r4, r1]
	mov r0, #2
	add r1, #0x65
	strb r0, [r4, r1]
	b _021FB9BA
_021FB90C:
	sub r1, #0x65
	ldrb r0, [r4, r1]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _021FB9BA
	add r0, r4, #0
	bl ov15_021FF004
	ldr r0, _021FB9C0 ; =0x0000067B
	mov r1, #3
	strb r1, [r4, r0]
	b _021FB9BA
_021FB926:
	ldr r0, _021FB9D4 ; =0x00000804
	ldr r0, [r4, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _021FB938
	cmp r0, #2
	beq _021FB956
_021FB936:
	b _021FB9BA
_021FB938:
	add r0, r4, #0
	bl ov15_021FF058
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
	pop {r3, r4, r5, pc}
_021FB956:
	add r0, r4, #0
	bl ov15_021FF058
	add r0, r4, #0
	bl ov15_021FED3C
	add r0, r4, #0
	add r0, #0x34
	mov r1, #1
	bl ClearFrameAndWindow2
	add r0, r4, #0
	add r0, #0x34
	bl ClearWindowTilemapAndScheduleTransfer
	add r0, r4, #4
	bl ScheduleWindowCopyToVram
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r5, [r4, r0]
	add r0, r4, #0
	bl ov15_021FA074
	add r1, r5, #4
	add r5, #0x64
	add r2, r0, #0
	ldrb r5, [r5]
	mov r3, #0xc
	add r0, r4, #0
	mul r3, r5
	add r1, r1, r3
	mov r3, #0
	bl ov15_02200140
	add r0, r4, #0
	bl ov15_021FE868
	add r0, r4, #0
	bl ov15_02200294
	add r0, r4, #0
	bl ov15_021FB518
	add r0, r4, #0
	mov r1, #1
	bl ov15_021FD788
	mov r0, #1
	pop {r3, r4, r5, pc}
_021FB9BA:
	mov r0, #0xd
	pop {r3, r4, r5, pc}
	nop
_021FB9C0: .word 0x0000067B
_021FB9C4: .word 0x000005E4
_021FB9C8: .word 0x00000616
_021FB9CC: .word gSystem
_021FB9D0: .word gSystem + 0x40
_021FB9D4: .word 0x00000804
	thumb_func_end ov15_021FB830


	thumb_func_start BagApp_TryUseItemInPlace
BagApp_TryUseItemInPlace: ; 0x021FB9D8
	push {r3, r4, r5, lr}
	mov r2, #0xbd
	add r4, r0, #0
	lsl r2, r2, #2
	ldr r0, [r4, r2]
	sub r2, #0xb8
	add r5, r1, #0
	ldr r2, [r4, r2]
	mov r1, #0
	bl BufferPlayersName
	mov r0, #0xbd
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	add r2, r5, #0
	bl BufferItemName
	cmp r5, #ITEM_BLACK_FLUTE
	bne _021FBA20
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #msg_0010_00065
	bl NewString_ReadMsgData
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #1
	bl BagApp_SetFlute
	mov r0, #0x1a
	mov r1, #0
	lsl r0, r0, #6
	strh r1, [r4, r0]
	b _021FBA7A
_021FBA20:
	cmp r5, #ITEM_WHITE_FLUTE
	bne _021FBA44
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #msg_0010_00064
	bl NewString_ReadMsgData
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #2
	bl BagApp_SetFlute
	mov r0, #0x1a
	mov r1, #0
	lsl r0, r0, #6
	strh r1, [r4, r0]
	b _021FBA7A
_021FBA44:
	cmp r5, #ITEM_MAX_REPEL
	beq _021FBA50
	cmp r5, #ITEM_SUPER_REPEL
	beq _021FBA50
	cmp r5, #ITEM_REPEL
	bne _021FBA5C
_021FBA50:
	add r0, r4, #0
	add r1, r5, #0
	bl BagApp_TryUseRepel
	add r5, r0, #0
	b _021FBA7A
_021FBA5C:
	ldr r0, _021FBA94 ; =ITEM_GB_SOUNDS
	cmp r5, r0
	bne _021FBA76
	add r0, r4, #0
	add r1, r5, #0
	bl BagApp_ToggleGBSounds
	add r5, r0, #0
	mov r0, #0x1a
	mov r1, #0
	lsl r0, r0, #6
	strh r1, [r4, r0]
	b _021FBA7A
_021FBA76:
	mov r0, #0
	pop {r3, r4, r5, pc}
_021FBA7A:
	mov r0, #0xbd
	ldr r1, _021FBA98 ; =0x000005E4
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldr r1, [r4, r1]
	add r2, r5, #0
	bl StringExpandPlaceholders
	add r0, r5, #0
	bl String_Delete
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FBA94: .word ITEM_GB_SOUNDS
_021FBA98: .word 0x000005E4
	thumb_func_end BagApp_TryUseItemInPlace


	thumb_func_start BagApp_TryUseRepel
BagApp_TryUseRepel: ; 0x021FBA9C
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r5, r1, #0
	bl BagApp_GetSaveRoamers
	bl RoamerSave_RepelNotInUse
	cmp r0, #0
	bne _021FBAC4
	mov r0, #0x1a
	mov r1, #0
	lsl r0, r0, #6
	strh r1, [r4, r0]
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #msg_0010_00063
	bl NewString_ReadMsgData
	pop {r3, r4, r5, pc}
_021FBAC4:
	add r0, r5, #0
	mov r1, #2
	mov r2, #6
	bl GetItemAttr
	add r1, r0, #0
	lsl r1, r1, #0x18
	add r0, r4, #0
	lsr r1, r1, #0x18
	bl BagApp_GetRepelStepCountAddr
	mov r0, #0x680>>6
	mov r1, #1
	lsl r0, r0, #6
	strh r1, [r4, r0]
	sub r0, #0x680-SEQ_SE_DP_CARD2
	bl PlaySE
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #msg_0010_00062
	bl NewString_ReadMsgData
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end BagApp_TryUseRepel
