#include "config.h"
#include "msgdata/msg/msg_0247.h"
#include "msgdata/msg/msg_0442.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_74_thumb.inc"
	.include "global.inc"
	.public gApplication_TitleScreen
	.public sub_020342C0

	.public MainMenuApp_Init
	.public MainMenuApp_Main
	.public MainMenuApp_Exit
	.public ov74_0223B2C0
	.public ov74_0223B2CC
	.public ov74_0223B2D8
	.public ov74_0223B2E8
	.public gApp_MainMenu_SelectOption_ConnectToRanger
	.public gApp_MainMenu_SelectOption_MigrateFromAgb
	.public gApp_MainMenu_SelectOption_MysteryGift

	.text
	.public ov74_02229200
	.public ov74_02229294
	.public ov74_02229450
	.public ov74_02229DA0
	.public ov74_02229DCC
	.public ov74_02229DD4
	.public ov74_02229DE0
	.public ov74_02229E60
	.public ov74_02229F90
	.public ov74_02229FF4
	.public ov74_0222A2A4
	.public ov74_0222A2E0
	.public ov74_0222A35C
	.public ov74_0222A3CC
	.public ov74_0222A494
	.public ov74_0222A4CC
	.public ov74_0222A504
	.public ov74_0222A538
	.public ov74_0222A560
	.public ov74_0222A5AC
	.public ov74_0222A5CC
	.public ov74_0222A650
	.public ov74_0222A688
	.public ov74_0222A6C0
	.public ov74_0222ACD8
	.public ov74_0222AE6C
	.public ov74_0222C2EC
	.public ov74_0222CD94
	.public ov74_0222D2D4
	.public ov74_0222D308
	.public ov74_0222D358
	.public ov74_0222D414
	.public ov74_0222D490
	.public ov74_0222D494
	.public ov74_0222D4E4
	.public ov74_0222D55C
	.public ov74_0222D5C4
	.public ov74_0222D614
	.public ov74_0222D690
	.public ov74_0222D774
	.public ov74_0222D78C
	.public ov74_0222D7D0
	.public ov74_0222DDFC
	.public ov74_0222E1F4
	.public ov74_0222EB44
	.public ov74_0222EE08
	.public ov74_0222EE0C
	.public ov74_0222EE58
	.public ov74_0222EEB0
	.public ov74_0222EF18
	.public ov74_0222EF64
	.public ov74_0222EF68
	.public ov74_0222F598
	.public ov74_0222F7D4
	.public ov74_0222FB8C
	.public ov74_02230018
	.public ov74_02230030
	.public ov74_02230070
	.public ov74_022300A8
	.public ov74_02230110
	.public ov74_02230138
	.public ov74_02230404
	.public ov74_02230520
	.public ov74_02230590
	.public ov74_022305E4
	.public ov74_022306C8
	.public ov74_022308E0
	.public ov74_02230964
	.public ov74_02230988
	.public ov74_022309AC
	.public ov74_022309F0
	.extern _0223B330
	.extern _0223B340
	.extern _0223B368
	.extern _0223B390
	.extern _0223B3A0
	.extern _0223B3BC
	.extern _0223B410
	.extern _0223B420
	.extern _0223B430
	.extern _0223B440
	.extern _0223B45C
	.extern _0223B478
	.extern _0223B494
	.extern _0223B4B0
	.extern gApp_MainMenu_SelectOption_ConnectToRanger
	.extern gApp_MainMenu_SelectOption_MigrateFromAgb
	.extern gApp_MainMenu_SelectOption_MysteryGift
	.extern ov74_02231048
	.extern ov74_02231054
	.extern ov74_0223105C
	.extern ov74_02231064
	.extern ov74_02231070
	.extern ov74_0223107C
	.extern ov74_02231088
	.extern ov74_02231094
	.extern ov74_022310A0
	.extern ov74_022310B8
	.extern ov74_022310C4
	.extern ov74_02231100
	.extern ov74_0223110C
	.extern ov74_02231118
	.extern ov74_02231124
	.extern ov74_02231130
	.extern ov74_0223113C
	.extern ov74_02231154
	.extern ov74_0223115C
	.extern ov74_02231164
	.extern ov74_02231184
	.extern ov74_02231194
	.extern ov74_022311A0
	.extern ov74_022311AC
	.extern ov74_022311BC
	.extern ov74_022311CC
	.extern ov74_022311DC
	.extern ov74_022311F4
	.extern ov74_02231214
	.extern ov74_02231238
	.extern ov74_02231260
	.extern ov74_022312C0
	.extern ov74_022313F0
	.extern ov74_02231424
	.extern ov74_02231448
	.extern ov74_0223144C
	.extern ov74_02231450
	.extern ov74_02231454
	.extern ov74_02231458
	.extern ov74_0223145C
	.extern ov74_02231460
	.extern ov74_022314A0
	.extern ov74_022314BC
	.extern ov74_022314DC
	.extern ov74_02231508
	.extern ov74_02231544
	.extern ov74_02231560
	.extern ov74_02231584
	.extern ov74_0223161C
	.extern ov74_02231638
	.extern ov74_02231670
	.extern ov74_022316E8
	.extern ov74_02231704
	.extern ov74_02231724
	.extern ov74_02231744
	.extern ov74_0223512C
	.extern ov74_02235230
	.extern ov74_02235258
	.extern ov74_022352A0
	.extern ov74_022352D0
	.extern ov74_02235308
	.extern ov74_02235390
	.extern ov74_0223539C
	.extern ov74_022353FC
	.extern ov74_02235414
	.extern ov74_02235464
	.extern ov74_0223546C
	.extern ov74_02235474
	.extern ov74_02235568
	.extern ov74_02235634
	.extern ov74_0223563C
	.extern ov74_0223567C
	.extern ov74_02235690
	.extern ov74_02235708
	.extern ov74_02235728
	.extern ov74_022358BC
	.extern ov74_022358C8
	.extern ov74_02235930
	.extern ov74_022359BC
	.extern ov74_02235A68
	.extern ov74_02235DC4
	.extern ov74_02235ED0
	.extern ov74_02235F58
	.extern ov74_02236034
	.extern ov74_022360A0
	.extern ov74_022360B0
	.extern ov74_02236128
	.extern ov74_02236140
	.extern ov74_0223615C
	.extern ov74_022365FC
	.extern ov74_02236680
	.extern ov74_022368D4
	.extern ov74_02236980
	.extern ov74_02236988
	.extern ov74_02236AE0
	.extern ov74_0223BD5C
	.extern ov74_0223BD68
	.extern ov74_0223C1F4
	.extern ov74_0223C220
	.extern ov74_0223C230
	.extern ov74_0223C240
	.extern ov74_0223C250
	.extern ov74_0223C260
	.extern ov74_0223C270
	.extern ov74_0223C2A0
	.extern ov74_0223C2B0
	.extern ov74_0223C2D0
	.extern ov74_0223C2E0
	.extern ov74_0223C2F0
	.extern ov74_0223C320
	.extern ov74_0223C340
	.extern ov74_0223C6D0
	.extern ov74_0223C6E0
	.extern ov74_0223C700
	.extern ov74_0223D080
	.extern ov74_0223D090
	.extern ov74_0223D0A4
	.extern ov74_0223D0A8
	.extern ov74_0223D0BC
	.extern ov74_0223D0C0

	thumb_func_start ov74_02228C84
ov74_02228C84: ; 0x02228C84
	push {r3, r4}
	ldr r4, _02228CAC ; =ov74_0223BD68
	ldr r1, _02228CB0 ; =0x00000123
	mov r3, #0
_02228C8C:
	ldrh r2, [r4, #2]
	cmp r0, r2
	bne _02228C9C
	ldr r0, _02228CAC ; =ov74_0223BD68
	lsl r1, r3, #2
	ldrh r0, [r0, r1]
	pop {r3, r4}
	bx lr
_02228C9C:
	add r3, r3, #1
	add r4, r4, #4
	cmp r3, r1
	blo _02228C8C
	mov r0, #0x3f
	pop {r3, r4}
	bx lr
	nop
_02228CAC: .word ov74_0223BD68
_02228CB0: .word 0x00000123
	thumb_func_end ov74_02228C84


	thumb_func_start ov74_IntToWstring5
ov74_IntToWstring5: ; 0x02228CB4
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldr r1, _02228D1C ; =0x00002710
	add r0, r4, #0
	bl _s32_div_f
	add r0, #0x30
	strh r0, [r5]
	ldr r1, _02228D1C ; =0x00002710
	add r0, r4, #0
	bl _s32_div_f
	add r4, r1, #0
	mov r1, #0xfa
	add r0, r4, #0
	lsl r1, r1, #2
	bl _s32_div_f
	add r0, #0x30
	mov r1, #0xfa
	strh r0, [r5, #2]
	add r0, r4, #0
	lsl r1, r1, #2
	bl _s32_div_f
	add r4, r1, #0
	add r0, r4, #0
	mov r1, #0x64
	bl _s32_div_f
	add r0, #0x30
	strh r0, [r5, #4]
	add r0, r4, #0
	mov r1, #0x64
	bl _s32_div_f
	add r4, r1, #0
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r0, #0x30
	strh r0, [r5, #6]
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r4, r1, #0
	add r4, #0x30
	strh r4, [r5, #8]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02228D1C: .word 0x00002710
	thumb_func_end ov74_IntToWstring5


	thumb_func_start ov74_02228D20
ov74_02228D20: ; 0x02228D20
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	ldr r0, [r7, #0x10]
	bl PlayerProfile_GetNamePtr
	ldr r5, _02228D58 ; =ov74_0223D080
	add r4, r0, #0
	mov r6, #0
_02228D30:
	ldrh r0, [r4]
	bl ov74_02228C84
	strh r0, [r5]
	add r6, r6, #1
	add r4, r4, #2
	add r5, r5, #2
	cmp r6, #8
	blt _02228D30
	ldr r0, [r7, #0x10]
	bl PlayerProfile_GetTrainerID_VisibleHalf
	add r1, r0, #0
	ldr r0, _02228D5C ; =ov74_0223D090
	bl ov74_IntToWstring5
	ldr r0, _02228D60 ; =ov74_0223D080
	mov r1, #0
	strh r1, [r0, #0x1a]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02228D58: .word ov74_0223D080
_02228D5C: .word ov74_0223D090
_02228D60: .word ov74_0223D080
	thumb_func_end ov74_02228D20


	thumb_func_start ov74_02228D64
ov74_02228D64: ; 0x02228D64
	push {r3, r4, r5, lr}
	sub sp, #0x48
	ldr r5, _02228E90 ; =_0223B340
	add r4, r0, #0
	add r3, sp, #0x20
	mov r2, #5
_02228D70:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02228D70
	ldr r3, _02228E94 ; =_0223B330
	add r2, sp, #0x10
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, sp, #0x20
	bl GfGfx_SetBanks
	add r0, sp, #0x10
	bl SetBothScreensModesAndDisable
	mov r1, #0
	str r1, [sp]
	mov r3, #0xf
	ldr r0, [r4, #4]
	mov r2, #1
	lsl r3, r3, #0xc
	bl ov74_02235308
	mov r0, #1
	lsl r0, r0, #0xe
	str r0, [sp]
	mov r1, #1
	mov r3, #0x3e
	ldr r0, [r4, #4]
	add r2, r1, #0
	lsl r3, r3, #0xa
	bl ov74_02235308
	mov r0, #0
	str r0, [sp]
	mov r3, #0x1e
	ldr r0, [r4, #4]
	mov r1, #4
	mov r2, #1
	lsl r3, r3, #0xa
	bl ov74_02235308
	mov r0, #1
	lsl r0, r0, #0xe
	str r0, [sp]
	mov r3, #7
	ldr r0, [r4, #4]
	mov r1, #5
	mov r2, #1
	lsl r3, r3, #0xc
	bl ov74_02235308
	bl ResetAllTextPrinters
	mov r0, #0
	ldr r2, [r4]
	add r1, r0, #0
	bl LoadFontPal0
	mov r1, #0
	str r1, [sp]
	ldr r0, [r4]
	mov r2, #1
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	add r3, r2, #0
	bl LoadUserFrameGfx1
	ldr r0, [r4, #0x14]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #0
	str r0, [sp, #4]
	ldr r0, [r4, #4]
	mov r2, #0xa
	mov r3, #2
	bl LoadUserFrameGfx2
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4]
	mov r1, #0
	str r0, [sp, #4]
	mov r0, #0x71
	add r3, r0, #0
	add r2, r1, #0
	add r3, #0x8f
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #0xa
	mov r1, #1
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4]
	add r3, r1, #0
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0x71
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r4]
	mov r1, #2
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0x71
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	mov r2, #0
	ldr r0, [r4, #4]
	mov r1, #1
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	ldr r0, [r4, #4]
	mov r1, #1
	bl BgCommitTilemapBufferToVram
	add r0, r4, #0
	bl ov74_02228E98
	add sp, #0x48
	pop {r3, r4, r5, pc}
	nop
_02228E90: .word _0223B340
_02228E94: .word _0223B330
	thumb_func_end ov74_02228D64


	thumb_func_start ov74_02228E98
ov74_02228E98: ; 0x02228E98
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r4]
	mov r2, #4
	add r3, r2, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0
	add r3, #0xfc
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	ldr r0, [r4]
	mov r3, #4
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0x71
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r4]
	mov r1, #2
	str r0, [sp, #0xc]
	ldr r2, [r4, #4]
	mov r0, #0x71
	mov r3, #4
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	mov r2, #0
	ldr r0, [r4, #4]
	mov r1, #4
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	ldr r0, [r4, #4]
	mov r1, #4
	bl BgCommitTilemapBufferToVram
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_02228E98


	thumb_func_start ov74_02228F14
ov74_02228F14: ; 0x02228F14
	push {r3, r4, lr}
	sub sp, #0x5c
	add r4, r0, #0
	add r0, #0x18
	bl WindowIsInUse
	cmp r0, #0
	bne _02228F5E
	mov r0, #1
	str r0, [sp]
	add r1, r4, #0
	str r0, [sp, #4]
	add r0, sp, #8
	add r1, #0x18
	mov r2, #0
	mov r3, #0x11
	bl ov74_02235414
	mov r3, #0x51
	lsl r3, r3, #2
	ldr r3, [r4, r3]
	add r0, sp, #8
	mov r1, #0x16
	mov r2, #0x10
	bl ov74_02235464
	mov r0, #2
	str r0, [sp]
	ldr r0, [r4, #4]
	add r1, sp, #8
	mov r2, #5
	mov r3, #4
	bl ov74_02235568
	add sp, #0x5c
	mov r0, #1
	pop {r3, r4, pc}
_02228F5E:
	ldr r0, _02228F88 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	beq _02228F80
	add r0, r4, #0
	add r0, #0x18
	mov r1, #0
	bl sub_0200E5D4
	add r4, #0x18
	add r0, r4, #0
	bl RemoveWindow
	add sp, #0x5c
	mov r0, #0
	pop {r3, r4, pc}
_02228F80:
	mov r0, #1
	add sp, #0x5c
	pop {r3, r4, pc}
	nop
_02228F88: .word gSystem
	thumb_func_end ov74_02228F14


	thumb_func_start ov74_02228F8C
ov74_02228F8C: ; 0x02228F8C
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	mov r0, #0xa
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x48
	add r1, #0x28
	mov r2, #0
	mov r3, #0xf7
	bl ov74_02235414
	mov r3, #0x51
	lsl r3, r3, #2
	add r0, r4, #0
	ldr r3, [r4, r3]
	add r0, #0x48
	mov r1, #0x1b
	mov r2, #4
	bl ov74_02235464
	add r0, r4, #0
	mov r1, #1
	add r0, #0x48
	add r2, r1, #0
	bl ov74_0223546C
	mov r0, #0x48
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
	add r0, r4, #0
	add r0, #0x48
	bl ov74_02235634
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	mov r3, #0xf7
	add r0, r2, r0
	str r0, [r4, r1]
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x9c
	add r1, #0x18
	mov r2, #0
	bl ov74_02235414
	mov r3, #0x51
	lsl r3, r3, #2
	add r0, r4, #0
	ldr r3, [r4, r3]
	add r0, #0x9c
	mov r1, #0x1e
	mov r2, #4
	bl ov74_02235464
	add r0, r4, #0
	add r0, #0x9c
	mov r1, #0
	mov r2, #1
	bl ov74_0223546C
	mov r0, #0xb
	str r0, [sp]
	add r1, r4, #0
	mov r2, #1
	ldr r0, [r4, #4]
	add r1, #0x9c
	add r3, r2, #0
	bl ov74_02235568
	add r0, r4, #0
	add r0, #0x9c
	bl ov74_02235634
	mov r1, #0x51
	lsl r1, r1, #2
	ldr r2, [r4, r1]
	add r0, r2, r0
	str r0, [r4, r1]
	bl ov74_0223563C
	bl ov74_02235690
	mov r0, #0xc
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0xe
	mov r2, #0xb
	mov r3, #0xd
	bl ov74_02235728
	mov r0, #1
	str r0, [sp]
	ldr r1, _02229080 ; =0x00003170
	mov r0, #0
	ldr r1, [r4, r1]
	mov r2, #0x80
	mov r3, #0x4c
	bl ov74_02235930
	ldr r1, _02229080 ; =0x00003170
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov74_02229084
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
_02229080: .word 0x00003170
	thumb_func_end ov74_02228F8C


	thumb_func_start ov74_02229084
ov74_02229084: ; 0x02229084
	push {r3, r4, r5, lr}
	sub sp, #0x20
	add r5, r0, #0
	ldr r0, [r5]
	bl MessageFormat_New
	add r4, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xf0
	add r1, #0x38
	mov r2, #0
	mov r3, #0xf7
	bl ov74_02235414
	mov r3, #0x51
	lsl r3, r3, #2
	add r0, r5, #0
	ldr r3, [r5, r3]
	add r0, #0xf0
	mov r1, #0x1a
	mov r2, #4
	bl ov74_02235464
	add r0, r5, #0
	add r0, #0xf0
	mov r1, #0
	mov r2, #1
	bl ov74_0223546C
	mov r0, #0x41
	lsl r0, r0, #2
	str r4, [r5, r0]
	ldr r2, [r5, #0x10]
	add r0, r4, #0
	mov r1, #0
	bl BufferPlayersName
	ldr r0, [r5, #0x10]
	bl PlayerProfile_GetTrainerID_VisibleHalf
	add r2, r0, #0
	mov r0, #2
	str r0, [sp]
	mov r1, #1
	add r0, r4, #0
	mov r3, #5
	str r1, [sp, #4]
	bl BufferIntegerAsString
	mov r0, #0x44
	str r0, [sp]
	add r1, r5, #0
	ldr r0, [r5, #4]
	add r1, #0xf0
	mov r2, #3
	mov r3, #0xd
	bl ov74_02235568
	add r1, r5, #0
	mov r0, #0
	add r1, #0xf8
	str r0, [r1]
	mov r1, #1
	bl GetFontAttribute
	add r2, r0, #0
	add r0, r5, #0
	add r0, #0xf0
	mov r1, #0
	bl ov74_02235474
	mov r2, #0x46
	str r2, [sp]
	add r1, r5, #0
	sub r2, #0x47
	ldr r0, [r5, #4]
	add r1, #0xf0
	add r3, r2, #0
	bl ov74_02235568
	add r0, sp, #0x10
	bl OS_GetMacAddress
	add r0, sp, #0x10
	bl ov74_022311F4
	add r1, sp, #0x1c
	add r2, sp, #0x18
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	bl ov74_02231238
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [sp, #0x1c]
	add r0, r4, #0
	mov r1, #0
	mov r3, #4
	bl BufferIntegerAsString
	mov r0, #2
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	ldr r2, [sp, #0x18]
	add r0, r4, #0
	mov r3, #4
	bl BufferIntegerAsString
	add r0, r5, #0
	mov r1, #1
	add r0, #0xfc
	str r1, [r0]
	mov r2, #0x47
	str r2, [sp]
	ldr r0, [r5, #4]
	add r5, #0xf0
	sub r2, #0x48
	add r1, r5, #0
	add r3, r2, #0
	bl ov74_02235568
	add r0, r4, #0
	bl MessageFormat_Delete
	add sp, #0x20
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov74_02229084


	thumb_func_start ov74_02229190
ov74_02229190: ; 0x02229190
	push {r4, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	bl ov74_022359BC
	add r0, r4, #0
	add r0, #0x18
	bl WindowIsInUse
	cmp r0, #1
	bne _022291D8
	add r0, r4, #0
	add r0, #0x18
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	add r0, #0x18
	bl RemoveWindow
	add r0, r4, #0
	add r0, #0x28
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	add r0, #0x28
	bl RemoveWindow
	add r0, r4, #0
	add r0, #0x38
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	add r0, #0x38
	bl RemoveWindow
_022291D8:
	ldr r0, [r4, #4]
	mov r1, #0
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #4
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [r4, #4]
	bl Heap_Free
	pop {r4, pc}
	thumb_func_end ov74_02229190


	thumb_func_start ov74_02229200
ov74_02229200: ; 0x02229200
	push {r3, r4, r5, lr}
	mov r3, #2
	ldr r2, _02229288 ; =0x000034DC
	mov r1, #0x53
	lsl r3, r3, #0x10
	add r5, r0, #0
	bl ov74_022352D0
	add r4, r0, #0
	mov r0, #0x53
	str r0, [r4]
	bl BgConfig_Alloc
	str r0, [r4, #4]
	add r0, r5, #0
	bl OverlayManager_GetArgs
	ldr r0, [r0, #8]
	str r0, [r4, #8]
	bl Save_PlayerData_GetProfile
	str r0, [r4, #0x10]
	ldr r0, [r4, #8]
	bl Save_Pokedex_Get
	str r0, [r4, #0xc]
	ldr r0, [r4, #8]
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #0x14]
	ldr r0, [r4]
	bl ov74_022352A0
	ldr r0, [r4, #8]
	bl Save_MysteryGift_Get
	ldr r1, _0222928C ; =0x00003174
	mov r2, #0x53
	str r0, [r4, r1]
	mov r0, #9
	lsl r2, r2, #2
	str r0, [r4, r2]
	add r0, r2, #0
	mov r1, #0x28
	sub r0, #8
	str r1, [r4, r0]
	add r1, r2, #0
	mov r0, #0
	add r1, #8
	str r0, [r4, r1]
	add r1, r2, #0
	add r1, #0x10
	str r0, [r4, r1]
	add r2, #0xc
	str r0, [r4, r2]
	mov r2, #0x57
	mov r1, #0x59
	lsl r2, r2, #4
	bl Heap_Create
	ldr r1, _02229290 ; =0x0000047E
	mov r0, #9
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_02229288: .word 0x000034DC
_0222928C: .word 0x00003174
_02229290: .word 0x0000047E
	thumb_func_end ov74_02229200


	thumb_func_start ov74_02229294
ov74_02229294: ; 0x02229294
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r1, #0
	add r6, r0, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #0xd
	bhi _022292FA
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_022292B4: ; jump table
	.short _022292D0 - _022292B4 - 2 ; case 0
	.short _022292F2 - _022292B4 - 2 ; case 1
	.short _02229310 - _022292B4 - 2 ; case 2
	.short _02229362 - _022292B4 - 2 ; case 3
	.short _0222938E - _022292B4 - 2 ; case 4
	.short _022293CA - _022292B4 - 2 ; case 5
	.short _02229404 - _022292B4 - 2 ; case 6
	.short _02229434 - _022292B4 - 2 ; case 7
	.short _02229434 - _022292B4 - 2 ; case 8
	.short _02229434 - _022292B4 - 2 ; case 9
	.short _02229434 - _022292B4 - 2 ; case 10
	.short _0222941A - _022292B4 - 2 ; case 11
	.short _02229422 - _022292B4 - 2 ; case 12
	.short _0222942E - _022292B4 - 2 ; case 13
_022292D0:
	bl ov74_02228D64
	ldr r0, [r4, #0xc]
	bl Pokedex_IsEnabled
	cmp r0, #0
	bne _022292EC
	mov r0, #1
	add r1, r0, #0
	add r2, r5, #0
	mov r3, #0xd
	bl ov74_0223539C
	b _02229434
_022292EC:
	mov r0, #2
	str r0, [r5]
	b _02229434
_022292F2:
	bl ov74_02228F14
	cmp r0, #0
	beq _022292FC
_022292FA:
	b _02229434
_022292FC:
	mov r0, #1
	bl ov74_02235390
	mov r0, #0
	mov r1, #0xc
	add r2, r5, #0
	mov r3, #0xd
	bl ov74_0223539C
	b _02229434
_02229310:
	bl ov74_02228F8C
	ldr r0, _02229440 ; =0x00003174
	ldr r0, [r4, r0]
	bl SaveMysteryGift_FindAvailable
	cmp r0, #0
	bne _0222934C
	add r0, r4, #0
	mov r1, #1
	add r0, #0x98
	str r1, [r0]
	mov r0, #0x16
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
	ldr r1, _02229444 ; =0x0000317C
	add r2, r5, #0
	str r0, [r4, r1]
	mov r0, #1
	mov r1, #3
	mov r3, #0xd
	bl ov74_0223539C
	b _02229434
_0222934C:
	mov r0, #0x53
	mov r1, #7
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r0, #1
	mov r1, #4
	add r2, r5, #0
	mov r3, #0xd
	bl ov74_0223539C
	b _02229434
_02229362:
	ldr r0, _02229444 ; =0x0000317C
	ldr r0, [r4, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _02229434
	ldr r0, _02229448 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r1, r0
	beq _02229434
	bl ov74_02235390
	mov r0, #0
	mov r1, #0xc
	add r2, r5, #0
	mov r3, #0xd
	bl ov74_0223539C
	b _02229434
_0222938E:
	bl ov74_0222962C
	mov r1, #0x15
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	cmp r0, #5
	bne _022293B2
	mov r0, #1
	bl ov74_02235390
	mov r0, #0
	mov r1, #0xc
	add r2, r5, #0
	mov r3, #0xd
	bl ov74_0223539C
	b _02229434
_022293B2:
	cmp r0, #4
	bne _02229434
	mov r0, #1
	bl ov74_02235390
	mov r0, #0
	mov r1, #0xc
	add r2, r5, #0
	mov r3, #0xd
	bl ov74_0223539C
	b _02229434
_022293CA:
	bl ov74_02228E98
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r1, #0xc6
	lsl r1, r1, #6
	ldr r0, [r4, #4]
	add r1, r4, r1
	mov r2, #0x53
	bl ov74_0222EC08
	mov r0, #1
	mov r1, #6
	add r2, r5, #0
	mov r3, #0xd
	bl ov74_0223539C
	ldr r1, _0222944C ; =0x000032D2
	mov r0, #4
	ldrb r2, [r4, r1]
	bic r2, r0
	strb r2, [r4, r1]
	b _02229434
_02229404:
	ldr r0, _02229448 ; =gSystem
	ldr r0, [r0, #0x48]
	cmp r0, #0
	beq _02229434
	mov r0, #0
	mov r1, #0xb
	add r2, r5, #0
	mov r3, #0xd
	bl ov74_0223539C
	b _02229434
_0222941A:
	mov r0, #0
	bl OS_ResetSystem
	b _02229434
_02229422:
	add r0, r6, #0
	bl ov74_02229190
	add sp, #4
	mov r0, #1
	pop {r3, r4, r5, r6, pc}
_0222942E:
	add r0, r5, #0
	bl ov74_022353FC
_02229434:
	bl ov74_022358BC
	mov r0, #0
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_02229440: .word 0x00003174
_02229444: .word 0x0000317C
_02229448: .word gSystem
_0222944C: .word 0x000032D2
	thumb_func_end ov74_02229294


	thumb_func_start ov74_02229450
ov74_02229450: ; 0x02229450
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x59
	bl Heap_Destroy
	ldr r0, _02229474 ; =FS_OVERLAY_ID(intro_title)
	ldr r1, _02229478 ; =gApplication_TitleScreen
	bl RegisterMainOverlay
	add r0, r4, #0
	bl OverlayManager_FreeData
	mov r0, #0x53
	bl Heap_Destroy
	mov r0, #1
	pop {r4, pc}
	nop
_02229474: .word FS_OVERLAY_ID(intro_title)
_02229478: .word gApplication_TitleScreen
	thumb_func_end ov74_02229450


	thumb_func_start ov74_0222947C
ov74_0222947C: ; 0x0222947C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	mov r0, #0xc6
	lsl r0, r0, #6
	add r4, r5, r0
	mov r2, #0xd6
	add r0, r4, #0
	mov r1, #0
	lsl r2, r2, #2
	bl MI_CpuFill8
	ldr r3, [r5]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	bl NewMsgDataFromNarc
	add r6, r0, #0
	ldr r0, [r5]
	bl MessageFormat_New
	mov r1, #0xc6
	mov r2, #7
	lsl r1, r1, #6
	strh r2, [r5, r1]
	ldr r3, [r5]
	add r1, r6, #0
	mov r2, #0x4e
	str r0, [sp]
	bl ReadMsgData_ExpandPlaceholders
	mov r1, #0x41
	lsl r1, r1, #2
	add r7, r0, #0
	add r1, r4, r1
	mov r2, #0x24
	bl CopyStringToU16Array
	add r0, r7, #0
	bl String_Delete
	mov r0, #8
	bl ov74_02235A68
	add r7, r0, #0
	mov r0, #7
	bl ov74_02235A68
	str r0, [sp, #4]
	mov r0, #0xc
	bl ov74_02235A68
	str r0, [sp, #8]
	mov r0, #0xa
	bl ov74_02235A68
	str r0, [sp, #0xc]
	mov r0, #0xb
	bl ov74_02235A68
	ldr r1, [sp, #0xc]
	mov r2, #0x53
	orr r1, r0
	ldr r0, [sp, #8]
	lsl r2, r2, #2
	orr r1, r0
	ldr r0, [sp, #4]
	mov r3, #1
	orr r0, r1
	orr r0, r7
	str r0, [r4, r2]
	mov r1, #1
	add r0, r2, #4
	strh r1, [r4, r0]
	add r0, r2, #6
	add r1, r0, #0
	ldrb r1, [r4, r1]
	bic r1, r3
	add r3, r0, #0
	strb r1, [r4, r3]
	add r1, r0, #0
	ldrb r1, [r4, r1]
	mov r3, #2
	bic r1, r3
	add r3, r0, #0
	strb r1, [r4, r3]
	add r1, r0, #0
	ldrb r3, [r4, r1]
	mov r1, #4
	orr r3, r1
	add r1, r0, #0
	strb r3, [r4, r1]
	ldrb r3, [r4, r1]
	mov r1, #8
	orr r3, r1
	add r1, r0, #0
	strb r3, [r4, r1]
	ldrb r2, [r4, r0]
	mov r1, #0x20
	bic r2, r1
	strb r2, [r4, r0]
	ldr r0, [sp]
	ldr r3, [r5]
	add r1, r6, #0
	mov r2, #0x4d
	bl ReadMsgData_ExpandPlaceholders
	mov r1, #0x55
	lsl r1, r1, #2
	add r7, r0, #0
	add r1, r4, r1
	mov r2, #0xfa
	bl CopyStringToU16Array
	add r0, r7, #0
	bl String_Delete
	mov r0, #0xd2
	lsl r0, r0, #2
	mov r1, #0
	ldr r3, _022295C0 ; =0x000001EA
	strb r1, [r4, r0]
	add r2, r0, #2
	strh r3, [r4, r2]
	add r2, r0, #4
	strh r1, [r4, r2]
	add r2, r0, #6
	strh r1, [r4, r2]
	add r0, #8
	strb r1, [r4, r0]
	add r0, sp, #0x10
	bl GF_RTC_CopyDate
	add r0, sp, #0x10
	bl RTC_ConvertDateToDay
	mov r1, #0xd5
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [sp]
	bl MessageFormat_Delete
	add r0, r6, #0
	bl DestroyMsgData
	ldr r0, _022295C4 ; =0x00003174
	add r1, r4, #0
	ldr r0, [r5, r0]
	mov r2, #3
	bl SaveMysteryGift_TryInsertGift
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r5, #4]
	add r1, r4, #0
	bl ov74_02235DC4
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022295C0: .word 0x000001EA
_022295C4: .word 0x00003174
	thumb_func_end ov74_0222947C


	thumb_func_start ov74_022295C8
ov74_022295C8: ; 0x022295C8
	mov r2, #0x16
	lsl r2, r2, #4
	str r1, [r0, r2]
	bx lr
	thumb_func_end ov74_022295C8


	thumb_func_start ov74_022295D0
ov74_022295D0: ; 0x022295D0
	push {r3, r4, r5, lr}
	add r5, r1, #0
	mov r1, #0x16
	lsl r1, r1, #4
	add r4, r3, #0
	ldr r3, [r0, r1]
	sub r3, r3, #1
	str r3, [r0, r1]
	ldr r0, [r0, r1]
	cmp r0, #0
	bne _022295F2
	bl ov74_02231008
	mov r0, #0x17
	str r0, [r5]
	mov r0, #0
	pop {r3, r4, r5, pc}
_022295F2:
	cmp r2, #0
	beq _0222960A
	bl ov74_02230FD4
	cmp r0, #0
	bne _0222960A
	bl ov74_02231008
	mov r0, #0x16
	str r0, [r5]
	mov r0, #0
	pop {r3, r4, r5, pc}
_0222960A:
	cmp r4, #0
	beq _02229622
	ldr r0, _02229628 ; =gSystem
	ldr r0, [r0, #0x48]
	tst r0, r4
	beq _02229622
	bl ov74_02231008
	mov r0, #0x1a
	str r0, [r5]
	mov r0, #1
	pop {r3, r4, r5, pc}
_02229622:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02229628: .word gSystem
	thumb_func_end ov74_022295D0


	thumb_func_start ov74_0222962C
ov74_0222962C: ; 0x0222962C
	push {r3, r4, r5, lr}
	mov r5, #0x57
	lsl r5, r5, #2
	add r4, r0, #0
	sub r0, r5, #4
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _02229652
	bl ov74_02230E7C
	mov r1, #3
	sub r0, r1, r0
	bl sub_0203A930
	bl ov74_02230D28
	mov r0, #1
	bl ov74_022310B8
_02229652:
	ldr r0, [r4, r5]
	cmp r0, #0x1e
	bls _0222965A
	b _02229B52
_0222965A:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02229666: ; jump table
	.short _022296A4 - _02229666 - 2 ; case 0
	.short _022296BA - _02229666 - 2 ; case 1
	.short _022296E0 - _02229666 - 2 ; case 2
	.short _02229702 - _02229666 - 2 ; case 3
	.short _0222972C - _02229666 - 2 ; case 4
	.short _02229B52 - _02229666 - 2 ; case 5
	.short _02229B52 - _02229666 - 2 ; case 6
	.short _0222975E - _02229666 - 2 ; case 7
	.short _022297D4 - _02229666 - 2 ; case 8
	.short _022297F2 - _02229666 - 2 ; case 9
	.short _0222983C - _02229666 - 2 ; case 10
	.short _02229878 - _02229666 - 2 ; case 11
	.short _02229892 - _02229666 - 2 ; case 12
	.short _022298C6 - _02229666 - 2 ; case 13
	.short _02229908 - _02229666 - 2 ; case 14
	.short _02229928 - _02229666 - 2 ; case 15
	.short _02229940 - _02229666 - 2 ; case 16
	.short _0222995A - _02229666 - 2 ; case 17
	.short _022299B0 - _02229666 - 2 ; case 18
	.short _02229A38 - _02229666 - 2 ; case 19
	.short _02229A80 - _02229666 - 2 ; case 20
	.short _02229B52 - _02229666 - 2 ; case 21
	.short _02229AB4 - _02229666 - 2 ; case 22
	.short _02229AB8 - _02229666 - 2 ; case 23
	.short _02229B52 - _02229666 - 2 ; case 24
	.short _02229B52 - _02229666 - 2 ; case 25
	.short _02229B20 - _02229666 - 2 ; case 26
	.short _02229B52 - _02229666 - 2 ; case 27
	.short _02229AEC - _02229666 - 2 ; case 28
	.short _0222977A - _02229666 - 2 ; case 29
	.short _022297B8 - _02229666 - 2 ; case 30
_022296A4:
	add r0, r4, #0
	bl ov74_02228D20
	bl sub_02034D8C
	mov r0, #0x52
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r4, r0]
	str r1, [r4, r5]
	b _02229B52
_022296BA:
	bl sub_02034DB8
	cmp r0, #0
	beq _02229772
	mov r1, #0x5b
	lsl r1, r1, #2
	ldr r0, _022299FC ; =ov74_0223BD5C
	add r1, r4, r1
	bl ov74_02230A84
	mov r0, #0x56
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r4, r0]
	bl sub_0203A880
	mov r0, #2
	str r0, [r4, r5]
	b _02229B52
_022296E0:
	bl ov74_02230D6C
	mov r1, #0x19
	add r0, r4, #0
	lsl r1, r1, #6
	bl ov74_022295C8
	add r0, r4, #0
	add r0, #0x28
	mov r1, #0xa
	bl WaitingIcon_New
	ldr r1, _02229A00 ; =0x000034D8
	str r0, [r4, r1]
	mov r0, #3
	str r0, [r4, r5]
	b _02229B52
_02229702:
	bl ov74_02230E94
	cmp r0, #0
	beq _0222971E
	sub r1, r0, #1
	mov r0, #0x59
	lsl r0, r0, #2
	str r1, [r4, r0]
	ldr r1, _02229A04 ; =0x00000708
	add r0, r4, #0
	bl ov74_022295C8
	mov r0, #4
	str r0, [r4, r5]
_0222971E:
	add r0, r4, #0
	add r1, r4, r5
	mov r2, #0
	mov r3, #2
	bl ov74_022295D0
	b _02229B52
_0222972C:
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov74_02230DB8
	cmp r0, #0
	beq _02229750
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov74_02230DF4
	mov r0, #7
	str r0, [r4, r5]
	mov r0, #0x16
	ldr r1, _02229A04 ; =0x00000708
	lsl r0, r0, #4
	str r1, [r4, r0]
_02229750:
	add r0, r4, #0
	add r1, r4, r5
	mov r2, #0
	mov r3, #2
	bl ov74_022295D0
	b _02229B52
_0222975E:
	add r0, r4, #0
	add r1, r4, r5
	mov r2, #0
	mov r3, #2
	bl ov74_022295D0
	bl ov74_02230FD4
	cmp r0, #0
	bne _02229774
_02229772:
	b _02229B52
_02229774:
	mov r0, #0x1d
	str r0, [r4, r5]
	b _02229B52
_0222977A:
	mov r0, #0x1f
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
	ldr r0, _02229A08 ; =0x00003170
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _02229A00 ; =0x000034D8
	ldr r0, [r4, r0]
	bl sub_0200F450
	ldr r0, _02229A00 ; =0x000034D8
	mov r1, #0
	str r1, [r4, r0]
	ldr r0, _02229A0C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #0x16
	ldr r1, _02229A04 ; =0x00000708
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r0, #0x1e
	str r0, [r4, r5]
	b _02229B52
_022297B8:
	ldr r0, _02229A10 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _022297C6
	mov r0, #8
	str r0, [r4, r5]
_022297C6:
	add r0, r4, #0
	add r1, r4, r5
	mov r2, #1
	mov r3, #2
	bl ov74_022295D0
	b _02229B52
_022297D4:
	bl ov74_02230EB4
	mov r0, #9
	str r0, [r4, r5]
	mov r0, #0x16
	ldr r1, _02229A04 ; =0x00000708
	lsl r0, r0, #4
	str r1, [r4, r0]
	add r0, r4, #0
	add r1, r4, r5
	mov r2, #1
	mov r3, #2
	bl ov74_022295D0
	b _02229B52
_022297F2:
	bl ov74_02230F40
	cmp r0, #0
	beq _0222982E
	bl ov74_02230EE8
	mov r0, #0xa
	str r0, [r4, r5]
	mov r1, #0x32
	mov r0, #0x16
	lsl r1, r1, #6
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r0, #0x23
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
	ldr r0, _02229A0C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	ldr r0, _02229A00 ; =0x000034D8
	mov r1, #0
	str r1, [r4, r0]
	mov r0, #1
	pop {r3, r4, r5, pc}
_0222982E:
	add r0, r4, #0
	add r1, r4, r5
	mov r2, #1
	mov r3, #2
	bl ov74_022295D0
	b _02229B52
_0222983C:
	bl ov74_02230F40
	cmp r0, #0
	beq _0222986A
	mov r0, #0x49
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
	ldr r0, _02229A08 ; =0x00003170
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	bl ov74_02229084
	mov r0, #0xb
	str r0, [r4, r5]
_0222986A:
	add r0, r4, #0
	add r1, r4, r5
	mov r2, #1
	mov r3, #2
	bl ov74_022295D0
	b _02229B52
_02229878:
	ldr r0, _02229A14 ; =ov74_0223C1F4
	mov r1, #0x2a
	mov r2, #1
	bl ov74_02230F14
	mov r0, #0xc
	str r0, [r4, r5]
	mov r1, #0x32
	mov r0, #0x16
	lsl r1, r1, #6
	lsl r0, r0, #4
	str r1, [r4, r0]
	b _02229B52
_02229892:
	bl ov74_02230F6C
	cmp r0, #0
	beq _022298B8
	mov r0, #0xd
	str r0, [r4, r5]
	mov r0, #0x16
	mov r1, #0x3c
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r0, #0x49
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
_022298B8:
	add r0, r4, #0
	add r1, r4, r5
	mov r2, #1
	mov r3, #2
	bl ov74_022295D0
	b _02229B52
_022298C6:
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _02229938
	mov r0, #0x4a
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
	add r0, r4, #0
	add r0, #0x28
	mov r1, #0xa
	bl WaitingIcon_New
	ldr r1, _02229A00 ; =0x000034D8
	str r0, [r4, r1]
	add r0, r4, #0
	bl ov74_0222947C
	ldr r0, [r4, #8]
	bl ov74_022360A0
	mov r0, #0xe
	str r0, [r4, r5]
	b _02229B52
_02229908:
	bl ov74_022360B0
	cmp r0, #1
	bne _02229938
	mov r0, #0xf
	str r0, [r4, r5]
	bl OS_GetTickLo
	mov r1, #0x36
	bl _s32_div_f
	mov r0, #0x16
	add r1, r1, #6
	lsl r0, r0, #4
	str r1, [r4, r0]
	b _02229B52
_02229928:
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222993A
_02229938:
	b _02229B52
_0222993A:
	mov r0, #0x10
	str r0, [r4, r5]
	b _02229B52
_02229940:
	ldr r0, _02229A14 ; =ov74_0223C1F4
	mov r1, #0x2a
	mov r2, #2
	bl ov74_02230F14
	mov r0, #0x11
	str r0, [r4, r5]
	mov r1, #0x4b
	mov r0, #0x16
	lsl r1, r1, #4
	lsl r0, r0, #4
	str r1, [r4, r0]
	b _02229B52
_0222995A:
	bl ov74_02230F98
	cmp r0, #0
	beq _02229976
	bl ov74_02236128
	mov r0, #0x12
	str r0, [r4, r5]
	mov r1, #0x32
	mov r0, #0x16
	lsl r1, r1, #4
	lsl r0, r0, #4
	str r1, [r4, r0]
	b _02229B52
_02229976:
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _02229996
	bl ov74_02231008
	mov r0, #0x17
	mov r1, #0x78
	str r0, [r4, r5]
	add r0, r1, #0
	add r0, #0xe8
	str r1, [r4, r0]
_02229996:
	bl ov74_02230FD4
	cmp r0, #0
	bne _02229A48
	bl ov74_02231008
	mov r0, #0x16
	mov r1, #0x78
	str r0, [r4, r5]
	add r0, r1, #0
	add r0, #0xe8
	str r1, [r4, r0]
	b _02229B52
_022299B0:
	bl ov74_0223615C
	cmp r0, #3
	bne _022299CA
	bl ov74_02231008
	mov r0, #0x16
	mov r1, #0x78
	str r0, [r4, r5]
	add r0, r1, #0
	add r0, #0xe8
	str r1, [r4, r0]
	b _02229A18
_022299CA:
	bl ov74_0223615C
	cmp r0, #2
	beq _022299D8
	bl ov74_022360B0
	b _02229A18
_022299D8:
	bl ov74_02230F6C
	cmp r0, #0
	bne _022299E8
	bl ov74_02230FD4
	cmp r0, #0
	bne _02229A18
_022299E8:
	mov r0, #0x13
	str r0, [r4, r5]
	mov r0, #0x16
	mov r1, #1
	lsl r0, r0, #4
	str r1, [r4, r0]
	bl ov74_02231008
	b _02229B52
	nop
_022299FC: .word ov74_0223BD5C
_02229A00: .word 0x000034D8
_02229A04: .word 0x00000708
_02229A08: .word 0x00003170
_02229A0C: .word SEQ_SE_DP_SELECT
_02229A10: .word gSystem
_02229A14: .word ov74_0223C1F4
_02229A18:
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _02229A38
	bl ov74_02231008
	mov r0, #0x17
	str r0, [r4, r5]
	mov r0, #0x16
	mov r1, #0xa
	lsl r0, r0, #4
	str r1, [r4, r0]
_02229A38:
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02229A4A
_02229A48:
	b _02229B52
_02229A4A:
	mov r0, #0x14
	str r0, [r4, r5]
	mov r0, #0x4b
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
	ldr r0, _02229B58 ; =0x00003170
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _02229B5C ; =0x000034D8
	ldr r0, [r4, r0]
	bl sub_0200F450
	ldr r0, _02229B60 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	ldr r0, _02229B5C ; =0x000034D8
	mov r1, #0
	str r1, [r4, r0]
	b _02229B52
_02229A80:
	bl ov74_02231048
	cmp r0, #0
	beq _02229B52
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _02229AA2
	bl sub_02034DE0
	bl sub_0203A914
	mov r0, #0x52
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
_02229AA2:
	ldr r0, _02229B64 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _02229B52
	mov r0, #0x1b
	str r0, [r4, r5]
	mov r0, #4
	pop {r3, r4, r5, pc}
_02229AB4:
	mov r0, #0x17
	str r0, [r4, r5]
_02229AB8:
	mov r0, #0x4c
	str r0, [sp]
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x48
	mov r2, #2
	mov r3, #0x13
	bl ov74_02235568
	ldr r0, _02229B58 ; =0x00003170
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _02229B5C ; =0x000034D8
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02229AE0
	bl sub_0200F450
_02229AE0:
	ldr r0, _02229B5C ; =0x000034D8
	mov r1, #0
	str r1, [r4, r0]
	mov r0, #0x1c
	str r0, [r4, r5]
	b _02229B52
_02229AEC:
	bl ov74_02231048
	cmp r0, #0
	beq _02229B52
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _02229B0E
	bl sub_02034DE0
	bl sub_0203A914
	mov r0, #0x52
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
_02229B0E:
	ldr r0, _02229B64 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _02229B52
	mov r0, #0
	bl OS_ResetSystem
	b _02229B52
_02229B20:
	bl ov74_02231048
	cmp r0, #0
	beq _02229B52
	mov r0, #0x52
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _02229B52
	bl sub_02034DE0
	bl sub_0203A914
	mov r0, #0x52
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
	ldr r0, _02229B5C ; =0x000034D8
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02229B4E
	bl sub_0200F450
_02229B4E:
	mov r0, #5
	pop {r3, r4, r5, pc}
_02229B52:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02229B58: .word 0x00003170
_02229B5C: .word 0x000034D8
_02229B60: .word SEQ_SE_DP_SELECT
_02229B64: .word gSystem
	thumb_func_end ov74_0222962C


	thumb_func_start ov74_02229B68
ov74_02229B68: ; 0x02229B68
	push {r4, lr}
	ldr r1, _02229BB8 ; =ov74_0223D0A4
	add r4, r0, #0
	ldr r1, [r1]
	cmp r1, #0
	bne _02229BB4
	bl ov74_02229E14
	mov r1, #0xf5
	mov r0, #0xf
	lsl r1, r1, #2
	bl Heap_Alloc
	ldr r1, _02229BB8 ; =ov74_0223D0A4
	mov r2, #0xf5
	str r0, [r1]
	mov r1, #0
	lsl r2, r2, #2
	bl MI_CpuFill8
	ldr r0, _02229BB8 ; =ov74_0223D0A4
	mov r1, #0x32
	ldr r0, [r0]
	mov r2, #0xa
	strh r1, [r0, #0x24]
	ldr r0, _02229BBC ; =ov74_02229CB8
	mov r1, #0
	bl SysTask_CreateOnMainQueue
	ldr r1, _02229BB8 ; =ov74_0223D0A4
	ldr r2, [r1]
	str r0, [r2, #0x1c]
	ldr r0, [r1]
	str r4, [r0]
	ldr r0, [r1]
	add r0, r0, #4
	bl sub_0203778C
_02229BB4:
	pop {r4, pc}
	nop
_02229BB8: .word ov74_0223D0A4
_02229BBC: .word ov74_02229CB8
	thumb_func_end ov74_02229B68


	thumb_func_start ov74_02229BC0
ov74_02229BC0: ; 0x02229BC0
	ldr r2, _02229BCC ; =ov74_0223D0A4
	ldr r3, [r2]
	str r0, [r3, #0x20]
	ldr r0, [r2]
	strh r1, [r0, #0x24]
	bx lr
	.balign 4, 0
_02229BCC: .word ov74_0223D0A4
	thumb_func_end ov74_02229BC0


	thumb_func_start ov74_02229BD0
ov74_02229BD0: ; 0x02229BD0
	push {r4, lr}
	bl sub_0203769C
	bl sub_020373B4
	cmp r0, #0
	beq _02229BFE
	mov r4, #0
	ldr r1, _02229C00 ; =ov74_0223D0A4
	ldr r0, _02229C04 ; =0x000003C1
	add r3, r4, #0
_02229BE6:
	ldr r2, [r1]
	add r2, r2, r4
	add r4, r4, #1
	strb r3, [r2, r0]
	cmp r4, #0x10
	blt _02229BE6
	bl sub_02034434
	ldr r0, _02229C08 ; =ov74_02229C0C
	mov r1, #0
	bl ov74_02229BC0
_02229BFE:
	pop {r4, pc}
	.balign 4, 0
_02229C00: .word ov74_0223D0A4
_02229C04: .word 0x000003C1
_02229C08: .word ov74_02229C0C
	thumb_func_end ov74_02229BD0


	thumb_func_start ov74_02229C0C
ov74_02229C0C: ; 0x02229C0C
	push {r4, r5, r6, lr}
	mov r4, #0
	ldr r6, _02229C40 ; =ov74_0223D0A4
	add r5, r4, #0
_02229C14:
	ldr r0, [r6]
	add r0, r0, r5
	ldr r0, [r0, #0x28]
	cmp r0, #0
	bne _02229C36
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #1
	bne _02229C36
	add r0, r4, #0
	bl sub_02034818
	ldr r1, [r6]
	add r1, r1, r5
	str r0, [r1, #0x28]
_02229C36:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0x10
	blt _02229C14
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02229C40: .word ov74_0223D0A4
	thumb_func_end ov74_02229C0C


	thumb_func_start ov74_02229C44
ov74_02229C44: ; 0x02229C44
	push {r3, lr}
	bl sub_02034DB8
	cmp r0, #0
	beq _02229C56
	ldr r0, _02229C58 ; =ov74_02229C5C
	mov r1, #0
	bl ov74_02229BC0
_02229C56:
	pop {r3, pc}
	.balign 4, 0
_02229C58: .word ov74_02229C5C
	thumb_func_end ov74_02229C44


	thumb_func_start ov74_02229C5C
ov74_02229C5C: ; 0x02229C5C
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02229C5C


	thumb_func_start ov74_02229C60
ov74_02229C60: ; 0x02229C60
	push {r3, lr}
	ldr r0, _02229C78 ; =ov74_0223D0A4
	ldr r0, [r0]
	add r0, #0x27
	ldrb r0, [r0]
	bl sub_02037E1C
	ldr r0, _02229C7C ; =ov74_02229C80
	mov r1, #0
	bl ov74_02229BC0
	pop {r3, pc}
	.balign 4, 0
_02229C78: .word ov74_0223D0A4
_02229C7C: .word ov74_02229C80
	thumb_func_end ov74_02229C60


	thumb_func_start ov74_02229C80
ov74_02229C80: ; 0x02229C80
	push {r3, lr}
	bl sub_02037EC8
	cmp r0, #0
	beq _02229CA8
	ldr r0, _02229CAC ; =ov74_0223D0A4
	mov r2, #0
	ldr r1, [r0]
	mov r0, #0xf
	lsl r0, r0, #6
	strb r2, [r1, r0]
	bl sub_02034434
	mov r0, #0xab
	bl sub_02037AC0
	ldr r0, _02229CB0 ; =ov74_02229CB4
	mov r1, #0
	bl ov74_02229BC0
_02229CA8:
	pop {r3, pc}
	nop
_02229CAC: .word ov74_0223D0A4
_02229CB0: .word ov74_02229CB4
	thumb_func_end ov74_02229C80


	thumb_func_start ov74_02229CB4
ov74_02229CB4: ; 0x02229CB4
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02229CB4


	thumb_func_start ov74_02229CB8
ov74_02229CB8: ; 0x02229CB8
	push {r3, lr}
	ldr r1, _02229CDC ; =ov74_0223D0A4
	ldr r2, [r1]
	cmp r2, #0
	bne _02229CC8
	bl SysTask_Destroy
	pop {r3, pc}
_02229CC8:
	ldr r1, [r2, #0x20]
	cmp r1, #0
	beq _02229CD8
	add r2, #0x26
	ldrb r0, [r2]
	cmp r0, #0
	bne _02229CD8
	blx r1
_02229CD8:
	pop {r3, pc}
	nop
_02229CDC: .word ov74_0223D0A4
	thumb_func_end ov74_02229CB8


	thumb_func_start ov74_02229CE0
ov74_02229CE0: ; 0x02229CE0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	bl sub_02037474
	cmp r0, #0
	bne _02229D06
	add r0, r4, #0
	add r1, r6, #0
	bl sub_02038114
	add r0, r5, #0
	bl ov74_02229B68
	ldr r0, _02229D08 ; =ov74_02229BD0
	mov r1, #0
	bl ov74_02229BC0
_02229D06:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02229D08: .word ov74_02229BD0
	thumb_func_end ov74_02229CE0


	thumb_func_start ov74_02229D0C
ov74_02229D0C: ; 0x02229D0C
	add r3, r0, #0
	add r2, r1, #0
	add r1, r3, #0
	ldr r3, _02229D18 ; =sub_02037088
	mov r0, #0x16
	bx r3
	.balign 4, 0
_02229D18: .word sub_02037088
	thumb_func_end ov74_02229D0C


	thumb_func_start ov74_02229D1C
ov74_02229D1C: ; 0x02229D1C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl sub_02037474
	cmp r0, #0
	bne _02229D48
	bl ov74_0222CD7C
	bl OverlayManager_GetArgs
	ldr r0, [r0, #8]
	add r1, r4, #0
	bl sub_02038148
	add r0, r5, #0
	bl ov74_02229B68
	ldr r0, _02229D4C ; =ov74_02229C44
	mov r1, #0
	bl ov74_02229BC0
_02229D48:
	pop {r3, r4, r5, pc}
	nop
_02229D4C: .word ov74_02229C44
	thumb_func_end ov74_02229D1C


	thumb_func_start ov74_02229D50
ov74_02229D50: ; 0x02229D50
	ldr r1, _02229D60 ; =ov74_0223D0A4
	ldr r3, _02229D64 ; =ov74_02229BC0
	ldr r1, [r1]
	add r1, #0x27
	strb r0, [r1]
	ldr r0, _02229D68 ; =ov74_02229C60
	mov r1, #0
	bx r3
	.balign 4, 0
_02229D60: .word ov74_0223D0A4
_02229D64: .word ov74_02229BC0
_02229D68: .word ov74_02229C60
	thumb_func_end ov74_02229D50


	thumb_func_start ov74_02229D6C
ov74_02229D6C: ; 0x02229D6C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r4, #0
_02229D72:
	add r0, r4, #0
	bl sub_020358D0
	add r1, r0, #0
	beq _02229D92
	add r0, #0x4c
	ldrh r0, [r0]
	cmp r0, #0
	beq _02229D92
	add r5, #0x8c
	add r0, r5, #0
	mov r2, #0x50
	bl memcpy
	add r0, r4, #0
	pop {r3, r4, r5, pc}
_02229D92:
	add r4, r4, #1
	cmp r4, #0x10
	blt _02229D72
	mov r0, #0
	mvn r0, r0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov74_02229D6C


	thumb_func_start ov74_02229DA0
ov74_02229DA0: ; 0x02229DA0
	ldr r1, _02229DB8 ; =ov74_0223D0A4
	ldr r2, [r1]
	add r1, r2, #0
	add r1, #0x27
	ldrb r1, [r1]
	cmp r1, r0
	bne _02229DB6
	mov r0, #0xf
	mov r1, #1
	lsl r0, r0, #6
	strb r1, [r2, r0]
_02229DB6:
	bx lr
	.balign 4, 0
_02229DB8: .word ov74_0223D0A4
	thumb_func_end ov74_02229DA0


	thumb_func_start ov74_02229DBC
ov74_02229DBC: ; 0x02229DBC
	ldr r0, _02229DC8 ; =ov74_0223D0A4
	ldr r1, [r0]
	mov r0, #0xf
	lsl r0, r0, #6
	ldrb r0, [r1, r0]
	bx lr
	.balign 4, 0
_02229DC8: .word ov74_0223D0A4
	thumb_func_end ov74_02229DBC


	thumb_func_start ov74_02229DCC
ov74_02229DCC: ; 0x02229DCC
	mov r0, #0xd6
	lsl r0, r0, #2
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02229DCC


	thumb_func_start ov74_02229DD4
ov74_02229DD4: ; 0x02229DD4
	ldr r0, _02229DDC ; =ov74_0223D0A4
	ldr r0, [r0]
	add r0, #0x68
	bx lr
	.balign 4, 0
_02229DDC: .word ov74_0223D0A4
	thumb_func_end ov74_02229DD4


	thumb_func_start ov74_02229DE0
ov74_02229DE0: ; 0x02229DE0
	ldr r1, _02229DF0 ; =ov74_0223D0A4
	mov r2, #1
	ldr r1, [r1]
	add r1, r1, r0
	ldr r0, _02229DF4 ; =0x000003C1
	strb r2, [r1, r0]
	bx lr
	nop
_02229DF0: .word ov74_0223D0A4
_02229DF4: .word 0x000003C1
	thumb_func_end ov74_02229DE0


	thumb_func_start ov74_02229DF8
ov74_02229DF8: ; 0x02229DF8
	push {r3, lr}
	ldr r1, _02229E10 ; =ov74_0223D0A4
	mov r0, #0xf
	ldr r1, [r1]
	bl Heap_FreeExplicit
	ldr r0, _02229E10 ; =ov74_0223D0A4
	mov r1, #0
	str r1, [r0]
	bl sub_02037E9C
	pop {r3, pc}
	.balign 4, 0
_02229E10: .word ov74_0223D0A4
	thumb_func_end ov74_02229DF8


	thumb_func_start ov74_02229E14
ov74_02229E14: ; 0x02229E14
	ldr r3, _02229E20 ; =sub_0203410C
	add r2, r0, #0
	ldr r0, _02229E24 ; =_0223B368
	mov r1, #2
	bx r3
	nop
_02229E20: .word sub_0203410C
_02229E24: .word _0223B368
	thumb_func_end ov74_02229E14


	thumb_func_start ov74_02229E28
ov74_02229E28: ; 0x02229E28
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #1
	ldr r0, _02229E5C ; =0x000029F0
	bne _02229E48
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _02229E58
	add r0, r4, #0
	add r0, #0x18
	mov r1, #1
	bl WaitingIcon_New
	ldr r1, _02229E5C ; =0x000029F0
	str r0, [r4, r1]
	pop {r4, pc}
_02229E48:
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02229E52
	bl sub_0200F478
_02229E52:
	ldr r0, _02229E5C ; =0x000029F0
	mov r1, #0
	str r1, [r4, r0]
_02229E58:
	pop {r4, pc}
	nop
_02229E5C: .word 0x000029F0
	thumb_func_end ov74_02229E28


	thumb_func_start ov74_02229E60
ov74_02229E60: ; 0x02229E60
	ldr r3, _02229E64 ; =ov74_02229E28
	bx r3
	.balign 4, 0
_02229E64: .word ov74_02229E28
	thumb_func_end ov74_02229E60


	thumb_func_start ov74_02229E68
ov74_02229E68: ; 0x02229E68
	push {r3, r4, r5, r6, r7, lr}
	bl OverlayManager_GetData
	add r7, r0, #0
	bl ov74_022359BC
	ldr r0, [r7, #0x7c]
	cmp r0, #0
	beq _02229E7E
	bl ListMenuItems_Delete
_02229E7E:
	ldr r0, [r7, #0x78]
	cmp r0, #0
	beq _02229E8C
	mov r1, #0
	add r2, r1, #0
	bl DestroyListMenu
_02229E8C:
	add r0, r7, #0
	add r0, #0x18
	bl ClearWindowTilemapAndCopyToVram
	add r0, r7, #0
	add r0, #0x18
	bl RemoveWindow
	add r0, r7, #0
	add r0, #0x58
	bl WindowIsInUse
	cmp r0, #0
	beq _02229EB8
	add r0, r7, #0
	add r0, #0x58
	bl ClearWindowTilemapAndCopyToVram
	add r0, r7, #0
	add r0, #0x58
	bl RemoveWindow
_02229EB8:
	add r5, r7, #0
	mov r6, #0
	add r4, r7, #0
	add r5, #0x28
_02229EC0:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _02229ED2
	add r0, r5, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	bl RemoveWindow
_02229ED2:
	add r6, r6, #1
	add r4, #0x10
	add r5, #0x10
	cmp r6, #3
	blt _02229EC0
	ldr r0, [r7]
	mov r1, #0
	bl FreeBgTilemapBuffer
	ldr r0, [r7]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r7]
	mov r1, #4
	bl FreeBgTilemapBuffer
	ldr r0, [r7]
	mov r1, #5
	bl FreeBgTilemapBuffer
	ldr r0, [r7]
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_02229E68


	thumb_func_start ov74_02229F04
ov74_02229F04: ; 0x02229F04
	push {r3, lr}
	sub sp, #8
	bl ov74_0223563C
	bl ov74_02235690
	mov r0, #0xc
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0xe
	mov r2, #0xb
	mov r3, #0xd
	bl ov74_02235728
	add sp, #8
	pop {r3, pc}
	thumb_func_end ov74_02229F04


	thumb_func_start ov74_02229F28
ov74_02229F28: ; 0x02229F28
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	beq _02229F4E
	str r1, [sp]
	ldr r1, _02229F5C ; =0x000005C4
	mov r0, #0
	ldr r1, [r4, r1]
	mov r2, #0x80
	mov r3, #0x64
	bl ov74_02235930
	ldr r1, _02229F5C ; =0x000005C4
	add sp, #4
	str r0, [r4, r1]
	pop {r3, r4, pc}
_02229F4E:
	ldr r0, _02229F5C ; =0x000005C4
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_02229F5C: .word 0x000005C4
	thumb_func_end ov74_02229F28


	thumb_func_start ov74_02229F60
ov74_02229F60: ; 0x02229F60
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl WindowIsInUse
	cmp r0, #1
	bne _02229F76
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0200E5D4
_02229F76:
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_02229F60


	thumb_func_start ov74_02229F78
ov74_02229F78: ; 0x02229F78
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl WindowIsInUse
	cmp r0, #1
	bne _02229F8E
	add r0, r5, #0
	add r1, r4, #0
	bl ClearFrameAndWindow2
_02229F8E:
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_02229F78


	thumb_func_start ov74_02229F90
ov74_02229F90: ; 0x02229F90
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, _02229FE8 ; =0x000015D4
	ldr r0, [r4, r0]
	cmp r0, #2
	beq _02229FAE
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x18
	mov r2, #3
	bl ov74_0222AA18
_02229FAE:
	add r0, r4, #0
	add r0, #0x48
	mov r1, #0
	bl ov74_02229F60
	ldr r0, _02229FE8 ; =0x000015D4
	ldr r0, [r4, r0]
	cmp r0, #2
	beq _02229FDE
	add r0, r4, #0
	mov r1, #0xf
	bl ov74_02229D1C
	ldr r1, _02229FEC ; =0x00001C20
	ldr r0, _02229FF0 ; =0x00000434
	str r1, [r4, r0]
	bl sub_0203A880
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229E28
	mov r0, #7
	pop {r3, r4, r5, pc}
_02229FDE:
	mov r0, #0x13
	add r4, #0x84
	str r0, [r4]
	pop {r3, r4, r5, pc}
	nop
_02229FE8: .word 0x000015D4
_02229FEC: .word 0x00001C20
_02229FF0: .word 0x00000434
	thumb_func_end ov74_02229F90


	thumb_func_start ov74_02229FF4
ov74_02229FF4: ; 0x02229FF4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, #0x80
	ldr r1, [r0]
	cmp r1, #1
	bne _0222A00A
	mov r0, #0x31
	pop {r3, r4, r5, pc}
_0222A00A:
	sub r0, r1, #2
	cmp r0, #2
	bhi _0222A014
	mov r0, #0x31
	pop {r3, r4, r5, pc}
_0222A014:
	cmp r1, #5
	bne _0222A01C
	mov r0, #0x31
	pop {r3, r4, r5, pc}
_0222A01C:
	ldr r0, _0222A070 ; =0x000015D4
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0222A02C
	ldr r0, _0222A074 ; =0x00000438
	ldr r0, [r4, r0]
	bl ov74_02229D50
_0222A02C:
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x18
	mov r2, #6
	bl ov74_0222AA18
	add r0, r4, #0
	add r0, #0x48
	mov r1, #0
	bl ov74_02229F60
	ldr r0, _0222A070 ; =0x000015D4
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0222A05A
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229F28
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229E28
_0222A05A:
	ldr r0, _0222A070 ; =0x000015D4
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0222A06C
	mov r0, #0xab
	bl sub_02037AC0
	mov r0, #9
	pop {r3, r4, r5, pc}
_0222A06C:
	mov r0, #0x15
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222A070: .word 0x000015D4
_0222A074: .word 0x00000438
	thumb_func_end ov74_02229FF4


	thumb_func_start ov74_0222A078
ov74_0222A078: ; 0x0222A078
	push {r3, r4, r5, r6, r7, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, _0222A0DC ; =0x000015D4
	add r5, r4, #0
	add r6, r4, #0
	ldr r0, [r4, r0]
	add r5, #0xdc
	add r6, #0x8c
	cmp r0, #1
	beq _0222A096
	cmp r0, #3
	beq _0222A0BC
	b _0222A0D6
_0222A096:
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	bl ov74_02229DD4
	mov r2, #0xd6
	add r1, r0, #0
	add r0, r5, #0
	lsl r2, r2, #2
	bl memcpy
	add r0, r4, #0
	add r4, #0xdc
	add r0, #0x8c
	add r1, r4, #0
	mov r2, #0x54
	bl ov74_02235F58
	b _0222A0D6
_0222A0BC:
	ldr r7, _0222A0E0 ; =0x000005D4
	mov r2, #0xd6
	add r1, r4, r7
	add r0, r5, #0
	add r1, #0x50
	lsl r2, r2, #2
	bl memcpy
	add r0, r6, #0
	add r1, r4, r7
	mov r2, #0x50
	bl memcpy
_0222A0D6:
	add r0, r5, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222A0DC: .word 0x000015D4
_0222A0E0: .word 0x000005D4
	thumb_func_end ov74_0222A078


	thumb_func_start ov74_0222A0E4
ov74_0222A0E4: ; 0x0222A0E4
	push {r3, lr}
	ldrh r1, [r0]
	cmp r1, #3
	bgt _0222A0FC
	cmp r1, #1
	blt _0222A12C
	beq _0222A10E
	cmp r1, #2
	beq _0222A10E
	cmp r1, #3
	beq _0222A104
	b _0222A12C
_0222A0FC:
	cmp r1, #0xd
	bne _0222A12C
	mov r0, #1
	pop {r3, pc}
_0222A104:
	ldr r0, [r0, #8]
	cmp r0, #1
	bne _0222A12C
	mov r0, #1
	pop {r3, pc}
_0222A10E:
	add r0, #8
	mov r1, #0x98
	mov r2, #0
	bl GetMonData
	cmp r0, #3
	blt _0222A120
	cmp r0, #0xe
	ble _0222A128
_0222A120:
	cmp r0, #0x41
	blt _0222A12C
	cmp r0, #0x47
	bgt _0222A12C
_0222A128:
	mov r0, #1
	pop {r3, pc}
_0222A12C:
	mov r0, #0
	pop {r3, pc}
	thumb_func_end ov74_0222A0E4


	thumb_func_start ov74_0222A130
ov74_0222A130: ; 0x0222A130
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222A168 ; =0x000029EC
	ldr r1, [r4, r0]
	cmp r1, #1
	bne _0222A142
	mov r1, #0
	sub r0, r0, #4
	str r1, [r4, r0]
_0222A142:
	bl ov74_022360B0
	sub r0, r0, #2
	cmp r0, #1
	bhi _0222A164
	add r0, r4, #0
	add r0, #0xdc
	bl ov74_0222A0E4
	cmp r0, #1
	beq _0222A15E
	ldr r0, _0222A16C ; =SEQ_SE_DP_SAVE
	bl PlaySE
_0222A15E:
	ldr r0, _0222A170 ; =0x000029E8
	mov r1, #0
	str r1, [r4, r0]
_0222A164:
	pop {r4, pc}
	nop
_0222A168: .word 0x000029EC
_0222A16C: .word SEQ_SE_DP_SAVE
_0222A170: .word 0x000029E8
	thumb_func_end ov74_0222A130


	thumb_func_start ov74_0222A174
ov74_0222A174: ; 0x0222A174
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r6, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r5, r0, #0
	str r0, [sp, #4]
	add r0, r6, #0
	add r4, #0x8c
	add r5, #0xdc
	bl OverlayManager_GetArgs
	ldr r0, [r0, #8]
	str r0, [sp]
	add r0, r4, #0
	add r0, #0x4e
	ldrb r0, [r0]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1f
	bne _0222A1A2
	mov r6, #0
	b _0222A1CE
_0222A1A2:
	mov r1, #0x35
	add r2, r4, #0
	mov r0, #0
	lsl r1, r1, #4
	strb r0, [r5, r1]
	add r2, #0x4e
	ldrb r2, [r2]
	mov r6, #1
	lsl r2, r2, #0x1b
	lsr r2, r2, #0x1f
	bne _0222A1BC
	sub r1, #8
	strb r0, [r5, r1]
_0222A1BC:
	add r0, sp, #8
	bl GF_RTC_CopyDate
	add r0, sp, #8
	bl RTC_ConvertDateToDay
	mov r1, #0xd5
	lsl r1, r1, #2
	str r0, [r5, r1]
_0222A1CE:
	ldr r0, [sp]
	bl Save_MysteryGift_Get
	add r1, r4, #0
	add r1, #0x4c
	ldrh r1, [r1]
	add r7, r0, #0
	bl SaveMysteryGift_ReceivedFlagSet
	add r4, #0x4e
	ldrb r0, [r4]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0222A204
	ldrh r0, [r5]
	cmp r0, #3
	bne _0222A204
	ldr r1, [r5, #4]
	ldr r0, _0222A234 ; =0x00000215
	cmp r1, r0
	bne _0222A204
	add r0, r7, #0
	add r1, r5, #0
	bl SaveMysteryGift_TrySetSpecialCard
	b _0222A21C
_0222A204:
	cmp r6, #0
	bne _0222A214
	add r0, r7, #0
	add r1, r5, #0
	mov r2, #3
	bl SaveMysteryGift_TryInsertGift
	b _0222A21C
_0222A214:
	add r0, r7, #0
	add r1, r5, #0
	bl SaveMysteryGift_TryInsertCard
_0222A21C:
	ldr r0, [sp]
	bl ov74_022360A0
	ldr r1, _0222A238 ; =0x000029EC
	ldr r0, [sp, #4]
	mov r2, #0
	str r2, [r0, r1]
	ldr r2, _0222A23C ; =ov74_0222A130
	sub r1, r1, #4
	str r2, [r0, r1]
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222A234: .word 0x00000215
_0222A238: .word 0x000029EC
_0222A23C: .word ov74_0222A130
	thumb_func_end ov74_0222A174


	thumb_func_start ov74_0222A240
ov74_0222A240: ; 0x0222A240
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r6, r0, #0
	add r4, r1, #0
	bl OverlayManager_GetData
	cmp r4, #0
	bne _0222A254
	mov r5, #4
	b _0222A258
_0222A254:
	mov r5, #0
	mvn r5, r5
_0222A258:
	ldr r1, [r0, #0x48]
	add r4, r0, #0
	add r4, #0x48
	cmp r1, #0
	bne _0222A282
	mov r1, #0xa
	str r1, [sp]
	mov r1, #6
	str r1, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	mov r2, #0
	mov r1, #0x6b
	str r2, [sp, #0xc]
	lsl r1, r1, #2
	str r1, [sp, #0x10]
	ldr r0, [r0]
	add r1, r4, #0
	mov r3, #0x17
	bl AddWindowParameterized
_0222A282:
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x1f
	mov r3, #3
	bl DrawFrameAndWindow1
	ldr r1, _0222A2A0 ; =ov74_0223C260
	add r0, r6, #0
	mov r2, #2
	add r3, r4, #0
	str r5, [sp]
	bl ov74_0222A89C
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0222A2A0: .word ov74_0223C260
	thumb_func_end ov74_0222A240


	thumb_func_start ov74_0222A2A4
ov74_0222A2A4: ; 0x0222A2A4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, #0x48
	mov r1, #0
	bl ov74_02229F60
	add r0, r4, #0
	add r0, #0x58
	mov r1, #0
	bl ov74_02229F60
	ldr r0, _0222A2DC ; =0x000015D4
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0222A2D0
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
_0222A2D0:
	bl sub_0203A914
	add r0, r5, #0
	bl ov74_0222A5CC
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222A2DC: .word 0x000015D4
	thumb_func_end ov74_0222A2A4


	thumb_func_start ov74_0222A2E0
ov74_0222A2E0: ; 0x0222A2E0
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r6, r0, #0
	bl OverlayManager_GetData
	add r5, r0, #0
	bl ov74_02235230
	cmp r0, #0
	beq _0222A2F8
	mov r1, #2
	b _0222A2FA
_0222A2F8:
	mov r1, #1
_0222A2FA:
	ldr r0, _0222A354 ; =0x000015D4
	str r1, [r5, r0]
	add r0, r5, #0
	add r0, #0x38
	mov r1, #0
	bl ov74_02229F60
	add r4, r5, #0
	ldr r0, [r5, #0x48]
	add r4, #0x48
	cmp r0, #0
	bne _0222A332
	mov r0, #0xa
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r2, #0
	mov r0, #0x6b
	str r2, [sp, #0xc]
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r1, r4, #0
	mov r3, #0x17
	bl AddWindowParameterized
_0222A332:
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x1f
	mov r3, #3
	bl DrawFrameAndWindow1
	mov r2, #2
	ldr r1, _0222A358 ; =ov74_0223C250
	add r0, r6, #0
	add r3, r4, #0
	str r2, [sp]
	bl ov74_0222A89C
	mov r0, #5
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	nop
_0222A354: .word 0x000015D4
_0222A358: .word ov74_0223C250
	thumb_func_end ov74_0222A2E0


	thumb_func_start ov74_0222A35C
ov74_0222A35C: ; 0x0222A35C
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r6, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, _0222A3C4 ; =0x000015D4
	mov r1, #4
	str r1, [r4, r0]
	add r0, r4, #0
	add r0, #0x38
	mov r1, #0
	bl ov74_02229F60
	add r5, r4, #0
	ldr r0, [r4, #0x48]
	add r5, #0x48
	cmp r0, #0
	bne _0222A3A2
	mov r0, #0xa
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r2, #0
	mov r0, #0x6b
	str r2, [sp, #0xc]
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r4]
	add r1, r5, #0
	mov r3, #0x17
	bl AddWindowParameterized
_0222A3A2:
	add r0, r5, #0
	mov r1, #1
	mov r2, #0x1f
	mov r3, #3
	bl DrawFrameAndWindow1
	mov r0, #0x50
	str r0, [sp]
	ldr r1, _0222A3C8 ; =ov74_0223C220
	add r0, r6, #0
	mov r2, #2
	add r3, r5, #0
	bl ov74_0222A89C
	mov r0, #5
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0222A3C4: .word 0x000015D4
_0222A3C8: .word ov74_0223C220
	thumb_func_end ov74_0222A35C


	thumb_func_start ov74_0222A3CC
ov74_0222A3CC: ; 0x0222A3CC
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r6, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, _0222A434 ; =0x000015D4
	mov r1, #3
	str r1, [r4, r0]
	add r0, r4, #0
	add r0, #0x38
	mov r1, #0
	bl ov74_02229F60
	add r5, r4, #0
	ldr r0, [r4, #0x48]
	add r5, #0x48
	cmp r0, #0
	bne _0222A412
	mov r0, #0xa
	str r0, [sp]
	mov r0, #6
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r2, #0
	mov r0, #0x6b
	str r2, [sp, #0xc]
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r4]
	add r1, r5, #0
	mov r3, #0x17
	bl AddWindowParameterized
_0222A412:
	add r0, r5, #0
	mov r1, #1
	mov r2, #0x1f
	mov r3, #3
	bl DrawFrameAndWindow1
	mov r0, #0x4f
	str r0, [sp]
	ldr r1, _0222A438 ; =ov74_0223C230
	add r0, r6, #0
	mov r2, #2
	add r3, r5, #0
	bl ov74_0222A89C
	mov r0, #5
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0222A434: .word 0x000015D4
_0222A438: .word ov74_0223C230
	thumb_func_end ov74_0222A3CC


	thumb_func_start ov74_0222A43C
ov74_0222A43C: ; 0x0222A43C
	push {r4, r5, lr}
	sub sp, #0x14
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r1, [r0, #0x48]
	add r4, #0x48
	cmp r1, #0
	bne _0222A470
	mov r1, #0xa
	str r1, [sp]
	mov r1, #6
	str r1, [sp, #4]
	mov r1, #4
	str r1, [sp, #8]
	mov r2, #0
	mov r1, #0x6b
	str r2, [sp, #0xc]
	lsl r1, r1, #2
	str r1, [sp, #0x10]
	ldr r0, [r0]
	add r1, r4, #0
	mov r3, #0x17
	bl AddWindowParameterized
_0222A470:
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x1f
	mov r3, #3
	bl DrawFrameAndWindow1
	mov r0, #4
	str r0, [sp]
	ldr r1, _0222A490 ; =ov74_0223C240
	add r0, r5, #0
	mov r2, #2
	add r3, r4, #0
	bl ov74_0222A89C
	add sp, #0x14
	pop {r4, r5, pc}
	.balign 4, 0
_0222A490: .word ov74_0223C240
	thumb_func_end ov74_0222A43C


	thumb_func_start ov74_0222A494
ov74_0222A494: ; 0x0222A494
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, #0x48
	mov r1, #0
	bl ov74_02229F60
	add r0, r4, #0
	add r0, #0x58
	mov r1, #0
	bl ov74_02229F60
	bl sub_0203A914
	ldr r0, _0222A4C8 ; =0x000015D4
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _0222A4C0
	bl ov74_02229DF8
_0222A4C0:
	add r0, r5, #0
	bl ov74_0222A5CC
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222A4C8: .word 0x000015D4
	thumb_func_end ov74_0222A494


	thumb_func_start ov74_0222A4CC
ov74_0222A4CC: ; 0x0222A4CC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x18
	mov r2, #3
	bl ov74_0222AA18
	add r0, r4, #0
	add r0, #0x48
	mov r1, #0
	bl ov74_02229F60
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229E28
	ldr r0, _0222A500 ; =ov74_0223D0A8
	mov r1, #0x25
	str r1, [r0, #0x10]
	mov r0, #0x20
	pop {r3, r4, r5, pc}
	nop
_0222A500: .word ov74_0223D0A8
	thumb_func_end ov74_0222A4CC


	thumb_func_start ov74_0222A504
ov74_0222A504: ; 0x0222A504
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, #0x80
	ldr r0, [r0]
	sub r0, r0, #2
	cmp r0, #2
	bhi _0222A51C
	mov r0, #0x31
	pop {r3, r4, r5, pc}
_0222A51C:
	add r0, r4, #0
	add r0, #0x48
	mov r1, #0
	bl ov74_02229F60
	add r4, #0x18
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #7
	bl ov74_0222AA18
	mov r0, #0x21
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov74_0222A504


	thumb_func_start ov74_0222A538
ov74_0222A538: ; 0x0222A538
	push {r3, lr}
	ldr r0, _0222A55C ; =ov74_0223D0A8
	ldr r0, [r0, #0x10]
	cmp r0, #0x28
	beq _0222A54A
	cmp r0, #0x29
	beq _0222A54A
	cmp r0, #0x30
	bne _0222A558
_0222A54A:
	bl ov74_022365FC
	cmp r0, #0
	beq _0222A558
	ldr r0, _0222A55C ; =ov74_0223D0A8
	mov r1, #0x2b
	str r1, [r0, #0x10]
_0222A558:
	mov r0, #0x24
	pop {r3, pc}
	.balign 4, 0
_0222A55C: .word ov74_0223D0A8
	thumb_func_end ov74_0222A538


	thumb_func_start ov74_0222A560
ov74_0222A560: ; 0x0222A560
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x18
	mov r2, #3
	bl ov74_0222AA18
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229E28
	add r0, r4, #0
	add r0, #0x48
	mov r1, #0
	bl ov74_02229F60
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229E28
	mov r1, #1
	ldr r0, _0222A5A4 ; =0x000015E0
	lsl r1, r1, #0xc
	str r1, [r4, r0]
	ldr r0, _0222A5A8 ; =0x0000267C
	mov r1, #0
	str r1, [r4, r0]
	mov r0, #0x1b
	pop {r3, r4, r5, pc}
	nop
_0222A5A4: .word 0x000015E0
_0222A5A8: .word 0x0000267C
	thumb_func_end ov74_0222A560


	thumb_func_start ov74_0222A5AC
ov74_0222A5AC: ; 0x0222A5AC
	push {r4, lr}
	add r4, r0, #0
	bl OverlayManager_GetData
	add r0, #0x38
	mov r1, #0
	bl ov74_02229F60
	add r0, r4, #0
	mov r1, #0xc4
	mov r2, #0
	bl ov74_0222A94C
	mov r0, #3
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222A5AC


	thumb_func_start ov74_0222A5CC
ov74_0222A5CC: ; 0x0222A5CC
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r6, r0, #0
	bl OverlayManager_GetData
	add r5, r0, #0
	ldr r0, [r5, #4]
	bl Save_MysteryGift_Get
	ldr r0, _0222A648 ; =0x000005C8
	ldr r1, [r5, r0]
	cmp r1, #0x1e
	bne _0222A5F2
	mov r1, #1
	add r0, r0, #4
	str r1, [r5, r0]
	add r0, r5, #0
	bl ov74_0222CE10
_0222A5F2:
	add r0, r5, #0
	add r0, #0x28
	mov r1, #0
	bl ov74_02229F60
	add r4, r5, #0
	ldr r0, [r5, #0x38]
	add r4, #0x38
	cmp r0, #0
	bne _0222A626
	mov r0, #9
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	mov r0, #8
	str r0, [sp, #8]
	mov r2, #0
	mov r0, #0x49
	str r2, [sp, #0xc]
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r5]
	add r1, r4, #0
	mov r3, #0xf
	bl AddWindowParameterized
_0222A626:
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x1f
	mov r3, #3
	bl DrawFrameAndWindow1
	mov r0, #1
	str r0, [sp]
	ldr r1, _0222A64C ; =ov74_0223C2B0
	add r0, r6, #0
	mov r2, #4
	add r3, r4, #0
	bl ov74_0222A89C
	mov r0, #4
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0222A648: .word 0x000005C8
_0222A64C: .word ov74_0223C2B0
	thumb_func_end ov74_0222A5CC


	thumb_func_start ov74_0222A650
ov74_0222A650: ; 0x0222A650
	push {r4, lr}
	bl OverlayManager_GetData
	ldr r1, _0222A680 ; =0x000005C8
	add r4, r0, #0
	ldr r2, [r4, r1]
	cmp r2, #0x1e
	bne _0222A66A
	mov r2, #1
	add r1, r1, #4
	str r2, [r4, r1]
	bl ov74_0222CE10
_0222A66A:
	ldr r2, _0222A684 ; =0x000015D8
	mov r0, #0
	ldr r2, [r4, r2]
	mov r1, #0x36
	mov r3, #2
	bl ov74_0223539C
	mov r0, #0
	mvn r0, r0
	pop {r4, pc}
	nop
_0222A680: .word 0x000005C8
_0222A684: .word 0x000015D8
	thumb_func_end ov74_0222A650


	thumb_func_start ov74_0222A688
ov74_0222A688: ; 0x0222A688
	push {r4, lr}
	bl OverlayManager_GetData
	ldr r1, _0222A6B8 ; =0x000005C8
	add r4, r0, #0
	ldr r2, [r4, r1]
	cmp r2, #0x1e
	bne _0222A6A2
	mov r2, #1
	add r1, r1, #4
	str r2, [r4, r1]
	bl ov74_0222CE10
_0222A6A2:
	ldr r2, _0222A6BC ; =0x000015D8
	mov r0, #0
	ldr r2, [r4, r2]
	mov r1, #0x37
	mov r3, #2
	bl ov74_0223539C
	mov r0, #0
	mvn r0, r0
	pop {r4, pc}
	nop
_0222A6B8: .word 0x000005C8
_0222A6BC: .word 0x000015D8
	thumb_func_end ov74_0222A688


	thumb_func_start ov74_0222A6C0
ov74_0222A6C0: ; 0x0222A6C0
	push {r4, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, _0222A6F0 ; =0x000005C8
	ldr r1, [r4, r0]
	cmp r1, #0x1e
	bne _0222A6D6
	mov r1, #1
	add r0, r0, #4
	str r1, [r4, r0]
_0222A6D6:
	mov r0, #1
	bl ov74_02235390
	ldr r2, _0222A6F4 ; =0x000015D8
	mov r0, #0
	ldr r2, [r4, r2]
	mov r1, #0x35
	mov r3, #2
	bl ov74_0223539C
	mov r0, #0
	mvn r0, r0
	pop {r4, pc}
	.balign 4, 0
_0222A6F0: .word 0x000005C8
_0222A6F4: .word 0x000015D8
	thumb_func_end ov74_0222A6C0


	thumb_func_start ov74_0222A6F8
ov74_0222A6F8: ; 0x0222A6F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r3, #0
	ldr r3, _0222A740 ; =_0223B3A0
	add r7, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	mov ip, r2
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	lsr r1, r6, #0xb
	str r0, [r2]
	add r0, sp, #0
	strb r1, [r0, #0x12]
	lsr r1, r5, #0xe
	strb r1, [r0, #0x13]
	lsl r1, r4, #0x18
	add r0, r7, #0
	lsr r1, r1, #0x18
	mov r2, ip
	mov r3, #0
	bl InitBgFromTemplate
	lsl r1, r4, #0x18
	add r0, r7, #0
	lsr r1, r1, #0x18
	bl BgClearTilemapBufferAndCommit
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222A740: .word _0223B3A0
	thumb_func_end ov74_0222A6F8


	thumb_func_start ov74_0222A744
ov74_0222A744: ; 0x0222A744
	push {r3, r4, r5, lr}
	sub sp, #0x10
	ldr r5, _0222A79C ; =_0223B390
	add r3, sp, #0
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	mov r1, #0
	mov r2, #0xf
	add r0, r4, #0
	lsl r2, r2, #0xc
	add r3, r1, #0
	bl ov74_0222A6F8
	mov r1, #1
	mov r2, #0x3e
	add r0, r4, #0
	lsl r2, r2, #0xa
	lsl r3, r1, #0xf
	bl ov74_0222A6F8
	mov r2, #0xe
	add r0, r4, #0
	mov r1, #4
	lsl r2, r2, #0xa
	mov r3, #0
	bl ov74_0222A6F8
	mov r2, #0x1e
	mov r3, #1
	add r0, r4, #0
	mov r1, #5
	lsl r2, r2, #0xa
	lsl r3, r3, #0xe
	bl ov74_0222A6F8
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222A79C: .word _0223B390
	thumb_func_end ov74_0222A744


	thumb_func_start ov74_0222A7A0
ov74_0222A7A0: ; 0x0222A7A0
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x20
	mov r2, #4
	str r0, [sp]
	mov r0, #0x54
	add r3, r2, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0
	add r3, #0xfc
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	mov r0, #0x54
	str r0, [sp, #0xc]
	mov r0, #0x71
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x54
	str r0, [sp, #0xc]
	mov r0, #0x71
	mov r1, #2
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #8
	mov r2, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #5
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	add r0, r4, #0
	mov r1, #5
	bl BgCommitTilemapBufferToVram
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222A7A0


	thumb_func_start ov74_0222A81C
ov74_0222A81C: ; 0x0222A81C
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x54
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0
	add r3, r0, #0
	add r2, r1, #0
	add r3, #0x8f
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	mov r0, #0x54
	str r0, [sp, #0xc]
	mov r0, #0x71
	add r2, r4, #0
	add r3, r1, #0
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	mov r0, #0x54
	str r0, [sp, #0xc]
	mov r0, #0x71
	mov r1, #2
	add r2, r4, #0
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #8
	mov r2, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	add r0, r4, #0
	mov r1, #1
	bl BgCommitTilemapBufferToVram
	add r0, r4, #0
	bl ov74_0222A7A0
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222A81C


	thumb_func_start ov74_0222A89C
ov74_0222A89C: ; 0x0222A89C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	str r0, [sp]
	add r5, r1, #0
	add r7, r2, #0
	str r3, [sp, #4]
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, [r4, #0x7c]
	cmp r0, #0
	beq _0222A8B8
	bl ListMenuItems_Delete
_0222A8B8:
	add r0, r7, #0
	mov r1, #0x54
	bl ListMenuItems_New
	str r0, [r4, #0x7c]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x54
	bl NewMsgDataFromNarc
	mov r6, #0
	str r0, [r4, #0x10]
	cmp r7, #0
	ble _0222A8EA
_0222A8D6:
	ldr r0, [r4, #0x7c]
	ldr r1, [r4, #0x10]
	ldr r2, [r5]
	ldr r3, [r5, #4]
	bl ListMenuItems_AppendFromMsgData
	add r6, r6, #1
	add r5, #8
	cmp r6, r7
	blt _0222A8D6
_0222A8EA:
	ldr r0, [r4, #0x10]
	bl DestroyMsgData
	ldr r3, _0222A948 ; =ov74_0223C270
	add r2, sp, #8
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r4, #0x7c]
	str r0, [sp, #8]
	add r0, sp, #8
	strh r7, [r0, #0x12]
	ldrh r1, [r0, #0x12]
	strh r1, [r0, #0x10]
	ldr r0, [sp, #4]
	str r0, [sp, #0x14]
	ldr r0, [r4, #0x78]
	cmp r0, #0
	beq _0222A922
	mov r1, #0
	add r2, r1, #0
	bl DestroyListMenu
_0222A922:
	mov r1, #0
	add r0, sp, #8
	add r2, r1, #0
	mov r3, #0x54
	bl ListMenuInit
	str r0, [r4, #0x78]
	mov r0, #0
	ldr r2, [sp, #0x40]
	mvn r0, r0
	cmp r2, r0
	beq _0222A944
	add r4, #0x18
	ldr r0, [sp]
	add r1, r4, #0
	bl ov74_0222AA18
_0222A944:
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222A948: .word ov74_0223C270
	thumb_func_end ov74_0222A89C


	thumb_func_start ov74_0222A94C
ov74_0222A94C: ; 0x0222A94C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	str r0, [sp, #0x14]
	add r7, r1, #0
	str r2, [sp, #0x20]
	bl OverlayManager_GetData
	str r0, [sp, #0x1c]
	ldr r0, [r0, #4]
	mov r5, #0
	bl Save_MysteryGift_Get
	ldr r1, _0222AA10 ; =ov74_0223C220
	ldr r4, [sp, #0x1c]
	ldr r2, [r1, #0x70]
	ldr r1, [r1, #0x74]
	str r0, [sp, #0x18]
	add r4, #0x28
	add r5, r5, #1
	str r2, [sp, #0x24]
	str r1, [sp, #0x28]
	bl SaveMysteryGift_HasAnyCard
	cmp r0, #0
	beq _0222A992
	lsl r6, r5, #3
	add r0, sp, #0x24
	add r1, r0, r6
	ldr r0, _0222AA10 ; =ov74_0223C220
	add r5, r5, #1
	ldr r3, [r0, #0x78]
	ldr r2, [r0, #0x7c]
	add r0, sp, #0x24
	str r3, [r0, r6]
	str r2, [r1, #4]
_0222A992:
	ldr r0, [sp, #0x18]
	bl SaveMysteryGift_SpecialCardTagIsValid
	cmp r0, #0
	beq _0222A9B0
	lsl r6, r5, #3
	add r0, sp, #0x24
	add r1, r0, r6
	ldr r0, _0222AA14 ; =ov74_0223C2A0
	add r5, r5, #1
	ldr r3, [r0]
	ldr r2, [r0, #4]
	add r0, sp, #0x24
	str r3, [r0, r6]
	str r2, [r1, #4]
_0222A9B0:
	lsl r6, r5, #3
	add r0, sp, #0x24
	add r1, r0, r6
	ldr r0, _0222AA14 ; =ov74_0223C2A0
	ldr r3, [r0, #8]
	ldr r2, [r0, #0xc]
	add r0, sp, #0x24
	str r3, [r0, r6]
	str r2, [r1, #4]
	ldr r0, [r4]
	cmp r0, #0
	bne _0222A9EE
	mov r0, #7
	str r0, [sp]
	mov r0, #0x14
	str r0, [sp, #4]
	add r0, r5, #1
	lsl r0, r0, #0x19
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r2, #0
	lsl r0, r7, #0x10
	str r2, [sp, #0xc]
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x1c]
	add r1, r4, #0
	ldr r0, [r0]
	mov r3, #6
	bl AddWindowParameterized
_0222A9EE:
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x1f
	mov r3, #3
	bl DrawFrameAndWindow1
	ldr r0, [sp, #0x20]
	add r1, sp, #0x24
	str r0, [sp]
	ldr r0, [sp, #0x14]
	add r2, r5, #1
	add r3, r4, #0
	bl ov74_0222A89C
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	nop
_0222AA10: .word ov74_0223C220
_0222AA14: .word ov74_0223C2A0
	thumb_func_end ov74_0222A94C


	thumb_func_start ov74_0222AA18
ov74_0222AA18: ; 0x0222AA18
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r1, #0
	add r7, r2, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x54
	bl NewMsgDataFromNarc
	str r0, [r4, #0x10]
	mov r0, #0x54
	bl MessageFormat_New
	str r0, [r4, #0xc]
	mov r0, #1
	mov r1, #6
	bl GetFontAttribute
	add r1, r0, #0
	add r0, r5, #0
	bl FillWindowPixelBuffer
	ldr r6, [r4, #0x14]
	cmp r6, #0
	bne _0222AA60
	ldr r0, [r4, #0xc]
	ldr r1, [r4, #0x10]
	add r2, r7, #0
	mov r3, #0x54
	bl ReadMsgData_ExpandPlaceholders
	add r6, r0, #0
_0222AA60:
	mov r3, #0
	str r3, [sp]
	ldr r0, [r4, #0x68]
	mov r1, #1
	str r0, [sp, #4]
	ldr r0, _0222AAA8 ; =0x0001020F
	add r2, r6, #0
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	add r0, r5, #0
	bl AddTextPrinterParameterizedWithColor
	str r0, [r4, #0x6c]
	ldr r0, [r4, #0x14]
	cmp r0, #0
	bne _0222AA86
	add r0, r6, #0
	bl String_Delete
_0222AA86:
	add r0, r5, #0
	mov r1, #0
	mov r2, #1
	mov r3, #2
	bl DrawFrameAndWindow2
	ldr r0, [r4, #0x10]
	bl DestroyMsgData
	ldr r0, [r4, #0xc]
	bl MessageFormat_Delete
	mov r0, #0xff
	str r0, [r4, #0x68]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222AAA8: .word 0x0001020F
	thumb_func_end ov74_0222AA18


	thumb_func_start ov74_0222AAAC
ov74_0222AAAC: ; 0x0222AAAC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r1, #0
	add r6, r2, #0
	bl OverlayManager_GetData
	mov r0, #0x25
	mov r1, #0x54
	bl String_New
	add r1, r6, #0
	mov r2, #0x24
	add r4, r0, #0
	bl CopyU16ArrayToStringN
	mov r0, #0
	mov r1, #6
	bl GetFontAttribute
	add r1, r0, #0
	add r0, r5, #0
	bl FillWindowPixelBuffer
	mov r1, #0
	str r1, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0222AB08 ; =0x0001020F
	add r2, r4, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r3, r1, #0
	str r1, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	mov r1, #0
	mov r2, #0x1f
	mov r3, #3
	bl DrawFrameAndWindow1
	add r0, r4, #0
	bl String_Delete
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222AB08: .word 0x0001020F
	thumb_func_end ov74_0222AAAC


	thumb_func_start ov74_0222AB0C
ov74_0222AB0C: ; 0x0222AB0C
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r1, #0
	add r6, r2, #0
	bl OverlayManager_GetData
	ldr r0, [r0, #0x78]
	bl ListMenu_ProcessInput
	add r4, r0, #0
	mov r0, #1
	mvn r0, r0
	cmp r4, r0
	beq _0222AB30
	add r0, r0, #1
	cmp r4, r0
	beq _0222AB66
	b _0222AB4A
_0222AB30:
	ldr r0, _0222AB68 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	cmp r6, #0
	beq _0222AB66
	add r0, r7, #0
	blx r6
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222AB66
	str r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
_0222AB4A:
	ldr r0, _0222AB68 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	cmp r4, #0
	beq _0222AB66
	ldr r0, _0222AB6C ; =ov74_0223D0A8
	str r4, [r0, #8]
	add r0, r7, #0
	blx r4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222AB66
	str r0, [r5]
_0222AB66:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222AB68: .word SEQ_SE_DP_SELECT
_0222AB6C: .word ov74_0223D0A8
	thumb_func_end ov74_0222AB0C


	thumb_func_start ov74_0222AB70
ov74_0222AB70: ; 0x0222AB70
	push {r4, r5, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r4, r1, #0
	bl ResetAllTextPrinters
	mov r0, #0
	add r1, r0, #0
	mov r2, #0x54
	bl LoadFontPal0
	mov r0, #0
	mov r1, #0x20
	mov r2, #0x54
	bl LoadFontPal0
	ldr r0, [r4, #8]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x54
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0
	mov r2, #1
	mov r3, #2
	bl LoadUserFrameGfx2
	mov r0, #1
	str r0, [sp]
	mov r0, #0x54
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0
	mov r2, #0x1f
	mov r3, #3
	bl LoadUserFrameGfx1
	mov r0, #5
	ldr r1, _0222AC18 ; =0x00007D8C
	lsl r0, r0, #0x18
	strh r1, [r0]
	add r0, r4, #0
	add r0, #0x18
	bl WindowIsInUse
	cmp r0, #0
	bne _0222ABF4
	mov r0, #0x13
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r2, #0
	add r1, r4, #0
	str r2, [sp, #0xc]
	mov r0, #0x28
	str r0, [sp, #0x10]
	ldr r0, [r4]
	add r1, #0x18
	mov r3, #2
	bl AddWindowParameterized
_0222ABF4:
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0x18
	mov r2, #0
	bl ov74_0222AA18
	add r0, r5, #0
	mov r1, #0xc4
	mov r2, #0
	bl ov74_0222A94C
	ldr r0, [r4]
	bl ov74_0222A81C
	mov r0, #1
	add sp, #0x14
	pop {r4, r5, pc}
	nop
_0222AC18: .word 0x00007D8C
	thumb_func_end ov74_0222AB70


	thumb_func_start ov74_0222AC1C
ov74_0222AC1C: ; 0x0222AC1C
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r1, _0222ACC8 ; =0x000015E0
	add r0, r6, #0
	add r1, r4, r1
	bl ov74_02236AE0
	cmp r0, #4
	bhi _0222ACC4
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222AC42: ; jump table
	.short _0222ACC4 - _0222AC42 - 2 ; case 0
	.short _0222AC4C - _0222AC42 - 2 ; case 1
	.short _0222AC78 - _0222AC42 - 2 ; case 2
	.short _0222AC78 - _0222AC42 - 2 ; case 3
	.short _0222AC8C - _0222AC42 - 2 ; case 4
_0222AC4C:
	ldr r1, _0222ACCC ; =0x00001658
	add r0, r4, #0
	mov r2, #0xea
	add r0, #0x8c
	add r1, r4, r1
	lsl r2, r2, #2
	bl memcpy
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	add r0, r4, #0
	mov r1, #0x1b
	add r0, #0x84
	str r1, [r0]
	mov r0, #0x13
	str r0, [r5]
	ldr r0, _0222ACD0 ; =0x000015DC
	mov r1, #0
	str r1, [r4, r0]
	pop {r4, r5, r6, pc}
_0222AC78:
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	ldr r0, _0222ACD0 ; =0x000015DC
	mov r1, #0
	str r1, [r4, r0]
	mov r0, #0x11
	str r0, [r5]
	pop {r4, r5, r6, pc}
_0222AC8C:
	mov r0, #0x9a
	lsl r0, r0, #6
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	mov r0, #0x9a
	lsl r0, r0, #6
	add r0, r4, r0
	bl RemoveWindow
	ldr r0, [r4]
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r0, _0222ACD4 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r0, r6, #0
	mov r1, #0xc4
	mov r2, #0
	bl ov74_0222A94C
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #3
	str r0, [r5]
_0222ACC4:
	pop {r4, r5, r6, pc}
	nop
_0222ACC8: .word 0x000015E0
_0222ACCC: .word 0x00001658
_0222ACD0: .word 0x000015DC
_0222ACD4: .word SEQ_SE_DP_SELECT
	thumb_func_end ov74_0222AC1C


	thumb_func_start ov74_0222ACD8
ov74_0222ACD8: ; 0x0222ACD8
	push {r3, r4, r5, r6, lr}
	sub sp, #0x5c
	add r5, r0, #0
	ldr r0, _0222AD64 ; =0x0000266C
	ldr r4, [r5, r0]
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _0222ACEC
	mov r4, #0xb
_0222ACEC:
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r5]
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	mov r0, #0x54
	bl MessageFormat_New
	mov r1, #2
	str r1, [sp]
	mov r1, #1
	str r1, [sp, #4]
	ldr r2, _0222AD68 ; =0x00002670
	mov r1, #0
	ldr r2, [r5, r2]
	mov r3, #5
	add r6, r0, #0
	bl BufferIntegerAsString
	mov r0, #0x1f
	mov r1, #0x9a
	str r0, [sp]
	mov r0, #3
	lsl r1, r1, #6
	mov r3, #0x32
	str r0, [sp, #4]
	add r0, sp, #8
	add r1, r5, r1
	mov r2, #1
	lsl r3, r3, #4
	bl ov74_02235414
	add r0, sp, #8
	mov r1, #0x18
	mov r2, #0x10
	mov r3, #0x64
	bl ov74_02235464
	add r0, sp, #8
	mov r1, #0
	mov r2, #1
	bl ov74_0223546C
	str r6, [sp, #0x1c]
	str r4, [sp]
	mov r2, #4
	ldr r0, [r5]
	add r1, sp, #8
	add r3, r2, #0
	bl ov74_02235568
	add r0, r6, #0
	bl MessageFormat_Delete
	add sp, #0x5c
	pop {r3, r4, r5, r6, pc}
	nop
_0222AD64: .word 0x0000266C
_0222AD68: .word 0x00002670
	thumb_func_end ov74_0222ACD8


	thumb_func_start ov74_0222AD6C
ov74_0222AD6C: ; 0x0222AD6C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r1, r0, #0
	add r0, #0x80
	ldr r0, [r0]
	cmp r0, #3
	bne _0222AD82
	mov r4, #0x16
	b _0222ADAC
_0222AD82:
	cmp r0, #4
	bne _0222AD8A
	mov r4, #0x1a
	b _0222ADAC
_0222AD8A:
	cmp r0, #2
	bne _0222AD92
	mov r4, #0x17
	b _0222ADAC
_0222AD92:
	cmp r0, #1
	bne _0222AD9A
	mov r4, #0x1c
	b _0222ADAC
_0222AD9A:
	cmp r0, #5
	bne _0222ADAC
	add r0, r5, #0
	add r1, #0x18
	mov r2, #9
	mov r3, #0x34
	bl ov74_0222ADBC
	pop {r3, r4, r5, pc}
_0222ADAC:
	add r0, r5, #0
	add r1, #0x18
	add r2, r4, #0
	mov r3, #0x33
	bl ov74_0222ADBC
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov74_0222AD6C


	thumb_func_start ov74_0222ADBC
ov74_0222ADBC: ; 0x0222ADBC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	add r6, r1, #0
	add r5, r2, #0
	add r7, r3, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	cmp r6, #0
	beq _0222AE16
	cmp r5, #0
	beq _0222AE16
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x54
	bl NewMsgDataFromNarc
	str r0, [sp, #4]
	mov r0, #0x54
	bl MessageFormat_New
	ldr r1, [sp, #4]
	add r2, r5, #0
	mov r3, #0x54
	str r0, [sp, #8]
	bl ReadMsgData_ExpandPlaceholders
	str r0, [r4, #0x14]
	mov r0, #1
	str r0, [r4, #0x68]
	ldr r0, [sp]
	add r1, r6, #0
	add r2, r5, #0
	bl ov74_0222AA18
	ldr r0, [sp, #8]
	str r7, [r4, #0x74]
	bl MessageFormat_Delete
	ldr r0, [sp, #4]
	bl DestroyMsgData
	b _0222AE36
_0222AE16:
	ldr r0, [r4, #0x6c]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0222AE36
	ldr r0, [r4, #0x14]
	bl String_Delete
	mov r0, #0
	str r0, [r4, #0x14]
	str r0, [r4, #0x68]
	add sp, #0xc
	ldr r0, [r4, #0x74]
	pop {r4, r5, r6, r7, pc}
_0222AE36:
	mov r0, #0x32
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov74_0222ADBC


	thumb_func_start ov74_0222AE3C
ov74_0222AE3C: ; 0x0222AE3C
	push {r3, lr}
	ldr r1, _0222AE68 ; =0x000015D4
	ldr r0, [r0, r1]
	cmp r0, #4
	bhi _0222AE64
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222AE52: ; jump table
	.short _0222AE64 - _0222AE52 - 2 ; case 0
	.short _0222AE5C - _0222AE52 - 2 ; case 1
	.short _0222AE64 - _0222AE52 - 2 ; case 2
	.short _0222AE64 - _0222AE52 - 2 ; case 3
	.short _0222AE64 - _0222AE52 - 2 ; case 4
_0222AE5C:
	bl ov74_02229DF8
	bl sub_0203A914
_0222AE64:
	pop {r3, pc}
	nop
_0222AE68: .word 0x000015D4
	thumb_func_end ov74_0222AE3C


	thumb_func_start ov74_0222AE6C
ov74_0222AE6C: ; 0x0222AE6C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl ov74_0222CD88
	mov r0, #3
	mov r1, #0x54
	lsl r2, r0, #0x10
	bl Heap_Create
	ldr r1, _0222AF14 ; =0x000029F8
	add r0, r5, #0
	mov r2, #0x54
	bl OverlayManager_CreateAndGetData
	ldr r2, _0222AF14 ; =0x000029F8
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x54
	bl BgConfig_Alloc
	str r0, [r4]
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	bl ov74_0222FCA4
	ldr r0, [r4]
	bl ov74_0222A744
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FBF4
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	ldr r1, _0222AF18 ; =0x0000047E
	mov r0, #0xa
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	mov r0, #0x54
	bl ov74_0223512C
	bl ov74_02235230
	cmp r0, #0
	beq _0222AEE8
	ldr r0, _0222AF1C ; =0x000015D4
	mov r1, #2
	str r1, [r4, r0]
	ldr r0, _0222AF20 ; =gGameVersion
	ldrb r0, [r0]
	bl sub_0201A4B0
	mov r0, #1
	bl ov74_02236034
_0222AEE8:
	ldr r0, _0222AF24 ; =0x000005C8
	mov r1, #0x1d
	str r1, [r4, r0]
	add r0, r5, #0
	bl OverlayManager_GetArgs
	ldr r0, [r0, #8]
	str r0, [r4, #4]
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #8]
	mov r0, #0xff
	mov r2, #0x57
	str r0, [r4, #0x68]
	mov r0, #0
	mov r1, #0x59
	lsl r2, r2, #4
	bl Heap_Create
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_0222AF14: .word 0x000029F8
_0222AF18: .word 0x0000047E
_0222AF1C: .word 0x000015D4
_0222AF20: .word gGameVersion
_0222AF24: .word 0x000005C8
	thumb_func_end ov74_0222AE6C


	thumb_func_start ov74_0222AF28
ov74_0222AF28: ; 0x0222AF28
	push {r4, r5, lr}
	sub sp, #0x2c
	add r4, r0, #0
	ldr r0, _0222B0C0 ; =0x00004E21
	mov r3, #1
	str r0, [sp]
	str r3, [sp, #4]
	mov r1, #0x54
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	add r1, #0xd8
	ldr r0, [r0, r1]
	mov r1, #0x71
	mov r2, #0x2b
	bl AddCharResObjFromNarc
	str r0, [r4, #0x58]
	ldr r0, _0222B0C0 ; =0x00004E21
	mov r1, #0x54
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r4, #0xc]
	add r1, #0xdc
	ldr r0, [r0, r1]
	mov r1, #0x71
	mov r2, #0x28
	mov r3, #0
	bl AddPlttResObjFromNarc
	str r0, [r4, #0x5c]
	ldr r0, _0222B0C0 ; =0x00004E21
	mov r1, #0x54
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	add r1, #0xe0
	ldr r0, [r0, r1]
	mov r1, #0x71
	mov r2, #0x2a
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x60]
	ldr r0, _0222B0C0 ; =0x00004E21
	mov r1, #0x54
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	add r1, #0xe4
	ldr r0, [r0, r1]
	mov r1, #0x71
	mov r2, #0x29
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x64]
	ldr r0, _0222B0C4 ; =0x00004E22
	mov r1, #0x54
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	add r1, #0xd8
	ldr r0, [r0, r1]
	mov r1, #0x71
	mov r2, #0x2b
	mov r3, #1
	bl AddCharResObjFromNarc
	str r0, [r4, #0x70]
	ldr r0, _0222B0C4 ; =0x00004E22
	mov r1, #0x54
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r4, #0xc]
	add r1, #0xdc
	ldr r0, [r0, r1]
	mov r1, #0x71
	mov r2, #0x28
	mov r3, #0
	bl AddPlttResObjFromNarc
	str r0, [r4, #0x74]
	ldr r0, _0222B0C4 ; =0x00004E22
	mov r1, #0x54
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	add r1, #0xe0
	ldr r0, [r0, r1]
	mov r1, #0x71
	mov r2, #0x2a
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x78]
	ldr r0, _0222B0C4 ; =0x00004E22
	mov r1, #0x54
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0xc]
	add r1, #0xe4
	ldr r0, [r0, r1]
	mov r1, #0x71
	mov r2, #0x29
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	str r0, [r4, #0x7c]
	ldr r0, [r4, #0x58]
	bl SpriteTransfer_CreateCharTransferTask
	ldr r0, [r4, #0x70]
	bl SpriteTransfer_CreateCharTransferTask
	ldr r0, [r4, #0x5c]
	bl SpriteTransfer_CreatePlttTransferTask
	ldr r0, [r4, #0x74]
	bl SpriteTransfer_CreatePlttTransferTask
	mov r0, #0
	mov r5, #0x4b
	ldr r2, [r4, #0xc]
	ldr r1, _0222B0C0 ; =0x00004E21
	mvn r0, r0
	str r1, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	lsl r5, r5, #2
	ldr r3, [r2, r5]
	str r3, [sp, #0x14]
	add r3, r5, #4
	ldr r3, [r2, r3]
	str r3, [sp, #0x18]
	add r3, r5, #0
	add r3, #8
	ldr r3, [r2, r3]
	add r5, #0xc
	str r3, [sp, #0x1c]
	ldr r2, [r2, r5]
	add r3, r1, #0
	str r2, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, r4, #0
	add r0, #0x10
	add r2, r1, #0
	bl CreateSpriteResourcesHeader
	ldr r2, [r4, #0xc]
	ldr r1, _0222B0C4 ; =0x00004E22
	mov r0, #0
	mov r5, #0x4b
	add r4, #0x10
	str r1, [sp]
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	lsl r5, r5, #2
	ldr r3, [r2, r5]
	add r4, #0x24
	str r3, [sp, #0x14]
	add r3, r5, #4
	ldr r3, [r2, r3]
	str r3, [sp, #0x18]
	add r3, r5, #0
	add r3, #8
	ldr r3, [r2, r3]
	add r5, #0xc
	str r3, [sp, #0x1c]
	ldr r2, [r2, r5]
	add r3, r1, #0
	str r2, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	add r0, r4, #0
	add r2, r1, #0
	bl CreateSpriteResourcesHeader
	add sp, #0x2c
	pop {r4, r5, pc}
	.balign 4, 0
_0222B0C0: .word 0x00004E21
_0222B0C4: .word 0x00004E22
	thumb_func_end ov74_0222AF28


	thumb_func_start ov74_0222B0C8
ov74_0222B0C8: ; 0x0222B0C8
	push {r4, lr}
	sub sp, #0x30
	cmp r1, #1
	beq _0222B0D4
	mov r3, #1
	b _0222B0D6
_0222B0D4:
	mov r3, #0
_0222B0D6:
	ldr r2, [r0, #0xc]
	add r0, #0x10
	ldr r2, [r2]
	str r2, [sp]
	mov r2, #0x24
	mul r2, r3
	add r0, r0, r2
	mov r3, #1
	lsl r3, r3, #0xc
	mov r2, #0
	str r0, [sp, #4]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r3, [sp, #0x18]
	str r3, [sp, #0x1c]
	add r0, sp, #0
	strh r2, [r0, #0x20]
	lsl r0, r3, #7
	str r0, [sp, #8]
	mov r0, #0xa
	lsl r2, r3, #5
	str r0, [sp, #0x24]
	mov r0, #0x54
	str r2, [sp, #0xc]
	str r1, [sp, #0x28]
	str r0, [sp, #0x2c]
	cmp r1, #2
	bne _0222B114
	lsl r0, r3, #8
	add r0, r2, r0
	str r0, [sp, #0xc]
_0222B114:
	add r0, sp, #0
	bl Sprite_CreateAffine
	add r4, r0, #0
	beq _0222B13C
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetPriority
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetDrawFlag
_0222B13C:
	add r0, r4, #0
	add sp, #0x30
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222B0C8


	thumb_func_start ov74_0222B144
ov74_0222B144: ; 0x0222B144
	push {r4, lr}
	mov r1, #1
	add r4, r0, #0
	bl ov74_0222B0C8
	ldr r1, _0222B198 ; =0x00003014
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #2
	bl Sprite_TryChangeAnimSeq
	ldr r0, _0222B198 ; =0x00003014
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetAnimationFrame
	ldr r0, _0222B198 ; =0x00003014
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0222B198 ; =0x00003014
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawPriority
	ldr r0, _0222B198 ; =0x00003014
	mov r1, #2
	ldr r0, [r4, r0]
	bl Sprite_SetAffineOverwriteMode
	ldr r0, _0222B198 ; =0x00003014
	ldr r0, [r4, r0]
	bl Sprite_GetMatrixPtr
	mov r1, #2
	lsl r1, r1, #0x12
	str r1, [r0]
	mov r1, #6
	lsl r1, r1, #0x10
	str r1, [r0, #4]
	pop {r4, pc}
	.balign 4, 0
_0222B198: .word 0x00003014
	thumb_func_end ov74_0222B144


	thumb_func_start ov74_0222B19C
ov74_0222B19C: ; 0x0222B19C
	push {r4, lr}
	mov r1, #2
	add r4, r0, #0
	bl ov74_0222B0C8
	ldr r1, _0222B1F0 ; =0x00003060
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #4
	bl Sprite_TryChangeAnimSeq
	ldr r0, _0222B1F0 ; =0x00003060
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetAnimationFrame
	ldr r0, _0222B1F0 ; =0x00003060
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0222B1F0 ; =0x00003060
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawPriority
	ldr r0, _0222B1F0 ; =0x00003060
	mov r1, #2
	ldr r0, [r4, r0]
	bl Sprite_SetAffineOverwriteMode
	ldr r0, _0222B1F0 ; =0x00003060
	ldr r0, [r4, r0]
	bl Sprite_GetMatrixPtr
	mov r1, #2
	lsl r1, r1, #0x12
	str r1, [r0]
	lsl r1, r1, #1
	str r1, [r0, #4]
	pop {r4, pc}
	nop
_0222B1F0: .word 0x00003060
	thumb_func_end ov74_0222B19C


	thumb_func_start ov74_0222B1F4
ov74_0222B1F4: ; 0x0222B1F4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222B208 ; =0x00003014
	ldr r0, [r4, r0]
	bl Sprite_Delete
	ldr r0, _0222B208 ; =0x00003014
	mov r1, #0
	str r1, [r4, r0]
	pop {r4, pc}
	.balign 4, 0
_0222B208: .word 0x00003014
	thumb_func_end ov74_0222B1F4


	thumb_func_start ov74_0222B20C
ov74_0222B20C: ; 0x0222B20C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222B220 ; =0x00003060
	ldr r0, [r4, r0]
	bl Sprite_Delete
	ldr r0, _0222B220 ; =0x00003060
	mov r1, #0
	str r1, [r4, r0]
	pop {r4, pc}
	.balign 4, 0
_0222B220: .word 0x00003060
	thumb_func_end ov74_0222B20C


	thumb_func_start ov74_0222B224
ov74_0222B224: ; 0x0222B224
	push {r3, r4, r5, r6, r7, lr}
	mov r6, #2
	ldr r7, _0222B27C ; =0x00001854
	str r0, [sp]
	mov r4, #0
	add r5, r0, #0
	lsl r6, r6, #0xc
_0222B232:
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _0222B242
	add r1, r6, #0
	bl Sprite_UpdateAnim
_0222B242:
	ldr r0, [r5, r7]
	cmp r0, #0
	beq _0222B24E
	add r1, r6, #0
	bl Sprite_UpdateAnim
_0222B24E:
	add r4, r4, #1
	add r5, #0x4c
	cmp r4, #0x50
	blt _0222B232
	ldr r1, _0222B280 ; =0x00003014
	ldr r0, [sp]
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _0222B268
	mov r1, #2
	lsl r1, r1, #0xc
	bl Sprite_UpdateAnim
_0222B268:
	ldr r1, _0222B284 ; =0x00003060
	ldr r0, [sp]
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _0222B27A
	mov r1, #2
	lsl r1, r1, #0xc
	bl Sprite_UpdateAnim
_0222B27A:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222B27C: .word 0x00001854
_0222B280: .word 0x00003014
_0222B284: .word 0x00003060
	thumb_func_end ov74_0222B224


	thumb_func_start ov74_0222B288
ov74_0222B288: ; 0x0222B288
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
	mov r7, #1
_0222B292:
	add r0, r6, #0
	add r1, r7, #0
	bl ov74_0222B0C8
	add r1, r5, #0
	add r1, #0x94
	str r0, [r1]
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_TryChangeAnimSeq
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0
	bl Sprite_SetAnimationFrame
	add r4, r4, #1
	add r5, #0x4c
	cmp r4, #0x50
	blt _0222B292
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov74_0222B288


	thumb_func_start ov74_0222B2C4
ov74_0222B2C4: ; 0x0222B2C4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
	add r7, r4, #0
_0222B2CE:
	cmp r4, #0x14
	bge _0222B2FA
	add r0, r6, #0
	mov r1, #1
	bl ov74_0222B0C8
	add r1, r5, #0
	add r1, #0x94
	str r0, [r1]
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_TryChangeAnimSeq
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0
	bl Sprite_SetAnimationFrame
	b _0222B300
_0222B2FA:
	add r0, r5, #0
	add r0, #0x94
	str r7, [r0]
_0222B300:
	add r4, r4, #1
	add r5, #0x4c
	cmp r4, #0x50
	blt _0222B2CE
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov74_0222B2C4


	thumb_func_start ov74_0222B30C
ov74_0222B30C: ; 0x0222B30C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r7, _0222B340 ; =0x00001854
	mov r4, #0
	add r5, r6, #0
_0222B316:
	add r0, r6, #0
	mov r1, #2
	bl ov74_0222B0C8
	ldr r1, _0222B340 ; =0x00001854
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #5
	bl Sprite_TryChangeAnimSeq
	ldr r0, [r5, r7]
	mov r1, #0
	bl Sprite_SetAnimationFrame
	add r4, r4, #1
	add r5, #0x4c
	cmp r4, #0x50
	blt _0222B316
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222B340: .word 0x00001854
	thumb_func_end ov74_0222B30C


	thumb_func_start ov74_0222B344
ov74_0222B344: ; 0x0222B344
	push {r4, r5, r6, lr}
	mov r4, #0
	add r5, r0, #0
	add r6, r4, #0
_0222B34C:
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _0222B36A
	bl Sprite_Delete
	add r0, r5, #0
	add r0, #0x94
	str r6, [r0]
	add r0, r5, #0
	add r0, #0xd0
	ldr r0, [r0]
	bl SysTask_Destroy
_0222B36A:
	add r4, r4, #1
	add r5, #0x4c
	cmp r4, #0x50
	blt _0222B34C
	pop {r4, r5, r6, pc}
	thumb_func_end ov74_0222B344


	thumb_func_start ov74_0222B374
ov74_0222B374: ; 0x0222B374
	push {r3, r4, r5, r6, r7, lr}
	mov r4, #0
	ldr r7, _0222B39C ; =0x00001890
	add r5, r0, #0
	add r6, r4, #0
_0222B37E:
	ldr r0, _0222B3A0 ; =0x00001854
	ldr r0, [r5, r0]
	bl Sprite_Delete
	ldr r0, _0222B3A0 ; =0x00001854
	str r6, [r5, r0]
	ldr r0, [r5, r7]
	bl SysTask_Destroy
	add r4, r4, #1
	add r5, #0x4c
	cmp r4, #0x50
	blt _0222B37E
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222B39C: .word 0x00001890
_0222B3A0: .word 0x00001854
	thumb_func_end ov74_0222B374


	thumb_func_start ov74_0222B3A4
ov74_0222B3A4: ; 0x0222B3A4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0xb8
	add r5, r0, #0
	str r0, [sp]
	add r0, #0x88
	ldr r3, _0222B5E8 ; =_0223B3BC
	mov r4, #0
	add r7, sp, #0x64
	str r0, [sp]
	add r2, sp, #0x10
	mov r6, #0xa
_0222B3BA:
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	sub r6, r6, #1
	bne _0222B3BA
	ldr r0, [r3]
	str r0, [r2]
_0222B3C6:
	mov r2, #2
	add r0, r5, #0
	mov r1, #6
	lsl r2, r2, #0x12
	add r0, #0x98
	str r2, [r0]
	add r0, r5, #0
	lsl r1, r1, #0x10
	add r0, #0x9c
	str r1, [r0]
	add r0, r5, #0
	lsr r1, r2, #5
	add r0, #0xa4
	str r1, [r0]
	mov r1, #5
	add r0, r5, #0
	lsl r1, r1, #0xc
	add r0, #0xa8
	str r1, [r0]
	lsr r2, r4, #0x1f
	lsl r1, r4, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r5, #0
	add r1, r2, r1
	add r0, #0xb4
	str r1, [r0]
	add r0, r5, #0
	mov r1, #0
	add r0, #0xbc
	str r1, [r0]
	add r0, r5, #0
	add r0, #0x8c
	str r1, [r0]
	add r0, r4, #0
	mov r1, #0xa
	bl _s32_div_f
	add r0, r0, #4
	cmp r0, #0
	ble _0222B42C
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222B43A
_0222B42C:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222B43A:
	bl _ffix
	add r1, r5, #0
	add r1, #0xa4
	str r0, [r1]
	cmp r4, #0x32
	ble _0222B462
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	mov r0, #0x41
	lsl r0, r0, #2
	add r0, r4, r0
	add r1, r0, r1
	add r0, r5, #0
	add r0, #0xb8
	str r1, [r0]
	b _0222B4EC
_0222B462:
	cmp r4, #0x28
	ble _0222B47E
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	add r0, r4, #0
	add r0, #0xfa
	add r1, r0, r1
	add r0, r5, #0
	add r0, #0xb8
	str r1, [r0]
	b _0222B4EC
_0222B47E:
	cmp r4, #0x1e
	ble _0222B49A
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	add r0, r4, #0
	add r0, #0xf0
	add r1, r0, r1
	add r0, r5, #0
	add r0, #0xb8
	str r1, [r0]
	b _0222B4EC
_0222B49A:
	cmp r4, #0x19
	ble _0222B4B6
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	add r0, r4, #0
	add r0, #0xe6
	add r1, r0, r1
	add r0, r5, #0
	add r0, #0xb8
	str r1, [r0]
	b _0222B4EC
_0222B4B6:
	cmp r4, #0x14
	ble _0222B4D2
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	add r0, r4, #0
	add r0, #0xdc
	add r1, r0, r1
	add r0, r5, #0
	add r0, #0xb8
	str r1, [r0]
	b _0222B4EC
_0222B4D2:
	add r6, sp, #0x10
	add r3, sp, #0x64
	mov r2, #0xa
_0222B4D8:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0222B4D8
	ldr r0, [r6]
	str r0, [r3]
	add r0, r5, #0
	ldr r1, [r7]
	add r0, #0xb8
	str r1, [r0]
_0222B4EC:
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	add r1, r0, #1
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	bl _dflt
	add r2, r0, #0
	add r3, r1, #0
	ldr r0, _0222B5EC ; =0x66666666
	ldr r1, _0222B5F0 ; =0x3FE66666
	bl _dmul
	bl _dfix
	add r1, r5, #0
	add r1, #0xb8
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xb8
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0xb8
	str r1, [r0]
	add r0, r5, #0
	mov r1, #0xf
	add r0, #0xc0
	str r1, [r0]
	add r0, r5, #0
	add r0, #0xc0
	ldr r1, [r0]
	add r0, r5, #0
	add r0, #0xc8
	str r1, [r0]
	add r0, r5, #0
	add r0, #0xc0
	ldr r1, [r0]
	add r0, r5, #0
	add r0, #0xcc
	str r1, [r0]
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #4
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	bl LCRandom
	mov r1, #0xe0
	bl _s32_div_f
	add r1, #0x10
	cmp r1, #0
	ble _0222B586
	bl LCRandom
	mov r1, #0xe0
	bl _s32_div_f
	add r1, #0x10
	lsl r0, r1, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222B5A0
_0222B586:
	bl LCRandom
	mov r1, #0xe0
	bl _s32_div_f
	add r1, #0x10
	lsl r0, r1, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222B5A0:
	bl _ffix
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	add r1, sp, #4
	bl Sprite_SetMatrix
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0222B5F4 ; =ov74_0222BA48
	ldr r1, [sp]
	mov r2, #6
	bl SysTask_CreateOnMainQueue
	add r1, r5, #0
	add r1, #0xd0
	str r0, [r1]
	ldr r0, [sp]
	add r4, r4, #1
	add r0, #0x4c
	add r5, #0x4c
	add r7, r7, #4
	str r0, [sp]
	cmp r4, #0x50
	bge _0222B5E4
	b _0222B3C6
_0222B5E4:
	add sp, #0xb8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222B5E8: .word _0223B3BC
_0222B5EC: .word 0x66666666
_0222B5F0: .word 0x3FE66666
_0222B5F4: .word ov74_0222BA48
	thumb_func_end ov74_0222B3A4


	thumb_func_start ov74_0222B5F8
ov74_0222B5F8: ; 0x0222B5F8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r5, #0
	mov r4, #0
	add r7, #0x88
_0222B604:
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	bne _0222B610
	b _0222B74C
_0222B610:
	add r1, r5, #0
	mov r0, #2
	add r1, #0x98
	lsl r0, r0, #0x12
	str r0, [r1]
	add r1, r5, #0
	mov r0, #6
	add r1, #0x9c
	lsl r0, r0, #0x10
	str r0, [r1]
	add r1, r5, #0
	add r1, #0xa4
	lsr r0, r0, #3
	str r0, [r1]
	add r1, r5, #0
	mov r0, #1
	add r1, #0xa8
	lsl r0, r0, #0xc
	str r0, [r1]
	add r1, r5, #0
	add r1, #0xb4
	mov r0, #0xff
	str r0, [r1]
	add r1, r5, #0
	add r1, #0xbc
	mov r0, #0
	str r0, [r1]
	add r1, r5, #0
	add r1, #0x8c
	str r0, [r1]
	add r1, r5, #0
	add r1, #0x90
	str r0, [r1]
	cmp r4, #0x1e
	ble _0222B66A
	bl LCRandom
	mov r1, #0xa
	bl _s32_div_f
	add r0, r5, #0
	add r1, #0xf
	add r0, #0xb8
	str r1, [r0]
	b _0222B6AC
_0222B66A:
	cmp r4, #0x14
	ble _0222B682
	bl LCRandom
	mov r1, #0xa
	bl _s32_div_f
	add r0, r5, #0
	add r1, #0xa
	add r0, #0xb8
	str r1, [r0]
	b _0222B6AC
_0222B682:
	cmp r4, #0xa
	ble _0222B69A
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	add r0, r5, #0
	add r1, #0xa
	add r0, #0xb8
	str r1, [r0]
	b _0222B6AC
_0222B69A:
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	add r0, r5, #0
	add r1, r1, #5
	add r0, #0xb8
	str r1, [r0]
_0222B6AC:
	add r1, r5, #0
	add r1, #0xb8
	mov r0, #0
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xc0
	ldr r1, [r0]
	add r0, r5, #0
	add r0, #0xc8
	str r1, [r0]
	add r0, r5, #0
	add r0, #0xc0
	ldr r1, [r0]
	add r0, r5, #0
	add r0, #0xcc
	str r1, [r0]
	bl LCRandom
	mov r1, #0x5a
	lsl r1, r1, #2
	bl _s32_div_f
	str r1, [sp]
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1b
	sub r1, r1, r2
	mov r0, #0x1b
	ror r1, r0
	ldr r0, [sp]
	add r6, r2, r1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	add r6, #0x40
	bl GF_SinDeg
	add r1, r5, #0
	add r1, #0x98
	ldr r1, [r1]
	mul r0, r6
	add r0, r1, r0
	str r0, [sp, #4]
	ldr r0, [sp]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_CosDeg
	add r1, r5, #0
	add r1, #0x9c
	ldr r1, [r1]
	mul r0, r6
	add r0, r1, r0
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	add r1, sp, #4
	bl Sprite_SetMatrix
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #1
	bl Sprite_TryChangeAnimSeq
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, _0222B75C ; =ov74_0222BA48
	add r1, r7, #0
	mov r2, #6
	bl SysTask_CreateOnMainQueue
	add r1, r5, #0
	add r1, #0xd0
	str r0, [r1]
_0222B74C:
	add r4, r4, #1
	add r5, #0x4c
	add r7, #0x4c
	cmp r4, #0x50
	bge _0222B758
	b _0222B604
_0222B758:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222B75C: .word ov74_0222BA48
	thumb_func_end ov74_0222B5F8


	thumb_func_start ov74_0222B760
ov74_0222B760: ; 0x0222B760
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, _0222B928 ; =0x00001848
	mov r4, #0
	add r6, r5, r0
_0222B76C:
	mov r1, #2
	ldr r0, _0222B92C ; =0x00001858
	lsl r1, r1, #0x12
	str r1, [r5, r0]
	mov r1, #6
	lsl r1, r1, #0x12
	add r0, r0, #4
	str r1, [r5, r0]
	mov r1, #1
	ldr r0, _0222B930 ; =0x00001864
	lsl r1, r1, #0xe
	str r1, [r5, r0]
	mov r1, #5
	lsl r1, r1, #0xc
	add r0, r0, #4
	str r1, [r5, r0]
	lsr r2, r4, #0x1f
	lsl r1, r4, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	add r1, r0, #4
	ldr r0, _0222B934 ; =0x00001874
	str r1, [r5, r0]
	mov r1, #0
	add r0, #8
	str r1, [r5, r0]
	ldr r0, _0222B938 ; =0x0000184C
	str r1, [r5, r0]
	bl LCRandom
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1e
	sub r1, r1, r2
	mov r0, #0x1e
	ror r1, r0
	add r0, r2, r1
	add r1, r0, #2
	ldr r0, _0222B93C ; =0x00001884
	str r1, [r5, r0]
	add r0, r4, #0
	mov r1, #0x1e
	bl _s32_div_f
	add r0, r0, #4
	cmp r0, #0
	ble _0222B7DE
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222B7EC
_0222B7DE:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222B7EC:
	bl _ffix
	ldr r1, _0222B930 ; =0x00001864
	cmp r4, #0x3c
	str r0, [r5, r1]
	ble _0222B812
	mov r0, #0x62
	mov r1, #5
	lsl r0, r0, #6
	str r1, [r5, r0]
	bl LCRandom
	mov r1, #0xa
	bl _s32_div_f
	ldr r0, _0222B940 ; =0x00001878
	add r1, #0x46
	str r1, [r5, r0]
	b _0222B8C0
_0222B812:
	cmp r4, #0x32
	ble _0222B830
	mov r0, #0x62
	mov r1, #5
	lsl r0, r0, #6
	str r1, [r5, r0]
	bl LCRandom
	mov r1, #0xa
	bl _s32_div_f
	ldr r0, _0222B940 ; =0x00001878
	add r1, #0x3c
	str r1, [r5, r0]
	b _0222B8C0
_0222B830:
	cmp r4, #0x28
	ble _0222B84E
	mov r0, #0x62
	mov r1, #5
	lsl r0, r0, #6
	str r1, [r5, r0]
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	ldr r0, _0222B940 ; =0x00001878
	add r1, #0x32
	str r1, [r5, r0]
	b _0222B8C0
_0222B84E:
	cmp r4, #0x1e
	ble _0222B86C
	mov r0, #0x62
	mov r1, #5
	lsl r0, r0, #6
	str r1, [r5, r0]
	bl LCRandom
	mov r1, #0xa
	bl _s32_div_f
	ldr r0, _0222B940 ; =0x00001878
	add r1, #0x28
	str r1, [r5, r0]
	b _0222B8C0
_0222B86C:
	cmp r4, #0x14
	ble _0222B88A
	mov r0, #0x62
	mov r1, #5
	lsl r0, r0, #6
	str r1, [r5, r0]
	bl LCRandom
	mov r1, #0xa
	bl _s32_div_f
	ldr r0, _0222B940 ; =0x00001878
	add r1, #0x1e
	str r1, [r5, r0]
	b _0222B8C0
_0222B88A:
	cmp r4, #0xa
	ble _0222B8A8
	mov r0, #0x62
	mov r1, #5
	lsl r0, r0, #6
	str r1, [r5, r0]
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	ldr r0, _0222B940 ; =0x00001878
	add r1, #0x14
	str r1, [r5, r0]
	b _0222B8C0
_0222B8A8:
	mov r0, #0x62
	mov r1, #5
	lsl r0, r0, #6
	str r1, [r5, r0]
	bl LCRandom
	mov r1, #5
	bl _s32_div_f
	ldr r0, _0222B940 ; =0x00001878
	add r1, #0xa
	str r1, [r5, r0]
_0222B8C0:
	mov r0, #0x62
	lsl r0, r0, #6
	ldr r1, [r5, r0]
	add r0, #8
	str r1, [r5, r0]
	mov r0, #0x62
	lsl r0, r0, #6
	ldr r1, [r5, r0]
	add r0, #0xc
	str r1, [r5, r0]
	ldr r0, _0222B944 ; =0x00001854
	ldr r0, [r5, r0]
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	add r2, sp, #0
	ldmia r3!, {r0, r1}
	add r7, r2, #0
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, r7, #0
	str r0, [r2]
	mov r0, #2
	lsl r0, r0, #0x12
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #0x12
	str r0, [sp, #4]
	ldr r0, _0222B944 ; =0x00001854
	ldr r0, [r5, r0]
	bl Sprite_SetMatrix
	ldr r0, _0222B944 ; =0x00001854
	mov r1, #1
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	ldr r0, _0222B948 ; =ov74_0222BA48
	add r1, r6, #0
	mov r2, #6
	bl SysTask_CreateOnMainQueue
	ldr r1, _0222B94C ; =0x00001890
	add r4, r4, #1
	str r0, [r5, r1]
	add r5, #0x4c
	add r6, #0x4c
	cmp r4, #0x50
	bge _0222B924
	b _0222B76C
_0222B924:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222B928: .word 0x00001848
_0222B92C: .word 0x00001858
_0222B930: .word 0x00001864
_0222B934: .word 0x00001874
_0222B938: .word 0x0000184C
_0222B93C: .word 0x00001884
_0222B940: .word 0x00001878
_0222B944: .word 0x00001854
_0222B948: .word ov74_0222BA48
_0222B94C: .word 0x00001890
	thumb_func_end ov74_0222B760


	thumb_func_start ov74_0222B950
ov74_0222B950: ; 0x0222B950
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r5, r1, #0
	mov r1, #0
	add r4, r2, #0
	add r6, r3, #0
	str r1, [sp]
	str r1, [sp, #4]
	bl _fflt
	add r1, r4, #0
	bl _fsub
	str r0, [sp, #8]
	add r0, r5, #0
	bl _fflt
	add r1, r6, #0
	bl _fsub
	str r0, [sp, #0xc]
	mov r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	ldr r0, [sp, #8]
	add r1, r0, #0
	bl _fmul
	add r4, r0, #0
	ldr r0, [sp, #0xc]
	add r1, r0, #0
	bl _fmul
	add r1, r0, #0
	add r0, r4, #0
	bl _fadd
	mov r1, #0
	add r4, r0, #0
	bl _fgr
	ldr r0, _0222BA44 ; =0x45800000
	bls _0222B9B8
	add r1, r4, #0
	bl _fmul
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222B9C6
_0222B9B8:
	add r1, r4, #0
	bl _fmul
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222B9C6:
	bl _ffix
	bl FX_Sqrt
	bl _fflt
	ldr r1, _0222BA44 ; =0x45800000
	bl _fdiv
	ldr r1, [sp, #0x30]
	add r4, r0, #0
	bl _fls
	blo _0222B9FE
	add r1, sp, #0x18
	mov r0, #0x1c
	ldrsh r0, [r1, r0]
	bl _fflt
	add r1, r4, #0
	bl _fgr
	bhi _0222B9FE
	mov r0, #0
	add r1, r4, #0
	bl _feq
	bne _0222BA04
_0222B9FE:
	add sp, #0x18
	mov r0, #0
	pop {r4, r5, r6, pc}
_0222BA04:
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x30]
	bl _fmul
	add r1, r4, #0
	bl _fdiv
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x30]
	bl _fmul
	add r1, r4, #0
	bl _fdiv
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	ldr r1, [sp]
	bl _fadd
	ldr r1, [sp, #0x28]
	str r0, [r1]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #4]
	bl _fadd
	ldr r1, [sp, #0x2c]
	str r0, [r1]
	mov r0, #1
	add sp, #0x18
	pop {r4, r5, r6, pc}
	nop
_0222BA44: .word 0x45800000
	thumb_func_end ov74_0222B950


	thumb_func_start ov74_0222BA48
ov74_0222BA48: ; 0x0222BA48
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r1, #0
	ldr r0, [r5, #0x30]
	cmp r0, #0
	ldr r0, [r5, #0xc]
	beq _0222BA66
	mov r1, #0
	bl Sprite_SetAnimationFrame
	ldr r0, [r5, #0x30]
	add sp, #0x24
	sub r0, r0, #1
	str r0, [r5, #0x30]
	pop {r4, r5, r6, r7, pc}
_0222BA66:
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, [r5, #0xc]
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x18
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [sp, #0x18]
	bl _fflt
	ldr r1, _0222BD90 ; =0x45800000
	bl _fdiv
	add r6, r0, #0
	ldr r0, [sp, #0x1c]
	bl _fflt
	ldr r1, _0222BD90 ; =0x45800000
	bl _fdiv
	add r7, r0, #0
	ldr r0, [r5, #0x1c]
	bl _fflt
	ldr r1, _0222BD90 ; =0x45800000
	bl _fdiv
	add r4, r0, #0
	ldr r0, [r5, #0x20]
	bl _fflt
	ldr r1, _0222BD90 ; =0x45800000
	bl _fdiv
	bl _ffix
	add r1, sp, #0x14
	str r1, [sp]
	add r1, sp, #0x10
	str r1, [sp, #4]
	str r4, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	lsl r0, r0, #4
	lsl r1, r1, #4
	asr r0, r0, #0x10
	asr r1, r1, #0x10
	add r2, r6, #0
	add r3, r7, #0
	bl ov74_0222B950
	cmp r0, #0
	beq _0222BB5A
	ldr r0, [r5, #0x24]
	cmp r0, #0
	bne _0222BB5A
	ldr r0, [sp, #0x14]
	mov r1, #0
	bl _fgr
	ldr r0, _0222BD90 ; =0x45800000
	bls _0222BB00
	ldr r1, [sp, #0x14]
	bl _fmul
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222BB0E
_0222BB00:
	ldr r1, [sp, #0x14]
	bl _fmul
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222BB0E:
	bl _ffix
	ldr r1, [sp, #0x18]
	add r0, r1, r0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	mov r1, #0
	bl _fgr
	ldr r0, _0222BD90 ; =0x45800000
	bls _0222BB36
	ldr r1, [sp, #0x10]
	bl _fmul
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222BB44
_0222BB36:
	ldr r1, [sp, #0x10]
	bl _fmul
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222BB44:
	bl _ffix
	ldr r1, [sp, #0x1c]
	add r0, r1, r0
	str r0, [sp, #0x1c]
	ldr r0, [r5, #0xc]
	add r1, sp, #0x18
	bl Sprite_SetMatrix
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_0222BB5A:
	ldr r0, [r5, #0x24]
	cmp r0, #0
	beq _0222BB68
	cmp r0, #1
	beq _0222BBDE
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_0222BB68:
	ldr r1, [r5, #0x10]
	ldr r0, [sp, #0x18]
	sub r0, r1, r0
	cmp r0, #0
	ble _0222BB84
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222BB92
_0222BB84:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222BB92:
	add r4, r0, #0
	ldr r1, [r5, #0x14]
	ldr r0, [sp, #0x1c]
	sub r0, r1, r0
	cmp r0, #0
	ble _0222BBB0
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222BBBE
_0222BBB0:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222BBBE:
	bl _ffix
	add r6, r0, #0
	add r0, r4, #0
	bl _ffix
	add r1, r0, #0
	add r0, r6, #0
	bl FX_Atan2Idx
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x24]
	add sp, #0x24
	add r0, r0, #1
	str r0, [r5, #0x24]
	pop {r4, r5, r6, r7, pc}
_0222BBDE:
	ldr r0, [r5, #4]
	cmp r0, #0x14
	bge _0222BBEA
	add r0, r0, #1
	str r0, [r5, #4]
	b _0222BBEE
_0222BBEA:
	mov r0, #1
	str r0, [r5, #8]
_0222BBEE:
	ldr r0, [r5, #0x28]
	add r0, #8
	str r0, [r5, #0x28]
	ldr r0, [r5, #0x2c]
	cmp r0, #0
	bne _0222BC44
	ldr r0, [r5, #0x34]
	mov r1, #0x5a
	add r0, #8
	lsl r1, r1, #2
	str r0, [r5, #0x34]
	bl _s32_div_f
	lsl r0, r1, #0x10
	str r1, [r5, #0x34]
	lsr r0, r0, #0x10
	bl GF_CosDeg
	ldr r1, [r5, #0x38]
	mul r0, r1
	asr r0, r0, #0xc
	str r0, [r5, #0x40]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDeg
	ldr r1, [r5, #0x40]
	ldr r2, [r5, #0x10]
	mul r0, r1
	add r0, r2, r0
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_CosDeg
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x14]
	mul r0, r1
	add r0, r2, r0
	str r0, [sp, #0x1c]
	b _0222BEBC
_0222BC44:
	cmp r0, #1
	bne _0222BC92
	ldr r0, [r5, #0x34]
	mov r1, #0x5a
	add r0, #8
	lsl r1, r1, #2
	str r0, [r5, #0x34]
	bl _s32_div_f
	lsl r0, r1, #0x10
	str r1, [r5, #0x34]
	lsr r0, r0, #0x10
	bl GF_SinDeg
	ldr r1, [r5, #0x38]
	mul r0, r1
	asr r0, r0, #0xc
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDeg
	ldr r1, [r5, #0x40]
	ldr r2, [r5, #0x10]
	mul r0, r1
	add r0, r2, r0
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_CosDeg
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x14]
	mul r0, r1
	add r0, r2, r0
	str r0, [sp, #0x1c]
	b _0222BEBC
_0222BC92:
	cmp r0, #2
	bne _0222BCF0
	ldr r0, [r5, #0x34]
	mov r1, #0x5a
	add r0, #8
	lsl r1, r1, #2
	str r0, [r5, #0x34]
	bl _s32_div_f
	lsl r0, r1, #0x10
	str r1, [r5, #0x34]
	lsr r0, r0, #0x10
	bl GF_SinDeg
	ldr r1, [r5, #0x38]
	mul r0, r1
	asr r0, r0, #0xc
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDeg
	ldr r1, [r5, #0x40]
	ldr r3, [r5, #0x10]
	add r2, r1, #0
	mul r2, r0
	mov r0, #0
	mvn r0, r0
	mul r0, r2
	add r0, r3, r0
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_CosDeg
	ldr r1, [r5, #0x44]
	ldr r3, [r5, #0x14]
	add r2, r1, #0
	mul r2, r0
	mov r0, #0
	mvn r0, r0
	mul r0, r2
	add r0, r3, r0
	str r0, [sp, #0x1c]
	b _0222BEBC
_0222BCF0:
	cmp r0, #3
	bne _0222BD4E
	ldr r0, [r5, #0x34]
	mov r1, #0x5a
	add r0, #8
	lsl r1, r1, #2
	str r0, [r5, #0x34]
	bl _s32_div_f
	lsl r0, r1, #0x10
	str r1, [r5, #0x34]
	lsr r0, r0, #0x10
	bl GF_CosDeg
	ldr r1, [r5, #0x38]
	mul r0, r1
	asr r0, r0, #0xc
	str r0, [r5, #0x40]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDeg
	ldr r1, [r5, #0x40]
	ldr r3, [r5, #0x10]
	add r2, r1, #0
	mul r2, r0
	mov r0, #0
	mvn r0, r0
	mul r0, r2
	add r0, r3, r0
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_CosDeg
	ldr r1, [r5, #0x44]
	ldr r3, [r5, #0x14]
	add r2, r1, #0
	mul r2, r0
	mov r0, #0
	mvn r0, r0
	mul r0, r2
	add r0, r3, r0
	str r0, [sp, #0x1c]
	b _0222BEBC
_0222BD4E:
	cmp r0, #4
	bne _0222BD94
	ldr r1, [r5, #0x38]
	cmp r1, #0x60
	bge _0222BD5E
	ldr r0, [r5, #0x3c]
	add r0, r1, r0
	str r0, [r5, #0x38]
_0222BD5E:
	ldr r0, [r5, #0x38]
	str r0, [r5, #0x40]
	ldr r0, [r5, #0x38]
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDeg
	ldr r1, [r5, #0x40]
	ldr r2, [r5, #0x10]
	mul r0, r1
	add r0, r2, r0
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_CosDeg
	ldr r1, [r5, #0x44]
	ldr r2, [r5, #0x14]
	mul r0, r1
	add r0, r2, r0
	str r0, [sp, #0x1c]
	b _0222BEBC
	.balign 4, 0
_0222BD90: .word 0x45800000
_0222BD94:
	cmp r0, #5
	bne _0222BDE6
	ldr r1, [r5, #0x38]
	cmp r1, #0x60
	bge _0222BDA4
	ldr r0, [r5, #0x3c]
	add r0, r1, r0
	str r0, [r5, #0x38]
_0222BDA4:
	ldr r0, [r5, #0x38]
	str r0, [r5, #0x40]
	ldr r0, [r5, #0x38]
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDeg
	ldr r1, [r5, #0x40]
	ldr r3, [r5, #0x10]
	add r2, r1, #0
	mul r2, r0
	mov r0, #0
	mvn r0, r0
	mul r0, r2
	add r0, r3, r0
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x28]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_CosDeg
	ldr r1, [r5, #0x44]
	ldr r3, [r5, #0x14]
	add r2, r1, #0
	mul r2, r0
	mov r0, #0
	mvn r0, r0
	mul r0, r2
	add r0, r3, r0
	str r0, [sp, #0x1c]
	b _0222BEBC
_0222BDE6:
	mov r0, #0xa
	str r0, [r5, #4]
	mov r0, #2
	ldr r1, [r5, #0x1c]
	lsl r0, r0, #0xa
	add r0, r1, r0
	str r0, [r5, #0x1c]
	ldr r0, [sp, #0x18]
	bl _fflt
	ldr r1, _0222BED4 ; =0x45800000
	bl _fdiv
	add r4, r0, #0
	ldr r0, [sp, #0x1c]
	bl _fflt
	ldr r1, _0222BED4 ; =0x45800000
	bl _fdiv
	add r6, r0, #0
	ldr r0, [r5, #0x1c]
	bl _fflt
	ldr r1, _0222BED4 ; =0x45800000
	bl _fdiv
	add r1, sp, #0x14
	str r1, [sp]
	add r1, sp, #0x10
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	lsl r0, r0, #4
	lsl r1, r1, #4
	asr r0, r0, #0x10
	asr r1, r1, #0x10
	add r2, r4, #0
	add r3, r6, #0
	bl ov74_0222B950
	cmp r0, #0
	beq _0222BEB8
	ldr r0, [sp, #0x14]
	mov r1, #0
	bl _fgr
	ldr r0, _0222BED4 ; =0x45800000
	bls _0222BE60
	ldr r1, [sp, #0x14]
	bl _fmul
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222BE6E
_0222BE60:
	ldr r1, [sp, #0x14]
	bl _fmul
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222BE6E:
	bl _ffix
	ldr r1, [sp, #0x18]
	add r0, r1, r0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	mov r1, #0
	bl _fgr
	ldr r0, _0222BED4 ; =0x45800000
	bls _0222BE96
	ldr r1, [sp, #0x10]
	bl _fmul
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0222BEA4
_0222BE96:
	ldr r1, [sp, #0x10]
	bl _fmul
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0222BEA4:
	bl _ffix
	ldr r1, [sp, #0x1c]
	add r0, r1, r0
	str r0, [sp, #0x1c]
	ldr r0, [r5, #0xc]
	add r1, sp, #0x18
	bl Sprite_SetMatrix
	b _0222BEBC
_0222BEB8:
	mov r0, #1
	str r0, [r5, #8]
_0222BEBC:
	mov r1, #0x5a
	ldr r0, [r5, #0x28]
	lsl r1, r1, #2
	bl _s32_div_f
	str r1, [r5, #0x28]
	ldr r0, [r5, #0xc]
	add r1, sp, #0x18
	bl Sprite_SetMatrix
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222BED4: .word 0x45800000
	thumb_func_end ov74_0222BA48


	thumb_func_start ov74_0222BED8
ov74_0222BED8: ; 0x0222BED8
	add r3, r0, #0
	mov r2, #8
	ldrsb r2, [r3, r2]
	ldr r3, _0222BEE8 ; =G2x_SetBlendBrightness_
	ldr r0, _0222BEEC ; =0x04000050
	mov r1, #0x22
	bx r3
	nop
_0222BEE8: .word G2x_SetBlendBrightness_
_0222BEEC: .word 0x04000050
	thumb_func_end ov74_0222BED8


	thumb_func_start ov74_0222BEF0
ov74_0222BEF0: ; 0x0222BEF0
	add r3, r0, #0
	mov r2, #8
	ldrsb r2, [r3, r2]
	ldr r3, _0222BF00 ; =G2x_SetBlendBrightness_
	ldr r0, _0222BF04 ; =0x04001050
	mov r1, #0x22
	bx r3
	nop
_0222BF00: .word G2x_SetBlendBrightness_
_0222BF04: .word 0x04001050
	thumb_func_end ov74_0222BEF0


	thumb_func_start ov74_0222BF08
ov74_0222BF08: ; 0x0222BF08
	push {r4, lr}
	add r4, r0, #0
	bl ov74_0222BED8
	add r0, r4, #0
	bl ov74_0222BEF0
	pop {r4, pc}
	thumb_func_end ov74_0222BF08


	thumb_func_start ov74_0222BF18
ov74_0222BF18: ; 0x0222BF18
	push {r3, lr}
	mov r0, #1
	mov r1, #0
	bl BG_SetMaskColor
	mov r0, #5
	mov r1, #0
	bl BG_SetMaskColor
	pop {r3, pc}
	thumb_func_end ov74_0222BF18


	thumb_func_start ov74_0222BF2C
ov74_0222BF2C: ; 0x0222BF2C
	push {r4, lr}
	mov r4, #1
	cmp r1, #0
	beq _0222BF3E
	cmp r1, #1
	beq _0222BF6A
	cmp r1, #2
	beq _0222BF84
	b _0222BF98
_0222BF3E:
	mov r1, #8
	ldrsb r1, [r0, r1]
	cmp r1, #0
	ble _0222BF58
	sub r1, r1, r2
	cmp r1, #0
	ble _0222BF52
	strb r1, [r0, #8]
	mov r4, #0
	b _0222BF98
_0222BF52:
	mov r1, #0
	strb r1, [r0, #8]
	b _0222BF98
_0222BF58:
	bge _0222BF98
	add r1, r1, r2
	bpl _0222BF64
	strb r1, [r0, #8]
	mov r4, #0
	b _0222BF98
_0222BF64:
	mov r1, #0
	strb r1, [r0, #8]
	b _0222BF98
_0222BF6A:
	mov r3, #8
	ldrsb r1, [r0, r3]
	sub r2, r1, r2
	add r1, r3, #0
	sub r1, #0x18
	cmp r2, r1
	ble _0222BF7E
	strb r2, [r0, #8]
	mov r4, #0
	b _0222BF98
_0222BF7E:
	sub r3, #0x18
	strb r3, [r0, #8]
	b _0222BF98
_0222BF84:
	mov r1, #8
	ldrsb r1, [r0, r1]
	add r1, r1, r2
	cmp r1, #0x10
	bge _0222BF94
	strb r1, [r0, #8]
	mov r4, #0
	b _0222BF98
_0222BF94:
	mov r1, #0x10
	strb r1, [r0, #8]
_0222BF98:
	bl ov74_0222BF08
	add r0, r4, #0
	pop {r4, pc}
	thumb_func_end ov74_0222BF2C


	thumb_func_start ov74_0222BFA0
ov74_0222BFA0: ; 0x0222BFA0
	push {r4, lr}
	mov r4, #1
	cmp r1, #0
	beq _0222BFB2
	cmp r1, #1
	beq _0222BFDE
	cmp r1, #2
	beq _0222BFF8
	b _0222C00C
_0222BFB2:
	mov r1, #8
	ldrsb r1, [r0, r1]
	cmp r1, #0
	ble _0222BFCC
	sub r1, r1, r2
	cmp r1, #0
	ble _0222BFC6
	strb r1, [r0, #8]
	mov r4, #0
	b _0222C00C
_0222BFC6:
	mov r1, #0
	strb r1, [r0, #8]
	b _0222C00C
_0222BFCC:
	bge _0222C00C
	add r1, r1, r2
	bpl _0222BFD8
	strb r1, [r0, #8]
	mov r4, #0
	b _0222C00C
_0222BFD8:
	mov r1, #0
	strb r1, [r0, #8]
	b _0222C00C
_0222BFDE:
	mov r3, #8
	ldrsb r1, [r0, r3]
	sub r2, r1, r2
	add r1, r3, #0
	sub r1, #0x18
	cmp r2, r1
	ble _0222BFF2
	strb r2, [r0, #8]
	mov r4, #0
	b _0222C00C
_0222BFF2:
	sub r3, #0x18
	strb r3, [r0, #8]
	b _0222C00C
_0222BFF8:
	mov r1, #8
	ldrsb r1, [r0, r1]
	add r1, r1, r2
	cmp r1, #0x10
	bge _0222C008
	strb r1, [r0, #8]
	mov r4, #0
	b _0222C00C
_0222C008:
	mov r1, #0x10
	strb r1, [r0, #8]
_0222C00C:
	bl ov74_0222BED8
	add r0, r4, #0
	pop {r4, pc}
	thumb_func_end ov74_0222BFA0


	thumb_func_start ov74_0222C014
ov74_0222C014: ; 0x0222C014
	push {r4, lr}
	add r4, r0, #0
	mov r1, #0
	strb r1, [r4, #8]
	bl ov74_0222BF08
	add r0, r4, #0
	bl ov74_0222AF28
	add r0, r4, #0
	bl ov74_0222B288
	add r0, r4, #0
	bl ov74_0222B3A4
	add r0, r4, #0
	bl ov74_0222B144
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222C014


	thumb_func_start ov74_0222C04C
ov74_0222C04C: ; 0x0222C04C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	ldr r1, [r4]
	cmp r1, #9
	bls _0222C058
	b _0222C2BC
_0222C058:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0222C064: ; jump table
	.short _0222C078 - _0222C064 - 2 ; case 0
	.short _0222C084 - _0222C064 - 2 ; case 1
	.short _0222C09A - _0222C064 - 2 ; case 2
	.short _0222C0FE - _0222C064 - 2 ; case 3
	.short _0222C126 - _0222C064 - 2 ; case 4
	.short _0222C17C - _0222C064 - 2 ; case 5
	.short _0222C19A - _0222C064 - 2 ; case 6
	.short _0222C222 - _0222C064 - 2 ; case 7
	.short _0222C294 - _0222C064 - 2 ; case 8
	.short _0222C2A8 - _0222C064 - 2 ; case 9
_0222C078:
	add r0, r4, #0
	bl ov74_0222C014
	mov r0, #1
	str r0, [r4]
	b _0222C2D0
_0222C084:
	add r0, r4, #0
	mov r1, #1
	mov r2, #2
	bl ov74_0222BF2C
	cmp r0, #0
	bne _0222C094
	b _0222C2D0
_0222C094:
	mov r0, #2
	str r0, [r4]
	b _0222C2D0
_0222C09A:
	mov r5, #0
	mov r6, #1
	add r0, r5, #0
	add r1, r4, #0
	add r3, r5, #0
_0222C0A4:
	add r2, r1, #0
	add r2, #0x90
	ldr r2, [r2]
	cmp r2, #0
	beq _0222C0B2
	add r5, r5, #1
	b _0222C0B4
_0222C0B2:
	add r6, r3, #0
_0222C0B4:
	add r0, r0, #1
	add r1, #0x4c
	cmp r0, #0x50
	blt _0222C0A4
	cmp r5, #0x32
	ble _0222C0CC
	ldr r0, _0222C2D8 ; =0x00003014
	mov r1, #4
	ldr r0, [r4, r0]
	bl Sprite_TryChangeAnimSeq
	b _0222C0EA
_0222C0CC:
	cmp r5, #0x1e
	ble _0222C0DC
	ldr r0, _0222C2D8 ; =0x00003014
	mov r1, #3
	ldr r0, [r4, r0]
	bl Sprite_TryChangeAnimSeq
	b _0222C0EA
_0222C0DC:
	cmp r5, #7
	ble _0222C0EA
	ldr r0, _0222C2D8 ; =0x00003014
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
_0222C0EA:
	cmp r6, #0
	bne _0222C0F2
	cmp r5, #0x4f
	bne _0222C1A8
_0222C0F2:
	mov r0, #3
	str r0, [r4]
	add r0, r4, #0
	bl ov74_0222B344
	b _0222C2D0
_0222C0FE:
	ldr r0, _0222C2DC ; =0x000030A0
	ldr r0, [r4, r0]
	ldr r0, [r0]
	cmp r0, #2
	bne _0222C1A8
	add r0, r4, #0
	bl ov74_0222B2C4
	add r0, r4, #0
	bl ov74_0222B5F8
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	bl ov74_0222BF18
	mov r0, #4
	str r0, [r4]
	b _0222C2D0
_0222C126:
	mov r5, #0
	mov r6, #1
	add r1, r5, #0
	add r2, r4, #0
	add r0, r5, #0
_0222C130:
	add r3, r2, #0
	add r3, #0x94
	ldr r3, [r3]
	cmp r3, #0
	beq _0222C14A
	add r3, r2, #0
	add r3, #0x90
	ldr r3, [r3]
	cmp r3, #0
	beq _0222C148
	add r5, r5, #1
	b _0222C14A
_0222C148:
	add r6, r0, #0
_0222C14A:
	add r1, r1, #1
	add r2, #0x4c
	cmp r1, #0x50
	blt _0222C130
	mov r1, #2
	add r0, r4, #0
	add r2, r1, #0
	bl ov74_0222BFA0
	cmp r6, #0
	bne _0222C164
	cmp r5, #0x13
	bne _0222C1A8
_0222C164:
	ldr r0, _0222C2E0 ; =SEQ_SE_DP_SAVE
	bl PlaySE
	mov r0, #5
	str r0, [r4]
	add r0, r4, #0
	bl ov74_0222B344
	add r0, r4, #0
	bl ov74_0222B19C
	b _0222C2D0
_0222C17C:
	mov r1, #2
	add r0, r4, #0
	add r2, r1, #0
	bl ov74_0222BFA0
	cmp r0, #0
	beq _0222C1A8
	add r0, r4, #0
	mov r1, #1
	mov r2, #2
	bl ov74_0222BFA0
	mov r0, #6
	str r0, [r4]
	b _0222C2D0
_0222C19A:
	add r0, r4, #0
	mov r1, #1
	mov r2, #2
	bl ov74_0222BFA0
	cmp r0, #0
	bne _0222C1AA
_0222C1A8:
	b _0222C2D0
_0222C1AA:
	ldr r0, _0222C2D8 ; =0x00003014
	ldr r0, [r4, r0]
	bl Sprite_GetMatrixPtr
	add r5, r0, #0
	ldr r0, _0222C2E4 ; =0x00003060
	ldr r0, [r4, r0]
	bl Sprite_GetMatrixPtr
	mov r1, #0xe
	ldr r2, [r5, #4]
	lsl r1, r1, #0x10
	cmp r2, r1
	bge _0222C1CE
	mov r1, #2
	lsl r1, r1, #0xe
	add r1, r2, r1
	str r1, [r5, #4]
_0222C1CE:
	mov r1, #3
	ldr r2, [r5, #4]
	lsl r1, r1, #0x12
	sub r2, r2, r1
	cmp r2, #0
	ble _0222C2D0
	ldr r2, [r0, #4]
	lsl r1, r1, #1
	cmp r2, r1
	bge _0222C202
	mov r1, #2
	lsl r1, r1, #0xe
	add r1, r2, r1
	str r1, [r0, #4]
	ldr r0, _0222C2E4 ; =0x00003060
	ldr r0, [r4, r0]
	bl Sprite_GetDrawFlag
	cmp r0, #0
	bne _0222C2D0
	ldr r0, _0222C2E4 ; =0x00003060
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	b _0222C2D0
_0222C202:
	mov r0, #7
	str r0, [r4]
	add r0, r4, #0
	bl ov74_0222B1F4
	add r0, r4, #0
	bl ov74_0222B30C
	add r0, r4, #0
	bl ov74_0222B760
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	b _0222C2D0
_0222C222:
	mov r5, #0
	ldr r0, _0222C2E8 ; =0x00001850
	mov r6, #1
	add r2, r5, #0
	add r3, r4, #0
	add r7, r5, #0
_0222C22E:
	ldr r1, [r3, r0]
	cmp r1, #0
	beq _0222C238
	add r5, r5, #1
	b _0222C23A
_0222C238:
	add r6, r7, #0
_0222C23A:
	add r2, r2, #1
	add r3, #0x4c
	cmp r2, #0x50
	blt _0222C22E
	cmp r5, #7
	ble _0222C250
	add r0, r4, #0
	mov r1, #2
	mov r2, #1
	bl ov74_0222BF2C
_0222C250:
	cmp r5, #0x32
	ble _0222C260
	ldr r0, _0222C2E4 ; =0x00003060
	mov r1, #0
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	b _0222C27E
_0222C260:
	cmp r5, #0x1e
	ble _0222C270
	ldr r0, _0222C2E4 ; =0x00003060
	mov r1, #2
	ldr r0, [r4, r0]
	bl Sprite_TryChangeAnimSeq
	b _0222C27E
_0222C270:
	cmp r5, #7
	ble _0222C27E
	ldr r0, _0222C2E4 ; =0x00003060
	mov r1, #3
	ldr r0, [r4, r0]
	bl Sprite_TryChangeAnimSeq
_0222C27E:
	cmp r6, #0
	beq _0222C2D0
	mov r0, #8
	str r0, [r4]
	add r0, r4, #0
	bl ov74_0222B374
	add r0, r4, #0
	bl ov74_0222B20C
	b _0222C2D0
_0222C294:
	add r0, r4, #0
	mov r1, #2
	mov r2, #1
	bl ov74_0222BF2C
	cmp r0, #0
	beq _0222C2D0
	mov r0, #9
	str r0, [r4]
	b _0222C2D0
_0222C2A8:
	add r0, r4, #0
	mov r1, #0
	mov r2, #2
	bl ov74_0222BF2C
	cmp r0, #0
	beq _0222C2D0
	mov r0, #0xff
	str r0, [r4]
	b _0222C2D0
_0222C2BC:
	ldr r1, _0222C2DC ; =0x000030A0
	mov r2, #0
	ldr r1, [r4, r1]
	str r2, [r1]
	bl SysTask_Destroy
	add r0, r4, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
_0222C2D0:
	add r0, r4, #0
	bl ov74_0222B224
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222C2D8: .word 0x00003014
_0222C2DC: .word 0x000030A0
_0222C2E0: .word SEQ_SE_DP_SAVE
_0222C2E4: .word 0x00003060
_0222C2E8: .word 0x00001850
	thumb_func_end ov74_0222C04C


	thumb_func_start ov74_0222C2EC
ov74_0222C2EC: ; 0x0222C2EC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r0, #0
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	bl CTRDG_IsExisting
	ldr r0, _0222C640 ; =0x000005C8
	ldr r0, [r4, r0]
	cmp r0, #0x1d
	beq _0222C30C
	add r0, r4, #0
	bl ov74_0222CE10
_0222C30C:
	ldr r3, [r5]
	cmp r3, #0x3a
	bls _0222C316
	bl _0222CD3A
_0222C316:
	add r0, r3, r3
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222C322: ; jump table
	.short _0222C398 - _0222C322 - 2 ; case 0
	.short _0222C3AA - _0222C322 - 2 ; case 1
	.short _0222C3C8 - _0222C322 - 2 ; case 2
	.short _0222C3D2 - _0222C322 - 2 ; case 3
	.short _0222C3E0 - _0222C322 - 2 ; case 4
	.short _0222C3EE - _0222C322 - 2 ; case 5
	.short _0222CD3A - _0222C322 - 2 ; case 6
	.short _0222C636 - _0222C322 - 2 ; case 7
	.short _0222C71C - _0222C322 - 2 ; case 8
	.short _0222C728 - _0222C322 - 2 ; case 9
	.short _0222C7E8 - _0222C322 - 2 ; case 10
	.short _0222C836 - _0222C322 - 2 ; case 11
	.short _0222C858 - _0222C322 - 2 ; case 12
	.short _0222C8E8 - _0222C322 - 2 ; case 13
	.short _0222C93E - _0222C322 - 2 ; case 14
	.short _0222C96A - _0222C322 - 2 ; case 15
	.short _0222C9AA - _0222C322 - 2 ; case 16
	.short _0222C9CC - _0222C322 - 2 ; case 17
	.short _0222CA04 - _0222C322 - 2 ; case 18
	.short _0222CA48 - _0222C322 - 2 ; case 19
	.short _0222CAEA - _0222C322 - 2 ; case 20
	.short _0222CAF6 - _0222C322 - 2 ; case 21
	.short _0222CAFC - _0222C322 - 2 ; case 22
	.short _0222CB32 - _0222C322 - 2 ; case 23
	.short _0222CB4C - _0222C322 - 2 ; case 24
	.short _0222CBC4 - _0222C322 - 2 ; case 25
	.short _0222CD3A - _0222C322 - 2 ; case 26
	.short _0222C3FC - _0222C322 - 2 ; case 27
	.short _0222CD3A - _0222C322 - 2 ; case 28
	.short _0222CD3A - _0222C322 - 2 ; case 29
	.short _0222CD3A - _0222C322 - 2 ; case 30
	.short _0222C4BA - _0222C322 - 2 ; case 31
	.short _0222C408 - _0222C322 - 2 ; case 32
	.short _0222C4CE - _0222C322 - 2 ; case 33
	.short _0222C570 - _0222C322 - 2 ; case 34
	.short _0222C54E - _0222C322 - 2 ; case 35
	.short _0222C612 - _0222C322 - 2 ; case 36
	.short _0222CD3A - _0222C322 - 2 ; case 37
	.short _0222CD3A - _0222C322 - 2 ; case 38
	.short _0222CD3A - _0222C322 - 2 ; case 39
	.short _0222CD3A - _0222C322 - 2 ; case 40
	.short _0222CD3A - _0222C322 - 2 ; case 41
	.short _0222CD3A - _0222C322 - 2 ; case 42
	.short _0222CD3A - _0222C322 - 2 ; case 43
	.short _0222CD3A - _0222C322 - 2 ; case 44
	.short _0222CD3A - _0222C322 - 2 ; case 45
	.short _0222CD3A - _0222C322 - 2 ; case 46
	.short _0222CD3A - _0222C322 - 2 ; case 47
	.short _0222CD3A - _0222C322 - 2 ; case 48
	.short _0222CBDE - _0222C322 - 2 ; case 49
	.short _0222CC02 - _0222C322 - 2 ; case 50
	.short _0222CC10 - _0222C322 - 2 ; case 51
	.short _0222CC2E - _0222C322 - 2 ; case 52
	.short _0222CC44 - _0222C322 - 2 ; case 53
	.short _0222CC58 - _0222C322 - 2 ; case 54
	.short _0222CC6A - _0222C322 - 2 ; case 55
	.short _0222CC7E - _0222C322 - 2 ; case 56
	.short _0222CCC0 - _0222C322 - 2 ; case 57
	.short _0222CD34 - _0222C322 - 2 ; case 58
_0222C398:
	mov r0, #0x54
	bl ov74_022352A0
	ldr r0, _0222C644 ; =0x000015D8
	str r5, [r4, r0]
	mov r0, #1
	str r0, [r5]
	bl _0222CD3A
_0222C3AA:
	add r0, r6, #0
	add r1, r4, #0
	bl ov74_0222AB70
	add r0, r4, #0
	bl ov74_02229F04
	mov r0, #1
	mov r1, #3
	add r2, r5, #0
	mov r3, #2
	bl ov74_0223539C
	bl _0222CD3A
_0222C3C8:
	add r0, r5, #0
	bl ov74_022353FC
	bl _0222CD3A
_0222C3D2:
	ldr r2, _0222C648 ; =ov74_0222A6C0
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222AB0C
	bl _0222CD3A
_0222C3E0:
	ldr r2, _0222C64C ; =ov74_0222A5AC
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222AB0C
	bl _0222CD3A
_0222C3EE:
	ldr r2, _0222C650 ; =ov74_0222A2A4
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222AB0C
	bl _0222CD3A
_0222C3FC:
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222AC1C
	bl _0222CD3A
_0222C408:
	add r0, r4, #0
	bl ov74_0222CEE0
	ldr r0, _0222C654 ; =ov74_0223D0A8
	ldr r0, [r0, #0x10]
	cmp r0, #0x2d
	bne _0222C4A0
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	add r0, r6, #0
	bl ov74_0222A078
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x8c
	bl ov74_0222FD98
	add r1, r4, #0
	add r1, #0x80
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	cmp r0, #1
	bne _0222C44C
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	mov r0, #0x31
	str r0, [r5]
	b _0222C4A0
_0222C44C:
	add r0, r4, #0
	add r0, #0x58
	bl WindowIsInUse
	cmp r0, #0
	bne _0222C47A
	mov r0, #2
	str r0, [sp]
	mov r0, #0x1a
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r2, #0
	mov r0, #0x71
	add r1, r4, #0
	str r2, [sp, #0xc]
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r4]
	add r1, #0x58
	mov r3, #3
	bl AddWindowParameterized
_0222C47A:
	bl ov74_02236988
	add r1, r4, #0
	add r2, r0, #0
	add r0, r6, #0
	add r1, #0x58
	bl ov74_0222AAAC
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #4
	bl ov74_0222AA18
	add r0, r6, #0
	bl ov74_0222A43C
	mov r0, #0x1f
	str r0, [r5]
_0222C4A0:
	ldr r0, _0222C654 ; =ov74_0223D0A8
	ldr r0, [r0, #0x10]
	sub r0, #0x2e
	cmp r0, #1
	bls _0222C4AE
	bl _0222CD3A
_0222C4AE:
	bl ov74_0222CEC0
	mov r0, #0x11
	str r0, [r5]
	bl _0222CD3A
_0222C4BA:
	ldr r2, _0222C658 ; =ov74_0222A538
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222AB0C
	add r0, r4, #0
	bl ov74_0222CEE0
	bl _0222CD3A
_0222C4CE:
	add r0, r6, #0
	bl ov74_0222A078
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229E28
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229F28
	add r0, r7, #0
	bl ov74_0222A0E4
	cmp r0, #1
	bne _0222C53A
	add r0, r6, #0
	bl ov74_0222A174
	ldr r0, _0222C65C ; =0x000029F4
	mov r1, #1
	str r1, [r4, r0]
	add r0, r4, #0
	sub r1, r1, #2
	bl ov74_02229F28
	add r0, r4, #0
	add r0, #0x58
	mov r1, #0
	bl ov74_02229F60
	ldr r1, _0222C660 ; =0x000030A4
	mov r0, #0x54
	bl Heap_Alloc
	ldr r2, _0222C660 ; =0x000030A4
	mov r1, #0
	add r6, r0, #0
	bl memset
	ldr r0, _0222C65C ; =0x000029F4
	add r1, r4, r0
	ldr r0, _0222C664 ; =0x000030A0
	str r1, [r6, r0]
	bl ov74_02235708
	str r0, [r6, #0xc]
	ldr r0, _0222C668 ; =ov74_0222C04C
	add r1, r6, #0
	mov r2, #5
	bl SysTask_CreateOnMainQueue
	b _0222C548
_0222C53A:
	ldr r0, [r4]
	add r1, r7, #0
	bl ov74_02235DC4
	add r0, r6, #0
	bl ov74_0222A174
_0222C548:
	mov r0, #0x22
	str r0, [r5]
	b _0222CD3A
_0222C54E:
	ldr r0, _0222C65C ; =0x000029F4
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222C5DC
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #8
	mov r3, #0x38
	bl ov74_0222ADBC
	str r0, [r5]
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	b _0222CD3A
_0222C570:
	bl ov74_0223615C
	add r7, r0, #0
	cmp r7, #4
	bne _0222C57E
	bl ov74_02236128
_0222C57E:
	cmp r7, #2
	bne _0222C5D8
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov74_02229F28
	add r0, r4, #0
	add r0, #0x18
	mov r1, #0
	bl ov74_02229F78
	ldr r0, [r4]
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add r6, r4, #0
	add r6, #0xdc
	add r0, r6, #0
	bl ov74_0222A0E4
	cmp r0, #1
	bne _0222C5CC
	ldr r0, [r4]
	add r1, r6, #0
	bl ov74_02235DC4
	ldr r0, _0222C65C ; =0x000029F4
	mov r1, #2
	str r1, [r4, r0]
	b _0222C5D2
_0222C5CC:
	ldr r0, _0222C66C ; =SEQ_SE_DP_UG_020
	bl PlaySE
_0222C5D2:
	mov r0, #0x23
	str r0, [r5]
	b _0222CD3A
_0222C5D8:
	cmp r7, #3
	beq _0222C5DE
_0222C5DC:
	b _0222CD3A
_0222C5DE:
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov74_02229F28
	add r0, r4, #0
	add r0, #0xda
	ldrb r1, [r0]
	mov r0, #4
	mov r2, #0x1b
	bic r1, r0
	add r0, r4, #0
	add r0, #0xda
	strb r1, [r0]
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r3, #0x38
	bl ov74_0222ADBC
	str r0, [r5]
	b _0222CD3A
_0222C612:
	add r0, r4, #0
	bl ov74_0222CEE0
	ldr r0, _0222C654 ; =ov74_0223D0A8
	ldr r1, [r0, #0x10]
	add r0, r1, #0
	sub r0, #0x2d
	cmp r0, #2
	bhi _0222C704
	cmp r1, #0x2f
	bne _0222C62C
	bl ov74_0222CEC0
_0222C62C:
	add r0, r6, #0
	bl ov74_0222A494
	str r0, [r5]
	b _0222CD3A
_0222C636:
	add r0, r4, #0
	bl ov74_02229D6C
	ldr r1, _0222C670 ; =0x00000438
	b _0222C674
	.balign 4, 0
_0222C640: .word 0x000005C8
_0222C644: .word 0x000015D8
_0222C648: .word ov74_0222A6C0
_0222C64C: .word ov74_0222A5AC
_0222C650: .word ov74_0222A2A4
_0222C654: .word ov74_0223D0A8
_0222C658: .word ov74_0222A538
_0222C65C: .word 0x000029F4
_0222C660: .word 0x000030A4
_0222C664: .word 0x000030A0
_0222C668: .word ov74_0222C04C
_0222C66C: .word SEQ_SE_DP_UG_020
_0222C670: .word 0x00000438
_0222C674:
	str r0, [r4, r1]
	mov r0, #0
	ldr r1, [r4, r1]
	mvn r0, r0
	cmp r1, r0
	beq _0222C6EC
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x8c
	bl ov74_0222FD98
	add r1, r4, #0
	add r1, #0x80
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x58
	bl WindowIsInUse
	cmp r0, #0
	bne _0222C6C6
	mov r0, #2
	str r0, [sp]
	mov r0, #0x1a
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r2, #0
	mov r0, #0x71
	add r1, r4, #0
	str r2, [sp, #0xc]
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r4]
	add r1, #0x58
	mov r3, #3
	bl AddWindowParameterized
_0222C6C6:
	add r1, r4, #0
	add r2, r4, #0
	add r0, r6, #0
	add r1, #0x58
	add r2, #0x8c
	bl ov74_0222AAAC
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #4
	bl ov74_0222AA18
	add r0, r6, #0
	mov r1, #0
	bl ov74_0222A240
	mov r0, #8
	str r0, [r5]
_0222C6EC:
	ldr r0, _0222CA14 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	bne _0222C706
	ldr r0, _0222CA18 ; =0x00000434
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222C706
_0222C704:
	b _0222CD3A
_0222C706:
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	bl ov74_02229DF8
	bl sub_0203A914
	mov r0, #0x11
	str r0, [r5]
	b _0222CD3A
_0222C71C:
	ldr r2, _0222CA1C ; =ov74_0222A494
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222AB0C
	b _0222CD3A
_0222C728:
	bl sub_0203769C
	add r7, r0, #0
	beq _0222C780
	lsl r0, r7, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	beq _0222C780
	mov r0, #0xab
	bl sub_02037B38
	cmp r0, #1
	bne _0222C7B0
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	mov r0, #1
	add r1, r0, #0
	bl sub_020398D4
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #7
	bl ov74_0222AA18
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229F28
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229E28
	mov r1, #0x96
	ldr r0, _0222CA18 ; =0x00000434
	lsl r1, r1, #2
	str r1, [r4, r0]
	mov r0, #0xa
	str r0, [r5]
	b _0222C7B0
_0222C780:
	cmp r7, #0
	beq _0222C7B0
	lsl r0, r7, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	bne _0222C7B0
	bl ov74_02229DF8
	bl sub_0203A914
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov74_02229F28
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	mov r0, #0x10
	str r0, [r5]
	b _0222CD3A
_0222C7B0:
	ldr r0, _0222CA14 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	bne _0222C7C8
	ldr r0, _0222CA18 ; =0x00000434
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222C8B8
_0222C7C8:
	bl ov74_02229DF8
	bl sub_0203A914
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov74_02229F28
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	mov r0, #0x11
	str r0, [r5]
	b _0222CD3A
_0222C7E8:
	bl ov74_02229DBC
	cmp r0, #0
	beq _0222C7F4
	mov r0, #0xb
	str r0, [r5]
_0222C7F4:
	bl sub_0203769C
	ldr r1, _0222CA14 ; =gSystem
	ldr r2, [r1, #0x48]
	mov r1, #2
	tst r1, r2
	bne _0222C820
	ldr r1, _0222CA18 ; =0x00000434
	ldr r2, [r4, r1]
	sub r2, r2, #1
	str r2, [r4, r1]
	ldr r1, [r4, r1]
	cmp r1, #0
	beq _0222C820
	cmp r0, #0
	beq _0222C8B8
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	bne _0222C8B8
_0222C820:
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	bl ov74_02229DF8
	bl sub_0203A914
	mov r0, #0x11
	str r0, [r5]
	b _0222CD3A
_0222C836:
	add r0, r6, #0
	bl ov74_0222A078
	add r1, r0, #0
	ldr r0, [r4]
	bl ov74_02235DC4
	mov r0, #0
	add r1, r0, #0
	bl sub_020398D4
	add r0, r6, #0
	bl ov74_0222A174
	mov r0, #0xc
	str r0, [r5]
	b _0222CD3A
_0222C858:
	bl sub_0203769C
	cmp r0, #0
	beq _0222C896
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	bne _0222C896
	bl ov74_02229DF8
	ldr r0, _0222CA20 ; =0x000029EC
	mov r1, #1
	str r1, [r4, r0]
	bl ov74_02236140
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	bl sub_0203A914
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov74_02229F28
	mov r0, #0xe
	str r0, [r5]
	b _0222CD3A
_0222C896:
	bl ov74_0223615C
	cmp r0, #4
	bne _0222C8B0
	mov r0, #0x93
	bl sub_02037AC0
	mov r0, #0xd
	str r0, [r5]
	ldr r0, _0222CA24 ; =0x0000043C
	mov r1, #0x78
	str r1, [r4, r0]
	b _0222CD3A
_0222C8B0:
	bl ov74_0223615C
	cmp r0, #3
	beq _0222C8BA
_0222C8B8:
	b _0222CD3A
_0222C8BA:
	bl ov74_02236140
	add r0, r4, #0
	add r0, #0xda
	ldrb r1, [r0]
	mov r0, #4
	bic r1, r0
	add r0, r4, #0
	add r0, #0xda
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #0x1b
	mov r3, #0x38
	bl ov74_0222ADBC
	str r0, [r5]
	b _0222CD3A
_0222C8E8:
	mov r0, #0x93
	bl sub_02037B38
	cmp r0, #1
	bne _0222C902
	bl ov74_02236128
	ldr r0, _0222CA24 ; =0x0000043C
	mov r1, #0xa
	str r1, [r4, r0]
	mov r0, #0xf
	str r0, [r5]
	b _0222CD3A
_0222C902:
	ldr r0, _0222CA24 ; =0x0000043C
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222CA0C
	bl ov74_02236140
	add r0, r4, #0
	add r0, #0xda
	ldrb r1, [r0]
	mov r0, #4
	bic r1, r0
	add r0, r4, #0
	add r0, #0xda
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #0x1b
	mov r3, #0x38
	bl ov74_0222ADBC
	str r0, [r5]
	b _0222CD3A
_0222C93E:
	add r0, r4, #0
	add r0, #0x58
	mov r1, #0
	bl ov74_02229F60
	add r0, r4, #0
	add r0, #0xda
	ldrb r1, [r0]
	mov r0, #4
	mov r2, #0x1d
	bic r1, r0
	add r0, r4, #0
	add r0, #0xda
	strb r1, [r0]
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r3, #0x38
	bl ov74_0222ADBC
	str r0, [r5]
	b _0222CD3A
_0222C96A:
	ldr r0, _0222CA24 ; =0x0000043C
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222CA0C
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	bl ov74_02229DF8
	bl sub_0203A914
	ldr r0, _0222CA28 ; =SEQ_SE_DP_UG_020
	bl PlaySE
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov74_02229F28
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #8
	mov r3, #0x38
	bl ov74_0222ADBC
	str r0, [r5]
	b _0222CD3A
_0222C9AA:
	ldr r0, _0222CA2C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #0x19
	bl ov74_0222AA18
	add r0, r4, #0
	add r0, #0x58
	mov r1, #0
	bl ov74_02229F60
	mov r0, #0x12
	str r0, [r5]
	b _0222CD3A
_0222C9CC:
	ldr r0, _0222CA30 ; =0x000015DC
	ldr r1, [r4, r0]
	cmp r1, #0
	beq _0222C9DA
	sub r1, r1, #1
	str r1, [r4, r0]
	b _0222CD3A
_0222C9DA:
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	ldr r0, _0222CA2C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #0x18
	bl ov74_0222AA18
	add r0, r4, #0
	add r0, #0x58
	mov r1, #0
	bl ov74_02229F60
	mov r0, #0x12
	str r0, [r5]
	b _0222CD3A
_0222CA04:
	ldr r0, _0222CA14 ; =gSystem
	ldr r0, [r0, #0x48]
	cmp r0, #0
	bne _0222CA0E
_0222CA0C:
	b _0222CD3A
_0222CA0E:
	ldr r0, _0222CA2C ; =SEQ_SE_DP_SELECT
	b _0222CA34
	nop
_0222CA14: .word gSystem
_0222CA18: .word 0x00000434
_0222CA1C: .word ov74_0222A494
_0222CA20: .word 0x000029EC
_0222CA24: .word 0x0000043C
_0222CA28: .word SEQ_SE_DP_UG_020
_0222CA2C: .word SEQ_SE_DP_SELECT
_0222CA30: .word 0x000015DC
_0222CA34:
	bl PlaySE
	add r0, r6, #0
	mov r1, #0xc4
	mov r2, #0
	bl ov74_0222A94C
	mov r0, #3
	str r0, [r5]
	b _0222CD3A
_0222CA48:
	ldr r0, _0222CD54 ; =0x000015DC
	ldr r1, [r4, r0]
	cmp r1, #0
	beq _0222CA56
	sub r1, r1, #1
	str r1, [r4, r0]
	b _0222CD3A
_0222CA56:
	add r0, r4, #0
	add r0, #0x84
	ldr r0, [r0]
	cmp r0, #0x1b
	beq _0222CA6C
	add r0, r4, #0
	mov r1, #0xea
	add r0, #0x8c
	lsl r1, r1, #2
	bl ov74_02235258
_0222CA6C:
	add r1, r4, #0
	ldr r0, [r4, #4]
	add r1, #0x8c
	bl ov74_0222FD98
	add r1, r4, #0
	add r1, #0x80
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	cmp r0, #1
	bne _0222CA94
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	mov r0, #0x31
	str r0, [r5]
	b _0222CD3A
_0222CA94:
	add r0, r4, #0
	add r0, #0x58
	bl WindowIsInUse
	cmp r0, #0
	bne _0222CAC2
	mov r0, #2
	str r0, [sp]
	mov r0, #0x1a
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r2, #0
	mov r0, #0x71
	add r1, r4, #0
	str r2, [sp, #0xc]
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r4]
	add r1, #0x58
	mov r3, #3
	bl AddWindowParameterized
_0222CAC2:
	add r1, r4, #0
	add r2, r4, #0
	add r0, r6, #0
	add r1, #0x58
	add r2, #0x8c
	bl ov74_0222AAAC
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #4
	bl ov74_0222AA18
	add r0, r6, #0
	mov r1, #0
	bl ov74_0222A240
	mov r0, #0x14
	str r0, [r5]
	b _0222CD3A
_0222CAEA:
	ldr r2, _0222CD58 ; =ov74_0222A494
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222AB0C
	b _0222CD3A
_0222CAF6:
	mov r0, #0x16
	str r0, [r5]
	b _0222CD3A
_0222CAFC:
	add r0, r6, #0
	bl ov74_0222A078
	add r1, r0, #0
	ldr r0, [r4]
	bl ov74_02235DC4
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #7
	bl ov74_0222AA18
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229F28
	add r0, r4, #0
	mov r1, #1
	bl ov74_02229E28
	ldr r0, _0222CD5C ; =0x0000043C
	mov r1, #0x3c
	str r1, [r4, r0]
	mov r0, #0x17
	str r0, [r5]
	b _0222CD3A
_0222CB32:
	ldr r0, _0222CD5C ; =0x0000043C
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222CC18
	add r0, r6, #0
	bl ov74_0222A174
	mov r0, #0x18
	str r0, [r5]
	b _0222CD3A
_0222CB4C:
	bl ov74_0223615C
	cmp r0, #4
	bne _0222CB58
	bl ov74_02236128
_0222CB58:
	bl ov74_0223615C
	cmp r0, #2
	bne _0222CB90
	ldr r0, _0222CD5C ; =0x0000043C
	mov r1, #1
	str r1, [r4, r0]
	add r0, r4, #0
	mov r1, #0
	bl ov74_02229E28
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov74_02229F28
	ldr r0, _0222CD60 ; =SEQ_SE_DP_UG_020
	bl PlaySE
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r2, #8
	mov r3, #0x19
	bl ov74_0222ADBC
	str r0, [r5]
	b _0222CD3A
_0222CB90:
	bl ov74_0223615C
	cmp r0, #3
	bne _0222CC18
	mov r1, #0
	add r0, r4, #0
	mvn r1, r1
	bl ov74_02229F28
	add r0, r4, #0
	add r0, #0xda
	ldrb r1, [r0]
	mov r0, #4
	mov r2, #0x1b
	bic r1, r0
	add r0, r4, #0
	add r0, #0xda
	strb r1, [r0]
	add r1, r4, #0
	add r0, r6, #0
	add r1, #0x18
	mov r3, #0x38
	bl ov74_0222ADBC
	str r0, [r5]
	b _0222CD3A
_0222CBC4:
	ldr r0, _0222CD5C ; =0x0000043C
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r1, [r4, r0]
	cmp r1, #0
	bne _0222CC18
	mov r1, #1
	lsl r1, r1, #0x10
	str r1, [r4, r0]
	mov r0, #0x38
	str r0, [r5]
	b _0222CD3A
_0222CBDE:
	add r0, r4, #0
	add r0, #0x80
	ldr r0, [r0]
	cmp r0, #5
	beq _0222CBEE
	add r0, r4, #0
	bl ov74_0222AE3C
_0222CBEE:
	add r0, r6, #0
	bl ov74_0222AD6C
	str r0, [r5]
	add r0, r4, #0
	add r0, #0x48
	mov r1, #0
	bl ov74_02229F60
	b _0222CD3A
_0222CC02:
	mov r1, #0
	add r0, r6, #0
	add r2, r1, #0
	bl ov74_0222ADBC
	str r0, [r5]
	b _0222CD3A
_0222CC10:
	ldr r0, _0222CD64 ; =gSystem
	ldr r0, [r0, #0x48]
	cmp r0, #0
	bne _0222CC1A
_0222CC18:
	b _0222CD3A
_0222CC1A:
	add r0, r4, #0
	add r0, #0x58
	mov r1, #0
	bl ov74_02229F60
	add r0, r6, #0
	bl ov74_0222A5AC
	str r0, [r5]
	b _0222CD3A
_0222CC2E:
	add r0, r6, #0
	mov r1, #1
	bl ov74_0222A240
	mov r0, #8
	str r0, [r5]
	add r0, r4, #0
	mov r1, #0
	add r0, #0x80
	str r1, [r0]
	b _0222CD3A
_0222CC44:
	add r0, r6, #0
	bl ov74_02229E68
	mov r0, #0x11
	mov r1, #0
	lsl r0, r0, #6
	str r1, [r4, r0]
	add sp, #0x14
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0222CC58:
	add r0, r6, #0
	bl ov74_02229E68
	mov r1, #0x11
	mov r0, #1
	lsl r1, r1, #6
	add sp, #0x14
	str r0, [r4, r1]
	pop {r4, r5, r6, r7, pc}
_0222CC6A:
	add r0, r6, #0
	bl ov74_02229E68
	mov r0, #0x11
	mov r1, #2
	lsl r0, r0, #6
	str r1, [r4, r0]
	add sp, #0x14
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0222CC7E:
	ldr r0, _0222CD64 ; =gSystem
	ldr r0, [r0, #0x48]
	cmp r0, #0
	beq _0222CD3A
	ldr r0, _0222CD68 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r0, r4, #0
	add r0, #0xda
	ldrb r0, [r0]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0222CCAA
	ldr r2, _0222CD6C ; =0x000015D8
	mov r0, #0
	ldr r2, [r4, r2]
	mov r1, #0x39
	mov r3, #2
	bl ov74_0223539C
	b _0222CD3A
_0222CCAA:
	mov r0, #1
	bl ov74_02235390
	ldr r2, _0222CD6C ; =0x000015D8
	mov r0, #0
	ldr r2, [r4, r2]
	mov r1, #0x3a
	mov r3, #2
	bl ov74_0223539C
	b _0222CD3A
_0222CCC0:
	ldr r0, [r4]
	bl ov74_0222A7A0
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	add r0, r4, #0
	add r0, #0xda
	ldrb r0, [r0]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0222CD08
	add r0, r4, #0
	add r0, #0xdc
	ldrh r0, [r0]
	cmp r0, #3
	bne _0222CD08
	add r0, r4, #0
	add r0, #0xe0
	ldr r1, [r0]
	ldr r0, _0222CD70 ; =0x00000215
	cmp r1, r0
	bne _0222CD08
	add r1, r4, #0
	ldr r0, [r4]
	add r1, #0xdc
	mov r2, #0x54
	bl ov74_0222FC50
	b _0222CD14
_0222CD08:
	add r1, r4, #0
	ldr r0, [r4]
	add r1, #0xdc
	mov r2, #0x54
	bl ov74_0222EC08
_0222CD14:
	ldr r2, _0222CD6C ; =0x000015D8
	mov r0, #1
	ldr r2, [r4, r2]
	mov r1, #0x38
	mov r3, #2
	bl ov74_0223539C
	add r0, r4, #0
	add r0, #0xda
	ldrb r1, [r0]
	mov r0, #4
	bic r1, r0
	add r0, r4, #0
	add r0, #0xda
	strb r1, [r0]
	b _0222CD3A
_0222CD34:
	mov r0, #0
	bl OS_ResetSystem
_0222CD3A:
	ldr r0, _0222CD74 ; =0x000029E8
	ldr r1, [r4, r0]
	cmp r1, #0
	beq _0222CD46
	add r0, r4, #0
	blx r1
_0222CD46:
	ldr r0, _0222CD78 ; =0x000029F4
	ldr r0, [r4, r0]
	bl ov74_022358C8
	mov r0, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222CD54: .word 0x000015DC
_0222CD58: .word ov74_0222A494
_0222CD5C: .word 0x0000043C
_0222CD60: .word SEQ_SE_DP_UG_020
_0222CD64: .word gSystem
_0222CD68: .word SEQ_SE_DP_SELECT
_0222CD6C: .word 0x000015D8
_0222CD70: .word 0x00000215
_0222CD74: .word 0x000029E8
_0222CD78: .word 0x000029F4
	thumb_func_end ov74_0222C2EC


	thumb_func_start ov74_0222CD7C
ov74_0222CD7C: ; 0x0222CD7C
	ldr r0, _0222CD84 ; =ov74_0223D0A8
	ldr r0, [r0]
	bx lr
	nop
_0222CD84: .word ov74_0223D0A8
	thumb_func_end ov74_0222CD7C


	thumb_func_start ov74_0222CD88
ov74_0222CD88: ; 0x0222CD88
	ldr r1, _0222CD90 ; =ov74_0223D0A8
	str r0, [r1]
	bx lr
	nop
_0222CD90: .word ov74_0223D0A8
	thumb_func_end ov74_0222CD88


	thumb_func_start ov74_0222CD94
ov74_0222CD94: ; 0x0222CD94
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	mov r0, #0x11
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222CDB2
	ldr r0, _0222CDF8 ; =FS_OVERLAY_ID(intro_title)
	ldr r1, _0222CDFC ; =gApplication_TitleScreen
	bl RegisterMainOverlay
	b _0222CDCC
_0222CDB2:
	cmp r0, #1
	bne _0222CDC0
	ldr r0, _0222CE00 ; =FS_OVERLAY_ID(OVY_74)
	ldr r1, _0222CE04 ; =_0223B410
	bl RegisterMainOverlay
	b _0222CDCC
_0222CDC0:
	cmp r0, #2
	bne _0222CDCC
	ldr r0, _0222CE00 ; =FS_OVERLAY_ID(OVY_74)
	ldr r1, _0222CE08 ; =_0223B420
	bl RegisterMainOverlay
_0222CDCC:
	mov r0, #0x59
	bl Heap_Destroy
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x54
	bl Heap_Destroy
	ldr r0, _0222CE0C ; =0x000015D4
	ldr r0, [r4, r0]
	cmp r0, #2
	bne _0222CDEC
	mov r0, #0
	bl sub_0201A4B0
_0222CDEC:
	mov r0, #0
	bl ov74_02236034
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_0222CDF8: .word FS_OVERLAY_ID(intro_title)
_0222CDFC: .word gApplication_TitleScreen
_0222CE00: .word FS_OVERLAY_ID(OVY_74)
_0222CE04: .word _0223B410
_0222CE08: .word _0223B420
_0222CE0C: .word 0x000015D4
	thumb_func_end ov74_0222CD94


	thumb_func_start ov74_0222CE10
ov74_0222CE10: ; 0x0222CE10
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222CE64 ; =0x000005C8
	ldr r0, [r4, r0]
	cmp r0, #0x1c
	beq _0222CE26
	cmp r0, #0x1d
	beq _0222CE62
	cmp r0, #0x1e
	beq _0222CE3A
	pop {r4, pc}
_0222CE26:
	ldr r0, [r4, #4]
	bl sub_02038D28
	ldr r0, _0222CE68 ; =0x000005CC
	mov r1, #0x78
	str r1, [r4, r0]
	mov r1, #0x1e
	sub r0, r0, #4
	str r1, [r4, r0]
	pop {r4, pc}
_0222CE3A:
	bl sub_02038D80
	mov r1, #1
	tst r0, r1
	beq _0222CE4A
	mov r0, #0x5d
	lsl r0, r0, #4
	str r1, [r4, r0]
_0222CE4A:
	ldr r0, _0222CE68 ; =0x000005CC
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222CE62
	bl sub_02038D64
	ldr r0, _0222CE64 ; =0x000005C8
	mov r1, #0x1d
	str r1, [r4, r0]
_0222CE62:
	pop {r4, pc}
	.balign 4, 0
_0222CE64: .word 0x000005C8
_0222CE68: .word 0x000005CC
	thumb_func_end ov74_0222CE10


	thumb_func_start ov74_0222CE6C
ov74_0222CE6C: ; 0x0222CE6C
	cmp r0, #4
	bhi _0222CEB8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222CE7C: ; jump table
	.short _0222CE86 - _0222CE7C - 2 ; case 0
	.short _0222CE8E - _0222CE7C - 2 ; case 1
	.short _0222CE96 - _0222CE7C - 2 ; case 2
	.short _0222CE9E - _0222CE7C - 2 ; case 3
	.short _0222CEB2 - _0222CE7C - 2 ; case 4
_0222CE86:
	ldr r0, _0222CEBC ; =ov74_0223D0A8
	mov r1, #0x28
	str r1, [r0, #0x10]
	bx lr
_0222CE8E:
	ldr r0, _0222CEBC ; =ov74_0223D0A8
	mov r1, #0x29
	str r1, [r0, #0x10]
	bx lr
_0222CE96:
	ldr r0, _0222CEBC ; =ov74_0223D0A8
	mov r1, #0x2a
	str r1, [r0, #0x10]
	bx lr
_0222CE9E:
	ldr r0, _0222CEBC ; =ov74_0223D0A8
	ldr r1, [r0, #0x10]
	cmp r1, #0x2a
	bne _0222CEAC
	mov r1, #0x2c
	str r1, [r0, #0x10]
	bx lr
_0222CEAC:
	mov r1, #0x2f
	str r1, [r0, #0x10]
	bx lr
_0222CEB2:
	ldr r0, _0222CEBC ; =ov74_0223D0A8
	mov r1, #0x30
	str r1, [r0, #0x10]
_0222CEB8:
	bx lr
	nop
_0222CEBC: .word ov74_0223D0A8
	thumb_func_end ov74_0222CE6C


	thumb_func_start ov74_0222CEC0
ov74_0222CEC0: ; 0x0222CEC0
	push {r3, lr}
	bl sub_02034DE0
	ldr r0, _0222CEDC ; =ov74_0223D0A8
	ldr r0, [r0, #4]
	bl Heap_Free
	bl sub_0203A914
	ldr r0, _0222CEDC ; =ov74_0223D0A8
	mov r1, #0
	str r1, [r0, #4]
	pop {r3, pc}
	nop
_0222CEDC: .word ov74_0223D0A8
	thumb_func_end ov74_0222CEC0


	thumb_func_start ov74_0222CEE0
ov74_0222CEE0: ; 0x0222CEE0
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	ldr r0, [r0, #0x10]
	cmp r0, #0x2c
	bne _0222CF06
	bl ov74_0222CEC0
	bl ov74_022368D4
	cmp r0, #0
	beq _0222CF00
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	mov r1, #0x2d
	str r1, [r0, #0x10]
	b _0222CF06
_0222CF00:
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	mov r1, #0x2e
	str r1, [r0, #0x10]
_0222CF06:
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	ldr r0, [r0, #0x10]
	cmp r0, #0x25
	beq _0222CF22
	cmp r0, #0x26
	beq _0222CF22
	cmp r0, #0x27
	beq _0222CF22
	cmp r0, #0x28
	beq _0222CF22
	cmp r0, #0x29
	beq _0222CF22
	cmp r0, #0x2b
	bne _0222CF2E
_0222CF22:
	bl WM_GetLinkLevel
	mov r1, #3
	sub r0, r1, r0
	bl sub_0203A930
_0222CF2E:
	ldr r1, _0222CFEC ; =ov74_0223D0A8
	ldr r0, [r1, #0x10]
	sub r0, #0x25
	cmp r0, #0xb
	bhi _0222CFA8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222CF44: ; jump table
	.short _0222CF5C - _0222CF44 - 2 ; case 0
	.short _0222CF68 - _0222CF44 - 2 ; case 1
	.short _0222CFA8 - _0222CF44 - 2 ; case 2
	.short _0222CFA8 - _0222CF44 - 2 ; case 3
	.short _0222CF9E - _0222CF44 - 2 ; case 4
	.short _0222CFA8 - _0222CF44 - 2 ; case 5
	.short _0222CFA8 - _0222CF44 - 2 ; case 6
	.short _0222CFA8 - _0222CF44 - 2 ; case 7
	.short _0222CFA8 - _0222CF44 - 2 ; case 8
	.short _0222CFA8 - _0222CF44 - 2 ; case 9
	.short _0222CFA6 - _0222CF44 - 2 ; case 10
	.short _0222CFA8 - _0222CF44 - 2 ; case 11
_0222CF5C:
	bl sub_02034D8C
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	mov r1, #0x26
	str r1, [r0, #0x10]
	b _0222CFA8
_0222CF68:
	bl sub_02034DB8
	cmp r0, #1
	bne _0222CFA8
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	mov r1, #0
	str r1, [r0, #0xc]
	bl ov74_02236980
	add r1, r0, #0
	mov r0, #0x54
	bl Heap_Alloc
	add r2, r0, #0
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	ldr r1, _0222CFF0 ; =ov74_0222CE6C
	str r2, [r0, #4]
	ldr r0, _0222CFF4 ; =0x000005D4
	add r0, r4, r0
	bl ov74_02236680
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	mov r1, #0x27
	str r1, [r0, #0x10]
	bl sub_0203A880
	b _0222CFA8
_0222CF9E:
	ldr r0, [r1, #0xc]
	add r0, r0, #1
	str r0, [r1, #0xc]
	b _0222CFA8
_0222CFA6:
	pop {r4, pc}
_0222CFA8:
	ldr r0, _0222CFF8 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _0222CFE8
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	ldr r0, [r0, #0x10]
	sub r0, #0x28
	cmp r0, #8
	bhi _0222CFE8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0222CFC8: ; jump table
	.short _0222CFDA - _0222CFC8 - 2 ; case 0
	.short _0222CFDA - _0222CFC8 - 2 ; case 1
	.short _0222CFE8 - _0222CFC8 - 2 ; case 2
	.short _0222CFE8 - _0222CFC8 - 2 ; case 3
	.short _0222CFE8 - _0222CFC8 - 2 ; case 4
	.short _0222CFE8 - _0222CFC8 - 2 ; case 5
	.short _0222CFE8 - _0222CFC8 - 2 ; case 6
	.short _0222CFE8 - _0222CFC8 - 2 ; case 7
	.short _0222CFDA - _0222CFC8 - 2 ; case 8
_0222CFDA:
	bl ov74_022365FC
	cmp r0, #0
	beq _0222CFE8
	ldr r0, _0222CFEC ; =ov74_0223D0A8
	mov r1, #0x2b
	str r1, [r0, #0x10]
_0222CFE8:
	pop {r4, pc}
	nop
_0222CFEC: .word ov74_0223D0A8
_0222CFF0: .word ov74_0222CE6C
_0222CFF4: .word 0x000005D4
_0222CFF8: .word gSystem
	thumb_func_end ov74_0222CEE0


	thumb_func_start ov74_0222CFFC
ov74_0222CFFC: ; 0x0222CFFC
	push {r3, lr}
	sub sp, #8
	bl ov74_0222D024
	bl ov74_0223563C
	bl ov74_02235690
	mov r0, #0x11
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0x13
	mov r2, #0x10
	mov r3, #0x12
	bl ov74_02235728
	add sp, #8
	pop {r3, pc}
	thumb_func_end ov74_0222CFFC


	thumb_func_start ov74_0222D024
ov74_0222D024: ; 0x0222D024
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222D088 ; =0x00002DC4
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222D034
	bl Sprite_Delete
_0222D034:
	ldr r0, _0222D08C ; =0x00002DC8
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222D040
	bl Sprite_Delete
_0222D040:
	ldr r0, _0222D08C ; =0x00002DC8
	mov r1, #0
	str r1, [r4, r0]
	ldr r2, [r4, r0]
	sub r1, r0, #4
	str r2, [r4, r1]
	add r0, r0, #4
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222D058
	bl Sprite_Delete
_0222D058:
	ldr r0, _0222D090 ; =0x00002DD0
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222D064
	bl Sprite_Delete
_0222D064:
	ldr r0, _0222D094 ; =0x00002DD4
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222D070
	bl Sprite_Delete
_0222D070:
	ldr r1, _0222D094 ; =0x00002DD4
	mov r0, #0
	str r0, [r4, r1]
	ldr r2, [r4, r1]
	sub r0, r1, #4
	str r2, [r4, r0]
	ldr r0, [r4, r0]
	sub r1, #8
	str r0, [r4, r1]
	bl ov74_022359BC
	pop {r4, pc}
	.balign 4, 0
_0222D088: .word 0x00002DC4
_0222D08C: .word 0x00002DC8
_0222D090: .word 0x00002DD0
_0222D094: .word 0x00002DD4
	thumb_func_end ov74_0222D024


	thumb_func_start ov74_0222D098
ov74_0222D098: ; 0x0222D098
	push {r3, r4, lr}
	sub sp, #4
	ldr r1, _0222D0E0 ; =0x00003D4C
	add r4, r0, #0
	mov r0, #0
	str r0, [r4, r1]
	mov r1, #1
	str r1, [sp]
	ldr r1, _0222D0E4 ; =0x00002DC4
	mov r2, #0x48
	ldr r1, [r4, r1]
	mov r3, #0xa8
	bl ov74_02235930
	ldr r1, _0222D0E4 ; =0x00002DC4
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #2
	bl Sprite_SetPriority
	mov r0, #0
	ldr r1, _0222D0E8 ; =0x00002DC8
	str r0, [sp]
	ldr r1, [r4, r1]
	mov r2, #0xb8
	mov r3, #0xa8
	bl ov74_02235930
	ldr r1, _0222D0E8 ; =0x00002DC8
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #2
	bl Sprite_SetPriority
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_0222D0E0: .word 0x00003D4C
_0222D0E4: .word 0x00002DC4
_0222D0E8: .word 0x00002DC8
	thumb_func_end ov74_0222D098


	thumb_func_start ov74_0222D0EC
ov74_0222D0EC: ; 0x0222D0EC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl WindowIsInUse
	cmp r0, #1
	bne _0222D102
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0200E5D4
_0222D102:
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_0222D0EC


	thumb_func_start ov74_0222D104
ov74_0222D104: ; 0x0222D104
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl WindowIsInUse
	cmp r0, #1
	bne _0222D11A
	add r0, r5, #0
	add r1, r4, #0
	bl ClearFrameAndWindow2
_0222D11A:
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_0222D104


	thumb_func_start ov74_0222D11C
ov74_0222D11C: ; 0x0222D11C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	ldr r0, _0222D1C4 ; =0x00002BCC
	add r4, r1, #0
	ldr r0, [r5, r0]
	add r7, r2, #0
	str r3, [sp]
	cmp r0, #0
	beq _0222D134
	bl ListMenuItems_Delete
_0222D134:
	ldr r0, _0222D1C8 ; =0x00002BC8
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0222D144
	mov r1, #0
	add r2, r1, #0
	bl DestroyListMenu
_0222D144:
	add r0, r7, #0
	mov r1, #0x55
	bl ListMenuItems_New
	ldr r1, _0222D1C4 ; =0x00002BCC
	mov r2, #0xf7
	str r0, [r5, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r3, #0x55
	bl NewMsgDataFromNarc
	ldr r1, _0222D1CC ; =0x00002A04
	mov r6, #0
	str r0, [r5, r1]
	cmp r7, #0
	ble _0222D17E
_0222D166:
	ldr r0, _0222D1C4 ; =0x00002BCC
	ldr r1, _0222D1CC ; =0x00002A04
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [r4]
	ldr r3, [r4, #4]
	bl ListMenuItems_AppendFromMsgData
	add r6, r6, #1
	add r4, #8
	cmp r6, r7
	blt _0222D166
_0222D17E:
	ldr r0, _0222D1CC ; =0x00002A04
	ldr r0, [r5, r0]
	bl DestroyMsgData
	ldr r4, _0222D1D0 ; =ov74_0223C320
	add r3, sp, #4
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, _0222D1C4 ; =0x00002BCC
	mov r1, #0
	ldr r0, [r5, r0]
	mov r3, #0x55
	str r0, [sp, #4]
	add r0, sp, #4
	strh r7, [r0, #0x10]
	ldr r0, [sp]
	str r0, [sp, #0x10]
	add r0, r2, #0
	ldr r2, [sp, #0x38]
	lsl r2, r2, #0x10
	lsr r2, r2, #0x10
	bl ListMenuInit
	ldr r1, _0222D1C8 ; =0x00002BC8
	str r0, [r5, r1]
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_0222D1C4: .word 0x00002BCC
_0222D1C8: .word 0x00002BC8
_0222D1CC: .word 0x00002A04
_0222D1D0: .word ov74_0223C320
	thumb_func_end ov74_0222D11C


	thumb_func_start ov74_0222D1D4
ov74_0222D1D4: ; 0x0222D1D4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x55
	bl NewMsgDataFromNarc
	add r4, r0, #0
	mov r0, #0x55
	bl MessageFormat_New
	add r6, r0, #0
	mov r0, #1
	mov r1, #6
	bl GetFontAttribute
	add r1, r0, #0
	add r0, r5, #0
	bl FillWindowPixelBuffer
	add r0, r6, #0
	add r1, r4, #0
	add r2, r7, #0
	mov r3, #0x55
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0222D244 ; =0x00010200
	mov r1, #1
	str r0, [sp, #8]
	add r0, r5, #0
	add r2, r7, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r5, #0
	bl CopyWindowToVram
	add r0, r7, #0
	bl String_Delete
	add r0, r4, #0
	bl DestroyMsgData
	add r0, r6, #0
	bl MessageFormat_Delete
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222D244: .word 0x00010200
	thumb_func_end ov74_0222D1D4


	thumb_func_start ov74_0222D248
ov74_0222D248: ; 0x0222D248
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x55
	mov r1, #0xf
	str r0, [sp, #4]
	mov r0, #0x71
	mov r2, #0
	lsl r3, r1, #5
	bl GfGfxLoader_GXLoadPal
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x55
	mov r3, #6
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0x14
	mov r2, #0
	lsl r3, r3, #6
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	mov r0, #0x55
	str r0, [sp, #0xc]
	mov r0, #0x71
	mov r1, #0x15
	add r2, r4, #0
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	mov r0, #0x55
	str r0, [sp, #0xc]
	mov r0, #0x71
	mov r1, #0x16
	add r2, r4, #0
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #0xc
	mov r2, #0
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #1
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	add r0, r4, #0
	mov r1, #1
	bl BgCommitTilemapBufferToVram
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov74_0222D248


	thumb_func_start ov74_0222D2D4
ov74_0222D2D4: ; 0x0222D2D4
	push {r4, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	bl ov74_0222D448
	ldr r0, _0222D300 ; =0x00002BD0
	mov r1, #0x2f
	add r0, r4, r0
	bl ov74_0222D1D4
	ldr r3, _0222D304 ; =0x00002BE0
	add r0, r4, #0
	add r1, r4, r3
	add r3, #0x10
	ldr r3, [r4, r3]
	mov r2, #0xa
	bl ov74_0222D9E0
	mov r0, #0xe
	pop {r4, pc}
	nop
_0222D300: .word 0x00002BD0
_0222D304: .word 0x00002BE0
	thumb_func_end ov74_0222D2D4


	thumb_func_start ov74_0222D308
ov74_0222D308: ; 0x0222D308
	push {r4, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	bl ov74_0222D448
	ldr r1, _0222D34C ; =0x00002BA0
	ldr r0, [r4, r1]
	add r1, #0x20
	ldr r1, [r4, r1]
	bl SaveMysteryGift_HasAnyGift
	cmp r0, #1
	ldr r0, _0222D350 ; =0x00002BD0
	bne _0222D330
	add r0, r4, r0
	mov r1, #0x3f
	bl ov74_0222D1D4
	b _0222D338
_0222D330:
	add r0, r4, r0
	mov r1, #0x3e
	bl ov74_0222D1D4
_0222D338:
	ldr r3, _0222D354 ; =0x00002BE0
	add r0, r4, #0
	add r1, r4, r3
	add r3, #0x10
	ldr r3, [r4, r3]
	mov r2, #9
	bl ov74_0222D9E0
	mov r0, #0xc
	pop {r4, pc}
	.balign 4, 0
_0222D34C: .word 0x00002BA0
_0222D350: .word 0x00002BD0
_0222D354: .word 0x00002BE0
	thumb_func_end ov74_0222D308


	thumb_func_start ov74_0222D358
ov74_0222D358: ; 0x0222D358
	push {r4, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	bl ov74_0222D448
	ldr r0, _0222D400 ; =0x00002BD0
	mov r1, #0x40
	add r0, r4, r0
	bl ov74_0222D1D4
	ldr r0, _0222D400 ; =0x00002BD0
	mov r1, #0x13
	add r0, r4, r0
	bl WaitingIcon_New
	ldr r1, _0222D404 ; =0x00003D50
	str r0, [r4, r1]
	ldr r1, _0222D408 ; =0x00002BA0
	ldr r0, [r4, r1]
	add r1, #0x20
	ldr r1, [r4, r1]
	bl SaveMysteryGift_HasAnyGift
	cmp r0, #1
	ldr r1, _0222D408 ; =0x00002BA0
	bne _0222D39A
	ldr r0, [r4, r1]
	add r1, #0x20
	ldr r1, [r4, r1]
	bl SaveMysteryGift_ReceiveGiftAndClearCardByIndex
	b _0222D3A4
_0222D39A:
	ldr r0, [r4, r1]
	add r1, #0x20
	ldr r1, [r4, r1]
	bl SaveMysteryGift_DeleteWonderCardByIndex
_0222D3A4:
	ldr r0, _0222D40C ; =0x00002BA4
	ldr r0, [r4, r0]
	bl SaveGameNormal
	ldr r0, _0222D404 ; =0x00003D50
	ldr r0, [r4, r0]
	bl sub_0200F450
	ldr r0, _0222D408 ; =0x00002BA0
	ldr r0, [r4, r0]
	bl SaveMysteryGift_HasAnyCard
	cmp r0, #0
	bne _0222D3C4
	mov r0, #0x1b
	pop {r4, pc}
_0222D3C4:
	mov r1, #0xaf
	lsl r1, r1, #6
	ldr r1, [r4, r1]
	add r0, r4, #0
	mov r2, #1
	bl ov74_0222DAF8
	mov r1, #0xaf
	lsl r1, r1, #6
	str r0, [r4, r1]
	add r1, #0x10
	add r0, r4, r1
	mov r1, #0x25
	bl ov74_0222D1D4
	ldr r3, _0222D410 ; =0x00002BE0
	add r0, r4, #0
	add r1, r4, r3
	add r3, #0x10
	ldr r3, [r4, r3]
	mov r2, #8
	bl ov74_0222D9E0
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov74_0222D824
	mov r0, #5
	pop {r4, pc}
	.balign 4, 0
_0222D400: .word 0x00002BD0
_0222D404: .word 0x00003D50
_0222D408: .word 0x00002BA0
_0222D40C: .word 0x00002BA4
_0222D410: .word 0x00002BE0
	thumb_func_end ov74_0222D358


	thumb_func_start ov74_0222D414
ov74_0222D414: ; 0x0222D414
	push {r4, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	bl ov74_0222D448
	ldr r0, _0222D440 ; =0x00002BD0
	mov r1, #0x25
	add r0, r4, r0
	bl ov74_0222D1D4
	ldr r3, _0222D444 ; =0x00002BE0
	add r0, r4, #0
	add r1, r4, r3
	add r3, #0x10
	ldr r3, [r4, r3]
	mov r2, #8
	bl ov74_0222D9E0
	mov r0, #5
	pop {r4, pc}
	nop
_0222D440: .word 0x00002BD0
_0222D444: .word 0x00002BE0
	thumb_func_end ov74_0222D414


	thumb_func_start ov74_0222D448
ov74_0222D448: ; 0x0222D448
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222D484 ; =0x00002BCC
	ldr r0, [r4, r0]
	bl ListMenuItems_Delete
	mov r1, #0
	ldr r0, _0222D484 ; =0x00002BCC
	add r2, r1, #0
	str r1, [r4, r0]
	sub r0, r0, #4
	ldr r0, [r4, r0]
	bl DestroyListMenu
	ldr r0, _0222D488 ; =0x00002BC8
	mov r1, #0
	str r1, [r4, r0]
	add r0, #0x18
	add r0, r4, r0
	bl ov74_0222D0EC
	ldr r0, _0222D48C ; =0x00002BE0
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222D48C ; =0x00002BE0
	add r0, r4, r0
	bl RemoveWindow
	pop {r4, pc}
	.balign 4, 0
_0222D484: .word 0x00002BCC
_0222D488: .word 0x00002BC8
_0222D48C: .word 0x00002BE0
	thumb_func_end ov74_0222D448


	thumb_func_start ov74_0222D490
ov74_0222D490: ; 0x0222D490
	mov r0, #1
	bx lr
	thumb_func_end ov74_0222D490


	thumb_func_start ov74_0222D494
ov74_0222D494: ; 0x0222D494
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	ldr r1, [r5]
	mov r0, #0x25
	add r4, r2, #0
	bl String_New
	mov r1, #0xaf
	lsl r1, r1, #6
	ldr r2, [r5, r1]
	sub r1, #0xc
	lsl r2, r2, #2
	add r2, r5, r2
	ldr r2, [r2, r1]
	mov r1, #0x41
	lsl r1, r1, #2
	add r1, r2, r1
	mov r2, #0x24
	add r6, r0, #0
	bl CopyU16ArrayToStringN
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r4, [sp, #8]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #1
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_0222D494


	thumb_func_start ov74_0222D4E4
ov74_0222D4E4: ; 0x0222D4E4
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0xaf
	lsl r0, r0, #6
	add r6, r1, #0
	ldr r1, [r4, r0]
	add r5, r2, #0
	lsl r2, r1, #2
	add r3, r4, r2
	add r2, r0, #0
	sub r2, #0xc
	ldr r3, [r3, r2]
	ldr r2, _0222D558 ; =0x00000152
	ldrb r2, [r3, r2]
	lsl r2, r2, #0x1c
	lsr r2, r2, #0x1f
	bne _0222D50C
	mov r2, #0x28
	b _0222D522
_0222D50C:
	sub r0, #0x20
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222D51C
	bl SaveMysteryGift_HasAnyGift
	cmp r0, #1
	bne _0222D520
_0222D51C:
	mov r2, #0x26
	b _0222D522
_0222D520:
	mov r2, #0x27
_0222D522:
	mov r1, #0x2a
	lsl r1, r1, #8
	ldr r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	ldr r3, [r4]
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r5, [sp, #8]
	add r0, r6, #0
	mov r1, #1
	add r2, r4, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	mov r0, #1
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_0222D558: .word 0x00000152
	thumb_func_end ov74_0222D4E4


	thumb_func_start ov74_0222D55C
ov74_0222D55C: ; 0x0222D55C
	push {r4, lr}
	sub sp, #0x18
	mov r1, #0xaf
	add r4, r0, #0
	lsl r1, r1, #6
	ldr r2, [r4, r1]
	sub r1, #0xc
	lsl r2, r2, #2
	add r2, r4, r2
	ldr r2, [r2, r1]
	mov r1, #0xd5
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	add r0, sp, #8
	bl RTC_ConvertDayToDate
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x2a
	lsl r0, r0, #8
	mov r2, #0x7d
	ldr r3, [sp, #8]
	lsl r2, r2, #4
	add r2, r3, r2
	ldr r0, [r4, r0]
	mov r1, #0
	mov r3, #4
	bl BufferIntegerAsString
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	ldr r2, [sp, #0xc]
	mov r1, #1
	bl BufferMonthNameAbbr
	mov r1, #2
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	ldr r2, [sp, #0x10]
	add r3, r1, #0
	bl BufferIntegerAsString
	mov r0, #1
	add sp, #0x18
	pop {r4, pc}
	thumb_func_end ov74_0222D55C


	thumb_func_start ov74_0222D5C4
ov74_0222D5C4: ; 0x0222D5C4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	mov r0, #0xfb
	mov r1, #0x55
	add r4, r2, #0
	bl String_New
	mov r1, #0xaf
	lsl r1, r1, #6
	ldr r2, [r5, r1]
	sub r1, #0xc
	lsl r2, r2, #2
	add r2, r5, r2
	ldr r2, [r2, r1]
	mov r1, #0x55
	lsl r1, r1, #2
	add r1, r2, r1
	mov r2, #0xfa
	add r6, r0, #0
	bl CopyU16ArrayToStringN
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r4, [sp, #8]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_0222D5C4


	thumb_func_start ov74_0222D614
ov74_0222D614: ; 0x0222D614
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r3, r0, #0
	mov r0, #0xaf
	lsl r0, r0, #6
	add r6, r1, #0
	ldr r1, [r3, r0]
	sub r0, #0xc
	lsl r1, r1, #2
	add r1, r3, r1
	ldr r1, [r1, r0]
	mov r0, #0xd2
	lsl r0, r0, #2
	add r5, r2, #0
	ldrb r2, [r1, r0]
	cmp r2, #0xff
	bne _0222D66C
	mov r1, #0x2a
	lsl r1, r1, #8
	ldr r0, [r3, r1]
	add r1, r1, #4
	ldr r1, [r3, r1]
	mov r2, #0x34
	mov r3, #0x55
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r5, [sp, #8]
	add r0, r6, #0
	mov r1, #1
	add r2, r4, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	add sp, #0x10
	mov r0, #0
	pop {r4, r5, r6, pc}
_0222D66C:
	cmp r2, #0
	beq _0222D68A
	mov r1, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r3, r0]
	mov r3, #3
	bl BufferIntegerAsString
	add sp, #0x10
	mov r0, #1
	pop {r4, r5, r6, pc}
_0222D68A:
	mov r0, #0
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end ov74_0222D614


	thumb_func_start ov74_0222D690
ov74_0222D690: ; 0x0222D690
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r5, r0, #0
	mov r0, #0
	add r7, r1, #0
	add r1, r0, #1
	ldr r0, _0222D764 ; =ov74_0223C2D0
	ldr r2, _0222D764 ; =ov74_0223C2D0
	ldr r0, [r0, #0x30]
	ldr r2, [r2, #0x34]
	str r0, [sp, #0x14]
	mov r0, #0xaf
	lsl r0, r0, #6
	str r2, [sp, #0x18]
	ldr r2, [r5, r0]
	sub r0, #0xc
	lsl r2, r2, #2
	add r2, r5, r2
	ldr r2, [r2, r0]
	mov r0, #0xd2
	lsl r0, r0, #2
	ldrb r0, [r2, r0]
	add r4, r1, #0
	add r6, sp, #0x14
	cmp r0, #0
	beq _0222D6D6
	ldr r0, _0222D764 ; =ov74_0223C2D0
	ldr r2, _0222D764 ; =ov74_0223C2D0
	ldr r0, [r0, #0x38]
	add r4, r1, #1
	lsl r1, r1, #3
	ldr r2, [r2, #0x3c]
	add r3, r6, r1
	str r0, [r6, r1]
	str r2, [r3, #4]
_0222D6D6:
	ldr r0, _0222D764 ; =ov74_0223C2D0
	ldr r2, _0222D764 ; =ov74_0223C2D0
	ldr r0, [r0, #0x40]
	lsl r1, r4, #3
	add r6, sp, #0x14
	str r0, [r6, r1]
	ldr r2, [r2, #0x44]
	add r3, r6, r1
	add r0, r4, #1
	lsl r1, r0, #3
	str r2, [r3, #4]
	ldr r0, _0222D764 ; =ov74_0223C2D0
	ldr r2, _0222D764 ; =ov74_0223C2D0
	ldr r0, [r0, #0x48]
	ldr r2, [r2, #0x4c]
	str r0, [r6, r1]
	add r3, r6, r1
	ldr r0, _0222D768 ; =0x00002B9C
	str r2, [r3, #4]
	ldr r6, [r5, r0]
	add r0, r7, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r7, #0
	bl RemoveWindow
	add r1, r4, #2
	mov r0, #4
	sub r0, r0, r1
	ldr r1, [r6, #8]
	lsl r0, r0, #1
	add r1, r1, r0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp]
	ldr r1, [r6, #0xc]
	mov r2, #2
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #4]
	ldr r1, [r6, #0x10]
	sub r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	ldr r0, _0222D76C ; =0x00002B98
	add r1, r7, #0
	ldr r0, [r5, r0]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, _0222D770 ; =0x000029FC
	ldr r3, [r6, #4]
	ldr r0, [r5, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	mov r0, #0
	str r0, [sp]
	add r0, r5, #0
	add r1, sp, #0x14
	add r2, r4, #2
	add r3, r7, #0
	bl ov74_0222D11C
	mov r0, #1
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222D764: .word ov74_0223C2D0
_0222D768: .word 0x00002B9C
_0222D76C: .word 0x00002B98
_0222D770: .word 0x000029FC
	thumb_func_end ov74_0222D690


	thumb_func_start ov74_0222D774
ov74_0222D774: ; 0x0222D774
	push {r3, lr}
	add r3, r1, #0
	mov r1, #1
	str r1, [sp]
	ldr r1, _0222D788 ; =ov74_0223C2D0
	mov r2, #2
	bl ov74_0222D11C
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_0222D788: .word ov74_0223C2D0
	thumb_func_end ov74_0222D774


	thumb_func_start ov74_0222D78C
ov74_0222D78C: ; 0x0222D78C
	push {r3, lr}
	add r3, r1, #0
	mov r1, #0
	str r1, [sp]
	ldr r1, _0222D7A0 ; =ov74_0223C2F0
	mov r2, #2
	bl ov74_0222D11C
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_0222D7A0: .word ov74_0223C2F0
	thumb_func_end ov74_0222D78C


	thumb_func_start ov74_0222D7A4
ov74_0222D7A4: ; 0x0222D7A4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _0222D7C8 ; =0x00002BD0
	add r4, r1, #0
	add r0, r5, r0
	mov r1, #2
	bl ov74_0222D1D4
	mov r0, #0
	str r0, [sp]
	ldr r1, _0222D7CC ; =ov74_0223C2E0
	add r0, r5, #0
	mov r2, #2
	add r3, r4, #0
	bl ov74_0222D11C
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222D7C8: .word 0x00002BD0
_0222D7CC: .word ov74_0223C2E0
	thumb_func_end ov74_0222D7A4


	thumb_func_start ov74_0222D7D0
ov74_0222D7D0: ; 0x0222D7D0
	push {r3, lr}
	sub sp, #8
	mov r3, #1
	str r3, [sp]
	mov r1, #0x2a
	str r3, [sp, #4]
	lsl r1, r1, #8
	ldr r0, [r0, r1]
	mov r1, #0
	add r2, r1, #0
	bl BufferIntegerAsString
	mov r0, #1
	add sp, #8
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_0222D7D0


	thumb_func_start ov74_0222D7F0
ov74_0222D7F0: ; 0x0222D7F0
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x55
	str r0, [sp, #8]
	add r6, r2, #0
	mov r0, #0
	add r4, r3, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	cmp r4, #0
	beq _0222D818
	mov r0, #0x1c
	str r0, [r4]
_0222D818:
	mov r0, #0xb1
	lsl r0, r0, #6
	str r6, [r5, r0]
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov74_0222D7F0


	thumb_func_start ov74_0222D824
ov74_0222D824: ; 0x0222D824
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r5, r0, #0
	ldr r3, [r5]
	str r2, [sp, #0x14]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	ldr r4, _0222D9C8 ; =ov74_0223C340
	bl NewMsgDataFromNarc
	ldr r1, _0222D9CC ; =0x00002A04
	str r0, [r5, r1]
	ldr r0, [r5]
	bl MessageFormat_New
	mov r1, #0x2a
	lsl r1, r1, #8
	str r0, [r5, r1]
	ldr r1, _0222D9D0 ; =0x00002BC4
	ldr r0, [sp, #0x14]
	str r0, [r5, r1]
	ldr r1, [sp, #0x14]
	add r0, r5, #0
	bl ov74_0222DB70
	mov r0, #0
	str r0, [sp, #0x30]
	ldr r0, _0222D9D4 ; =0x00002A08
	add r7, r4, #0
	str r5, [sp, #0x1c]
	add r6, r5, r0
_0222D864:
	ldr r1, [r7]
	ldr r0, [sp, #0x14]
	cmp r0, r1
	beq _0222D886
	cmp r1, #2
	beq _0222D886
	ldr r1, [sp, #0x1c]
	ldr r0, _0222D9D4 ; =0x00002A08
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _0222D886
	add r0, r6, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r6, #0
	bl RemoveWindow
_0222D886:
	ldr r0, [sp, #0x1c]
	add r7, #0x30
	add r0, #0x10
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x30]
	add r6, #0x10
	add r0, r0, #1
	str r0, [sp, #0x30]
	cmp r0, #0x13
	blo _0222D864
	mov r0, #0x31
	str r0, [sp, #0x2c]
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, _0222D9D4 ; =0x00002A08
	str r5, [sp, #0x24]
	str r5, [sp, #0x20]
	add r6, r5, r0
_0222D8AA:
	ldr r1, [r4]
	ldr r0, [sp, #0x14]
	cmp r0, r1
	bne _0222D98A
	ldr r1, [sp, #0x24]
	ldr r0, _0222D9D4 ; =0x00002A08
	ldr r0, [r1, r0]
	cmp r0, #0
	bne _0222D8FA
	ldr r2, [sp, #0x2c]
	ldr r1, [sp, #0x20]
	ldr r0, _0222D9D8 ; =0x00002B48
	str r2, [r1, r0]
	ldr r0, [r4, #8]
	add r1, r6, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r4, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	add r0, r2, #0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, _0222D9DC ; =0x000029FC
	ldr r3, [r4, #4]
	ldr r0, [r5, r0]
	lsl r3, r3, #0x18
	mov r2, #0
	lsr r3, r3, #0x18
	bl AddWindowParameterized
_0222D8FA:
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x1c]
	lsl r0, r0, #0x18
	lsl r1, r1, #0x18
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	bl GetFontAttribute
	add r1, r0, #0
	add r0, r6, #0
	bl FillWindowPixelBuffer
	ldr r0, [r4, #0x18]
	ldr r3, [r4, #0x24]
	str r0, [sp, #0x28]
	ldr r2, [sp, #0x28]
	add r0, r5, #0
	add r1, r6, #0
	blx r3
	cmp r0, #1
	bne _0222D976
	ldr r2, [r4, #0x20]
	cmp r2, #0
	beq _0222D976
	mov r0, #0x2a
	ldr r1, _0222D9CC ; =0x00002A04
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r3, [r5]
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	mov r0, #0
	ldr r3, [r4, #0x28]
	mvn r0, r0
	cmp r3, r0
	bne _0222D956
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x14]
	add r1, r7, #0
	mov r2, #0
	lsl r3, r3, #3
	bl FontID_String_GetCenterAlignmentX
	add r3, r0, #0
_0222D956:
	ldr r0, [r4, #0x2c]
	add r2, r7, #0
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r1, [r4, #0x14]
	add r0, r6, #0
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
_0222D976:
	add r0, r6, #0
	bl CopyWindowToVram
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x10]
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #0x2c]
	add r0, r0, r2
	str r0, [sp, #0x2c]
_0222D98A:
	ldr r0, [sp, #0x24]
	add r4, #0x30
	add r0, #0x10
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	add r6, #0x10
	add r0, r0, #4
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #0x13
	blo _0222D8AA
	ldr r0, _0222D9CC ; =0x00002A04
	ldr r0, [r5, r0]
	bl DestroyMsgData
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	bl MessageFormat_Delete
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bne _0222D9C2
	add r0, r5, #0
	bl ov74_0222DCD4
_0222D9C2:
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	nop
_0222D9C8: .word ov74_0223C340
_0222D9CC: .word 0x00002A04
_0222D9D0: .word 0x00002BC4
_0222D9D4: .word 0x00002A08
_0222D9D8: .word 0x00002B48
_0222D9DC: .word 0x000029FC
	thumb_func_end ov74_0222D824


	thumb_func_start ov74_0222D9E0
ov74_0222D9E0: ; 0x0222D9E0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r7, r3, #0
	mov r3, #0x30
	ldr r0, _0222DAE0 ; =ov74_0223C340
	mul r3, r2
	add r6, r1, #0
	add r4, r0, r3
	ldr r0, [r6]
	cmp r0, #0
	bne _0222DA2A
	ldr r0, [r4, #8]
	mov r2, #2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r4, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	lsl r0, r7, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, _0222DAE4 ; =0x000029FC
	ldr r3, [r4, #4]
	ldr r0, [r5, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl AddWindowParameterized
_0222DA2A:
	ldr r1, [r4, #0x1c]
	add r0, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl FillWindowPixelBuffer
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0222DA58
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x55
	bl NewMsgDataFromNarc
	ldr r1, _0222DAE8 ; =0x00002A04
	str r0, [r5, r1]
	mov r0, #0x55
	bl MessageFormat_New
	mov r1, #0x2a
	lsl r1, r1, #8
	str r0, [r5, r1]
_0222DA58:
	ldr r0, _0222DAEC ; =0x00002B98
	ldr r2, _0222DAF0 ; =0x00010200
	str r7, [r5, r0]
	add r0, r0, #4
	str r4, [r5, r0]
	ldr r3, [r4, #0x24]
	add r0, r5, #0
	add r1, r6, #0
	blx r3
	ldr r2, [r4, #0x20]
	cmp r2, #0
	beq _0222DAB2
	mov r1, #0x2a
	lsl r1, r1, #8
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r3, #0x55
	bl ReadMsgData_ExpandPlaceholders
	str r0, [sp, #0x14]
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [r4, #0x18]
	ldr r2, [sp, #0x14]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	ldr r1, [r4, #0x14]
	add r0, r6, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x14]
	bl String_Delete
	ldr r0, _0222DAE8 ; =0x00002A04
	ldr r0, [r5, r0]
	bl DestroyMsgData
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	bl MessageFormat_Delete
_0222DAB2:
	ldr r0, _0222DAF4 ; =0x00002BD0
	add r0, r5, r0
	cmp r6, r0
	bne _0222DAC8
	add r0, r6, #0
	mov r1, #0
	mov r2, #0x13
	mov r3, #0xa
	bl DrawFrameAndWindow2
	b _0222DAD4
_0222DAC8:
	add r0, r6, #0
	mov r1, #0
	mov r2, #0xa
	mov r3, #0xe
	bl DrawFrameAndWindow1
_0222DAD4:
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x10]
	mul r0, r1
	add r0, r7, r0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222DAE0: .word ov74_0223C340
_0222DAE4: .word 0x000029FC
_0222DAE8: .word 0x00002A04
_0222DAEC: .word 0x00002B98
_0222DAF0: .word 0x00010200
_0222DAF4: .word 0x00002BD0
	thumb_func_end ov74_0222D9E0


	thumb_func_start ov74_0222DAF8
ov74_0222DAF8: ; 0x0222DAF8
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	add r7, r4, #0
_0222DB02:
	add r4, r4, r6
	cmp r4, #3
	bne _0222DB0A
	mov r4, #0
_0222DB0A:
	mov r0, #0
	mvn r0, r0
	cmp r4, r0
	bne _0222DB14
	mov r4, #2
_0222DB14:
	cmp r7, r4
	beq _0222DB26
	ldr r0, _0222DB2C ; =0x00002BA0
	add r1, r4, #0
	ldr r0, [r5, r0]
	bl SaveMysteryGift_CardTagIsValid
	cmp r0, #0
	beq _0222DB02
_0222DB26:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222DB2C: .word 0x00002BA0
	thumb_func_end ov74_0222DAF8


	thumb_func_start ov74_0222DB30
ov74_0222DB30: ; 0x0222DB30
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r2, #0
	mov r2, #1
	add r5, r0, #0
	str r2, [sp]
	add r6, r3, #0
	ldr r3, [r5]
	mov r0, #0x71
	bl GfGfxLoader_LoadFromNarc
	add r1, sp, #4
	add r7, r0, #0
	bl NNS_G2dGetUnpackedScreenData
	ldr r0, _0222DB6C ; =0x000029FC
	ldr r2, [sp, #4]
	lsl r1, r4, #0x18
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	add r2, #0xc
	add r3, r6, #0
	bl BG_LoadScreenTilemapData
	add r0, r7, #0
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222DB6C: .word 0x000029FC
	thumb_func_end ov74_0222DB30


	thumb_func_start ov74_0222DB70
ov74_0222DB70: ; 0x0222DB70
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #1
	lsl r0, r0, #8
	str r0, [sp]
	ldr r0, [r5]
	mov r2, #0
	add r4, r1, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #3
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r5]
	ldr r2, _0222DC5C ; =0x000029FC
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r0, #0x71
	mov r1, #6
	bl GfGfxLoader_LoadCharData
	cmp r4, #0
	beq _0222DBB6
	cmp r4, #1
	beq _0222DBD6
	b _0222DBF4
_0222DBB6:
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r5]
	ldr r2, _0222DC5C ; =0x000029FC
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r0, #0x71
	mov r1, #4
	bl GfGfxLoader_LoadScrnData
	b _0222DBF4
_0222DBD6:
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r5]
	ldr r2, _0222DC5C ; =0x000029FC
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r0, #0x71
	mov r1, #5
	bl GfGfxLoader_LoadScrnData
_0222DBF4:
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r5]
	mov r1, #0
	str r0, [sp, #4]
	mov r0, #0x71
	add r3, r0, #0
	add r2, r1, #0
	add r3, #0xef
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	ldr r0, [r5]
	ldr r2, _0222DC5C ; =0x000029FC
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r0, #0x71
	mov r3, #3
	bl GfGfxLoader_LoadCharData
	mov r2, #3
	add r0, r5, #0
	mov r1, #2
	lsl r3, r2, #9
	bl ov74_0222DB30
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	ldr r0, _0222DC5C ; =0x000029FC
	mov r2, #0
	ldr r0, [r5, r0]
	mov r1, #3
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	ldr r0, _0222DC5C ; =0x000029FC
	mov r1, #3
	ldr r0, [r5, r0]
	bl BgCommitTilemapBufferToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222DC5C: .word 0x000029FC
	thumb_func_end ov74_0222DB70


	thumb_func_start ov74_0222DC60
ov74_0222DC60: ; 0x0222DC60
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r1, #0
	add r6, r2, #0
	bl OverlayManager_GetData
	ldr r1, _0222DCC8 ; =0x00002BC8
	ldr r0, [r0, r1]
	bl ListMenu_ProcessInput
	add r4, r0, #0
	mov r0, #1
	mvn r0, r0
	cmp r4, r0
	beq _0222DC86
	add r0, r0, #1
	cmp r4, r0
	beq _0222DCC4
	b _0222DCA0
_0222DC86:
	ldr r0, _0222DCCC ; =SEQ_SE_DP_SELECT
	bl PlaySE
	cmp r6, #0
	beq _0222DCC4
	add r0, r7, #0
	blx r6
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222DCC4
	str r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
_0222DCA0:
	ldr r0, _0222DCCC ; =SEQ_SE_DP_SELECT
	bl PlaySE
	cmp r4, #0
	beq _0222DCC4
	cmp r4, #0x1f
	bhs _0222DCB2
	str r4, [r5]
	pop {r3, r4, r5, r6, r7, pc}
_0222DCB2:
	ldr r0, _0222DCD0 ; =ov74_0223D0BC
	str r4, [r0]
	add r0, r7, #0
	blx r4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222DCC4
	str r0, [r5]
_0222DCC4:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222DCC8: .word 0x00002BC8
_0222DCCC: .word SEQ_SE_DP_SELECT
_0222DCD0: .word ov74_0223D0BC
	thumb_func_end ov74_0222DC60


	thumb_func_start ov74_0222DCD4
ov74_0222DCD4: ; 0x0222DCD4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	ldr r1, _0222DDF0 ; =0x00002DCC
	add r6, r0, #0
	ldr r0, [r6, r1]
	cmp r0, #0
	bne _0222DD34
	add r0, r1, #4
	ldr r0, [r6, r0]
	cmp r0, #0
	bne _0222DD34
	add r1, #8
	ldr r0, [r6, r1]
	cmp r0, #0
	bne _0222DD34
	bl ov74_0223567C
	cmp r0, #1
	bne _0222DD00
	add r0, r6, #0
	bl ov74_0222D024
_0222DD00:
	bl ov74_0223563C
	bl ov74_02235690
	mov r0, #0x1c
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0x1e
	mov r2, #0x1b
	mov r3, #0x1d
	bl ov74_02235728
	bl sub_02074490
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, [r6]
	mov r2, #1
	str r0, [sp, #4]
	mov r0, #0x14
	mov r3, #0x60
	bl GfGfxLoader_GXLoadPal
_0222DD34:
	mov r0, #0xb2
	mov r4, #0
	str r0, [sp, #0x10]
	str r4, [sp, #0xc]
	add r5, r6, #0
	mov r7, #0x64
_0222DD40:
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	lsl r0, r0, #2
	add r1, r6, r0
	ldr r0, _0222DDF4 ; =0x00002BB4
	ldr r0, [r1, r0]
	add r1, r0, r4
	ldr r0, _0222DDF8 ; =0x0000034A
	ldrh r0, [r1, r0]
	str r0, [sp, #8]
	cmp r0, #0
	bne _0222DD6A
	ldr r0, _0222DDF0 ; =0x00002DCC
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0222DDD4
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0222DDD4
_0222DD6A:
	ldr r0, [sp, #0xc]
	ldr r1, _0222DDF0 ; =0x00002DCC
	add r0, #0xa
	str r0, [sp]
	ldr r1, [r5, r1]
	ldr r2, [sp, #0x10]
	mov r0, #0
	mov r3, #0x10
	bl ov74_02235930
	ldr r1, _0222DDF0 ; =0x00002DCC
	str r0, [r5, r1]
	mov r1, #0
	ldr r0, [sp, #8]
	add r2, r1, #0
	bl GetMonIconNaixEx
	add r1, r0, #0
	ldr r0, [r6]
	mov r2, #0
	str r0, [sp]
	mov r0, #0x14
	add r3, sp, #0x18
	bl GfGfxLoader_GetCharData
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	mov r1, #2
	ldr r0, [r0, #0x14]
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp, #0x18]
	mov r2, #2
	ldr r0, [r0, #0x14]
	lsl r1, r7, #5
	lsl r2, r2, #8
	bl GX_LoadOBJ
	mov r1, #0
	ldr r0, [sp, #8]
	add r2, r1, #0
	bl GetMonIconPaletteEx
	add r1, r0, #0
	ldr r0, _0222DDF0 ; =0x00002DCC
	add r1, r1, #3
	ldr r0, [r5, r0]
	bl Sprite_SetPaletteOverride
	ldr r0, [sp, #0x14]
	bl Heap_Free
_0222DDD4:
	ldr r0, [sp, #0xc]
	add r4, r4, #2
	add r0, r0, #1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r5, r5, #4
	add r0, #0x19
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r7, #0x10
	cmp r0, #3
	blt _0222DD40
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0222DDF0: .word 0x00002DCC
_0222DDF4: .word 0x00002BB4
_0222DDF8: .word 0x0000034A
	thumb_func_end ov74_0222DCD4


	thumb_func_start ov74_0222DDFC
ov74_0222DDFC: ; 0x0222DDFC
	push {r4, lr}
	add r4, r0, #0
	mov r0, #3
	mov r1, #0x55
	lsl r2, r0, #0x10
	bl Heap_Create
	ldr r1, _0222DE60 ; =0x00003D54
	add r0, r4, #0
	mov r2, #0x55
	bl OverlayManager_CreateAndGetData
	ldr r2, _0222DE60 ; =0x00003D54
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x55
	bl BgConfig_Alloc
	ldr r1, _0222DE64 ; =0x000029FC
	str r0, [r4, r1]
	mov r0, #0x55
	str r0, [r4]
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FBF4
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	mov r0, #0xaf
	mov r1, #2
	lsl r0, r0, #6
	str r1, [r4, r0]
	mov r1, #1
	add r0, #0x7c
	str r1, [r4, r0]
	mov r0, #0x55
	bl ov74_022352A0
	mov r2, #0x57
	mov r0, #0
	mov r1, #0x59
	lsl r2, r2, #4
	bl Heap_Create
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
_0222DE60: .word 0x00003D54
_0222DE64: .word 0x000029FC
	thumb_func_end ov74_0222DDFC


	thumb_func_start ov74_0222DE68
ov74_0222DE68: ; 0x0222DE68
	push {r4, lr}
	add r4, r1, #0
	bl sub_02014AA0
	mov r0, #3
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	bl sub_02014A60
	ldr r1, _0222DE88 ; =0x04000010
	mov r2, #8
	mov r3, #1
	bl sub_02014AB0
	pop {r4, pc}
	nop
_0222DE88: .word 0x04000010
	thumb_func_end ov74_0222DE68


	thumb_func_start ov74_0222DE8C
ov74_0222DE8C: ; 0x0222DE8C
	push {r3, r4, r5, lr}
	ldr r4, _0222DEE0 ; =0x00003130
	ldr r5, _0222DEE4 ; =0x00000C14
	add r4, r0, r4
	add r0, r5, #0
	str r1, [r4, r5]
	sub r0, #0xc
	str r2, [r4, r0]
	add r0, r5, #0
	sub r0, #8
	sub r5, #0x14
	str r3, [r4, r0]
	ldr r0, [r4, r5]
	cmp r0, #0
	bne _0222DEBE
	mov r2, #6
	lsl r2, r2, #8
	mov r0, #0x55
	add r1, r4, #0
	add r2, r4, r2
	bl sub_02014A08
	mov r1, #3
	lsl r1, r1, #0xa
	str r0, [r4, r1]
_0222DEBE:
	ldr r0, _0222DEE8 ; =0x00000C04
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222DED6
	mov r2, #1
	ldr r0, _0222DEEC ; =ov74_0222DE68
	add r1, r4, #0
	lsl r2, r2, #0xa
	bl SysTask_CreateOnVBlankQueue
	ldr r1, _0222DEE8 ; =0x00000C04
	str r0, [r4, r1]
_0222DED6:
	mov r0, #0xc1
	mov r1, #1
	lsl r0, r0, #4
	str r1, [r4, r0]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222DEE0: .word 0x00003130
_0222DEE4: .word 0x00000C14
_0222DEE8: .word 0x00000C04
_0222DEEC: .word ov74_0222DE68
	thumb_func_end ov74_0222DE8C


	thumb_func_start ov74_0222DEF0
ov74_0222DEF0: ; 0x0222DEF0
	push {r4, lr}
	ldr r1, _0222DF24 ; =0x00003130
	add r4, r0, r1
	mov r0, #3
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222DF04
	bl sub_02014A38
_0222DF04:
	ldr r0, _0222DF28 ; =0x00000C04
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222DF10
	bl SysTask_Destroy
_0222DF10:
	mov r0, #3
	mov r1, #0
	lsl r0, r0, #0xa
	str r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
	bl sub_02014AA0
	pop {r4, pc}
	nop
_0222DF24: .word 0x00003130
_0222DF28: .word 0x00000C04
	thumb_func_end ov74_0222DEF0


	thumb_func_start ov74_0222DF2C
ov74_0222DF2C: ; 0x0222DF2C
	push {r3, r4, r5, r6, r7, lr}
	ldr r1, _0222E034 ; =0x00003130
	mov r5, #0x15
	add r4, r0, r1
	mov r0, #0xc1
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	lsl r5, r5, #0xe
	cmp r1, #0
	bne _0222DF44
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0222DF44:
	add r1, r0, #4
	ldr r1, [r4, r1]
	cmp r1, #1
	bne _0222DF92
	add r1, r0, #0
	sub r1, #8
	ldr r2, [r4, r1]
	sub r1, r0, #4
	ldr r1, [r4, r1]
	add r2, r2, r1
	add r1, r0, #0
	sub r1, #8
	str r2, [r4, r1]
	sub r1, r0, #4
	ldr r2, [r4, r1]
	add r1, r2, #0
	add r2, r2, r1
	sub r1, r0, #4
	str r2, [r4, r1]
	add r1, r0, #0
	sub r1, #8
	ldr r2, [r4, r1]
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	asr r2, r1, #0xc
	mov r1, #0xfa
	lsl r1, r1, #2
	cmp r2, r1
	ble _0222DFCC
	mov r2, #0
	add r1, r0, #0
	str r2, [r4, r0]
	sub r1, #8
	str r2, [r4, r1]
	sub r0, r0, #4
	mov r5, #0xa8
	str r2, [r4, r0]
	b _0222DFCC
_0222DF92:
	add r1, r0, #0
	sub r1, #8
	ldr r2, [r4, r1]
	sub r1, r0, #4
	ldr r1, [r4, r1]
	sub r2, r2, r1
	add r1, r0, #0
	sub r1, #8
	str r2, [r4, r1]
	sub r1, r0, #4
	ldr r2, [r4, r1]
	lsr r1, r2, #0x1f
	add r1, r2, r1
	asr r2, r1, #1
	sub r1, r0, #4
	str r2, [r4, r1]
	mov r2, #1
	ldr r1, [r4, r1]
	lsl r2, r2, #0xa
	cmp r1, r2
	bge _0222DFCC
	mov r1, #0
	lsl r3, r2, #2
	add r2, r0, #0
	str r1, [r4, r0]
	sub r2, #8
	str r3, [r4, r2]
	sub r0, r0, #4
	str r1, [r4, r0]
_0222DFCC:
	mov r0, #3
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	bl sub_02014A4C
	add r2, r0, #0
	mov r0, #0x54
	add r3, r0, #0
	add r3, #0xfc
_0222DFDE:
	asr r1, r5, #0xb
	lsr r1, r1, #0x14
	add r1, r5, r1
	asr r1, r1, #0xc
	bpl _0222DFEA
	mov r1, #0
_0222DFEA:
	cmp r1, #0xa8
	ble _0222DFF0
	mov r1, #0xa8
_0222DFF0:
	lsl r6, r3, #1
	add r7, r2, r6
	sub r6, r1, r0
	strh r6, [r7, #6]
	ldrh r6, [r7, #6]
	sub r1, r0, r1
	add r3, r3, #4
	strh r6, [r7, #2]
	mov r6, #0xa8
	sub r6, r6, r0
	lsl r6, r6, #3
	add r6, r2, r6
	strh r1, [r6, #6]
	ldrh r1, [r6, #6]
	add r0, r0, #1
	strh r1, [r6, #2]
	ldr r1, _0222E038 ; =0x00000C08
	ldr r1, [r4, r1]
	add r5, r5, r1
	cmp r0, #0xa8
	blt _0222DFDE
	mov r1, #6
	add r0, r2, #0
	lsl r1, r1, #8
	bl DC_FlushRange
	mov r0, #3
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	bl sub_02014A8C
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222E034: .word 0x00003130
_0222E038: .word 0x00000C08
	thumb_func_end ov74_0222DF2C


	thumb_func_start ov74_0222E03C
ov74_0222E03C: ; 0x0222E03C
	push {r4, lr}
	add r4, r0, #0
	bl ov74_022360B0
	sub r0, r0, #2
	cmp r0, #1
	bhi _0222E056
	ldr r0, _0222E058 ; =SEQ_SE_DP_SAVE
	bl PlaySE
	ldr r0, _0222E05C ; =0x00003D48
	mov r1, #0
	str r1, [r4, r0]
_0222E056:
	pop {r4, pc}
	.balign 4, 0
_0222E058: .word SEQ_SE_DP_SAVE
_0222E05C: .word 0x00003D48
	thumb_func_end ov74_0222E03C


	thumb_func_start ov74_0222E060
ov74_0222E060: ; 0x0222E060
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	cmp r0, #3
	blt _0222E072
	bl GF_AssertFail
_0222E072:
	mov r0, #0x1b
	bl SaveSubstruct_AssertCRC
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r1, [r4, r0]
	sub r0, #0xc
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r2, [r1, r0]
	mov r0, #0x35
	lsl r0, r0, #4
	ldrb r1, [r2, r0]
	cmp r1, #0xff
	beq _0222E094
	add r1, r1, #1
	strb r1, [r2, r0]
_0222E094:
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r1, [r4, r0]
	sub r0, #0xc
	lsl r1, r1, #2
	add r1, r4, r1
	ldr r2, [r1, r0]
	mov r0, #0xd2
	lsl r0, r0, #2
	ldrb r1, [r2, r0]
	cmp r1, #0xff
	beq _0222E0B0
	sub r1, r1, #1
	strb r1, [r2, r0]
_0222E0B0:
	mov r0, #0x1b
	bl SaveSubstruct_UpdateCRC
	ldr r0, _0222E0C8 ; =0x00002BA4
	ldr r0, [r4, r0]
	bl ov74_022360A0
	ldr r1, _0222E0CC ; =ov74_0222E03C
	ldr r0, _0222E0D0 ; =0x00003D48
	str r1, [r4, r0]
	pop {r4, pc}
	nop
_0222E0C8: .word 0x00002BA4
_0222E0CC: .word ov74_0222E03C
_0222E0D0: .word 0x00003D48
	thumb_func_end ov74_0222E060


	thumb_func_start ov74_0222E0D4
ov74_0222E0D4: ; 0x0222E0D4
	push {r3, r4, r5, r6, r7, lr}
	add r7, r2, #0
	ldr r2, _0222E1D4 ; =gSystem
	add r6, r1, #0
	ldr r3, [r2, #0x48]
	ldr r1, _0222E1D8 ; =0x00003D4C
	add r5, r0, #0
	mov r2, #0x10
	ldr r0, [r5, r1]
	tst r2, r3
	beq _0222E0F2
	cmp r0, #1
	beq _0222E0F2
	mov r2, #1
	str r2, [r5, r1]
_0222E0F2:
	ldr r1, _0222E1D4 ; =gSystem
	ldr r2, [r1, #0x48]
	mov r1, #0x20
	tst r1, r2
	beq _0222E108
	ldr r1, _0222E1D8 ; =0x00003D4C
	ldr r2, [r5, r1]
	cmp r2, #0
	beq _0222E108
	mov r2, #0
	str r2, [r5, r1]
_0222E108:
	ldr r1, _0222E1D8 ; =0x00003D4C
	ldr r1, [r5, r1]
	cmp r0, r1
	beq _0222E138
	cmp r1, #0
	bne _0222E118
	mov r1, #1
	b _0222E11A
_0222E118:
	mov r1, #0
_0222E11A:
	ldr r0, _0222E1DC ; =0x00002DC4
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _0222E1D8 ; =0x00003D4C
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0222E12E
	mov r1, #1
	b _0222E130
_0222E12E:
	mov r1, #0
_0222E130:
	ldr r0, _0222E1E0 ; =0x00002DC8
	ldr r0, [r5, r0]
	bl Sprite_SetAnimCtrlSeq
_0222E138:
	ldr r0, _0222E1D4 ; =gSystem
	mov r4, #0
	ldr r1, [r0, #0x48]
	mov r0, #2
	add r2, r1, #0
	tst r2, r0
	beq _0222E14A
	add r4, r0, #0
	b _0222E17A
_0222E14A:
	mov r0, #1
	and r1, r0
	beq _0222E160
	cmp r6, #0
	beq _0222E160
	ldr r2, _0222E1D8 ; =0x00003D4C
	ldr r2, [r5, r2]
	cmp r2, #0
	bne _0222E160
	add r4, r0, #0
	b _0222E17A
_0222E160:
	cmp r1, #0
	beq _0222E170
	ldr r0, _0222E1D8 ; =0x00003D4C
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _0222E170
	mov r4, #2
	b _0222E17A
_0222E170:
	cmp r1, #0
	beq _0222E17A
	cmp r6, #0
	bne _0222E17A
	mov r4, #3
_0222E17A:
	cmp r4, #1
	bne _0222E1B2
	ldr r0, _0222E1E4 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #0xab
	bl sub_02037AC0
	mov r3, #0xa
	ldr r1, _0222E1E8 ; =0x00002C34
	mov r0, #1
	str r0, [r5, r1]
	mov r0, #0x16
	sub r1, #0x64
	str r0, [r7]
	add r0, r5, #0
	add r1, r5, r1
	mov r2, #0x11
	lsl r3, r3, #6
	bl ov74_0222D9E0
	ldr r0, _0222E1EC ; =0x00002BD0
	mov r1, #0x13
	add r0, r5, r0
	bl WaitingIcon_New
	ldr r1, _0222E1F0 ; =0x00003D50
	str r0, [r5, r1]
_0222E1B2:
	cmp r4, #2
	bne _0222E1C6
	ldr r0, _0222E1E4 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r0, r5, #0
	add r1, r7, #0
	mov r2, #0x14
	bl ov74_0222EB28
_0222E1C6:
	cmp r4, #3
	bne _0222E1D0
	ldr r0, _0222E1E4 ; =SEQ_SE_DP_SELECT
	bl PlaySE
_0222E1D0:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222E1D4: .word gSystem
_0222E1D8: .word 0x00003D4C
_0222E1DC: .word 0x00002DC4
_0222E1E0: .word 0x00002DC8
_0222E1E4: .word SEQ_SE_DP_SELECT
_0222E1E8: .word 0x00002C34
_0222E1EC: .word 0x00002BD0
_0222E1F0: .word 0x00003D50
	thumb_func_end ov74_0222E0D4


	thumb_func_start ov74_0222E1F4
ov74_0222E1F4: ; 0x0222E1F4
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r1, #0
	add r6, r0, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #0x1e
	bls _0222E20A
	b _0222E79C
_0222E20A:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0222E216: ; jump table
	.short _0222E254 - _0222E216 - 2 ; case 0
	.short _0222E2C2 - _0222E216 - 2 ; case 1
	.short _0222E2D4 - _0222E216 - 2 ; case 2
	.short _0222E34A - _0222E216 - 2 ; case 3
	.short _0222E3C8 - _0222E216 - 2 ; case 4
	.short _0222E3F0 - _0222E216 - 2 ; case 5
	.short _0222E410 - _0222E216 - 2 ; case 6
	.short _0222E444 - _0222E216 - 2 ; case 7
	.short _0222E468 - _0222E216 - 2 ; case 8
	.short _0222E48E - _0222E216 - 2 ; case 9
	.short _0222E4BA - _0222E216 - 2 ; case 10
	.short _0222E4F4 - _0222E216 - 2 ; case 11
	.short _0222E518 - _0222E216 - 2 ; case 12
	.short _0222E744 - _0222E216 - 2 ; case 13
	.short _0222E524 - _0222E216 - 2 ; case 14
	.short _0222E530 - _0222E216 - 2 ; case 15
	.short _0222E540 - _0222E216 - 2 ; case 16
	.short _0222E54C - _0222E216 - 2 ; case 17
	.short _0222E58E - _0222E216 - 2 ; case 18
	.short _0222E5E8 - _0222E216 - 2 ; case 19
	.short _0222E646 - _0222E216 - 2 ; case 20
	.short _0222E652 - _0222E216 - 2 ; case 21
	.short _0222E6A2 - _0222E216 - 2 ; case 22
	.short _0222E68E - _0222E216 - 2 ; case 23
	.short _0222E6D6 - _0222E216 - 2 ; case 24
	.short _0222E6F2 - _0222E216 - 2 ; case 25
	.short _0222E734 - _0222E216 - 2 ; case 26
	.short _0222E76E - _0222E216 - 2 ; case 27
	.short _0222E77A - _0222E216 - 2 ; case 28
	.short _0222E78C - _0222E216 - 2 ; case 29
	.short _0222E79C - _0222E216 - 2 ; case 30
_0222E254:
	add r0, r6, #0
	bl OverlayManager_GetArgs
	ldr r1, [r0, #8]
	ldr r0, _0222E5A4 ; =0x00002BA4
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	bl Save_MysteryGift_Get
	ldr r1, _0222E5A8 ; =0x00002BA0
	str r0, [r4, r1]
	add r0, r1, #4
	ldr r0, [r4, r0]
	bl Save_PlayerData_GetOptionsAddr
	ldr r1, _0222E5AC ; =0x00002BA8
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	bl Options_GetFrame
	ldr r1, _0222E5B0 ; =0x00002BAC
	str r0, [r4, r1]
	sub r1, #0xc
	ldr r0, [r4, r1]
	mov r1, #0
	bl SaveMysteryGift_CardGetByIdx
	ldr r1, _0222E5B4 ; =0x00002BB4
	str r0, [r4, r1]
	sub r1, #0x14
	ldr r0, [r4, r1]
	mov r1, #1
	bl SaveMysteryGift_CardGetByIdx
	ldr r1, _0222E5B8 ; =0x00002BB8
	str r0, [r4, r1]
	sub r1, #0x18
	ldr r0, [r4, r1]
	mov r1, #2
	bl SaveMysteryGift_CardGetByIdx
	ldr r1, _0222E5BC ; =0x00002BBC
	mov r2, #1
	str r0, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov74_0222DAF8
	mov r1, #0xaf
	lsl r1, r1, #6
	str r0, [r4, r1]
	mov r0, #1
	str r0, [r5]
	b _0222E79C
_0222E2C2:
	bl ov74_0222FCA4
	ldr r0, _0222E5C0 ; =0x000029FC
	ldr r0, [r4, r0]
	bl ov74_0222FCC4
	mov r0, #2
	str r0, [r5]
	b _0222E79C
_0222E2D4:
	bl ResetAllTextPrinters
	add r0, r4, #0
	mov r1, #0
	bl ov74_0222DB70
	mov r1, #0x1e
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x55
	bl LoadFontPal0
	mov r1, #0
	str r1, [sp]
	mov r0, #0x55
	str r0, [sp, #4]
	ldr r0, _0222E5C0 ; =0x000029FC
	mov r2, #1
	ldr r0, [r4, r0]
	mov r3, #0xd
	bl LoadUserFrameGfx1
	mov r0, #1
	str r0, [sp]
	mov r0, #0x55
	str r0, [sp, #4]
	ldr r0, _0222E5C0 ; =0x000029FC
	mov r1, #0
	ldr r0, [r4, r0]
	mov r2, #0xa
	mov r3, #0xe
	bl LoadUserFrameGfx1
	ldr r0, _0222E5B0 ; =0x00002BAC
	mov r1, #0
	ldr r0, [r4, r0]
	mov r2, #0x13
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x55
	str r0, [sp, #4]
	ldr r0, _0222E5C0 ; =0x000029FC
	mov r3, #0xa
	ldr r0, [r4, r0]
	bl LoadUserFrameGfx2
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov74_0222D824
	add r0, r4, #0
	mov r1, #1
	mov r2, #3
	add r3, r5, #0
	bl ov74_0222D7F0
	b _0222E79C
_0222E34A:
	mov r1, #0xaf
	lsl r1, r1, #6
	ldr r6, [r4, r1]
	ldr r1, _0222E5C4 ; =gSystem
	mov r2, #0x40
	ldr r1, [r1, #0x48]
	add r3, r1, #0
	tst r3, r2
	beq _0222E368
	add r1, r6, #0
	sub r2, #0x41
	bl ov74_0222DAF8
	add r6, r0, #0
	b _0222E3A4
_0222E368:
	mov r2, #0x80
	tst r2, r1
	beq _0222E37A
	add r1, r6, #0
	mov r2, #1
	bl ov74_0222DAF8
	add r6, r0, #0
	b _0222E3A4
_0222E37A:
	mov r0, #2
	tst r0, r1
	beq _0222E394
	ldr r0, _0222E5C8 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x1d
	add r3, r5, #0
	bl ov74_0222D7F0
	b _0222E3A4
_0222E394:
	mov r0, #1
	tst r0, r1
	beq _0222E3A4
	ldr r0, _0222E5C8 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #4
	str r0, [r5]
_0222E3A4:
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	cmp r0, r6
	bne _0222E3B0
	b _0222E79C
_0222E3B0:
	ldr r0, _0222E5CC ; =SEQ_SE_DP_CARD2
	bl PlaySE
	mov r0, #0xaf
	lsl r0, r0, #6
	str r6, [r4, r0]
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov74_0222D824
	b _0222E79C
_0222E3C8:
	ldr r1, _0222E5D0 ; =0x00002BD0
	mov r3, #0xa
	add r1, r4, r1
	mov r2, #7
	lsl r3, r3, #6
	bl ov74_0222D9E0
	ldr r3, _0222E5D4 ; =0x00002BF0
	mov r2, #8
	add r1, r3, #0
	str r0, [r4, r3]
	sub r1, #0x10
	ldr r3, [r4, r3]
	add r0, r4, #0
	add r1, r4, r1
	bl ov74_0222D9E0
	mov r0, #5
	str r0, [r5]
	b _0222E79C
_0222E3F0:
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0
	bl ov74_0222DC60
	ldr r0, _0222E5C4 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _0222E4C2
	ldr r0, _0222E5C8 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #0xb
	str r0, [r5]
	b _0222E79C
_0222E410:
	ldr r0, _0222E5CC ; =SEQ_SE_DP_CARD2
	bl PlaySE
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, _0222E5D0 ; =0x00002BD0
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222D104
	ldr r0, _0222E5D8 ; =0x00002BE0
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222D0EC
	mov r1, #1
	add r0, r4, #0
	lsl r2, r1, #0xc
	mov r3, #0x66
	bl ov74_0222DE8C
	mov r0, #7
	str r0, [r5]
	b _0222E79C
_0222E444:
	bl ov74_0222DF2C
	cmp r0, #0
	beq _0222E4C2
	mov r1, #1
	add r0, r4, #0
	add r2, r1, #0
	bl ov74_0222D824
	ldr r2, _0222E5DC ; =0x00708000
	add r0, r4, #0
	mov r1, #0
	lsr r3, r2, #1
	bl ov74_0222DE8C
	mov r0, #8
	str r0, [r5]
	b _0222E79C
_0222E468:
	bl ov74_0222DF2C
	ldr r0, _0222E5C4 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	beq _0222E4C2
	ldr r0, _0222E5CC ; =SEQ_SE_DP_CARD2
	bl PlaySE
	mov r1, #1
	add r0, r4, #0
	lsl r2, r1, #0xc
	mov r3, #0x66
	bl ov74_0222DE8C
	mov r0, #9
	str r0, [r5]
	b _0222E79C
_0222E48E:
	bl ov74_0222DF2C
	cmp r0, #0
	beq _0222E4C2
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov74_0222D824
	ldr r2, _0222E5DC ; =0x00708000
	add r0, r4, #0
	mov r1, #0
	lsr r3, r2, #1
	bl ov74_0222DE8C
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0xa
	str r0, [r5]
	b _0222E79C
_0222E4BA:
	bl ov74_0222DF2C
	cmp r0, #0
	bne _0222E4C4
_0222E4C2:
	b _0222E79C
_0222E4C4:
	ldr r0, _0222E5D0 ; =0x00002BD0
	mov r1, #0
	add r0, r4, r0
	mov r2, #0x13
	mov r3, #0xa
	bl DrawFrameAndWindow2
	ldr r0, _0222E5D8 ; =0x00002BE0
	mov r1, #0
	add r0, r4, r0
	mov r2, #0xa
	mov r3, #0xe
	bl DrawFrameAndWindow1
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	bl ov74_0222DEF0
	mov r0, #5
	str r0, [r5]
	b _0222E79C
_0222E4F4:
	bl ov74_0222D448
	ldr r0, _0222E5D0 ; =0x00002BD0
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222D104
	ldr r0, _0222E5D0 ; =0x00002BD0
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222E5D0 ; =0x00002BD0
	add r0, r4, r0
	bl RemoveWindow
	mov r0, #3
	str r0, [r5]
	b _0222E79C
_0222E518:
	ldr r2, _0222E5E0 ; =ov74_0222D414
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222DC60
	b _0222E79C
_0222E524:
	ldr r2, _0222E5E0 ; =ov74_0222D414
	add r0, r6, #0
	add r1, r5, #0
	bl ov74_0222DC60
	b _0222E79C
_0222E530:
	ldr r1, _0222E5D8 ; =0x00002BE0
	ldr r2, _0222E5E4 ; =0x00010200
	add r1, r4, r1
	bl ov74_0222D7A4
	mov r0, #0xe
	str r0, [r5]
	b _0222E79C
_0222E540:
	mov r1, #0
	mov r2, #0x11
	add r3, r5, #0
	bl ov74_0222D7F0
	b _0222E79C
_0222E54C:
	bl ov74_0222D448
	ldr r0, _0222E5D0 ; =0x00002BD0
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222D104
	ldr r0, _0222E5D0 ; =0x00002BD0
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222E5D0 ; =0x00002BD0
	add r0, r4, r0
	bl RemoveWindow
	add r0, r4, #0
	mov r1, #0
	mov r2, #3
	bl ov74_0222D824
	ldr r0, _0222E5C0 ; =0x000029FC
	ldr r0, [r4, r0]
	bl ov74_0222D248
	add r0, r4, #0
	bl ov74_0222CFFC
	add r0, r4, #0
	bl ov74_0222D098
	mov r0, #0x12
	str r0, [r5]
	b _0222E79C
_0222E58E:
	bl ov74_0222E7EC
	bl sub_0203A880
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x13
	add r3, r5, #0
	bl ov74_0222D7F0
	b _0222E79C
	.balign 4, 0
_0222E5A4: .word 0x00002BA4
_0222E5A8: .word 0x00002BA0
_0222E5AC: .word 0x00002BA8
_0222E5B0: .word 0x00002BAC
_0222E5B4: .word 0x00002BB4
_0222E5B8: .word 0x00002BB8
_0222E5BC: .word 0x00002BBC
_0222E5C0: .word 0x000029FC
_0222E5C4: .word gSystem
_0222E5C8: .word SEQ_SE_DP_SELECT
_0222E5CC: .word SEQ_SE_DP_CARD2
_0222E5D0: .word 0x00002BD0
_0222E5D4: .word 0x00002BF0
_0222E5D8: .word 0x00002BE0
_0222E5DC: .word 0x00708000
_0222E5E0: .word ov74_0222D414
_0222E5E4: .word 0x00010200
_0222E5E8:
	mov r6, #0
	add r0, r6, #0
	bl sub_020373B4
	cmp r0, #0
	beq _0222E63A
	add r0, r4, #0
	add r0, #0x90
	bl sub_020358B8
	ldr r1, _0222E7C0 ; =0x00002B08
	add r0, r4, #0
	add r1, r4, r1
	bl ov74_0222E8B4
	add r6, r0, #0
	bne _0222E62A
	ldr r0, _0222E7C4 ; =0x00002C30
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222E62A
	ldr r0, _0222E7C0 ; =0x00002B08
	mov r1, #0
	add r0, r4, r0
	bl FillWindowPixelBuffer
	ldr r0, _0222E7C0 ; =0x00002B08
	add r0, r4, r0
	bl CopyWindowToVram
	ldr r0, _0222E7C4 ; =0x00002C30
	mov r1, #0
	str r1, [r4, r0]
_0222E62A:
	ldr r1, _0222E7C8 ; =0x00002AF8
	add r0, r4, #0
	add r1, r4, r1
	add r2, r6, #0
	bl ov74_0222EA88
	ldr r0, _0222E7C4 ; =0x00002C30
	str r6, [r4, r0]
_0222E63A:
	add r0, r4, #0
	add r1, r6, #0
	add r2, r5, #0
	bl ov74_0222E0D4
	b _0222E79C
_0222E646:
	mov r1, #0
	mov r2, #0x15
	add r3, r5, #0
	bl ov74_0222D7F0
	b _0222E79C
_0222E652:
	bl ov74_0222D024
	ldr r0, _0222E7CC ; =0x00002BD0
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222D104
	ldr r0, _0222E7D0 ; =0x00002BE0
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222D0EC
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov74_0222D824
	mov r1, #0x1e
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x55
	bl LoadFontPal0
	add r0, r4, #0
	mov r1, #1
	mov r2, #4
	add r3, r5, #0
	bl ov74_0222D7F0
	b _0222E79C
_0222E68E:
	bl sub_02037D78
	cmp r0, #0
	beq _0222E698
	b _0222E79C
_0222E698:
	mov r0, #0xb1
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	str r0, [r5]
	b _0222E79C
_0222E6A2:
	ldr r0, _0222E7D4 ; =0x00002C34
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222E79C
	ldr r1, _0222E7D8 ; =0x00002DD8
	add r0, r4, #0
	ldr r2, [r4]
	add r0, #0x90
	add r1, r4, r1
	bl ov74_02235ED0
	ldr r0, _0222E7D8 ; =0x00002DD8
	mov r1, #0xd6
	add r0, r4, r0
	lsl r1, r1, #2
	bl ov74_02229D0C
	add r0, r4, #0
	bl ov74_0222E060
	mov r0, #0x18
	str r0, [r5]
	b _0222E79C
_0222E6D6:
	bl ov74_0223615C
	cmp r0, #4
	bne _0222E79C
	mov r0, #0x93
	bl sub_02037AC0
	mov r0, #1
	add r1, r0, #0
	bl sub_020398D4
	mov r0, #0x19
	str r0, [r5]
	b _0222E79C
_0222E6F2:
	bl ov74_0222E898
	cmp r0, #0
	beq _0222E704
	mov r0, #0x93
	bl sub_02037B38
	cmp r0, #1
	bne _0222E79C
_0222E704:
	mov r0, #0
	add r1, r0, #0
	bl sub_020398D4
	bl ov74_02236128
	ldr r1, _0222E7CC ; =0x00002BD0
	mov r3, #0xa
	add r0, r4, #0
	add r1, r4, r1
	mov r2, #0x12
	lsl r3, r3, #6
	bl ov74_0222D9E0
	ldr r0, _0222E7DC ; =0x00003D50
	ldr r0, [r4, r0]
	bl sub_0200F450
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x1a
	bl ov74_0222EB28
	b _0222E79C
_0222E734:
	ldr r0, _0222E7E0 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	beq _0222E79C
	mov r0, #0x14
	str r0, [r5]
	b _0222E79C
_0222E744:
	ldr r0, _0222E7E0 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	beq _0222E79C
	ldr r0, _0222E7CC ; =0x00002BD0
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222D104
	ldr r0, _0222E7CC ; =0x00002BD0
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222E7CC ; =0x00002BD0
	add r0, r4, r0
	bl RemoveWindow
	mov r0, #3
	str r0, [r5]
	b _0222E79C
_0222E76E:
	mov r1, #0
	mov r2, #0x1d
	add r3, r5, #0
	bl ov74_0222D7F0
	b _0222E79C
_0222E77A:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0222E79C
	mov r0, #0xb1
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	str r0, [r5]
	b _0222E79C
_0222E78C:
	bl ov74_0222D024
	add r0, r4, #0
	bl ov74_0222DEF0
	add sp, #8
	mov r0, #1
	pop {r4, r5, r6, pc}
_0222E79C:
	ldr r0, _0222E7E4 ; =0x00002C44
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222E7A8
	bl SpriteList_RenderAndAnimateSprites
_0222E7A8:
	bl ov74_022358BC
	ldr r0, _0222E7E8 ; =0x00003D48
	ldr r1, [r4, r0]
	cmp r1, #0
	beq _0222E7B8
	add r0, r4, #0
	blx r1
_0222E7B8:
	mov r0, #0
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_0222E7C0: .word 0x00002B08
_0222E7C4: .word 0x00002C30
_0222E7C8: .word 0x00002AF8
_0222E7CC: .word 0x00002BD0
_0222E7D0: .word 0x00002BE0
_0222E7D4: .word 0x00002C34
_0222E7D8: .word 0x00002DD8
_0222E7DC: .word 0x00003D50
_0222E7E0: .word gSystem
_0222E7E4: .word 0x00002C44
_0222E7E8: .word 0x00003D48
	thumb_func_end ov74_0222E1F4


	thumb_func_start ov74_0222E7EC
ov74_0222E7EC: ; 0x0222E7EC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r1, [r5, r0]
	mov r2, #0xd6
	lsl r1, r1, #2
	add r1, r5, r1
	sub r0, #0xc
	ldr r4, [r1, r0]
	add r0, r5, #0
	add r0, #0xe0
	add r1, r4, #0
	lsl r2, r2, #2
	bl memcpy
	mov r1, #0x41
	add r0, r5, #0
	lsl r1, r1, #2
	add r0, #0x90
	add r1, r4, r1
	mov r2, #0x50
	bl memcpy
	ldr r0, _0222E854 ; =0x00000428
	mov r1, #0
	strb r1, [r5, r0]
	add r0, r5, #0
	add r0, #0xde
	ldrb r1, [r0]
	mov r0, #0x10
	mov r2, #0xf
	bic r1, r0
	add r0, r5, #0
	add r0, #0xde
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0xde
	ldrb r1, [r0]
	mov r0, #0x20
	orr r1, r0
	add r0, r5, #0
	add r0, #0xde
	strb r1, [r0]
	ldr r1, _0222E858 ; =0x00002BA4
	add r0, r5, #4
	ldr r1, [r5, r1]
	bl ov74_02229CE0
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0222E854: .word 0x00000428
_0222E858: .word 0x00002BA4
	thumb_func_end ov74_0222E7EC


	thumb_func_start ov74_0222E85C
ov74_0222E85C: ; 0x0222E85C
	push {r3, r4}
	ldr r3, [r0]
	ldr r1, [r0, #4]
	add r2, r0, #0
	mov r4, #0
	cmp r1, r3
	bge _0222E870
	add r3, r1, #0
	mov r4, #1
	add r2, r0, #4
_0222E870:
	ldr r1, [r0, #8]
	cmp r1, r3
	bge _0222E87E
	add r2, r0, #0
	add r3, r1, #0
	mov r4, #2
	add r2, #8
_0222E87E:
	ldr r1, [r0, #0xc]
	cmp r1, r3
	bge _0222E88A
	add r2, r0, #0
	mov r4, #3
	add r2, #0xc
_0222E88A:
	ldr r0, _0222E894 ; =0x3FFF0001
	str r0, [r2]
	add r0, r4, #1
	pop {r3, r4}
	bx lr
	.balign 4, 0
_0222E894: .word 0x3FFF0001
	thumb_func_end ov74_0222E85C


	thumb_func_start ov74_0222E898
ov74_0222E898: ; 0x0222E898
	push {r3, r4, r5, lr}
	mov r5, #0
	mov r4, #1
_0222E89E:
	add r0, r4, #0
	bl sub_02034818
	cmp r0, #0
	beq _0222E8AA
	add r5, r5, #1
_0222E8AA:
	add r4, r4, #1
	cmp r4, #5
	blt _0222E89E
	add r0, r5, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_0222E898


	thumb_func_start ov74_0222E8B4
ov74_0222E8B4: ; 0x0222E8B4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x48
	add r5, r0, #0
	mov r6, #0
	mov r0, #1
	str r1, [sp, #0x10]
	add r7, r6, #0
	str r0, [sp, #0x24]
	add r4, r5, #4
_0222E8C6:
	ldr r0, [sp, #0x24]
	bl sub_02034818
	cmp r0, #0
	bne _0222E8E8
	ldr r0, _0222EA70 ; =0x00002C08
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222E8DA
	add r7, r7, #1
_0222E8DA:
	ldr r0, _0222EA70 ; =0x00002C08
	mov r1, #0
	str r1, [r4, r0]
	ldr r1, _0222EA74 ; =0x3FFF0001
	add r0, #0x14
	str r1, [r4, r0]
	b _0222E910
_0222E8E8:
	ldr r1, _0222EA70 ; =0x00002C08
	ldr r1, [r4, r1]
	cmp r1, r0
	beq _0222E90E
	ldr r1, _0222EA70 ; =0x00002C08
	add r7, r7, #1
	str r0, [r4, r1]
	add r0, r1, #0
	add r1, #0x34
	ldr r1, [r5, r1]
	add r0, #0x34
	add r2, r1, #1
	ldr r0, [r5, r0]
	ldr r1, _0222EA78 ; =0x00002C3C
	add r6, r6, #1
	str r2, [r5, r1]
	sub r1, #0x20
	str r0, [r4, r1]
	b _0222E910
_0222E90E:
	add r6, r6, #1
_0222E910:
	ldr r0, [sp, #0x24]
	add r4, r4, #4
	add r0, r0, #1
	str r0, [sp, #0x24]
	cmp r0, #5
	blt _0222E8C6
	cmp r7, #0
	bne _0222E926
	add sp, #0x48
	add r0, r6, #0
	pop {r3, r4, r5, r6, r7, pc}
_0222E926:
	ldr r1, _0222EA7C ; =0x00002C20
	ldr r0, [r5, r1]
	str r0, [sp, #0x38]
	add r0, r1, #4
	ldr r0, [r5, r0]
	str r0, [sp, #0x3c]
	add r0, r1, #0
	add r0, #8
	ldr r0, [r5, r0]
	add r1, #0xc
	str r0, [sp, #0x40]
	ldr r0, [r5, r1]
	str r0, [sp, #0x44]
	add r0, sp, #0x38
	bl ov74_0222E85C
	str r0, [sp, #0x28]
	add r0, sp, #0x38
	bl ov74_0222E85C
	str r0, [sp, #0x2c]
	add r0, sp, #0x38
	bl ov74_0222E85C
	str r0, [sp, #0x30]
	add r0, sp, #0x38
	bl ov74_0222E85C
	str r0, [sp, #0x34]
	mov r0, #0x55
	bl MessageFormat_New
	add r4, r0, #0
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x55
	bl NewMsgDataFromNarc
	str r0, [sp, #0x1c]
	mov r5, #0
	ldr r0, [sp, #0x10]
	add r1, r5, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	str r0, [sp, #0x14]
	cmp r6, #0
	ble _0222EA54
	add r0, sp, #0x28
	str r0, [sp, #0x18]
_0222E98C:
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	bl sub_02034818
	add r7, r0, #0
	beq _0222EA44
	add r0, r4, #0
	mov r1, #0
	add r2, r7, #0
	bl BufferPlayersName
	ldr r1, [sp, #0x1c]
	add r0, r4, #0
	mov r2, #0x36
	mov r3, #0x55
	bl ReadMsgData_ExpandPlaceholders
	str r0, [sp, #0x20]
	add r0, r7, #0
	bl PlayerProfile_GetTrainerGender
	cmp r0, #0
	str r5, [sp]
	bne _0222E9D6
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0222EA80 ; =0x00050600
	mov r1, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r2, [sp, #0x20]
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
	b _0222E9F0
_0222E9D6:
	mov r0, #0xff
	str r0, [sp, #4]
	mov r0, #0xc1
	lsl r0, r0, #0xa
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	mov r1, #0
	ldr r0, [sp, #0x10]
	ldr r2, [sp, #0x20]
	add r3, r1, #0
	bl AddTextPrinterParameterizedWithColor
_0222E9F0:
	ldr r0, [sp, #0x20]
	bl String_Delete
	add r0, r7, #0
	bl PlayerProfile_GetTrainerID
	add r2, r0, #0
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	lsl r2, r2, #0x10
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0
	lsr r2, r2, #0x10
	mov r3, #5
	bl BufferIntegerAsString
	ldr r1, [sp, #0x1c]
	add r0, r4, #0
	mov r2, #0x37
	mov r3, #0x55
	bl ReadMsgData_ExpandPlaceholders
	add r7, r0, #0
	str r5, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0222EA84 ; =0x000E0F00
	mov r1, #0
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r2, r7, #0
	mov r3, #0x50
	bl AddTextPrinterParameterizedWithColor
	add r0, r7, #0
	bl String_Delete
	add r5, #0x18
_0222EA44:
	ldr r0, [sp, #0x18]
	add r0, r0, #4
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	cmp r0, r6
	blt _0222E98C
_0222EA54:
	cmp r6, #0
	beq _0222EA5E
	ldr r0, [sp, #0x10]
	bl CopyWindowToVram
_0222EA5E:
	ldr r0, [sp, #0x1c]
	bl DestroyMsgData
	add r0, r4, #0
	bl MessageFormat_Delete
	add r0, r6, #0
	add sp, #0x48
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222EA70: .word 0x00002C08
_0222EA74: .word 0x3FFF0001
_0222EA78: .word 0x00002C3C
_0222EA7C: .word 0x00002C20
_0222EA80: .word 0x00050600
_0222EA84: .word 0x000E0F00
	thumb_func_end ov74_0222E8B4


	thumb_func_start ov74_0222EA88
ov74_0222EA88: ; 0x0222EA88
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, _0222EB1C ; =0x00002BF4
	add r4, r1, #0
	str r2, [r5, r0]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x55
	bl NewMsgDataFromNarc
	ldr r1, _0222EB20 ; =0x00002A04
	str r0, [r5, r1]
	mov r0, #0x55
	bl MessageFormat_New
	mov r1, #0x2a
	lsl r1, r1, #8
	str r0, [r5, r1]
	add r0, r4, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r3, #1
	str r3, [sp]
	mov r0, #0x2a
	ldr r2, _0222EB1C ; =0x00002BF4
	str r3, [sp, #4]
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	ldr r2, [r5, r2]
	mov r1, #0
	bl BufferIntegerAsString
	mov r1, #0x2a
	lsl r1, r1, #8
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r2, #0x39
	mov r3, #0x55
	bl ReadMsgData_ExpandPlaceholders
	add r6, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, _0222EB24 ; =0x00010200
	mov r1, #1
	str r0, [sp, #8]
	add r0, r4, #0
	add r2, r6, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl CopyWindowToVram
	add r0, r6, #0
	bl String_Delete
	ldr r0, _0222EB20 ; =0x00002A04
	ldr r0, [r5, r0]
	bl DestroyMsgData
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	bl MessageFormat_Delete
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222EB1C: .word 0x00002BF4
_0222EB20: .word 0x00002A04
_0222EB24: .word 0x00010200
	thumb_func_end ov74_0222EA88


	thumb_func_start ov74_0222EB28
ov74_0222EB28: ; 0x0222EB28
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	bl ov74_02229DF8
	bl sub_0203A914
	mov r0, #0xb1
	lsl r0, r0, #6
	str r6, [r5, r0]
	mov r0, #0x17
	str r0, [r4]
	pop {r4, r5, r6, pc}
	thumb_func_end ov74_0222EB28


	thumb_func_start ov74_0222EB44
ov74_0222EB44: ; 0x0222EB44
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	bl OverlayManager_GetData
	add r7, r0, #0
	ldr r0, _0222EBF0 ; =0x00002A08
	mov r6, #0
	add r4, r7, #0
	add r5, r7, r0
_0222EB56:
	ldr r0, _0222EBF0 ; =0x00002A08
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222EB6A
	add r0, r5, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	bl RemoveWindow
_0222EB6A:
	add r6, r6, #1
	add r4, #0x10
	add r5, #0x10
	cmp r6, #0x13
	blo _0222EB56
	ldr r0, _0222EBF4 ; =0x00002BD0
	ldr r1, [r7, r0]
	cmp r1, #0
	beq _0222EB8A
	add r0, r7, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222EBF4 ; =0x00002BD0
	add r0, r7, r0
	bl RemoveWindow
_0222EB8A:
	ldr r0, _0222EBF8 ; =0x00002BE0
	ldr r1, [r7, r0]
	cmp r1, #0
	beq _0222EBA0
	add r0, r7, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222EBF8 ; =0x00002BE0
	add r0, r7, r0
	bl RemoveWindow
_0222EBA0:
	ldr r0, _0222EBFC ; =0x000029FC
	mov r1, #0
	ldr r0, [r7, r0]
	bl FreeBgTilemapBuffer
	ldr r0, _0222EBFC ; =0x000029FC
	mov r1, #1
	ldr r0, [r7, r0]
	bl FreeBgTilemapBuffer
	ldr r0, _0222EBFC ; =0x000029FC
	mov r1, #2
	ldr r0, [r7, r0]
	bl FreeBgTilemapBuffer
	ldr r0, _0222EBFC ; =0x000029FC
	mov r1, #3
	ldr r0, [r7, r0]
	bl FreeBgTilemapBuffer
	ldr r0, _0222EBFC ; =0x000029FC
	ldr r0, [r7, r0]
	bl Heap_Free
	ldr r0, _0222EC00 ; =FS_OVERLAY_ID(OVY_74)
	ldr r1, _0222EC04 ; =gApp_MainMenu_SelectOption_MysteryGift
	bl RegisterMainOverlay
	mov r0, #0x59
	bl Heap_Destroy
	ldr r0, [sp]
	bl OverlayManager_FreeData
	mov r0, #0x55
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222EBF0: .word 0x00002A08
_0222EBF4: .word 0x00002BD0
_0222EBF8: .word 0x00002BE0
_0222EBFC: .word 0x000029FC
_0222EC00: .word FS_OVERLAY_ID(OVY_74)
_0222EC04: .word gApp_MainMenu_SelectOption_MysteryGift
	thumb_func_end ov74_0222EB44


	thumb_func_start ov74_0222EC08
ov74_0222EC08: ; 0x0222EC08
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r7, r1, #0
	add r5, r2, #0
	bl ov74_0222FCC4
	ldr r1, _0222EC54 ; =0x00003D54
	add r0, r5, #0
	bl Heap_AllocAtEnd
	ldr r2, _0222EC54 ; =0x00003D54
	mov r1, #0
	add r4, r0, #0
	bl memset
	ldr r0, _0222EC58 ; =0x000029FC
	mov r1, #0x1e
	str r6, [r4, r0]
	mov r0, #0
	lsl r1, r1, #4
	add r2, r5, #0
	str r5, [r4]
	bl LoadFontPal0
	ldr r0, _0222EC5C ; =0x00002BB4
	mov r2, #0
	str r7, [r4, r0]
	add r0, #0xc
	str r2, [r4, r0]
	add r0, r4, #0
	mov r1, #1
	bl ov74_0222D824
	add r0, r4, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222EC54: .word 0x00003D54
_0222EC58: .word 0x000029FC
_0222EC5C: .word 0x00002BB4
	thumb_func_end ov74_0222EC08


	thumb_func_start ov74_0222EC60
ov74_0222EC60: ; 0x0222EC60
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _0222ECC8 ; =0x00002D7C
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222EC70
	bl Sprite_Delete
_0222EC70:
	mov r0, #0xb6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222EC7E
	bl Sprite_Delete
_0222EC7E:
	mov r0, #0xb6
	mov r1, #0
	lsl r0, r0, #6
	str r1, [r4, r0]
	ldr r2, [r4, r0]
	sub r1, r0, #4
	str r2, [r4, r1]
	add r0, r0, #4
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222EC98
	bl Sprite_Delete
_0222EC98:
	ldr r0, _0222ECCC ; =0x00002D88
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222ECA4
	bl Sprite_Delete
_0222ECA4:
	ldr r0, _0222ECD0 ; =0x00002D8C
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222ECB0
	bl Sprite_Delete
_0222ECB0:
	ldr r1, _0222ECD0 ; =0x00002D8C
	mov r0, #0
	str r0, [r4, r1]
	ldr r2, [r4, r1]
	sub r0, r1, #4
	str r2, [r4, r0]
	ldr r0, [r4, r0]
	sub r1, #8
	str r0, [r4, r1]
	bl ov74_022359BC
	pop {r4, pc}
	.balign 4, 0
_0222ECC8: .word 0x00002D7C
_0222ECCC: .word 0x00002D88
_0222ECD0: .word 0x00002D8C
	thumb_func_end ov74_0222EC60


	thumb_func_start ov74_0222ECD4
ov74_0222ECD4: ; 0x0222ECD4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl WindowIsInUse
	cmp r0, #1
	bne _0222ECEA
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0200E5D4
_0222ECEA:
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_0222ECD4


	thumb_func_start ov74_0222ECEC
ov74_0222ECEC: ; 0x0222ECEC
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl WindowIsInUse
	cmp r0, #1
	bne _0222ED02
	add r0, r5, #0
	add r1, r4, #0
	bl ClearFrameAndWindow2
_0222ED02:
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_0222ECEC


	thumb_func_start ov74_0222ED04
ov74_0222ED04: ; 0x0222ED04
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r4, r1, #0
	add r7, r2, #0
	str r3, [sp]
	cmp r0, #0
	beq _0222ED1E
	bl ListMenuItems_Delete
_0222ED1E:
	ldr r0, _0222EDB4 ; =0x00002BBC
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0222ED2E
	mov r1, #0
	add r2, r1, #0
	bl DestroyListMenu
_0222ED2E:
	add r0, r7, #0
	mov r1, #0x55
	bl ListMenuItems_New
	mov r1, #0xaf
	lsl r1, r1, #6
	str r0, [r5, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x55
	bl NewMsgDataFromNarc
	ldr r1, _0222EDB8 ; =0x00002A04
	mov r6, #0
	str r0, [r5, r1]
	cmp r7, #0
	ble _0222ED6C
_0222ED52:
	mov r0, #0xaf
	ldr r1, _0222EDB8 ; =0x00002A04
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r2, [r4]
	ldr r3, [r4, #4]
	bl ListMenuItems_AppendFromMsgData
	add r6, r6, #1
	add r4, #8
	cmp r6, r7
	blt _0222ED52
_0222ED6C:
	ldr r0, _0222EDB8 ; =0x00002A04
	ldr r0, [r5, r0]
	bl DestroyMsgData
	ldr r4, _0222EDBC ; =ov74_0223C6E0
	add r3, sp, #4
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	mov r1, #0
	str r0, [sp, #4]
	add r0, sp, #4
	strh r7, [r0, #0x10]
	ldr r0, [sp]
	mov r3, #0x55
	str r0, [sp, #0x10]
	add r0, r2, #0
	ldr r2, [sp, #0x38]
	lsl r2, r2, #0x10
	lsr r2, r2, #0x10
	bl ListMenuInit
	ldr r1, _0222EDB4 ; =0x00002BBC
	str r0, [r5, r1]
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_0222EDB4: .word 0x00002BBC
_0222EDB8: .word 0x00002A04
_0222EDBC: .word ov74_0223C6E0
	thumb_func_end ov74_0222ED04


	thumb_func_start ov74_0222EDC0
ov74_0222EDC0: ; 0x0222EDC0
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0xaf
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl ListMenuItems_Delete
	mov r0, #0xaf
	mov r1, #0
	lsl r0, r0, #6
	str r1, [r4, r0]
	sub r0, r0, #4
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl DestroyListMenu
	ldr r0, _0222EE00 ; =0x00002BBC
	mov r1, #0
	str r1, [r4, r0]
	add r0, #0x18
	add r0, r4, r0
	bl ov74_0222ECD4
	ldr r0, _0222EE04 ; =0x00002BD4
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222EE04 ; =0x00002BD4
	add r0, r4, r0
	bl RemoveWindow
	pop {r4, pc}
	.balign 4, 0
_0222EE00: .word 0x00002BBC
_0222EE04: .word 0x00002BD4
	thumb_func_end ov74_0222EDC0


	thumb_func_start ov74_0222EE08
ov74_0222EE08: ; 0x0222EE08
	mov r0, #1
	bx lr
	thumb_func_end ov74_0222EE08


	thumb_func_start ov74_0222EE0C
ov74_0222EE0C: ; 0x0222EE0C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	ldr r1, [r5]
	mov r0, #0x25
	add r4, r2, #0
	bl String_New
	ldr r1, _0222EE54 ; =0x00002BB4
	add r6, r0, #0
	ldr r2, [r5, r1]
	mov r1, #0x41
	lsl r1, r1, #2
	add r1, r2, r1
	mov r2, #0x24
	bl CopyU16ArrayToStringN
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r4, [sp, #8]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #1
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222EE54: .word 0x00002BB4
	thumb_func_end ov74_0222EE0C


	thumb_func_start ov74_0222EE58
ov74_0222EE58: ; 0x0222EE58
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r3, r0, #0
	ldr r0, _0222EEAC ; =0x00002BB4
	add r6, r1, #0
	ldr r1, [r3, r0]
	mov r0, #0x35
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	add r5, r2, #0
	cmp r0, #0
	bne _0222EE74
	mov r2, #0x51
	b _0222EE76
_0222EE74:
	mov r2, #0x52
_0222EE76:
	mov r1, #0x2a
	lsl r1, r1, #8
	ldr r0, [r3, r1]
	add r1, r1, #4
	ldr r1, [r3, r1]
	ldr r3, [r3]
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r5, [sp, #8]
	add r0, r6, #0
	mov r1, #1
	add r2, r4, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r4, #0
	bl String_Delete
	mov r0, #1
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_0222EEAC: .word 0x00002BB4
	thumb_func_end ov74_0222EE58


	thumb_func_start ov74_0222EEB0
ov74_0222EEB0: ; 0x0222EEB0
	push {r4, lr}
	sub sp, #0x18
	ldr r1, _0222EF14 ; =0x00002BB4
	add r4, r0, #0
	ldr r2, [r4, r1]
	mov r1, #0xd5
	lsl r1, r1, #2
	ldr r1, [r2, r1]
	add r0, sp, #8
	bl RTC_ConvertDayToDate
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x2a
	lsl r0, r0, #8
	mov r2, #0x7d
	ldr r3, [sp, #8]
	lsl r2, r2, #4
	add r2, r3, r2
	ldr r0, [r4, r0]
	mov r1, #0
	mov r3, #4
	bl BufferIntegerAsString
	mov r3, #2
	mov r0, #0x2a
	str r3, [sp]
	mov r1, #1
	str r1, [sp, #4]
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	ldr r2, [sp, #0xc]
	bl BufferIntegerAsString
	mov r1, #2
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	ldr r2, [sp, #0x10]
	add r3, r1, #0
	bl BufferIntegerAsString
	mov r0, #1
	add sp, #0x18
	pop {r4, pc}
	.balign 4, 0
_0222EF14: .word 0x00002BB4
	thumb_func_end ov74_0222EEB0


	thumb_func_start ov74_0222EF18
ov74_0222EF18: ; 0x0222EF18
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r7, r1, #0
	mov r0, #0xfb
	mov r1, #0x55
	add r4, r2, #0
	bl String_New
	ldr r1, _0222EF60 ; =0x00002BB4
	add r6, r0, #0
	ldr r2, [r5, r1]
	mov r1, #0x55
	lsl r1, r1, #2
	add r1, r2, r1
	mov r2, #0xfa
	bl CopyU16ArrayToStringN
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	str r4, [sp, #8]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	str r3, [sp, #0xc]
	bl AddTextPrinterParameterizedWithColor
	add r0, r6, #0
	bl String_Delete
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222EF60: .word 0x00002BB4
	thumb_func_end ov74_0222EF18


	thumb_func_start ov74_0222EF64
ov74_0222EF64: ; 0x0222EF64
	mov r0, #0
	bx lr
	thumb_func_end ov74_0222EF64


	thumb_func_start ov74_0222EF68
ov74_0222EF68: ; 0x0222EF68
	push {r3, r4, r5, r6, lr}
	sub sp, #0x24
	add r5, r0, #0
	ldr r0, _0222EFE0 ; =ov74_0223C6D0
	add r6, r1, #0
	ldr r1, [r0, #4]
	ldr r2, [r0]
	str r1, [sp, #0x18]
	ldr r1, [r0, #8]
	ldr r0, [r0, #0xc]
	str r2, [sp, #0x14]
	str r0, [sp, #0x20]
	ldr r0, _0222EFE4 ; =0x00002B9C
	str r1, [sp, #0x1c]
	ldr r4, [r5, r0]
	add r0, r6, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r6, #0
	bl RemoveWindow
	ldr r0, [r4, #8]
	add r1, r6, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4, #0xc]
	mov r2, #2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r4, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	ldr r0, _0222EFE8 ; =0x00002B98
	ldr r0, [r5, r0]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, _0222EFEC ; =0x000029FC
	ldr r3, [r4, #4]
	ldr r0, [r5, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl AddWindowParameterized
	mov r0, #0
	str r0, [sp]
	add r0, r5, #0
	add r1, sp, #0x14
	mov r2, #2
	add r3, r6, #0
	bl ov74_0222ED04
	mov r0, #1
	add sp, #0x24
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0222EFE0: .word ov74_0223C6D0
_0222EFE4: .word 0x00002B9C
_0222EFE8: .word 0x00002B98
_0222EFEC: .word 0x000029FC
	thumb_func_end ov74_0222EF68


	thumb_func_start ov74_0222EFF0
ov74_0222EFF0: ; 0x0222EFF0
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x55
	str r0, [sp, #8]
	add r6, r2, #0
	mov r0, #0
	add r4, r3, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	cmp r4, #0
	beq _0222F018
	mov r0, #0x1c
	str r0, [r4]
_0222F018:
	ldr r0, _0222F020 ; =0x00002BF8
	str r6, [r5, r0]
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0222F020: .word 0x00002BF8
	thumb_func_end ov74_0222EFF0


	thumb_func_start ov74_0222F024
ov74_0222F024: ; 0x0222F024
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	add r5, r0, #0
	ldr r3, [r5]
	str r2, [sp, #0x14]
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	ldr r4, _0222F1A4 ; =ov74_0223C700
	bl NewMsgDataFromNarc
	ldr r1, _0222F1A8 ; =0x00002A04
	str r0, [r5, r1]
	ldr r0, [r5]
	bl MessageFormat_New
	mov r1, #0x2a
	lsl r1, r1, #8
	str r0, [r5, r1]
	ldr r1, _0222F1AC ; =0x00002BB8
	ldr r0, [sp, #0x14]
	str r0, [r5, r1]
	ldr r1, [sp, #0x14]
	add r0, r5, #0
	bl ov74_0222F314
	mov r0, #0
	str r0, [sp, #0x2c]
	ldr r0, _0222F1B0 ; =0x00002A08
	add r7, r4, #0
	str r5, [sp, #0x1c]
	add r6, r5, r0
_0222F064:
	ldr r1, [r7]
	ldr r0, [sp, #0x14]
	cmp r0, r1
	beq _0222F086
	cmp r1, #2
	beq _0222F086
	ldr r1, [sp, #0x1c]
	ldr r0, _0222F1B0 ; =0x00002A08
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _0222F086
	add r0, r6, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r6, #0
	bl RemoveWindow
_0222F086:
	ldr r0, [sp, #0x1c]
	add r7, #0x30
	add r0, #0x10
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x2c]
	add r6, #0x10
	add r0, r0, #1
	str r0, [sp, #0x2c]
	cmp r0, #0xb
	blo _0222F064
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, _0222F1B0 ; =0x00002A08
	mov r7, #0x31
	str r5, [sp, #0x24]
	str r5, [sp, #0x20]
	add r6, r5, r0
_0222F0A8:
	ldr r1, [r4]
	ldr r0, [sp, #0x14]
	cmp r0, r1
	bne _0222F166
	ldr r1, [sp, #0x24]
	ldr r0, _0222F1B0 ; =0x00002A08
	ldr r0, [r1, r0]
	cmp r0, #0
	bne _0222F0F4
	ldr r1, [sp, #0x20]
	ldr r0, _0222F1B4 ; =0x00002B48
	mov r2, #0
	str r7, [r1, r0]
	ldr r0, [r4, #8]
	add r1, r6, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r4, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	lsl r0, r7, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, _0222F1B8 ; =0x000029FC
	ldr r3, [r4, #4]
	ldr r0, [r5, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl AddWindowParameterized
_0222F0F4:
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x1c]
	lsl r0, r0, #0x18
	lsl r1, r1, #0x18
	lsr r0, r0, #0x18
	lsr r1, r1, #0x18
	bl GetFontAttribute
	add r1, r0, #0
	add r0, r6, #0
	bl FillWindowPixelBuffer
	ldr r0, [r4, #0x18]
	ldr r3, [r4, #0x24]
	str r0, [sp, #0x28]
	ldr r2, [sp, #0x28]
	add r0, r5, #0
	add r1, r6, #0
	blx r3
	cmp r0, #1
	bne _0222F158
	ldr r2, [r4, #0x20]
	cmp r2, #0
	beq _0222F158
	mov r0, #0x2a
	ldr r1, _0222F1A8 ; =0x00002A04
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	ldr r3, [r5]
	bl ReadMsgData_ExpandPlaceholders
	str r0, [sp, #0x30]
	ldr r0, [r4, #0x2c]
	ldr r2, [sp, #0x30]
	str r0, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r1, [r4, #0x14]
	ldr r3, [r4, #0x28]
	add r0, r6, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x30]
	bl String_Delete
_0222F158:
	add r0, r6, #0
	bl CopyWindowToVram
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x10]
	mul r0, r1
	add r7, r7, r0
_0222F166:
	ldr r0, [sp, #0x24]
	add r4, #0x30
	add r0, #0x10
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	add r6, #0x10
	add r0, r0, #4
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	str r0, [sp, #0x18]
	cmp r0, #0xb
	blo _0222F0A8
	ldr r0, _0222F1A8 ; =0x00002A04
	ldr r0, [r5, r0]
	bl DestroyMsgData
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	bl MessageFormat_Delete
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bne _0222F19E
	add r0, r5, #0
	bl ov74_0222F478
_0222F19E:
	add sp, #0x34
	pop {r4, r5, r6, r7, pc}
	nop
_0222F1A4: .word ov74_0223C700
_0222F1A8: .word 0x00002A04
_0222F1AC: .word 0x00002BB8
_0222F1B0: .word 0x00002A08
_0222F1B4: .word 0x00002B48
_0222F1B8: .word 0x000029FC
	thumb_func_end ov74_0222F024


	thumb_func_start ov74_0222F1BC
ov74_0222F1BC: ; 0x0222F1BC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r7, r3, #0
	mov r3, #0x30
	ldr r0, _0222F2BC ; =ov74_0223C700
	mul r3, r2
	add r6, r1, #0
	add r4, r0, r3
	ldr r0, [r6]
	cmp r0, #0
	bne _0222F206
	ldr r0, [r4, #8]
	mov r2, #2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r4, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r4, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	lsl r0, r7, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, _0222F2C0 ; =0x000029FC
	ldr r3, [r4, #4]
	ldr r0, [r5, r0]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl AddWindowParameterized
_0222F206:
	ldr r1, [r4, #0x1c]
	add r0, r6, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl FillWindowPixelBuffer
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _0222F234
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xf7
	mov r3, #0x55
	bl NewMsgDataFromNarc
	ldr r1, _0222F2C4 ; =0x00002A04
	str r0, [r5, r1]
	mov r0, #0x55
	bl MessageFormat_New
	mov r1, #0x2a
	lsl r1, r1, #8
	str r0, [r5, r1]
_0222F234:
	ldr r0, _0222F2C8 ; =0x00002B98
	ldr r2, _0222F2CC ; =0x00010200
	str r7, [r5, r0]
	add r0, r0, #4
	str r4, [r5, r0]
	ldr r3, [r4, #0x24]
	add r0, r5, #0
	add r1, r6, #0
	blx r3
	ldr r2, [r4, #0x20]
	cmp r2, #0
	beq _0222F28E
	mov r1, #0x2a
	lsl r1, r1, #8
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	mov r3, #0x55
	bl ReadMsgData_ExpandPlaceholders
	str r0, [sp, #0x14]
	mov r3, #0
	str r3, [sp]
	mov r0, #0xff
	str r0, [sp, #4]
	ldr r0, [r4, #0x18]
	ldr r2, [sp, #0x14]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	ldr r1, [r4, #0x14]
	add r0, r6, #0
	bl AddTextPrinterParameterizedWithColor
	ldr r0, [sp, #0x14]
	bl String_Delete
	ldr r0, _0222F2C4 ; =0x00002A04
	ldr r0, [r5, r0]
	bl DestroyMsgData
	mov r0, #0x2a
	lsl r0, r0, #8
	ldr r0, [r5, r0]
	bl MessageFormat_Delete
_0222F28E:
	ldr r0, _0222F2D0 ; =0x00002BC4
	add r0, r5, r0
	cmp r6, r0
	bne _0222F2A4
	add r0, r6, #0
	mov r1, #0
	mov r2, #0x13
	mov r3, #0xa
	bl DrawFrameAndWindow2
	b _0222F2B0
_0222F2A4:
	add r0, r6, #0
	mov r1, #0
	mov r2, #0xa
	mov r3, #0xe
	bl DrawFrameAndWindow1
_0222F2B0:
	ldr r1, [r4, #0xc]
	ldr r0, [r4, #0x10]
	mul r0, r1
	add r0, r7, r0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222F2BC: .word ov74_0223C700
_0222F2C0: .word 0x000029FC
_0222F2C4: .word 0x00002A04
_0222F2C8: .word 0x00002B98
_0222F2CC: .word 0x00010200
_0222F2D0: .word 0x00002BC4
	thumb_func_end ov74_0222F1BC


	thumb_func_start ov74_0222F2D4
ov74_0222F2D4: ; 0x0222F2D4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r2, #0
	mov r2, #1
	add r5, r0, #0
	str r2, [sp]
	add r6, r3, #0
	ldr r3, [r5]
	mov r0, #0x71
	bl GfGfxLoader_LoadFromNarc
	add r1, sp, #4
	add r7, r0, #0
	bl NNS_G2dGetUnpackedScreenData
	ldr r0, _0222F310 ; =0x000029FC
	ldr r2, [sp, #4]
	lsl r1, r4, #0x18
	ldr r0, [r5, r0]
	lsr r1, r1, #0x18
	add r2, #0xc
	add r3, r6, #0
	bl BG_LoadScreenTilemapData
	add r0, r7, #0
	bl Heap_Free
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222F310: .word 0x000029FC
	thumb_func_end ov74_0222F2D4


	thumb_func_start ov74_0222F314
ov74_0222F314: ; 0x0222F314
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #1
	lsl r0, r0, #8
	str r0, [sp]
	ldr r0, [r5]
	mov r2, #0
	add r4, r1, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #7
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r5]
	ldr r2, _0222F400 ; =0x000029FC
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r0, #0x71
	mov r1, #0xa
	bl GfGfxLoader_LoadCharData
	cmp r4, #0
	beq _0222F35A
	cmp r4, #1
	beq _0222F37A
	b _0222F398
_0222F35A:
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r5]
	ldr r2, _0222F400 ; =0x000029FC
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r0, #0x71
	mov r1, #8
	bl GfGfxLoader_LoadScrnData
	b _0222F398
_0222F37A:
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r3, #1
	str r3, [sp, #8]
	ldr r0, [r5]
	ldr r2, _0222F400 ; =0x000029FC
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r0, #0x71
	mov r1, #9
	bl GfGfxLoader_LoadScrnData
_0222F398:
	mov r0, #0x20
	str r0, [sp]
	ldr r0, [r5]
	mov r1, #0
	str r0, [sp, #4]
	mov r0, #0x71
	add r3, r0, #0
	add r2, r1, #0
	add r3, #0xef
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	ldr r0, [r5]
	ldr r2, _0222F400 ; =0x000029FC
	str r0, [sp, #0xc]
	ldr r2, [r5, r2]
	mov r0, #0x71
	mov r3, #3
	bl GfGfxLoader_LoadCharData
	mov r2, #3
	add r0, r5, #0
	mov r1, #2
	lsl r3, r2, #9
	bl ov74_0222F2D4
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	ldr r0, _0222F400 ; =0x000029FC
	mov r2, #0
	ldr r0, [r5, r0]
	mov r1, #3
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	ldr r0, _0222F400 ; =0x000029FC
	mov r1, #3
	ldr r0, [r5, r0]
	bl BgCommitTilemapBufferToVram
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222F400: .word 0x000029FC
	thumb_func_end ov74_0222F314


	thumb_func_start ov74_0222F404
ov74_0222F404: ; 0x0222F404
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r5, r1, #0
	add r6, r2, #0
	bl OverlayManager_GetData
	ldr r1, _0222F46C ; =0x00002BBC
	ldr r0, [r0, r1]
	bl ListMenu_ProcessInput
	add r4, r0, #0
	mov r0, #1
	mvn r0, r0
	cmp r4, r0
	beq _0222F42A
	add r0, r0, #1
	cmp r4, r0
	beq _0222F468
	b _0222F444
_0222F42A:
	ldr r0, _0222F470 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	cmp r6, #0
	beq _0222F468
	add r0, r7, #0
	blx r6
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222F468
	str r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
_0222F444:
	ldr r0, _0222F470 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	cmp r4, #0
	beq _0222F468
	cmp r4, #0x1f
	bhs _0222F456
	str r4, [r5]
	pop {r3, r4, r5, r6, r7, pc}
_0222F456:
	ldr r0, _0222F474 ; =ov74_0223D0C0
	str r4, [r0]
	add r0, r7, #0
	blx r4
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222F468
	str r0, [r5]
_0222F468:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222F46C: .word 0x00002BBC
_0222F470: .word SEQ_SE_DP_SELECT
_0222F474: .word ov74_0223D0C0
	thumb_func_end ov74_0222F404


	thumb_func_start ov74_0222F478
ov74_0222F478: ; 0x0222F478
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	ldr r1, _0222F58C ; =0x00002D84
	add r7, r0, #0
	ldr r0, [r7, r1]
	cmp r0, #0
	bne _0222F4D8
	add r0, r1, #4
	ldr r0, [r7, r0]
	cmp r0, #0
	bne _0222F4D8
	add r1, #8
	ldr r0, [r7, r1]
	cmp r0, #0
	bne _0222F4D8
	bl ov74_0223567C
	cmp r0, #1
	bne _0222F4A4
	add r0, r7, #0
	bl ov74_0222EC60
_0222F4A4:
	bl ov74_0223563C
	bl ov74_02235690
	mov r0, #0x1c
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0x1e
	mov r2, #0x1b
	mov r3, #0x1d
	bl ov74_02235728
	bl sub_02074490
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, [r7]
	mov r2, #1
	str r0, [sp, #4]
	mov r0, #0x14
	mov r3, #0x60
	bl GfGfxLoader_GXLoadPal
_0222F4D8:
	mov r0, #0xb2
	mov r4, #0
	str r0, [sp, #0x10]
	str r4, [sp, #0xc]
	add r5, r7, #0
	mov r6, #0x64
_0222F4E4:
	ldr r0, _0222F590 ; =0x00002BB4
	ldr r0, [r7, r0]
	add r1, r0, r4
	ldr r0, _0222F594 ; =0x0000034A
	ldrh r0, [r1, r0]
	str r0, [sp, #8]
	cmp r0, #0
	bne _0222F504
	ldr r0, _0222F58C ; =0x00002D84
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0222F56E
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0222F56E
_0222F504:
	ldr r0, [sp, #0xc]
	ldr r1, _0222F58C ; =0x00002D84
	add r0, #0xa
	str r0, [sp]
	ldr r1, [r5, r1]
	ldr r2, [sp, #0x10]
	mov r0, #0
	mov r3, #0x10
	bl ov74_02235930
	ldr r1, _0222F58C ; =0x00002D84
	str r0, [r5, r1]
	mov r1, #0
	ldr r0, [sp, #8]
	add r2, r1, #0
	bl GetMonIconNaixEx
	add r1, r0, #0
	ldr r0, [r7]
	mov r2, #0
	str r0, [sp]
	mov r0, #0x14
	add r3, sp, #0x18
	bl GfGfxLoader_GetCharData
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	mov r1, #2
	ldr r0, [r0, #0x14]
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp, #0x18]
	mov r2, #2
	ldr r0, [r0, #0x14]
	lsl r1, r6, #5
	lsl r2, r2, #8
	bl GX_LoadOBJ
	mov r1, #0
	ldr r0, [sp, #8]
	add r2, r1, #0
	bl GetMonIconPaletteEx
	add r1, r0, #0
	ldr r0, _0222F58C ; =0x00002D84
	add r1, r1, #3
	ldr r0, [r5, r0]
	bl Sprite_SetPaletteOverride
	ldr r0, [sp, #0x14]
	bl Heap_Free
_0222F56E:
	ldr r0, [sp, #0xc]
	add r4, r4, #2
	add r0, r0, #1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	add r5, r5, #4
	add r0, #0x19
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r6, #0x10
	cmp r0, #3
	blt _0222F4E4
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_0222F58C: .word 0x00002D84
_0222F590: .word 0x00002BB4
_0222F594: .word 0x0000034A
	thumb_func_end ov74_0222F478


	thumb_func_start ov74_0222F598
ov74_0222F598: ; 0x0222F598
	push {r4, lr}
	add r4, r0, #0
	mov r0, #3
	mov r1, #0x55
	lsl r2, r0, #0x10
	bl Heap_Create
	ldr r1, _0222F5F4 ; =0x00003D0C
	add r0, r4, #0
	mov r2, #0x55
	bl OverlayManager_CreateAndGetData
	ldr r2, _0222F5F4 ; =0x00003D0C
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x55
	bl BgConfig_Alloc
	ldr r1, _0222F5F8 ; =0x000029FC
	str r0, [r4, r1]
	mov r0, #0x55
	str r0, [r4]
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FBF4
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	ldr r0, _0222F5FC ; =0x00002BF4
	mov r1, #1
	str r1, [r4, r0]
	mov r0, #0x55
	bl ov74_022352A0
	mov r2, #0x57
	mov r0, #0
	mov r1, #0x59
	lsl r2, r2, #4
	bl Heap_Create
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
_0222F5F4: .word 0x00003D0C
_0222F5F8: .word 0x000029FC
_0222F5FC: .word 0x00002BF4
	thumb_func_end ov74_0222F598


	thumb_func_start ov74_0222F600
ov74_0222F600: ; 0x0222F600
	push {r4, lr}
	add r4, r1, #0
	bl sub_02014AA0
	mov r0, #3
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	bl sub_02014A60
	ldr r1, _0222F620 ; =0x04000010
	mov r2, #8
	mov r3, #1
	bl sub_02014AB0
	pop {r4, pc}
	nop
_0222F620: .word 0x04000010
	thumb_func_end ov74_0222F600


	thumb_func_start ov74_0222F624
ov74_0222F624: ; 0x0222F624
	push {r3, r4, r5, lr}
	ldr r4, _0222F678 ; =0x000030E8
	ldr r5, _0222F67C ; =0x00000C14
	add r4, r0, r4
	add r0, r5, #0
	str r1, [r4, r5]
	sub r0, #0xc
	str r2, [r4, r0]
	add r0, r5, #0
	sub r0, #8
	sub r5, #0x14
	str r3, [r4, r0]
	ldr r0, [r4, r5]
	cmp r0, #0
	bne _0222F656
	mov r2, #6
	lsl r2, r2, #8
	mov r0, #0x55
	add r1, r4, #0
	add r2, r4, r2
	bl sub_02014A08
	mov r1, #3
	lsl r1, r1, #0xa
	str r0, [r4, r1]
_0222F656:
	ldr r0, _0222F680 ; =0x00000C04
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0222F66E
	mov r2, #1
	ldr r0, _0222F684 ; =ov74_0222F600
	add r1, r4, #0
	lsl r2, r2, #0xa
	bl SysTask_CreateOnVBlankQueue
	ldr r1, _0222F680 ; =0x00000C04
	str r0, [r4, r1]
_0222F66E:
	mov r0, #0xc1
	mov r1, #1
	lsl r0, r0, #4
	str r1, [r4, r0]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0222F678: .word 0x000030E8
_0222F67C: .word 0x00000C14
_0222F680: .word 0x00000C04
_0222F684: .word ov74_0222F600
	thumb_func_end ov74_0222F624


	thumb_func_start ov74_0222F688
ov74_0222F688: ; 0x0222F688
	push {r4, lr}
	ldr r1, _0222F6BC ; =0x000030E8
	add r4, r0, r1
	mov r0, #3
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222F69C
	bl sub_02014A38
_0222F69C:
	ldr r0, _0222F6C0 ; =0x00000C04
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222F6A8
	bl SysTask_Destroy
_0222F6A8:
	mov r0, #3
	mov r1, #0
	lsl r0, r0, #0xa
	str r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
	bl sub_02014AA0
	pop {r4, pc}
	nop
_0222F6BC: .word 0x000030E8
_0222F6C0: .word 0x00000C04
	thumb_func_end ov74_0222F688


	thumb_func_start ov74_0222F6C4
ov74_0222F6C4: ; 0x0222F6C4
	push {r3, r4, r5, r6, r7, lr}
	ldr r1, _0222F7CC ; =0x000030E8
	mov r5, #0x15
	add r4, r0, r1
	mov r0, #0xc1
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	lsl r5, r5, #0xe
	cmp r1, #0
	bne _0222F6DC
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0222F6DC:
	add r1, r0, #4
	ldr r1, [r4, r1]
	cmp r1, #1
	bne _0222F72A
	add r1, r0, #0
	sub r1, #8
	ldr r2, [r4, r1]
	sub r1, r0, #4
	ldr r1, [r4, r1]
	add r2, r2, r1
	add r1, r0, #0
	sub r1, #8
	str r2, [r4, r1]
	sub r1, r0, #4
	ldr r2, [r4, r1]
	add r1, r2, #0
	add r2, r2, r1
	sub r1, r0, #4
	str r2, [r4, r1]
	add r1, r0, #0
	sub r1, #8
	ldr r2, [r4, r1]
	asr r1, r2, #0xb
	lsr r1, r1, #0x14
	add r1, r2, r1
	asr r2, r1, #0xc
	mov r1, #0xfa
	lsl r1, r1, #2
	cmp r2, r1
	ble _0222F764
	mov r2, #0
	add r1, r0, #0
	str r2, [r4, r0]
	sub r1, #8
	str r2, [r4, r1]
	sub r0, r0, #4
	mov r5, #0xa8
	str r2, [r4, r0]
	b _0222F764
_0222F72A:
	add r1, r0, #0
	sub r1, #8
	ldr r2, [r4, r1]
	sub r1, r0, #4
	ldr r1, [r4, r1]
	sub r2, r2, r1
	add r1, r0, #0
	sub r1, #8
	str r2, [r4, r1]
	sub r1, r0, #4
	ldr r2, [r4, r1]
	lsr r1, r2, #0x1f
	add r1, r2, r1
	asr r2, r1, #1
	sub r1, r0, #4
	str r2, [r4, r1]
	mov r2, #1
	ldr r1, [r4, r1]
	lsl r2, r2, #0xa
	cmp r1, r2
	bge _0222F764
	mov r1, #0
	lsl r3, r2, #2
	add r2, r0, #0
	str r1, [r4, r0]
	sub r2, #8
	str r3, [r4, r2]
	sub r0, r0, #4
	str r1, [r4, r0]
_0222F764:
	mov r0, #3
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	bl sub_02014A4C
	add r2, r0, #0
	mov r0, #0x54
	add r3, r0, #0
	add r3, #0xfc
_0222F776:
	asr r1, r5, #0xb
	lsr r1, r1, #0x14
	add r1, r5, r1
	asr r1, r1, #0xc
	bpl _0222F782
	mov r1, #0
_0222F782:
	cmp r1, #0xa8
	ble _0222F788
	mov r1, #0xa8
_0222F788:
	lsl r6, r3, #1
	add r7, r2, r6
	sub r6, r1, r0
	strh r6, [r7, #6]
	ldrh r6, [r7, #6]
	sub r1, r0, r1
	add r3, r3, #4
	strh r6, [r7, #2]
	mov r6, #0xa8
	sub r6, r6, r0
	lsl r6, r6, #3
	add r6, r2, r6
	strh r1, [r6, #6]
	ldrh r1, [r6, #6]
	add r0, r0, #1
	strh r1, [r6, #2]
	ldr r1, _0222F7D0 ; =0x00000C08
	ldr r1, [r4, r1]
	add r5, r5, r1
	cmp r0, #0xa8
	blt _0222F776
	mov r1, #6
	add r0, r2, #0
	lsl r1, r1, #8
	bl DC_FlushRange
	mov r0, #3
	lsl r0, r0, #0xa
	ldr r0, [r4, r0]
	bl sub_02014A8C
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222F7CC: .word 0x000030E8
_0222F7D0: .word 0x00000C08
	thumb_func_end ov74_0222F6C4


	thumb_func_start ov74_0222F7D4
ov74_0222F7D4: ; 0x0222F7D4
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r1, #0
	add r6, r0, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #0x1e
	bls _0222F7EA
	b _0222FB2C
_0222F7EA:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0222F7F6: ; jump table
	.short _0222F834 - _0222F7F6 - 2 ; case 0
	.short _0222F874 - _0222F7F6 - 2 ; case 1
	.short _0222F886 - _0222F7F6 - 2 ; case 2
	.short _0222F8FC - _0222F7F6 - 2 ; case 3
	.short _0222F92E - _0222F7F6 - 2 ; case 4
	.short _0222F956 - _0222F7F6 - 2 ; case 5
	.short _0222F976 - _0222F7F6 - 2 ; case 6
	.short _0222F9AA - _0222F7F6 - 2 ; case 7
	.short _0222F9CE - _0222F7F6 - 2 ; case 8
	.short _0222F9F4 - _0222F7F6 - 2 ; case 9
	.short _0222FA20 - _0222F7F6 - 2 ; case 10
	.short _0222FA5A - _0222F7F6 - 2 ; case 11
	.short _0222FB2C - _0222F7F6 - 2 ; case 12
	.short _0222FAD6 - _0222F7F6 - 2 ; case 13
	.short _0222FB2C - _0222F7F6 - 2 ; case 14
	.short _0222FB2C - _0222F7F6 - 2 ; case 15
	.short _0222FB2C - _0222F7F6 - 2 ; case 16
	.short _0222FB2C - _0222F7F6 - 2 ; case 17
	.short _0222FB2C - _0222F7F6 - 2 ; case 18
	.short _0222FB2C - _0222F7F6 - 2 ; case 19
	.short _0222FA7E - _0222F7F6 - 2 ; case 20
	.short _0222FA8A - _0222F7F6 - 2 ; case 21
	.short _0222FB2C - _0222F7F6 - 2 ; case 22
	.short _0222FAC6 - _0222F7F6 - 2 ; case 23
	.short _0222FB2C - _0222F7F6 - 2 ; case 24
	.short _0222FB2C - _0222F7F6 - 2 ; case 25
	.short _0222FB2C - _0222F7F6 - 2 ; case 26
	.short _0222FB00 - _0222F7F6 - 2 ; case 27
	.short _0222FB0C - _0222F7F6 - 2 ; case 28
	.short _0222FB1C - _0222F7F6 - 2 ; case 29
	.short _0222FB2C - _0222F7F6 - 2 ; case 30
_0222F834:
	add r0, r6, #0
	bl OverlayManager_GetArgs
	ldr r1, [r0, #8]
	ldr r0, _0222FB50 ; =0x00002BA4
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	bl Save_MysteryGift_Get
	ldr r1, _0222FB54 ; =0x00002BA0
	str r0, [r4, r1]
	add r0, r1, #4
	ldr r0, [r4, r0]
	bl Save_PlayerData_GetOptionsAddr
	ldr r1, _0222FB58 ; =0x00002BA8
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	bl Options_GetFrame
	ldr r1, _0222FB5C ; =0x00002BAC
	str r0, [r4, r1]
	sub r1, #0xc
	ldr r0, [r4, r1]
	mov r1, #4
	bl SaveMysteryGift_CardGetByIdx
	ldr r1, _0222FB60 ; =0x00002BB4
	str r0, [r4, r1]
	mov r0, #1
	str r0, [r5]
	b _0222FB2C
_0222F874:
	bl ov74_0222FCA4
	ldr r0, _0222FB64 ; =0x000029FC
	ldr r0, [r4, r0]
	bl ov74_0222FCC4
	mov r0, #2
	str r0, [r5]
	b _0222FB2C
_0222F886:
	bl ResetAllTextPrinters
	add r0, r4, #0
	mov r1, #0
	bl ov74_0222F314
	mov r1, #0x1e
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x55
	bl LoadFontPal0
	mov r1, #0
	str r1, [sp]
	mov r0, #0x55
	str r0, [sp, #4]
	ldr r0, _0222FB64 ; =0x000029FC
	mov r2, #1
	ldr r0, [r4, r0]
	mov r3, #0xd
	bl LoadUserFrameGfx1
	mov r0, #1
	str r0, [sp]
	mov r0, #0x55
	str r0, [sp, #4]
	ldr r0, _0222FB64 ; =0x000029FC
	mov r1, #0
	ldr r0, [r4, r0]
	mov r2, #0xa
	mov r3, #0xe
	bl LoadUserFrameGfx1
	ldr r0, _0222FB5C ; =0x00002BAC
	mov r1, #0
	ldr r0, [r4, r0]
	mov r2, #0x13
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x55
	str r0, [sp, #4]
	ldr r0, _0222FB64 ; =0x000029FC
	mov r3, #0xa
	ldr r0, [r4, r0]
	bl LoadUserFrameGfx2
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov74_0222F024
	add r0, r4, #0
	mov r1, #1
	mov r2, #3
	add r3, r5, #0
	bl ov74_0222EFF0
	b _0222FB2C
_0222F8FC:
	ldr r0, _0222FB68 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _0222F91A
	ldr r0, _0222FB6C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x1d
	add r3, r5, #0
	bl ov74_0222EFF0
	b _0222FB2C
_0222F91A:
	mov r0, #1
	tst r0, r1
	bne _0222F922
	b _0222FB2C
_0222F922:
	ldr r0, _0222FB6C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #4
	str r0, [r5]
	b _0222FB2C
_0222F92E:
	ldr r1, _0222FB70 ; =0x00002BC4
	mov r3, #0xa
	add r1, r4, r1
	mov r2, #7
	lsl r3, r3, #6
	bl ov74_0222F1BC
	ldr r3, _0222FB74 ; =0x00002BE4
	mov r2, #8
	add r1, r3, #0
	str r0, [r4, r3]
	sub r1, #0x10
	ldr r3, [r4, r3]
	add r0, r4, #0
	add r1, r4, r1
	bl ov74_0222F1BC
	mov r0, #5
	str r0, [r5]
	b _0222FB2C
_0222F956:
	add r0, r6, #0
	add r1, r5, #0
	mov r2, #0
	bl ov74_0222F404
	ldr r0, _0222FB68 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _0222FA28
	ldr r0, _0222FB6C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #0xb
	str r0, [r5]
	b _0222FB2C
_0222F976:
	ldr r0, _0222FB78 ; =SEQ_SE_DP_CARD2
	bl PlaySE
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, _0222FB70 ; =0x00002BC4
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222ECEC
	ldr r0, _0222FB7C ; =0x00002BD4
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222ECD4
	mov r1, #1
	add r0, r4, #0
	lsl r2, r1, #0xc
	mov r3, #0x66
	bl ov74_0222F624
	mov r0, #7
	str r0, [r5]
	b _0222FB2C
_0222F9AA:
	bl ov74_0222F6C4
	cmp r0, #0
	beq _0222FA28
	mov r1, #1
	add r0, r4, #0
	add r2, r1, #0
	bl ov74_0222F024
	ldr r2, _0222FB80 ; =0x00708000
	add r0, r4, #0
	mov r1, #0
	lsr r3, r2, #1
	bl ov74_0222F624
	mov r0, #8
	str r0, [r5]
	b _0222FB2C
_0222F9CE:
	bl ov74_0222F6C4
	ldr r0, _0222FB68 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	beq _0222FA28
	ldr r0, _0222FB78 ; =SEQ_SE_DP_CARD2
	bl PlaySE
	mov r1, #1
	add r0, r4, #0
	lsl r2, r1, #0xc
	mov r3, #0x66
	bl ov74_0222F624
	mov r0, #9
	str r0, [r5]
	b _0222FB2C
_0222F9F4:
	bl ov74_0222F6C4
	cmp r0, #0
	beq _0222FA28
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov74_0222F024
	ldr r2, _0222FB80 ; =0x00708000
	add r0, r4, #0
	mov r1, #0
	lsr r3, r2, #1
	bl ov74_0222F624
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0xa
	str r0, [r5]
	b _0222FB2C
_0222FA20:
	bl ov74_0222F6C4
	cmp r0, #0
	bne _0222FA2A
_0222FA28:
	b _0222FB2C
_0222FA2A:
	ldr r0, _0222FB70 ; =0x00002BC4
	mov r1, #0
	add r0, r4, r0
	mov r2, #0x13
	mov r3, #0xa
	bl DrawFrameAndWindow2
	ldr r0, _0222FB7C ; =0x00002BD4
	mov r1, #0
	add r0, r4, r0
	mov r2, #0xa
	mov r3, #0xe
	bl DrawFrameAndWindow1
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	bl ov74_0222F688
	mov r0, #5
	str r0, [r5]
	b _0222FB2C
_0222FA5A:
	bl ov74_0222EDC0
	ldr r0, _0222FB70 ; =0x00002BC4
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222ECEC
	ldr r0, _0222FB70 ; =0x00002BC4
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222FB70 ; =0x00002BC4
	add r0, r4, r0
	bl RemoveWindow
	mov r0, #3
	str r0, [r5]
	b _0222FB2C
_0222FA7E:
	mov r1, #0
	mov r2, #0x15
	add r3, r5, #0
	bl ov74_0222EFF0
	b _0222FB2C
_0222FA8A:
	bl ov74_0222EC60
	ldr r0, _0222FB70 ; =0x00002BC4
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222ECEC
	ldr r0, _0222FB7C ; =0x00002BD4
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222ECD4
	add r0, r4, #0
	mov r1, #1
	mov r2, #0
	bl ov74_0222F024
	mov r1, #0x1e
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x55
	bl LoadFontPal0
	add r0, r4, #0
	mov r1, #1
	mov r2, #4
	add r3, r5, #0
	bl ov74_0222EFF0
	b _0222FB2C
_0222FAC6:
	bl sub_02037D78
	cmp r0, #0
	bne _0222FB2C
	ldr r0, _0222FB84 ; =0x00002BF8
	ldr r0, [r4, r0]
	str r0, [r5]
	b _0222FB2C
_0222FAD6:
	ldr r0, _0222FB68 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	beq _0222FB2C
	ldr r0, _0222FB70 ; =0x00002BC4
	mov r1, #0
	add r0, r4, r0
	bl ov74_0222ECEC
	ldr r0, _0222FB70 ; =0x00002BC4
	add r0, r4, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222FB70 ; =0x00002BC4
	add r0, r4, r0
	bl RemoveWindow
	mov r0, #3
	str r0, [r5]
	b _0222FB2C
_0222FB00:
	mov r1, #0
	mov r2, #0x1d
	add r3, r5, #0
	bl ov74_0222EFF0
	b _0222FB2C
_0222FB0C:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0222FB2C
	ldr r0, _0222FB84 ; =0x00002BF8
	ldr r0, [r4, r0]
	str r0, [r5]
	b _0222FB2C
_0222FB1C:
	bl ov74_0222EC60
	add r0, r4, #0
	bl ov74_0222F688
	add sp, #8
	mov r0, #1
	pop {r4, r5, r6, pc}
_0222FB2C:
	ldr r0, _0222FB88 ; =0x00002BFC
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222FB38
	bl SpriteList_RenderAndAnimateSprites
_0222FB38:
	bl ov74_022358BC
	mov r0, #0x3d
	lsl r0, r0, #8
	ldr r1, [r4, r0]
	cmp r1, #0
	beq _0222FB4A
	add r0, r4, #0
	blx r1
_0222FB4A:
	mov r0, #0
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0222FB50: .word 0x00002BA4
_0222FB54: .word 0x00002BA0
_0222FB58: .word 0x00002BA8
_0222FB5C: .word 0x00002BAC
_0222FB60: .word 0x00002BB4
_0222FB64: .word 0x000029FC
_0222FB68: .word gSystem
_0222FB6C: .word SEQ_SE_DP_SELECT
_0222FB70: .word 0x00002BC4
_0222FB74: .word 0x00002BE4
_0222FB78: .word SEQ_SE_DP_CARD2
_0222FB7C: .word 0x00002BD4
_0222FB80: .word 0x00708000
_0222FB84: .word 0x00002BF8
_0222FB88: .word 0x00002BFC
	thumb_func_end ov74_0222F7D4


	thumb_func_start ov74_0222FB8C
ov74_0222FB8C: ; 0x0222FB8C
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	bl OverlayManager_GetData
	add r7, r0, #0
	ldr r0, _0222FC38 ; =0x00002A08
	mov r6, #0
	add r4, r7, #0
	add r5, r7, r0
_0222FB9E:
	ldr r0, _0222FC38 ; =0x00002A08
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _0222FBB2
	add r0, r5, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r5, #0
	bl RemoveWindow
_0222FBB2:
	add r6, r6, #1
	add r4, #0x10
	add r5, #0x10
	cmp r6, #0xb
	blo _0222FB9E
	ldr r0, _0222FC3C ; =0x00002BC4
	ldr r1, [r7, r0]
	cmp r1, #0
	beq _0222FBD2
	add r0, r7, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222FC3C ; =0x00002BC4
	add r0, r7, r0
	bl RemoveWindow
_0222FBD2:
	ldr r0, _0222FC40 ; =0x00002BD4
	ldr r1, [r7, r0]
	cmp r1, #0
	beq _0222FBE8
	add r0, r7, r0
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, _0222FC40 ; =0x00002BD4
	add r0, r7, r0
	bl RemoveWindow
_0222FBE8:
	ldr r0, _0222FC44 ; =0x000029FC
	mov r1, #0
	ldr r0, [r7, r0]
	bl FreeBgTilemapBuffer
	ldr r0, _0222FC44 ; =0x000029FC
	mov r1, #1
	ldr r0, [r7, r0]
	bl FreeBgTilemapBuffer
	ldr r0, _0222FC44 ; =0x000029FC
	mov r1, #2
	ldr r0, [r7, r0]
	bl FreeBgTilemapBuffer
	ldr r0, _0222FC44 ; =0x000029FC
	mov r1, #3
	ldr r0, [r7, r0]
	bl FreeBgTilemapBuffer
	ldr r0, _0222FC44 ; =0x000029FC
	ldr r0, [r7, r0]
	bl Heap_Free
	ldr r0, _0222FC48 ; =FS_OVERLAY_ID(OVY_74)
	ldr r1, _0222FC4C ; =gApp_MainMenu_SelectOption_MysteryGift
	bl RegisterMainOverlay
	mov r0, #0x59
	bl Heap_Destroy
	ldr r0, [sp]
	bl OverlayManager_FreeData
	mov r0, #0x55
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222FC38: .word 0x00002A08
_0222FC3C: .word 0x00002BC4
_0222FC40: .word 0x00002BD4
_0222FC44: .word 0x000029FC
_0222FC48: .word FS_OVERLAY_ID(OVY_74)
_0222FC4C: .word gApp_MainMenu_SelectOption_MysteryGift
	thumb_func_end ov74_0222FB8C


	thumb_func_start ov74_0222FC50
ov74_0222FC50: ; 0x0222FC50
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	add r7, r1, #0
	add r5, r2, #0
	bl ov74_0222FCC4
	ldr r1, _0222FC98 ; =0x00003D0C
	add r0, r5, #0
	bl Heap_AllocAtEnd
	ldr r2, _0222FC98 ; =0x00003D0C
	mov r1, #0
	add r4, r0, #0
	bl memset
	ldr r0, _0222FC9C ; =0x000029FC
	mov r1, #0x1e
	str r6, [r4, r0]
	mov r0, #0
	lsl r1, r1, #4
	add r2, r5, #0
	str r5, [r4]
	bl LoadFontPal0
	ldr r0, _0222FCA0 ; =0x00002BB4
	mov r1, #1
	str r7, [r4, r0]
	add r0, r4, #0
	mov r2, #0
	bl ov74_0222F024
	add r0, r4, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222FC98: .word 0x00003D0C
_0222FC9C: .word 0x000029FC
_0222FCA0: .word 0x00002BB4
	thumb_func_end ov74_0222FC50


	thumb_func_start ov74_0222FCA4
ov74_0222FCA4: ; 0x0222FCA4
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _0222FCC0 ; =_0223B4B0
	add r3, sp, #0
	mov r2, #5
_0222FCAE:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0222FCAE
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_0222FCC0: .word _0223B4B0
	thumb_func_end ov74_0222FCA4


	thumb_func_start ov74_0222FCC4
ov74_0222FCC4: ; 0x0222FCC4
	push {r3, r4, r5, lr}
	sub sp, #0x80
	ldr r5, _0222FD84 ; =_0223B430
	add r3, sp, #0x70
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _0222FD88 ; =_0223B45C
	add r3, sp, #0x54
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #0
	str r0, [r3]
	add r0, r4, #0
	add r3, r1, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r5, _0222FD8C ; =_0223B494
	add r3, sp, #0x38
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #1
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	ldr r5, _0222FD90 ; =_0223B478
	add r3, sp, #0x1c
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #2
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r5, _0222FD94 ; =_0223B440
	add r3, sp, #0
	ldmia r5!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	mov r1, #3
	str r0, [r3]
	add r0, r4, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	add sp, #0x80
	pop {r3, r4, r5, pc}
	nop
_0222FD84: .word _0223B430
_0222FD88: .word _0223B45C
_0222FD8C: .word _0223B494
_0222FD90: .word _0223B478
_0222FD94: .word _0223B440
	thumb_func_end ov74_0222FCC4


	thumb_func_start ov74_0222FD98
ov74_0222FD98: ; 0x0222FD98
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	add r7, r0, #0
	bl Save_MysteryGift_Get
	mov r1, #0
	ldr r4, [r5, #0x48]
	mvn r1, r1
	add r6, r0, #0
	cmp r4, r1
	bne _0222FDCC
	add r2, r5, #0
	add r2, #0x4c
	ldrh r2, [r2]
	lsr r1, r1, #0x10
	cmp r2, r1
	bne _0222FDCC
	bl Save_MysteryGift_Init
	add r0, r7, #0
	mov r1, #0
	bl Save_NowWriteFile_AfterMGInit
	mov r0, #0
	bl OS_ResetSystem
_0222FDCC:
	add r0, r5, #0
	add r0, #0x4c
	ldrh r1, [r0]
	cmp r1, #0x64
	blo _0222FDE0
	cmp r1, #0x98
	bhi _0222FDE0
	mov r0, #0x46
	lsl r0, r0, #6
	orr r4, r0
_0222FDE0:
	cmp r4, #0
	bne _0222FDE8
	mov r4, #0
	mvn r4, r4
_0222FDE8:
#ifdef HEARTGOLD
	mov r0, #0x80
#else
	mov r0, #1
	lsl r0, r0, #8
#endif
	tst r0, r4
	bne _0222FDF2
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0222FDF2:
	add r0, r5, #0
	add r0, #0x4e
	ldrb r0, [r0]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0222FE0E
	add r0, r6, #0
	bl SaveMysteryGift_ReceivedFlagTest
	cmp r0, #1
	bne _0222FE0E
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_0222FE0E:
	add r0, r5, #0
	add r0, #0x4e
	ldrb r0, [r0]
	lsl r0, r0, #0x1d
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0222FE2A
	add r0, r6, #0
	bl SaveMysteryGift_CardFindAvailable
	cmp r0, #0
	bne _0222FE2A
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_0222FE2A:
	add r0, r6, #0
	bl SaveMysteryGift_FindAvailable
	cmp r0, #0
	bne _0222FE38
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_0222FE38:
	add r5, #0x4e
	ldrb r0, [r5]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _0222FE48
	mov r0, #5
	pop {r3, r4, r5, r6, r7, pc}
_0222FE48:
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_0222FD98


	thumb_func_start ov74_0222FE4C
ov74_0222FE4C: ; 0x0222FE4C
	push {r3, lr}
	mov r0, #4
	bl ov74_02231070
	bl ov74_02231724
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_0222FE4C


	thumb_func_start ov74_0222FE5C
ov74_0222FE5C: ; 0x0222FE5C
	push {r3, lr}
	bl ov74_022311F4
	str r0, [sp]
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_0222FE5C


	thumb_func_start ov74_0222FE68
ov74_0222FE68: ; 0x0222FE68
	push {r3, lr}
	bl ov74_02231214
	add r1, sp, #0
	strh r0, [r1]
	mov r0, #0
	ldrsh r0, [r1, r0]
	pop {r3, pc}
	thumb_func_end ov74_0222FE68


	thumb_func_start ov74_0222FE78
ov74_0222FE78: ; 0x0222FE78
	push {r4, lr}
	bl ov74_0223107C
	cmp r0, #0xc
	bne _0222FE9A
	bl ov74_0223105C
	add r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	bne _0222FE96
	bl ov74_02231724
	mov r0, #1
	str r0, [r4, #0x1c]
_0222FE96:
	mov r0, #1
	pop {r4, pc}
_0222FE9A:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222FE78


	thumb_func_start ov74_0222FEA0
ov74_0222FEA0: ; 0x0222FEA0
	push {r4, lr}
	add r4, r0, #0
	bl ov74_0223115C
	mov r3, #0
	add r1, r3, #0
_0222FEAC:
	ldr r2, [r0]
	cmp r2, #0
	beq _0222FEBC
	ldrh r2, [r0, #6]
	cmp r4, r2
	bne _0222FEBC
	strb r1, [r0, #8]
	strb r1, [r0, #0xa]
_0222FEBC:
	add r3, r3, #1
	add r0, #0xc
	cmp r3, #8
	blt _0222FEAC
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222FEA0


	thumb_func_start ov74_0222FEC8
ov74_0222FEC8: ; 0x0222FEC8
	push {r3, lr}
	bl ov74_0223115C
	add r1, r0, #0
	add r1, #0x62
	ldrh r3, [r1]
	mov r2, #1
	add r1, r3, #0
	tst r1, r2
	beq _0222FEEE
	add r1, r0, #0
	add r1, #0x62
	ldrh r3, [r1]
	mov r1, #1
	add r0, #0x62
	bic r3, r1
	strh r3, [r0]
	add r0, r2, #0
	pop {r3, pc}
_0222FEEE:
	mov r1, #0x40
	add r2, r3, #0
	tst r2, r1
	beq _0222FF08
	add r1, r0, #0
	add r1, #0x62
	ldrh r2, [r1]
	mov r1, #0x40
	add r0, #0x62
	bic r2, r1
	strh r2, [r0]
	mov r0, #7
	pop {r3, pc}
_0222FF08:
	lsl r1, r1, #6
	tst r1, r3
	beq _0222FF20
	add r1, r0, #0
	add r1, #0x62
	ldrh r2, [r1]
	ldr r1, _0222FF24 ; =0xFFFFEFFF
	add r0, #0x62
	and r1, r2
	strh r1, [r0]
	mov r0, #0xd
	pop {r3, pc}
_0222FF20:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_0222FF24: .word 0xFFFFEFFF
	thumb_func_end ov74_0222FEC8


	thumb_func_start ov74_0222FF28
ov74_0222FF28: ; 0x0222FF28
	push {r4, lr}
	bl ov74_0223115C
	add r4, r0, #0
	mov r1, #1
	add r0, #0x60
	strb r1, [r0]
	bl WM_GetAllowedChannel
	add r1, r4, #0
	add r1, #0x62
	strh r0, [r1]
	add r0, r4, #0
	add r0, #0x62
	ldrh r1, [r0]
	cmp r1, #0
	beq _0222FF52
	mov r0, #2
	lsl r0, r0, #0xe
	cmp r1, r0
	bne _0222FF56
_0222FF52:
	mov r0, #0
	pop {r4, pc}
_0222FF56:
	add r0, r4, #0
	mov r1, #0x66
	add r0, #0x61
	strb r1, [r0]
	mov r0, #0
	add r4, #0x64
	strb r0, [r4]
	mov r0, #1
	pop {r4, pc}
	thumb_func_end ov74_0222FF28


	thumb_func_start ov74_0222FF68
ov74_0222FF68: ; 0x0222FF68
	push {r4, lr}
	bl ov74_02231054
	add r4, r0, #0
	bl WM_GetDispersionBeaconPeriod
	strh r0, [r4, #0x18]
	bl WM_GetNextTgid
	strh r0, [r4, #0xc]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222FF68


	thumb_func_start ov74_0222FF80
ov74_0222FF80: ; 0x0222FF80
	push {r4, lr}
	bl ov74_022310C4
	add r4, r0, #0
	bl ov74_02231100
	str r0, [r4]
	bl ov74_02231054
	ldrh r0, [r0, #0x32]
	strh r0, [r4, #4]
	bl WM_GetDispersionScanPeriod
	strh r0, [r4, #6]
	mov r0, #0xff
	strb r0, [r4, #8]
	strb r0, [r4, #9]
	strb r0, [r4, #0xa]
	strb r0, [r4, #0xb]
	strb r0, [r4, #0xc]
	strb r0, [r4, #0xd]
	pop {r4, pc}
	thumb_func_end ov74_0222FF80


	thumb_func_start ov74_0222FFAC
ov74_0222FFAC: ; 0x0222FFAC
	push {r3, r4, r5, r6, r7, lr}
	bl ov74_022310C4
	add r7, r0, #0
	bl WM_GetAllowedChannel
	add r3, r0, #0
	beq _0222FFF8
	ldrh r2, [r7, #4]
	mov r1, #0
	mov r0, #1
	mov ip, r2
	mov r4, #0x1c
_0222FFC6:
	lsr r6, r2, #0x1f
	lsl r5, r2, #0x1c
	sub r5, r5, r6
	ror r5, r4
	add r5, r6, r5
	add r6, r0, #0
	lsl r6, r5
	add r5, r3, #0
	tst r5, r6
	beq _0222FFF0
	mov r0, ip
	add r0, r0, r1
	lsr r2, r0, #0x1f
	lsl r1, r0, #0x1c
	sub r1, r1, r2
	mov r0, #0x1c
	ror r1, r0
	add r0, r2, r1
	add r0, r0, #1
	strh r0, [r7, #4]
	pop {r3, r4, r5, r6, r7, pc}
_0222FFF0:
	add r1, r1, #1
	add r2, r2, #1
	cmp r1, #0x10
	blt _0222FFC6
_0222FFF8:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov74_0222FFAC


	thumb_func_start ov74_0222FFFC
ov74_0222FFFC: ; 0x0222FFFC
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #4]
	bl ov74_0223144C
	ldrh r0, [r4, #2]
	cmp r0, #8
	bne _02230014
	bl ov74_02231448
	bl ov74_0222FE4C
_02230014:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_0222FFFC


	thumb_func_start ov74_02230018
ov74_02230018: ; 0x02230018
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #8]
	bl ov74_0223144C
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _0223002C
	bl ov74_02231448
_0223002C:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_02230018


	thumb_func_start ov74_02230030
ov74_02230030: ; 0x02230030
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _02230066
	mov r0, #2
	bl ov74_02231070
	bl ov74_0223107C
	cmp r0, #0xc
	bne _02230052
	bl ov74_022314BC
	mov r0, #2
	bl ov74_02231070
	pop {r3, pc}
_02230052:
	bl ov74_022316E8
	cmp r0, #0
	bne _0223006E
	bl ov74_022314BC
	mov r0, #2
	bl ov74_02231070
	pop {r3, pc}
_02230066:
	bl ov74_02231448
	bl ov74_022314BC
_0223006E:
	pop {r3, pc}
	thumb_func_end ov74_02230030


	thumb_func_start ov74_02230070
ov74_02230070: ; 0x02230070
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _0223009A
	bl ov74_0223107C
	cmp r0, #0xc
	bne _02230092
	bl WM_Finish
	mov r0, #0xc
	bl ov74_02231070
	mov r0, #1
	bl ov74_0223113C
	pop {r3, pc}
_02230092:
	mov r0, #1
	bl ov74_02231070
	pop {r3, pc}
_0223009A:
	bl ov74_02231448
	mov r0, #4
	bl ov74_02231070
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_02230070


	thumb_func_start ov74_022300A8
ov74_022300A8: ; 0x022300A8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldrh r0, [r5, #2]
	cmp r0, #0
	bne _02230106
	bl ov74_0223115C
	add r4, r0, #0
	add r0, #0x61
	ldrh r1, [r5, #0xa]
	ldrb r0, [r0]
	cmp r0, r1
	ble _022300D0
	add r0, r4, #0
	add r0, #0x61
	strb r1, [r0]
	add r0, r4, #0
	ldrh r1, [r5, #8]
	add r0, #0x64
	strb r1, [r0]
_022300D0:
	bl ov74_0222FEC8
	cmp r0, #0
	beq _022300E6
	bl ov74_022314DC
	cmp r0, #0
	bne _0223010E
	bl ov74_0222FE4C
	pop {r3, r4, r5, pc}
_022300E6:
	add r4, #0x61
	ldrb r0, [r4]
	cmp r0, #0x66
	bhs _02230100
	bl ov74_0222FF68
	bl ov74_02231508
	cmp r0, #0
	bne _0223010E
	bl ov74_0222FE4C
	pop {r3, r4, r5, pc}
_02230100:
	bl ov74_0222FE4C
	pop {r3, r4, r5, pc}
_02230106:
	bl ov74_02231448
	bl ov74_0222FE4C
_0223010E:
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_022300A8


	thumb_func_start ov74_02230110
ov74_02230110: ; 0x02230110
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _0223012E
	bl ov74_0222FE78
	cmp r0, #0
	bne _02230136
	bl ov74_02231544
	cmp r0, #0
	bne _02230136
	bl ov74_0222FE4C
	pop {r3, pc}
_0223012E:
	bl ov74_02231448
	bl ov74_0222FE4C
_02230136:
	pop {r3, pc}
	thumb_func_end ov74_02230110


	thumb_func_start ov74_02230138
ov74_02230138: ; 0x02230138
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldrh r0, [r5, #8]
	bl ov74_0223144C
	ldrh r0, [r5, #2]
	cmp r0, #0
	beq _0223014C
	b _0223025E
_0223014C:
	bl ov74_0223115C
	add r4, r0, #0
	mov r0, #8
	bl ov74_02231070
	bl ov74_0222FE78
	cmp r0, #0
	beq _02230162
	b _02230266
_02230162:
	add r0, r4, #0
	add r0, #0x60
	ldrb r0, [r0]
	cmp r0, #1
	bne _02230174
	add r0, r4, #0
	mov r1, #2
	add r0, #0x60
	strb r1, [r0]
_02230174:
	ldrh r0, [r5, #8]
	cmp r0, #7
	bgt _0223018C
	bge _022301AE
	cmp r0, #2
	bgt _02230266
	cmp r0, #0
	blt _02230266
	beq _02230194
	add sp, #0xc
	cmp r0, #2
	pop {r4, r5, pc}
_0223018C:
	cmp r0, #9
	beq _02230254
	add sp, #0xc
	pop {r4, r5, pc}
_02230194:
	bl ov74_02231670
	cmp r0, #0
	bne _022301A4
	bl ov74_0222FE4C
	add sp, #0xc
	pop {r4, r5, pc}
_022301A4:
	mov r0, #0
	bl ov74_0223110C
	add sp, #0xc
	pop {r4, r5, pc}
_022301AE:
	bl ov74_0223115C
	bl ov74_02231458
	add r4, #0x60
	ldrb r0, [r4]
	cmp r0, #2
	bne _02230266
	add r4, r5, #0
	add r4, #0x14
	bl ov74_022311AC
	ldr r1, [r5, #0x14]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, r0
	bne _02230266
	bl ov74_022311BC
	ldr r1, [r4]
	lsl r1, r1, #0x14
	lsr r1, r1, #0x1c
	cmp r1, r0
	bhi _02230266
	bl ov74_022311CC
	ldr r1, [r4, #4]
	lsr r1, r1, #0x10
	cmp r1, r0
	bne _02230266
	bl ov74_0223115C
	add r4, r0, #0
	add r0, r5, #0
	add r0, #0xa
	bl ov74_0222FE5C
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0xa
	bl ov74_0222FE68
	add r1, sp, #0
	strh r0, [r1]
	ldrh r0, [r1]
	ldr r2, [sp, #8]
	add r3, r4, #0
	strh r0, [r1, #2]
	mov r0, #0
_02230212:
	ldr r1, [r3]
	cmp r1, r2
	bne _0223022A
	mov r1, #0xc
	mul r1, r0
	ldrh r0, [r5, #0x10]
	add r1, r4, r1
	add sp, #0xc
	strh r0, [r1, #6]
	mov r0, #1
	strb r0, [r1, #0xa]
	pop {r4, r5, pc}
_0223022A:
	cmp r1, #0
	bne _02230248
	mov r1, #0xc
	mul r1, r0
	str r2, [r4, r1]
	add r0, sp, #0
	ldrh r0, [r0, #2]
	add r1, r4, r1
	add sp, #0xc
	strh r0, [r1, #4]
	ldrh r0, [r5, #0x10]
	strh r0, [r1, #6]
	mov r0, #1
	strb r0, [r1, #0xa]
	pop {r4, r5, pc}
_02230248:
	add r0, r0, #1
	add r3, #0xc
	cmp r0, #8
	blt _02230212
	add sp, #0xc
	pop {r4, r5, pc}
_02230254:
	ldrh r0, [r5, #0x10]
	bl ov74_0222FEA0
	add sp, #0xc
	pop {r4, r5, pc}
_0223025E:
	bl ov74_02231448
	bl ov74_0222FE4C
_02230266:
	add sp, #0xc
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov74_02230138


	thumb_func_start ov74_0223026C
ov74_0223026C: ; 0x0223026C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	str r0, [sp]
	bl ov74_02231154
	add r7, r0, #0
	add r0, r4, #4
	bl ov74_0222FE5C
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, r4, #4
	bl ov74_0222FE68
	add r2, sp, #4
	strh r0, [r2]
	ldrh r0, [r2]
	ldr r6, [sp, #0xc]
	add r1, r7, #0
	strh r0, [r2, #2]
	ldrh r3, [r2, #2]
	mov r0, #0
_0223029A:
	ldr r2, [r1]
	add r5, r1, #0
	add r5, #0x34
	cmp r2, r6
	bne _022302B0
	ldrh r5, [r5]
	cmp r5, r3
	bne _022302B0
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_022302B0:
	cmp r2, #0
	bne _022302FC
	mov r1, #0x38
	mul r1, r0
	ldr r0, [sp, #0xc]
	add r5, r4, #0
	str r0, [r7, r1]
	add r0, r7, r1
	add r5, #0x58
	add r3, r0, #4
	mov r2, #0xc
_022302C6:
	ldrh r0, [r5]
	add r5, r5, #2
	strh r0, [r3]
	add r3, r3, #2
	sub r2, r2, #1
	bne _022302C6
	add r3, r7, r1
	add r4, #0x70
	add r3, #0x1c
	mov r2, #0xc
_022302DA:
	ldrh r0, [r4]
	add r4, r4, #2
	strh r0, [r3]
	add r3, r3, #2
	sub r2, r2, #1
	bne _022302DA
	add r0, sp, #4
	ldrh r0, [r0, #2]
	add r1, r7, r1
	strh r0, [r1, #0x34]
	ldr r0, [sp]
	add r1, #0x36
	ldrh r0, [r0, #0x12]
	add sp, #0x10
	strb r0, [r1]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_022302FC:
	add r0, r0, #1
	add r1, #0x38
	cmp r0, #8
	blt _0223029A
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov74_0223026C


	thumb_func_start ov74_0223030C
ov74_0223030C: ; 0x0223030C
	push {r3, lr}
	bl ov74_0222FFAC
	bl ov74_02231560
	cmp r0, #0
	bne _0223031E
	bl ov74_0222FE4C
_0223031E:
	pop {r3, pc}
	thumb_func_end ov74_0223030C


	thumb_func_start ov74_02230320
ov74_02230320: ; 0x02230320
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bl ov74_02231100
	add r4, r0, #0
	bl ov74_02231154
	add r5, r0, #0
	bl ov74_0222FE78
	cmp r0, #0
	beq _0223033C
	mov r0, #1
	pop {r4, r5, r6, pc}
_0223033C:
	mov r1, #0
	add r2, r1, #0
	add r3, r5, #0
_02230342:
	ldr r0, [r3]
	cmp r0, #0
	beq _0223034C
	mov r1, #1
	b _02230354
_0223034C:
	add r2, r2, #1
	add r3, #0x38
	cmp r2, #8
	blt _02230342
_02230354:
	cmp r1, #0
	beq _02230372
	mov r0, #7
	lsl r0, r0, #6
	ldrh r0, [r5, r0]
	cmp r0, #0
	bne _02230372
	bl ov74_0223161C
	cmp r0, #0
	bne _0223036E
	bl ov74_0222FE4C
_0223036E:
	mov r0, #1
	pop {r4, r5, r6, pc}
_02230372:
	add r0, r4, #0
	mov r1, #0xc0
	bl DC_InvalidateRange
	bl ov74_02231154
	bl ov74_02231454
	ldrh r0, [r6, #0x36]
	cmp r0, #8
	blo _022303FC
	bl ov74_022311A0
	ldr r1, [r4, #0x44]
	cmp r1, r0
	bne _022303FC
	add r5, r4, #0
	add r5, #0x50
	bl ov74_022311AC
	ldr r1, [r4, #0x50]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, r0
	bne _022303FC
	bl ov74_022311BC
	ldr r1, [r5]
	lsl r1, r1, #0x14
	lsr r1, r1, #0x1c
	cmp r1, r0
	bhi _022303FC
	bl ov74_022311CC
	ldr r1, [r5, #4]
	lsr r1, r1, #0x10
	cmp r1, r0
	bne _022303FC
	add r0, r6, #0
	add r1, r4, #0
	bl ov74_0223026C
	cmp r0, #0
	beq _022303EC
	bl ov74_02231154
	ldr r1, _02230400 ; =0x000001C2
	ldrb r2, [r0, r1]
	add r2, r2, #1
	strb r2, [r0, r1]
	ldrb r0, [r0, r1]
	cmp r0, #0x1c
	bls _022303FC
	bl ov74_0223161C
	cmp r0, #0
	bne _022303FC
	bl ov74_0222FE4C
	mov r0, #1
	pop {r4, r5, r6, pc}
_022303EC:
	bl ov74_0223161C
	cmp r0, #0
	bne _022303F8
	bl ov74_0222FE4C
_022303F8:
	mov r0, #1
	pop {r4, r5, r6, pc}
_022303FC:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02230400: .word 0x000001C2
	thumb_func_end ov74_02230320


	thumb_func_start ov74_02230404
ov74_02230404: ; 0x02230404
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #8]
	bl ov74_0223144C
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne _0223046A
	bl ov74_02231100
	bl ov74_02231450
	mov r0, #6
	bl ov74_02231070
	bl ov74_0222FE78
	cmp r0, #0
	bne _02230472
	bl ov74_02231094
	cmp r0, #1
	bne _02230444
	bl ov74_02231154
	ldr r2, _02230474 ; =0x000001C3
	mov r1, #0xf0
	ldrb r3, [r0, r2]
	bic r3, r1
	mov r1, #0x10
	orr r1, r3
	strb r1, [r0, r2]
_02230444:
	ldrh r0, [r4, #8]
	cmp r0, #4
	beq _02230458
	cmp r0, #5
	bne _0223045E
	add r0, r4, #0
	bl ov74_02230320
	cmp r0, #0
	bne _02230472
_02230458:
	bl ov74_0223030C
	pop {r4, pc}
_0223045E:
	ldrh r0, [r4, #2]
	bl ov74_02231448
	bl ov74_0222FE4C
	pop {r4, pc}
_0223046A:
	bl ov74_02231448
	bl ov74_0222FE4C
_02230472:
	pop {r4, pc}
	.balign 4, 0
_02230474: .word 0x000001C3
	thumb_func_end ov74_02230404


	thumb_func_start ov74_02230478
ov74_02230478: ; 0x02230478
	push {r4, r5, r6, lr}
	sub sp, #8
	bl ov74_02231100
	add r4, r0, #0
	bl ov74_02231154
	add r6, r0, #0
	bl ov74_02231054
	bl ov74_0222FE78
	cmp r0, #0
	beq _0223049A
	add sp, #8
	mov r0, #1
	pop {r4, r5, r6, pc}
_0223049A:
	add r0, r4, #0
	mov r1, #0xc0
	bl DC_InvalidateRange
	bl ov74_02231154
	bl ov74_02231454
	ldrh r0, [r4, #0x3c]
	cmp r0, #8
	blo _02230514
	bl ov74_022311A0
	ldr r1, [r4, #0x44]
	cmp r1, r0
	bne _02230514
	add r5, r4, #0
	add r5, #0x50
	bl ov74_022311AC
	ldr r1, [r4, #0x50]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, r0
	bne _02230514
	bl ov74_022311BC
	ldr r1, [r5]
	lsl r1, r1, #0x14
	lsr r1, r1, #0x1c
	cmp r1, r0
	bhi _02230514
	bl ov74_022311CC
	ldr r1, [r5, #4]
	lsr r1, r1, #0x10
	cmp r1, r0
	bne _02230514
	add r0, r4, #4
	bl ov74_0222FE5C
	ldr r1, _0223051C ; =0x000001C3
	str r0, [sp]
	ldrb r1, [r6, r1]
	str r0, [sp, #4]
	lsl r1, r1, #0x1c
	lsr r2, r1, #0x1c
	mov r1, #0x38
	mul r1, r2
	ldr r1, [r6, r1]
	cmp r1, r0
	bne _02230514
	bl ov74_0223161C
	cmp r0, #0
	bne _0223050E
	bl ov74_0222FE4C
_0223050E:
	add sp, #8
	mov r0, #1
	pop {r4, r5, r6, pc}
_02230514:
	mov r0, #0
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_0223051C: .word 0x000001C3
	thumb_func_end ov74_02230478


	thumb_func_start ov74_02230520
ov74_02230520: ; 0x02230520
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #8]
	bl ov74_0223144C
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne _02230580
	bl ov74_02231154
	ldr r2, _0223058C ; =0x000001C3
	mov r1, #0xf0
	ldrb r3, [r0, r2]
	bic r3, r1
	mov r1, #0x20
	orr r1, r3
	strb r1, [r0, r2]
	mov r0, #6
	bl ov74_02231070
	bl ov74_0222FE78
	cmp r0, #0
	bne _02230588
	ldrh r0, [r4, #8]
	cmp r0, #4
	beq _02230562
	cmp r0, #5
	bne _02230574
	bl ov74_02230478
	cmp r0, #0
	bne _02230588
_02230562:
	bl ov74_0222FFAC
	bl ov74_02231584
	cmp r0, #0
	bne _02230588
	bl ov74_0222FE4C
	pop {r4, pc}
_02230574:
	ldrh r0, [r4, #2]
	bl ov74_02231448
	bl ov74_0222FE4C
	pop {r4, pc}
_02230580:
	bl ov74_02231448
	bl ov74_0222FE4C
_02230588:
	pop {r4, pc}
	nop
_0223058C: .word 0x000001C3
	thumb_func_end ov74_02230520


	thumb_func_start ov74_02230590
ov74_02230590: ; 0x02230590
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _022305D4
	mov r0, #7
	bl ov74_02231070
	bl ov74_0222FE78
	cmp r0, #0
	bne _022305DC
	bl ov74_02231094
	cmp r0, #1
	bne _022305DC
	bl ov74_02231154
	ldr r1, _022305E0 ; =0x000001C3
	ldrb r0, [r0, r1]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	cmp r0, #2
	bne _022305DC
	bl ov74_02231638
	cmp r0, #0
	bne _022305CC
	bl ov74_0222FE4C
	pop {r3, pc}
_022305CC:
	mov r0, #3
	bl ov74_02231070
	pop {r3, pc}
_022305D4:
	bl ov74_02231448
	bl ov74_0222FE4C
_022305DC:
	pop {r3, pc}
	nop
_022305E0: .word 0x000001C3
	thumb_func_end ov74_02230590


	thumb_func_start ov74_022305E4
ov74_022305E4: ; 0x022305E4
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #8]
	bl ov74_0223144C
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne _0223066A
	mov r0, #9
	bl ov74_02231070
	bl ov74_0222FE78
	cmp r0, #0
	bne _02230672
	ldrh r0, [r4, #8]
	cmp r0, #9
	bhi _0223065E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02230614: ; jump table
	.short _0223065E - _02230614 - 2 ; case 0
	.short _0223065E - _02230614 - 2 ; case 1
	.short _0223065E - _02230614 - 2 ; case 2
	.short _0223065E - _02230614 - 2 ; case 3
	.short _0223065E - _02230614 - 2 ; case 4
	.short _0223065E - _02230614 - 2 ; case 5
	.short _02230672 - _02230614 - 2 ; case 6
	.short _02230628 - _02230614 - 2 ; case 7
	.short _02230672 - _02230614 - 2 ; case 8
	.short _02230648 - _02230614 - 2 ; case 9
_02230628:
	ldrh r0, [r4, #0xa]
	bl ov74_0223110C
	mov r0, #1
	bl ov74_02231124
	mov r0, #0
	bl ov74_02231130
	bl ov74_02231670
	cmp r0, #0
	bne _02230672
	bl ov74_0222FE4C
	pop {r4, pc}
_02230648:
	bl ov74_02231118
	cmp r0, #0
	beq _02230656
	mov r0, #1
	bl ov74_02231130
_02230656:
	mov r0, #0
	bl ov74_02231124
	pop {r4, pc}
_0223065E:
	ldrh r0, [r4, #2]
	bl ov74_02231448
	bl ov74_0222FE4C
	pop {r4, pc}
_0223066A:
	bl ov74_02231448
	bl ov74_0222FE4C
_02230672:
	pop {r4, pc}
	thumb_func_end ov74_022305E4


	thumb_func_start ov74_02230674
ov74_02230674: ; 0x02230674
	push {r3, lr}
	bl ov74_02231094
	cmp r0, #1
	beq _022306AE
	cmp r0, #2
	bne _022306C6
	bl ov74_0222FF28
	cmp r0, #0
	beq _022306A8
	bl ov74_0222FEC8
	bl ov74_022314DC
	cmp r0, #0
	beq _022306A8
	bl ov74_0223115C
	mov r1, #1
	add r0, #0x60
	strb r1, [r0]
	mov r0, #3
	bl ov74_02231070
	pop {r3, pc}
_022306A8:
	bl ov74_0222FE4C
	pop {r3, pc}
_022306AE:
	bl ov74_0222FF80
	bl ov74_02231560
	cmp r0, #0
	bne _022306C0
	bl ov74_0222FE4C
	pop {r3, pc}
_022306C0:
	mov r0, #3
	bl ov74_02231070
_022306C6:
	pop {r3, pc}
	thumb_func_end ov74_02230674


	thumb_func_start ov74_022306C8
ov74_022306C8: ; 0x022306C8
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #4]
	bl ov74_0223144C
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne _02230702
	ldrh r0, [r4]
	cmp r0, #0xe
	bne _022306E6
	bl ov74_0222FE78
	cmp r0, #0
	bne _02230712
_022306E6:
	bl ov74_02231094
	cmp r0, #1
	beq _022306FA
	cmp r0, #2
	bne _02230712
	mov r0, #0xa
	bl ov74_02231070
	pop {r4, pc}
_022306FA:
	mov r0, #0xb
	bl ov74_02231070
	pop {r4, pc}
_02230702:
	cmp r0, #9
	beq _02230712
	cmp r0, #0xd
	beq _02230712
	cmp r0, #0xf
	beq _02230712
	bl ov74_0222FE4C
_02230712:
	pop {r4, pc}
	thumb_func_end ov74_022306C8


	thumb_func_start ov74_02230714
ov74_02230714: ; 0x02230714
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bl ov74_02231184
	add r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bne _0223078A
	ldrh r1, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r5, [r4, #0xc]
	bl DC_FlushRange
	ldrh r2, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, [r4, #0xc]
	bl MI_CpuCopy8
	bl ov74_022311AC
	ldr r1, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, r0
	bne _0223078A
	bl ov74_022311BC
	ldr r1, [r5]
	lsl r1, r1, #0x14
	lsr r1, r1, #0x1c
	cmp r1, r0
	bhi _0223078A
	ldr r0, [r4, #0xc]
	bl ov74_022313F0
	ldr r0, [r5, #8]
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldrb r0, [r4, #0x1c]
	cmp r1, r0
	bne _0223078A
	ldr r0, [r4, #0xc]
	bl ov74_0223145C
	ldr r0, [r4, #0xc]
	bl ov74_02231424
	cmp r0, #0
	beq _02230786
	ldr r0, [r5, #8]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x18
	cmp r0, #1
	beq _02230786
	mov r0, #2
	strb r0, [r4, #0x19]
	pop {r4, r5, r6, pc}
_02230786:
	mov r0, #0
	strb r0, [r4, #0x19]
_0223078A:
	pop {r4, r5, r6, pc}
	thumb_func_end ov74_02230714


	thumb_func_start ov74_0223078C
ov74_0223078C: ; 0x0223078C
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bl ov74_02231184
	add r4, r0, #0
	bl ov74_02231094
	cmp r0, #2
	bne _02230814
	ldrb r0, [r4, #0x19]
	cmp r0, #2
	beq _02230814
	ldrh r1, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r5, [r4, #0xc]
	bl DC_FlushRange
	ldrh r2, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, [r4, #0xc]
	bl MI_CpuCopy8
	bl ov74_022311AC
	ldr r1, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, r0
	bne _02230814
	bl ov74_022311BC
	ldr r1, [r5]
	lsl r1, r1, #0x14
	lsr r1, r1, #0x1c
	cmp r1, r0
	bhi _02230814
	ldr r0, [r4, #0xc]
	bl ov74_022313F0
	ldr r0, [r5, #8]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #0xfd
	bne _02230814
	bl ov74_0223115C
	ldrh r5, [r6, #0x12]
	mov r2, #0
	add r3, r0, #0
_022307EE:
	ldrh r1, [r3, #6]
	cmp r5, r1
	bne _0223080C
	mov r1, #0xc
	mul r1, r2
	add r1, r0, r1
	mov r2, #1
	strb r2, [r1, #8]
	mov r0, #3
	strb r0, [r1, #9]
	mov r0, #0xb4
	strb r0, [r4, #0x1a]
	mov r0, #0
	strb r0, [r4, #0x19]
	pop {r4, r5, r6, pc}
_0223080C:
	add r2, r2, #1
	add r3, #0xc
	cmp r2, #8
	blt _022307EE
_02230814:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov74_0223078C


	thumb_func_start ov74_02230818
ov74_02230818: ; 0x02230818
	push {r4, r5, r6, lr}
	add r6, r0, #0
	bl ov74_02231184
	add r4, r0, #0
	ldrb r0, [r4, #0x1c]
	cmp r0, #0xfd
	bne _02230830
	add r0, r6, #0
	bl ov74_0223078C
	pop {r4, r5, r6, pc}
_02230830:
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	beq _0223083C
	ldrb r0, [r4, #0x19]
	cmp r0, #3
	bne _022308D8
_0223083C:
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _022308D8
	ldrh r1, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r5, [r4, #0xc]
	bl DC_FlushRange
	ldrh r2, [r6, #0x10]
	ldr r0, [r6, #0xc]
	ldr r1, [r4, #0xc]
	bl MI_CpuCopy8
	bl ov74_022311AC
	ldr r1, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	cmp r1, r0
	bne _022308D8
	bl ov74_022311BC
	ldr r1, [r5]
	lsl r1, r1, #0x14
	lsr r1, r1, #0x1c
	cmp r1, r0
	bhi _022308D8
	ldr r0, [r4, #0xc]
	bl ov74_022313F0
	ldr r0, [r5, #8]
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldrb r0, [r4, #0x1c]
	cmp r1, r0
	bne _022308D8
	ldr r0, [r4, #0xc]
	bl ov74_0223145C
	mov r0, #0
	strb r0, [r4, #0x19]
	ldr r0, [r4, #0xc]
	bl ov74_02231424
	cmp r0, #0
	beq _022308CA
	ldr r0, [r5, #8]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r0, #0xfd
	bne _022308AA
	add r0, r6, #0
	bl ov74_0223078C
	b _022308BC
_022308AA:
	ldr r2, [r5, #0xc]
	ldr r1, [r4, #0xc]
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	add r0, r1, r0
	ldr r1, [r4, #4]
	lsr r2, r2, #8
	bl MI_CpuCopy8
_022308BC:
	ldr r1, [r5, #8]
	ldr r0, _022308DC ; =0xFFFF00FF
	and r0, r1
	str r0, [r5, #8]
	mov r0, #4
	strb r0, [r4, #0x1b]
	pop {r4, r5, r6, pc}
_022308CA:
	ldr r1, [r5, #8]
	ldr r0, _022308DC ; =0xFFFF00FF
	and r1, r0
	mov r0, #1
	lsl r0, r0, #8
	orr r0, r1
	str r0, [r5, #8]
_022308D8:
	pop {r4, r5, r6, pc}
	nop
_022308DC: .word 0xFFFF00FF
	thumb_func_end ov74_02230818


	thumb_func_start ov74_022308E0
ov74_022308E0: ; 0x022308E0
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #4]
	bl ov74_0223144C
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne _02230962
	ldrh r0, [r4, #4]
	cmp r0, #7
	beq _0223092A
	cmp r0, #9
	beq _02230938
	cmp r0, #0x15
	bne _02230962
	bl ov74_02231064
	cmp r0, #0xa
	beq _0223090A
	cmp r0, #0xb
	bne _02230962
_0223090A:
	bl ov74_02231184
	ldrb r0, [r0, #0x18]
	cmp r0, #1
	beq _0223091A
	cmp r0, #2
	beq _02230922
	pop {r4, pc}
_0223091A:
	add r0, r4, #0
	bl ov74_02230714
	pop {r4, pc}
_02230922:
	add r0, r4, #0
	bl ov74_02230818
	pop {r4, pc}
_0223092A:
	mov r0, #1
	bl ov74_02231124
	mov r0, #0
	bl ov74_02231130
	pop {r4, pc}
_02230938:
	bl ov74_02231118
	cmp r0, #0
	beq _02230946
	mov r0, #1
	bl ov74_02231130
_02230946:
	bl ov74_02231064
	cmp r0, #0xa
	beq _02230954
	cmp r0, #0xb
	beq _0223095C
	pop {r4, pc}
_02230954:
	ldrh r0, [r4, #0x12]
	bl ov74_0222FEA0
	pop {r4, pc}
_0223095C:
	mov r0, #0
	bl ov74_02231124
_02230962:
	pop {r4, pc}
	thumb_func_end ov74_022308E0


	thumb_func_start ov74_02230964
ov74_02230964: ; 0x02230964
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _0223097A
	bl ov74_0222FE78
	cmp r0, #0
	bne _02230984
	bl ov74_02230674
	pop {r3, pc}
_0223097A:
	bl ov74_02231448
	mov r0, #4
	bl ov74_02231070
_02230984:
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_02230964


	thumb_func_start ov74_02230988
ov74_02230988: ; 0x02230988
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _022309A0
	bl ov74_022314BC
	cmp r0, #0
	beq _022309A8
	mov r0, #2
	bl ov74_02231070
	pop {r3, pc}
_022309A0:
	bl ov74_02231448
	bl ov74_0222FE4C
_022309A8:
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_02230988


	thumb_func_start ov74_022309AC
ov74_022309AC: ; 0x022309AC
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _022309E2
	mov r0, #0
	bl ov74_0223110C
	bl ov74_0223107C
	cmp r0, #0xc
	bne _022309D2
	bl ov74_02231744
	cmp r0, #0
	beq _022309EC
	mov r0, #3
	bl ov74_02231070
	pop {r3, pc}
_022309D2:
	bl ov74_02231704
	cmp r0, #0
	beq _022309EC
	mov r0, #3
	bl ov74_02231070
	pop {r3, pc}
_022309E2:
	bl ov74_02231448
	mov r0, #4
	bl ov74_02231070
_022309EC:
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_022309AC


	thumb_func_start ov74_022309F0
ov74_022309F0: ; 0x022309F0
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	bne _02230A06
	mov r0, #0xc
	bl ov74_02231070
	mov r0, #1
	bl ov74_0223113C
	pop {r3, pc}
_02230A06:
	bl ov74_02231448
	mov r0, #4
	bl ov74_02231070
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_022309F0


	thumb_func_start ov74_02230A14
ov74_02230A14: ; 0x02230A14
	push {r3, lr}
	ldr r0, _02230A30 ; =ov74_0222FFFC
	bl WM_SetIndCallback
	cmp r0, #0
	beq _02230A2A
	mov r0, #4
	bl ov74_02231070
	mov r0, #0
	pop {r3, pc}
_02230A2A:
	mov r0, #1
	pop {r3, pc}
	nop
_02230A30: .word ov74_0222FFFC
	thumb_func_end ov74_02230A14


	thumb_func_start ov74_02230A34
ov74_02230A34: ; 0x02230A34
	push {r3, lr}
	bl ov74_02231064
	cmp r0, #0
	beq _02230A46
	cmp r0, #1
	beq _02230A46
	cmp r0, #2
	bne _02230A4A
_02230A46:
	bl ov74_022314A0
_02230A4A:
	pop {r3, pc}
	thumb_func_end ov74_02230A34


	thumb_func_start ov74_02230A4C
ov74_02230A4C: ; 0x02230A4C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	bl ov74_02231054
	ldrh r0, [r0, #0x34]
	cmp r4, r0
	bhi _02230A70
	add r0, r5, #0
	add r1, r4, #0
	bl DC_FlushRange
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl ov74_02231460
_02230A70:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov74_02230A4C


	thumb_func_start ov74_02230A74
ov74_02230A74: ; 0x02230A74
	mov r0, #0x17
	lsl r0, r0, #6
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02230A74


	thumb_func_start ov74_02230A7C
ov74_02230A7C: ; 0x02230A7C
	mov r0, #0x17
	lsl r0, r0, #6
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02230A7C


	thumb_func_start ov74_02230A84
ov74_02230A84: ; 0x02230A84
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	add r5, r0, #0
	bl ov74_02231054
	bl ov74_0223105C
	add r4, r0, #0
	mov r0, #0x1f
	add r1, r7, #0
	and r1, r0
	beq _02230AA2
	mov r0, #0x20
	sub r0, r0, r1
	add r7, r7, r0
_02230AA2:
	mov r1, #0
	strb r1, [r4]
	strb r1, [r4, #1]
	strb r1, [r4, #2]
	mov r0, #4
	strb r0, [r4, #3]
	ldr r0, _02230BA8 ; =0x00400131
	str r0, [r4, #4]
	mov r0, #0xf
	strh r1, [r4, #0xc]
	lsl r0, r0, #8
	str r7, [r4, #0x34]
	add r7, r7, r0
	str r7, [r4, #0x38]
	bl ov74_02230A74
	str r0, [r4, #0x2c]
	add r7, r7, r0
	str r7, [r4, #0x3c]
	bl ov74_02230A7C
	add r7, r7, r0
	str r0, [r4, #0x30]
	add r0, r7, #0
	str r7, [r4, #0x28]
	add r0, #0xc0
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x34]
	mov r1, #2
	add r7, #0xe0
	bl WM_Init
	bl ov74_02230A14
	str r0, [r4, #0x10]
	mov r2, #0
	str r2, [r4, #0x14]
	str r2, [r4, #0x18]
	str r2, [r4, #0x1c]
	str r2, [r4, #0x20]
	ldr r0, [r4, #0x40]
	mov r6, #0xff
	bic r0, r6
	add r3, r0, #0
	mov r1, #0xf
	orr r3, r1
	ldr r0, _02230BAC ; =0xFFFFF0FF
	add r1, #0xf1
	and r0, r3
	orr r1, r0
	ldr r0, _02230BB0 ; =0xFFFF0FFF
	and r1, r0
	mov r0, #1
	lsl r0, r0, #0xc
	orr r0, r1
	str r0, [r4, #0x40]
	ldr r3, [r5]
	ldr r1, [r4, #0x44]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	lsl r3, r3, #0x18
	add r0, r4, #0
	bic r1, r6
	lsr r3, r3, #0x18
	orr r3, r1
	ldr r1, _02230BAC ; =0xFFFFF0FF
	str r3, [r4, #0x44]
	and r1, r3
	ldr r3, [r5]
	add r0, #0x44
	lsl r3, r3, #0x14
	lsr r3, r3, #0x1c
	lsl r3, r3, #0x1c
	lsr r3, r3, #0x14
	orr r3, r1
	ldr r1, _02230BB0 ; =0xFFFF0FFF
	str r3, [r4, #0x44]
	and r1, r3
	ldr r3, [r5]
	lsl r3, r3, #0x10
	lsr r3, r3, #0x1c
	lsl r3, r3, #0x1c
	lsr r3, r3, #0x10
	orr r1, r3
	str r1, [r4, #0x44]
	ldr r1, [r0]
	ldr r3, [r5]
	lsl r1, r1, #0x10
	lsr r3, r3, #0x10
	lsr r1, r1, #0x10
	lsl r3, r3, #0x10
	orr r1, r3
	str r1, [r0]
	ldr r0, [r5, #8]
	ldr r1, [r5, #4]
	add r3, r4, #0
	b _02230B7C
_02230B64:
	ldrh r6, [r0]
	add r5, r3, #0
	add r5, #0x48
	strh r6, [r5]
	add r5, r3, #0
	ldrh r6, [r1]
	add r5, #0x60
	add r3, r3, #2
	strh r6, [r5]
	add r2, r2, #1
	add r0, r0, #2
	add r1, r1, #2
_02230B7C:
	cmp r0, #0
	beq _02230B84
	cmp r2, #0xc
	blo _02230B64
_02230B84:
	ldr r1, [r4, #0x40]
	ldr r0, [r4, #0x44]
	str r1, [r4, #0x78]
	str r0, [r4, #0x7c]
	bl ov74_02231194
	bl ov74_02231184
	str r7, [r0, #8]
	ldr r0, [r4, #0x2c]
	add r7, r7, r0
	bl ov74_02231184
	str r7, [r0, #0xc]
	bl WM_GetNextTgid
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02230BA8: .word 0x00400131
_02230BAC: .word 0xFFFFF0FF
_02230BB0: .word 0xFFFF0FFF
	thumb_func_end ov74_02230A84


	thumb_func_start ov74_02230BB4
ov74_02230BB4: ; 0x02230BB4
	push {r3, r4, r5, lr}
	bl ov74_02231184
	add r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bne _02230BD2
	ldrb r0, [r4, #0x1a]
	sub r0, r0, #1
	strb r0, [r4, #0x1a]
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	bne _02230C08
	mov r0, #0
	strb r0, [r4, #0x19]
_02230BD2:
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	bne _02230C08
	bl ov74_02231260
	mov r1, #0x40
	sub r5, r1, r0
	ldrb r0, [r4, #0x1c]
	add r2, r5, #0
	mov r3, #3
	str r0, [sp]
	ldr r0, [r4, #8]
	ldr r1, [r4, #4]
	bl ov74_022312C0
	bl ov74_02231260
	add r1, r0, #0
	ldr r0, [r4, #8]
	ldr r2, _02230C0C ; =0x0000FFFF
	add r1, r5, r1
	bl ov74_02230A4C
	mov r0, #1
	strb r0, [r4, #0x19]
	mov r0, #0x3c
	strb r0, [r4, #0x1a]
_02230C08:
	pop {r3, r4, r5, pc}
	nop
_02230C0C: .word 0x0000FFFF
	thumb_func_end ov74_02230BB4


	thumb_func_start ov74_02230C10
ov74_02230C10: ; 0x02230C10
	push {r3, r4, r5, r6, r7, lr}
	bl ov74_02231184
	add r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	bne _02230CC6
	ldrb r0, [r4, #0x1c]
	cmp r0, #0xfd
	bne _02230C88
	bl ov74_0223115C
	add r5, r0, #0
	mov r1, #0
	add r2, r5, #0
_02230C2E:
	ldrb r0, [r2, #9]
	cmp r0, #0
	beq _02230C6E
	add r6, r1, #0
	mov r0, #0xc
	mul r6, r0
	add r0, r5, r6
	ldrh r0, [r0, #6]
	mov r1, #1
	mov r2, #0
	lsl r1, r0
	lsl r0, r1, #0x10
	lsr r7, r0, #0x10
	mov r0, #0xfd
	str r0, [sp]
	ldr r0, [r4, #8]
	ldr r1, [r4, #4]
	add r3, r2, #0
	bl ov74_022312C0
	bl ov74_02231260
	add r1, r0, #0
	ldr r0, [r4, #8]
	add r2, r7, #0
	bl ov74_02230A4C
	add r5, #9
	ldrb r0, [r5, r6]
	sub r0, r0, #1
	strb r0, [r5, r6]
	pop {r3, r4, r5, r6, r7, pc}
_02230C6E:
	add r1, r1, #1
	add r2, #0xc
	cmp r1, #8
	blt _02230C2E
	ldrb r0, [r4, #0x1a]
	sub r0, r0, #1
	strb r0, [r4, #0x1a]
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	bne _02230CC6
	mov r0, #2
	strb r0, [r4, #0x19]
	pop {r3, r4, r5, r6, r7, pc}
_02230C88:
	bl ov74_02231260
	bl ov74_02230A74
	ldr r0, [r4, #0xc]
	ldr r0, [r0, #8]
	lsl r0, r0, #0x10
	lsr r3, r0, #0x18
	bne _02230CAA
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	bne _02230CA6
	mov r0, #2
	strb r0, [r4, #0x19]
	pop {r3, r4, r5, r6, r7, pc}
_02230CA6:
	sub r0, r0, #1
	strb r0, [r4, #0x1b]
_02230CAA:
	ldrb r0, [r4, #0x1c]
	mov r2, #0
	str r0, [sp]
	ldr r0, [r4, #8]
	ldr r1, [r4, #4]
	bl ov74_022312C0
	bl ov74_02231260
	add r1, r0, #0
	ldr r0, [r4, #8]
	ldr r2, _02230CC8 ; =0x0000FFFF
	bl ov74_02230A4C
_02230CC6:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02230CC8: .word 0x0000FFFF
	thumb_func_end ov74_02230C10


	thumb_func_start ov74_02230CCC
ov74_02230CCC: ; 0x02230CCC
	push {r3, lr}
	bl ov74_02231184
	ldrb r0, [r0, #0x18]
	cmp r0, #1
	beq _02230CDE
	cmp r0, #2
	beq _02230CE4
	pop {r3, pc}
_02230CDE:
	bl ov74_02230BB4
	pop {r3, pc}
_02230CE4:
	bl ov74_02230C10
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_02230CCC


	thumb_func_start ov74_02230CEC
ov74_02230CEC: ; 0x02230CEC
	push {r4, lr}
	bl ov74_02231154
	add r4, r0, #0
	bl ov74_02231064
	cmp r0, #6
	beq _02230D02
	cmp r0, #0xb
	beq _02230D12
	pop {r4, pc}
_02230D02:
	mov r0, #7
	lsl r0, r0, #6
	ldrh r1, [r4, r0]
	cmp r1, #0
	beq _02230D16
	sub r1, r1, #1
	strh r1, [r4, r0]
	pop {r4, pc}
_02230D12:
	bl ov74_02230CCC
_02230D16:
	pop {r4, pc}
	thumb_func_end ov74_02230CEC


	thumb_func_start ov74_02230D18
ov74_02230D18: ; 0x02230D18
	push {r3, lr}
	bl ov74_02231064
	cmp r0, #0xa
	bne _02230D26
	bl ov74_02230CCC
_02230D26:
	pop {r3, pc}
	thumb_func_end ov74_02230D18


	thumb_func_start ov74_02230D28
ov74_02230D28: ; 0x02230D28
	push {r3, lr}
	bl ov74_02231064
	cmp r0, #0xc
	beq _02230D6A
	bl ov74_0223107C
	cmp r0, #0xc
	bne _02230D48
	bl ov74_02231064
	cmp r0, #7
	bne _02230D6A
	bl ov74_02231724
	pop {r3, pc}
_02230D48:
	bl ov74_02231094
	cmp r0, #1
	beq _02230D56
	cmp r0, #2
	beq _02230D5C
	b _02230D62
_02230D56:
	bl ov74_02230CEC
	pop {r3, pc}
_02230D5C:
	bl ov74_02230D18
	pop {r3, pc}
_02230D62:
	bl ov74_0223105C
	bl ov74_02231064
_02230D6A:
	pop {r3, pc}
	thumb_func_end ov74_02230D28


	thumb_func_start ov74_02230D6C
ov74_02230D6C: ; 0x02230D6C
	push {r3, lr}
	bl ov74_02231164
	mov r0, #1
	bl ov74_022310A0
	bl ov74_02230A34
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_02230D6C


	thumb_func_start ov74_02230D80
ov74_02230D80: ; 0x02230D80
	push {r4, lr}
	bl ov74_02231094
	mov r4, #0
	cmp r0, #1
	bne _02230DAE
	bl ov74_02231154
	ldr r1, _02230DB4 ; =0x000001C3
	ldrb r1, [r0, r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	cmp r1, #1
	bne _02230DAE
	add r2, r4, #0
_02230D9E:
	ldr r1, [r0]
	cmp r1, #0
	beq _02230DA6
	add r4, r4, #1
_02230DA6:
	add r2, r2, #1
	add r0, #0x38
	cmp r2, #8
	blo _02230D9E
_02230DAE:
	add r0, r4, #0
	pop {r4, pc}
	nop
_02230DB4: .word 0x000001C3
	thumb_func_end ov74_02230D80


	thumb_func_start ov74_02230DB8
ov74_02230DB8: ; 0x02230DB8
	push {r4, lr}
	add r4, r0, #0
	bl ov74_02231094
	cmp r0, #1
	bne _02230DEA
	bl ov74_02231064
	cmp r0, #7
	bne _02230DEA
	bl ov74_02231154
	ldr r1, _02230DF0 ; =0x000001C3
	ldrb r1, [r0, r1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	cmp r1, #1
	bne _02230DEA
	mov r1, #0x38
	mul r1, r4
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _02230DEA
	mov r0, #1
	pop {r4, pc}
_02230DEA:
	mov r0, #0
	pop {r4, pc}
	nop
_02230DF0: .word 0x000001C3
	thumb_func_end ov74_02230DB8


	thumb_func_start ov74_02230DF4
ov74_02230DF4: ; 0x02230DF4
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bl ov74_02231094
	cmp r0, #1
	bne _02230E3E
	bl ov74_02231064
	cmp r0, #7
	bne _02230E3E
	bl ov74_02231154
	ldr r2, _02230E40 ; =0x000001C3
	ldrb r3, [r0, r2]
	lsl r1, r3, #0x18
	lsr r1, r1, #0x1c
	cmp r1, #1
	bne _02230E3E
	mov r1, #0x38
	add r5, r4, #0
	mul r5, r1
	ldr r5, [r0, r5]
	cmp r5, #0
	beq _02230E3E
	mov r5, #0xf
	lsl r4, r4, #0x18
	bic r3, r5
	lsr r5, r4, #0x18
	mov r4, #0xf
	and r4, r5
	orr r3, r4
	strb r3, [r0, r2]
	mov r2, #0x78
	lsl r1, r1, #3
	strh r2, [r0, r1]
	bl ov74_02231584
_02230E3E:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02230E40: .word 0x000001C3
	thumb_func_end ov74_02230DF4


	thumb_func_start ov74_02230E44
ov74_02230E44: ; 0x02230E44
	push {r4, lr}
	bl ov74_02231094
	mov r4, #0
	cmp r0, #2
	bne _02230E76
	bl ov74_0223115C
	add r1, r0, #0
	add r1, #0x60
	ldrb r1, [r1]
	cmp r1, #2
	bne _02230E76
	add r2, r4, #0
_02230E60:
	ldr r1, [r0]
	cmp r1, #0
	beq _02230E6E
	ldrb r1, [r0, #0xa]
	cmp r1, #0
	beq _02230E6E
	add r4, r4, #1
_02230E6E:
	add r2, r2, #1
	add r0, #0xc
	cmp r2, #8
	blo _02230E60
_02230E76:
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_02230E44


	thumb_func_start ov74_02230E7C
ov74_02230E7C: ; 0x02230E7C
	push {r3, lr}
	bl ov74_0223105C
	ldr r0, [r0, #0x20]
	cmp r0, #0
	beq _02230E8C
	mov r0, #0
	pop {r3, pc}
_02230E8C:
	bl WM_GetLinkLevel
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_02230E7C


	thumb_func_start ov74_02230E94
ov74_02230E94: ; 0x02230E94
	push {r3, lr}
	bl ov74_02231094
	cmp r0, #1
	beq _02230EA4
	cmp r0, #2
	beq _02230EAA
	b _02230EB0
_02230EA4:
	bl ov74_02230D80
	pop {r3, pc}
_02230EAA:
	bl ov74_02230E44
	pop {r3, pc}
_02230EB0:
	mov r0, #0
	pop {r3, pc}
	thumb_func_end ov74_02230E94


	thumb_func_start ov74_02230EB4
ov74_02230EB4: ; 0x02230EB4
	push {r3, r4, r5, lr}
	bl ov74_02231184
	add r5, r0, #0
	bl ov74_022311DC
	add r4, r0, #0
	bl ov74_02231094
	cmp r0, #1
	bne _02230EE6
	mov r0, #1
	strb r0, [r5, #0x18]
	mov r1, #0
	strb r1, [r5, #0x19]
	add r4, #8
	str r4, [r5]
	str r4, [r5, #4]
	str r1, [r5, #0x10]
	str r1, [r5, #0x14]
	mov r0, #0x78
	strb r0, [r5, #0x1a]
	strb r1, [r5, #0x1b]
	mov r0, #0xfd
	strb r0, [r5, #0x1c]
_02230EE6:
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_02230EB4


	thumb_func_start ov74_02230EE8
ov74_02230EE8: ; 0x02230EE8
	push {r4, lr}
	bl ov74_02231184
	add r4, r0, #0
	bl ov74_022311DC
	mov r1, #1
	strb r1, [r4, #0x18]
	mov r1, #0
	strb r1, [r4, #0x19]
	add r0, #8
	str r0, [r4]
	str r0, [r4, #4]
	mov r0, #0x30
	str r0, [r4, #0x10]
	str r0, [r4, #0x14]
	mov r0, #0x78
	strb r0, [r4, #0x1a]
	strb r1, [r4, #0x1b]
	mov r0, #0xfe
	strb r0, [r4, #0x1c]
	pop {r4, pc}
	thumb_func_end ov74_02230EE8


	thumb_func_start ov74_02230F14
ov74_02230F14: ; 0x02230F14
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r4, r2, #0
	bl ov74_02231184
	cmp r4, #0xf0
	bgt _02230F3E
	mov r1, #2
	strb r1, [r0, #0x18]
	mov r1, #3
	strb r1, [r0, #0x19]
	str r5, [r0]
	str r5, [r0, #4]
	str r6, [r0, #0x10]
	mov r2, #0
	str r2, [r0, #0x14]
	mov r1, #0x78
	strb r1, [r0, #0x1a]
	strb r2, [r0, #0x1b]
	strb r4, [r0, #0x1c]
_02230F3E:
	pop {r4, r5, r6, pc}
	thumb_func_end ov74_02230F14


	thumb_func_start ov74_02230F40
ov74_02230F40: ; 0x02230F40
	push {r3, lr}
	bl ov74_02231094
	cmp r0, #1
	beq _02230F4E
	cmp r0, #2
	bne _02230F68
_02230F4E:
	bl ov74_02231064
	cmp r0, #0xa
	beq _02230F5A
	cmp r0, #0xb
	bne _02230F68
_02230F5A:
	bl ov74_02231184
	ldrb r0, [r0, #0x19]
	cmp r0, #2
	bne _02230F68
	mov r0, #1
	pop {r3, pc}
_02230F68:
	mov r0, #0
	pop {r3, pc}
	thumb_func_end ov74_02230F40


	thumb_func_start ov74_02230F6C
ov74_02230F6C: ; 0x02230F6C
	push {r3, lr}
	bl ov74_02231094
	cmp r0, #1
	beq _02230F7A
	cmp r0, #2
	bne _02230F94
_02230F7A:
	bl ov74_02231064
	cmp r0, #0xa
	beq _02230F86
	cmp r0, #0xb
	bne _02230F94
_02230F86:
	bl ov74_02231184
	ldrb r0, [r0, #0x19]
	cmp r0, #2
	bne _02230F94
	mov r0, #1
	pop {r3, pc}
_02230F94:
	mov r0, #0
	pop {r3, pc}
	thumb_func_end ov74_02230F6C


	thumb_func_start ov74_02230F98
ov74_02230F98: ; 0x02230F98
	push {r3, lr}
	bl ov74_02231094
	cmp r0, #1
	beq _02230FA6
	cmp r0, #2
	bne _02230FD0
_02230FA6:
	bl ov74_02231064
	cmp r0, #0xa
	beq _02230FB2
	cmp r0, #0xb
	bne _02230FD0
_02230FB2:
	bl ov74_02231184
	ldrb r1, [r0, #0x19]
	cmp r1, #0
	bne _02230FD0
	ldr r1, [r0, #0xc]
	ldr r1, [r1, #8]
	lsl r1, r1, #0x10
	lsr r1, r1, #0x18
	bne _02230FD0
	ldrb r0, [r0, #0x1b]
	cmp r0, #4
	bhs _02230FD0
	mov r0, #1
	pop {r3, pc}
_02230FD0:
	mov r0, #0
	pop {r3, pc}
	thumb_func_end ov74_02230F98


	thumb_func_start ov74_02230FD4
ov74_02230FD4: ; 0x02230FD4
	push {r3, lr}
	bl ov74_02231094
	cmp r0, #2
	bne _02231000
	bl ov74_0223115C
	mov r2, #0
_02230FE4:
	ldr r1, [r0]
	cmp r1, #0
	beq _02230FF4
	ldrb r1, [r0, #0xa]
	cmp r1, #0
	beq _02230FF4
	mov r0, #1
	pop {r3, pc}
_02230FF4:
	add r2, r2, #1
	add r0, #0xc
	cmp r2, #8
	blt _02230FE4
	mov r0, #0
	pop {r3, pc}
_02231000:
	bl ov74_02231118
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_02230FD4


	thumb_func_start ov74_02231008
ov74_02231008: ; 0x02231008
	push {r4, lr}
	mov r0, #0xc
	bl ov74_02231088
	bl ov74_02231064
	cmp r0, #0
	beq _02231022
	cmp r0, #1
	beq _02231022
	cmp r0, #9
	beq _0223102E
	pop {r4, pc}
_02231022:
	bl WM_Finish
	mov r0, #1
	bl ov74_0223113C
	pop {r4, pc}
_0223102E:
	bl ov74_02231118
	cmp r0, #0
	bne _02231044
	bl ov74_0223105C
	add r4, r0, #0
	bl ov74_02231724
	mov r0, #1
	str r0, [r4, #0x1c]
_02231044:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_02231008
