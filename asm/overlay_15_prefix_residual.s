#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.extern BagApp_GetSaveStructPtrs
	.extern ov15_021F995C
	.extern ov15_021F9984
	.extern ov15_021F99A4
	.extern ov15_021F9A8C
	.extern ov15_021F9AE4
	.extern ov15_021F9C78
	.extern ov15_021F9CBC
	.extern ov15_021F9D28
	.extern ov15_021F9DB4
	.extern ov15_021F9EA8
	.extern ov15_021F9F08
	.extern ov15_021FA008
	.extern ov15_021FA028
	.extern ov15_021FA044
	.extern ov15_021FA070
	.extern ov15_021FA074
	.extern ov15_021FA0D8
	.extern ov15_021FA170
	.extern ov15_021FA1BC
	.extern ov15_021FA4F8
	.extern ov15_021FA578
	.extern ov15_021FA620
	.extern ov15_021FA93C
	.extern ov15_021FAE48
	.extern ov15_021FAFFC
	.extern ov15_021FB060
	.extern ov15_021FB5AC
	.extern ov15_021FB604
	.extern ov15_021FB654
	.extern ov15_021FB680
	.extern ov15_021FB700
	.extern ov15_021FB820
	.extern ov15_021FBC6C
	.extern ov15_021FBC8C
	.extern ov15_021FBCAC
	.extern ov15_021FBD50
	.extern ov15_021FBF98
	.extern ov15_021FBFC0
	.extern ov15_021FBFF8
	.extern ov15_021FC01C
	.extern ov15_021FC140
	.extern ov15_021FC164
	.extern ov15_021FC224
	.extern ov15_021FC2E0
	.extern ov15_021FC37C
	.extern ov15_021FC3E0
	.extern ov15_021FC3EC
	.extern ov15_021FC41C
	.extern ov15_021FC784
	.extern ov15_021FC7EC
	.extern ov15_021FCB64
	.extern ov15_021FCD80
	.extern ov15_021FCDE4
	.extern ov15_021FCFC8
	.extern ov15_021FD058
	.extern ov15_021FD0E8
	.extern ov15_021FD10C
	.extern ov15_021FD24C
	.extern ov15_021FD2FC
	.extern ov15_021FD3AC
	.extern ov15_021FD3C0
	.extern ov15_021FD3F0
	.extern ov15_021FD404
	.extern ov15_021FD574
	.extern ov15_021FD850
	.extern ov15_021FD93C
	.extern ov15_021FDC6C
	.extern ov15_021FDC88
	.extern ov15_021FE020
	.extern ov15_021FE154
	.extern ov15_021FE17C
	.extern ov15_021FE1D0
	.extern ov15_021FE204
	.extern ov15_021FE3E0
	.extern ov15_021FE4C8
	.extern ov15_021FE504
	.extern ov15_021FE528
	.extern ov15_021FE584
	.extern ov15_021FE5A4
	.extern ov15_021FE5C4
	.extern ov15_021FE620
	.extern ov15_021FE874
	.extern ov15_021FE8A4

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

	thumb_func_start Bag_Init
Bag_Init: ; 0x021F9380
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r0, #1
	lsl r0, r0, #0x1a
	ldr r2, [r0]
	ldr r1, _021F95EC ; =0xFFFFE0FF
	ldr r3, _021F95F0 ; =0x04001000
	and r2, r1
	str r2, [r0]
	ldr r2, [r3]
	add r0, #0x50
	and r1, r2
	str r1, [r3]
	mov r1, #0
	strh r1, [r0]
	add r3, #0x50
	mov r2, #0x42
	strh r1, [r3]
	mov r0, #3
	mov r1, #6
	lsl r2, r2, #0xc
	bl Heap_Create
	ldr r1, _021F95F4 ; =0x0000094C
	add r0, r5, #0
	mov r2, #6
	bl OverlayManager_CreateAndGetData
	ldr r2, _021F95F4 ; =0x0000094C
	mov r1, #0
	add r4, r0, #0
	bl memset
	add r0, r5, #0
	bl OverlayManager_GetArgs
	mov r1, #0x8d
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r0, r4, #0
	bl BagApp_GetSaveStructPtrs
	mov r0, #6
	bl BgConfig_Alloc
	str r0, [r4]
	mov r0, #0x8f
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl PlayerProfile_GetTrainerGender
	ldr r1, _021F95F8 ; =0x00000615
	mov r3, #0
	strb r0, [r4, r1]
	mov r1, #6
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r1, #3
	mov r0, #2
	add r2, r1, #0
	bl BeginNormalPaletteFade
	mov r0, #3
	mov r1, #8
	bl SetKeyRepeatTimers
	add r0, r4, #0
	bl ov15_021F9DB4
	add r0, r4, #0
	bl ov15_021F9CBC
	add r0, r4, #0
	bl ov15_021FA008
	add r0, r4, #0
	bl ov15_021F9D28
	add r0, r4, #0
	bl ov15_021FA620
	bl ov15_021F9984
	ldr r0, [r4]
	bl ov15_021F99A4
	add r0, r4, #0
	bl ov15_021F9AE4
	bl sub_020210BC
	mov r0, #4
	bl sub_02021148
	add r0, r4, #0
	bl ov15_021FE020
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	add r0, r4, #0
	bl ov15_021FE4C8
	add r0, r4, #0
	bl ov15_021FE528
	add r0, r4, #0
	bl ov15_021FEA5C
	add r0, r4, #0
	bl ov15_021FE874
	add r0, r4, #0
	bl ov15_021F9F08
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FF29C
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r3, [r4, r0]
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
	ldr r3, [r4, r0]
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
	add r0, r4, #0
	bl ov15_021FF850
	add r0, r4, #0
	bl ov15_021FA074
	mov r1, #0
	add r2, r0, #0
	add r0, r4, #0
	add r3, r1, #0
	bl ov15_021FD574
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r3, [r4, r0]
	add r0, r4, #0
	add r1, r3, #0
	add r1, #0x64
	ldrb r2, [r1]
	mov r1, #0xc
	mul r1, r2
	add r1, r3, r1
	mov r2, #0xa
	ldrsh r1, [r1, r2]
	sub r2, #0xb
	mov r3, #0
	bl ov15_021FF364
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	add r0, r4, #0
	add r1, #0x64
	ldrb r1, [r1]
	bl ov15_02200030
	mov r2, #0x8d
	lsl r2, r2, #2
	ldr r2, [r4, r2]
	add r0, r4, #0
	add r2, #0x64
	ldrb r2, [r2]
	mov r1, #1
	bl ov15_021FD404
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r3, [r4, r0]
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
	add r0, r4, #0
	mov r3, #0
	bl ov15_021FF6BC
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
	mov r3, #1
	bl ov15_02200140
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	add r0, r2, #0
	add r0, #0x64
	ldrb r1, [r0]
	mov r0, #0xc
	mul r0, r1
	add r0, r2, r0
	ldrh r0, [r0, #8]
	ldr r1, _021F95FC ; =0x00000644
	add r0, #8
	str r0, [r4, r1]
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov15_021FFECC
	add r0, r4, #0
	bl ov15_021FA170
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r0, #0x65
	ldrb r0, [r0]
	add r0, #0xfc
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #1
	bhi _021F95B6
	add r0, r4, #0
	bl ov15_021FF1E0
_021F95B6:
	add r0, r4, #0
	bl ov15_021FD93C
	ldr r0, _021F9600 ; =ov15_021F995C
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r1, #0
	mov r0, #0x33
	add r2, r1, #0
	bl Sound_SetSceneAndPlayBGM
	bl sub_0203A964
	ldr r2, _021F9604 ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	mov r0, #4
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, pc}
	nop
_021F95EC: .word 0xFFFFE0FF
_021F95F0: .word 0x04001000
_021F95F4: .word 0x0000094C
_021F95F8: .word 0x00000615
_021F95FC: .word 0x00000644
_021F9600: .word ov15_021F995C
_021F9604: .word 0x04000304
	thumb_func_end Bag_Init


	thumb_func_start Bag_Main
Bag_Main: ; 0x021F9608
	push {r3, r4, r5, lr}
	add r4, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r4]
	add r5, r0, #0
	cmp r1, #0x25
	bhi _021F96B8
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021F9624: ; jump table
	.short _021F9670 - _021F9624 - 2 ; case 0
	.short _021F96A8 - _021F9624 - 2 ; case 1
	.short _021F96B0 - _021F9624 - 2 ; case 2
	.short _021F96E8 - _021F9624 - 2 ; case 3
	.short _021F96F0 - _021F9624 - 2 ; case 4
	.short _021F96F8 - _021F9624 - 2 ; case 5
	.short _021F9700 - _021F9624 - 2 ; case 6
	.short _021F9708 - _021F9624 - 2 ; case 7
	.short _021F9710 - _021F9624 - 2 ; case 8
	.short _021F9718 - _021F9624 - 2 ; case 9
	.short _021F9720 - _021F9624 - 2 ; case 10
	.short _021F9728 - _021F9624 - 2 ; case 11
	.short _021F9730 - _021F9624 - 2 ; case 12
	.short _021F9738 - _021F9624 - 2 ; case 13
	.short _021F9740 - _021F9624 - 2 ; case 14
	.short _021F9748 - _021F9624 - 2 ; case 15
	.short _021F9750 - _021F9624 - 2 ; case 16
	.short _021F9758 - _021F9624 - 2 ; case 17
	.short _021F9760 - _021F9624 - 2 ; case 18
	.short _021F9768 - _021F9624 - 2 ; case 19
	.short _021F9770 - _021F9624 - 2 ; case 20
	.short _021F9778 - _021F9624 - 2 ; case 21
	.short _021F9780 - _021F9624 - 2 ; case 22
	.short _021F9788 - _021F9624 - 2 ; case 23
	.short _021F9790 - _021F9624 - 2 ; case 24
	.short _021F97A0 - _021F9624 - 2 ; case 25
	.short _021F9798 - _021F9624 - 2 ; case 26
	.short _021F97A8 - _021F9624 - 2 ; case 27
	.short _021F97B0 - _021F9624 - 2 ; case 28
	.short _021F97B8 - _021F9624 - 2 ; case 29
	.short _021F97C0 - _021F9624 - 2 ; case 30
	.short _021F97CA - _021F9624 - 2 ; case 31
	.short _021F97D6 - _021F9624 - 2 ; case 32
	.short _021F97DE - _021F9624 - 2 ; case 33
	.short _021F97E6 - _021F9624 - 2 ; case 34
	.short _021F97EE - _021F9624 - 2 ; case 35
	.short _021F97F6 - _021F9624 - 2 ; case 36
	.short _021F9804 - _021F9624 - 2 ; case 37
_021F9670:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021F96B8
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x65
	ldrb r0, [r0]
	cmp r0, #1
	beq _021F9696
	cmp r0, #2
	beq _021F9690
	cmp r0, #3
	beq _021F969C
	b _021F96A2
_021F9690:
	mov r0, #0x10
	str r0, [r4]
	b _021F9810
_021F9696:
	mov r0, #0xe
	str r0, [r4]
	b _021F9810
_021F969C:
	mov r0, #0x1a
	str r0, [r4]
	b _021F9810
_021F96A2:
	mov r0, #1
	str r0, [r4]
	b _021F9810
_021F96A8:
	bl ov15_021FA1BC
	str r0, [r4]
	b _021F9810
_021F96B0:
	bl ov15_021FA93C
	cmp r0, #1
	beq _021F96BA
_021F96B8:
	b _021F9810
_021F96BA:
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x65
	ldrb r0, [r0]
	cmp r0, #2
	bne _021F96CE
	mov r0, #0x10
	str r0, [r4]
	b _021F9810
_021F96CE:
	cmp r0, #1
	bne _021F96D8
	mov r0, #0xe
	str r0, [r4]
	b _021F9810
_021F96D8:
	cmp r0, #3
	bne _021F96E2
	mov r0, #0x1a
	str r0, [r4]
	b _021F9810
_021F96E2:
	mov r0, #1
	str r0, [r4]
	b _021F9810
_021F96E8:
	bl ov15_021FAE48
	str r0, [r4]
	b _021F9810
_021F96F0:
	bl ov15_021FB5AC
	str r0, [r4]
	b _021F9810
_021F96F8:
	bl ov15_021FBD50
	str r0, [r4]
	b _021F9810
_021F9700:
	bl ov15_021FBF98
	str r0, [r4]
	b _021F9810
_021F9708:
	bl ov15_021FBFC0
	str r0, [r4]
	b _021F9810
_021F9710:
	bl ov15_021FBFF8
	str r0, [r4]
	b _021F9810
_021F9718:
	bl ov15_021FC01C
	str r0, [r4]
	b _021F9810
_021F9720:
	bl ov15_021FC140
	str r0, [r4]
	b _021F9810
_021F9728:
	bl ov15_021FC164
	str r0, [r4]
	b _021F9810
_021F9730:
	bl ov15_021FB700
	str r0, [r4]
	b _021F9810
_021F9738:
	bl ov15_021FB820
	str r0, [r4]
	b _021F9810
_021F9740:
	bl ov15_021FC41C
	str r0, [r4]
	b _021F9810
_021F9748:
	bl ov15_021FC784
	str r0, [r4]
	b _021F9810
_021F9750:
	bl ov15_021FC7EC
	str r0, [r4]
	b _021F9810
_021F9758:
	bl ov15_021FCD80
	str r0, [r4]
	b _021F9810
_021F9760:
	bl ov15_021FCDE4
	str r0, [r4]
	b _021F9810
_021F9768:
	bl ov15_021FCFC8
	str r0, [r4]
	b _021F9810
_021F9770:
	bl ov15_021FD058
	str r0, [r4]
	b _021F9810
_021F9778:
	bl ov15_021FD0E8
	str r0, [r4]
	b _021F9810
_021F9780:
	bl ov15_021FD10C
	str r0, [r4]
	b _021F9810
_021F9788:
	bl ov15_021FD24C
	str r0, [r4]
	b _021F9810
_021F9790:
	bl ov15_021FD2FC
	str r0, [r4]
	b _021F9810
_021F9798:
	bl ov15_021FD3AC
	str r0, [r4]
	b _021F9810
_021F97A0:
	bl ov15_021FC2E0
	str r0, [r4]
	b _021F9810
_021F97A8:
	bl ov15_021FA4F8
	str r0, [r4]
	b _021F9810
_021F97B0:
	bl ov15_021FB604
	str r0, [r4]
	b _021F9810
_021F97B8:
	bl ov15_021FB654
	str r0, [r4]
	b _021F9810
_021F97C0:
	mov r1, #1
	bl ov15_021FA578
	str r0, [r4]
	b _021F9810
_021F97CA:
	mov r1, #0
	mvn r1, r1
	bl ov15_021FA578
	str r0, [r4]
	b _021F9810
_021F97D6:
	bl ov15_021FB060
	str r0, [r4]
	b _021F9810
_021F97DE:
	bl ov15_021FAFFC
	str r0, [r4]
	b _021F9810
_021F97E6:
	bl ov15_021FCB64
	str r0, [r4]
	b _021F9810
_021F97EE:
	bl ov15_021FD850
	str r0, [r4]
	b _021F9810
_021F97F6:
	mov r0, #1
	mov r1, #6
	bl sub_020880CC
	mov r0, #0x25
	str r0, [r4]
	b _021F9810
_021F9804:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021F9810
	mov r0, #1
	pop {r3, r4, r5, pc}
_021F9810:
	add r0, r5, #0
	bl ov15_021FF8D4
	mov r0, #0x93
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl SpriteSystem_DrawSprites
	add r0, r5, #0
	bl ov15_021FDC88
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end Bag_Main
