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
	.public _0223B330
	.public _0223B340
	.public _0223B368
	.public _0223B390
	.public _0223B3A0
	.public _0223B3BC
	.public _0223B410
	.public _0223B420
	.public _0223B430
	.public _0223B440
	.public _0223B45C
	.public _0223B478
	.public _0223B494
	.public _0223B4B0
	.public ov74_022312C0
	.public ov74_022313F0
	.public ov74_02231424
	.public ov74_02231448
	.public ov74_0223144C
	.public ov74_02231450
	.public ov74_02231454
	.public ov74_02231458
	.public ov74_0223145C
	.public ov74_02231460
	.public ov74_022314A0
	.public ov74_022314BC
	.public ov74_022314DC
	.public ov74_02231508
	.public ov74_02231544
	.public ov74_02231560
	.public ov74_02231584
	.public ov74_0223161C
	.public ov74_02231638
	.public ov74_02231670
	.public ov74_022316E8
	.public ov74_02231704
	.public ov74_02231724
	.public ov74_02231744
	.public ov74_0223512C
	.public ov74_02235230
	.public ov74_02235258
	.public ov74_022352A0
	.public ov74_022352D0
	.public ov74_02235308
	.public ov74_02235390
	.public ov74_0223539C
	.public ov74_022353FC
	.public ov74_02235414
	.public ov74_02235464
	.public ov74_0223546C
	.public ov74_02235474
	.public ov74_02235568
	.public ov74_02235634
	.public ov74_0223563C
	.public ov74_0223567C
	.public ov74_02235690
	.public ov74_02235708
	.public ov74_02235728
	.public ov74_022358BC
	.public ov74_022358C8
	.public ov74_02235930
	.public ov74_022359BC
	.public ov74_02235A68
	.public ov74_02235DC4
	.public ov74_02235ED0
	.public ov74_02235F58
	.public ov74_02236034
	.public ov74_022360A0
	.public ov74_022360B0
	.public ov74_02236128
	.public ov74_02236140
	.public ov74_0223615C
	.public ov74_022365FC
	.public ov74_02236680
	.public ov74_022368D4
	.public ov74_02236980
	.public ov74_02236988
	.public ov74_02236AE0
	.public ov74_0223BD5C
	.public ov74_0223BD68
	.public ov74_0223C1F4
	.public ov74_0223C220
	.public ov74_0223C230
	.public ov74_0223C240
	.public ov74_0223C250
	.public ov74_0223C260
	.public ov74_0223C270
	.public ov74_0223C2A0
	.public ov74_0223C2B0
	.public ov74_0223C2D0
	.public ov74_0223C2E0
	.public ov74_0223C2F0
	.public ov74_0223C320
	.public ov74_0223C340
	.public ov74_0223C6D0
	.public ov74_0223C6E0
	.public ov74_0223C700
	.public ov74_0223D080
	.public ov74_0223D090
	.public ov74_0223D0A4
	.public ov74_0223D0A8
	.public ov74_0223D0BC
	.public ov74_0223D0C0
	.extern ov74_02229200
	.extern ov74_02229294
	.extern ov74_02229450
	.extern ov74_02229DA0
	.extern ov74_02229DCC
	.extern ov74_02229DD4
	.extern ov74_02229DE0
	.extern ov74_02229E60
	.extern ov74_02229F90
	.extern ov74_02229FF4
	.extern ov74_0222A2A4
	.extern ov74_0222A2E0
	.extern ov74_0222A35C
	.extern ov74_0222A3CC
	.extern ov74_0222A494
	.extern ov74_0222A4CC
	.extern ov74_0222A504
	.extern ov74_0222A538
	.extern ov74_0222A560
	.extern ov74_0222A5AC
	.extern ov74_0222A5CC
	.extern ov74_0222A650
	.extern ov74_0222A688
	.extern ov74_0222A6C0
	.extern ov74_0222ACD8
	.extern ov74_0222AE6C
	.extern ov74_0222C2EC
	.extern ov74_0222CD94
	.extern ov74_0222D2D4
	.extern ov74_0222D308
	.extern ov74_0222D358
	.extern ov74_0222D414
	.extern ov74_0222D490
	.extern ov74_0222D494
	.extern ov74_0222D4E4
	.extern ov74_0222D55C
	.extern ov74_0222D5C4
	.extern ov74_0222D614
	.extern ov74_0222D690
	.extern ov74_0222D774
	.extern ov74_0222D78C
	.extern ov74_0222D7D0
	.extern ov74_0222DDFC
	.extern ov74_0222E1F4
	.extern ov74_0222EB44
	.extern ov74_0222EE08
	.extern ov74_0222EE0C
	.extern ov74_0222EE58
	.extern ov74_0222EEB0
	.extern ov74_0222EF18
	.extern ov74_0222EF64
	.extern ov74_0222EF68
	.extern ov74_0222F598
	.extern ov74_0222F7D4
	.extern ov74_0222FB8C
	.extern ov74_02230018
	.extern ov74_02230030
	.extern ov74_02230070
	.extern ov74_022300A8
	.extern ov74_02230110
	.extern ov74_02230138
	.extern ov74_02230404
	.extern ov74_02230520
	.extern ov74_02230590
	.extern ov74_022305E4
	.extern ov74_022306C8
	.extern ov74_022308E0
	.extern ov74_02230964
	.extern ov74_02230988
	.extern ov74_022309AC
	.extern ov74_022309F0
	.extern ov74_02231054
	.extern ov74_022310AC
	.extern ov74_022310C4
	.extern ov74_022310D0
	.extern ov74_022310DC
	.extern ov74_022310E8
	.extern ov74_022310F4
	.extern ov74_02231100
	.extern ov74_02231154
	.extern ov74_0223115C
	.extern ov74_022311D8
	.extern ov74_022311DC
	.extern ov74_022311E8
	.extern ov74_02231260

	thumb_func_start ov74_02231264
ov74_02231264: ; 0x02231264
	push {r4, lr}
	ldr r0, _02231278 ; =0x04000006
	ldrh r4, [r0]
	bl OS_GetTick
	add r1, r0, r4
	mov r0, #1
	bic r1, r0
	add r0, r1, #1
	pop {r4, pc}
	.balign 4, 0
_02231278: .word 0x04000006
	thumb_func_end ov74_02231264


	thumb_func_start ov74_0223127C
ov74_0223127C: ; 0x0223127C
	push {r4, r5, r6, r7}
	add r3, r0, #0
	mov r0, #0
	lsr r1, r1, #2
	beq _022312B2
	ldr r4, _022312B8 ; =0x00269EC3
_02231288:
	ldr r5, _022312BC ; =0x5D588B65
	ldr r6, _022312BC ; =0x5D588B65
	mul r5, r3
	ldr r3, _022312B8 ; =0x00269EC3
	add r0, r0, #1
	add r3, r5, r3
	lsr r5, r3, #0x10
	mul r6, r3
	add r3, r6, r4
	lsl r5, r5, #0x10
	lsr r7, r3, #0x10
	lsr r5, r5, #0x10
	lsl r7, r7, #0x10
	ldr r6, [r2]
	lsl r5, r5, #0x10
	lsr r7, r7, #0x10
	orr r5, r7
	eor r5, r6
	stmia r2!, {r5}
	cmp r0, r1
	blo _02231288
_022312B2:
	add r0, r3, #0
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
_022312B8: .word 0x00269EC3
_022312BC: .word 0x5D588B65
	thumb_func_end ov74_0223127C


	thumb_func_start ov74_022312C0
ov74_022312C0: ; 0x022312C0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	add r6, r2, #0
	str r3, [sp]
	bl ov74_022311DC
	add r4, r0, #0
	ldr r0, [r5]
	mov r1, #0xff
	bic r0, r1
	ldr r1, [r4]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	orr r1, r0
	ldr r0, _022313E4 ; =0xFFFFF0FF
	str r1, [r5]
	and r0, r1
	ldr r1, [r4]
	lsl r1, r1, #0x14
	lsr r1, r1, #0x1c
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x14
	orr r1, r0
	ldr r0, _022313E8 ; =0xFFFF0FFF
	str r1, [r5]
	and r0, r1
	ldr r1, [r4]
	lsl r1, r1, #0x10
	lsr r1, r1, #0x1c
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x10
	orr r0, r1
	str r0, [r5]
	bl ov74_02231264
	ldr r1, [r5]
	lsl r0, r0, #0x10
	lsl r1, r1, #0x10
	lsr r0, r0, #0x10
	lsr r1, r1, #0x10
	lsl r0, r0, #0x10
	orr r0, r1
	str r0, [r5]
	ldr r2, [r4, #4]
	ldr r1, [r5, #4]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	mov r0, #0xff
	lsl r2, r2, #0x18
	bic r1, r0
	lsr r2, r2, #0x18
	orr r2, r1
	ldr r1, _022313E4 ; =0xFFFFF0FF
	str r2, [r5, #4]
	and r1, r2
	ldr r2, [r4, #4]
	lsl r2, r2, #0x14
	lsr r2, r2, #0x1c
	lsl r2, r2, #0x1c
	lsr r2, r2, #0x14
	orr r2, r1
	ldr r1, _022313E8 ; =0xFFFF0FFF
	str r2, [r5, #4]
	and r1, r2
	ldr r2, [r4, #4]
	lsl r2, r2, #0x10
	lsr r2, r2, #0x1c
	lsl r2, r2, #0x1c
	lsr r2, r2, #0x10
	orr r1, r2
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	str r1, [r5, #4]
	ldr r1, [r5, #8]
	bic r1, r0
	ldr r0, [sp, #0x18]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	orr r1, r0
	ldr r0, _022313EC ; =0xFFFF00FF
	and r0, r1
	ldr r1, [sp]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x10
	orr r0, r1
	str r0, [r5, #8]
	mov r0, #0
	add r1, r7, #0
	add r2, r6, #0
	bl SVC_GetCRC16
	ldr r1, [r5, #8]
	lsl r0, r0, #0x10
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	orr r0, r1
	str r0, [r5, #8]
	bl ov74_02231260
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r0, r0, #0x18
	ldr r1, [r5, #0xc]
	mov r2, #0xff
	bic r1, r2
	lsr r0, r0, #0x18
	orr r0, r1
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	lsl r0, r6, #8
	orr r0, r1
	str r0, [r5, #0xc]
	cmp r6, #0
	beq _022313BE
	ldr r1, [r5, #0xc]
	add r0, r7, #0
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r1, r5, r1
	add r2, r6, #0
	bl MI_CpuCopy8
_022313BE:
	add r0, r5, #0
	bl ov74_0223145C
	ldr r0, [r4]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x1c
	cmp r0, #1
	bne _022313E2
	ldr r1, [r5, #0xc]
	ldr r0, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r1, r6, r1
	lsr r0, r0, #0x10
	sub r1, r1, #4
	add r2, r5, #4
	bl ov74_0223127C
_022313E2:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022313E4: .word 0xFFFFF0FF
_022313E8: .word 0xFFFF0FFF
_022313EC: .word 0xFFFF00FF
	thumb_func_end ov74_022312C0


	thumb_func_start ov74_022313F0
ov74_022313F0: ; 0x022313F0
	push {r4, lr}
	add r4, r0, #0
	bl ov74_022311DC
	ldr r0, [r4]
	lsl r1, r0, #0x10
	lsr r1, r1, #0x1c
	cmp r1, #1
	bne _02231420
	lsr r0, r0, #0x10
	mov r1, #0xc
	add r2, r4, #4
	bl ov74_0223127C
	ldr r1, [r4, #0xc]
	add r4, #0x10
	lsl r2, r1, #0x18
	lsr r2, r2, #0x18
	lsr r1, r1, #8
	add r1, r2, r1
	sub r1, #0x10
	add r2, r4, #0
	bl ov74_0223127C
_02231420:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_022313F0


	thumb_func_start ov74_02231424
ov74_02231424: ; 0x02231424
	push {r4, lr}
	add r4, r0, #0
	ldr r2, [r4, #0xc]
	mov r0, #0
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	add r1, r4, r1
	lsr r2, r2, #8
	bl SVC_GetCRC16
	ldr r1, [r4, #8]
	lsr r1, r1, #0x10
	cmp r1, r0
	bne _02231444
	mov r0, #1
	pop {r4, pc}
_02231444:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov74_02231424


	thumb_func_start ov74_02231448
ov74_02231448: ; 0x02231448
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02231448


	thumb_func_start ov74_0223144C
ov74_0223144C: ; 0x0223144C
	bx lr
	.balign 4, 0
	thumb_func_end ov74_0223144C


	thumb_func_start ov74_02231450
ov74_02231450: ; 0x02231450
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02231450


	thumb_func_start ov74_02231454
ov74_02231454: ; 0x02231454
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02231454


	thumb_func_start ov74_02231458
ov74_02231458: ; 0x02231458
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02231458


	thumb_func_start ov74_0223145C
ov74_0223145C: ; 0x0223145C
	bx lr
	.balign 4, 0
	thumb_func_end ov74_0223145C


	thumb_func_start ov74_02231460
ov74_02231460: ; 0x02231460
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r6, r0, #0
	add r5, r1, #0
	add r4, r2, #0
	bl ov74_022310AC
	lsl r0, r0, #0x10
	lsl r3, r5, #0x10
	lsr r0, r0, #0x10
	str r4, [sp]
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _0223149C ; =ov74_02230018
	mov r1, #0
	add r2, r6, #0
	lsr r3, r3, #0x10
	bl WM_SetMPDataToPortEx
	cmp r0, #2
	beq _02231496
	bl ov74_02231448
	add sp, #0xc
	mov r0, #0
	pop {r3, r4, r5, r6, pc}
_02231496:
	mov r0, #1
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_0223149C: .word ov74_02230018
	thumb_func_end ov74_02231460


	thumb_func_start ov74_022314A0
ov74_022314A0: ; 0x022314A0
	push {r3, lr}
	ldr r0, _022314B8 ; =ov74_02230030
	bl WM_Enable
	cmp r0, #2
	beq _022314B4
	bl ov74_02231448
	mov r0, #0
	pop {r3, pc}
_022314B4:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_022314B8: .word ov74_02230030
	thumb_func_end ov74_022314A0


	thumb_func_start ov74_022314BC
ov74_022314BC: ; 0x022314BC
	push {r3, lr}
	ldr r0, _022314D8 ; =ov74_02230070
	bl WM_Disable
	cmp r0, #2
	beq _022314D4
	bl ov74_02231448
	bl OS_Terminate
	mov r0, #0
	pop {r3, pc}
_022314D4:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_022314D8: .word ov74_02230070
	thumb_func_end ov74_022314BC


	thumb_func_start ov74_022314DC
ov74_022314DC: ; 0x022314DC
	push {r3, lr}
	add r3, r0, #0
	mov r0, #0x1e
	str r0, [sp]
	lsl r3, r3, #0x10
	ldr r0, _02231504 ; =ov74_022300A8
	mov r1, #3
	mov r2, #0x11
	lsr r3, r3, #0x10
	bl WM_MeasureChannel
	cmp r0, #2
	beq _022314FE
	bl ov74_02231448
	mov r0, #0
	pop {r3, pc}
_022314FE:
	mov r0, #1
	pop {r3, pc}
	nop
_02231504: .word ov74_022300A8
	thumb_func_end ov74_022314DC


	thumb_func_start ov74_02231508
ov74_02231508: ; 0x02231508
	push {r3, r4, r5, lr}
	bl ov74_02231054
	add r5, r0, #0
	bl ov74_022311DC
	add r4, r0, #0
	bl ov74_0223115C
	add r0, #0x64
	ldrb r0, [r0]
	strh r0, [r5, #0x32]
	str r4, [r5]
	bl ov74_022311D8
	strh r0, [r5, #4]
	ldr r0, _02231540 ; =ov74_02230110
	add r1, r5, #0
	bl WM_SetParentParameter
	cmp r0, #2
	beq _0223153C
	bl ov74_02231448
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223153C:
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02231540: .word ov74_02230110
	thumb_func_end ov74_02231508


	thumb_func_start ov74_02231544
ov74_02231544: ; 0x02231544
	push {r3, lr}
	ldr r0, _0223155C ; =ov74_02230138
	bl WM_StartParent
	cmp r0, #2
	beq _02231558
	bl ov74_02231448
	mov r0, #0
	pop {r3, pc}
_02231558:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_0223155C: .word ov74_02230138
	thumb_func_end ov74_02231544


	thumb_func_start ov74_02231560
ov74_02231560: ; 0x02231560
	push {r3, lr}
	bl ov74_022310C4
	add r1, r0, #0
	ldr r0, _02231580 ; =ov74_02230404
	bl WM_StartScan
	cmp r0, #2
	beq _0223157A
	bl ov74_02231448
	mov r0, #0
	pop {r3, pc}
_0223157A:
	mov r0, #1
	pop {r3, pc}
	nop
_02231580: .word ov74_02230404
	thumb_func_end ov74_02231560


	thumb_func_start ov74_02231584
ov74_02231584: ; 0x02231584
	push {r3, r4, r5, lr}
	bl ov74_022310C4
	add r4, r0, #0
	bl ov74_02231154
	ldr r2, _02231614 ; =0x000001C3
	mov r3, #0x38
	ldrb r1, [r0, r2]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	add r5, r1, #0
	mul r5, r3
	add r1, r0, r5
	add r1, #0x34
	ldrb r1, [r1]
	strb r1, [r4, #8]
	ldrb r1, [r0, r2]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	add r5, r1, #0
	mul r5, r3
	add r1, r0, r5
	add r1, #0x35
	ldrb r1, [r1]
	strb r1, [r4, #9]
	ldrb r1, [r0, r2]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	add r5, r1, #0
	mul r5, r3
	ldrb r1, [r0, r5]
	strb r1, [r4, #0xa]
	ldrb r1, [r0, r2]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	add r5, r1, #0
	mul r5, r3
	add r1, r0, r5
	ldrb r1, [r1, #1]
	strb r1, [r4, #0xb]
	ldrb r1, [r0, r2]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	add r5, r1, #0
	mul r5, r3
	add r1, r0, r5
	ldrb r1, [r1, #2]
	strb r1, [r4, #0xc]
	ldrb r1, [r0, r2]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	add r2, r1, #0
	mul r2, r3
	add r0, r0, r2
	ldrb r0, [r0, #3]
	strb r0, [r4, #0xd]
	bl ov74_022310C4
	add r1, r0, #0
	ldr r0, _02231618 ; =ov74_02230520
	bl WM_StartScan
	cmp r0, #2
	beq _0223160E
	bl ov74_02231448
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223160E:
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_02231614: .word 0x000001C3
_02231618: .word ov74_02230520
	thumb_func_end ov74_02231584


	thumb_func_start ov74_0223161C
ov74_0223161C: ; 0x0223161C
	push {r3, lr}
	ldr r0, _02231634 ; =ov74_02230590
	bl WM_EndScan
	cmp r0, #2
	beq _02231630
	bl ov74_02231448
	mov r0, #0
	pop {r3, pc}
_02231630:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_02231634: .word ov74_02230590
	thumb_func_end ov74_0223161C


	thumb_func_start ov74_02231638
ov74_02231638: ; 0x02231638
	push {r3, r4, lr}
	sub sp, #4
	bl ov74_022311E8
	add r4, r0, #0
	bl ov74_02231100
	add r1, r0, #0
	mov r0, #0
	str r0, [sp]
	ldr r0, _0223166C ; =ov74_022305E4
	add r2, r4, #0
	mov r3, #1
	bl WM_StartConnectEx
	cmp r0, #2
	beq _02231664
	bl ov74_02231448
	add sp, #4
	mov r0, #0
	pop {r3, r4, pc}
_02231664:
	mov r0, #1
	add sp, #4
	pop {r3, r4, pc}
	nop
_0223166C: .word ov74_022305E4
	thumb_func_end ov74_02231638


	thumb_func_start ov74_02231670
ov74_02231670: ; 0x02231670
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r1, _022316E0 ; =ov74_022308E0
	mov r0, #4
	mov r2, #0
	bl WM_SetPortCallback
	cmp r0, #0
	beq _0223168C
	bl ov74_02231448
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0223168C:
	bl ov74_02231054
	ldrh r0, [r0, #0x16]
	cmp r0, #0
	bne _0223169A
	mov r5, #1
	b _0223169C
_0223169A:
	mov r5, #0
_0223169C:
	bl ov74_022310F4
	add r6, r0, #0
	bl ov74_022310DC
	add r4, r0, #0
	bl ov74_022310E8
	add r7, r0, #0
	bl ov74_022310D0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	lsl r0, r5, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	lsl r2, r4, #0x10
	ldr r0, _022316E4 ; =ov74_022306C8
	add r1, r6, #0
	lsr r2, r2, #0x10
	add r3, r7, #0
	bl WM_StartMP
	cmp r0, #2
	beq _022316DA
	bl ov74_02231448
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_022316DA:
	mov r0, #1
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022316E0: .word ov74_022308E0
_022316E4: .word ov74_022306C8
	thumb_func_end ov74_02231670


	thumb_func_start ov74_022316E8
ov74_022316E8: ; 0x022316E8
	push {r3, lr}
	ldr r0, _02231700 ; =ov74_02230964
	bl WM_PowerOn
	cmp r0, #2
	beq _022316FC
	bl ov74_02231448
	mov r0, #0
	pop {r3, pc}
_022316FC:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_02231700: .word ov74_02230964
	thumb_func_end ov74_022316E8


	thumb_func_start ov74_02231704
ov74_02231704: ; 0x02231704
	push {r3, lr}
	ldr r0, _02231720 ; =ov74_02230988
	bl WM_PowerOff
	cmp r0, #2
	beq _0223171C
	bl ov74_02231448
	bl OS_Terminate
	mov r0, #0
	pop {r3, pc}
_0223171C:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_02231720: .word ov74_02230988
	thumb_func_end ov74_02231704


	thumb_func_start ov74_02231724
ov74_02231724: ; 0x02231724
	push {r3, lr}
	ldr r0, _02231740 ; =ov74_022309AC
	bl WM_Reset
	cmp r0, #2
	beq _0223173C
	bl ov74_02231448
	bl OS_Terminate
	mov r0, #0
	pop {r3, pc}
_0223173C:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_02231740: .word ov74_022309AC
	thumb_func_end ov74_02231724


	thumb_func_start ov74_02231744
ov74_02231744: ; 0x02231744
	push {r3, lr}
	ldr r0, _02231760 ; =ov74_022309F0
	bl WM_End
	cmp r0, #2
	beq _0223175C
	bl ov74_02231448
	bl OS_Terminate
	mov r0, #0
	pop {r3, pc}
_0223175C:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_02231760: .word ov74_022309F0
	thumb_func_end ov74_02231744


	thumb_func_start ov74_02231764
ov74_02231764: ; 0x02231764
	cmp r0, #0
	bgt _0223176C
	mov r0, #1
	bx lr
_0223176C:
	cmp r0, #0xfb
	bgt _02231774
	mov r0, #0
	bx lr
_02231774:
	ldr r1, _0223178C ; =0x00000115
	cmp r0, r1
	bge _0223177E
	mov r0, #1
	bx lr
_0223177E:
	add r1, #0x86
	cmp r0, r1
	ble _02231788
	mov r0, #1
	bx lr
_02231788:
	mov r0, #0
	bx lr
	.balign 4, 0
_0223178C: .word 0x00000115
	thumb_func_end ov74_02231764


	thumb_func_start ov74_02231790
ov74_02231790: ; 0x02231790
	push {r4, lr}
	add r4, r0, #0
	bl PmAgbCartridge_GetVersionInternal
	cmp r0, #4
	bhi _022317D0
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022317A8: ; jump table
	.short _022317B2 - _022317A8 - 2 ; case 0
	.short _022317B8 - _022317A8 - 2 ; case 1
	.short _022317BE - _022317A8 - 2 ; case 2
	.short _022317C4 - _022317A8 - 2 ; case 3
	.short _022317CA - _022317A8 - 2 ; case 4
_022317B2:
	mov r0, #VERSION_RUBY
	str r0, [r4]
	pop {r4, pc}
_022317B8:
	mov r0, #VERSION_SAPPHIRE
	str r0, [r4]
	pop {r4, pc}
_022317BE:
	mov r0, #VERSION_LEAFGREEN
	str r0, [r4]
	pop {r4, pc}
_022317C4:
	mov r0, #VERSION_FIRERED
	str r0, [r4]
	pop {r4, pc}
_022317CA:
	mov r0, #VERSION_EMERALD
	str r0, [r4]
	pop {r4, pc}
_022317D0:
	mov r0, #0
	mvn r0, r0
	str r0, [r4]
	pop {r4, pc}
	thumb_func_end ov74_02231790


	thumb_func_start ov74_022317D8
ov74_022317D8: ; 0x022317D8
	push {r3, r4, r5, lr}
	sub sp, #0x10
	ldr r1, _0223192C ; =0x0000E890
	add r5, r0, #0
	add r4, r5, r1
	ldr r1, [r4]
	cmp r1, #9
	bls _022317EA
	b _02231924
_022317EA:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_022317F6: ; jump table
	.short _0223180A - _022317F6 - 2 ; case 0
	.short _0223182A - _022317F6 - 2 ; case 1
	.short _02231842 - _022317F6 - 2 ; case 2
	.short _02231852 - _022317F6 - 2 ; case 3
	.short _02231862 - _022317F6 - 2 ; case 4
	.short _0223187E - _022317F6 - 2 ; case 5
	.short _02231892 - _022317F6 - 2 ; case 6
	.short _022318AE - _022317F6 - 2 ; case 7
	.short _022318DA - _022317F6 - 2 ; case 8
	.short _02231900 - _022317F6 - 2 ; case 9
_0223180A:
	bl ov74_0223195C
	ldr r0, [r5, #0x10]
	bl Save_MigratedPokemon_Get
	add r5, r0, #0
	bl ov74_02233F68
	add r1, r0, #0
	add r0, r5, #0
	bl MigratedPokemon_RecordMigration
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_0223182A:
	bl OS_GetTick
	mov r2, #0x78
	mov r3, #0
	bl _ull_mod
	add r0, r0, #1
	str r0, [r4, #4]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_02231842:
	ldr r0, [r4, #4]
	sub r0, r0, #1
	str r0, [r4, #4]
	bne _02231924
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_02231852:
	ldr r0, [r5, #0x10]
	mov r1, #2
	bl Save_PrepareForAsyncWrite
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_02231862:
	ldr r0, [r5, #0x10]
	bl Save_WriteFileAsync
	cmp r0, #3
	bne _02231872
	add sp, #0x10
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_02231872:
	cmp r0, #1
	bne _02231924
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_0223187E:
	mov r0, #0
	add r1, r0, #0
	add r2, sp, #0
	mov r3, #0x10
	bl CTRDG_ReadAgbFlash
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_02231892:
	bl ov74_02233E8C
	cmp r0, #0
	bne _022318A6
	mov r0, #1
	bl Sys_ClearSleepDisableFlag
	add sp, #0x10
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_022318A6:
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_022318AE:
	bl ov74_02233F14
	cmp r0, #9
	beq _02231924
	bl ov74_02233F14
	cmp r0, #0xb
	bne _022318C6
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_022318C6:
	bl ov74_02233ED4
	cmp r0, #8
	bne _02231924
	mov r0, #1
	bl Sys_ClearSleepDisableFlag
	add sp, #0x10
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_022318DA:
	ldr r0, [r5, #0x10]
	bl Save_WriteFileAsync
	cmp r0, #3
	bne _022318EA
	add sp, #0x10
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_022318EA:
	cmp r0, #2
	bne _022318DA
	bl ov74_02233ED4
	mov r0, #1
	bl Sys_SetSleepDisableFlag
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02231924
_02231900:
	bl ov74_02233ED4
	cmp r0, #8
	bne _02231914
	mov r0, #1
	bl Sys_ClearSleepDisableFlag
	add sp, #0x10
	mov r0, #0xc
	pop {r3, r4, r5, pc}
_02231914:
	cmp r0, #0
	bne _02231924
	mov r0, #1
	bl Sys_ClearSleepDisableFlag
	add sp, #0x10
	mov r0, #0xb
	pop {r3, r4, r5, pc}
_02231924:
	mov r0, #0xa
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_0223192C: .word 0x0000E890
	thumb_func_end ov74_022317D8


	thumb_func_start ov74_02231930
ov74_02231930: ; 0x02231930
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x10]
	bl Save_MigratedPokemon_Get
	add r4, r0, #0
	bl ov74_02233F68
	add r1, r0, #0
	add r0, r4, #0
	bl MigratedPokemon_RecordMigration
	mov r0, #4
	bl sub_0201A728
	ldr r0, [r5, #0x10]
	bl SaveGameNormal
	mov r0, #4
	bl sub_0201A738
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_02231930


	thumb_func_start ov74_0223195C
ov74_0223195C: ; 0x0223195C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xf4
	add r7, r0, #0
	ldr r0, [r7, #0x10]
	bl Save_MigratedPokemon_Get
	str r0, [sp]
	add r0, sp, #8
	bl Mon_GetBoxMon
	add r6, r0, #0
	mov r4, #0
	add r5, r7, #0
_02231976:
	ldr r0, _022319F4 ; =0x0000E880
	mov r1, #0x3d
	lsl r1, r1, #4
	ldr r0, [r7, r0]
	ldr r2, [r5, r1]
	mov r1, #0x96
	lsl r1, r1, #4
	add r0, r0, #4
	mul r1, r2
	add r0, r0, r1
	mov r1, #0xf3
	lsl r1, r1, #2
	ldr r2, [r5, r1]
	mov r1, #0x50
	mul r1, r2
	add r0, r0, r1
	add r1, r6, #0
	bl MigrateBoxMon
	ldr r0, [sp]
	add r1, r6, #0
	add r2, r4, #0
	bl MigratedPokemon_CopyBoxPokemonToSlot
	add r4, r4, #1
	add r5, #0xc
	cmp r4, #6
	blt _02231976
	mov r5, #0
	add r0, sp, #4
	strh r5, [r0]
	add r4, r7, #0
	sub r6, r5, #1
_022319B8:
	mov r0, #0xf3
	lsl r0, r0, #2
	ldr r2, [r4, r0]
	add r0, r0, #4
	ldr r1, [r4, r0]
	cmp r2, r6
	beq _022319E6
	cmp r1, #0xe
	beq _022319E6
	ldr r0, _022319F4 ; =0x0000E880
	mov r3, #0x96
	ldr r0, [r7, r0]
	lsl r3, r3, #4
	mul r3, r1
	add r0, r0, #4
	mov r1, #0x50
	mul r1, r2
	add r0, r0, r3
	add r0, r0, r1
	mov r1, #0xb
	add r2, sp, #4
	bl ov74_022348B0
_022319E6:
	add r5, r5, #1
	add r4, #0xc
	cmp r5, #6
	blt _022319B8
	add sp, #0xf4
	pop {r4, r5, r6, r7, pc}
	nop
_022319F4: .word 0x0000E880
	thumb_func_end ov74_0223195C


	thumb_func_start ov74_022319F8
ov74_022319F8: ; 0x022319F8
	push {r4, lr}
	add r4, r0, #0
	mov r0, #1
	tst r2, r0
	beq _02231A16
	mov r2, #0
	bl FontID_String_GetWidth
	ldr r1, [r4, #0x10]
	lsl r1, r1, #3
	sub r1, r1, r0
	lsr r0, r1, #0x1f
	add r0, r1, r0
	asr r0, r0, #1
	pop {r4, pc}
_02231A16:
	ldr r0, [r4, #0x18]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_022319F8


	thumb_func_start ov74_02231A1C
ov74_02231A1C: ; 0x02231A1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r1, #0
	ldr r7, [r5, #0x44]
	add r6, r0, #0
	add r4, r2, #0
	cmp r7, #0
	bne _02231A2E
	mov r7, #0xff
_02231A2E:
	ldr r1, [r5]
	ldr r0, [r1]
	cmp r0, #0
	bne _02231A6C
	ldr r0, [r5, #0xc]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r5, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r5, #0x14]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	mov r0, #0xf
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x20]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r2, [r5, #0x24]
	ldr r3, [r5, #8]
	lsl r2, r2, #0x18
	lsl r3, r3, #0x18
	ldr r0, [r6, #0x20]
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl AddWindowParameterized
_02231A6C:
	mov r0, #2
	tst r0, r4
	bne _02231A7E
	ldr r1, [r5, #0x30]
	ldr r0, [r5]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	bl FillWindowPixelBuffer
_02231A7E:
	mov r0, #0
	ldr r1, [r5, #0x34]
	mvn r0, r0
	cmp r1, r0
	beq _02231B0E
	ldr r2, _02231BB0 ; =0x0000012D
	mov r0, #1
	mov r1, #0x1b
	mov r3, #0x4c
	bl NewMsgDataFromNarc
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x40]
	str r0, [sp, #0x14]
	cmp r0, #0
	bne _02231AA6
	mov r0, #0x4c
	bl MessageFormat_New
	str r0, [sp, #0x14]
_02231AA6:
	ldr r0, _02231BB4 ; =0x00012608
	ldr r0, [r6, r0]
	bl String_SetEmpty
	ldr r0, _02231BB4 ; =0x00012608
	ldr r1, [r5, #0x34]
	ldr r0, [r6, r0]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	bl NewString_ReadMsgData
	str r0, [sp, #0x20]
	ldr r1, _02231BB4 ; =0x00012608
	ldr r0, [sp, #0x14]
	ldr r1, [r6, r1]
	ldr r2, [sp, #0x20]
	bl StringExpandPlaceholders
	ldr r0, [sp, #0x20]
	bl String_Delete
	ldr r1, [sp, #0x1c]
	add r0, r5, #0
	add r2, r4, #0
	bl ov74_022319F8
	add r3, r0, #0
	ldr r0, [r5, #0x1c]
	ldr r2, [sp, #0x1c]
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x2c]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r5]
	ldr r1, [r5, #0x28]
	bl AddTextPrinterParameterizedWithColor
	str r0, [r5, #0x48]
	ldr r0, [r5, #0x40]
	cmp r0, #0
	bne _02231B02
	ldr r0, [sp, #0x14]
	bl MessageFormat_Delete
_02231B02:
	ldr r0, [sp, #0x18]
	bl DestroyMsgData
	mov r0, #0
	mvn r0, r0
	str r0, [r5, #0x34]
_02231B0E:
	ldr r1, [r5, #0x38]
	cmp r1, #0
	beq _02231B4A
	ldr r0, _02231BB8 ; =0x0001260C
	mov r2, #0x40
	ldr r6, [r6, r0]
	add r0, r6, #0
	bl CopyU16ArrayToStringN
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	bl ov74_022319F8
	add r3, r0, #0
	ldr r0, [r5, #0x1c]
	add r2, r6, #0
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x2c]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r5]
	ldr r1, [r5, #0x28]
	bl AddTextPrinterParameterizedWithColor
	str r0, [r5, #0x48]
	mov r0, #0
	str r0, [r5, #0x38]
_02231B4A:
	ldr r1, [r5, #0x3c]
	cmp r1, #0
	beq _02231B78
	add r0, r5, #0
	add r2, r4, #0
	bl ov74_022319F8
	add r3, r0, #0
	ldr r0, [r5, #0x1c]
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #0x2c]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r5]
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x3c]
	bl AddTextPrinterParameterizedWithColor
	str r0, [r5, #0x48]
	mov r0, #0
	str r0, [r5, #0x3c]
_02231B78:
	mov r0, #4
	tst r0, r4
	bne _02231B84
	ldr r0, [r5]
	bl CopyWindowToVram
_02231B84:
	mov r0, #8
	tst r0, r4
	beq _02231BAC
	mov r0, #0x10
	tst r0, r4
	ldr r0, [r5]
	beq _02231BA0
	ldr r2, _02231BBC ; =0x000003D2
	mov r1, #0
	mov r3, #0xd
	bl DrawFrameAndWindow2
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
_02231BA0:
	mov r2, #0x3f
	mov r1, #0
	lsl r2, r2, #4
	mov r3, #0xe
	bl DrawFrameAndWindow1
_02231BAC:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02231BB0: .word 0x0000012D
_02231BB4: .word 0x00012608
_02231BB8: .word 0x0001260C
_02231BBC: .word 0x000003D2
	thumb_func_end ov74_02231A1C


	thumb_func_start ov74_02231BC0
ov74_02231BC0: ; 0x02231BC0
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _02231BEC ; =_0223B4E8
	add r3, sp, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl ObjCharTransfer_Init
	mov r0, #0x14
	mov r1, #0x4c
	bl ObjPlttTransfer_Init
	bl ObjCharTransfer_ClearBuffers
	bl ObjPlttTransfer_Reset
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_02231BEC: .word _0223B4E8
	thumb_func_end ov74_02231BC0


	thumb_func_start ov74_02231BF0
ov74_02231BF0: ; 0x02231BF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r0, #0
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	str r3, [sp, #0xc]
	mov r2, #0x4c
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	add r1, r6, #0
	mov r0, #0x50
	add r1, #0x2c
	mov r2, #0x4c
	bl G2dRenderer_Init
	str r0, [r6, #0x28]
	add r0, r6, #0
	mov r2, #1
	add r0, #0x2c
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	mov r7, #0x55
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_02231C36:
	mov r0, #3
	add r1, r4, #0
	mov r2, #0x4c
	bl Create2DGfxResObjMan
	str r0, [r5, r7]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blt _02231C36
	mov r0, #0
	str r0, [sp]
	mov r3, #1
	str r3, [sp, #4]
	mov r0, #0x4c
	str r0, [sp, #8]
	mov r0, #0x55
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0x71
	mov r2, #0x1e
	bl AddCharResObjFromNarc
	mov r1, #0x5b
	lsl r1, r1, #2
	str r0, [r6, r1]
	mov r3, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	mov r0, #0x4c
	sub r1, #0x14
	str r0, [sp, #0xc]
	ldr r0, [r6, r1]
	mov r1, #0x71
	mov r2, #0x1b
	bl AddPlttResObjFromNarc
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r6, r1]
	mov r0, #0
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0x4c
	sub r1, #0x14
	str r0, [sp, #8]
	ldr r0, [r6, r1]
	mov r1, #0x71
	mov r2, #0x1d
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5d
	lsl r1, r1, #2
	str r0, [r6, r1]
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x4c
	sub r1, #0x14
	str r0, [sp, #8]
	ldr r0, [r6, r1]
	mov r1, #0x71
	mov r2, #0x1c
	mov r3, #1
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x5e
	lsl r1, r1, #2
	str r0, [r6, r1]
	sub r1, #0xc
	ldr r0, [r6, r1]
	bl SpriteTransfer_CreateCharTransferTask
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl SpriteTransfer_CreateExtPlttTransferTask
	bl sub_02074490
	add r1, r0, #0
	mov r0, #0
	mov r2, #1
	str r0, [sp]
	mov r0, #0x4c
	add r3, r2, #0
	str r0, [sp, #4]
	mov r0, #0x14
	add r3, #0xff
	bl GfGfxLoader_GXLoadPal
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov74_02231BF0


	thumb_func_start ov74_02231CFC
ov74_02231CFC: ; 0x02231CFC
	push {lr}
	sub sp, #0x2c
	mov r1, #0
	str r1, [sp]
	sub r2, r1, #1
	str r2, [sp, #4]
	str r2, [sp, #8]
	str r1, [sp, #0xc]
	mov r3, #0x55
	str r1, [sp, #0x10]
	lsl r3, r3, #2
	ldr r2, [r0, r3]
	str r2, [sp, #0x14]
	add r2, r3, #4
	ldr r2, [r0, r2]
	str r2, [sp, #0x18]
	add r2, r3, #0
	add r2, #8
	ldr r2, [r0, r2]
	str r2, [sp, #0x1c]
	add r2, r3, #0
	add r2, #0xc
	ldr r2, [r0, r2]
	add r3, #0x30
	str r2, [sp, #0x20]
	str r1, [sp, #0x24]
	add r0, r0, r3
	add r2, r1, #0
	add r3, r1, #0
	str r1, [sp, #0x28]
	bl CreateSpriteResourcesHeader
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add sp, #0x2c
	pop {pc}
	thumb_func_end ov74_02231CFC


	thumb_func_start ov74_02231D48
ov74_02231D48: ; 0x02231D48
	ldr r2, [r1, #0x28]
	str r2, [r0]
	mov r2, #0x61
	lsl r2, r2, #2
	add r1, r1, r2
	str r1, [r0, #4]
	mov r2, #0
	mov r1, #1
	str r2, [r0, #0x10]
	lsl r1, r1, #0xc
	str r1, [r0, #0x14]
	str r1, [r0, #0x18]
	str r1, [r0, #0x1c]
	strh r2, [r0, #0x20]
	mov r1, #0x14
	str r1, [r0, #0x24]
	str r3, [r0, #0x28]
	mov r1, #0x4c
	str r1, [r0, #0x2c]
	bx lr
	thumb_func_end ov74_02231D48


	thumb_func_start ov74_02231D70
ov74_02231D70: ; 0x02231D70
	ldr r3, _02231D8C ; =0x0000E880
	ldr r0, [r0, r3]
	add r3, r0, #4
	mov r0, #0x96
	lsl r0, r0, #4
	mul r0, r1
	add r1, r3, r0
	mov r0, #0x50
	mul r0, r2
	add r0, r1, r0
	ldr r3, _02231D90 ; =AGB_GetBoxMonData
	mov r1, #0xb
	mov r2, #0
	bx r3
	.balign 4, 0
_02231D8C: .word 0x0000E880
_02231D90: .word AGB_GetBoxMonData
	thumb_func_end ov74_02231D70


	thumb_func_start ov74_02231D94
ov74_02231D94: ; 0x02231D94
	ldr r3, _02231DB0 ; =0x0000E880
	ldr r0, [r0, r3]
	add r3, r0, #4
	mov r0, #0x96
	lsl r0, r0, #4
	mul r0, r1
	add r1, r3, r0
	mov r0, #0x50
	mul r0, r2
	add r0, r1, r0
	ldr r3, _02231DB4 ; =AGB_GetBoxMonData
	mov r1, #0x2d
	mov r2, #0
	bx r3
	.balign 4, 0
_02231DB0: .word 0x0000E880
_02231DB4: .word AGB_GetBoxMonData
	thumb_func_end ov74_02231D94


	thumb_func_start ov74_02231DB8
ov74_02231DB8: ; 0x02231DB8
	ldr r3, _02231DD4 ; =0x0000E880
	ldr r0, [r0, r3]
	add r3, r0, #4
	mov r0, #0x96
	lsl r0, r0, #4
	mul r0, r1
	add r1, r3, r0
	mov r0, #0x50
	mul r0, r2
	add r0, r1, r0
	mov r1, #0
	ldr r3, _02231DD8 ; =AGB_GetBoxMonData
	add r2, r1, #0
	bx r3
	.balign 4, 0
_02231DD4: .word 0x0000E880
_02231DD8: .word AGB_GetBoxMonData
	thumb_func_end ov74_02231DB8


	thumb_func_start ov74_02231DDC
ov74_02231DDC: ; 0x02231DDC
	push {r4, r5}
	ldr r5, [sp, #8]
	lsr r4, r5, #0x1f
	add r4, r5, r4
	asr r4, r4, #1
	sub r5, r2, r4
	strb r5, [r0]
	lsr r5, r3, #0x1f
	add r5, r3, r5
	asr r5, r5, #1
	sub r3, r1, r5
	strb r3, [r0, #2]
	add r2, r2, r4
	strb r2, [r0, #1]
	add r1, r1, r5
	strb r1, [r0, #3]
	pop {r4, r5}
	bx lr
	thumb_func_end ov74_02231DDC


	thumb_func_start ov74_02231E00
ov74_02231E00: ; 0x02231E00
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	mov r1, #1
	add r5, r0, #0
	add r0, r3, #0
	lsl r1, r1, #0xc
	add r7, r2, #0
	bl Heap_AllocAtEnd
	add r4, r0, #0
	beq _02231E34
	add r1, r5, #0
	add r2, r6, #0
	bl ReadWholeNarcMemberByIdPair
	add r0, r4, #0
	add r1, r7, #0
	bl NNS_G2dGetUnpackedBGCharacterData
	cmp r0, #0
	bne _02231E34
	add r0, r4, #0
	bl Heap_Free
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02231E34:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_02231E00


	thumb_func_start ov74_02231E38
ov74_02231E38: ; 0x02231E38
	push {r4, r5, r6, lr}
	add r6, r0, #0
	add r5, r1, #0
	add r4, r2, #0
	add r0, r3, #0
	add r1, r6, #0
	bl NARC_ReadWholeMember
	add r0, r4, #0
	add r1, r5, #0
	bl NNS_G2dGetUnpackedBGCharacterData
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov74_02231E38


	thumb_func_start ov74_02231E54
ov74_02231E54: ; 0x02231E54
	push {r4, lr}
	add r3, r1, #0
	mov r4, #0
	cmp r0, #0xc9
	beq _02231E66
	ldr r1, _02231EC0 ; =0x00000182
	cmp r0, r1
	beq _02231E90
	b _02231EBA
_02231E66:
	mov r4, #3
	lsl r0, r4, #8
	add r2, r3, #0
	and r0, r3
	lsr r1, r0, #6
	lsl r0, r4, #0x18
	and r2, r4
	and r0, r3
	lsl r4, r4, #0x10
	and r3, r4
	lsr r0, r0, #0x12
	lsr r3, r3, #0xc
	orr r0, r3
	orr r0, r1
	orr r0, r2
	mov r1, #0x1c
	bl _u32_div_f
	lsl r0, r1, #0x18
	lsr r4, r0, #0x18
	b _02231EBA
_02231E90:
	cmp r2, #5
	bhi _02231EAC
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02231EA0: ; jump table
	.short _02231EAC - _02231EA0 - 2 ; case 0
	.short _02231EAC - _02231EA0 - 2 ; case 1
	.short _02231EAC - _02231EA0 - 2 ; case 2
	.short _02231EB8 - _02231EA0 - 2 ; case 3
	.short _02231EB0 - _02231EA0 - 2 ; case 4
	.short _02231EB4 - _02231EA0 - 2 ; case 5
_02231EAC:
	mov r4, #0
	b _02231EBA
_02231EB0:
	mov r4, #1
	b _02231EBA
_02231EB4:
	mov r4, #2
	b _02231EBA
_02231EB8:
	mov r4, #3
_02231EBA:
	add r0, r4, #0
	pop {r4, pc}
	nop
_02231EC0: .word 0x00000182
	thumb_func_end ov74_02231E54


	thumb_func_start ov74_02231EC4
ov74_02231EC4: ; 0x02231EC4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r2, #0
	add r7, r3, #0
	add r5, r1, #0
	bl TranslateAgbSpecies
	add r1, r6, #0
	add r2, r7, #0
	add r4, r0, #0
	bl ov74_02231E54
	add r7, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	add r2, r7, #0
	bl GetMonIconNaixEx
	add r1, r0, #0
	mov r0, #0x14
	add r2, sp, #0
	mov r3, #0x4c
	bl ov74_02231E00
	add r6, r0, #0
	ldr r0, [sp]
	mov r1, #2
	ldr r0, [r0, #0x14]
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r1, [sp, #0x18]
	ldr r0, [sp]
	lsl r1, r1, #4
	add r1, #0x64
	mov r2, #2
	ldr r0, [r0, #0x14]
	lsl r1, r1, #5
	lsl r2, r2, #8
	bl GX_LoadOBJ
	add r0, r4, #0
	add r1, r7, #0
	add r2, r5, #0
	bl GetMonIconPaletteEx
	add r1, r0, #0
	ldr r0, [sp, #0x1c]
	add r1, #8
	bl Sprite_SetPaletteOverride
	add r0, r6, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_02231EC4


	thumb_func_start ov74_02231F30
ov74_02231F30: ; 0x02231F30
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r1, #0
	ldr r1, _02231FAC ; =ov74_0223D338
	str r2, [sp]
	ldr r2, [r1]
	mov r1, #0x83
	add r5, r3, #0
	lsl r1, r1, #2
	mul r1, r5
	add r4, r2, r1
	ldr r1, [sp, #0x20]
	add r6, r0, #0
	cmp r1, #0
	beq _02231FA4
	bl ov74_02231764
	cmp r0, #0
	bne _02231F60
	add r0, r6, #0
	bl TranslateAgbSpecies
	add r6, r0, #0
	b _02231F62
_02231F60:
	mov r6, #0
_02231F62:
	ldr r2, [sp]
	add r0, r6, #0
	add r1, r7, #0
	bl GetMonIconNaixEx
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	add r1, sp, #4
	bl ov74_02231E38
	ldr r0, [sp, #4]
	add r1, r4, #0
	mov r2, #2
	ldr r0, [r0, #0x14]
	add r1, #0xc
	lsl r2, r2, #8
	bl MIi_CpuCopyFast
	lsl r0, r5, #4
	add r0, #0x64
	lsl r0, r0, #5
	str r0, [r4]
	ldr r0, [sp, #0x20]
	ldr r1, [sp]
	str r0, [r4, #8]
	add r0, r6, #0
	add r2, r7, #0
	bl GetMonIconPaletteEx
	add r0, #8
	add sp, #8
	str r0, [r4, #4]
	pop {r3, r4, r5, r6, r7, pc}
_02231FA4:
	mov r0, #0
	str r0, [r4, #8]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02231FAC: .word ov74_0223D338
	thumb_func_end ov74_02231F30


	thumb_func_start ov74_02231FB0
ov74_02231FB0: ; 0x02231FB0
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _02231FF0 ; =ov74_0223D338
	mov r6, #2
	lsl r6, r6, #8
	add r7, r6, #0
	ldr r5, [r0]
	mov r4, #0
	add r7, #0xc
_02231FC0:
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _02231FE4
	add r0, r5, #0
	add r0, #0xc
	add r1, r6, #0
	bl DC_FlushRange
	add r0, r5, #0
	ldr r1, [r5]
	add r0, #0xc
	add r2, r6, #0
	bl GX_LoadOBJ
	ldr r0, [r5, #8]
	ldr r1, [r5, #4]
	bl Sprite_SetPaletteOverride
_02231FE4:
	add r4, r4, #1
	add r5, r5, r7
	cmp r4, #0x1e
	blt _02231FC0
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02231FF0: .word ov74_0223D338
	thumb_func_end ov74_02231FB0


	thumb_func_start ov74_02231FF4
ov74_02231FF4: ; 0x02231FF4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r6, r0, #0
	mov r0, #0x14
	mov r1, #0x4c
	bl NARC_New
	mov r1, #1
	str r0, [sp, #0x10]
	mov r0, #0x4c
	lsl r1, r1, #0xc
	bl Heap_AllocAtEnd
	mov r7, #0
	str r0, [sp, #0x14]
	str r7, [sp, #0xc]
	add r5, r6, #0
_02232016:
	ldr r0, _02232140 ; =0x0000E880
	ldr r1, _02232144 ; =0x0000E884
	ldr r0, [r6, r0]
	ldr r2, [r6, r1]
	mov r1, #0x96
	lsl r1, r1, #4
	mul r1, r2
	add r0, r0, #4
	add r1, r0, r1
	ldr r0, [sp, #0xc]
	mov r2, #0
	add r0, r1, r0
	mov r1, #5
	bl AGB_GetBoxMonData
	cmp r0, #0
	beq _022320DA
	ldr r1, _02232144 ; =0x0000E884
	add r0, r6, #0
	ldr r1, [r6, r1]
	add r2, r7, #0
	bl ov74_02231D70
	ldr r1, _02232144 ; =0x0000E884
	str r0, [sp, #0x1c]
	ldr r1, [r6, r1]
	add r0, r6, #0
	add r2, r7, #0
	bl ov74_02231D94
	ldr r1, _02232144 ; =0x0000E884
	str r0, [sp, #0x18]
	ldr r1, [r6, r1]
	add r0, r6, #0
	add r2, r7, #0
	bl ov74_02231DB8
	add r4, r0, #0
	ldr r0, [sp, #0x1c]
	bl TranslateAgbSpecies
	ldr r2, _02232148 ; =gSystem + 0x60
	add r1, r4, #0
	ldrb r2, [r2, #0xa]
	bl ov74_02231E54
	add r4, r0, #0
	mov r0, #0x6a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [sp, #0x18]
	str r0, [sp]
	ldr r0, [sp, #0x14]
	add r2, r4, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	add r3, r7, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	bl ov74_02231F30
	mov r0, #0x6a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, _02232140 ; =0x0000E880
	ldr r1, _02232144 ; =0x0000E884
	ldr r0, [r6, r0]
	ldr r2, [r6, r1]
	mov r1, #0x96
	lsl r1, r1, #4
	mul r1, r2
	add r0, r0, #4
	add r1, r0, r1
	ldr r0, [sp, #0xc]
	mov r2, #0
	add r0, r1, r0
	mov r1, #0xc
	bl AGB_GetBoxMonData
	cmp r0, #0
	beq _022320CC
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	b _0223210A
_022320CC:
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0223210A
_022320DA:
	mov r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [sp, #4]
	ldr r0, [sp, #0x10]
	add r2, r4, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x1c]
	add r3, r7, #0
	bl ov74_02231F30
	mov r0, #0x6a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_0223210A:
	ldr r0, [sp, #0xc]
	add r7, r7, #1
	add r0, #0x50
	add r5, #0xc
	str r0, [sp, #0xc]
	cmp r7, #0x1e
	bge _0223211A
	b _02232016
_0223211A:
	ldr r0, [sp, #0x14]
	bl Heap_Free
	ldr r0, [sp, #0x10]
	bl NARC_Delete
	ldr r1, _0223214C ; =ov74_02231FB0
	ldr r0, _02232150 ; =0x00012604
	str r1, [r6, r0]
	ldr r1, _02232144 ; =0x0000E884
	add r0, r6, #0
	ldr r1, [r6, r1]
	bl ov74_02232678
	add r0, r6, #0
	bl ov74_0223262C
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02232140: .word 0x0000E880
_02232144: .word 0x0000E884
_02232148: .word gSystem + 0x60
_0223214C: .word ov74_02231FB0
_02232150: .word 0x00012604
	thumb_func_end ov74_02231FF4


	thumb_func_start ov74_02232154
ov74_02232154: ; 0x02232154
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	mov r2, #0x61
	add r5, r0, #0
	lsl r2, r2, #2
	add r0, sp, #0x14
	add r1, r5, #0
	add r2, r5, r2
	mov r3, #1
	bl ov74_02231D48
	mov r0, #0x28
	str r0, [sp, #8]
	mov r0, #0x31
	mov r4, #0
	lsl r0, r0, #4
	str r4, [sp, #0xc]
	add r7, r5, r0
_02232178:
	mov r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #8]
	mov r6, #0x1c
	lsl r0, r0, #0xc
	str r0, [sp, #4]
_02232184:
	mov r0, #0x1c
	str r0, [sp]
	ldr r2, [sp, #8]
	add r0, r7, #0
	add r1, r6, #0
	mov r3, #0x1c
	bl ov74_02231DDC
	lsl r0, r6, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #4]
	str r0, [sp, #0x20]
	mov r0, #0x6a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _022321B2
	add r0, sp, #0x14
	bl Sprite_CreateAffine
	mov r1, #0x6a
	lsl r1, r1, #2
	str r0, [r5, r1]
_022321B2:
	mov r0, #0x6a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x6a
	lsl r0, r0, #2
	add r1, r4, #0
	ldr r0, [r5, r0]
	add r1, #0xa
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x6a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetPriority
	mov r0, #0x6a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x6a
	lsl r0, r0, #2
	add r1, r4, #0
	ldr r0, [r5, r0]
	add r1, #0x64
	bl Sprite_SetDrawPriority
	mov r0, #6
	ldr r1, [sp, #0x1c]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #0x1c]
	mov r0, #3
	ldr r1, [sp, #0x20]
	lsl r0, r0, #0xe
	add r0, r1, r0
	str r0, [sp, #0x20]
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	bne _0223221C
	add r0, sp, #0x14
	bl Sprite_CreateAffine
	mov r1, #0x6b
	lsl r1, r1, #2
	str r0, [r5, r1]
_0223221C:
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0x28
	bl Sprite_SetAnimCtrlSeq
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetPriority
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl Sprite_SetDrawPriority
	add r4, r4, #1
	add r7, r7, #4
	add r5, #0xc
	cmp r4, #0x1e
	beq _02232280
	ldr r0, [sp, #0x10]
	add r6, #0x28
	add r0, r0, #1
	str r0, [sp, #0x10]
	cmp r0, #6
	blt _02232184
	ldr r0, [sp, #8]
	add r0, #0x18
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	cmp r0, #5
	bge _02232280
	b _02232178
_02232280:
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov74_02232154


	thumb_func_start ov74_02232284
ov74_02232284: ; 0x02232284
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	add r4, r2, #0
	mov r2, #0x61
	add r6, r0, #0
	lsl r2, r2, #2
	add r5, r1, #0
	add r7, r3, #0
	add r0, sp, #0
	add r1, r6, #0
	add r2, r6, r2
	mov r3, #1
	bl ov74_02231D48
	lsl r0, r5, #0xc
	str r0, [sp, #8]
	lsl r0, r4, #0xc
	str r0, [sp, #0xc]
	mov r0, #0xa
	str r0, [sp, #0x24]
	add r0, sp, #0
	bl Sprite_CreateAffine
	add r4, r0, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	add r1, r7, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetPriority
	ldr r1, [sp, #0x48]
	add r0, r4, #0
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_02232284


	thumb_func_start ov74_022322D8
ov74_022322D8: ; 0x022322D8
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0xe2
	lsl r0, r0, #2
	add r0, r6, r0
	mov r1, #0xe4
	mov r2, #0xb0
	mov r3, #0x32
	bl ov74_02231DDC
	mov r0, #1
	str r0, [sp]
	add r0, r6, #0
	mov r1, #0xe4
	mov r2, #0xb0
	mov r3, #6
	bl ov74_02232284
	mov r1, #0xe6
	lsl r1, r1, #2
	str r0, [r6, r1]
	sub r1, #8
	add r0, r6, r1
	mov r1, #0xb0
	mov r3, #0x20
	add r2, r1, #0
	str r3, [sp]
	bl ov74_02231DDC
	mov r0, #1
	mov r1, #0xb0
	str r0, [sp]
	add r0, r6, #0
	add r2, r1, #0
	mov r3, #3
	bl ov74_02232284
	mov r1, #0xea
	lsl r1, r1, #2
	str r0, [r6, r1]
	sub r1, #0x1c
	mov r3, #0x20
	add r0, r6, r1
	mov r1, #0x18
	mov r2, #0xb0
	str r3, [sp]
	bl ov74_02231DDC
	mov r0, #1
	str r0, [sp]
	add r0, r6, #0
	mov r1, #0x18
	mov r2, #0xb0
	mov r3, #0
	bl ov74_02232284
	mov r1, #0xee
	lsl r1, r1, #2
	str r0, [r6, r1]
	mov r7, #0
	mov r0, #0xff
	sub r1, #0x24
	strb r0, [r6, r1]
	add r4, r7, #0
	add r5, r6, #0
_0223235E:
	mov r0, #0
	str r0, [sp]
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0x40
	mov r3, #9
	bl ov74_02232284
	mov r1, #0xf2
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r1, #0
	mov r0, #0xf3
	mvn r1, r1
	lsl r0, r0, #2
	str r1, [r5, r0]
	mov r1, #0xe
	add r0, r0, #4
	str r1, [r5, r0]
	add r7, r7, #1
	add r4, #0x24
	add r5, #0xc
	cmp r7, #6
	blt _0223235E
	mov r0, #0x41
	mov r1, #0
	lsl r0, r0, #4
	str r1, [r6, r0]
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_022322D8


	thumb_func_start ov74_02232398
ov74_02232398: ; 0x02232398
	push {r3, lr}
	ldr r3, _022323CC ; =0x0000E880
	ldr r2, [r0, r3]
	add r3, r3, #4
	ldr r3, [r0, r3]
	mov r0, #0x96
	lsl r0, r0, #4
	add r2, r2, #4
	mul r0, r3
	add r2, r2, r0
	mov r0, #0x50
	mul r0, r1
	add r0, r2, r0
	mov r1, #0x41
	mov r2, #0
	bl AGB_GetBoxMonData
	mov r1, #0x67
	lsl r1, r1, #2
	cmp r0, r1
	bne _022323C6
	mov r0, #1
	pop {r3, pc}
_022323C6:
	mov r0, #0
	pop {r3, pc}
	nop
_022323CC: .word 0x0000E880
	thumb_func_end ov74_02232398


	thumb_func_start ov74_022323D0
ov74_022323D0: ; 0x022323D0
	push {r3, r4, r5, r6, r7, lr}
	ldr r3, _0223241C ; =0x0000E880
	mov r5, #0
	ldr r2, [r0, r3]
	add r3, r3, #4
	ldr r3, [r0, r3]
	mov r0, #0x96
	lsl r0, r0, #4
	add r2, r2, #4
	mul r0, r3
	add r4, r2, r0
	mov r0, #0x50
	add r6, r1, #0
	mul r6, r0
	add r7, r5, #0
_022323EE:
	add r1, r5, #0
	add r0, r4, r6
	add r1, #0xd
	add r2, r7, #0
	bl AGB_GetBoxMonData
	ldr r3, _02232420 ; =ov74_0223C998
	add r2, r0, #0
	mov r1, #0
_02232400:
	ldr r0, [r3]
	cmp r2, r0
	bne _0223240A
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0223240A:
	add r1, r1, #1
	add r3, r3, #4
	cmp r1, #8
	blo _02232400
	add r5, r5, #1
	cmp r5, #4
	blt _022323EE
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0223241C: .word 0x0000E880
_02232420: .word ov74_0223C998
	thumb_func_end ov74_022323D0


	thumb_func_start ov74_02232424
ov74_02232424: ; 0x02232424
	push {r3, lr}
	ldr r3, _02232468 ; =0x0000E880
	ldr r2, [r0, r3]
	add r3, r3, #4
	ldr r3, [r0, r3]
	mov r0, #0x96
	lsl r0, r0, #4
	add r2, r2, #4
	mul r0, r3
	add r2, r2, r0
	mov r0, #0x50
	mul r0, r1
	add r0, r2, r0
	mov r1, #0xc
	mov r2, #0
	bl AGB_GetBoxMonData
	ldr r1, _0223246C ; =ov74_0223C9A8
	ldrh r1, [r1, #0x30]
	cmp r1, #0
	beq _02232462
	ldr r2, _02232470 ; =ov74_0223C9D8
_02232450:
	ldrh r1, [r2]
	cmp r0, r1
	bne _0223245A
	mov r0, #1
	pop {r3, pc}
_0223245A:
	add r2, r2, #2
	ldrh r1, [r2]
	cmp r1, #0
	bne _02232450
_02232462:
	mov r0, #0
	pop {r3, pc}
	nop
_02232468: .word 0x0000E880
_0223246C: .word ov74_0223C9A8
_02232470: .word ov74_0223C9D8
	thumb_func_end ov74_02232424


	thumb_func_start ov74_02232474
ov74_02232474: ; 0x02232474
	push {r3, lr}
	ldr r3, _0223249C ; =0x0000E880
	ldr r2, [r0, r3]
	add r3, r3, #4
	ldr r3, [r0, r3]
	mov r0, #0x96
	lsl r0, r0, #4
	add r2, r2, #4
	mul r0, r3
	add r2, r2, r0
	mov r0, #0x50
	mul r0, r1
	add r0, r2, r0
	mov r1, #0xb
	mov r2, #0
	bl AGB_GetBoxMonData
	bl ov74_02231764
	pop {r3, pc}
	.balign 4, 0
_0223249C: .word 0x0000E880
	thumb_func_end ov74_02232474


	thumb_func_start ov74_022324A0
ov74_022324A0: ; 0x022324A0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r4, r0, #0
	mov r0, #0x6a
	lsl r0, r0, #2
	add r0, r4, r0
	str r0, [sp]
	add r6, r1, #0
	mov r0, #0xc
	mul r0, r6
	ldr r1, [sp]
	str r0, [sp, #4]
	ldr r0, [r1, r0]
	cmp r0, #0
	beq _022324CC
	bl Sprite_GetDrawFlag
	cmp r0, #0
	bne _022324CC
	add sp, #0x14
	mov r0, #3
	pop {r4, r5, r6, r7, pc}
_022324CC:
	mov r5, #0
	mov r7, #0x3d
	mvn r5, r5
	mov r2, #0
	add r3, r4, #0
	lsl r7, r7, #4
	b _022324F4
_022324DA:
	ldr r0, _02232628 ; =0x0000E884
	ldr r1, [r4, r0]
	ldr r0, [r3, r7]
	cmp r1, r0
	bne _022324F0
	mov r0, #0xf3
	lsl r0, r0, #2
	ldr r0, [r3, r0]
	cmp r6, r0
	bne _022324F0
	add r5, r2, #0
_022324F0:
	add r3, #0xc
	add r2, r2, #1
_022324F4:
	mov r0, #0
	mvn r0, r0
	cmp r5, r0
	bne _02232500
	cmp r2, #6
	blt _022324DA
_02232500:
	add r0, r4, #0
	add r1, r6, #0
	bl ov74_02232398
	cmp r0, #1
	bne _02232512
	add sp, #0x14
	mov r0, #4
	pop {r4, r5, r6, r7, pc}
_02232512:
	add r0, r4, #0
	add r1, r6, #0
	bl ov74_022323D0
	cmp r0, #1
	bne _02232524
	add sp, #0x14
	mov r0, #5
	pop {r4, r5, r6, r7, pc}
_02232524:
	add r0, r4, #0
	add r1, r6, #0
	bl ov74_02232424
	cmp r0, #1
	bne _02232536
	add sp, #0x14
	mov r0, #6
	pop {r4, r5, r6, r7, pc}
_02232536:
	add r0, r4, #0
	add r1, r6, #0
	bl ov74_02232474
	cmp r0, #1
	bne _02232548
	add sp, #0x14
	mov r0, #7
	pop {r4, r5, r6, r7, pc}
_02232548:
	mov r0, #0
	mvn r0, r0
	cmp r5, r0
	bne _022325F0
	mov r0, #0x41
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	cmp r0, #6
	bne _02232560
	add sp, #0x14
	mov r0, #0
	pop {r4, r5, r6, r7, pc}
_02232560:
	mov r5, #0
	mov r0, #0xf3
	add r3, r4, #0
	lsl r0, r0, #2
	sub r1, r5, #1
_0223256A:
	ldr r2, [r3, r0]
	cmp r2, r1
	bne _022325E6
	ldr r1, [sp]
	ldr r0, [sp, #4]
	ldr r0, [r1, r0]
	bl Sprite_GetMatrixPtr
	add r1, r0, #0
	mov r0, #0xc
	add r7, r5, #0
	mul r7, r0
	mov r0, #0xf2
	lsl r0, r0, #2
	add r5, r4, r0
	ldr r0, [r5, r7]
	bl Sprite_SetMatrix
	ldr r0, [r5, r7]
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	add r2, sp, #8
	ldmia r3!, {r0, r1}
	mov ip, r2
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, #2
	str r0, [r2]
	ldr r0, [sp, #8]
	lsl r1, r1, #0xe
	sub r0, r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	lsr r1, r1, #1
	sub r0, r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r5, r7]
	mov r1, ip
	bl Sprite_SetMatrix
	ldr r0, [r5, r7]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r1, #0xf3
	add r3, r4, r7
	lsl r1, r1, #2
	ldr r0, _02232628 ; =0x0000E884
	str r6, [r3, r1]
	ldr r2, [r4, r0]
	add r0, r1, #4
	str r2, [r3, r0]
	add r0, r1, #0
	add r0, #0x44
	ldr r0, [r4, r0]
	add r1, #0x44
	add r0, r0, #1
	str r0, [r4, r1]
	add sp, #0x14
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_022325E6:
	add r5, r5, #1
	add r3, #0xc
	cmp r5, #6
	blt _0223256A
	b _02232622
_022325F0:
	mov r0, #0xc
	add r6, r5, #0
	mul r6, r0
	mov r0, #0xf2
	add r1, r4, r6
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r2, #0
	mov r1, #0xf3
	mvn r2, r2
	add r0, r4, r6
	lsl r1, r1, #2
	str r2, [r0, r1]
	add r0, r1, #0
	add r0, #0x44
	ldr r0, [r4, r0]
	add r1, #0x44
	sub r0, r0, #1
	str r0, [r4, r1]
	add sp, #0x14
	mov r0, #2
	pop {r4, r5, r6, r7, pc}
_02232622:
	mov r0, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02232628: .word 0x0000E884
	thumb_func_end ov74_022324A0


	thumb_func_start ov74_0223262C
ov74_0223262C: ; 0x0223262C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r4, #0
	add r5, r6, #0
	sub r7, r4, #1
_02232636:
	mov r0, #0xf3
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, r7
	beq _0223265C
	ldr r0, _02232674 ; =0x0000E884
	ldr r1, [r6, r0]
	mov r0, #0x3d
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r1, r0
	bne _0223265C
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	b _02232668
_0223265C:
	mov r0, #0xf2
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
_02232668:
	add r4, r4, #1
	add r5, #0xc
	cmp r4, #6
	blt _02232636
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02232674: .word 0x0000E884
	thumb_func_end ov74_0223262C


	thumb_func_start ov74_02232678
ov74_02232678: ; 0x02232678
	push {r3, r4, r5, lr}
	sub sp, #0x60
	add r5, r0, #0
	mov r0, #0
	add r4, r1, #0
	add r3, sp, #0x14
	add r1, r0, #0
	mov r2, #4
_02232688:
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02232688
	stmia r3!, {r0, r1}
	str r0, [r3]
	ldr r0, _022326F0 ; =0x00000478
	add r0, r5, r0
	str r0, [sp, #0x14]
	mov r0, #6
	str r0, [sp, #0x1c]
	mov r0, #0x15
	str r0, [sp, #0x20]
	mov r0, #0xd
	str r0, [sp, #0x24]
	mov r0, #2
	str r0, [sp, #0x28]
	sub r0, r0, #3
	str r0, [sp, #0x48]
	mov r0, #0
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	mov r0, #1
	str r0, [sp, #0x38]
	str r0, [sp, #0x3c]
	ldr r0, _022326F4 ; =0x00010200
	str r0, [sp, #0x40]
	mov r0, #0xa0
	str r0, [sp, #0x34]
	bl PmAgbCartridge_GetLanguage
	add r3, r0, #0
	ldr r0, _022326F8 ; =0x0000E880
	mov r2, #9
	ldr r1, [r5, r0]
	ldr r0, _022326FC ; =0x00008344
	add r1, r1, r0
	lsl r0, r4, #3
	add r0, r4, r0
	add r0, r1, r0
	add r1, sp, #0
	bl ConvertRSStringToDPStringInternational
	add r0, sp, #0
	str r0, [sp, #0x4c]
	add r0, r5, #0
	add r1, sp, #0x14
	mov r2, #1
	bl ov74_02231A1C
	add sp, #0x60
	pop {r3, r4, r5, pc}
	.balign 4, 0
_022326F0: .word 0x00000478
_022326F4: .word 0x00010200
_022326F8: .word 0x0000E880
_022326FC: .word 0x00008344
	thumb_func_end ov74_02232678


	thumb_func_start ov74_02232700
ov74_02232700: ; 0x02232700
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r6, r1, #0
	mov r1, #2
	bl GetBgTilemapBuffer
	add r4, r0, #0
	cmp r6, #0
	beq _02232724
	add r0, r6, #0
	mov r1, #8
	mov r2, #0
	bl AGB_GetBoxMonData
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	b _02232726
_02232724:
	mov r1, #0
_02232726:
	mov r2, #0
	mov r0, #1
_0223272A:
	add r3, r1, #0
	tst r3, r0
	beq _02232736
	add r6, r2, #0
	add r6, #0x80
	b _0223273A
_02232736:
	add r6, r2, #0
	add r6, #0x60
_0223273A:
	add r3, r4, #0
	add r3, #0xd6
	lsl r1, r1, #0x17
	add r2, r2, #1
	strh r6, [r3]
	lsr r1, r1, #0x18
	add r4, r4, #2
	cmp r2, #4
	blt _0223272A
	ldr r0, [r5, #0x20]
	mov r1, #2
	bl BgCommitTilemapBufferToVram
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov74_02232700


	thumb_func_start ov74_02232758
ov74_02232758: ; 0x02232758
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x78
	add r5, r0, #0
	mov r0, #0
	add r4, r1, #0
	add r3, sp, #0x2c
	add r1, r0, #0
	mov r2, #4
_02232768:
	stmia r3!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02232768
	stmia r3!, {r0, r1}
	str r0, [r3]
	mov r1, #0x20
	str r1, [sp, #0x3c]
	mov r1, #1
	ldr r0, _02232908 ; =0x00000488
	str r1, [sp, #0x50]
	str r1, [sp, #0x54]
	mov r1, #0xbc
	str r1, [sp, #0x4c]
	ldr r1, _0223290C ; =0x000F0200
	add r0, r5, r0
	str r1, [sp, #0x58]
	mov r1, #0x2c
	str r0, [sp, #0x2c]
	mov r0, #0
	str r1, [sp, #0x60]
	mov r1, #0x90
	mov r2, #4
	str r1, [sp, #0x44]
	str r0, [sp, #0x34]
	str r0, [sp, #0x38]
	str r0, [sp, #0x64]
	str r0, [sp, #0x48]
	add r0, r5, #0
	add r1, sp, #0x2c
	str r2, [sp, #0x40]
	bl ov74_02231A1C
	mov r0, #0x2b
	str r0, [sp, #0x60]
	mov r0, #0x50
	str r0, [sp, #0x44]
	mov r0, #8
	str r0, [sp, #0x48]
	add r0, r5, #0
	add r1, sp, #0x2c
	mov r2, #6
	bl ov74_02231A1C
	add r0, r5, #0
	add r1, r4, #0
	bl ov74_02232700
	cmp r4, #0
	bne _022327D6
	ldr r0, [sp, #0x2c]
	bl CopyWindowToVram
	add sp, #0x78
	pop {r3, r4, r5, r6, r7, pc}
_022327D6:
	add r2, sp, #0x1c
	add r0, r4, #0
	mov r1, #2
	add r2, #2
	bl AGB_GetBoxMonData
	add r0, r4, #0
	mov r1, #3
	mov r2, #0
	bl AGB_GetBoxMonData
	add r3, r0, #0
	add r0, sp, #0x1c
	add r0, #2
	add r1, sp, #8
	mov r2, #0xb
	bl ConvertRSStringToDPStringInternational
	add r0, sp, #8
	str r0, [sp, #0x64]
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x60]
	mov r0, #8
	str r0, [sp, #0x44]
	mov r0, #0
	str r0, [sp, #0x48]
	add r0, r5, #0
	add r1, sp, #0x2c
	mov r2, #6
	bl ov74_02231A1C
	mov r0, #0x40
	mov r1, #0x4c
	bl String_New
	add r6, r0, #0
	mov r0, #1
	mov r1, #0x1b
	mov r2, #0xed
	mov r3, #0x4c
	bl NewMsgDataFromNarc
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #0xb
	mov r2, #0
	bl AGB_GetBoxMonData
	bl TranslateAgbSpecies
	str r0, [sp, #4]
	ldr r1, [sp, #4]
	add r0, r7, #0
	add r2, r6, #0
	bl ReadMsgDataIntoString
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x60]
	mov r0, #0x10
	str r0, [sp, #0x44]
	str r0, [sp, #0x48]
	add r0, r5, #0
	add r1, sp, #0x2c
	mov r2, #6
	str r6, [sp, #0x68]
	bl ov74_02231A1C
	add r0, r7, #0
	bl DestroyMsgData
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	mov r1, #0xc
	mov r2, #0
	bl AGB_GetBoxMonData
	cmp r0, #0
	beq _022328B8
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl UpConvertItemId_Gen3to4
	add r7, r0, #0
	mov r0, #0x40
	mov r1, #0x4c
	bl String_New
	lsl r1, r7, #0x10
	lsr r1, r1, #0x10
	mov r2, #0x4c
	add r6, r0, #0
	bl GetItemNameIntoString
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x60]
	mov r0, #0x98
	str r0, [sp, #0x44]
	mov r0, #0x10
	str r0, [sp, #0x48]
	add r0, r5, #0
	add r1, sp, #0x2c
	mov r2, #6
	str r6, [sp, #0x68]
	bl ov74_02231A1C
	add r0, r6, #0
	bl String_Delete
_022328B8:
	add r0, r4, #0
	bl ov74_02234A0C
	add r6, r0, #0
	mov r0, #0xa
	mov r1, #0x4c
	bl String_New
	mov r3, #1
	add r1, r6, #0
	mov r2, #3
	add r4, r0, #0
	str r3, [sp]
	bl String16_FormatInteger
	mov r0, #0
	mvn r0, r0
	str r0, [sp, #0x60]
	mov r0, #0x64
	str r0, [sp, #0x44]
	mov r0, #8
	str r0, [sp, #0x48]
	add r0, r5, #0
	add r1, sp, #0x2c
	mov r2, #2
	str r4, [sp, #0x68]
	bl ov74_02231A1C
	add r0, r4, #0
	bl String_Delete
	ldr r0, [sp, #4]
	mov r1, #0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl PlayCry
	add sp, #0x78
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02232908: .word 0x00000488
_0223290C: .word 0x000F0200
	thumb_func_end ov74_02232758


	thumb_func_start ov74_02232910
ov74_02232910: ; 0x02232910
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x4c
	str r0, [sp, #8]
	add r6, r2, #0
	mov r0, #0
	add r4, r3, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	cmp r4, #0
	beq _02232938
	mov r0, #0x17
	str r0, [r4]
_02232938:
	str r6, [r5, #0x24]
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov74_02232910


	thumb_func_start ov74_02232940
ov74_02232940: ; 0x02232940
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	add r4, r3, #0
	str r0, [sp, #4]
	mov r0, #0x4c
	add r6, r2, #0
	str r0, [sp, #8]
	ldr r3, _02232970 ; =0x00007FFF
	mov r0, #0
	add r2, r1, #0
	bl BeginNormalPaletteFade
	cmp r4, #0
	beq _02232968
	mov r0, #0x17
	str r0, [r4]
_02232968:
	str r6, [r5, #0x24]
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	nop
_02232970: .word 0x00007FFF
	thumb_func_end ov74_02232940


	thumb_func_start ov74_02232974
ov74_02232974: ; 0x02232974
	push {r3, r4, r5, lr}
	sub sp, #0x80
	ldr r5, _02232A34 ; =_0223B4F8
	add r3, sp, #0x70
	add r4, r0, #0
	add r2, r3, #0
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r5, _02232A38 ; =_0223B508
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
	ldr r5, _02232A3C ; =_0223B524
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
	ldr r5, _02232A40 ; =_0223B540
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
	ldr r5, _02232A44 ; =_0223B55C
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
_02232A34: .word _0223B4F8
_02232A38: .word _0223B508
_02232A3C: .word _0223B524
_02232A40: .word _0223B540
_02232A44: .word _0223B55C
	thumb_func_end ov74_02232974


	thumb_func_start ov74_02232A48
ov74_02232A48: ; 0x02232A48
	push {r3, r4, r5, lr}
	sub sp, #0x38
	ldr r5, _02232AC0 ; =_0223B578
	add r4, r0, #0
	add r3, sp, #0x10
	mov r2, #5
_02232A54:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02232A54
	add r0, sp, #0x10
	bl GfGfx_SetBanks
	ldr r0, [r4, #0x20]
	bl ov74_02232974
	ldr r0, _02232AC4 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	bl ResetAllTextPrinters
	mov r1, #0x1e
	mov r0, #0
	lsl r1, r1, #4
	mov r2, #0x4c
	bl LoadFontPal0
	mov r0, #0xc0
	str r0, [sp]
	mov r0, #0x4c
	mov r2, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0x17
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPal
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x4c
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x20]
	mov r0, #0x71
	mov r1, #0x1a
	mov r3, #2
	bl GfGfxLoader_LoadCharData
	mov r0, #2
	mov r1, #0x4c
	bl FontID_Alloc
	add sp, #0x38
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02232AC0: .word _0223B578
_02232AC4: .word gSystem + 0x60
	thumb_func_end ov74_02232A48


	thumb_func_start ov74_02232AC8
ov74_02232AC8: ; 0x02232AC8
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x4c
	str r0, [sp, #0xc]
	ldr r2, [r4, #0x20]
	mov r0, #0x71
	mov r1, #0x18
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r2, #0
	ldr r1, [r4]
	ldr r0, _02232B14 ; =ov74_0223C960
	add r3, r2, #0
	ldrb r0, [r0, r1]
	mov r1, #2
	str r0, [sp, #8]
	ldr r0, [r4, #0x20]
	bl BgTilemapRectChangePalette
	ldr r0, [r4, #0x20]
	mov r1, #2
	bl BgCommitTilemapBufferToVram
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_02232B14: .word ov74_0223C960
	thumb_func_end ov74_02232AC8


	thumb_func_start ov74_02232B18
ov74_02232B18: ; 0x02232B18
	push {r4, lr}
	sub sp, #8
	mov r1, #7
	add r4, r0, #0
	mov r0, #0
	lsl r1, r1, #6
	mov r2, #0x4c
	bl LoadFontPal0
	mov r1, #0
	mov r2, #0x3f
	str r1, [sp]
	mov r0, #0x4c
	str r0, [sp, #4]
	ldr r0, [r4, #0x20]
	lsl r2, r2, #4
	mov r3, #0xe
	bl LoadUserFrameGfx1
	ldr r0, [r4, #0x1c]
	ldr r2, _02232BC0 ; =0x000003D2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x4c
	str r0, [sp, #4]
	ldr r0, [r4, #0x20]
	mov r1, #0
	mov r3, #0xd
	bl LoadUserFrameGfx2
	ldr r0, _02232BC4 ; =0x0000042C
	mov r1, #0
	add r0, r4, r0
	mov r2, #0x4c
	bl memset
	ldr r0, _02232BC8 ; =0x00000498
	mov r3, #0x1b
	add r1, r0, #0
	add r2, r4, r0
	sub r1, #0x6c
	str r2, [r4, r1]
	add r1, r0, #0
	mov r2, #2
	sub r1, #0x64
	str r2, [r4, r1]
	add r1, r0, #0
	mov r2, #1
	sub r1, #0x60
	str r2, [r4, r1]
	add r1, r0, #0
	sub r1, #0x5c
	str r3, [r4, r1]
	add r1, r0, #0
	mov r3, #4
	sub r1, #0x58
	str r3, [r4, r1]
	add r3, r0, #0
	mov r1, #0
	sub r3, #0x48
	str r1, [r4, r3]
	add r3, r0, #0
	sub r3, #0x44
	str r2, [r4, r3]
	add r3, r0, #0
	sub r3, #0x4c
	str r2, [r4, r3]
	add r2, r0, #0
	ldr r3, _02232BCC ; =0x0001020F
	sub r2, #0x40
	str r3, [r4, r2]
	add r2, r0, #0
	ldr r3, _02232BD0 ; =0x000F020F
	sub r2, #0x3c
	str r3, [r4, r2]
	add r2, r0, #0
	sub r2, #0x34
	str r1, [r4, r2]
	sub r0, #0x30
	str r1, [r4, r0]
	add sp, #8
	pop {r4, pc}
	nop
_02232BC0: .word 0x000003D2
_02232BC4: .word 0x0000042C
_02232BC8: .word 0x00000498
_02232BCC: .word 0x0001020F
_02232BD0: .word 0x000F020F
	thumb_func_end ov74_02232B18


	thumb_func_start ov74_02232BD4
ov74_02232BD4: ; 0x02232BD4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	add r6, r0, #0
	mov r7, #0x6b
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_02232BE2:
	mov r0, #0x6a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r4, r7]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r5, r5, #1
	add r4, #0xc
	cmp r5, #0x1e
	blt _02232BE2
	mov r7, #0xf2
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_02232C06:
	ldr r0, [r4, r7]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r5, r5, #1
	add r4, #0xc
	cmp r5, #6
	blt _02232C06
	mov r0, #0xe6
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0xee
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	mov r2, #0x61
	lsl r2, r2, #2
	add r0, sp, #0x1c
	add r1, r6, #0
	add r2, r6, r2
	mov r3, #1
	bl ov74_02231D48
	mov r0, #0x1c
	mov r7, #0
	str r0, [sp, #0x10]
	add r4, r6, #0
	add r5, r6, #0
_02232C54:
	ldr r0, [sp, #0x10]
	lsl r0, r0, #0xc
	str r0, [sp, #0x24]
	mov r0, #0x8e
	lsl r0, r0, #0xc
	str r0, [sp, #0x28]
	add r0, sp, #0x1c
	bl Sprite_CreateAffine
	ldr r1, _02232D94 ; =0x00000414
	str r0, [r4, r1]
	add r0, r1, #0
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	ldr r0, _02232D94 ; =0x00000414
	add r1, r7, #0
	ldr r0, [r4, r0]
	add r1, #0xa
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _02232D94 ; =0x00000414
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetPriority
	ldr r0, _02232D94 ; =0x00000414
	mov r1, #1
	ldr r0, [r4, r0]
	bl Sprite_SetDrawFlag
	mov r1, #0x3d
	mov r2, #0xf3
	lsl r1, r1, #4
	lsl r2, r2, #2
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	add r0, r6, #0
	bl ov74_02231D70
	mov r1, #0x3d
	mov r2, #0xf3
	lsl r1, r1, #4
	lsl r2, r2, #2
	str r0, [sp, #0x14]
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	add r0, r6, #0
	bl ov74_02231D94
	mov r1, #0x3d
	mov r2, #0xf3
	lsl r1, r1, #4
	lsl r2, r2, #2
	str r0, [sp, #0x18]
	ldr r1, [r5, r1]
	ldr r2, [r5, r2]
	add r0, r6, #0
	bl ov74_02231DB8
	add r2, r0, #0
	ldr r0, _02232D94 ; =0x00000414
	str r7, [sp]
	ldr r0, [r4, r0]
	ldr r3, _02232D98 ; =gSystem + 0x60
	str r0, [sp, #4]
	ldrb r3, [r3, #0xa]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	bl ov74_02231EC4
	ldr r0, [sp, #0x10]
	add r7, r7, #1
	add r0, #0x28
	str r0, [sp, #0x10]
	add r4, r4, #4
	add r5, #0xc
	cmp r7, #6
	blt _02232C54
	mov r0, #0
	str r0, [sp]
	mov r0, #6
	lsl r0, r0, #8
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x4c
	str r0, [sp, #0xc]
	ldr r2, [r6, #0x20]
	mov r0, #0x71
	mov r1, #0x19
	mov r3, #2
	bl GfGfxLoader_LoadScrnData
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	mov r2, #0
	ldr r1, [r6]
	ldr r0, _02232D9C ; =ov74_0223C960
	add r3, r2, #0
	ldrb r0, [r0, r1]
	mov r1, #2
	str r0, [sp, #8]
	ldr r0, [r6, #0x20]
	bl BgTilemapRectChangePalette
	ldr r0, [r6, #0x20]
	mov r1, #2
	bl BgCommitTilemapBufferToVram
	mov r0, #2
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r1, #7
	mov r0, #0
	lsl r1, r1, #6
	mov r2, #0x4c
	bl LoadFontPal0
	mov r1, #0
	mov r2, #0x3f
	str r1, [sp]
	mov r0, #0x4c
	str r0, [sp, #4]
	ldr r0, [r6, #0x20]
	lsl r2, r2, #4
	mov r3, #0xe
	bl LoadUserFrameGfx1
	ldr r0, [r6, #0x1c]
	ldr r2, _02232DA0 ; =0x000003D2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x4c
	str r0, [sp, #4]
	ldr r0, [r6, #0x20]
	mov r1, #0
	mov r3, #0xd
	bl LoadUserFrameGfx2
	add r0, r6, #0
	bl ov74_02232B18
	mov r1, #0x46
	mov r0, #0xa
	lsl r1, r1, #4
	str r0, [r6, r1]
	sub r1, #0x34
	add r0, r6, #0
	add r1, r6, r1
	mov r2, #0x18
	bl ov74_02231A1C
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02232D94: .word 0x00000414
_02232D98: .word gSystem + 0x60
_02232D9C: .word ov74_0223C960
_02232DA0: .word 0x000003D2
	thumb_func_end ov74_02232BD4


	thumb_func_start ov74_02232DA4
ov74_02232DA4: ; 0x02232DA4
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4]
	cmp r1, #0
	beq _02232DC0
	mov r1, #0
	bl ClearFrameAndWindow2
	add r0, r4, #0
	bl ClearWindowTilemapAndCopyToVram
	add r0, r4, #0
	bl RemoveWindow
_02232DC0:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov74_02232DA4


	thumb_func_start ov74_02232DC4
ov74_02232DC4: ; 0x02232DC4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r7, _02232E34 ; =0x00000414
	mov r4, #0
	add r5, r6, #0
_02232DCE:
	ldr r0, [r5, r7]
	bl Sprite_Delete
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blt _02232DCE
	mov r0, #2
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, _02232E38 ; =0x00000498
	add r0, r6, r0
	bl ov74_02232DA4
	mov r0, #0xe6
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xee
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xf3
	mov r5, #0
	lsl r0, r0, #2
	add r4, r6, #0
	sub r3, r5, #1
	mov r2, #0xe
	add r1, r0, #4
_02232E1E:
	str r3, [r4, r0]
	str r2, [r4, r1]
	add r5, r5, #1
	add r4, #0xc
	cmp r5, #6
	blt _02232E1E
	mov r0, #0x41
	mov r1, #0
	lsl r0, r0, #4
	str r1, [r6, r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02232E34: .word 0x00000414
_02232E38: .word 0x00000498
	thumb_func_end ov74_02232DC4


	thumb_func_start ov74_02232E3C
ov74_02232E3C: ; 0x02232E3C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r7, #0x6a
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_02232E50:
	ldr r0, [r5, r7]
	cmp r0, #0
	beq _02232E5A
	bl Sprite_Delete
_02232E5A:
	mov r0, #0x6b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02232E68
	bl Sprite_Delete
_02232E68:
	add r4, r4, #1
	add r5, #0xc
	cmp r4, #0x1e
	blt _02232E50
	mov r7, #0xf2
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_02232E78:
	ldr r0, [r4, r7]
	cmp r0, #0
	beq _02232E82
	bl Sprite_Delete
_02232E82:
	add r5, r5, #1
	add r4, #0xc
	cmp r5, #6
	blt _02232E78
	mov r0, #0xe6
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	beq _02232E98
	bl Sprite_Delete
_02232E98:
	mov r0, #0xee
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	beq _02232EA6
	bl Sprite_Delete
_02232EA6:
	mov r0, #0xea
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	beq _02232EB4
	bl Sprite_Delete
_02232EB4:
	ldr r0, _02232F48 ; =0x00000478
	add r0, r6, r0
	bl ov74_02232DA4
	ldr r0, _02232F4C ; =0x00000488
	add r0, r6, r0
	bl ov74_02232DA4
	ldr r0, _02232F50 ; =0x00000498
	add r0, r6, r0
	bl ov74_02232DA4
	mov r0, #2
	bl FontID_Release
	mov r0, #0x5b
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r7, #0x55
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_02232EEE:
	ldr r0, [r4, r7]
	bl Destroy2DGfxResObjMan
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #6
	blt _02232EEE
	ldr r0, [r6, #0x28]
	bl SpriteList_Delete
	mov r0, #0
	str r0, [r6, #0x28]
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	ldr r0, _02232F54 ; =0x0000E88C
	ldr r0, [r6, r0]
	bl YesNoPrompt_Destroy
	ldr r0, _02232F58 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	ldr r0, [r6, #0x20]
	mov r1, #0
	bl FreeBgTilemapBuffer
	ldr r0, [r6, #0x20]
	mov r1, #1
	bl FreeBgTilemapBuffer
	ldr r0, [r6, #0x20]
	mov r1, #2
	bl FreeBgTilemapBuffer
	ldr r0, [r6, #0x20]
	mov r1, #3
	bl FreeBgTilemapBuffer
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02232F48: .word 0x00000478
_02232F4C: .word 0x00000488
_02232F50: .word 0x00000498
_02232F54: .word 0x0000E88C
_02232F58: .word gSystem + 0x60
	thumb_func_end ov74_02232E3C


	thumb_func_start ov74_02232F5C
ov74_02232F5C: ; 0x02232F5C
	push {lr}
	sub sp, #0x14
	ldr r1, [r0, #0x20]
	mov r3, #0
	str r1, [sp]
	mov r1, #2
	lsl r1, r1, #8
	str r1, [sp, #8]
	mov r1, #8
	str r1, [sp, #0xc]
	str r3, [sp, #4]
	mov r1, #0x19
	add r2, sp, #0
	strb r1, [r2, #0x10]
	mov r1, #7
	strb r1, [r2, #0x11]
	strb r3, [r2, #0x13]
	ldrb r3, [r2, #0x12]
	mov r1, #0xf0
	bic r3, r1
	mov r1, #0x10
	orr r1, r3
	strb r1, [r2, #0x12]
	ldr r1, _02232F98 ; =0x0000E88C
	ldr r0, [r0, r1]
	add r1, sp, #0
	bl YesNoPrompt_InitFromTemplate
	add sp, #0x14
	pop {pc}
	.balign 4, 0
_02232F98: .word 0x0000E88C
	thumb_func_end ov74_02232F5C


	thumb_func_start ov74_02232F9C
ov74_02232F9C: ; 0x02232F9C
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r5, r0, #0
	bl ov74_02233F84
	add r4, r0, #0
	bl PmAgbCartridge_GetLanguage
	add r3, r0, #0
	add r0, r4, #0
	add r1, sp, #8
	mov r2, #8
	bl ConvertRSStringToDPStringInternational
	mov r0, #0x4c
	bl MessageFormat_New
	add r4, r0, #0
	mov r0, #8
	mov r1, #0x4c
	bl String_New
	add r1, sp, #8
	add r6, r0, #0
	bl CopyU16ArrayToString
	mov r1, #1
	str r1, [sp]
	mov r0, #2
	str r0, [sp, #4]
	add r0, r4, #0
	add r2, r6, #0
	mov r3, #0
	bl BufferString
	add r0, r5, #0
	bl ov74_02232B18
	ldr r0, [r5]
	mov r2, #0x18
	lsl r1, r0, #2
	ldr r0, _02233020 ; =ov74_0223C980
	ldr r0, [r0, r1]
	mov r1, #0x46
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	add r0, #0xc
	sub r1, #0x34
	str r4, [r5, r0]
	add r0, r5, #0
	add r1, r5, r1
	bl ov74_02231A1C
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	bl MessageFormat_Delete
	add r0, r5, #0
	bl ov74_02232F5C
	add sp, #0x18
	pop {r4, r5, r6, pc}
	nop
_02233020: .word ov74_0223C980
	thumb_func_end ov74_02232F9C


	thumb_func_start ov74_02233024
ov74_02233024: ; 0x02233024
	push {r4, lr}
	add r4, r0, #0
	ldr r0, _02233054 ; =0x00012604
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02233038
	blx r0
	ldr r0, _02233054 ; =0x00012604
	mov r1, #0
	str r1, [r4, r0]
_02233038:
	bl GF_RunVramTransferTasks
	bl OamManager_ApplyAndResetBuffers
	ldr r0, [r4, #0x20]
	bl DoScheduledBgGpuUpdates
	ldr r3, _02233058 ; =0x027E0000
	ldr r1, _0223305C ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	.balign 4, 0
_02233054: .word 0x00012604
_02233058: .word 0x027E0000
_0223305C: .word 0x00003FF8
	thumb_func_end ov74_02233024


	thumb_func_start ov74_02233060
ov74_02233060: ; 0x02233060
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	ldr r0, [r0, #0x10]
	bl Save_MigratedPokemon_Get
	mov r6, #0
	str r0, [sp, #8]
	str r6, [sp, #4]
	add r7, r6, #0
_02233074:
	mov r4, #0
	add r5, r4, #0
_02233078:
	ldr r1, [sp]
	ldr r0, _022330CC ; =0x0000E880
	mov r2, #0
	ldr r0, [r1, r0]
	mov r1, #5
	add r0, r0, #4
	add r0, r0, r7
	add r0, r0, r5
	bl AGB_GetBoxMonData
	cmp r0, #0
	beq _02233092
	add r6, r6, #1
_02233092:
	add r4, r4, #1
	add r5, #0x50
	cmp r4, #0x1e
	blt _02233078
	mov r0, #0x96
	lsl r0, r0, #4
	add r7, r7, r0
	ldr r0, [sp, #4]
	add r0, r0, #1
	str r0, [sp, #4]
	cmp r0, #0xe
	blt _02233074
	cmp r6, #6
	bge _022330B4
	add sp, #0xc
	mov r0, #5
	pop {r4, r5, r6, r7, pc}
_022330B4:
	ldr r0, [sp, #8]
	bl MigratedPokemon_CountPokemon
	cmp r0, #0
	beq _022330C4
	add sp, #0xc
	mov r0, #6
	pop {r4, r5, r6, r7, pc}
_022330C4:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_022330CC: .word 0x0000E880
	thumb_func_end ov74_02233060


	thumb_func_start ov74_022330D0
ov74_022330D0: ; 0x022330D0
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r1, [r5, #4]
	cmp r1, #0
	beq _0223310C
	bl ov74_02232B18
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, _0223312C ; =ov74_0223C9B8
	lsl r1, r4, #2
	ldr r0, [r0, r1]
	mov r1, #0x46
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	sub r1, #0x34
	mov r2, #1
	add r0, #0x10
	str r2, [r5, r0]
	add r0, r5, #0
	add r1, r5, r1
	mov r2, #0x18
	bl ov74_02231A1C
	mov r0, #0
	str r0, [r5, #4]
	b _02233126
_0223310C:
	ldr r0, _02233130 ; =0x00000474
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _02233126
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	mov r0, #1
	pop {r3, r4, r5, pc}
_02233126:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0223312C: .word ov74_0223C9B8
_02233130: .word 0x00000474
	thumb_func_end ov74_022330D0


	thumb_func_start ov74_02233134
ov74_02233134: ; 0x02233134
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r1, [r5, #4]
	cmp r1, #0
	beq _02233170
	bl ov74_02232B18
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, _02233194 ; =ov74_0223C9B8
	lsl r1, r4, #2
	ldr r0, [r0, r1]
	mov r1, #0x46
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	sub r1, #0x34
	mov r2, #1
	add r0, #0x10
	str r2, [r5, r0]
	add r0, r5, #0
	add r1, r5, r1
	mov r2, #0x18
	bl ov74_02231A1C
	mov r0, #0
	str r0, [r5, #4]
	b _02233190
_02233170:
	ldr r0, _02233198 ; =0x00000474
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _02233190
	add r0, r5, #0
	bl ov74_02232F5C
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	mov r0, #1
	pop {r3, r4, r5, pc}
_02233190:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02233194: .word ov74_0223C9B8
_02233198: .word 0x00000474
	thumb_func_end ov74_02233134


	thumb_func_start ov74_0223319C
ov74_0223319C: ; 0x0223319C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	mov r1, #0
	ldr r2, [r5, #8]
	mvn r1, r1
	cmp r2, r1
	beq _022331DE
	bl ov74_02232B18
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	mov r1, #0x46
	ldr r0, [r5, #8]
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	add r0, #0x10
	sub r1, #0x34
	str r4, [r5, r0]
	add r0, r5, #0
	add r1, r5, r1
	mov r2, #0x18
	bl ov74_02231A1C
	mov r0, #0
	mvn r0, r0
	str r0, [r5, #8]
	ldr r0, _02233220 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	b _0223321C
_022331DE:
	cmp r4, #0
	beq _022331FC
	ldr r0, _02233224 ; =0x00000474
	ldr r0, [r5, r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0223321C
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	mov r0, #1
	pop {r3, r4, r5, pc}
_022331FC:
	ldr r0, _02233228 ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	bne _0223320C
	ldr r0, _0223322C ; =gSystem
	ldr r0, [r0, #0x48]
	cmp r0, #0
	beq _0223321C
_0223320C:
	mov r0, #0
	bl TextFlags_SetCanTouchSpeedUpPrint
	ldr r0, _02233220 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #1
	pop {r3, r4, r5, pc}
_0223321C:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02233220: .word SEQ_SE_DP_SELECT
_02233224: .word 0x00000474
_02233228: .word gSystem + 0x40
_0223322C: .word gSystem
	thumb_func_end ov74_0223319C


	thumb_func_start ov74_02233230
ov74_02233230: ; 0x02233230
	push {r3, r4, r5, lr}
	mov r2, #0xe
	add r5, r0, #0
	mov r0, #3
	mov r1, #0x4c
	lsl r2, r2, #0xe
	bl Heap_Create
	ldr r1, _022332D8 ; =0x00012610
	add r0, r5, #0
	mov r2, #0x4c
	bl OverlayManager_CreateAndGetData
	ldr r2, _022332D8 ; =0x00012610
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x4c
	bl BgConfig_Alloc
	str r0, [r4, #0x20]
	mov r0, #0x4c
	bl YesNoPrompt_Create
	ldr r1, _022332DC ; =0x0000E88C
	str r0, [r4, r1]
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FBF4
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	add r0, r5, #0
	bl OverlayManager_GetArgs
	ldr r0, [r0, #8]
	str r0, [r4, #0x10]
	bl Save_PlayerData_GetProfile
	str r0, [r4, #0x14]
	ldr r0, [r4, #0x10]
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #0x18]
	bl Options_GetFrame
	str r0, [r4, #0x1c]
	mov r0, #6
	lsl r0, r0, #6
	mov r1, #0x4c
	bl String_New
	ldr r1, _022332E0 ; =0x00012608
	str r0, [r4, r1]
	mov r0, #6
	lsl r0, r0, #6
	mov r1, #0x4c
	bl String_New
	ldr r1, _022332E4 ; =0x0001260C
	mov r2, #1
	str r0, [r4, r1]
	ldr r1, _022332E8 ; =0x0000047E
	mov r0, #9
	bl Sound_SetSceneAndPlayBGM
	bl OS_IsTickAvailable
	cmp r0, #0
	bne _022332C6
	bl OS_InitTick
_022332C6:
	bl ov74_02236074
	ldr r0, _022332EC ; =0x0000E89C
	add r1, r4, r0
	ldr r0, _022332F0 ; =ov74_0223D338
	str r1, [r0]
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_022332D8: .word 0x00012610
_022332DC: .word 0x0000E88C
_022332E0: .word 0x00012608
_022332E4: .word 0x0001260C
_022332E8: .word 0x0000047E
_022332EC: .word 0x0000E89C
_022332F0: .word ov74_0223D338
	thumb_func_end ov74_02233230


	thumb_func_start ov74_022332F4
ov74_022332F4: ; 0x022332F4
	push {r4, r5, r6, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	bl CTRDG_IsExisting
	bl CTRDG_IsPulledOut
	cmp r0, #1
	beq _02233312
	ldr r0, _02233618 ; =_02111864
	ldr r0, [r0]
	cmp r0, #0
	beq _02233328
_02233312:
	ldr r0, _0223361C ; =0x0000E890
	ldr r0, [r4, r0]
	sub r0, r0, #3
	cmp r0, #1
	bhi _02233322
	ldr r0, [r4, #0x10]
	bl Save_Cancel
_02233322:
	mov r0, #0x4c
	bl ShowGBACartRemovedError
_02233328:
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	ldr r0, [r5]
	cmp r0, #0x18
	bhi _02233424
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02233340: ; jump table
	.short _02233372 - _02233340 - 2 ; case 0
	.short _022333BA - _02233340 - 2 ; case 1
	.short _02233400 - _02233340 - 2 ; case 2
	.short _02233414 - _02233340 - 2 ; case 3
	.short _0223344E - _02233340 - 2 ; case 4
	.short _02233466 - _02233340 - 2 ; case 5
	.short _022334BC - _02233340 - 2 ; case 6
	.short _022334CE - _02233340 - 2 ; case 7
	.short _022334EC - _02233340 - 2 ; case 8
	.short _022334FE - _02233340 - 2 ; case 9
	.short _0223355C - _02233340 - 2 ; case 10
	.short _02233574 - _02233340 - 2 ; case 11
	.short _02233588 - _02233340 - 2 ; case 12
	.short _022335C8 - _02233340 - 2 ; case 13
	.short _022336F6 - _02233340 - 2 ; case 14
	.short _02233710 - _02233340 - 2 ; case 15
	.short _0223372C - _02233340 - 2 ; case 16
	.short _02233746 - _02233340 - 2 ; case 17
	.short _0223377C - _02233340 - 2 ; case 18
	.short _022337A2 - _02233340 - 2 ; case 19
	.short _0223380C - _02233340 - 2 ; case 20
	.short _02233818 - _02233340 - 2 ; case 21
	.short _0223385A - _02233340 - 2 ; case 22
	.short _0223387E - _02233340 - 2 ; case 23
	.short _0223388C - _02233340 - 2 ; case 24
_02233372:
	bl PmAgbCartridgeUnlinkSpec
	mov r0, #0x4b
	lsl r0, r0, #4
	add r0, r4, r0
	bl PmAgbCartridgeGetOffsets
	ldr r1, _02233620 ; =0x000004A8
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	cmp r0, #0
	bne _022333AE
	bl ov74_02233CE4
	ldr r1, _02233624 ; =0x000004AC
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	cmp r0, #0
	bne _022333AA
	bl ov74_02233F4C
	ldr r1, _02233628 ; =0x0000E880
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	ldrb r2, [r0]
	add r0, r1, #4
	str r2, [r4, r0]
	b _022333AE
_022333AA:
	mov r0, #1
	str r0, [r4, #4]
_022333AE:
	add r0, r4, #0
	bl ov74_02231790
	mov r0, #1
	str r0, [r5]
	b _02233896
_022333BA:
	add r0, r4, #0
	bl ov74_02232A48
	bl ov74_02231BC0
	add r0, r4, #0
	bl ov74_02231BF0
	add r0, r4, #0
	bl ov74_02231CFC
	add r0, r4, #0
	bl ov74_022322D8
	ldr r0, _0223362C ; =ov74_02233024
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4, #4]
	cmp r0, #1
	bne _022333FA
	add r0, r4, #0
	mov r1, #1
	mov r2, #0xb
	add r3, r5, #0
	bl ov74_02232910
	b _02233896
_022333FA:
	mov r0, #2
	str r0, [r5]
	b _02233896
_02233400:
	add r0, r4, #0
	bl ov74_02232F9C
	add r0, r4, #0
	mov r1, #1
	mov r2, #3
	add r3, r5, #0
	bl ov74_02232910
	b _02233896
_02233414:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _02233426
	cmp r0, #2
	beq _02233438
_02233424:
	b _02233896
_02233426:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
#ifdef HEARTGOLD
	mov r0, #0x22
#else
	mov r0, #0x23
#endif
	str r0, [r4, #8]
	mov r0, #4
	str r0, [r5]
	b _02233896
_02233438:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x18
	add r3, r5, #0
	bl ov74_02232940
	b _02233896
_0223344E:
	add r0, r4, #0
	mov r1, #1
	bl ov74_0223319C
	cmp r0, #0
	beq _02233476
	add r0, r4, #0
	bl ov74_02232F5C
	mov r0, #5
	str r0, [r5]
	b _02233896
_02233466:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _02233478
	cmp r0, #2
	beq _022334A6
_02233476:
	b _02233896
_02233478:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	add r0, r4, #0
	bl ov74_02233060
	str r0, [r4, #4]
	cmp r0, #0
	beq _0223349E
	sub r0, r0, #3
	cmp r0, #1
	bhi _02233498
	mov r0, #8
	str r0, [r5]
	b _02233896
_02233498:
	mov r0, #0xb
	str r0, [r5]
	b _02233896
_0223349E:
	mov r0, #6
	str r0, [r4, #8]
	str r0, [r5]
	b _02233896
_022334A6:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x18
	add r3, r5, #0
	bl ov74_02232940
	b _02233896
_022334BC:
	add r0, r4, #0
	mov r1, #1
	bl ov74_0223319C
	cmp r0, #0
	beq _0223350E
	mov r0, #7
	str r0, [r5]
	b _02233896
_022334CE:
	ldr r0, _02233634 ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	bne _022334DE
	ldr r0, _02233638 ; =gSystem
	ldr r0, [r0, #0x48]
	cmp r0, #0
	beq _0223350E
_022334DE:
	add r0, r4, #0
	mov r1, #0
	mov r2, #0xc
	add r3, r5, #0
	bl ov74_02232910
	b _02233896
_022334EC:
	ldr r1, [r4, #4]
	add r0, r4, #0
	bl ov74_02233134
	cmp r0, #0
	beq _0223350E
	mov r0, #9
	str r0, [r5]
	b _02233896
_022334FE:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _02233510
	cmp r0, #2
	beq _02233546
_0223350E:
	b _02233896
_02233510:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	mov r1, #0x47
	lsl r1, r1, #4
	mov r2, #0
	add r0, r1, #0
	str r2, [r4, r1]
	sub r1, #0x44
	mov r3, #0x28
	sub r0, #0x10
	str r3, [r4, r0]
	add r0, r4, #0
	add r1, r4, r1
	bl ov74_02231A1C
	ldr r1, _0223363C ; =0x00000498
	add r0, r4, r1
	sub r1, #0xc6
	bl WaitingIcon_New
	ldr r1, _02233640 ; =0x0000E898
	str r0, [r4, r1]
	mov r0, #0xa
	str r0, [r5]
	b _02233896
_02233546:
	ldr r0, _02233630 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x18
	add r3, r5, #0
	bl ov74_02232940
	b _02233896
_0223355C:
	add r0, r4, #0
	bl ov74_02231930
	ldr r0, _02233640 ; =0x0000E898
	ldr r0, [r4, r0]
	bl sub_0200F450
	mov r0, #7
	str r0, [r4, #4]
	mov r0, #0xb
	str r0, [r5]
	b _02233896
_02233574:
	ldr r1, [r4, #4]
	add r0, r4, #0
	bl ov74_022330D0
	cmp r0, #0
	bne _02233582
	b _02233896
_02233582:
	mov r0, #0x16
	str r0, [r5]
	b _02233896
_02233588:
	ldr r0, _0223363C ; =0x00000498
	add r0, r4, r0
	bl ov74_02232DA4
	add r0, r4, #0
	bl ov74_02232AC8
	add r0, r4, #0
	bl ov74_02232154
	add r0, r4, #0
	bl ov74_02231FF4
	ldr r0, _0223362C ; =ov74_02233024
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	mov r1, #0
	bl ov74_02232758
	add r0, r4, #0
	mov r1, #1
	mov r2, #0xd
	add r3, r5, #0
	bl ov74_02232910
	b _02233896
_022335C8:
	mov r0, #0x31
	lsl r0, r0, #4
	add r0, r4, r0
	bl TouchscreenHitbox_FindRectAtTouchNew
	add r6, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _022336A2
	cmp r6, #0x1e
	bge _02233698
	add r0, r4, #0
	add r1, r6, #0
	bl ov74_022324A0
	cmp r0, #1
	bne _02233652
	ldr r2, _02233628 ; =0x0000E880
	add r0, r4, #0
	ldr r1, [r4, r2]
	add r2, r2, #4
	ldr r3, [r4, r2]
	mov r2, #0x96
	lsl r2, r2, #4
	add r1, r1, #4
	mul r2, r3
	add r2, r1, r2
	mov r1, #0x50
	mul r1, r6
	add r1, r2, r1
	bl ov74_02232758
	mov r0, #0x41
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	cmp r0, #6
	bne _022336A2
	ldr r0, _02233644 ; =0x0000E888
	b _02233648
	.balign 4, 0
_02233618: .word _02111864
_0223361C: .word 0x0000E890
_02233620: .word 0x000004A8
_02233624: .word 0x000004AC
_02233628: .word 0x0000E880
_0223362C: .word ov74_02233024
_02233630: .word 0x0000E88C
_02233634: .word gSystem + 0x40
_02233638: .word gSystem
_0223363C: .word 0x00000498
_02233640: .word 0x0000E898
_02233644: .word 0x0000E888
_02233648:
	mov r1, #0x2d
	str r1, [r4, r0]
	mov r0, #0xf
	str r0, [r5]
	b _02233896
_02233652:
	cmp r0, #2
	bne _02233660
	add r0, r4, #0
	mov r1, #0
	bl ov74_02232758
	b _02233896
_02233660:
	cmp r0, #4
	bne _0223366E
	mov r0, #8
	str r0, [r4, #8]
	mov r0, #0xe
	str r0, [r5]
	b _02233896
_0223366E:
	cmp r0, #5
	bne _0223367C
	mov r0, #9
	str r0, [r4, #8]
	mov r0, #0xe
	str r0, [r5]
	b _02233896
_0223367C:
	cmp r0, #6
	bne _0223368A
	mov r0, #0x26
	str r0, [r4, #8]
	mov r0, #0xe
	str r0, [r5]
	b _02233896
_0223368A:
	cmp r0, #7
	bne _022336A2
	mov r0, #0x26
	str r0, [r4, #8]
	mov r0, #0xe
	str r0, [r5]
	b _02233896
_02233698:
	beq _022336E2
	cmp r6, #0x1f
	beq _022336A4
	cmp r6, #0x20
	beq _022336C2
_022336A2:
	b _02233896
_022336A4:
	ldr r0, _022338A4 ; =0x0000E884
	ldr r1, [r4, r0]
	cmp r1, #0
	bne _022336B0
	mov r1, #0xd
	b _022336B2
_022336B0:
	sub r1, r1, #1
_022336B2:
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov74_02231FF4
	ldr r0, _022338A8 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	b _02233896
_022336C2:
	ldr r0, _022338A4 ; =0x0000E884
	ldr r1, [r4, r0]
	add r1, r1, #1
	str r1, [r4, r0]
	ldr r1, [r4, r0]
	cmp r1, #0xe
	bne _022336D4
	mov r1, #0
	str r1, [r4, r0]
_022336D4:
	add r0, r4, #0
	bl ov74_02231FF4
	ldr r0, _022338A8 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	b _02233896
_022336E2:
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x18
	add r3, r5, #0
	bl ov74_02232940
	ldr r0, _022338A8 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	b _02233896
_022336F6:
	add r0, r4, #0
	mov r1, #0
	bl ov74_0223319C
	cmp r0, #0
	beq _02233756
	ldr r0, _022338AC ; =0x00000498
	add r0, r4, r0
	bl ov74_02232DA4
	mov r0, #0xd
	str r0, [r5]
	b _02233896
_02233710:
	ldr r0, _022338B0 ; =0x0000E888
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _02233756
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x10
	add r3, r5, #0
	bl ov74_02232910
	b _02233896
_0223372C:
	add r0, r4, #0
	bl ov74_02232BD4
	add r0, r4, #0
	mov r1, #1
	mov r2, #0x11
	add r3, r5, #0
	bl ov74_02232910
	add r0, r4, #0
	bl ov74_02232F5C
	b _02233896
_02233746:
	ldr r0, _022338B4 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _02233758
	cmp r0, #2
	beq _02233766
_02233756:
	b _02233896
_02233758:
	ldr r0, _022338B4 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	mov r0, #0x12
	str r0, [r5]
	b _02233896
_02233766:
	ldr r0, _022338B4 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x14
	add r3, r5, #0
	bl ov74_02232910
	b _02233896
_0223377C:
	mov r1, #0x46
	mov r0, #0xb
	lsl r1, r1, #4
	str r0, [r4, r1]
	sub r1, #0x34
	add r0, r4, #0
	add r1, r4, r1
	mov r2, #0
	bl ov74_02231A1C
	add r0, r4, #0
	bl ov74_02232F5C
	ldr r0, _022338A8 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	mov r0, #0x13
	str r0, [r5]
	b _02233896
_022337A2:
	ldr r0, _022338B4 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	beq _022337B4
	cmp r0, #2
	beq _022337F6
	b _02233896
_022337B4:
	ldr r0, [r4]
	mov r2, #0
	lsl r1, r0, #2
	ldr r0, _022338B8 ; =ov74_0223C968
	ldr r0, [r0, r1]
	mov r1, #0x46
	lsl r1, r1, #4
	str r0, [r4, r1]
	sub r1, #0x34
	add r0, r4, #0
	add r1, r4, r1
	bl ov74_02231A1C
	ldr r0, _022338B4 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	ldr r0, _022338BC ; =0x0000E890
	mov r1, #0
	str r1, [r4, r0]
	ldr r1, _022338AC ; =0x00000498
	add r0, r4, r1
	sub r1, #0xc6
	bl WaitingIcon_New
	ldr r1, _022338C0 ; =0x0000E898
	str r0, [r4, r1]
	mov r0, #0x15
	str r0, [r5]
	mov r0, #4
	bl sub_0201A728
	b _02233896
_022337F6:
	ldr r0, _022338B4 ; =0x0000E88C
	ldr r0, [r4, r0]
	bl YesNoPrompt_Reset
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x14
	add r3, r5, #0
	bl ov74_02232910
	b _02233896
_0223380C:
	add r0, r4, #0
	bl ov74_02232DC4
	mov r0, #0xc
	str r0, [r5]
	b _02233896
_02233818:
	add r0, r4, #0
	bl ov74_022317D8
	add r6, r0, #0
	cmp r6, #0xa
	beq _02233896
	ldr r0, _022338C0 ; =0x0000E898
	ldr r0, [r4, r0]
	bl sub_0200F450
	ldr r0, _022338C4 ; =SEQ_SE_DP_SAVE
	bl PlaySE
	cmp r6, #0xb
	bne _0223383A
#ifdef HEARTGOLD
	mov r1, #0x1d
#else
	mov r1, #0x1e
#endif
	b _0223383C
_0223383A:
	mov r1, #0x24
_0223383C:
	mov r0, #0x46
	lsl r0, r0, #4
	str r1, [r4, r0]
	ldr r1, _022338C8 ; =0x0000042C
	add r0, r4, #0
	add r1, r4, r1
	mov r2, #0
	bl ov74_02231A1C
	mov r0, #0x16
	str r0, [r5]
	mov r0, #4
	bl sub_0201A738
	b _02233896
_0223385A:
	ldr r0, _022338CC ; =gSystem + 0x40
	ldrh r0, [r0, #0x24]
	cmp r0, #0
	bne _0223386A
	ldr r0, _022338D0 ; =gSystem
	ldr r0, [r0, #0x48]
	cmp r0, #0
	beq _02233896
_0223386A:
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x18
	add r3, r5, #0
	bl ov74_02232940
	ldr r0, _022338A8 ; =SEQ_SE_DP_SELECT
	bl PlaySE
	b _02233896
_0223387E:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02233896
	ldr r0, [r4, #0x24]
	str r0, [r5]
	b _02233896
_0223388C:
	add r0, r4, #0
	bl ov74_02232E3C
	mov r0, #1
	pop {r4, r5, r6, pc}
_02233896:
	ldr r0, [r4, #0x28]
	cmp r0, #0
	beq _022338A0
	bl SpriteList_RenderAndAnimateSprites
_022338A0:
	mov r0, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_022338A4: .word 0x0000E884
_022338A8: .word SEQ_SE_DP_SELECT
_022338AC: .word 0x00000498
_022338B0: .word 0x0000E888
_022338B4: .word 0x0000E88C
_022338B8: .word ov74_0223C968
_022338BC: .word 0x0000E890
_022338C0: .word 0x0000E898
_022338C4: .word SEQ_SE_DP_SAVE
_022338C8: .word 0x0000042C
_022338CC: .word gSystem + 0x40
_022338D0: .word gSystem
	thumb_func_end ov74_022332F4


	thumb_func_start ov74_022338D4
ov74_022338D4: ; 0x022338D4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, _02233914 ; =0x00012608
	ldr r0, [r4, r0]
	bl String_Delete
	ldr r0, _02233918 ; =0x0001260C
	ldr r0, [r4, r0]
	bl String_Delete
	ldr r0, [r4, #0x20]
	bl Heap_Free
	ldr r0, _0223391C ; =FS_OVERLAY_ID(intro_title)
	ldr r1, _02233920 ; =gApplication_TitleScreen
	bl RegisterMainOverlay
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0x4c
	bl Heap_Destroy
	mov r0, #0
	bl ov74_02236034
	mov r0, #1
	pop {r3, r4, r5, pc}
	nop
_02233914: .word 0x00012608
_02233918: .word 0x0001260C
_0223391C: .word FS_OVERLAY_ID(intro_title)
_02233920: .word gApplication_TitleScreen
	thumb_func_end ov74_022338D4


	thumb_func_start PmAgbCartridgeHasFlash
PmAgbCartridgeHasFlash: ; 0x02233924
	push {r3, lr}
	mov r0, #1
	bl CTRDG_IdentifyAgbBackup
	cmp r0, #0
	bne _02233934
	mov r0, #1
	pop {r3, pc}
_02233934:
	mov r0, #0
	pop {r3, pc}
	thumb_func_end PmAgbCartridgeHasFlash


	thumb_func_start PmAgbCartridgeGetOffsets
PmAgbCartridgeGetOffsets: ; 0x02233938
	push {r3, lr}
	ldr r1, _02233994 ; =ov74_0223D33C
	str r0, [r1, #8]
	ldr r0, _02233998 ; =sPmAgbCartridgeSpec
	ldr r0, [r0]
	cmp r0, #0
	beq _0223394A
	mov r0, #0xc
	pop {r3, pc}
_0223394A:
	ldr r0, _0223399C ; =sPmAgbRomCodeMappings
	mov r1, #0x1e
	bl IdentifyPmAgbCartridge
	cmp r0, #0
	bne _02233992
	ldr r0, _02233998 ; =sPmAgbCartridgeSpec
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0223397A
	mov r0, #0x89
	ldr r1, _022339A0 ; =sPmAgbRomHeader + 0x68
	lsl r0, r0, #4
	str r0, [r1, #0x20]
	mov r0, #0xeb
	lsl r0, r0, #6
	str r0, [r1, #0x24]
	ldr r2, _022339A4 ; =0x00001220
	ldr r0, _02233994 ; =ov74_0223D33C
	str r2, [r0, #0x68]
	mov r0, #9
	str r0, [r1, #0x30]
	b _02233984
_0223397A:
	ldr r0, _022339A8 ; =0x08000100
	ldr r1, _022339AC ; =sPmAgbRomHeader
	mov r2, #0xfc
	bl CTRDG_CpuCopy32
_02233984:
	bl PmAgbCartridgeHasFlash
	cmp r0, #0
	bne _02233990
	mov r0, #3
	pop {r3, pc}
_02233990:
	mov r0, #0
_02233992:
	pop {r3, pc}
	.balign 4, 0
_02233994: .word ov74_0223D33C
_02233998: .word sPmAgbCartridgeSpec
_0223399C: .word sPmAgbRomCodeMappings
_022339A0: .word sPmAgbRomHeader + 0x68
_022339A4: .word 0x00001220
_022339A8: .word 0x08000100
_022339AC: .word sPmAgbRomHeader
	thumb_func_end PmAgbCartridgeGetOffsets


	thumb_func_start PmAgbCartridgeUnlinkSpec
PmAgbCartridgeUnlinkSpec: ; 0x022339B0
	ldr r0, _022339B8 ; =sPmAgbCartridgeSpec
	mov r1, #0
	str r1, [r0]
	bx lr
	.balign 4, 0
_022339B8: .word sPmAgbCartridgeSpec
	thumb_func_end PmAgbCartridgeUnlinkSpec


	thumb_func_start PmAgbCartridge_GetVersionInternal
PmAgbCartridge_GetVersionInternal: ; 0x022339BC
	ldr r0, _022339C4 ; =sPmAgbCartridgeSpec
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	bx lr
	.balign 4, 0
_022339C4: .word sPmAgbCartridgeSpec
	thumb_func_end PmAgbCartridge_GetVersionInternal


	thumb_func_start PmAgbCartridge_GetLanguage
PmAgbCartridge_GetLanguage: ; 0x022339C8
	ldr r0, _022339D0 ; =sPmAgbCartridgeSpec
	ldr r0, [r0]
	ldrh r0, [r0, #6]
	bx lr
	.balign 4, 0
_022339D0: .word sPmAgbCartridgeSpec
	thumb_func_end PmAgbCartridge_GetLanguage


	thumb_func_start IdentifyPmAgbCartridge
IdentifyPmAgbCartridge: ; 0x022339D4
	push {r3, r4, r5, lr}
	sub sp, #0xc0
	add r5, r0, #0
	add r4, r1, #0
	ldr r0, _02233A80 ; =sPmAgbCartridgeSpec
	mov r1, #0
	str r1, [r0]
	bl CTRDG_IsAgbCartridge
	cmp r0, #0
	bne _022339F0
	add sp, #0xc0
	mov r0, #1
	pop {r3, r4, r5, pc}
_022339F0:
	bl CTRDG_GetAgbGameCode
	mov r2, #0
	cmp r4, #0
	ble _02233A14
	add r3, r5, #0
_022339FC:
	ldr r1, [r3]
	cmp r0, r1
	bne _02233A0C
	lsl r0, r2, #3
	add r1, r5, r0
	ldr r0, _02233A80 ; =sPmAgbCartridgeSpec
	str r1, [r0]
	b _02233A14
_02233A0C:
	add r2, r2, #1
	add r3, #8
	cmp r2, r4
	blt _022339FC
_02233A14:
	ldr r0, _02233A80 ; =sPmAgbCartridgeSpec
	ldr r0, [r0]
	cmp r0, #0
	bne _02233A22
	add sp, #0xc0
	mov r0, #2
	pop {r3, r4, r5, pc}
_02233A22:
	mov r0, #1
	bl CTRDG_Enable
	add r4, sp, #0
	mov r0, #2
	lsl r0, r0, #0x1a
	add r1, r4, #0
	mov r2, #0xc0
	bl CTRDG_CpuCopy32
	ldr r3, _02233A84 ; =sAgbCartNintendoLogo
	mov r2, #0
_02233A3A:
	add r0, r4, r2
	ldrb r1, [r3]
	ldrb r0, [r0, #4]
	cmp r1, r0
	beq _02233A4A
	add sp, #0xc0
	mov r0, #4
	pop {r3, r4, r5, pc}
_02233A4A:
	add r2, r2, #1
	add r3, r3, #1
	cmp r2, #0x9c
	blo _02233A3A
	mov r2, #0
	mov r1, #0xa0
_02233A56:
	ldrb r0, [r4, r1]
	add r1, r1, #1
	add r0, r2, r0
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r1, #0xbc
	ble _02233A56
	add r2, #0x19
	neg r0, r2
	lsl r0, r0, #0x18
	add r4, #0xbd
	lsr r1, r0, #0x18
	ldrb r0, [r4]
	cmp r0, r1
	beq _02233A7A
	add sp, #0xc0
	mov r0, #4
	pop {r3, r4, r5, pc}
_02233A7A:
	mov r0, #0
	add sp, #0xc0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02233A80: .word sPmAgbCartridgeSpec
_02233A84: .word sAgbCartNintendoLogo
	thumb_func_end IdentifyPmAgbCartridge


	thumb_func_start ov74_02233A88
ov74_02233A88: ; 0x02233A88
	push {r3, r4}
	mov r2, #0
	lsr r4, r1, #2
	add r3, r2, #0
	cmp r4, #0
	ble _02233AA4
_02233A94:
	ldr r1, [r0]
	add r0, r0, #4
	add r2, r2, r1
	add r1, r3, #1
	lsl r1, r1, #0x10
	lsr r3, r1, #0x10
	cmp r3, r4
	blt _02233A94
_02233AA4:
	lsr r0, r2, #0x10
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	lsl r0, r2, #0x10
	lsr r0, r0, #0x10
	add r0, r1, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	pop {r3, r4}
	bx lr
	thumb_func_end ov74_02233A88


	thumb_func_start ov74_02233AB8
ov74_02233AB8: ; 0x02233AB8
	push {r3, lr}
	lsl r0, r0, #0x10
	mov r3, #1
	add r2, r1, #0
	lsr r0, r0, #0x10
	mov r1, #0
	lsl r3, r3, #0xc
	bl CTRDG_ReadAgbFlash
	pop {r3, pc}
	thumb_func_end ov74_02233AB8


	thumb_func_start ov74_02233ACC
ov74_02233ACC: ; 0x02233ACC
	cmp r0, #0
	bne _02233ADA
	ldr r0, _02233B00 ; =sPmAgbRomHeader + 0x68
	ldr r0, [r0, #0x20]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bx lr
_02233ADA:
	cmp r0, #4
	bne _02233AEE
	ldr r0, _02233B00 ; =sPmAgbRomHeader + 0x68
	ldr r1, [r0, #0x24]
	mov r0, #0xba
	lsl r0, r0, #6
	sub r0, r1, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bx lr
_02233AEE:
	cmp r0, #0xd
	bne _02233AF8
	mov r0, #0x7d
	lsl r0, r0, #4
	bx lr
_02233AF8:
	mov r0, #0x3e
	lsl r0, r0, #6
	bx lr
	nop
_02233B00: .word sPmAgbRomHeader + 0x68
	thumb_func_end ov74_02233ACC


	thumb_func_start ov74_02233B04
ov74_02233B04: ; 0x02233B04
	cmp r0, #0
	bne _02233B14
	ldr r0, _02233B54 ; =ov74_0223D33C
	ldr r1, [r0, #8]
	mov r0, #1
	lsl r0, r0, #0xc
	add r0, r1, r0
	bx lr
_02233B14:
	cmp r0, #1
	blt _02233B32
	cmp r0, #4
	bgt _02233B32
	ldr r1, _02233B54 ; =ov74_0223D33C
	ldr r2, [r1, #8]
	mov r1, #2
	lsl r1, r1, #0xc
	add r2, r2, r1
	sub r1, r0, #1
	mov r0, #0x3e
	lsl r0, r0, #6
	mul r0, r1
	add r0, r2, r0
	bx lr
_02233B32:
	cmp r0, #5
	blt _02233B50
	cmp r0, #0xe
	bge _02233B50
	ldr r1, _02233B54 ; =ov74_0223D33C
	ldr r2, [r1, #8]
	mov r1, #6
	lsl r1, r1, #0xc
	add r2, r2, r1
	sub r1, r0, #5
	mov r0, #0x3e
	lsl r0, r0, #6
	mul r0, r1
	add r0, r2, r0
	bx lr
_02233B50:
	mov r0, #0
	bx lr
	.balign 4, 0
_02233B54: .word ov74_0223D33C
	thumb_func_end ov74_02233B04


	thumb_func_start ov74_02233B58
ov74_02233B58: ; 0x02233B58
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	mov r6, #0
	add r5, r1, #0
	str r6, [sp, #4]
	add r1, r2, #0
	str r6, [r1]
	ldr r1, _02233BEC ; =ov74_0223D33C
	add r7, r0, #0
	str r6, [r1, #4]
	mov r1, #0xe
	str r2, [sp]
	add r4, r6, #0
	mul r7, r1
_02233B74:
	add r0, r4, #0
	mov r1, #0xe
	bl _s32_div_f
	add r0, r1, r7
	add r1, r5, #0
	bl ov74_02233AB8
	mov r1, #1
	add r0, r5, #0
	lsl r1, r1, #0xc
	bl DC_FlushRange
	ldr r0, _02233BF0 ; =0x00000FF8
	ldr r1, [r5, r0]
	ldr r0, _02233BF4 ; =0x08012025
	cmp r1, r0
	bne _02233BC6
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, _02233BF8 ; =0x00000FF4
	ldrh r0, [r5, r0]
	bl ov74_02233ACC
	add r1, r0, #0
	add r0, r5, #0
	bl ov74_02233A88
	ldr r1, _02233BFC ; =0x00000FF6
	ldrh r1, [r5, r1]
	cmp r1, r0
	bne _02233BC6
	ldr r0, _02233C00 ; =0x00000FFC
	ldr r1, [r5, r0]
	ldr r0, [sp]
	str r1, [r0]
	ldr r0, _02233BF8 ; =0x00000FF4
	ldrh r1, [r5, r0]
	mov r0, #1
	lsl r0, r1
	orr r6, r0
_02233BC6:
	add r4, r4, #1
	cmp r4, #0xe
	blt _02233B74
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _02233BE4
	ldr r0, _02233C04 ; =0x00003FFF
	cmp r6, r0
	bne _02233BDE
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02233BDE:
	add sp, #8
	mov r0, #0xff
	pop {r3, r4, r5, r6, r7, pc}
_02233BE4:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02233BEC: .word ov74_0223D33C
_02233BF0: .word 0x00000FF8
_02233BF4: .word 0x08012025
_02233BF8: .word 0x00000FF4
_02233BFC: .word 0x00000FF6
_02233C00: .word 0x00000FFC
_02233C04: .word 0x00003FFF
	thumb_func_end ov74_02233B58


	thumb_func_start ov74_02233C08
ov74_02233C08: ; 0x02233C08
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r7, r0, #0
	add r5, r1, #0
	add r4, r2, #0
	mov r0, #0
	add r1, r7, #0
	add r2, sp, #4
	bl ov74_02233B58
	add r6, r0, #0
	mov r0, #1
	add r1, r7, #0
	add r2, sp, #0
	bl ov74_02233B58
	cmp r6, #1
	bne _02233C80
	cmp r0, #1
	bne _02233C80
	mov r1, #0
	ldr r0, [sp, #4]
	mvn r1, r1
	cmp r0, r1
	bne _02233C40
	ldr r3, [sp]
	cmp r3, #0
	beq _02233C4E
_02233C40:
	cmp r0, #0
	bne _02233C66
	mov r1, #0
	ldr r3, [sp]
	mvn r1, r1
	cmp r3, r1
	bne _02233C66
_02233C4E:
	add r2, r0, #1
	add r1, r3, #1
	cmp r2, r1
	bhs _02233C5E
	str r3, [r4]
	mov r0, #1
	str r0, [r5]
	b _02233C7A
_02233C5E:
	str r0, [r4]
	mov r0, #0
	str r0, [r5]
	b _02233C7A
_02233C66:
	ldr r1, [sp]
	cmp r0, r1
	bhs _02233C74
	str r1, [r4]
	mov r0, #1
	str r0, [r5]
	b _02233C7A
_02233C74:
	str r0, [r4]
	mov r0, #0
	str r0, [r5]
_02233C7A:
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02233C80:
	cmp r6, #1
	bne _02233CA4
	cmp r0, #1
	beq _02233CA4
	ldr r1, [sp, #4]
	cmp r0, #0xff
	str r1, [r4]
	bne _02233C9A
	mov r0, #0
	str r0, [r5]
	add sp, #8
	mov r0, #0xff
	pop {r3, r4, r5, r6, r7, pc}
_02233C9A:
	mov r0, #0
	str r0, [r5]
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02233CA4:
	cmp r0, #1
	bne _02233CC6
	cmp r6, #1
	beq _02233CC6
	ldr r0, [sp]
	cmp r6, #0xff
	str r0, [r4]
	bne _02233CBE
	mov r0, #1
	str r0, [r5]
	add sp, #8
	mov r0, #0xff
	pop {r3, r4, r5, r6, r7, pc}
_02233CBE:
	mov r0, #1
	add sp, #8
	str r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
_02233CC6:
	cmp r6, #0
	bne _02233CD8
	cmp r0, #0
	bne _02233CD8
	mov r0, #0
	str r0, [r4]
	add sp, #8
	str r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
_02233CD8:
	mov r0, #0
	str r0, [r4]
	str r0, [r5]
	mov r0, #2
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_02233C08


	thumb_func_start ov74_02233CE4
ov74_02233CE4: ; 0x02233CE4
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _02233D98 ; =ov74_0223D33C
	ldr r1, _02233D9C ; =ov74_0223D33C
	ldr r0, [r0, #8]
	ldr r2, _02233DA0 ; =ov74_0223D34C
	bl ov74_02233C08
	cmp r0, #1
	beq _02233D0E
	cmp r0, #0
	beq _02233D06
	cmp r0, #2
	beq _02233D0A
	cmp r0, #0xff
	bne _02233D0E
	mov r0, #5
	pop {r3, r4, r5, r6, r7, pc}
_02233D06:
	mov r0, #7
	pop {r3, r4, r5, r6, r7, pc}
_02233D0A:
	mov r0, #6
	pop {r3, r4, r5, r6, r7, pc}
_02233D0E:
	ldr r7, _02233D98 ; =ov74_0223D33C
	ldr r0, [r7]
	cmp r0, #1
	bhi _02233D92
	mov r6, #0
	ldr r5, [r7, #8]
	add r4, r6, #0
_02233D1C:
	ldr r1, [r7]
	mov r0, #0xe
	mul r0, r1
	add r0, r4, r0
	add r1, r5, #0
	bl ov74_02233AB8
	ldr r0, _02233DA4 ; =0x00000FF8
	ldr r1, [r5, r0]
	ldr r0, _02233DA8 ; =0x08012025
	cmp r1, r0
	bne _02233D7E
	ldr r0, _02233DAC ; =0x00000FF4
	ldrh r0, [r5, r0]
	bl ov74_02233ACC
	add r1, r0, #0
	add r0, r5, #0
	bl ov74_02233A88
	ldr r1, _02233DB0 ; =0x00000FF6
	ldrh r1, [r5, r1]
	cmp r1, r0
	bne _02233D7E
	ldr r0, _02233DB4 ; =0x00000FFC
	mov r1, #1
	ldr r0, [r5, r0]
	str r0, [r7, #0x10]
	ldr r0, _02233DAC ; =0x00000FF4
	ldrh r0, [r5, r0]
	lsl r1, r0
	orr r6, r1
	bl ov74_02233ACC
	str r0, [sp]
	ldr r0, _02233DAC ; =0x00000FF4
	ldrh r0, [r5, r0]
	bl ov74_02233B04
	add r1, r0, #0
	ldr r2, [sp]
	add r0, r5, #0
	bl MIi_CpuCopy32
	ldr r0, _02233DAC ; =0x00000FF4
	ldrh r0, [r5, r0]
	cmp r0, #0
	bne _02233D7E
	str r4, [r7, #0xc]
_02233D7E:
	add r4, r4, #1
	cmp r4, #0xe
	blt _02233D1C
	ldr r0, _02233DB8 ; =0x00003FFF
	cmp r6, r0
	bne _02233D8E
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02233D8E:
	mov r0, #4
	pop {r3, r4, r5, r6, r7, pc}
_02233D92:
	mov r0, #6
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02233D98: .word ov74_0223D33C
_02233D9C: .word ov74_0223D33C
_02233DA0: .word ov74_0223D34C
_02233DA4: .word 0x00000FF8
_02233DA8: .word 0x08012025
_02233DAC: .word 0x00000FF4
_02233DB0: .word 0x00000FF6
_02233DB4: .word 0x00000FFC
_02233DB8: .word 0x00003FFF
	thumb_func_end ov74_02233CE4


	thumb_func_start ov74_02233DBC
ov74_02233DBC: ; 0x02233DBC
	push {r4, r5, r6, lr}
	add r6, r0, #0
	ldr r0, _02233E38 ; =ov74_0223D33C
	mov r2, #1
	ldr r5, [r0, #8]
	str r2, [r0, #0x14]
	mov r0, #0
	add r1, r5, #0
	lsl r2, r2, #0xc
	bl MIi_CpuClear32
	add r0, r6, #0
	bl ov74_02233ACC
	add r4, r0, #0
	add r0, r6, #0
	bl ov74_02233B04
	add r1, r5, #0
	add r2, r4, #0
	bl MIi_CpuCopy32
	ldr r0, _02233E38 ; =ov74_0223D33C
	ldr r1, [r0, #0x10]
	ldr r0, _02233E3C ; =0x00000FFC
	str r1, [r5, r0]
	add r1, r0, #0
	sub r1, #8
	strh r6, [r5, r1]
	ldr r1, _02233E40 ; =0x08012025
	sub r0, r0, #4
	str r1, [r5, r0]
	add r0, r6, #0
	bl ov74_02233ACC
	add r1, r0, #0
	add r0, r5, #0
	bl ov74_02233A88
	ldr r1, _02233E44 ; =0x00000FF6
	strh r0, [r5, r1]
	ldr r0, _02233E38 ; =ov74_0223D33C
	mov r1, #0xe
	ldr r0, [r0, #0xc]
	add r0, r6, r0
	add r0, r0, #1
	bl _s32_div_f
	ldr r0, _02233E48 ; =sPmAgbCartridgeSpec
	ldr r3, _02233E4C ; =ov74_02233E50
	ldr r2, [r0, #4]
	mov r0, #0xe
	mul r0, r2
	add r0, r1, r0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	add r1, r5, #0
	mov r2, #4
	bl CTRDG_WriteAndVerifyAgbFlashAsync
	pop {r4, r5, r6, pc}
	nop
_02233E38: .word ov74_0223D33C
_02233E3C: .word 0x00000FFC
_02233E40: .word 0x08012025
_02233E44: .word 0x00000FF6
_02233E48: .word sPmAgbCartridgeSpec
_02233E4C: .word ov74_02233E50
	thumb_func_end ov74_02233DBC


	thumb_func_start ov74_02233E50
ov74_02233E50: ; 0x02233E50
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _02233E7C
	ldr r1, _02233E88 ; =ov74_0223D33C
	ldr r0, [r1, #4]
	add r0, r0, #1
	str r0, [r1, #4]
	cmp r0, #0xe
	blt _02233E6A
	mov r0, #0
	str r0, [r1, #4]
	str r0, [r1, #0x14]
	bx lr
_02233E6A:
	cmp r0, #0xd
	bne _02233E76
	mov r0, #2
	str r0, [r1, #0x14]
	mov r0, #0
	bx lr
_02233E76:
	mov r0, #3
	str r0, [r1, #0x14]
	b _02233E82
_02233E7C:
	ldr r0, _02233E88 ; =ov74_0223D33C
	mov r1, #4
	str r1, [r0, #0x14]
_02233E82:
	mov r0, #0
	bx lr
	nop
_02233E88: .word ov74_0223D33C
	thumb_func_end ov74_02233E50


	thumb_func_start ov74_02233E8C
ov74_02233E8C: ; 0x02233E8C
	push {r3, lr}
	ldr r1, _02233ECC ; =ov74_0223D33C
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _02233EB2
	ldr r1, [r1]
	cmp r1, #1
	bne _02233EA2
	mov r2, #0
	ldr r1, _02233ED0 ; =sPmAgbCartridgeSpec
	b _02233EA6
_02233EA2:
	ldr r1, _02233ED0 ; =sPmAgbCartridgeSpec
	mov r2, #1
_02233EA6:
	str r2, [r1, #4]
	ldr r1, _02233ECC ; =ov74_0223D33C
	ldr r2, [r1, #0x10]
	add r2, r2, #1
	str r2, [r1, #0x10]
	b _02233EB6
_02233EB2:
	mov r0, #0
	pop {r3, pc}
_02233EB6:
	ldr r1, _02233ED0 ; =sPmAgbCartridgeSpec
	ldr r1, [r1, #4]
	cmp r1, #0
	bge _02233EC2
	mov r0, #0
	pop {r3, pc}
_02233EC2:
	bl ov74_02233DBC
	mov r0, #1
	pop {r3, pc}
	nop
_02233ECC: .word ov74_0223D33C
_02233ED0: .word sPmAgbCartridgeSpec
	thumb_func_end ov74_02233E8C


	thumb_func_start ov74_02233ED4
ov74_02233ED4: ; 0x02233ED4
	push {r3, lr}
	ldr r1, _02233F10 ; =ov74_0223D33C
	ldr r0, [r1, #0x14]
	cmp r0, #4
	bhi _02233F0C
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02233EEA: ; jump table
	.short _02233F0C - _02233EEA - 2 ; case 0
	.short _02233F04 - _02233EEA - 2 ; case 1
	.short _02233EF4 - _02233EEA - 2 ; case 2
	.short _02233EFE - _02233EEA - 2 ; case 3
	.short _02233F08 - _02233EEA - 2 ; case 4
_02233EF4:
	ldr r0, [r1, #4]
	bl ov74_02233DBC
	mov r0, #0
	pop {r3, pc}
_02233EFE:
	ldr r0, [r1, #4]
	bl ov74_02233DBC
_02233F04:
	mov r0, #0xa
	pop {r3, pc}
_02233F08:
	mov r0, #8
	pop {r3, pc}
_02233F0C:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_02233F10: .word ov74_0223D33C
	thumb_func_end ov74_02233ED4


	thumb_func_start ov74_02233F14
ov74_02233F14: ; 0x02233F14
	ldr r0, _02233F48 ; =ov74_0223D33C
	ldr r0, [r0, #0x14]
	cmp r0, #4
	bhi _02233F42
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02233F28: ; jump table
	.short _02233F42 - _02233F28 - 2 ; case 0
	.short _02233F3A - _02233F28 - 2 ; case 1
	.short _02233F32 - _02233F28 - 2 ; case 2
	.short _02233F36 - _02233F28 - 2 ; case 3
	.short _02233F3E - _02233F28 - 2 ; case 4
_02233F32:
	mov r0, #0xb
	bx lr
_02233F36:
	mov r0, #0xa
	bx lr
_02233F3A:
	mov r0, #9
	bx lr
_02233F3E:
	mov r0, #8
	bx lr
_02233F42:
	mov r0, #0
	bx lr
	nop
_02233F48: .word ov74_0223D33C
	thumb_func_end ov74_02233F14


	thumb_func_start ov74_02233F4C
ov74_02233F4C: ; 0x02233F4C
	ldr r0, _02233F58 ; =ov74_0223D33C
	ldr r1, [r0, #8]
	mov r0, #6
	lsl r0, r0, #0xc
	add r0, r1, r0
	bx lr
	.balign 4, 0
_02233F58: .word ov74_0223D33C
	thumb_func_end ov74_02233F4C


	thumb_func_start ov74_02233F5C
ov74_02233F5C: ; 0x02233F5C
	ldr r3, _02233F64 ; =ov74_02233B04
	mov r0, #0
	bx r3
	nop
_02233F64: .word ov74_02233B04
	thumb_func_end ov74_02233F5C


	thumb_func_start ov74_02233F68
ov74_02233F68: ; 0x02233F68
	push {r3, lr}
	bl ov74_02233F5C
	ldrb r2, [r0, #0xb]
	ldrb r1, [r0, #0xa]
	lsl r3, r2, #8
	ldrb r2, [r0, #0xd]
	ldrb r0, [r0, #0xc]
	lsl r2, r2, #0x18
	lsl r0, r0, #0x10
	orr r0, r2
	orr r0, r3
	orr r0, r1
	pop {r3, pc}
	thumb_func_end ov74_02233F68


	thumb_func_start ov74_02233F84
ov74_02233F84: ; 0x02233F84
	ldr r3, _02233F88 ; =ov74_02233F5C
	bx r3
	.balign 4, 0
_02233F88: .word ov74_02233F5C
	thumb_func_end ov74_02233F84


	thumb_func_start ov74_02233F8C
ov74_02233F8C: ; 0x02233F8C
	push {r4, r5, r6, lr}
	add r4, r0, #0
	add r0, r1, #0
	mov r1, #0x18
	add r5, r2, #0
	mov r6, #0
	bl _u32_div_f
	cmp r1, #0x17
	bhi _02233FE2
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02233FAC: ; jump table
	.short _02233FDC - _02233FAC - 2 ; case 0
	.short _0223400E - _02233FAC - 2 ; case 1
	.short _0223403E - _02233FAC - 2 ; case 2
	.short _0223406E - _02233FAC - 2 ; case 3
	.short _0223409E - _02233FAC - 2 ; case 4
	.short _022340CE - _02233FAC - 2 ; case 5
	.short _022340FE - _02233FAC - 2 ; case 6
	.short _02234130 - _02233FAC - 2 ; case 7
	.short _02234160 - _02233FAC - 2 ; case 8
	.short _02234190 - _02233FAC - 2 ; case 9
	.short _022341C0 - _02233FAC - 2 ; case 10
	.short _022341F0 - _02233FAC - 2 ; case 11
	.short _02234220 - _02233FAC - 2 ; case 12
	.short _02234252 - _02233FAC - 2 ; case 13
	.short _02234282 - _02233FAC - 2 ; case 14
	.short _022342B2 - _02233FAC - 2 ; case 15
	.short _022342E2 - _02233FAC - 2 ; case 16
	.short _02234312 - _02233FAC - 2 ; case 17
	.short _02234342 - _02233FAC - 2 ; case 18
	.short _02234374 - _02233FAC - 2 ; case 19
	.short _022343A4 - _02233FAC - 2 ; case 20
	.short _022343D4 - _02233FAC - 2 ; case 21
	.short _02234404 - _02233FAC - 2 ; case 22
	.short _02234434 - _02233FAC - 2 ; case 23
_02233FDC:
	add r4, #0x20
	cmp r5, #3
	bls _02233FE4
_02233FE2:
	b _02234462
_02233FE4:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02233FF0: ; jump table
	.short _02233FF8 - _02233FF0 - 2 ; case 0
	.short _02233FFC - _02233FF0 - 2 ; case 1
	.short _02234002 - _02233FF0 - 2 ; case 2
	.short _02234008 - _02233FF0 - 2 ; case 3
_02233FF8:
	add r6, r4, #0
	b _02234462
_02233FFC:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234002:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234008:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_0223400E:
	add r4, #0x20
	cmp r5, #3
	bhi _02234104
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234020: ; jump table
	.short _02234028 - _02234020 - 2 ; case 0
	.short _0223402C - _02234020 - 2 ; case 1
	.short _02234032 - _02234020 - 2 ; case 2
	.short _02234038 - _02234020 - 2 ; case 3
_02234028:
	add r6, r4, #0
	b _02234462
_0223402C:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234032:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234038:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_0223403E:
	add r4, #0x20
	cmp r5, #3
	bhi _02234104
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234050: ; jump table
	.short _02234058 - _02234050 - 2 ; case 0
	.short _0223405C - _02234050 - 2 ; case 1
	.short _02234062 - _02234050 - 2 ; case 2
	.short _02234068 - _02234050 - 2 ; case 3
_02234058:
	add r6, r4, #0
	b _02234462
_0223405C:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234062:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234068:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_0223406E:
	add r4, #0x20
	cmp r5, #3
	bhi _02234104
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234080: ; jump table
	.short _02234088 - _02234080 - 2 ; case 0
	.short _0223408C - _02234080 - 2 ; case 1
	.short _02234092 - _02234080 - 2 ; case 2
	.short _02234098 - _02234080 - 2 ; case 3
_02234088:
	add r6, r4, #0
	b _02234462
_0223408C:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234092:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234098:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_0223409E:
	add r4, #0x20
	cmp r5, #3
	bhi _02234104
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022340B0: ; jump table
	.short _022340B8 - _022340B0 - 2 ; case 0
	.short _022340BC - _022340B0 - 2 ; case 1
	.short _022340C2 - _022340B0 - 2 ; case 2
	.short _022340C8 - _022340B0 - 2 ; case 3
_022340B8:
	add r6, r4, #0
	b _02234462
_022340BC:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_022340C2:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_022340C8:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_022340CE:
	add r4, #0x20
	cmp r5, #3
	bhi _02234104
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022340E0: ; jump table
	.short _022340E8 - _022340E0 - 2 ; case 0
	.short _022340EC - _022340E0 - 2 ; case 1
	.short _022340F2 - _022340E0 - 2 ; case 2
	.short _022340F8 - _022340E0 - 2 ; case 3
_022340E8:
	add r6, r4, #0
	b _02234462
_022340EC:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_022340F2:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_022340F8:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_022340FE:
	add r4, #0x20
	cmp r5, #3
	bls _02234106
_02234104:
	b _02234462
_02234106:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234112: ; jump table
	.short _0223411A - _02234112 - 2 ; case 0
	.short _02234120 - _02234112 - 2 ; case 1
	.short _02234124 - _02234112 - 2 ; case 2
	.short _0223412A - _02234112 - 2 ; case 3
_0223411A:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234120:
	add r6, r4, #0
	b _02234462
_02234124:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_0223412A:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234130:
	add r4, #0x20
	cmp r5, #3
	bhi _02234226
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234142: ; jump table
	.short _0223414A - _02234142 - 2 ; case 0
	.short _02234150 - _02234142 - 2 ; case 1
	.short _02234154 - _02234142 - 2 ; case 2
	.short _0223415A - _02234142 - 2 ; case 3
_0223414A:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234150:
	add r6, r4, #0
	b _02234462
_02234154:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_0223415A:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234160:
	add r4, #0x20
	cmp r5, #3
	bhi _02234226
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234172: ; jump table
	.short _0223417A - _02234172 - 2 ; case 0
	.short _02234180 - _02234172 - 2 ; case 1
	.short _02234184 - _02234172 - 2 ; case 2
	.short _0223418A - _02234172 - 2 ; case 3
_0223417A:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234180:
	add r6, r4, #0
	b _02234462
_02234184:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_0223418A:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234190:
	add r4, #0x20
	cmp r5, #3
	bhi _02234226
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022341A2: ; jump table
	.short _022341AA - _022341A2 - 2 ; case 0
	.short _022341B0 - _022341A2 - 2 ; case 1
	.short _022341B4 - _022341A2 - 2 ; case 2
	.short _022341BA - _022341A2 - 2 ; case 3
_022341AA:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_022341B0:
	add r6, r4, #0
	b _02234462
_022341B4:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_022341BA:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_022341C0:
	add r4, #0x20
	cmp r5, #3
	bhi _02234226
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022341D2: ; jump table
	.short _022341DA - _022341D2 - 2 ; case 0
	.short _022341E0 - _022341D2 - 2 ; case 1
	.short _022341E4 - _022341D2 - 2 ; case 2
	.short _022341EA - _022341D2 - 2 ; case 3
_022341DA:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_022341E0:
	add r6, r4, #0
	b _02234462
_022341E4:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_022341EA:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_022341F0:
	add r4, #0x20
	cmp r5, #3
	bhi _02234226
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234202: ; jump table
	.short _0223420A - _02234202 - 2 ; case 0
	.short _02234210 - _02234202 - 2 ; case 1
	.short _02234214 - _02234202 - 2 ; case 2
	.short _0223421A - _02234202 - 2 ; case 3
_0223420A:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234210:
	add r6, r4, #0
	b _02234462
_02234214:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_0223421A:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234220:
	add r4, #0x20
	cmp r5, #3
	bls _02234228
_02234226:
	b _02234462
_02234228:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234234: ; jump table
	.short _0223423C - _02234234 - 2 ; case 0
	.short _02234242 - _02234234 - 2 ; case 1
	.short _02234248 - _02234234 - 2 ; case 2
	.short _0223424C - _02234234 - 2 ; case 3
_0223423C:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234242:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234248:
	add r6, r4, #0
	b _02234462
_0223424C:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234252:
	add r4, #0x20
	cmp r5, #3
	bhi _02234348
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234264: ; jump table
	.short _0223426C - _02234264 - 2 ; case 0
	.short _02234272 - _02234264 - 2 ; case 1
	.short _02234278 - _02234264 - 2 ; case 2
	.short _0223427C - _02234264 - 2 ; case 3
_0223426C:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234272:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234278:
	add r6, r4, #0
	b _02234462
_0223427C:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234282:
	add r4, #0x20
	cmp r5, #3
	bhi _02234348
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234294: ; jump table
	.short _0223429C - _02234294 - 2 ; case 0
	.short _022342A2 - _02234294 - 2 ; case 1
	.short _022342A8 - _02234294 - 2 ; case 2
	.short _022342AC - _02234294 - 2 ; case 3
_0223429C:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_022342A2:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_022342A8:
	add r6, r4, #0
	b _02234462
_022342AC:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_022342B2:
	add r4, #0x20
	cmp r5, #3
	bhi _02234348
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022342C4: ; jump table
	.short _022342CC - _022342C4 - 2 ; case 0
	.short _022342D2 - _022342C4 - 2 ; case 1
	.short _022342D8 - _022342C4 - 2 ; case 2
	.short _022342DC - _022342C4 - 2 ; case 3
_022342CC:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_022342D2:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_022342D8:
	add r6, r4, #0
	b _02234462
_022342DC:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_022342E2:
	add r4, #0x20
	cmp r5, #3
	bhi _02234348
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022342F4: ; jump table
	.short _022342FC - _022342F4 - 2 ; case 0
	.short _02234302 - _022342F4 - 2 ; case 1
	.short _02234308 - _022342F4 - 2 ; case 2
	.short _0223430C - _022342F4 - 2 ; case 3
_022342FC:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234302:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234308:
	add r6, r4, #0
	b _02234462
_0223430C:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234312:
	add r4, #0x20
	cmp r5, #3
	bhi _02234348
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234324: ; jump table
	.short _0223432C - _02234324 - 2 ; case 0
	.short _02234332 - _02234324 - 2 ; case 1
	.short _02234338 - _02234324 - 2 ; case 2
	.short _0223433C - _02234324 - 2 ; case 3
_0223432C:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234332:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234338:
	add r6, r4, #0
	b _02234462
_0223433C:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234342:
	add r4, #0x20
	cmp r5, #3
	bls _0223434A
_02234348:
	b _02234462
_0223434A:
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234356: ; jump table
	.short _0223435E - _02234356 - 2 ; case 0
	.short _02234364 - _02234356 - 2 ; case 1
	.short _0223436A - _02234356 - 2 ; case 2
	.short _02234370 - _02234356 - 2 ; case 3
_0223435E:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234364:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_0223436A:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234370:
	add r6, r4, #0
	b _02234462
_02234374:
	add r4, #0x20
	cmp r5, #3
	bhi _02234462
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234386: ; jump table
	.short _0223438E - _02234386 - 2 ; case 0
	.short _02234394 - _02234386 - 2 ; case 1
	.short _0223439A - _02234386 - 2 ; case 2
	.short _022343A0 - _02234386 - 2 ; case 3
_0223438E:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234394:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_0223439A:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_022343A0:
	add r6, r4, #0
	b _02234462
_022343A4:
	add r4, #0x20
	cmp r5, #3
	bhi _02234462
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022343B6: ; jump table
	.short _022343BE - _022343B6 - 2 ; case 0
	.short _022343C4 - _022343B6 - 2 ; case 1
	.short _022343CA - _022343B6 - 2 ; case 2
	.short _022343D0 - _022343B6 - 2 ; case 3
_022343BE:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_022343C4:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_022343CA:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_022343D0:
	add r6, r4, #0
	b _02234462
_022343D4:
	add r4, #0x20
	cmp r5, #3
	bhi _02234462
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022343E6: ; jump table
	.short _022343EE - _022343E6 - 2 ; case 0
	.short _022343F4 - _022343E6 - 2 ; case 1
	.short _022343FA - _022343E6 - 2 ; case 2
	.short _02234400 - _022343E6 - 2 ; case 3
_022343EE:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_022343F4:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_022343FA:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234400:
	add r6, r4, #0
	b _02234462
_02234404:
	add r4, #0x20
	cmp r5, #3
	bhi _02234462
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234416: ; jump table
	.short _0223441E - _02234416 - 2 ; case 0
	.short _02234424 - _02234416 - 2 ; case 1
	.short _0223442A - _02234416 - 2 ; case 2
	.short _02234430 - _02234416 - 2 ; case 3
_0223441E:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_02234424:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_0223442A:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234430:
	add r6, r4, #0
	b _02234462
_02234434:
	add r4, #0x20
	cmp r5, #3
	bhi _02234462
	add r0, r5, r5
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234446: ; jump table
	.short _0223444E - _02234446 - 2 ; case 0
	.short _02234454 - _02234446 - 2 ; case 1
	.short _0223445A - _02234446 - 2 ; case 2
	.short _02234460 - _02234446 - 2 ; case 3
_0223444E:
	add r6, r4, #0
	add r6, #0x24
	b _02234462
_02234454:
	add r6, r4, #0
	add r6, #0x18
	b _02234462
_0223445A:
	add r6, r4, #0
	add r6, #0xc
	b _02234462
_02234460:
	add r6, r4, #0
_02234462:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov74_02233F8C


	thumb_func_start ov74_02234468
ov74_02234468: ; 0x02234468
	push {r3, r4}
	add r4, r0, #0
	mov r3, #0
	add r4, #0x20
_02234470:
	ldr r2, [r4]
	ldr r1, [r0, #4]
	add r3, r3, #1
	eor r2, r1
	str r2, [r4]
	ldr r1, [r0]
	eor r1, r2
	stmia r4!, {r1}
	cmp r3, #0xc
	blo _02234470
	pop {r3, r4}
	bx lr
	thumb_func_end ov74_02234468


	thumb_func_start ov74_02234488
ov74_02234488: ; 0x02234488
	push {r3, r4}
	add r4, r0, #0
	mov r3, #0
	add r4, #0x20
_02234490:
	ldr r2, [r4]
	ldr r1, [r0]
	add r3, r3, #1
	eor r2, r1
	str r2, [r4]
	ldr r1, [r0, #4]
	eor r1, r2
	stmia r4!, {r1}
	cmp r3, #0xc
	blo _02234490
	pop {r3, r4}
	bx lr
	thumb_func_end ov74_02234488


	thumb_func_start ov74_022344A8
ov74_022344A8: ; 0x022344A8
	push {r3, r4, r5, r6, r7, lr}
	add r1, r0, #0
	mov r4, #0
	ldr r1, [r1]
	str r0, [sp]
	add r2, r4, #0
	bl ov74_02233F8C
	add r5, r0, #0
	ldr r0, [sp]
	mov r2, #1
	add r1, r0, #0
	ldr r1, [r1]
	bl ov74_02233F8C
	add r6, r0, #0
	ldr r0, [sp]
	mov r2, #2
	add r1, r0, #0
	ldr r1, [r1]
	bl ov74_02233F8C
	add r7, r0, #0
	ldr r0, [sp]
	mov r2, #3
	add r1, r0, #0
	ldr r1, [r1]
	bl ov74_02233F8C
	add r1, r4, #0
_022344E4:
	ldrh r2, [r5]
	add r1, r1, #1
	add r5, r5, #2
	add r2, r4, r2
	lsl r2, r2, #0x10
	lsr r4, r2, #0x10
	cmp r1, #6
	blt _022344E4
	mov r2, #0
_022344F6:
	ldrh r1, [r6]
	add r2, r2, #1
	add r6, r6, #2
	add r1, r4, r1
	lsl r1, r1, #0x10
	lsr r4, r1, #0x10
	cmp r2, #6
	blt _022344F6
	mov r2, #0
_02234508:
	ldrh r1, [r7]
	add r2, r2, #1
	add r7, r7, #2
	add r1, r4, r1
	lsl r1, r1, #0x10
	lsr r4, r1, #0x10
	cmp r2, #6
	blt _02234508
	mov r2, #0
_0223451A:
	ldrh r1, [r0]
	add r2, r2, #1
	add r0, r0, #2
	add r1, r4, r1
	lsl r1, r1, #0x10
	lsr r4, r1, #0x10
	cmp r2, #6
	blt _0223451A
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov74_022344A8


	thumb_func_start AGB_GetBoxMonData
AGB_GetBoxMonData: ; 0x02234530
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov r4, #0
	add r6, r0, #0
	str r1, [sp]
	add r7, r2, #0
	add r5, r4, #0
	str r4, [sp, #0xc]
	str r4, [sp, #8]
	str r4, [sp, #4]
	cmp r1, #0xa
	ble _022345A6
	ldr r1, [r6]
	add r2, r4, #0
	bl ov74_02233F8C
	str r0, [sp, #0xc]
	ldr r1, [r6]
	add r0, r6, #0
	mov r2, #1
	bl ov74_02233F8C
	str r0, [sp, #8]
	ldr r1, [r6]
	add r0, r6, #0
	mov r2, #2
	bl ov74_02233F8C
	str r0, [sp, #4]
	ldr r1, [r6]
	add r0, r6, #0
	mov r2, #3
	bl ov74_02233F8C
	add r5, r0, #0
	add r0, r6, #0
	bl ov74_02234468
	add r0, r6, #0
	bl ov74_022344A8
	ldrh r1, [r6, #0x1c]
	cmp r0, r1
	beq _022345A6
	ldrb r0, [r6, #0x13]
	mov r1, #1
	bic r0, r1
	mov r1, #1
	orr r0, r1
	strb r0, [r6, #0x13]
	ldrb r1, [r6, #0x13]
	mov r0, #4
	orr r0, r1
	strb r0, [r6, #0x13]
	mov r0, #1
	ldr r1, [r5, #4]
	lsl r0, r0, #0x1e
	orr r0, r1
	str r0, [r5, #4]
_022345A6:
	ldr r0, [sp]
	cmp r0, #0x50
	bls _022345AE
	b _0223489C
_022345AE:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022345BA: ; jump table
	.short _0223465C - _022345BA - 2 ; case 0
	.short _02234660 - _022345BA - 2 ; case 1
	.short _02234664 - _022345BA - 2 ; case 2
	.short _02234684 - _022345BA - 2 ; case 3
	.short _02234688 - _022345BA - 2 ; case 4
	.short _02234690 - _022345BA - 2 ; case 5
	.short _02234698 - _022345BA - 2 ; case 6
	.short _022346A0 - _022345BA - 2 ; case 7
	.short _022346B4 - _022345BA - 2 ; case 8
	.short _022346B8 - _022345BA - 2 ; case 9
	.short _022346BC - _022345BA - 2 ; case 10
	.short _022346C0 - _022345BA - 2 ; case 11
	.short _022346D4 - _022345BA - 2 ; case 12
	.short _022346EC - _022345BA - 2 ; case 13
	.short _022346EC - _022345BA - 2 ; case 14
	.short _022346EC - _022345BA - 2 ; case 15
	.short _022346EC - _022345BA - 2 ; case 16
	.short _022346F8 - _022345BA - 2 ; case 17
	.short _022346F8 - _022345BA - 2 ; case 18
	.short _022346F8 - _022345BA - 2 ; case 19
	.short _022346F8 - _022345BA - 2 ; case 20
	.short _022346E0 - _022345BA - 2 ; case 21
	.short _02234728 - _022345BA - 2 ; case 22
	.short _0223472E - _022345BA - 2 ; case 23
	.short _02234734 - _022345BA - 2 ; case 24
	.short _022346DA - _022345BA - 2 ; case 25
	.short _02234704 - _022345BA - 2 ; case 26
	.short _0223470A - _022345BA - 2 ; case 27
	.short _02234710 - _022345BA - 2 ; case 28
	.short _02234716 - _022345BA - 2 ; case 29
	.short _0223471C - _022345BA - 2 ; case 30
	.short _02234722 - _022345BA - 2 ; case 31
	.short _022346E6 - _022345BA - 2 ; case 32
	.short _0223473A - _022345BA - 2 ; case 33
	.short _0223474C - _022345BA - 2 ; case 34
	.short _02234754 - _022345BA - 2 ; case 35
	.short _0223475C - _022345BA - 2 ; case 36
	.short _02234764 - _022345BA - 2 ; case 37
	.short _0223476C - _022345BA - 2 ; case 38
	.short _0223477A - _022345BA - 2 ; case 39
	.short _02234782 - _022345BA - 2 ; case 40
	.short _0223478A - _022345BA - 2 ; case 41
	.short _02234792 - _022345BA - 2 ; case 42
	.short _0223479A - _022345BA - 2 ; case 43
	.short _022347A2 - _022345BA - 2 ; case 44
	.short _022347AA - _022345BA - 2 ; case 45
	.short _022347B2 - _022345BA - 2 ; case 46
	.short _02234740 - _022345BA - 2 ; case 47
	.short _02234746 - _022345BA - 2 ; case 48
	.short _02234774 - _022345BA - 2 ; case 49
	.short _022347B8 - _022345BA - 2 ; case 50
	.short _022347C0 - _022345BA - 2 ; case 51
	.short _022347C8 - _022345BA - 2 ; case 52
	.short _022347D0 - _022345BA - 2 ; case 53
	.short _022347D8 - _022345BA - 2 ; case 54
	.short _0223489C - _022345BA - 2 ; case 55
	.short _0223489C - _022345BA - 2 ; case 56
	.short _0223489C - _022345BA - 2 ; case 57
	.short _0223489C - _022345BA - 2 ; case 58
	.short _0223489C - _022345BA - 2 ; case 59
	.short _0223489C - _022345BA - 2 ; case 60
	.short _0223489C - _022345BA - 2 ; case 61
	.short _0223489C - _022345BA - 2 ; case 62
	.short _0223489C - _022345BA - 2 ; case 63
	.short _0223489C - _022345BA - 2 ; case 64
	.short _0223484E - _022345BA - 2 ; case 65
	.short _0223486C - _022345BA - 2 ; case 66
	.short _022347E0 - _022345BA - 2 ; case 67
	.short _022347E8 - _022345BA - 2 ; case 68
	.short _022347F0 - _022345BA - 2 ; case 69
	.short _022347F8 - _022345BA - 2 ; case 70
	.short _02234800 - _022345BA - 2 ; case 71
	.short _02234808 - _022345BA - 2 ; case 72
	.short _02234810 - _022345BA - 2 ; case 73
	.short _02234818 - _022345BA - 2 ; case 74
	.short _02234820 - _022345BA - 2 ; case 75
	.short _02234828 - _022345BA - 2 ; case 76
	.short _02234830 - _022345BA - 2 ; case 77
	.short _02234838 - _022345BA - 2 ; case 78
	.short _02234840 - _022345BA - 2 ; case 79
	.short _02234848 - _022345BA - 2 ; case 80
_0223465C:
	ldr r4, [r6]
	b _0223489C
_02234660:
	ldr r4, [r6, #4]
	b _0223489C
_02234664:
	ldrb r0, [r6, #0x13]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _02234670
	mov r4, #0
	b _0223467E
_02234670:
	mov r4, #0
_02234672:
	add r0, r6, r4
	ldrb r0, [r0, #8]
	strb r0, [r7, r4]
	add r4, r4, #1
	cmp r4, #0xa
	blo _02234672
_0223467E:
	mov r0, #0xff
	strb r0, [r7, r4]
	b _0223489C
_02234684:
	ldrb r4, [r6, #0x12]
	b _0223489C
_02234688:
	ldrb r0, [r6, #0x13]
	lsl r0, r0, #0x1f
	lsr r4, r0, #0x1f
	b _0223489C
_02234690:
	ldrb r0, [r6, #0x13]
	lsl r0, r0, #0x1e
	lsr r4, r0, #0x1f
	b _0223489C
_02234698:
	ldrb r0, [r6, #0x13]
	lsl r0, r0, #0x1d
	lsr r4, r0, #0x1f
	b _0223489C
_022346A0:
	mov r4, #0
_022346A2:
	add r0, r6, r4
	ldrb r0, [r0, #0x14]
	strb r0, [r7, r4]
	add r4, r4, #1
	cmp r4, #7
	blo _022346A2
	mov r0, #0xff
	strb r0, [r7, r4]
	b _0223489C
_022346B4:
	ldrb r4, [r6, #0x1b]
	b _0223489C
_022346B8:
	ldrh r4, [r6, #0x1c]
	b _0223489C
_022346BC:
	ldrh r4, [r6, #0x1e]
	b _0223489C
_022346C0:
	ldrb r0, [r6, #0x13]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _022346CE
	mov r4, #0x67
	lsl r4, r4, #2
	b _0223489C
_022346CE:
	ldr r0, [sp, #0xc]
	ldrh r4, [r0]
	b _0223489C
_022346D4:
	ldr r0, [sp, #0xc]
	ldrh r4, [r0, #2]
	b _0223489C
_022346DA:
	ldr r0, [sp, #0xc]
	ldr r4, [r0, #4]
	b _0223489C
_022346E0:
	ldr r0, [sp, #0xc]
	ldrb r4, [r0, #8]
	b _0223489C
_022346E6:
	ldr r0, [sp, #0xc]
	ldrb r4, [r0, #9]
	b _0223489C
_022346EC:
	ldr r0, [sp]
	sub r0, #0xd
	lsl r1, r0, #1
	ldr r0, [sp, #8]
	ldrh r4, [r0, r1]
	b _0223489C
_022346F8:
	ldr r1, [sp]
	ldr r0, [sp, #8]
	sub r1, #0x11
	add r0, r0, r1
	ldrb r4, [r0, #8]
	b _0223489C
_02234704:
	ldr r0, [sp, #4]
	ldrb r4, [r0]
	b _0223489C
_0223470A:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #1]
	b _0223489C
_02234710:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #2]
	b _0223489C
_02234716:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #3]
	b _0223489C
_0223471C:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #4]
	b _0223489C
_02234722:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #5]
	b _0223489C
_02234728:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #6]
	b _0223489C
_0223472E:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #7]
	b _0223489C
_02234734:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #8]
	b _0223489C
_0223473A:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #9]
	b _0223489C
_02234740:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #0xa]
	b _0223489C
_02234746:
	ldr r0, [sp, #4]
	ldrb r4, [r0, #0xb]
	b _0223489C
_0223474C:
	ldr r0, [r5]
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	b _0223489C
_02234754:
	ldr r0, [r5]
	lsl r0, r0, #0x10
	lsr r4, r0, #0x18
	b _0223489C
_0223475C:
	ldr r0, [r5]
	lsl r0, r0, #9
	lsr r4, r0, #0x19
	b _0223489C
_02234764:
	ldr r0, [r5]
	lsl r0, r0, #5
	lsr r4, r0, #0x1c
	b _0223489C
_0223476C:
	ldr r0, [r5]
	lsl r0, r0, #1
	lsr r4, r0, #0x1c
	b _0223489C
_02234774:
	ldr r0, [r5]
	lsr r4, r0, #0x1f
	b _0223489C
_0223477A:
	ldr r0, [r5, #4]
	lsl r0, r0, #0x1b
	lsr r4, r0, #0x1b
	b _0223489C
_02234782:
	ldr r0, [r5, #4]
	lsl r0, r0, #0x16
	lsr r4, r0, #0x1b
	b _0223489C
_0223478A:
	ldr r0, [r5, #4]
	lsl r0, r0, #0x11
	lsr r4, r0, #0x1b
	b _0223489C
_02234792:
	ldr r0, [r5, #4]
	lsl r0, r0, #0xc
	lsr r4, r0, #0x1b
	b _0223489C
_0223479A:
	ldr r0, [r5, #4]
	lsl r0, r0, #7
	lsr r4, r0, #0x1b
	b _0223489C
_022347A2:
	ldr r0, [r5, #4]
	lsl r0, r0, #2
	lsr r4, r0, #0x1b
	b _0223489C
_022347AA:
	ldr r0, [r5, #4]
	lsl r0, r0, #1
	lsr r4, r0, #0x1f
	b _0223489C
_022347B2:
	ldr r0, [r5, #4]
	lsr r4, r0, #0x1f
	b _0223489C
_022347B8:
	ldr r0, [r5, #8]
	lsl r0, r0, #0x1d
	lsr r4, r0, #0x1d
	b _0223489C
_022347C0:
	ldr r0, [r5, #8]
	lsl r0, r0, #0x1a
	lsr r4, r0, #0x1d
	b _0223489C
_022347C8:
	ldr r0, [r5, #8]
	lsl r0, r0, #0x17
	lsr r4, r0, #0x1d
	b _0223489C
_022347D0:
	ldr r0, [r5, #8]
	lsl r0, r0, #0x14
	lsr r4, r0, #0x1d
	b _0223489C
_022347D8:
	ldr r0, [r5, #8]
	lsl r0, r0, #0x11
	lsr r4, r0, #0x1d
	b _0223489C
_022347E0:
	ldr r0, [r5, #8]
	lsl r0, r0, #0x10
	lsr r4, r0, #0x1f
	b _0223489C
_022347E8:
	ldr r0, [r5, #8]
	lsl r0, r0, #0xf
	lsr r4, r0, #0x1f
	b _0223489C
_022347F0:
	ldr r0, [r5, #8]
	lsl r0, r0, #0xe
	lsr r4, r0, #0x1f
	b _0223489C
_022347F8:
	ldr r0, [r5, #8]
	lsl r0, r0, #0xd
	lsr r4, r0, #0x1f
	b _0223489C
_02234800:
	ldr r0, [r5, #8]
	lsl r0, r0, #0xc
	lsr r4, r0, #0x1f
	b _0223489C
_02234808:
	ldr r0, [r5, #8]
	lsl r0, r0, #0xb
	lsr r4, r0, #0x1f
	b _0223489C
_02234810:
	ldr r0, [r5, #8]
	lsl r0, r0, #0xa
	lsr r4, r0, #0x1f
	b _0223489C
_02234818:
	ldr r0, [r5, #8]
	lsl r0, r0, #9
	lsr r4, r0, #0x1f
	b _0223489C
_02234820:
	ldr r0, [r5, #8]
	lsl r0, r0, #8
	lsr r4, r0, #0x1f
	b _0223489C
_02234828:
	ldr r0, [r5, #8]
	lsl r0, r0, #7
	lsr r4, r0, #0x1f
	b _0223489C
_02234830:
	ldr r0, [r5, #8]
	lsl r0, r0, #6
	lsr r4, r0, #0x1f
	b _0223489C
_02234838:
	ldr r0, [r5, #8]
	lsl r0, r0, #5
	lsr r4, r0, #0x1f
	b _0223489C
_02234840:
	ldr r0, [r5, #8]
	lsl r0, r0, #1
	lsr r4, r0, #0x1c
	b _0223489C
_02234848:
	ldr r0, [r5, #8]
	lsr r4, r0, #0x1f
	b _0223489C
_0223484E:
	ldr r0, [sp, #0xc]
	ldrh r4, [r0]
	cmp r4, #0
	beq _0223489C
	ldr r0, [r5, #4]
	lsl r0, r0, #1
	lsr r0, r0, #0x1f
	bne _02234866
	ldrb r0, [r6, #0x13]
	lsl r0, r0, #0x1f
	lsr r0, r0, #0x1f
	beq _0223489C
_02234866:
	mov r4, #0x67
	lsl r4, r4, #2
	b _0223489C
_0223486C:
	ldr r4, [r5, #4]
	lsl r0, r4, #2
	lsr r0, r0, #0x1b
	lsl r5, r0, #0x19
	lsl r0, r4, #7
	lsr r0, r0, #0x1b
	lsl r3, r0, #0x14
	lsl r0, r4, #0xc
	lsr r0, r0, #0x1b
	lsl r2, r0, #0xf
	lsl r0, r4, #0x11
	lsr r0, r0, #0x1b
	lsl r1, r0, #0xa
	lsl r0, r4, #0x1b
	lsl r4, r4, #0x16
	lsr r4, r4, #0x1b
	lsr r0, r0, #0x1b
	lsl r4, r4, #5
	orr r0, r4
	orr r0, r1
	orr r0, r2
	orr r0, r3
	add r4, r5, #0
	orr r4, r0
_0223489C:
	ldr r0, [sp]
	cmp r0, #0xa
	ble _022348A8
	add r0, r6, #0
	bl ov74_02234488
_022348A8:
	add r0, r4, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end AGB_GetBoxMonData


	thumb_func_start ov74_022348B0
ov74_022348B0: ; 0x022348B0
	push {r3, r4, r5, r6, r7, lr}
	add r6, r1, #0
	add r4, r0, #0
	add r5, r2, #0
	mov r7, #0
	cmp r6, #0xa
	ble _02234924
	ldr r1, [r4]
	add r2, r7, #0
	bl ov74_02233F8C
	add r7, r0, #0
	ldr r1, [r4]
	add r0, r4, #0
	mov r2, #1
	bl ov74_02233F8C
	ldr r1, [r4]
	add r0, r4, #0
	mov r2, #2
	bl ov74_02233F8C
	ldr r1, [r4]
	add r0, r4, #0
	mov r2, #3
	bl ov74_02233F8C
	str r0, [sp]
	add r0, r4, #0
	bl ov74_02234468
	add r0, r4, #0
	bl ov74_022344A8
	ldrh r1, [r4, #0x1c]
	cmp r0, r1
	beq _02234924
	ldrb r1, [r4, #0x13]
	mov r0, #1
	bic r1, r0
	mov r0, #1
	orr r0, r1
	strb r0, [r4, #0x13]
	ldrb r1, [r4, #0x13]
	mov r0, #4
	orr r0, r1
	strb r0, [r4, #0x13]
	ldr r0, [sp]
	ldr r1, [r0, #4]
	mov r0, #1
	lsl r0, r0, #0x1e
	orr r1, r0
	ldr r0, [sp]
	str r1, [r0, #4]
	add r0, r4, #0
	bl ov74_02234488
	pop {r3, r4, r5, r6, r7, pc}
_02234924:
	cmp r6, #0xb
	bhi _022349C8
	add r0, r6, r6
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234934: ; jump table
	.short _022349C8 - _02234934 - 2 ; case 0
	.short _022349C8 - _02234934 - 2 ; case 1
	.short _0223494C - _02234934 - 2 ; case 2
	.short _0223495C - _02234934 - 2 ; case 3
	.short _02234962 - _02234934 - 2 ; case 4
	.short _02234974 - _02234934 - 2 ; case 5
	.short _02234986 - _02234934 - 2 ; case 6
	.short _02234998 - _02234934 - 2 ; case 7
	.short _022349C8 - _02234934 - 2 ; case 8
	.short _022349C8 - _02234934 - 2 ; case 9
	.short _022349C8 - _02234934 - 2 ; case 10
	.short _022349A8 - _02234934 - 2 ; case 11
_0223494C:
	mov r2, #0
_0223494E:
	ldrb r1, [r5, r2]
	add r0, r4, r2
	add r2, r2, #1
	strb r1, [r0, #8]
	cmp r2, #0xa
	blt _0223494E
	b _022349C8
_0223495C:
	ldrb r0, [r5]
	strb r0, [r4, #0x12]
	b _022349C8
_02234962:
	ldrb r0, [r4, #0x13]
	ldrb r2, [r5]
	mov r1, #1
	bic r0, r1
	mov r1, #1
	and r1, r2
	orr r0, r1
	strb r0, [r4, #0x13]
	b _022349C8
_02234974:
	ldrb r0, [r4, #0x13]
	mov r1, #2
	bic r0, r1
	ldrb r1, [r5]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1e
	orr r0, r1
	strb r0, [r4, #0x13]
	b _022349C8
_02234986:
	ldrb r0, [r4, #0x13]
	mov r1, #4
	bic r0, r1
	ldrb r1, [r5]
	lsl r1, r1, #0x1f
	lsr r1, r1, #0x1d
	orr r0, r1
	strb r0, [r4, #0x13]
	b _022349C8
_02234998:
	mov r2, #0
_0223499A:
	ldrb r1, [r5, r2]
	add r0, r4, r2
	add r2, r2, #1
	strb r1, [r0, #0x14]
	cmp r2, #7
	blt _0223499A
	b _022349C8
_022349A8:
	ldrb r0, [r5, #1]
	ldrb r1, [r5]
	lsl r0, r0, #8
	add r0, r1, r0
	strh r0, [r7]
	ldrh r0, [r7]
	ldrb r1, [r4, #0x13]
	cmp r0, #0
	beq _022349C2
	mov r0, #2
	orr r0, r1
	strb r0, [r4, #0x13]
	b _022349C8
_022349C2:
	mov r0, #2
	bic r1, r0
	strb r1, [r4, #0x13]
_022349C8:
	cmp r6, #0xa
	ble _022349DA
	add r0, r4, #0
	bl ov74_022344A8
	strh r0, [r4, #0x1c]
	add r0, r4, #0
	bl ov74_02234488
_022349DA:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov74_022348B0


	thumb_func_start TranslateAgbSpecies
TranslateAgbSpecies: ; 0x022349DC
	ldr r1, _02234A00 ; =0x00000115
	cmp r0, r1
	blt _022349FC
	ldr r3, _02234A04 ; =ov74_0223CC5C
	mov r2, #0
_022349E6:
	ldrh r1, [r3]
	cmp r0, r1
	bne _022349F4
	ldr r0, _02234A08 ; =ov74_0223CC5E
	lsl r1, r2, #2
	ldrh r0, [r0, r1]
	bx lr
_022349F4:
	add r2, r2, #1
	add r3, r3, #4
	cmp r2, #0x90
	blo _022349E6
_022349FC:
	bx lr
	nop
_02234A00: .word 0x00000115
_02234A04: .word ov74_0223CC5C
_02234A08: .word ov74_0223CC5E
	thumb_func_end TranslateAgbSpecies


	thumb_func_start ov74_02234A0C
ov74_02234A0C: ; 0x02234A0C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r1, #0xb
	mov r2, #0
	bl AGB_GetBoxMonData
	bl TranslateAgbSpecies
	add r4, r0, #0
	add r0, r5, #0
	mov r1, #0x19
	mov r2, #0
	bl AGB_GetBoxMonData
	add r1, r0, #0
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	bl CalcLevelBySpeciesAndExp
	pop {r3, r4, r5, pc}
	thumb_func_end ov74_02234A0C


	thumb_func_start AGB_GetBoxMonAbility
AGB_GetBoxMonAbility: ; 0x02234A34
	push {r4, r5, r6, lr}
	add r4, r0, #0
	add r0, r1, #0
	mov r1, #5
	mov r2, #0
	bl GetBoxMonData
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	add r0, r4, #0
	mov r1, #0x2e
	mov r2, #0
	bl AGB_GetBoxMonData
	add r6, r0, #0
	add r0, r5, #0
	mov r1, #0x19
	bl GetMonBaseStat
	cmp r0, #0
	beq _02234A8E
	ldr r2, _02234A98 ; =ov74_0223CBA0
	mov r4, #0
_02234A62:
	ldrh r1, [r2]
	cmp r5, r1
	bne _02234A72
	add r0, r5, #0
	mov r1, #0x18
	bl GetMonBaseStat
	b _02234A7A
_02234A72:
	add r4, r4, #1
	add r2, r2, #2
	cmp r4, #0x5e
	blo _02234A62
_02234A7A:
	cmp r4, #0x5e
	bne _02234A96
	mov r1, #1
	tst r1, r6
	bne _02234A96
	add r0, r5, #0
	mov r1, #0x18
	bl GetMonBaseStat
	pop {r4, r5, r6, pc}
_02234A8E:
	add r0, r5, #0
	mov r1, #0x18
	bl GetMonBaseStat
_02234A96:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02234A98: .word ov74_0223CBA0
	thumb_func_end AGB_GetBoxMonAbility


	thumb_func_start MigrateBoxMon
MigrateBoxMon: ; 0x02234A9C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x30
	add r4, r1, #0
	add r6, r0, #0
	add r0, r4, #0
	bl ZeroBoxMonData
	add r0, r4, #0
	bl AcquireBoxMonLock
	mov r1, #0
	str r0, [sp]
	add r0, r6, #0
	add r2, r1, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0xb
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	bl TranslateAgbSpecies
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #5
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0xc
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	cmp r0, #0
	beq _02234AFE
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl UpConvertItemId_Gen3to4
	str r0, [sp, #8]
_02234AFE:
	add r0, r4, #0
	mov r1, #6
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #1
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #7
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x19
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #8
	add r2, sp, #8
	bl SetBoxMonData
	mov r0, #0x46
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #9
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	add r1, r4, #0
	bl AGB_GetBoxMonAbility
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0xa
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #8
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0xb
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #3
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xc
	add r2, sp, #4
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x1a
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0xd
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x1b
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0xe
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x1c
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0xf
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x1d
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x10
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x1e
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x11
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x1f
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x12
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x16
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x13
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x17
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x14
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x18
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x15
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x21
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x16
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x2f
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x17
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x30
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x18
	add r2, sp, #8
	bl SetBoxMonData
	mov r5, #0
	add r7, r5, #0
_02234C8E:
	add r1, r5, #0
	add r0, r6, #0
	add r1, #0xd
	mov r2, #0
	bl AGB_GetBoxMonData
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, #0x36
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x15
	mov r2, #0
	bl AGB_GetBoxMonData
	mov r1, #3
	lsl r1, r7
	str r0, [sp, #8]
	and r0, r1
	lsr r0, r7
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, #0x3e
	add r2, sp, #8
	bl SetBoxMonData
	add r1, r5, #0
	add r0, r4, #0
	add r1, #0x42
	mov r2, #0
	bl GetBoxMonData
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, #0x3a
	add r2, sp, #8
	bl SetBoxMonData
	add r5, r5, #1
	add r7, r7, #2
	cmp r5, #4
	blt _02234C8E
	add r0, r6, #0
	mov r1, #0x27
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x46
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x28
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x47
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x29
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x48
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x2a
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x49
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x2b
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x4a
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x2c
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x4b
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x2d
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x4c
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x32
	mov r2, #0
	bl AGB_GetBoxMonData
	add r7, r0, #0
	cmp r7, #4
	bgt _02234DB2
	mov r5, #0
	cmp r7, #0
	ble _02234DB2
_02234D9C:
	mov r0, #1
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, #0x4e
	add r2, sp, #8
	bl SetBoxMonData
	add r5, r5, #1
	cmp r5, r7
	blt _02234D9C
_02234DB2:
	add r0, r6, #0
	mov r1, #0x33
	mov r2, #0
	bl AGB_GetBoxMonData
	add r7, r0, #0
	cmp r7, #4
	bgt _02234DDE
	mov r5, #0
	cmp r7, #0
	ble _02234DDE
_02234DC8:
	mov r0, #1
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, #0x52
	add r2, sp, #8
	bl SetBoxMonData
	add r5, r5, #1
	cmp r5, r7
	blt _02234DC8
_02234DDE:
	add r0, r6, #0
	mov r1, #0x34
	mov r2, #0
	bl AGB_GetBoxMonData
	add r7, r0, #0
	cmp r7, #4
	bgt _02234E0A
	mov r5, #0
	cmp r7, #0
	ble _02234E0A
_02234DF4:
	mov r0, #1
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, #0x56
	add r2, sp, #8
	bl SetBoxMonData
	add r5, r5, #1
	cmp r5, r7
	blt _02234DF4
_02234E0A:
	add r0, r6, #0
	mov r1, #0x35
	mov r2, #0
	bl AGB_GetBoxMonData
	add r7, r0, #0
	cmp r7, #4
	bgt _02234E36
	mov r5, #0
	cmp r7, #0
	ble _02234E36
_02234E20:
	mov r0, #1
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, #0x5a
	add r2, sp, #8
	bl SetBoxMonData
	add r5, r5, #1
	cmp r5, r7
	blt _02234E20
_02234E36:
	add r0, r6, #0
	mov r1, #0x36
	mov r2, #0
	bl AGB_GetBoxMonData
	add r7, r0, #0
	cmp r7, #4
	bgt _02234E62
	mov r5, #0
	cmp r7, #0
	ble _02234E62
_02234E4C:
	mov r0, #1
	add r1, r5, #0
	str r0, [sp, #8]
	add r0, r4, #0
	add r1, #0x5e
	add r2, sp, #8
	bl SetBoxMonData
	add r5, r5, #1
	cmp r5, r7
	blt _02234E4C
_02234E62:
	add r0, r6, #0
	mov r1, #0x43
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x62
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x44
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x63
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x45
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x64
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x46
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x65
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x47
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x66
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x48
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x67
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x49
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x68
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x4a
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x69
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x4b
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x6a
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x4c
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x6b
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x4d
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x6c
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x4e
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x6d
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x50
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x6e
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r4, #0
	bl GetBoxMonGender
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x6f
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl GetBoxMonData
	cmp r0, #0xc9
	bne _02234FDE
	mov r1, #0
	add r0, r6, #0
	add r2, r1, #0
	bl AGB_GetBoxMonData
	add r3, r0, #0
	mov r7, #3
	lsl r0, r7, #8
	and r0, r3
	lsr r1, r0, #6
	lsl r0, r7, #0x18
	and r0, r3
	lsr r5, r0, #0x12
	lsl r0, r7, #0x10
	and r0, r3
	lsr r0, r0, #0xc
	add r2, r3, #0
	orr r0, r5
	orr r0, r1
	and r2, r7
	str r3, [sp, #8]
	orr r0, r2
	mov r1, #0x1c
	bl _u32_div_f
	str r1, [sp, #8]
	add r0, r4, #0
	mov r1, #0x70
	add r2, sp, #8
	bl SetBoxMonData
_02234FDE:
	add r0, r4, #0
	mov r1, #5
	mov r2, #0
	bl GetBoxMonData
	ldr r1, _02235120 ; =0x00000182
	cmp r0, r1
	bne _0223502E
	ldr r0, _02235124 ; =gSystem + 0x60
	ldrb r0, [r0, #0xa]
	cmp r0, #5
	bhi _0223500E
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02235002: ; jump table
	.short _0223500E - _02235002 - 2 ; case 0
	.short _0223500E - _02235002 - 2 ; case 1
	.short _0223500E - _02235002 - 2 ; case 2
	.short _02235020 - _02235002 - 2 ; case 3
	.short _02235014 - _02235002 - 2 ; case 4
	.short _0223501A - _02235002 - 2 ; case 5
_0223500E:
	mov r0, #0
	str r0, [sp, #8]
	b _02235024
_02235014:
	mov r0, #1
	str r0, [sp, #8]
	b _02235024
_0223501A:
	mov r0, #2
	str r0, [sp, #8]
	b _02235024
_02235020:
	mov r0, #3
	str r0, [sp, #8]
_02235024:
	add r0, r4, #0
	mov r1, #0x70
	add r2, sp, #8
	bl SetBoxMonData
_0223502E:
	add r0, r6, #0
	mov r1, #2
	add r2, sp, #0x24
	bl AGB_GetBoxMonData
	ldr r3, [sp, #4]
	add r0, sp, #0x24
	add r1, sp, #0xc
	mov r2, #0xc
	bl ConvertRSStringToDPStringInternational
	add r0, r4, #0
	mov r1, #0x76
	add r2, sp, #0xc
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #3
	mov r2, #0
	bl AGB_GetBoxMonData
	ldr r1, _02235128 ; =gGameLanguage
	ldrb r1, [r1]
	cmp r1, r0
	beq _0223506E
	mov r0, #1
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x4d
	add r2, sp, #8
	bl SetBoxMonData
_0223506E:
	add r0, r6, #0
	mov r1, #0x25
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x7a
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #7
	add r2, sp, #0x24
	bl AGB_GetBoxMonData
	ldr r3, [sp, #4]
	add r0, sp, #0x24
	add r1, sp, #0xc
	mov r2, #8
	bl ConvertRSStringToDPStringInternational
	add r0, r4, #0
	mov r1, #0x90
	add r2, sp, #0xc
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x23
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x99
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x22
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x9a
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x26
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x9b
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x24
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x9c
	add r2, sp, #8
	bl SetBoxMonData
	add r0, r6, #0
	mov r1, #0x31
	mov r2, #0
	bl AGB_GetBoxMonData
	str r0, [sp, #8]
	add r0, r4, #0
	mov r1, #0x9d
	add r2, sp, #8
	bl SetBoxMonData
	ldr r1, [sp]
	add r0, r4, #0
	bl ReleaseBoxMonLock
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02235120: .word 0x00000182
_02235124: .word gSystem + 0x60
_02235128: .word gGameLanguage
	thumb_func_end MigrateBoxMon


	thumb_func_start ov74_0223512C
ov74_0223512C: ; 0x0223512C
	ldr r1, _02235134 ; =ov74_0223D450
	str r0, [r1]
	bx lr
	nop
_02235134: .word ov74_0223D450
	thumb_func_end ov74_0223512C


	thumb_func_start ov74_02235138
ov74_02235138: ; 0x02235138
	add r1, r0, #0
	ldr r0, _02235144 ; =ov74_0223D450
	ldr r3, _02235148 ; =Heap_Alloc
	ldr r0, [r0]
	bx r3
	nop
_02235144: .word ov74_0223D450
_02235148: .word Heap_Alloc
	thumb_func_end ov74_02235138


	thumb_func_start ov74_0223514C
ov74_0223514C: ; 0x0223514C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x130
	bl CTRDG_GetAgbGameCode
	lsr r1, r0, #0x18
	lsl r1, r1, #0x18
	lsr r2, r1, #0x18
	lsr r1, r0, #0x10
	lsl r3, r0, #0x18
	lsr r0, r0, #8
	lsl r0, r0, #0x18
	lsl r1, r1, #0x18
	lsr r0, r0, #8
	lsr r1, r1, #0x10
	orr r0, r3
	orr r0, r1
	add r6, r2, #0
	orr r6, r0
	ldr r0, _022351E0 ; =ov74_0223CE9C
	mov r4, #0
	ldr r0, [r0]
	cmp r0, #0
	bls _022351D6
	ldr r5, _022351E4 ; =ov74_0223CE9C
	add r7, sp, #0x80
_02235182:
	ldr r0, [r5]
	cmp r6, r0
	bne _022351CC
	mov r0, #1
	bl CTRDG_Enable
	mov r0, #0x81
	ldr r2, _022351E8 ; =0x000004A8
	lsl r0, r0, #0x14
	add r1, r7, #0
	bl CTRDG_CpuCopy8
	ldr r0, _022351EC ; =0x08020000
	add r1, sp, #0
	mov r2, #0x80
	bl CTRDG_CpuCopy8
	mov r0, #0
	bl CTRDG_Enable
	ldr r0, _022351F0 ; =ov74_02235138
	ldr r1, _022351F4 ; =Heap_Free
	bl CRYPTO_SetAllocator
	ldr r1, _022351E8 ; =0x000004A8
	ldr r3, _022351F8 ; =_0223B690
	add r0, r7, #0
	add r2, sp, #0
	bl CRYPTO_VerifySignature
	cmp r0, #0
	beq _022351CC
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x130
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_022351CC:
	add r5, r5, #4
	ldr r0, [r5]
	add r4, r4, #1
	cmp r4, r0
	blo _02235182
_022351D6:
	mov r0, #0
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x130
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022351E0: .word ov74_0223CE9C
_022351E4: .word ov74_0223CE9C
_022351E8: .word 0x000004A8
_022351EC: .word 0x08020000
_022351F0: .word ov74_02235138
_022351F4: .word Heap_Free
_022351F8: .word _0223B690
	thumb_func_end ov74_0223514C


	thumb_func_start ov74_022351FC
ov74_022351FC: ; 0x022351FC
	push {r3, lr}
	bl CTRDG_Init
	bl CTRDG_IsAgbCartridge
	cmp r0, #0
	bne _0223520E
	mov r0, #0
	pop {r3, pc}
_0223520E:
	bl CTRDG_GetAgbMakerCode
	ldr r1, _0223522C ; =0x00003130
	cmp r0, r1
	beq _0223521C
	mov r0, #0
	pop {r3, pc}
_0223521C:
	bl ov74_0223514C
	cmp r0, #0
	beq _02235228
	mov r0, #1
	pop {r3, pc}
_02235228:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_0223522C: .word 0x00003130
	thumb_func_end ov74_022351FC


	thumb_func_start ov74_02235230
ov74_02235230: ; 0x02235230
	push {r3, lr}
	bl ov74_022351FC
	cmp r0, #0
	bne _0223523E
	mov r0, #0
	pop {r3, pc}
_0223523E:
	mov r0, #1
	bl CTRDG_Enable
	mov r0, #0x81
	lsl r0, r0, #0x14
	add r1, sp, #0
	bl CTRDG_Read32
	mov r0, #0
	bl CTRDG_Enable
	ldr r0, [sp]
	pop {r3, pc}
	thumb_func_end ov74_02235230


	thumb_func_start ov74_02235258
ov74_02235258: ; 0x02235258
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl ov74_022351FC
	cmp r0, #0
	bne _0223526A
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223526A:
	cmp r4, #0
	bne _02235274
	bl ov74_02235230
	add r4, r0, #0
_02235274:
	mov r0, #1
	bl CTRDG_Enable
	ldr r0, _0223529C ; =0x08100100
	add r1, r5, #0
	add r2, r4, #0
	bl CTRDG_CpuCopy16
	add r4, r0, #0
	mov r0, #0
	bl CTRDG_Enable
	bl CTRDG_IsExisting
	cmp r0, #0
	bne _02235298
	mov r0, #0
	pop {r3, r4, r5, pc}
_02235298:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0223529C: .word 0x08100100
	thumb_func_end ov74_02235258


	thumb_func_start ov74_022352A0
ov74_022352A0: ; 0x022352A0
	push {r3, r4, r5, r6}
	add r4, r0, #0
	mov r0, #0
	ldr r6, _022352C8 ; =ov74_0223D454
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	mov r5, #0x75
_022352B0:
	stmia r6!, {r0, r1, r2, r3}
	stmia r6!, {r0, r1, r2, r3}
	sub r5, r5, #1
	bne _022352B0
	stmia r6!, {r0, r1}
	ldr r0, _022352CC ; =ov74_0223D454
	mov r1, #1
	str r1, [r0, #4]
	str r4, [r0, #8]
	pop {r3, r4, r5, r6}
	bx lr
	nop
_022352C8: .word ov74_0223D454
_022352CC: .word ov74_0223D454
	thumb_func_end ov74_022352A0


	thumb_func_start ov74_022352D0
ov74_022352D0: ; 0x022352D0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r2, #0
	add r6, r1, #0
	mov r0, #3
	add r2, r3, #0
	bl Heap_Create
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl OverlayManager_CreateAndGetData
	mov r1, #0
	add r2, r4, #0
	add r5, r0, #0
	bl memset
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FBF4
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	add r0, r5, #0
	pop {r4, r5, r6, pc}
	thumb_func_end ov74_022352D0


	thumb_func_start ov74_02235308
ov74_02235308: ; 0x02235308
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	ldr r5, _0223538C ; =_0223B720
	add r6, r3, #0
	add r7, r0, #0
	add r4, r1, #0
	ldmia r5!, {r0, r1}
	add r3, sp, #0
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r5]
	cmp r2, #4
	str r0, [r3]
	add r0, sp, #0
	strb r2, [r0, #0x10]
	bhi _02235362
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223533A: ; jump table
	.short _02235362 - _0223533A - 2 ; case 0
	.short _02235344 - _0223533A - 2 ; case 1
	.short _0223534C - _0223533A - 2 ; case 2
	.short _02235354 - _0223533A - 2 ; case 3
	.short _0223535C - _0223533A - 2 ; case 4
_02235344:
	mov r0, #2
	lsl r0, r0, #0xa
	str r0, [sp, #8]
	b _02235362
_0223534C:
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	b _02235362
_02235354:
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	b _02235362
_0223535C:
	mov r0, #2
	lsl r0, r0, #0xc
	str r0, [sp, #8]
_02235362:
	lsr r1, r6, #0xb
	add r0, sp, #0
	strb r1, [r0, #0x12]
	ldr r1, [sp, #0x30]
	add r2, sp, #0
	lsr r1, r1, #0xe
	strb r1, [r0, #0x13]
	lsl r1, r4, #0x18
	add r0, r7, #0
	lsr r1, r1, #0x18
	mov r3, #0
	bl InitBgFromTemplate
	lsl r1, r4, #0x18
	add r0, r7, #0
	lsr r1, r1, #0x18
	bl BgClearTilemapBufferAndCommit
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_0223538C: .word _0223B720
	thumb_func_end ov74_02235308


	thumb_func_start ov74_02235390
ov74_02235390: ; 0x02235390
	ldr r1, _02235398 ; =ov74_0223D454
	str r0, [r1, #0x10]
	bx lr
	nop
_02235398: .word ov74_0223D454
	thumb_func_end ov74_02235390


	thumb_func_start ov74_0223539C
ov74_0223539C: ; 0x0223539C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp, #0xc]
	ldr r0, _022353F0 ; =ov74_0223D454
	add r5, r1, #0
	ldr r0, [r0, #0x10]
	add r4, r2, #0
	add r6, r3, #0
	ldr r7, _022353F4 ; =ov74_0223D454
	cmp r0, #0
	bne _022353CC
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r7, #8]
	ldr r1, [sp, #0xc]
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	b _022353E4
_022353CC:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r7, #8]
	ldr r1, [sp, #0xc]
	str r0, [sp, #8]
	ldr r3, _022353F8 ; =0x00007FFF
	mov r0, #0
	add r2, r1, #0
	bl BeginNormalPaletteFade
_022353E4:
	cmp r4, #0
	beq _022353EA
	str r6, [r4]
_022353EA:
	str r5, [r7, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022353F0: .word ov74_0223D454
_022353F4: .word ov74_0223D454
_022353F8: .word 0x00007FFF
	thumb_func_end ov74_0223539C


	thumb_func_start ov74_022353FC
ov74_022353FC: ; 0x022353FC
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r5, _02235410 ; =ov74_0223D454
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0223540E
	ldr r0, [r5, #0xc]
	str r0, [r4]
_0223540E:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02235410: .word ov74_0223D454
	thumb_func_end ov74_022353FC


	thumb_func_start ov74_02235414
ov74_02235414: ; 0x02235414
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r6, r2, #0
	mov r1, #0
	mov r2, #0x54
	add r5, r0, #0
	add r7, r3, #0
	bl memset
	mov r0, #1
	str r0, [r5, #4]
	str r0, [r5, #8]
	sub r0, r0, #2
	str r0, [r5, #0x4c]
	str r4, [r5, #0x10]
	str r6, [r5, #0x30]
	ldr r0, [sp, #0x18]
	str r7, [r5, #0x34]
	str r0, [r5, #0x38]
	ldr r0, [sp, #0x1c]
	mov r2, #0
	str r0, [r5, #0x3c]
	str r2, [r5, #0x2c]
	ldr r0, _02235460 ; =0x0001020F
	str r2, [r5, #0x40]
	str r0, [r5, #0x44]
	add r0, r5, #0
	mov r1, #0xf
	add r0, #0x48
	strb r1, [r0]
	str r2, [r5]
	str r2, [r5, #0x24]
	str r2, [r5, #0x20]
	str r2, [r5, #0x14]
	mov r0, #0xff
	str r0, [r5, #0x50]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02235460: .word 0x0001020F
	thumb_func_end ov74_02235414


	thumb_func_start ov74_02235464
ov74_02235464: ; 0x02235464
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	str r3, [r0, #0x28]
	bx lr
	thumb_func_end ov74_02235464


	thumb_func_start ov74_0223546C
ov74_0223546C: ; 0x0223546C
	str r1, [r0]
	str r2, [r0, #0x40]
	bx lr
	.balign 4, 0
	thumb_func_end ov74_0223546C


	thumb_func_start ov74_02235474
ov74_02235474: ; 0x02235474
	str r1, [r0, #0x20]
	str r2, [r0, #0x24]
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02235474


	thumb_func_start ov74_0223547C
ov74_0223547C: ; 0x0223547C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	mov r0, #0
	mvn r0, r0
	ldr r4, _02235564 ; =ov74_0223D454
	cmp r1, r0
	beq _0223555A
	ldr r0, [r5, #0x4c]
	cmp r0, r1
	beq _0223555A
	str r1, [r5, #0x4c]
	ldr r0, [r5, #8]
	cmp r0, #1
	bne _022354A6
	add r1, r5, #0
	add r1, #0x48
	ldrb r1, [r1]
	ldr r0, [r5, #0x10]
	bl FillWindowPixelBuffer
_022354A6:
	mov r0, #0
	ldr r1, [r5, #0x4c]
	mvn r0, r0
	cmp r1, r0
	beq _0223555A
	ldr r2, [r5, #0x34]
	ldr r3, [r4, #8]
	mov r0, #1
	mov r1, #0x1b
	bl NewMsgDataFromNarc
	ldr r6, [r5, #0x14]
	str r0, [sp, #0x10]
	cmp r6, #0
	bne _022354CC
	ldr r0, [r4, #8]
	bl MessageFormat_New
	add r6, r0, #0
_022354CC:
	ldr r1, [sp, #0x10]
	ldr r2, [r5, #0x4c]
	ldr r3, [r4, #8]
	add r0, r6, #0
	bl ReadMsgData_ExpandPlaceholders
	add r4, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _02235500
	ldr r0, [r5, #0x24]
	add r2, r4, #0
	str r0, [sp]
	ldr r0, [r5, #0x50]
	str r0, [sp, #4]
	ldr r0, [r5, #0x44]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x40]
	ldr r3, [r5, #0x20]
	bl AddTextPrinterParameterizedWithColor
	add r7, r0, #0
	b _02235542
_02235500:
	ldr r0, [r5, #0x40]
	mov r1, #2
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl GetFontAttribute
	add r2, r0, #0
	ldr r0, [r5, #0x40]
	add r1, r4, #0
	bl FontID_String_GetWidth
	add r7, r0, #0
	ldr r0, [r5, #0x10]
	bl GetWindowWidth
	lsl r0, r0, #3
	sub r3, r0, r7
	ldr r0, [r5, #0x24]
	add r2, r4, #0
	str r0, [sp]
	ldr r0, [r5, #0x50]
	str r0, [sp, #4]
	ldr r0, [r5, #0x44]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x40]
	bl AddTextPrinterParameterizedWithColor
	add r7, r0, #0
	mov r0, #0
	str r0, [r5, #0xc]
_02235542:
	add r0, r4, #0
	bl String_Delete
	ldr r0, [r5, #0x14]
	cmp r0, #0
	bne _02235554
	add r0, r6, #0
	bl MessageFormat_Delete
_02235554:
	ldr r0, [sp, #0x10]
	bl DestroyMsgData
_0223555A:
	mov r0, #0xff
	str r0, [r5, #0x50]
	add r0, r7, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02235564: .word ov74_0223D454
	thumb_func_end ov74_0223547C


	thumb_func_start ov74_02235568
ov74_02235568: ; 0x02235568
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r4, r1, #0
	ldr r1, [r4, #0x10]
	add r6, r2, #0
	ldr r2, [r1]
	add r5, r3, #0
	cmp r2, #0
	bne _022355BA
	lsl r2, r5, #0x18
	lsr r2, r2, #0x18
	str r2, [sp]
	ldr r2, [r4, #0x18]
	lsl r3, r6, #0x18
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	str r2, [sp, #4]
	ldr r2, [r4, #0x1c]
	lsr r3, r3, #0x18
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	str r2, [sp, #8]
	ldr r2, [r4, #0x30]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	str r2, [sp, #0xc]
	ldr r2, [r4, #0x28]
	lsl r2, r2, #0x10
	lsr r2, r2, #0x10
	str r2, [sp, #0x10]
	ldr r2, [r4, #0x2c]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	bl AddWindowParameterized
	ldr r1, [sp, #0x28]
	add r0, r4, #0
	bl ov74_0223547C
	add r5, r0, #0
	b _022355E8
_022355BA:
	mov r0, #0
	mvn r0, r0
	cmp r6, r0
	beq _022355CC
	add r0, r1, #0
	lsl r1, r6, #0x18
	lsr r1, r1, #0x18
	bl SetWindowX
_022355CC:
	mov r0, #0
	mvn r0, r0
	cmp r5, r0
	beq _022355DE
	lsl r1, r5, #0x18
	ldr r0, [r4, #0x10]
	lsr r1, r1, #0x18
	bl SetWindowY
_022355DE:
	ldr r1, [sp, #0x28]
	add r0, r4, #0
	bl ov74_0223547C
	add r5, r0, #0
_022355E8:
	ldr r0, [r4, #4]
	cmp r0, #1
	bne _0223562E
	ldr r0, [r4]
	cmp r0, #0
	beq _022355FC
	cmp r0, #1
	beq _02235612
	cmp r0, #2
	b _02235628
_022355FC:
	ldr r2, [r4, #0x38]
	ldr r3, [r4, #0x3c]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [r4, #0x10]
	mov r1, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl DrawFrameAndWindow1
	b _0223562E
_02235612:
	ldr r2, [r4, #0x38]
	ldr r3, [r4, #0x3c]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [r4, #0x10]
	mov r1, #0
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl DrawFrameAndWindow2
	b _0223562E
_02235628:
	ldr r0, [r4, #0x10]
	bl CopyWindowToVram
_0223562E:
	add r0, r5, #0
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	thumb_func_end ov74_02235568


	thumb_func_start ov74_02235634
ov74_02235634: ; 0x02235634
	ldr r1, [r0, #0x18]
	ldr r0, [r0, #0x1c]
	mul r0, r1
	bx lr
	thumb_func_end ov74_02235634


	thumb_func_start ov74_0223563C
ov74_0223563C: ; 0x0223563C
	push {r4, lr}
	sub sp, #0x10
	ldr r4, _02235674 ; =_0223B710
	add r3, sp, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, _02235678 ; =ov74_0223D454
	mov r1, #0x10
	ldr r0, [r0, #8]
	str r0, [sp, #0xc]
	add r0, r2, #0
	add r2, r1, #0
	bl ObjCharTransfer_InitEx
	ldr r1, _02235678 ; =ov74_0223D454
	mov r0, #0x1e
	ldr r1, [r1, #8]
	bl ObjPlttTransfer_Init
	bl ObjCharTransfer_ClearBuffers
	bl ObjPlttTransfer_Reset
	add sp, #0x10
	pop {r4, pc}
	.balign 4, 0
_02235674: .word _0223B710
_02235678: .word ov74_0223D454
	thumb_func_end ov74_0223563C


	thumb_func_start ov74_0223567C
ov74_0223567C: ; 0x0223567C
	ldr r0, _0223568C ; =ov74_0223D454
	ldr r0, [r0, #0x34]
	cmp r0, #0
	beq _02235688
	mov r0, #1
	bx lr
_02235688:
	mov r0, #0
	bx lr
	.balign 4, 0
_0223568C: .word ov74_0223D454
	thumb_func_end ov74_0223567C


	thumb_func_start ov74_02235690
ov74_02235690: ; 0x02235690
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	ldr r6, _022356F8 ; =ov74_0223D454
	bl NNS_G2dInitOamManagerModule
	mov r0, #0
	str r0, [sp]
	mov r1, #0x7e
	str r1, [sp, #4]
	str r0, [sp, #8]
	mov r3, #0x20
	ldr r2, _022356FC ; =ov74_0223D454
	str r3, [sp, #0xc]
	ldr r2, [r2, #8]
	str r2, [sp, #0x10]
	add r2, r0, #0
	bl OamManager_Create
	ldr r2, _022356FC ; =ov74_0223D454
	ldr r1, _02235700 ; =ov74_0223D48C
	ldr r2, [r2, #8]
	mov r0, #0x80
	bl G2dRenderer_Init
	ldr r1, _022356FC ; =ov74_0223D454
	mov r2, #1
	str r0, [r1, #0x34]
	ldr r0, _02235700 ; =ov74_0223D48C
	mov r1, #0
	lsl r2, r2, #0x14
	bl G2dRenderer_SetSubSurfaceCoords
	mov r1, #3
	mov r7, #0x16
	ldr r0, _02235704 ; =ov74_0223D654
	lsl r1, r1, #0x12
	str r1, [r0, #0x10]
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #4
_022356E0:
	ldr r2, [r6, #8]
	mov r0, #0x20
	add r1, r4, #0
	bl Create2DGfxResObjMan
	str r0, [r5, r7]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blt _022356E0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_022356F8: .word ov74_0223D454
_022356FC: .word ov74_0223D454
_02235700: .word ov74_0223D48C
_02235704: .word ov74_0223D654
	thumb_func_end ov74_02235690


	thumb_func_start ov74_02235708
ov74_02235708: ; 0x02235708
	push {r4, lr}
	ldr r0, _02235720 ; =ov74_0223D454
	ldr r4, _02235724 ; =ov74_0223D454
	ldr r0, [r0, #0x34]
	cmp r0, #0
	bne _02235718
	bl GF_AssertFail
_02235718:
	add r4, #0x34
	add r0, r4, #0
	pop {r4, pc}
	nop
_02235720: .word ov74_0223D454
_02235724: .word ov74_0223D454
	thumb_func_end ov74_02235708


	thumb_func_start ov74_02235728
ov74_02235728: ; 0x02235728
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x38
	ldr r4, [sp, #0x54]
	add r6, r0, #0
	mov ip, r1
	str r2, [sp, #0x2c]
	str r3, [sp, #0x30]
	ldr r5, _02235894 ; =ov74_0223D454
	cmp r4, #0
	bne _02235740
	mov r7, #1
	b _02235742
_02235740:
	mov r7, #2
_02235742:
	mov r0, #1
	str r0, [sp, #0x34]
	cmp r6, #0x12
	bne _0223574E
	mov r0, #0
	str r0, [sp, #0x34]
_0223574E:
	mov r1, #0
	mvn r1, r1
	mov r0, ip
	cmp r0, r1
	beq _0223577C
	str r4, [sp]
	str r7, [sp, #4]
	ldr r0, [r5, #8]
	ldr r3, [sp, #0x34]
	str r0, [sp, #8]
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r6, #0
	mov r2, ip
	bl AddCharResObjFromNarc
	mov r1, #0x18
	mul r1, r4
	add r2, r5, r1
	mov r1, #0x5e
	lsl r1, r1, #2
	str r0, [r2, r1]
_0223577C:
	mov r1, #0
	ldr r0, [sp, #0x2c]
	mvn r1, r1
	cmp r0, r1
	beq _022357AE
	str r4, [sp]
	str r7, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	ldr r0, [r5, #8]
	ldr r2, [sp, #0x2c]
	str r0, [sp, #0xc]
	mov r0, #0x59
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	mov r3, #0
	bl AddPlttResObjFromNarc
	mov r1, #0x18
	mul r1, r4
	add r2, r5, r1
	mov r1, #0x5f
	lsl r1, r1, #2
	str r0, [r2, r1]
_022357AE:
	mov r1, #0
	ldr r0, [sp, #0x30]
	mvn r1, r1
	cmp r0, r1
	beq _022357DE
	str r4, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r2, [sp, #0x30]
	str r0, [sp, #8]
	mov r0, #0x5a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r3, [sp, #0x34]
	add r1, r6, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x18
	add r2, r4, #0
	mul r2, r1
	add r2, r5, r2
	lsl r1, r1, #4
	str r0, [r2, r1]
_022357DE:
	mov r0, #0
	ldr r2, [sp, #0x50]
	mvn r0, r0
	cmp r2, r0
	beq _0223580C
	str r4, [sp]
	mov r0, #3
	str r0, [sp, #4]
	ldr r0, [r5, #8]
	ldr r3, [sp, #0x34]
	str r0, [sp, #8]
	mov r0, #0x5b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r6, #0
	bl AddCellOrAnimResObjFromNarc
	mov r1, #0x18
	mul r1, r4
	add r2, r5, r1
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r2, r1]
_0223580C:
	mov r0, #0x18
	add r6, r4, #0
	mul r6, r0
	mov r0, #0x5e
	add r1, r5, r6
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl SpriteTransfer_CreateCharTransferTask
	mov r0, #0x5f
	add r1, r5, r6
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl SpriteTransfer_CreatePlttTransferTask
	mov r0, #0
	mov r2, #0x16
	str r4, [sp]
	mvn r0, r0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	lsl r2, r2, #4
	ldr r1, [r5, r2]
	add r3, r4, #0
	str r1, [sp, #0x14]
	add r1, r2, #4
	ldr r1, [r5, r1]
	str r1, [sp, #0x18]
	add r1, r2, #0
	add r1, #8
	ldr r1, [r5, r1]
	str r1, [sp, #0x1c]
	add r1, r2, #0
	add r1, #0xc
	ldr r1, [r5, r1]
	add r2, #0x48
	str r1, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	mov r0, #0x24
	add r1, r5, r2
	mul r0, r4
	add r0, r1, r0
	add r1, r4, #0
	add r2, r4, #0
	bl CreateSpriteResourcesHeader
	cmp r4, #0
	bne _0223587E
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	b _02235886
_0223587E:
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
_02235886:
	ldr r0, _02235898 ; =ov74_02235A74
	mov r1, #0
	bl Main_SetVBlankIntrCB
	add sp, #0x38
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02235894: .word ov74_0223D454
_02235898: .word ov74_02235A74
	thumb_func_end ov74_02235728


	thumb_func_start ov74_0223589C
ov74_0223589C: ; 0x0223589C
	push {r4, lr}
	add r2, r0, #0
	add r4, r1, #0
	add r1, r2, #0
	ldr r0, _022358B4 ; =ov74_0223D48C
	add r2, r4, #0
	bl G2dRenderer_SetSubSurfaceCoords
	ldr r0, _022358B8 ; =ov74_0223D654
	str r4, [r0, #0x10]
	pop {r4, pc}
	nop
_022358B4: .word ov74_0223D48C
_022358B8: .word ov74_0223D654
	thumb_func_end ov74_0223589C


	thumb_func_start ov74_022358BC
ov74_022358BC: ; 0x022358BC
	ldr r3, _022358C4 ; =ov74_022358C8
	mov r0, #0
	bx r3
	nop
_022358C4: .word ov74_022358C8
	thumb_func_end ov74_022358BC


	thumb_func_start ov74_022358C8
ov74_022358C8: ; 0x022358C8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _02235928 ; =ov74_0223D654
	ldr r4, _0223592C ; =ov74_0223D454
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _0223591C
	mov r0, #0x83
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	cmp r1, #0
	bne _02235918
	sub r0, r0, #4
	ldr r0, [r4, r0]
	bl Sprite_GetDrawFlag
	cmp r0, #0
	bne _022358FC
	cmp r5, #0
	bne _022358FC
	mov r0, #0x82
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
_022358FC:
	mov r0, #0x82
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_GetMatrixPtr
	mov r1, #6
	ldr r2, [r0, #4]
	lsl r1, r1, #0x12
	cmp r2, r1
	bge _0223591C
	lsr r1, r1, #7
	add r1, r2, r1
	str r1, [r0, #4]
	b _0223591C
_02235918:
	sub r1, r1, #1
	str r1, [r4, r0]
_0223591C:
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _02235926
	bl SpriteList_RenderAndAnimateSprites
_02235926:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02235928: .word ov74_0223D654
_0223592C: .word ov74_0223D454
	thumb_func_end ov74_022358C8


	thumb_func_start ov74_02235930
ov74_02235930: ; 0x02235930
	push {r3, r4, r5, lr}
	sub sp, #0x30
	add r4, r1, #0
	ldr r1, _022359B8 ; =ov74_0223D454
	bne _02235992
	ldr r4, [r1, #0x34]
	lsl r2, r2, #0xc
	str r4, [sp]
	mov r4, #0x6a
	lsl r4, r4, #2
	add r5, r1, r4
	mov r4, #0x24
	mul r4, r0
	add r4, r5, r4
	str r4, [sp, #4]
	mov r4, #1
	lsl r4, r4, #0xc
	mov r5, #0
	str r5, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	add r4, sp, #0
	strh r5, [r4, #0x20]
	str r2, [sp, #8]
	lsl r2, r3, #0xc
	str r2, [sp, #0xc]
	mov r2, #0xa
	str r2, [sp, #0x24]
	cmp r0, #0
	bne _02235972
	mov r2, #1
	b _02235974
_02235972:
	mov r2, #2
_02235974:
	ldr r0, [r1, #8]
	str r2, [sp, #0x28]
	str r0, [sp, #0x2c]
	cmp r2, #2
	bne _0223598A
	mov r0, #0x21
	lsl r0, r0, #4
	ldr r2, [sp, #0xc]
	ldr r0, [r1, r0]
	add r0, r2, r0
	str r0, [sp, #0xc]
_0223598A:
	add r0, sp, #0
	bl Sprite_CreateAffine
	add r4, r0, #0
_02235992:
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetAnimActiveFlag
	add r0, r4, #0
	mov r1, #0
	bl Sprite_SetPriority
	ldr r1, [sp, #0x40]
	add r0, r4, #0
	bl Sprite_SetAnimCtrlSeq
	add r0, r4, #0
	mov r1, #1
	bl Sprite_SetDrawFlag
	add r0, r4, #0
	add sp, #0x30
	pop {r3, r4, r5, pc}
	.balign 4, 0
_022359B8: .word ov74_0223D454
	thumb_func_end ov74_02235930


	thumb_func_start ov74_022359BC
ov74_022359BC: ; 0x022359BC
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _02235A5C ; =ov74_0223D654
	ldr r4, _02235A60 ; =ov74_0223D454
	ldr r0, [r0, #8]
	cmp r0, #0
	beq _022359DA
	mov r0, #0x82
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Sprite_Delete
	mov r0, #0x82
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r4, r0]
_022359DA:
	mov r1, #0x51
	ldr r0, _02235A64 ; =ov74_0223D488
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _022359EA
	bl SpriteTransfer_DeleteCharTransferTask
_022359EA:
	mov r1, #0x57
	ldr r0, _02235A64 ; =ov74_0223D488
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _022359FA
	bl SpriteTransfer_DeleteCharTransferTask
_022359FA:
	mov r1, #0x52
	ldr r0, _02235A64 ; =ov74_0223D488
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _02235A0A
	bl SpriteTransfer_DeletePlttTransferTask
_02235A0A:
	mov r1, #0x16
	ldr r0, _02235A64 ; =ov74_0223D488
	lsl r1, r1, #4
	ldr r0, [r0, r1]
	cmp r0, #0
	beq _02235A1A
	bl SpriteTransfer_DeletePlttTransferTask
_02235A1A:
	mov r4, #0
	mov r7, #0x4b
	ldr r5, _02235A64 ; =ov74_0223D488
	add r6, r4, #0
	lsl r7, r7, #2
_02235A24:
	mov r0, #0x4b
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Destroy2DGfxResObjMan
	str r6, [r5, r7]
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #6
	blt _02235A24
	ldr r0, _02235A64 ; =ov74_0223D488
	ldr r0, [r0]
	bl SpriteList_Delete
	ldr r0, _02235A64 ; =ov74_0223D488
	mov r1, #0
	str r1, [r0]
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02235A5C: .word ov74_0223D654
_02235A60: .word ov74_0223D454
_02235A64: .word ov74_0223D488
	thumb_func_end ov74_022359BC


	thumb_func_start ov74_02235A68
ov74_02235A68: ; 0x02235A68
	mov r1, #1
	sub r0, #0xa
	lsl r1, r0
	add r0, r1, #0
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02235A68


	thumb_func_start ov74_02235A74
ov74_02235A74: ; 0x02235A74
	push {r4, lr}
	ldr r0, _02235AB0 ; =ov74_0223E2D4
	ldr r4, _02235AB4 ; =ov74_0223D454
	ldr r0, [r0, #0x24]
	cmp r0, #0
	beq _02235A8E
	ldr r1, _02235AB8 ; =0x00000EA4
	add r0, r4, #0
	ldr r1, [r4, r1]
	blx r1
	ldr r0, _02235AB8 ; =0x00000EA4
	mov r1, #0
	str r1, [r4, r0]
_02235A8E:
	bl GF_RunVramTransferTasks
	bl OamManager_ApplyAndResetBuffers
	ldr r0, [r4]
	cmp r0, #0
	beq _02235AA0
	bl DoScheduledBgGpuUpdates
_02235AA0:
	ldr r3, _02235ABC ; =0x027E0000
	ldr r1, _02235AC0 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	nop
_02235AB0: .word ov74_0223E2D4
_02235AB4: .word ov74_0223D454
_02235AB8: .word 0x00000EA4
_02235ABC: .word 0x027E0000
_02235AC0: .word 0x00003FF8
	thumb_func_end ov74_02235A74


	thumb_func_start ov74_02235AC4
ov74_02235AC4: ; 0x02235AC4
	push {r4}
	sub sp, #0x24
	ldr r4, _02235B10 ; =_0223B73C
	add r3, sp, #0
	mov r2, #0x22
_02235ACE:
	ldrb r1, [r4]
	add r4, r4, #1
	strb r1, [r3]
	add r3, r3, #1
	sub r2, r2, #1
	bne _02235ACE
	add r1, sp, #0
	ldrb r2, [r1]
	mov r3, #0
	sub r1, r3, #1
	cmp r2, r1
	beq _02235B08
	add r4, sp, #0
	sub r1, r3, #1
_02235AEA:
	ldrb r2, [r4]
	cmp r0, r2
	bne _02235AFE
	add r0, sp, #0
	lsl r1, r3, #1
	add r0, #1
	add sp, #0x24
	ldrb r0, [r0, r1]
	pop {r4}
	bx lr
_02235AFE:
	add r4, r4, #2
	ldrb r2, [r4]
	add r3, r3, #1
	cmp r2, r1
	bne _02235AEA
_02235B08:
	mov r0, #0
	add sp, #0x24
	pop {r4}
	bx lr
	.balign 4, 0
_02235B10: .word _0223B73C
	thumb_func_end ov74_02235AC4


	thumb_func_start ov74_02235B14
ov74_02235B14: ; 0x02235B14
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r6, r1, #0
	str r0, [sp, #0x20]
	add r0, r6, #0
	add r5, r2, #0
	add r7, r3, #0
	ldr r4, [sp, #0x44]
	bl GetMonGender
	str r0, [sp, #0x24]
	add r0, r6, #0
	bl MonIsShiny
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	lsl r0, r7, #0x18
	ldr r2, [sp, #0x24]
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #0
	lsl r1, r5, #0x10
	lsl r2, r2, #0x18
	str r0, [sp, #8]
	add r0, r4, #0
	lsr r1, r1, #0x10
	lsr r2, r2, #0x18
	mov r3, #2
	bl GetMonSpriteCharAndPlttNarcIdsEx
	mov r1, #0
	add r0, r6, #0
	add r2, r1, #0
	bl GetMonData
	mov r3, #0
	str r3, [sp]
	mov r1, #0xa
	str r1, [sp, #4]
	str r1, [sp, #8]
	ldr r1, [sp, #0x40]
	ldr r2, _02235BCC ; =ov74_0223D454
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r3, [sp, #0x14]
	mov r0, #2
	str r0, [sp, #0x18]
	str r5, [sp, #0x1c]
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	ldr r2, [r2, #8]
	bl sub_02014494
	mov r1, #0x32
	ldr r0, [sp, #0x40]
	lsl r1, r1, #6
	bl DC_FlushRange
	ldr r0, [sp, #0x20]
	bl Sprite_GetImageProxy
	mov r1, #2
	bl NNS_G2dGetImageLocation
	mov r2, #0x32
	add r1, r0, #0
	lsl r2, r2, #6
	ldr r0, [sp, #0x40]
	add r1, r1, r2
	bl GXS_LoadOBJ
	ldr r0, [sp, #0x20]
	bl Sprite_GetPaletteProxy
	mov r1, #2
	bl NNS_G2dGetImagePaletteLocation
	add r3, r0, #0
	mov r0, #0x20
	str r0, [sp]
	ldr r0, _02235BCC ; =ov74_0223D454
	mov r2, #5
	ldr r0, [r0, #8]
	add r3, #0x60
	str r0, [sp, #4]
	ldrh r0, [r4]
	ldrh r1, [r4, #4]
	bl GfGfxLoader_GXLoadPal
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02235BCC: .word ov74_0223D454
	thumb_func_end ov74_02235B14


	thumb_func_start ov74_02235BD0
ov74_02235BD0: ; 0x02235BD0
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	mov r0, #0x25
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0x27
	mov r2, #0x24
	mov r3, #0x26
	bl ov74_02235728
	mov r1, #1
	mov r0, #0
	lsl r1, r1, #0x14
	bl ov74_0223589C
	mov r3, #0
	mov r1, #0x82
	str r3, [sp]
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	mov r0, #1
	mov r2, #0x80
	bl ov74_02235930
	mov r1, #0x82
	lsl r1, r1, #2
	str r0, [r4, r1]
	add sp, #8
	pop {r4, pc}
	thumb_func_end ov74_02235BD0


	thumb_func_start ov74_02235C10
ov74_02235C10: ; 0x02235C10
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0xc
	str r0, [sp]
	mov r0, #1
	add r4, r1, #0
	add r6, r2, #0
	str r0, [sp, #4]
	mov r0, #0x34
	mov r1, #0xa
	mov r2, #0
	mov r3, #0xb
	bl ov74_02235728
	mov r1, #1
	mov r0, #0
	lsl r1, r1, #0x14
	bl ov74_0223589C
	mov r0, #1
	mov r1, #0x82
	str r0, [sp]
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r2, #0x80
	mov r3, #0
	bl ov74_02235930
	mov r2, #0x82
	lsl r2, r2, #2
	add r6, #8
	str r0, [r5, r2]
	cmp r4, #7
	bgt _02235C68
	cmp r4, #1
	blt _02235CDA
	beq _02235C6C
	cmp r4, #2
	beq _02235CA2
	cmp r4, #7
	beq _02235CC0
	add sp, #8
	pop {r4, r5, r6, pc}
_02235C68:
	cmp r4, #0xd
	bne _02235CDA
_02235C6C:
	add r0, r6, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	mov r1, #0x85
	lsl r1, r1, #2
	add r3, r0, #0
	add r0, r5, r1
	str r0, [sp]
	ldr r0, _02235CE0 ; =0x00000E94
	sub r1, #0xc
	add r0, r5, r0
	str r0, [sp, #4]
	ldr r0, [r5, r1]
	add r1, r6, #0
	add r2, r4, #0
	bl ov74_02235B14
	add sp, #8
	pop {r4, r5, r6, pc}
_02235CA2:
	add r0, r2, #0
	add r0, #0xc
	add r0, r5, r0
	str r0, [sp]
	ldr r0, _02235CE0 ; =0x00000E94
	add r1, r6, #0
	add r0, r5, r0
	str r0, [sp, #4]
	ldr r0, [r5, r2]
	sub r2, #0x1a
	mov r3, #0
	bl ov74_02235B14
	add sp, #8
	pop {r4, r5, r6, pc}
_02235CC0:
	add r0, r2, #0
	add r0, #0xc
	add r0, r5, r0
	str r0, [sp]
	ldr r0, _02235CE0 ; =0x00000E94
	add r1, r6, #0
	add r0, r5, r0
	str r0, [sp, #4]
	ldr r0, [r5, r2]
	sub r2, #0x1a
	mov r3, #1
	bl ov74_02235B14
_02235CDA:
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_02235CE0: .word 0x00000E94
	thumb_func_end ov74_02235C10


	thumb_func_start ov74_02235CE4
ov74_02235CE4: ; 0x02235CE4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	cmp r1, #0xf
	bhi _02235D36
	add r0, r1, r1
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02235CFA: ; jump table
	.short _02235D36 - _02235CFA - 2 ; case 0
	.short _02235D36 - _02235CFA - 2 ; case 1
	.short _02235D36 - _02235CFA - 2 ; case 2
	.short _02235D1A - _02235CFA - 2 ; case 3
	.short _02235D36 - _02235CFA - 2 ; case 4
	.short _02235D36 - _02235CFA - 2 ; case 5
	.short _02235D36 - _02235CFA - 2 ; case 6
	.short _02235D36 - _02235CFA - 2 ; case 7
	.short _02235D1E - _02235CFA - 2 ; case 8
	.short _02235D22 - _02235CFA - 2 ; case 9
	.short _02235D28 - _02235CFA - 2 ; case 10
	.short _02235D36 - _02235CFA - 2 ; case 11
	.short _02235D2C - _02235CFA - 2 ; case 12
	.short _02235D36 - _02235CFA - 2 ; case 13
	.short _02235D30 - _02235CFA - 2 ; case 14
	.short _02235D34 - _02235CFA - 2 ; case 15
_02235D1A:
	ldr r4, [r2, #4]
	b _02235D36
_02235D1E:
	ldr r4, _02235D90 ; =0x000001C6
	b _02235D36
_02235D22:
	mov r4, #0x71
	lsl r4, r4, #2
	b _02235D36
_02235D28:
	ldr r4, _02235D94 ; =0x000001C7
	b _02235D36
_02235D2C:
	ldr r4, _02235D98 ; =0x000001D3
	b _02235D36
_02235D30:
	ldr r4, _02235D9C ; =0x000001BA
	b _02235D36
_02235D34:
	ldr r4, _02235DA0 ; =0x000001F5
_02235D36:
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	mov r1, #1
	bl GetItemIndexMapping
	add r7, r0, #0
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	mov r1, #2
	bl GetItemIndexMapping
	add r4, r0, #0
	bl GetItemIconCell
	add r6, r0, #0
	bl GetItemIconAnim
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x12
	add r1, r7, #0
	add r2, r4, #0
	add r3, r6, #0
	bl ov74_02235728
	mov r1, #1
	mov r0, #0
	lsl r1, r1, #0x14
	bl ov74_0223589C
	mov r3, #0
	mov r1, #0x82
	str r3, [sp]
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	mov r0, #1
	mov r2, #0x80
	bl ov74_02235930
	mov r1, #0x82
	lsl r1, r1, #2
	str r0, [r5, r1]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02235D90: .word 0x000001C6
_02235D94: .word 0x000001C7
_02235D98: .word 0x000001D3
_02235D9C: .word 0x000001BA
_02235DA0: .word 0x000001F5
	thumb_func_end ov74_02235CE4


	thumb_func_start ov74_02235DA4
ov74_02235DA4: ; 0x02235DA4
	push {r3, lr}
	sub sp, #8
	mov r1, #0xc0
	str r1, [sp]
	ldr r0, [r0, #8]
	mov r2, #4
	add r3, r2, #0
	str r0, [sp, #4]
	mov r0, #0x71
	mov r1, #0x21
	add r3, #0xfc
	bl GfGfxLoader_GXLoadPal
	add sp, #8
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_02235DA4


	thumb_func_start ov74_02235DC4
ov74_02235DC4: ; 0x02235DC4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r6, r1, #0
	ldrh r4, [r6]
	add r5, r0, #0
	add r0, r4, #0
	bl ov74_02235AC4
	add r7, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #5
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _02235EC0 ; =ov74_0223D454
	mov r1, #0x22
	ldr r0, [r0, #8]
	add r2, r5, #0
	str r0, [sp, #0xc]
	mov r0, #0x71
	mov r3, #5
	bl GfGfxLoader_LoadCharData
	mov r2, #1
	ldr r3, _02235EC0 ; =ov74_0223D454
	str r2, [sp]
	ldr r3, [r3, #8]
	mov r0, #0x71
	mov r1, #0x23
	bl GfGfxLoader_LoadFromNarc
	add r1, sp, #0x14
	str r0, [sp, #0x10]
	bl NNS_G2dGetUnpackedScreenData
	ldr r2, [sp, #0x14]
	mov r3, #6
	add r0, r5, #0
	mov r1, #5
	add r2, #0xc
	lsl r3, r3, #8
	bl BG_LoadScreenTilemapData
	ldr r0, [sp, #0x10]
	bl Heap_Free
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	mov r2, #0
	add r7, #8
	str r0, [sp, #4]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #5
	add r3, r2, #0
	bl BgTilemapRectChangePalette
	add r0, r5, #0
	mov r1, #5
	bl ScheduleBgTilemapBufferTransfer
	ldr r1, _02235EC4 ; =ov74_02235DA4
	ldr r0, _02235EC8 ; =ov74_0223E2D4
	cmp r4, #0xf
	str r1, [r0, #0x24]
	ldr r0, _02235EC0 ; =ov74_0223D454
	str r5, [r0]
	bhi _02235EAE
	add r0, r4, r4
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02235E62: ; jump table
	.short _02235EAE - _02235E62 - 2 ; case 0
	.short _02235E98 - _02235E62 - 2 ; case 1
	.short _02235E98 - _02235E62 - 2 ; case 2
	.short _02235EA4 - _02235E62 - 2 ; case 3
	.short _02235E82 - _02235E62 - 2 ; case 4
	.short _02235E82 - _02235E62 - 2 ; case 5
	.short _02235E82 - _02235E62 - 2 ; case 6
	.short _02235E8E - _02235E62 - 2 ; case 7
	.short _02235EA4 - _02235E62 - 2 ; case 8
	.short _02235EA4 - _02235E62 - 2 ; case 9
	.short _02235EA4 - _02235E62 - 2 ; case 10
	.short _02235E82 - _02235E62 - 2 ; case 11
	.short _02235EA4 - _02235E62 - 2 ; case 12
	.short _02235E98 - _02235E62 - 2 ; case 13
	.short _02235EA4 - _02235E62 - 2 ; case 14
	.short _02235EA4 - _02235E62 - 2 ; case 15
_02235E82:
	ldr r0, _02235ECC ; =ov74_0223D454
	add r1, r4, #0
	add r2, r6, #0
	bl ov74_02235BD0
	b _02235EAE
_02235E8E:
	mov r1, #0x83
	ldr r0, _02235ECC ; =ov74_0223D454
	mov r2, #0x78
	lsl r1, r1, #2
	str r2, [r0, r1]
_02235E98:
	ldr r0, _02235ECC ; =ov74_0223D454
	add r1, r4, #0
	add r2, r6, #0
	bl ov74_02235C10
	b _02235EAE
_02235EA4:
	ldr r0, _02235ECC ; =ov74_0223D454
	add r1, r4, #0
	add r2, r6, #0
	bl ov74_02235CE4
_02235EAE:
	mov r1, #0x82
	ldr r0, _02235ECC ; =ov74_0223D454
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02235EC0: .word ov74_0223D454
_02235EC4: .word ov74_02235DA4
_02235EC8: .word ov74_0223E2D4
_02235ECC: .word ov74_0223D454
	thumb_func_end ov74_02235DC4


	thumb_func_start ov74_02235ED0
ov74_02235ED0: ; 0x02235ED0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r1, #0
	mov r1, #2
	add r5, r0, #0
	add r0, r2, #0
	lsl r1, r1, #8
	str r2, [sp]
	bl Heap_Alloc
	ldr r1, _02235F50 ; =0x0000A001
	add r4, r0, #0
	bl MATHi_CRC16InitTableRev
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x50
	bl MATH_CalcCRC16
	add r6, r0, #0
	add r0, r4, #0
	bl Heap_Free
	add r0, sp, #4
	bl OS_GetMacAddress
	add r0, sp, #4
	ldrh r1, [r0, #2]
	mov r2, #0
	add r3, sp, #4
	strh r1, [r0, #6]
	ldr r1, _02235F54 ; =0x0000D679
	strh r6, [r0, #2]
_02235F12:
	ldrh r0, [r3]
	add r2, r2, #1
	eor r0, r1
	strh r0, [r3]
	ldrh r1, [r3]
	add r3, r3, #2
	cmp r2, #4
	blt _02235F12
	mov r1, #0x41
	ldr r0, [sp]
	lsl r1, r1, #2
	bl Heap_Alloc
	add r1, sp, #4
	mov r2, #8
	add r4, r0, #0
	bl CRYPTO_RC4Init
	add r5, #0x50
	mov r2, #0xd6
	add r0, r4, #0
	add r1, r5, #0
	lsl r2, r2, #2
	add r3, r7, #0
	bl CRYPTO_RC4Encrypt
	add r0, r4, #0
	bl Heap_Free
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02235F50: .word 0x0000A001
_02235F54: .word 0x0000D679
	thumb_func_end ov74_02235ED0


	thumb_func_start ov74_02235F58
ov74_02235F58: ; 0x02235F58
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r1, #0
	mov r1, #2
	add r5, r0, #0
	add r0, r2, #0
	lsl r1, r1, #8
	str r2, [sp]
	bl Heap_Alloc
	ldr r1, _02235FF0 ; =0x0000A001
	add r4, r0, #0
	bl MATHi_CRC16InitTableRev
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0x50
	bl MATH_CalcCRC16
	add r6, r0, #0
	add r0, r4, #0
	bl Heap_Free
	mov r0, #0
	bl sub_02035754
	ldrb r2, [r0, #4]
	add r1, sp, #4
	mov r3, #0
	strb r2, [r1]
	ldrb r2, [r0, #5]
	strb r2, [r1, #1]
	ldrb r2, [r0, #6]
	strb r2, [r1, #2]
	ldrb r2, [r0, #7]
	strb r2, [r1, #3]
	ldrb r2, [r0, #8]
	strb r2, [r1, #4]
	ldrb r0, [r0, #9]
	strb r0, [r1, #5]
	add r0, sp, #4
	ldrh r2, [r0, #2]
	strh r2, [r0, #6]
	ldr r2, _02235FF4 ; =0x0000D679
	strh r6, [r0, #2]
_02235FB2:
	ldrh r0, [r1]
	add r3, r3, #1
	eor r0, r2
	strh r0, [r1]
	ldrh r2, [r1]
	add r1, r1, #2
	cmp r3, #4
	blt _02235FB2
	mov r1, #0x41
	ldr r0, [sp]
	lsl r1, r1, #2
	bl Heap_Alloc
	add r1, sp, #4
	mov r2, #8
	add r4, r0, #0
	bl CRYPTO_RC4Init
	add r5, #0x50
	mov r2, #0xd6
	add r0, r4, #0
	add r1, r5, #0
	lsl r2, r2, #2
	add r3, r7, #0
	bl CRYPTO_RC4Encrypt
	add r0, r4, #0
	bl Heap_Free
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02235FF0: .word 0x0000A001
_02235FF4: .word 0x0000D679
	thumb_func_end ov74_02235F58


	thumb_func_start ov74_02235FF8
ov74_02235FF8: ; 0x02235FF8
	push {r3, lr}
	cmp r2, #0
	beq _02236002
	cmp r2, #1
	pop {r3, pc}
_02236002:
	ldr r0, _0223600C ; =SEQ_SE_DP_SELECT
	bl PlaySE
	pop {r3, pc}
	nop
_0223600C: .word SEQ_SE_DP_SELECT
	thumb_func_end ov74_02235FF8


	thumb_func_start ov74_02236010
ov74_02236010: ; 0x02236010
	push {r3, lr}
	ldr r0, _02236030 ; =0x027FFFA8
	ldrh r1, [r0]
	mov r0, #2
	lsl r0, r0, #0xe
	and r0, r1
	asr r0, r0, #0xf
	bne _0223602C
	bl CTRDG_IsAgbCartridge
	cmp r0, #0
	bne _0223602C
	bl CTRDG_TerminateForPulledOut
_0223602C:
	pop {r3, pc}
	nop
_02236030: .word 0x027FFFA8
	thumb_func_end ov74_02236010


	thumb_func_start ov74_02236034
ov74_02236034: ; 0x02236034
	push {r3, lr}
	cmp r0, #1
	bne _0223605C
	ldr r1, _02236068 ; =0x04000208
	ldrh r0, [r1]
	mov r0, #0
	strh r0, [r1]
	lsr r0, r1, #0xd
	ldr r1, _0223606C ; =ov74_02236010
	bl OS_SetIrqFunction
	mov r0, #2
	lsl r0, r0, #0xc
	bl OS_EnableIrqMask
	ldr r1, _02236068 ; =0x04000208
	ldrh r0, [r1]
	mov r0, #1
	strh r0, [r1]
	pop {r3, pc}
_0223605C:
	mov r0, #2
	lsl r0, r0, #0xc
	bl OS_DisableIrqMask
	pop {r3, pc}
	nop
_02236068: .word 0x04000208
_0223606C: .word ov74_02236010
	thumb_func_end ov74_02236034


	thumb_func_start ov74_02236070
ov74_02236070: ; 0x02236070
	bx lr
	.balign 4, 0
	thumb_func_end ov74_02236070


	thumb_func_start ov74_02236074
ov74_02236074: ; 0x02236074
	push {r3, lr}
	ldr r1, _02236098 ; =0x04000208
	ldrh r0, [r1]
	mov r0, #0
	strh r0, [r1]
	lsr r0, r1, #0xd
	ldr r1, _0223609C ; =ov74_02236070
	bl OS_SetIrqFunction
	mov r0, #2
	lsl r0, r0, #0xc
	bl OS_EnableIrqMask
	ldr r1, _02236098 ; =0x04000208
	ldrh r0, [r1]
	mov r0, #1
	strh r0, [r1]
	pop {r3, pc}
	.balign 4, 0
_02236098: .word 0x04000208
_0223609C: .word ov74_02236070
	thumb_func_end ov74_02236074


	thumb_func_start ov74_022360A0
ov74_022360A0: ; 0x022360A0
	ldr r1, _022360AC ; =ov74_0223D454
	str r0, [r1, #0x18]
	mov r0, #0
	str r0, [r1, #0x14]
	bx lr
	nop
_022360AC: .word ov74_0223D454
	thumb_func_end ov74_022360A0


	thumb_func_start ov74_022360B0
ov74_022360B0: ; 0x022360B0
	push {r3, r4, r5, lr}
	ldr r0, _02236120 ; =ov74_0223D454
	ldr r4, _02236124 ; =ov74_0223D454
	ldr r0, [r0, #0x14]
	cmp r0, #4
	bhi _0223611C
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_022360C8: ; jump table
	.short _022360D2 - _022360C8 - 2 ; case 0
	.short _022360E8 - _022360C8 - 2 ; case 1
	.short _0223611C - _022360C8 - 2 ; case 2
	.short _0223611C - _022360C8 - 2 ; case 3
	.short _0223611C - _022360C8 - 2 ; case 4
_022360D2:
	mov r0, #4
	bl sub_0201A728
	ldr r0, [r4, #0x18]
	mov r1, #2
	bl Save_PrepareForAsyncWrite
	ldr r0, [r4, #0x14]
	add r0, r0, #1
	str r0, [r4, #0x14]
	b _0223611C
_022360E8:
	ldr r0, [r4, #0x18]
	bl Save_WriteFileAsync
	add r5, r0, #0
	cmp r5, #3
	bne _022360FA
	mov r0, #3
	str r0, [r4, #0x14]
	b _0223610C
_022360FA:
	cmp r5, #2
	bne _02236104
	mov r0, #2
	str r0, [r4, #0x14]
	b _0223610C
_02236104:
	cmp r5, #1
	bne _0223610C
	mov r0, #4
	str r0, [r4, #0x14]
_0223610C:
	sub r0, r5, #2
	cmp r0, #1
	bhi _02236118
	mov r0, #4
	bl sub_0201A738
_02236118:
	add r0, r5, #0
	pop {r3, r4, r5, pc}
_0223611C:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02236120: .word ov74_0223D454
_02236124: .word ov74_0223D454
	thumb_func_end ov74_022360B0


	thumb_func_start ov74_02236128
ov74_02236128: ; 0x02236128
	ldr r0, _02236138 ; =ov74_0223D454
	ldr r1, _0223613C ; =ov74_0223D454
	ldr r0, [r0, #0x14]
	cmp r0, #4
	bne _02236136
	mov r0, #1
	str r0, [r1, #0x14]
_02236136:
	bx lr
	.balign 4, 0
_02236138: .word ov74_0223D454
_0223613C: .word ov74_0223D454
	thumb_func_end ov74_02236128


	thumb_func_start ov74_02236140
ov74_02236140: ; 0x02236140
	push {r3, lr}
	ldr r0, _02236158 ; =ov74_0223D454
	ldr r0, [r0, #0x18]
	bl Save_Cancel
	ldr r0, _02236158 ; =ov74_0223D454
	mov r1, #3
	str r1, [r0, #0x14]
	mov r0, #4
	bl sub_0201A738
	pop {r3, pc}
	.balign 4, 0
_02236158: .word ov74_0223D454
	thumb_func_end ov74_02236140


	thumb_func_start ov74_0223615C
ov74_0223615C: ; 0x0223615C
	ldr r0, _02236164 ; =ov74_0223D454
	ldr r0, [r0, #0x14]
	bx lr
	nop
_02236164: .word ov74_0223D454
	thumb_func_end ov74_0223615C


	thumb_func_start ov74_02236168
ov74_02236168: ; 0x02236168
	push {r4, lr}
	ldr r1, _022361A4 ; =ov74_0223E2FC
	add r4, r0, #0
	ldr r2, [r1, #4]
	cmp r2, #0
	beq _02236184
	ldr r3, [r1]
	ldr r1, _022361A8 ; =0x00001150
	ldr r0, _022361AC ; =ov74_0223D00C
	ldr r1, [r3, r1]
	lsl r3, r1, #2
	ldr r1, _022361B0 ; =ov74_0223CFE4
	ldr r1, [r1, r3]
	blx r2
_02236184:
	ldr r3, _022361A4 ; =ov74_0223E2FC
	ldr r1, _022361A8 ; =0x00001150
	ldr r0, [r3]
	str r4, [r0, r1]
	ldr r2, [r3, #4]
	cmp r2, #0
	beq _022361A0
	ldr r3, [r3]
	ldr r0, _022361B4 ; =ov74_0223D014
	ldr r1, [r3, r1]
	lsl r3, r1, #2
	ldr r1, _022361B0 ; =ov74_0223CFE4
	ldr r1, [r1, r3]
	blx r2
_022361A0:
	pop {r4, pc}
	nop
_022361A4: .word ov74_0223E2FC
_022361A8: .word 0x00001150
_022361AC: .word ov74_0223D00C
_022361B0: .word ov74_0223CFE4
_022361B4: .word ov74_0223D014
	thumb_func_end ov74_02236168


	thumb_func_start ov74_022361B8
ov74_022361B8: ; 0x022361B8
	ldr r1, _022361CC ; =ov74_0223E2FC
	ldr r3, [r1]
	ldr r1, _022361D0 ; =0x00001150
	ldr r2, [r3, r1]
	sub r2, #9
	cmp r2, #1
	bls _022361CA
	add r1, r1, #4
	str r0, [r3, r1]
_022361CA:
	bx lr
	.balign 4, 0
_022361CC: .word ov74_0223E2FC
_022361D0: .word 0x00001150
	thumb_func_end ov74_022361B8


	thumb_func_start ov74_022361D4
ov74_022361D4: ; 0x022361D4
	push {r4, lr}
	ldr r0, _02236240 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _02236244 ; =0x00001150
	ldr r0, [r1, r0]
	cmp r0, #4
	bne _022361E6
	bl OS_Terminate
_022361E6:
	mov r0, #2
	bl ov74_02236168
	ldr r3, _02236240 ; =ov74_0223E2FC
	ldr r0, _02236248 ; =0x0000FFFF
	ldr r2, [r3]
	ldr r1, _0223624C ; =0x00000FCC
	strh r0, [r2, r1]
	sub r2, r1, #2
	ldr r4, [r3]
	sub r1, r1, #4
	strh r0, [r4, r2]
	ldr r2, [r3]
	strh r0, [r2, r1]
	bl ov74_02236258
	cmp r0, #0
	bne _02236224
	mov r0, #9
	bl ov74_02236168
	ldr r0, _02236240 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _02236250 ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _02236220
	mov r0, #4
	blx r1
_02236220:
	mov r0, #0
	pop {r4, pc}
_02236224:
	ldr r1, _02236240 ; =ov74_0223E2FC
	ldr r0, _02236254 ; =0x00001158
	ldr r2, [r1]
	mov r3, #2
	strh r3, [r2, r0]
	ldr r1, [r1]
	add r0, #0x24
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _0223623C
	mov r0, #0
	blx r1
_0223623C:
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
_02236240: .word ov74_0223E2FC
_02236244: .word 0x00001150
_02236248: .word 0x0000FFFF
_0223624C: .word 0x00000FCC
_02236250: .word 0x0000117C
_02236254: .word 0x00001158
	thumb_func_end ov74_022361D4


	thumb_func_start ov74_02236258
ov74_02236258: ; 0x02236258
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _02236330 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _02236334 ; =0x00001150
	ldr r0, [r1, r0]
	cmp r0, #2
	beq _0223626C
	bl OS_Terminate
	mov r0, #0
_0223626C:
	bl WM_GetAllowedChannel
	add r4, r0, #0
	mov r0, #2
	lsl r0, r0, #0xe
	cmp r4, r0
	bne _02236284
	mov r0, #3
	bl ov74_022361B8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02236284:
	cmp r4, #0
	bne _02236292
	mov r0, #0x16
	bl ov74_022361B8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02236292:
	ldr r0, _02236330 ; =ov74_0223E2FC
	ldr r2, [r0]
	ldr r0, _02236338 ; =0x00001176
	ldrh r1, [r2, r0]
	cmp r1, #0x10
	blo _022362D4
	sub r1, #0x10
	mov r5, #0
	mov r7, #0xd
	mov r6, #1
	b _022362BA
_022362A8:
	add r0, r1, #1
	add r1, r7, #0
	bl _s32_div_f
	add r0, r6, #0
	lsl r0, r1
	tst r0, r4
	bne _022362BE
	add r5, r5, #1
_022362BA:
	cmp r5, #0xd
	blt _022362A8
_022362BE:
	ldr r2, _02236330 ; =ov74_0223E2FC
	add r4, r1, #0
	ldr r3, [r2]
	ldr r0, _02236338 ; =0x00001176
	add r4, #0x10
	strh r4, [r3, r0]
	add r3, r1, #1
	ldr r1, [r2]
	ldr r0, _0223633C ; =0x00000FC4
	strh r3, [r1, r0]
	b _022362D8
_022362D4:
	ldr r0, _0223633C ; =0x00000FC4
	strh r1, [r2, r0]
_022362D8:
	ldr r2, _02236330 ; =ov74_0223E2FC
	ldr r0, _02236340 ; =0x00000FC6
	ldr r1, [r2]
	mov r3, #0xdc
	strh r3, [r1, r0]
	add r1, r0, #0
	ldr r3, [r2]
	sub r1, #0xc6
	add r1, r3, r1
	sub r0, r0, #6
	str r1, [r3, r0]
	ldr r1, [r2]
	ldr r0, _02236344 ; =0x00001158
	ldrh r0, [r1, r0]
	cmp r0, #3
	bne _0223630E
	mov r5, #0
	ldr r0, _02236348 ; =0x00001170
	ldr r1, _0223634C ; =0x00000FC8
	b _0223630A
_02236300:
	ldr r3, [r2]
	add r4, r3, r5
	ldrb r3, [r4, r0]
	add r5, r5, #1
	strb r3, [r4, r1]
_0223630A:
	cmp r5, #6
	blt _02236300
_0223630E:
	ldr r1, _02236330 ; =ov74_0223E2FC
	ldr r0, _02236350 ; =ov74_02236354
	ldr r2, [r1]
	mov r1, #0x3f
	lsl r1, r1, #6
	add r1, r2, r1
	bl WM_StartScan
	cmp r0, #2
	beq _0223632A
	bl ov74_022361B8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0223632A:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02236330: .word ov74_0223E2FC
_02236334: .word 0x00001150
_02236338: .word 0x00001176
_0223633C: .word 0x00000FC4
_02236340: .word 0x00000FC6
_02236344: .word 0x00001158
_02236348: .word 0x00001170
_0223634C: .word 0x00000FC8
_02236350: .word ov74_02236354
	thumb_func_end ov74_02236258


	thumb_func_start ov74_02236354
ov74_02236354: ; 0x02236354
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _0223637A
	bl ov74_022361B8
	mov r0, #9
	bl ov74_02236168
	ldr r0, _02236468 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _0223646C ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _02236466
	mov r0, #4
	blx r1
	pop {r3, r4, r5, pc}
_0223637A:
	ldr r0, _02236468 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _02236470 ; =0x00001150
	ldr r0, [r1, r0]
	cmp r0, #2
	beq _022363A6
	bl ov74_0223648C
	cmp r0, #0
	bne _02236466
	mov r0, #9
	bl ov74_02236168
	ldr r0, _02236468 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _0223646C ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _02236466
	mov r0, #4
	blx r1
	pop {r3, r4, r5, pc}
_022363A6:
	ldrh r0, [r4, #8]
	cmp r0, #3
	beq _02236466
	cmp r0, #4
	beq _02236448
	cmp r0, #5
	bne _02236448
	mov r0, #0xf
	lsl r0, r0, #8
	add r0, r1, r0
	mov r1, #0xc0
	bl DC_InvalidateRange
	ldrh r0, [r4, #0x36]
	cmp r0, #8
	blo _022363CE
	ldr r1, [r4, #0x3c]
	ldr r0, _02236474 ; =0x00400318
	cmp r1, r0
	beq _022363E0
_022363CE:
	ldr r0, _02236468 ; =ov74_0223E2FC
	ldr r3, [r0, #4]
	cmp r3, #0
	beq _02236448
	ldr r0, _02236478 ; =ov74_0223D018
	ldr r1, [r4, #0x3c]
	ldr r2, _02236474 ; =0x00400318
	blx r3
	b _02236448
_022363E0:
	ldr r1, _02236468 ; =ov74_0223E2FC
	ldrh r3, [r4, #0x12]
	ldr r2, [r1]
	ldr r0, _0223647C ; =0x0000116C
	str r3, [r2, r0]
	ldr r1, [r1]
	sub r0, #0x14
	ldrh r0, [r1, r0]
	cmp r0, #2
	bne _0223642C
	add r0, r4, #0
	add r0, #0x48
	bl ov74_022366E8
	ldr r2, _02236468 ; =ov74_0223E2FC
	ldr r1, _02236480 ; =0x00001170
	mov r0, #0
_02236402:
	add r3, r4, r0
	ldrb r5, [r3, #0xa]
	ldr r3, [r2]
	add r3, r3, r0
	add r0, r0, #1
	strb r5, [r3, r1]
	cmp r0, #6
	blt _02236402
	ldr r1, _02236468 ; =ov74_0223E2FC
	ldr r0, _02236484 ; =0x00001176
	ldr r3, [r1]
	ldrh r2, [r3, r0]
	sub r2, #0xf
	strh r2, [r3, r0]
	ldr r1, [r1]
	add r0, r0, #6
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _0223642C
	mov r0, #1
	blx r1
_0223642C:
	add r4, #0x48
	add r0, r4, #0
	bl ov74_02236768
	cmp r0, #0
	beq _02236448
	ldr r0, _02236468 ; =ov74_0223E2FC
	mov r2, #4
	ldr r1, [r0]
	ldr r0, _02236488 ; =0x00001158
	strh r2, [r1, r0]
	bl ov74_022365FC
	pop {r3, r4, r5, pc}
_02236448:
	bl ov74_02236258
	cmp r0, #0
	bne _02236466
	mov r0, #9
	bl ov74_02236168
	ldr r0, _02236468 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _0223646C ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _02236466
	mov r0, #4
	blx r1
_02236466:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02236468: .word ov74_0223E2FC
_0223646C: .word 0x0000117C
_02236470: .word 0x00001150
_02236474: .word 0x00400318
_02236478: .word ov74_0223D018
_0223647C: .word 0x0000116C
_02236480: .word 0x00001170
_02236484: .word 0x00001176
_02236488: .word 0x00001158
	thumb_func_end ov74_02236354


	thumb_func_start ov74_0223648C
ov74_0223648C: ; 0x0223648C
	push {r3, lr}
	ldr r0, _022364A4 ; =ov74_022364A8
	bl WM_EndScan
	cmp r0, #2
	beq _022364A0
	bl ov74_022361B8
	mov r0, #0
	pop {r3, pc}
_022364A0:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_022364A4: .word ov74_022364A8
	thumb_func_end ov74_0223648C


	thumb_func_start ov74_022364A8
ov74_022364A8: ; 0x022364A8
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _022364B6
	bl ov74_022361B8
	pop {r3, pc}
_022364B6:
	mov r0, #1
	bl ov74_02236168
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end ov74_022364A8


	thumb_func_start ov74_022364C0
ov74_022364C0: ; 0x022364C0
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _022364D0
	mov r0, #0xa
	bl ov74_02236168
	pop {r3, pc}
_022364D0:
	mov r0, #0
	bl ov74_02236168
	ldr r0, _022364E8 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _022364EC ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _022364E6
	mov r0, #3
	blx r1
_022364E6:
	pop {r3, pc}
	.balign 4, 0
_022364E8: .word ov74_0223E2FC
_022364EC: .word 0x0000117C
	thumb_func_end ov74_022364C0


	thumb_func_start ov74_022364F0
ov74_022364F0: ; 0x022364F0
	push {r3, lr}
	ldr r0, _0223650C ; =ov74_0223E2FC
	mov r2, #0
	ldr r1, [r0]
	ldr r0, _02236510 ; =0x00001154
	str r2, [r1, r0]
	bl ov74_0223653C
	cmp r0, #0
	beq _02236508
	mov r0, #1
	pop {r3, pc}
_02236508:
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
_0223650C: .word ov74_0223E2FC
_02236510: .word 0x00001154
	thumb_func_end ov74_022364F0


	thumb_func_start ov74_02236514
ov74_02236514: ; 0x02236514
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #8
	bne _02236532
	mov r0, #9
	bl ov74_02236168
	ldr r0, _02236534 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _02236538 ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _02236532
	mov r0, #4
	blx r1
_02236532:
	pop {r3, pc}
	.balign 4, 0
_02236534: .word ov74_0223E2FC
_02236538: .word 0x0000117C
	thumb_func_end ov74_02236514


	thumb_func_start ov74_0223653C
ov74_0223653C: ; 0x0223653C
	push {r3, lr}
	mov r0, #3
	bl ov74_02236168
	ldr r0, _02236568 ; =ov74_0223E2FC
	ldr r1, _0223656C ; =ov74_02236570
	ldr r0, [r0]
	mov r2, #2
	bl WM_Initialize
	cmp r0, #2
	beq _02236562
	bl ov74_022361B8
	mov r0, #0xa
	bl ov74_02236168
	mov r0, #0
	pop {r3, pc}
_02236562:
	mov r0, #1
	pop {r3, pc}
	nop
_02236568: .word ov74_0223E2FC
_0223656C: .word ov74_02236570
	thumb_func_end ov74_0223653C


	thumb_func_start ov74_02236570
ov74_02236570: ; 0x02236570
	push {r3, lr}
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _02236584
	bl ov74_022361B8
	mov r0, #0xa
	bl ov74_02236168
	pop {r3, pc}
_02236584:
	ldr r0, _022365A8 ; =ov74_02236514
	bl WM_SetIndCallback
	cmp r0, #0
	beq _0223659A
	bl ov74_022361B8
	mov r0, #0xa
	bl ov74_02236168
	pop {r3, pc}
_0223659A:
	mov r0, #1
	bl ov74_02236168
	bl ov74_022361D4
	pop {r3, pc}
	nop
_022365A8: .word ov74_02236514
	thumb_func_end ov74_02236570


	thumb_func_start ov74_022365AC
ov74_022365AC: ; 0x022365AC
	push {r3, lr}
	ldr r0, _022365EC ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _022365F0 ; =0x00001150
	ldr r0, [r1, r0]
	cmp r0, #1
	beq _022365BE
	bl OS_Terminate
_022365BE:
	mov r0, #3
	bl ov74_02236168
	ldr r0, _022365F4 ; =ov74_022364C0
	bl WM_End
	cmp r0, #2
	beq _022365E8
	mov r0, #9
	bl ov74_02236168
	ldr r0, _022365EC ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _022365F8 ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _022365E4
	mov r0, #4
	blx r1
_022365E4:
	mov r0, #0
	pop {r3, pc}
_022365E8:
	mov r0, #1
	pop {r3, pc}
	.balign 4, 0
_022365EC: .word ov74_0223E2FC
_022365F0: .word 0x00001150
_022365F4: .word ov74_022364C0
_022365F8: .word 0x0000117C
	thumb_func_end ov74_022365AC


	thumb_func_start ov74_022365FC
ov74_022365FC: ; 0x022365FC
	push {r3, lr}
	ldr r0, _02236618 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _0223661C ; =0x00001150
	ldr r0, [r1, r0]
	cmp r0, #1
	bne _02236610
	bl ov74_022365AC
	pop {r3, pc}
_02236610:
	bl ov74_02236620
	pop {r3, pc}
	nop
_02236618: .word ov74_0223E2FC
_0223661C: .word 0x00001150
	thumb_func_end ov74_022365FC


	thumb_func_start ov74_02236620
ov74_02236620: ; 0x02236620
	push {r3, lr}
	mov r0, #3
	bl ov74_02236168
	ldr r0, _02236640 ; =ov74_02236644
	bl WM_Reset
	cmp r0, #2
	beq _0223663A
	bl ov74_022361B8
	mov r0, #0
	pop {r3, pc}
_0223663A:
	mov r0, #1
	pop {r3, pc}
	nop
_02236640: .word ov74_02236644
	thumb_func_end ov74_02236620


	thumb_func_start ov74_02236644
ov74_02236644: ; 0x02236644
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _0223666C
	mov r0, #9
	bl ov74_02236168
	ldrh r0, [r4, #2]
	bl ov74_022361B8
	ldr r0, _02236678 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _0223667C ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _02236676
	mov r0, #4
	blx r1
	pop {r4, pc}
_0223666C:
	mov r0, #1
	bl ov74_02236168
	bl ov74_022365AC
_02236676:
	pop {r4, pc}
	.balign 4, 0
_02236678: .word ov74_0223E2FC
_0223667C: .word 0x0000117C
	thumb_func_end ov74_02236644


	thumb_func_start ov74_02236680
ov74_02236680: ; 0x02236680
	push {r3, r4, r5, r6, r7, lr}
	add r7, r0, #0
	add r2, #0x1f
	mov r0, #0x1f
	bic r2, r0
	ldr r4, _022366DC ; =ov74_0223E2FC
	ldr r3, _022366E0 ; =0x00001150
	str r2, [r4]
	mov r0, #0
	str r0, [r2, r3]
	add r2, r3, #0
	ldr r5, [r4]
	mov r6, #1
	add r2, #8
	strh r6, [r5, r2]
	add r2, r3, #0
	ldr r5, [r4]
	add r2, #0x28
	str r7, [r5, r2]
	add r2, r3, #0
	ldr r5, [r4]
	add r2, #0xc
	strh r0, [r5, r2]
	add r2, r3, #0
	ldr r5, [r4]
	add r2, #0xe
	strh r0, [r5, r2]
	add r2, r3, #0
	ldr r5, [r4]
	add r2, #0x2c
	str r1, [r5, r2]
	add r2, r3, #0
	ldr r5, [r4]
	mov r1, #0x10
	add r2, #0x26
	strh r1, [r5, r2]
	ldr r5, [r4]
	ldr r2, _022366E4 ; =0x00001048
	sub r1, #0x11
	str r0, [r5, r2]
	ldr r0, [r4]
	add r3, #0x1c
	str r1, [r0, r3]
	bl ov74_022364F0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022366DC: .word ov74_0223E2FC
_022366E0: .word 0x00001150
_022366E4: .word 0x00001048
	thumb_func_end ov74_02236680


	thumb_func_start ov74_022366E8
ov74_022366E8: ; 0x022366E8
	push {r4, r5, r6, lr}
	ldr r3, _02236758 ; =ov74_0223E2FC
	ldr r1, _0223675C ; =0x00001048
	ldr r2, [r3]
	mov r4, #0
	str r4, [r2, r1]
	ldr r1, [r3]
	ldr r2, _02236760 ; =0x00001158
	mov r4, #3
	strh r4, [r1, r2]
	ldrh r5, [r0]
	ldr r4, [r3]
	add r1, r2, #2
	strh r5, [r4, r1]
	ldr r4, [r0, #4]
	add r0, r2, #0
	ldr r1, [r3]
	add r0, #8
	str r4, [r1, r0]
	ldr r4, [r3]
	add r2, #8
	ldr r0, [r4, r2]
	mov r1, #0x68
	sub r0, r0, #1
	bl _u32_div_f
	ldr r2, _02236764 ; =0x0000115C
	add r0, r0, #1
	strh r0, [r4, r2]
	ldr r4, _02236758 ; =ov74_0223E2FC
	mov r0, #0
	ldr r3, [r4]
	add r1, r2, #2
	strh r0, [r3, r1]
	add r1, r2, #0
	ldr r3, [r4]
	add r1, #8
	str r0, [r3, r1]
	ldr r1, [r4]
	ldrh r2, [r1, r2]
	cmp r2, #0
	ble _02236754
	mov r2, #0x46
	lsl r2, r2, #6
	add r3, r2, #0
	add r6, r0, #0
	sub r3, #0x24
_02236746:
	add r1, r1, r0
	strb r6, [r1, r2]
	ldr r1, [r4]
	add r0, r0, #1
	ldrh r5, [r1, r3]
	cmp r0, r5
	blt _02236746
_02236754:
	pop {r4, r5, r6, pc}
	nop
_02236758: .word ov74_0223E2FC
_0223675C: .word 0x00001048
_02236760: .word 0x00001158
_02236764: .word 0x0000115C
	thumb_func_end ov74_022366E8


	thumb_func_start ov74_02236768
ov74_02236768: ; 0x02236768
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r0, _02236884 ; =ov74_0223E2FC
	ldrh r1, [r4]
	ldr r3, [r0]
	ldr r0, _02236888 ; =0x0000115A
	ldrh r2, [r3, r0]
	cmp r2, r1
	bne _02236784
	add r0, r0, #6
	ldr r1, [r3, r0]
	ldr r0, [r4, #4]
	cmp r1, r0
	beq _022367B0
_02236784:
	ldr r0, _02236884 ; =ov74_0223E2FC
	ldr r3, [r0]
	ldr r0, _0223688C ; =0x00001164
	ldr r2, [r3, r0]
	add r1, r2, #1
	str r1, [r3, r0]
	cmp r2, #0x10
	blo _022367AC
	add r0, r4, #0
	bl ov74_022366E8
	ldr r0, _02236884 ; =ov74_0223E2FC
	ldr r1, [r0]
	ldr r0, _02236890 ; =0x0000117C
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _022367B0
	mov r0, #5
	blx r1
	b _022367B0
_022367AC:
	mov r0, #0
	pop {r3, r4, r5, pc}
_022367B0:
	ldrh r3, [r4, #2]
	ldr r0, _02236894 ; =0x0000FFFF
	cmp r3, r0
	bne _022367D8
	ldr r1, _02236884 ; =ov74_0223E2FC
	add r4, #8
	ldr r2, [r1]
	mov r1, #0xfe
	lsl r1, r1, #4
	add r1, r2, r1
	add r0, r4, #0
	mov r2, #0x68
	bl MIi_CpuCopy32
	ldr r0, _02236884 ; =ov74_0223E2FC
	mov r2, #1
	ldr r1, [r0]
	ldr r0, _02236898 ; =0x00001048
	str r2, [r1, r0]
	b _02236880
_022367D8:
	ldr r1, _02236884 ; =ov74_0223E2FC
	ldr r0, _0223689C ; =0x00001168
	ldr r2, [r1]
	str r3, [r2, r0]
	ldr r3, [r1]
	add r1, r0, #0
	sub r1, #0xc
	ldrh r2, [r4, #2]
	ldrh r1, [r3, r1]
	cmp r2, r1
	blo _02236800
	add r0, #0x14
	ldr r1, [r3, r0]
	cmp r1, #0
	beq _022367FA
	mov r0, #4
	blx r1
_022367FA:
	mov r0, #9
	bl ov74_02236168
_02236800:
	ldr r0, _02236884 ; =ov74_0223E2FC
	mov r2, #0x46
	ldr r1, [r0]
	lsl r2, r2, #6
	ldrh r3, [r4, #2]
	add r5, r1, r2
	ldrb r1, [r5, r3]
	cmp r1, #0
	bne _02236880
	mov r1, #1
	strb r1, [r5, r3]
	ldr r5, [r0]
	add r0, r2, #0
	sub r0, #0x24
	ldrh r0, [r5, r0]
	ldrh r1, [r4, #2]
	sub r0, r0, #1
	cmp r1, r0
	bne _02236844
	add r3, r1, #0
	add r1, r2, #0
	sub r1, #8
	sub r2, #0x20
	mov r0, #0x68
	ldr r1, [r5, r1]
	mul r3, r0
	ldr r2, [r5, r2]
	add r4, #8
	add r0, r4, #0
	add r1, r1, r3
	sub r2, r2, r3
	bl MIi_CpuCopy32
	b _02236858
_02236844:
	add r4, #8
	sub r2, #8
	add r0, r4, #0
	ldr r4, [r5, r2]
	mov r2, #0x68
	add r3, r1, #0
	mul r3, r2
	add r1, r4, r3
	bl MIi_CpuCopy32
_02236858:
	ldr r1, _02236884 ; =ov74_0223E2FC
	ldr r0, _022368A0 ; =0x0000115E
	ldr r3, [r1]
	ldrh r2, [r3, r0]
	add r2, r2, #1
	strh r2, [r3, r0]
	ldr r3, [r1]
	sub r1, r0, #2
	ldrh r2, [r3, r0]
	ldrh r1, [r3, r1]
	cmp r2, r1
	bne _02236880
	add r0, #0x1e
	ldr r1, [r3, r0]
	cmp r1, #0
	beq _0223687C
	mov r0, #2
	blx r1
_0223687C:
	mov r0, #1
	pop {r3, r4, r5, pc}
_02236880:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02236884: .word ov74_0223E2FC
_02236888: .word 0x0000115A
_0223688C: .word 0x00001164
_02236890: .word 0x0000117C
_02236894: .word 0x0000FFFF
_02236898: .word 0x00001048
_0223689C: .word 0x00001168
_022368A0: .word 0x0000115E
	thumb_func_end ov74_02236768


	thumb_func_start ov74_022368A4
ov74_022368A4: ; 0x022368A4
	push {r3, r4}
	mov r2, #0
	add r3, r2, #0
	lsr r1, r1, #1
	beq _022368CC
_022368AE:
	lsl r4, r3, #1
	ldrh r4, [r0, r4]
	add r3, r3, #1
	lsl r3, r3, #0x10
	add r2, r2, r4
	lsl r2, r2, #0x10
	lsr r2, r2, #0x10
	lsl r4, r2, #1
	asr r2, r2, #0xf
	orr r2, r4
	lsl r2, r2, #0x10
	lsr r3, r3, #0x10
	lsr r2, r2, #0x10
	cmp r3, r1
	blo _022368AE
_022368CC:
	add r0, r2, #0
	pop {r3, r4}
	bx lr
	.balign 4, 0
	thumb_func_end ov74_022368A4


	thumb_func_start ov74_022368D4
ov74_022368D4: ; 0x022368D4
	push {r4, lr}
	sub sp, #8
	ldr r0, _02236968 ; =ov74_0223E2FC
	add r1, sp, #0
	ldr r4, [r0]
	ldr r0, _0223696C ; =0x00001170
	add r3, r4, r0
	ldrh r2, [r3]
	sub r0, #0x16
	strh r2, [r1]
	ldrh r2, [r3, #2]
	strh r2, [r1, #6]
	ldrh r2, [r3, #4]
	add r3, sp, #0
	strh r2, [r1, #4]
	ldrh r0, [r4, r0]
	ldr r2, _02236970 ; =0x00003FA2
	strh r0, [r1, #2]
	mov r1, #0
_022368FA:
	ldrh r0, [r3]
	add r1, r1, #1
	eor r0, r2
	strh r0, [r3]
	ldrh r2, [r3]
	add r3, r3, #2
	cmp r1, #4
	blt _022368FA
	ldr r0, _02236968 ; =ov74_0223E2FC
	mov r2, #8
	ldr r1, [r0]
	ldr r0, _02236974 ; =0x0000104C
	add r0, r1, r0
	add r1, sp, #0
	bl CRYPTO_RC4Init
	ldr r0, _02236968 ; =ov74_0223E2FC
	ldr r2, _02236978 ; =0x00001178
	ldr r3, [r0]
	ldr r0, _02236974 ; =0x0000104C
	ldr r1, [r3, r2]
	sub r2, #0x18
	ldr r2, [r3, r2]
	add r0, r3, r0
	add r3, r1, #0
	bl CRYPTO_RC4Encrypt
	ldr r1, _02236968 ; =ov74_0223E2FC
	ldr r2, _02236974 ; =0x0000104C
	ldr r1, [r1]
	mov r0, #0
	add r1, r1, r2
	lsr r2, r2, #4
	bl MIi_CpuClear32
	ldr r0, _02236968 ; =ov74_0223E2FC
	ldr r1, _02236978 ; =0x00001178
	ldr r2, [r0]
	ldr r0, [r2, r1]
	sub r1, #0x18
	ldr r1, [r2, r1]
	bl ov74_022368A4
	ldr r1, _02236968 ; =ov74_0223E2FC
	ldr r2, [r1]
	ldr r1, _0223697C ; =0x0000115A
	ldrh r1, [r2, r1]
	cmp r1, r0
	bne _02236962
	add sp, #8
	mov r0, #1
	pop {r4, pc}
_02236962:
	mov r0, #0
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
_02236968: .word ov74_0223E2FC
_0223696C: .word 0x00001170
_02236970: .word 0x00003FA2
_02236974: .word 0x0000104C
_02236978: .word 0x00001178
_0223697C: .word 0x0000115A
	thumb_func_end ov74_022368D4


	thumb_func_start ov74_02236980
ov74_02236980: ; 0x02236980
	ldr r0, _02236984 ; =0x000016A0
	bx lr
	.balign 4, 0
_02236984: .word 0x000016A0
	thumb_func_end ov74_02236980


	thumb_func_start ov74_02236988
ov74_02236988: ; 0x02236988
	ldr r0, _022369A0 ; =ov74_0223E2FC
	ldr r2, [r0]
	ldr r0, _022369A4 ; =0x00001048
	ldr r1, [r2, r0]
	cmp r1, #0
	beq _0223699A
	sub r0, #0x68
	add r0, r2, r0
	bx lr
_0223699A:
	mov r0, #0
	bx lr
	nop
_022369A0: .word ov74_0223E2FC
_022369A4: .word 0x00001048
	thumb_func_end ov74_02236988


	thumb_func_start ov74_022369A8
ov74_022369A8: ; 0x022369A8
	push {r3, lr}
	add r1, #0x24
	mov r0, #0x1f
	bic r1, r0
	add r1, #0x20
	mov r0, #0x54
	bl Heap_Alloc
	add r2, r0, #0
	add r2, #0x20
	mov r1, #0x1f
	bic r2, r1
	sub r1, r2, #4
	str r0, [r1]
	add r0, r2, #0
	pop {r3, pc}
	thumb_func_end ov74_022369A8


	thumb_func_start ov74_022369C8
ov74_022369C8: ; 0x022369C8
	push {r3, lr}
	cmp r1, #0
	beq _022369D6
	sub r0, r1, #4
	ldr r0, [r0]
	bl Heap_Free
_022369D6:
	pop {r3, pc}
	thumb_func_end ov74_022369C8


	thumb_func_start ov74_022369D8
ov74_022369D8: ; 0x022369D8
	push {r4, lr}
	sub sp, #8
	add r4, r0, #0
	add r0, sp, #0
	add r1, sp, #4
	bl ov00_021EC11C
	ldr r0, [sp]
	ldr r1, [sp, #4]
	neg r0, r0
	bl ov00_021E6A70
	ldr r2, _02236A20 ; =0x0000266C
	str r0, [r4, r2]
	ldr r0, [sp]
	neg r1, r0
	add r0, r2, #4
	str r1, [r4, r0]
	add r0, r2, #0
	ldr r1, [sp, #4]
	add r0, #8
	str r1, [r4, r0]
	sub r0, r2, #4
	mov r1, #1
	str r1, [r4, r0]
	ldr r0, _02236A24 ; =ov74_0223E304
	add r2, #0x10
	str r1, [r0, #0x10]
	mov r1, #0
	add r0, r4, #0
	str r1, [r4, r2]
	bl ov74_02229E60
	ldr r0, _02236A28 ; =0x0000100F
	add sp, #8
	pop {r4, pc}
	.balign 4, 0
_02236A20: .word 0x0000266C
_02236A24: .word ov74_0223E304
_02236A28: .word 0x0000100F
	thumb_func_end ov74_022369D8


	thumb_func_start ov74_02236A2C
ov74_02236A2C: ; 0x02236A2C
	push {lr}
	sub sp, #0x3c
	bl ov00_021EC724
	cmp r0, #4
	beq _02236A40
	cmp r0, #7
	beq _02236A4C
	cmp r0, #8
	b _02236A4C
_02236A40:
	add r0, sp, #0
	bl ov00_021EC9E0
	add sp, #0x3c
	mov r0, #1
	pop {pc}
_02236A4C:
	mov r0, #0
	add sp, #0x3c
	pop {pc}
	.balign 4, 0
	thumb_func_end ov74_02236A2C


	thumb_func_start ov74_02236A54
ov74_02236A54: ; 0x02236A54
	push {r3, r4}
	ldr r3, _02236A6C ; =ov74_0223E304
	mov r4, #0
	str r4, [r3]
	str r4, [r3, #0xc]
	ldr r3, _02236A70 ; =0x00001650
	str r2, [r0, r3]
	ldr r0, _02236A74 ; =0x00001012
	str r0, [r1]
	pop {r3, r4}
	bx lr
	nop
_02236A6C: .word ov74_0223E304
_02236A70: .word 0x00001650
_02236A74: .word 0x00001012
	thumb_func_end ov74_02236A54


	thumb_func_start ov74_02236A78
ov74_02236A78: ; 0x02236A78
	push {r3, r4, r5, lr}
	add r4, r2, #0
	ldr r2, _02236A9C ; =ov74_0223E304
	mov r5, #0
	str r5, [r2, #4]
	str r1, [r2, #8]
	ldr r1, _02236AA0 ; =0x00001650
	str r3, [r0, r1]
	ldr r0, _02236AA4 ; =0x00001013
	str r0, [r4]
	ldr r0, _02236AA8 ; =ov74_02236ABC
	bl ov00_021ED308
	cmp r0, #0
	bne _02236A9A
	ldr r0, [sp, #0x10]
	str r0, [r4]
_02236A9A:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02236A9C: .word ov74_0223E304
_02236AA0: .word 0x00001650
_02236AA4: .word 0x00001013
_02236AA8: .word ov74_02236ABC
	thumb_func_end ov74_02236A78


	thumb_func_start ov74_02236AAC
ov74_02236AAC: ; 0x02236AAC
	ldr r0, _02236AB8 ; =ov74_0223E304
	mov r2, #1
	str r2, [r0]
	str r1, [r0, #0xc]
	bx lr
	nop
_02236AB8: .word ov74_0223E304
	thumb_func_end ov74_02236AAC


	thumb_func_start ov74_02236ABC
ov74_02236ABC: ; 0x02236ABC
	ldr r0, _02236AC4 ; =ov74_0223E304
	mov r1, #1
	str r1, [r0, #4]
	bx lr
	.balign 4, 0
_02236AC4: .word ov74_0223E304
	thumb_func_end ov74_02236ABC


	thumb_func_start ov74_02236AC8
ov74_02236AC8: ; 0x02236AC8
	push {r3, lr}
	bl sub_0203A914
	bl sub_020394F4
	bl UnloadOVY38
	bl UnloadDwcOverlay
	bl sub_02034DE0
	pop {r3, pc}
	thumb_func_end ov74_02236AC8


	thumb_func_start ov74_02236AE0
ov74_02236AE0: ; 0x02236AE0
	push {r3, r4, r5, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldr r0, _02236DE8 ; =0x0000267C
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02236B00
	blx r0
	cmp r0, #1
	bne _02236B00
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
_02236B00:
	mov r3, #1
	ldr r0, [r5]
	lsl r3, r3, #0xc
	sub r0, r0, r3
	cmp r0, #0x13
	bls _02236B0E
	b _02236F0A
_02236B0E:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02236B1A: ; jump table
	.short _02236B42 - _02236B1A - 2 ; case 0
	.short _02236B5A - _02236B1A - 2 ; case 1
	.short _02236B76 - _02236B1A - 2 ; case 2
	.short _02236B9E - _02236B1A - 2 ; case 3
	.short _02236BE8 - _02236B1A - 2 ; case 4
	.short _02236C00 - _02236B1A - 2 ; case 5
	.short _02236C46 - _02236B1A - 2 ; case 6
	.short _02236C6A - _02236B1A - 2 ; case 7
	.short _02236CA0 - _02236B1A - 2 ; case 8
	.short _02236CC2 - _02236B1A - 2 ; case 9
	.short _02236CFE - _02236B1A - 2 ; case 10
	.short _02236D24 - _02236B1A - 2 ; case 11
	.short _02236DAA - _02236B1A - 2 ; case 12
	.short _02236DC8 - _02236B1A - 2 ; case 13
	.short _02236F0A - _02236B1A - 2 ; case 14
	.short _02236DE2 - _02236B1A - 2 ; case 15
	.short _02236E94 - _02236B1A - 2 ; case 16
	.short _02236E8A - _02236B1A - 2 ; case 17
	.short _02236EB0 - _02236B1A - 2 ; case 18
	.short _02236EE6 - _02236B1A - 2 ; case 19
_02236B42:
	bl sub_02034D8C
	bl LoadDwcOverlay
	bl LoadOVY38
	mov r0, #3
	bl sub_02039FD8
	ldr r0, _02236DEC ; =0x00001001
	str r0, [r5]
	b _02236F0A
_02236B5A:
	bl sub_02034DB8
	cmp r0, #0
	beq _02236C3E
	ldr r0, _02236DF0 ; =ov74_022369A8
	ldr r1, _02236DF4 ; =ov74_022369C8
	bl ov00_021EC294
	ldr r0, [r4, #4]
	bl sub_020394A0
	ldr r0, _02236DF8 ; =0x00001002
	str r0, [r5]
	b _02236F0A
_02236B76:
	ldr r0, _02236DFC ; =0x000015E8
	mov r1, #2
	add r0, r4, r0
	mov r2, #1
	mov r3, #0x14
	bl ov00_021EC3F0
	mov r0, #2
	bl ov00_021EC454
	bl ov00_021EC4A4
	bl sub_0203A880
	ldr r0, _02236E00 ; =0x00001003
	mov r1, #0
	str r0, [r5]
	ldr r0, _02236E04 ; =0x00002678
	str r1, [r4, r0]
	b _02236F0A
_02236B9E:
	bl ov00_021EC60C
	bl ov00_021EC5B4
	cmp r0, #0
	beq _02236BD6
	add r0, r4, #0
	bl ov74_02236A2C
	cmp r0, #1
	bne _02236BCE
	ldr r0, _02236E04 ; =0x00002678
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _02236BC8
	ldr r0, _02236E08 ; =ov74_0223E304
	mov r1, #3
	str r1, [r0, #8]
	ldr r0, _02236E0C ; =0x0000100D
	str r0, [r5]
	b _02236BD6
_02236BC8:
	ldr r0, _02236E10 ; =0x00001004
	str r0, [r5]
	b _02236BD6
_02236BCE:
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
_02236BD6:
	ldr r0, _02236E14 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _02236C3E
	ldr r0, _02236E04 ; =0x00002678
	mov r1, #1
	str r1, [r4, r0]
	b _02236F0A
_02236BE8:
	bl ov00_021ECD04
	cmp r0, #0
	bne _02236BFA
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	b _02236F0A
_02236BFA:
	ldr r0, _02236E18 ; =0x00001005
	str r0, [r5]
	b _02236F0A
_02236C00:
	bl ov00_021ECDC8
	cmp r0, #3
	bne _02236C14
	ldr r0, _02236E1C ; =0x00001006
	ldr r1, _02236E20 ; =ov00_021ECB40
	str r0, [r5]
	ldr r0, _02236DE8 ; =0x0000267C
	str r1, [r4, r0]
	b _02236C34
_02236C14:
	cmp r0, #4
	bne _02236C26
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	bl ov00_021EC8D8
	b _02236C34
_02236C26:
	cmp r0, #5
	bne _02236C34
	ldr r0, _02236E08 ; =ov74_0223E304
	mov r1, #3
	str r1, [r0, #8]
	ldr r0, _02236E0C ; =0x0000100D
	str r0, [r5]
_02236C34:
	ldr r0, _02236E14 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	bne _02236C40
_02236C3E:
	b _02236F0A
_02236C40:
	bl ov00_021ECEC0
	b _02236F0A
_02236C46:
	ldr r0, _02236E24 ; =ov74_02236AAC
	ldr r1, _02236E28 ; =ov74_0223D038
	ldr r2, _02236E2C ; =ov74_0223D040
	bl ov00_021ED1F0
	cmp r0, #0
	bne _02236C5E
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	b _02236F0A
_02236C5E:
	ldr r2, _02236E30 ; =0x00001007
	add r0, r4, #0
	add r1, r5, #0
	bl ov74_02236A54
	b _02236F0A
_02236C6A:
	ldr r0, _02236E04 ; =0x00002678
	ldr r0, [r4, r0]
	cmp r0, #1
	bne _02236C82
	add r3, #0xc
	add r0, r4, #0
	mov r1, #3
	add r2, r5, #0
	str r3, [sp]
	bl ov74_02236A78
	b _02236F0A
_02236C82:
	ldr r0, _02236E34 ; =ov74_0223D054
	add r1, r0, #0
	add r2, r0, #0
	bl ov00_021ED354
	cmp r0, #0
	bne _02236C9A
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	b _02236F0A
_02236C9A:
	ldr r0, _02236E38 ; =0x00001008
	str r0, [r5]
	b _02236F0A
_02236CA0:
	ldr r0, _02236E3C ; =0x00001654
	add r0, r4, r0
	bl ov00_021ED388
	cmp r0, #0
	bne _02236CB6
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	b _02236F0A
_02236CB6:
	ldr r2, _02236E40 ; =0x00001009
	add r0, r4, #0
	add r1, r5, #0
	bl ov74_02236A54
	b _02236F0A
_02236CC2:
	ldr r0, _02236E3C ; =0x00001654
	ldr r0, [r4, r0]
	cmp r0, #1
	beq _02236CDA
	add r3, #0xd
	add r0, r4, #0
	mov r1, #2
	add r2, r5, #0
	str r3, [sp]
	bl ov74_02236A78
	b _02236F0A
_02236CDA:
	ldr r0, _02236E44 ; =ov74_0223E318
	mov r1, #0
	mov r2, #0xa
	bl ov00_021ED3AC
	cmp r0, #0
	bne _02236CF2
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	b _02236F0A
_02236CF2:
	ldr r2, _02236E48 ; =0x0000100A
	add r0, r4, #0
	add r1, r5, #0
	bl ov74_02236A54
	b _02236F0A
_02236CFE:
	ldr r1, _02236E4C ; =0x00001658
	ldr r0, _02236E44 ; =ov74_0223E318
	add r1, r4, r1
	add r2, r3, #0
	bl ov00_021ED3F4
	cmp r0, #0
	bne _02236D18
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	b _02236F0A
_02236D18:
	ldr r0, _02236E50 ; =0x0000100B
	mov r1, #0
	str r0, [r5]
	ldr r0, _02236E54 ; =0x00002664
	str r1, [r4, r0]
	b _02236F0A
_02236D24:
	ldr r0, _02236E08 ; =ov74_0223E304
	ldr r1, [r0]
	cmp r1, #0
	bne _02236D72
	ldr r0, _02236E14 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _02236D46
	add r3, #0xc
	add r0, r4, #0
	mov r1, #3
	add r2, r5, #0
	str r3, [sp]
	bl ov74_02236A78
	b _02236F0A
_02236D46:
	ldr r1, _02236E58 ; =0x0000265C
	add r0, r4, r1
	add r1, r1, #4
	add r1, r4, r1
	bl ov00_021ED444
	cmp r0, #1
	bne _02236DD0
	ldr r1, _02236E58 ; =0x0000265C
	mov r0, #0x64
	ldr r2, [r4, r1]
	add r1, r1, #4
	ldr r1, [r4, r1]
	mul r0, r2
	bl _u32_div_f
	ldr r1, _02236E54 ; =0x00002664
	ldr r2, [r4, r1]
	cmp r2, r0
	beq _02236DD0
	str r0, [r4, r1]
	b _02236F0A
_02236D72:
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02236D82
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	b _02236F0A
_02236D82:
	ldr r0, _02236E04 ; =0x00002678
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _02236D9A
	add r3, #0xd
	add r0, r4, #0
	mov r1, #1
	add r2, r5, #0
	str r3, [sp]
	bl ov74_02236A78
	b _02236F0A
_02236D9A:
	add r3, #0xd
	add r0, r4, #0
	mov r1, #3
	add r2, r5, #0
	str r3, [sp]
	bl ov74_02236A78
	b _02236F0A
_02236DAA:
	bl ov00_021ED428
	cmp r0, #0
	bne _02236DB8
	ldr r0, _02236E0C ; =0x0000100D
	str r0, [r5]
	b _02236F0A
_02236DB8:
	ldr r0, _02236DE8 ; =0x0000267C
	mov r1, #0
	str r1, [r4, r0]
	bl ov74_02236AC8
	ldr r0, _02236E08 ; =ov74_0223E304
	ldr r0, [r0, #8]
	pop {r3, r4, r5, pc}
_02236DC8:
	bl ov00_021EC938
	cmp r0, #1
	beq _02236DD2
_02236DD0:
	b _02236F0A
_02236DD2:
	ldr r0, _02236DE8 ; =0x0000267C
	mov r1, #0
	str r1, [r4, r0]
	bl ov74_02236AC8
	ldr r0, _02236E08 ; =ov74_0223E304
	ldr r0, [r0, #8]
	pop {r3, r4, r5, pc}
_02236DE2:
	ldr r0, _02236E08 ; =ov74_0223E304
	b _02236E5C
	nop
_02236DE8: .word 0x0000267C
_02236DEC: .word 0x00001001
_02236DF0: .word ov74_022369A8
_02236DF4: .word ov74_022369C8
_02236DF8: .word 0x00001002
_02236DFC: .word 0x000015E8
_02236E00: .word 0x00001003
_02236E04: .word 0x00002678
_02236E08: .word ov74_0223E304
_02236E0C: .word 0x0000100D
_02236E10: .word 0x00001004
_02236E14: .word gSystem
_02236E18: .word 0x00001005
_02236E1C: .word 0x00001006
_02236E20: .word ov00_021ECB40
_02236E24: .word ov74_02236AAC
_02236E28: .word ov74_0223D038
_02236E2C: .word ov74_0223D040
_02236E30: .word 0x00001007
_02236E34: .word ov74_0223D054
_02236E38: .word 0x00001008
_02236E3C: .word 0x00001654
_02236E40: .word 0x00001009
_02236E44: .word ov74_0223E318
_02236E48: .word 0x0000100A
_02236E4C: .word 0x00001658
_02236E50: .word 0x0000100B
_02236E54: .word 0x00002664
_02236E58: .word 0x0000265C
_02236E5C:
	ldr r0, [r0, #0x10]
	cmp r0, #1
	bne _02236F0A
	add r0, r4, #0
	bl ov74_0222ACD8
	ldr r0, _02236F10 ; =0x00002674
	ldr r0, [r4, r0]
	sub r0, r0, #5
	cmp r0, #1
	bhi _02236E84
	ldr r3, _02236F14 ; =0x00001010
	add r0, r4, #0
	str r3, [sp]
	mov r1, #3
	add r2, r5, #0
	add r3, r3, #1
	bl ov74_02236A78
	b _02236F0A
_02236E84:
	ldr r0, _02236F18 ; =0x00001011
	str r0, [r5]
	b _02236F0A
_02236E8A:
	bl ov00_021EC8D8
	ldr r0, _02236F14 ; =0x00001010
	str r0, [r5]
	b _02236F0A
_02236E94:
	ldr r0, _02236F1C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #1
	tst r0, r1
	beq _02236F0A
	ldr r0, _02236F20 ; =0x0000267C
	mov r1, #0
	str r1, [r4, r0]
	bl ov00_021EC210
	bl ov74_02236AC8
	mov r0, #4
	pop {r3, r4, r5, pc}
_02236EB0:
	ldr r0, _02236F24 ; =ov74_0223E304
	ldr r1, [r0]
	cmp r1, #1
	bne _02236ED4
	mov r1, #0
	str r1, [r0]
	ldr r0, [r0, #0xc]
	cmp r0, #0
	beq _02236ECC
	add r0, r4, #0
	bl ov74_022369D8
	str r0, [r5]
	b _02236F0A
_02236ECC:
	ldr r0, _02236F28 ; =0x00001650
	ldr r0, [r4, r0]
	str r0, [r5]
	b _02236F0A
_02236ED4:
	ldr r0, _02236F1C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _02236F0A
	ldr r0, _02236F2C ; =0x00002678
	mov r1, #1
	str r1, [r4, r0]
	b _02236F0A
_02236EE6:
	ldr r0, _02236F24 ; =ov74_0223E304
	ldr r1, [r0, #4]
	cmp r1, #1
	bne _02236EFA
	mov r1, #0
	str r1, [r0, #4]
	ldr r0, _02236F28 ; =0x00001650
	ldr r0, [r4, r0]
	str r0, [r5]
	b _02236F0A
_02236EFA:
	ldr r0, _02236F1C ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _02236F0A
	ldr r0, _02236F2C ; =0x00002678
	mov r1, #1
	str r1, [r4, r0]
_02236F0A:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_02236F10: .word 0x00002674
_02236F14: .word 0x00001010
_02236F18: .word 0x00001011
_02236F1C: .word gSystem
_02236F20: .word 0x0000267C
_02236F24: .word ov74_0223E304
_02236F28: .word 0x00001650
_02236F2C: .word 0x00002678
	thumb_func_end ov74_02236AE0


	thumb_func_start ov74_02236F30
ov74_02236F30: ; 0x02236F30
	cmp r0, #1
	bne _02236F38
	mov r0, #1
	b _02236F3A
_02236F38:
	ldr r0, _02236F40 ; =0x000001DE
_02236F3A:
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bx lr
	.balign 4, 0
_02236F40: .word 0x000001DE
	thumb_func_end ov74_02236F30


	thumb_func_start ov74_02236F44
ov74_02236F44: ; 0x02236F44
	cmp r0, #7
	bhi _02236F64
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02236F54: ; jump table
	.short _02236F64 - _02236F54 - 2 ; case 0
	.short _02236F64 - _02236F54 - 2 ; case 1
	.short _02236F68 - _02236F54 - 2 ; case 2
	.short _02236F6E - _02236F54 - 2 ; case 3
	.short _02236F68 - _02236F54 - 2 ; case 4
	.short _02236F72 - _02236F54 - 2 ; case 5
	.short _02236F64 - _02236F54 - 2 ; case 6
	.short _02236F68 - _02236F54 - 2 ; case 7
_02236F64:
	mov r0, #0xea
	bx lr
_02236F68:
	mov r0, #0x6d
	lsl r0, r0, #2
	bx lr
_02236F6E:
	ldr r0, _02236F78 ; =0x000001B7
	bx lr
_02236F72:
	ldr r0, _02236F7C ; =0x000001B6
	bx lr
	nop
_02236F78: .word 0x000001B7
_02236F7C: .word 0x000001B6
	thumb_func_end ov74_02236F44


	thumb_func_start ov74_02236F80
ov74_02236F80: ; 0x02236F80
	cmp r0, #7
	bhi _02236FA0
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02236F90: ; jump table
	.short _02236FA0 - _02236F90 - 2 ; case 0
	.short _02236FA0 - _02236F90 - 2 ; case 1
	.short _02236FA4 - _02236F90 - 2 ; case 2
	.short _02236FA8 - _02236F90 - 2 ; case 3
	.short _02236FA4 - _02236F90 - 2 ; case 4
	.short _02236FAE - _02236F90 - 2 ; case 5
	.short _02236FA0 - _02236F90 - 2 ; case 6
	.short _02236FA4 - _02236F90 - 2 ; case 7
_02236FA0:
	mov r0, #0xeb
	bx lr
_02236FA4:
	ldr r0, _02236FB4 ; =0x000001B5
	bx lr
_02236FA8:
	mov r0, #0x6e
	lsl r0, r0, #2
	bx lr
_02236FAE:
	mov r0, #0x6d
	lsl r0, r0, #2
	bx lr
	.balign 4, 0
_02236FB4: .word 0x000001B5
	thumb_func_end ov74_02236F80


	thumb_func_start ConvertRSStringToDPStringInternational
ConvertRSStringToDPStringInternational: ; 0x02236FB8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r3, #0
	str r0, [sp]
	str r1, [sp, #4]
	str r2, [sp, #8]
	cmp r5, #1
	beq _02236FCC
	mov r2, #1
	b _02236FCE
_02236FCC:
	mov r2, #0
_02236FCE:
	ldr r0, [sp, #8]
	mov r6, #0
	sub r0, r0, #1
	str r0, [sp, #0xc]
	beq _02237056
	ldr r1, _02237064 ; =_0223B760
	lsl r0, r2, #1
	ldr r4, [sp, #4]
	add r7, r1, r0
_02236FE0:
	ldr r0, [sp]
	ldrb r0, [r0, r6]
	cmp r0, #0xff
	beq _02237056
	cmp r0, #0xf7
	blo _0223701A
	ldr r0, [sp, #8]
	sub r3, r0, #1
	cmp r3, #0xa
	blo _02236FF6
	mov r3, #0xa
_02236FF6:
	mov r1, #0
	cmp r3, #0
	ble _0223700C
	mov r0, #0x6b
	ldr r2, [sp, #4]
	lsl r0, r0, #2
_02237002:
	add r1, r1, #1
	strh r0, [r2]
	add r2, r2, #2
	cmp r1, r3
	blt _02237002
_0223700C:
	ldr r0, [sp, #4]
	ldr r2, _02237068 ; =0x0000FFFF
	lsl r1, r1, #1
	strh r2, [r0, r1]
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0223701A:
	lsl r0, r0, #2
	ldrh r0, [r7, r0]
	cmp r0, #1
	beq _0223702C
	cmp r0, #0xea
	beq _02237036
	cmp r0, #0xeb
	beq _02237040
	b _0223704A
_0223702C:
	add r0, r5, #0
	bl ov74_02236F30
	strh r0, [r4]
	b _0223704C
_02237036:
	add r0, r5, #0
	bl ov74_02236F44
	strh r0, [r4]
	b _0223704C
_02237040:
	add r0, r5, #0
	bl ov74_02236F80
	strh r0, [r4]
	b _0223704C
_0223704A:
	strh r0, [r4]
_0223704C:
	ldr r0, [sp, #0xc]
	add r6, r6, #1
	add r4, r4, #2
	cmp r6, r0
	blo _02236FE0
_02237056:
	ldr r2, _02237068 ; =0x0000FFFF
	ldr r0, [sp, #4]
	lsl r1, r6, #1
	strh r2, [r0, r1]
	mov r0, #1
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02237064: .word _0223B760
_02237068: .word 0x0000FFFF
	thumb_func_end ConvertRSStringToDPStringInternational

	.rodata

	.public gApp_MainMenu
gApp_MainMenu:
	.word MainMenuApp_Init, MainMenuApp_Main, MainMenuApp_Exit, 0xFFFFFFFF
gApp_MainMenu_SelectOption_ConnectToRanger:
	.word ov74_02229200, ov74_02229294, ov74_02229450, 0xFFFFFFFF
_0223B330:
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B340:
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00
_0223B368:
	.word ov74_02229DA0
	.word ov74_02229DCC
	.word ov74_02229DD4
	.word ov74_02229DE0
	.word sub_020342C0
	.word 0
gApp_MainMenu_SelectOption_MysteryGift:
	.word ov74_0222AE6C, ov74_0222C2EC, ov74_0222CD94, 0xFFFFFFFF
_0223B390:
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B3A0:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B3BC:
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x1E, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x00, 0x5A, 0x00, 0x00, 0x00, 0x5A, 0x00, 0x00, 0x00
	.byte 0x78, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00
	.byte 0x96, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0xB4, 0x00, 0x00, 0x00
	.byte 0xB4, 0x00, 0x00, 0x00, 0xB4, 0x00, 0x00, 0x00, 0xB4, 0x00, 0x00, 0x00, 0xD2, 0x00, 0x00, 0x00
	.byte 0xD2, 0x00, 0x00, 0x00, 0xD2, 0x00, 0x00, 0x00, 0xD2, 0x00, 0x00, 0x00, 0xD2, 0x00, 0x00, 0x00
_0223B410:
	.word ov74_0222DDFC, ov74_0222E1F4, ov74_0222EB44, 0xFFFFFFFF
_0223B420:
	.word ov74_0222F598, ov74_0222F7D4, ov74_0222FB8C, 0xFFFFFFFF
_0223B430:
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B440:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1F, 0x03, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B45C:
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1C, 0x00
	.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B478:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1E, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
_0223B494:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1D, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B4B0:
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00
gApp_MainMenu_SelectOption_MigrateFromAgb:
	.word ov74_02233230, ov74_022332F4, ov74_022338D4, 0xFFFFFFFF
_0223B4E8:
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x4C, 0x00, 0x00, 0x00
_0223B4F8:
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B508:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
_0223B524:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1D, 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B540:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x1E, 0x02, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B55C:
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x1F, 0x02
	.byte 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B578:
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00
sPmAgbRomCodeMappings:
	; Ruby
	.balign 4, 0
	.ascii "AXVJ"
	.byte 0x00, 0x00
	.short LANGUAGE_JAPANESE
	.balign 4, 0
	.ascii "AXVE"
	.byte 0x00, 0x00
	.short LANGUAGE_ENGLISH
	.balign 4, 0
	.ascii "AXVF"
	.byte 0x00, 0x00
	.short LANGUAGE_FRENCH
	.balign 4, 0
	.ascii "AXVD"
	.byte 0x00, 0x00
	.short LANGUAGE_GERMAN
	.balign 4, 0
	.ascii "AXVS"
	.byte 0x00, 0x00
	.short LANGUAGE_SPANISH
	.balign 4, 0
	.ascii "AXVI"
	.byte 0x00, 0x00
	.short LANGUAGE_ITALIAN

	; Sapphire
	.balign 4, 0
	.ascii "AXPJ"
	.byte 0x00, 0x01
	.short LANGUAGE_JAPANESE
	.balign 4, 0
	.ascii "AXPE"
	.byte 0x00, 0x01
	.short LANGUAGE_ENGLISH
	.balign 4, 0
	.ascii "AXPF"
	.byte 0x00, 0x01
	.short LANGUAGE_FRENCH
	.balign 4, 0
	.ascii "AXPD"
	.byte 0x00, 0x01
	.short LANGUAGE_GERMAN
	.balign 4, 0
	.ascii "AXPS"
	.byte 0x00, 0x01
	.short LANGUAGE_SPANISH
	.balign 4, 0
	.ascii "AXPI"
	.byte 0x00, 0x01
	.short LANGUAGE_ITALIAN

	; FireRed
	.balign 4, 0
	.ascii "BPRJ"
	.byte 0x01, 0x03
	.short LANGUAGE_JAPANESE
	.balign 4, 0
	.ascii "BPRE"
	.byte 0x01, 0x03
	.short LANGUAGE_ENGLISH
	.balign 4, 0
	.ascii "BPRF"
	.byte 0x01, 0x03
	.short LANGUAGE_FRENCH
	.balign 4, 0
	.ascii "BPRD"
	.byte 0x01, 0x03
	.short LANGUAGE_GERMAN
	.balign 4, 0
	.ascii "BPRS"
	.byte 0x01, 0x03
	.short LANGUAGE_SPANISH
	.balign 4, 0
	.ascii "BPRI"
	.byte 0x01, 0x03
	.short LANGUAGE_ITALIAN

	; LeafGreen
	.balign 4, 0
	.ascii "BPGJ"
	.byte 0x01, 0x02
	.short LANGUAGE_JAPANESE
	.balign 4, 0
	.ascii "BPGE"
	.byte 0x01, 0x02
	.short LANGUAGE_ENGLISH
	.balign 4, 0
	.ascii "BPGF"
	.byte 0x01, 0x02
	.short LANGUAGE_FRENCH
	.balign 4, 0
	.ascii "BPGD"
	.byte 0x01, 0x02
	.short LANGUAGE_GERMAN
	.balign 4, 0
	.ascii "BPGS"
	.byte 0x01, 0x02
	.short LANGUAGE_SPANISH
	.balign 4, 0
	.ascii "BPGI"
	.byte 0x01, 0x02
	.short LANGUAGE_ITALIAN

	; Emerald
	.balign 4, 0
	.ascii "BPEJ"
	.byte 0x02, 0x04
	.short LANGUAGE_JAPANESE
	.balign 4, 0
	.ascii "BPEE"
	.byte 0x02, 0x04
	.short LANGUAGE_ENGLISH
	.balign 4, 0
	.ascii "BPEF"
	.byte 0x02, 0x04
	.short LANGUAGE_FRENCH
	.balign 4, 0
	.ascii "BPED"
	.byte 0x02, 0x04
	.short LANGUAGE_GERMAN
	.balign 4, 0
	.ascii "BPES"
	.byte 0x02, 0x04
	.short LANGUAGE_SPANISH
	.balign 4, 0
	.ascii "BPEI"
	.byte 0x02, 0x04
	.short LANGUAGE_ITALIAN
	.balign 4, 0
_0223B690:
	.byte 0xC8, 0x7E, 0x66, 0x71, 0x46, 0x0B, 0xE6, 0x6F, 0x17, 0x8A, 0x5C, 0x7D, 0xEA, 0xE1, 0x93, 0xFD
	.byte 0xEE, 0xFA, 0x99, 0x84, 0xFE, 0x35, 0x02, 0xB9, 0x7F, 0x4F, 0xF1, 0x19, 0x74, 0xA2, 0x0F, 0x65
	.byte 0x8A, 0x9C, 0x44, 0x81, 0x0C, 0x1F, 0x94, 0xE4, 0xC0, 0xB6, 0xD7, 0x20, 0xEE, 0x11, 0x9A, 0x8D
	.byte 0x27, 0x33, 0x9B, 0x7B, 0x02, 0xE9, 0x33, 0x11, 0xDC, 0xCF, 0x72, 0xD9, 0xA8, 0x78, 0x12, 0x8C
	.byte 0x3B, 0x60, 0xD5, 0x24, 0xB8, 0xD9, 0xFC, 0x8D, 0x15, 0xBA, 0x0B, 0x90, 0xA3, 0xBD, 0x3A, 0xE4
	.byte 0x01, 0x18, 0xBA, 0xF9, 0x65, 0xA5, 0x15, 0x37, 0xDC, 0x7A, 0x48, 0x5C, 0x3A, 0x55, 0x35, 0x43
	.byte 0xE2, 0xC6, 0x66, 0xBA, 0x21, 0xEA, 0x67, 0x2E, 0xA8, 0x29, 0x03, 0xD7, 0x1F, 0x0F, 0xC6, 0xDE
	.byte 0x1B, 0xE2, 0xA1, 0xCA, 0x21, 0x51, 0xFE, 0xB9, 0x68, 0x17, 0x3C, 0xEB, 0x04, 0x54, 0xE0, 0xBD
_0223B710:
	.byte 0x28, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B720:
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
_0223B73C:
	.byte 0x00, 0x00, 0x01, 0x01
	.byte 0x02, 0x01, 0x03, 0x02, 0x04, 0x03, 0x05, 0x02, 0x06, 0x02, 0x07, 0x00, 0x08, 0x05, 0x09, 0x05
	.byte 0x0A, 0x05, 0x0B, 0x04, 0x0C, 0x05, 0x0D, 0x05, 0x0E, 0x02, 0x0F, 0x02, 0xFF, 0x00, 0x00, 0x00
_0223B760:
	.byte 0x01, 0x00, 0x01, 0x00, 0x03, 0x00, 0x03, 0x00, 0x05, 0x00, 0x05, 0x00, 0x07, 0x00, 0x07, 0x00
	.byte 0x09, 0x00, 0x09, 0x00, 0x0B, 0x00, 0x0B, 0x00, 0x0C, 0x00, 0x0C, 0x00, 0x0E, 0x00, 0x0E, 0x00
	.byte 0x10, 0x00, 0x10, 0x00, 0x12, 0x00, 0x12, 0x00, 0x14, 0x00, 0x14, 0x00, 0x16, 0x00, 0x16, 0x00
	.byte 0x18, 0x00, 0x18, 0x00, 0x1A, 0x00, 0x1A, 0x00, 0x1C, 0x00, 0x1C, 0x00, 0x1E, 0x00, 0x1E, 0x00
	.byte 0x20, 0x00, 0x20, 0x00, 0x22, 0x00, 0x22, 0x00, 0x25, 0x00, 0x25, 0x00, 0x27, 0x00, 0x27, 0x00
	.byte 0x29, 0x00, 0x29, 0x00, 0x2B, 0x00, 0x2B, 0x00, 0x2C, 0x00, 0x2C, 0x00, 0x2D, 0x00, 0x2D, 0x00
	.byte 0x2E, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x30, 0x00, 0x33, 0x00, 0x33, 0x00
	.byte 0x36, 0x00, 0x36, 0x00, 0x39, 0x00, 0x39, 0x00, 0x3C, 0x00, 0x3C, 0x00, 0x3F, 0x00, 0x3F, 0x00
	.byte 0x40, 0x00, 0x40, 0x00, 0x41, 0x00, 0x41, 0x00, 0x42, 0x00, 0x42, 0x00, 0x43, 0x00, 0x43, 0x00
	.byte 0x45, 0x00, 0x45, 0x00, 0x47, 0x00, 0x47, 0x00, 0x49, 0x00, 0x49, 0x00, 0x4A, 0x00, 0x4A, 0x00
	.byte 0x4B, 0x00, 0x4B, 0x00, 0x4C, 0x00, 0x4C, 0x00, 0x4D, 0x00, 0x4D, 0x00, 0x4E, 0x00, 0x4E, 0x00
	.byte 0x4F, 0x00, 0x4F, 0x00, 0x50, 0x00, 0x50, 0x00, 0x51, 0x00, 0x51, 0x00, 0x02, 0x00, 0x02, 0x00
	.byte 0x04, 0x00, 0x04, 0x00, 0x06, 0x00, 0x06, 0x00, 0x08, 0x00, 0x08, 0x00, 0x0A, 0x00, 0x0A, 0x00
	.byte 0x44, 0x00, 0x44, 0x00, 0x46, 0x00, 0x46, 0x00, 0x48, 0x00, 0x48, 0x00, 0x0D, 0x00, 0x0D, 0x00
	.byte 0x0F, 0x00, 0x0F, 0x00, 0x11, 0x00, 0x11, 0x00, 0x13, 0x00, 0x13, 0x00, 0x15, 0x00, 0x15, 0x00
	.byte 0x17, 0x00, 0x17, 0x00, 0x19, 0x00, 0x19, 0x00, 0x1B, 0x00, 0x1B, 0x00, 0x1D, 0x00, 0x1D, 0x00
	.byte 0x1F, 0x00, 0x1F, 0x00, 0x21, 0x00, 0x21, 0x00, 0x23, 0x00, 0x23, 0x00, 0x26, 0x00, 0x26, 0x00
	.byte 0x28, 0x00, 0x28, 0x00, 0x2A, 0x00, 0x2A, 0x00, 0x31, 0x00, 0x31, 0x00, 0x34, 0x00, 0x34, 0x00
	.byte 0x37, 0x00, 0x37, 0x00, 0x3A, 0x00, 0x3A, 0x00, 0x3D, 0x00, 0x3D, 0x00, 0x32, 0x00, 0x32, 0x00
	.byte 0x35, 0x00, 0x35, 0x00, 0x38, 0x00, 0x38, 0x00, 0x3B, 0x00, 0x3B, 0x00, 0x3E, 0x00, 0x3E, 0x00
	.byte 0x24, 0x00, 0x24, 0x00, 0x53, 0x00, 0x53, 0x00, 0x55, 0x00, 0x55, 0x00, 0x57, 0x00, 0x57, 0x00
	.byte 0x59, 0x00, 0x59, 0x00, 0x5B, 0x00, 0x5B, 0x00, 0x5C, 0x00, 0x5C, 0x00, 0x5E, 0x00, 0x5E, 0x00
	.byte 0x60, 0x00, 0x60, 0x00, 0x62, 0x00, 0x62, 0x00, 0x64, 0x00, 0x64, 0x00, 0x66, 0x00, 0x66, 0x00
	.byte 0x68, 0x00, 0x68, 0x00, 0x6A, 0x00, 0x6A, 0x00, 0x6C, 0x00, 0x6C, 0x00, 0x6E, 0x00, 0x6E, 0x00
	.byte 0x70, 0x00, 0x70, 0x00, 0x72, 0x00, 0x72, 0x00, 0x75, 0x00, 0x75, 0x00, 0x77, 0x00, 0x77, 0x00
	.byte 0x79, 0x00, 0x79, 0x00, 0x7B, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7D, 0x00
	.byte 0x7E, 0x00, 0x7E, 0x00, 0x7F, 0x00, 0x7F, 0x00, 0x80, 0x00, 0x80, 0x00, 0x83, 0x00, 0x83, 0x00
	.byte 0x86, 0x00, 0x86, 0x00, 0x89, 0x00, 0x89, 0x00, 0x8C, 0x00, 0x8C, 0x00, 0x8F, 0x00, 0x8F, 0x00
	.byte 0x90, 0x00, 0x90, 0x00, 0x91, 0x00, 0x91, 0x00, 0x92, 0x00, 0x92, 0x00, 0x93, 0x00, 0x93, 0x00
	.byte 0x95, 0x00, 0x95, 0x00, 0x97, 0x00, 0x97, 0x00, 0x99, 0x00, 0x99, 0x00, 0x9A, 0x00, 0x9A, 0x00
	.byte 0x9B, 0x00, 0x9B, 0x00, 0x9C, 0x00, 0x9C, 0x00, 0x9D, 0x00, 0x9D, 0x00, 0x9E, 0x00, 0x9E, 0x00
	.byte 0x9F, 0x00, 0x9F, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0xA1, 0x00, 0xA1, 0x00, 0x52, 0x00, 0x52, 0x00
	.byte 0x54, 0x00, 0x54, 0x00, 0x56, 0x00, 0x56, 0x00, 0x58, 0x00, 0x58, 0x00, 0x5A, 0x00, 0x5A, 0x00
	.byte 0x94, 0x00, 0x94, 0x00, 0x96, 0x00, 0x96, 0x00, 0x98, 0x00, 0x98, 0x00, 0x5D, 0x00, 0x5D, 0x00
	.byte 0x5F, 0x00, 0x5F, 0x00, 0x61, 0x00, 0x61, 0x00, 0x63, 0x00, 0x63, 0x00, 0x65, 0x00, 0x65, 0x00
	.byte 0x67, 0x00, 0x67, 0x00, 0x69, 0x00, 0x69, 0x00, 0x6B, 0x00, 0x6B, 0x00, 0x6D, 0x00, 0x6D, 0x00
	.byte 0x6F, 0x00, 0x6F, 0x00, 0x71, 0x00, 0x71, 0x00, 0x73, 0x00, 0x73, 0x00, 0x76, 0x00, 0x76, 0x00
	.byte 0x78, 0x00, 0x78, 0x00, 0x7A, 0x00, 0x7A, 0x00, 0x81, 0x00, 0x81, 0x00, 0x84, 0x00, 0x84, 0x00
	.byte 0x87, 0x00, 0x87, 0x00, 0x8A, 0x00, 0x8A, 0x00, 0x8D, 0x00, 0x8D, 0x00, 0x82, 0x00, 0x82, 0x00
	.byte 0x85, 0x00, 0x85, 0x00, 0x88, 0x00, 0x88, 0x00, 0x8B, 0x00, 0x8B, 0x00, 0x8E, 0x00, 0x8E, 0x00
	.byte 0x74, 0x00, 0x74, 0x00, 0xA2, 0x00, 0x21, 0x01, 0xA3, 0x00, 0x22, 0x01, 0xA4, 0x00, 0x23, 0x01
	.byte 0xA5, 0x00, 0x24, 0x01, 0xA6, 0x00, 0x25, 0x01, 0xA7, 0x00, 0x26, 0x01, 0xA8, 0x00, 0x27, 0x01
	.byte 0xA9, 0x00, 0x28, 0x01, 0xAA, 0x00, 0x29, 0x01, 0xAB, 0x00, 0x2A, 0x01, 0xE1, 0x00, 0xAB, 0x01
	.byte 0xE2, 0x00, 0xAC, 0x01, 0xE4, 0x00, 0xAE, 0x01, 0xF1, 0x00, 0xBE, 0x01, 0xE6, 0x00, 0xB0, 0x01
	.byte 0xE5, 0x00, 0xAF, 0x01, 0xEA, 0x00, 0xEA, 0x00, 0xEB, 0x00, 0xEB, 0x00, 0xE8, 0x00, 0xB2, 0x01
	.byte 0xE9, 0x00, 0xB3, 0x01, 0xEE, 0x00, 0xBB, 0x01, 0xEF, 0x00, 0xBC, 0x01, 0x12, 0x01, 0x12, 0x01
	.byte 0xE3, 0x00, 0xAD, 0x01, 0xF2, 0x00, 0x76, 0x01, 0xE7, 0x00, 0xB1, 0x01, 0xAC, 0x00, 0x2B, 0x01
	.byte 0xAD, 0x00, 0x2C, 0x01, 0xAE, 0x00, 0x2D, 0x01, 0xAF, 0x00, 0x2E, 0x01, 0xB0, 0x00, 0x2F, 0x01
	.byte 0xB1, 0x00, 0x30, 0x01, 0xB2, 0x00, 0x31, 0x01, 0xB3, 0x00, 0x32, 0x01, 0xB4, 0x00, 0x33, 0x01
	.byte 0xB5, 0x00, 0x34, 0x01, 0xB6, 0x00, 0x35, 0x01, 0xB7, 0x00, 0x36, 0x01, 0xB8, 0x00, 0x37, 0x01
	.byte 0xB9, 0x00, 0x38, 0x01, 0xBA, 0x00, 0x39, 0x01, 0xBB, 0x00, 0x3A, 0x01, 0xBC, 0x00, 0x3B, 0x01
	.byte 0xBD, 0x00, 0x3C, 0x01, 0xBE, 0x00, 0x3D, 0x01, 0xBF, 0x00, 0x3E, 0x01, 0xC0, 0x00, 0x3F, 0x01
	.byte 0xC1, 0x00, 0x40, 0x01, 0xC2, 0x00, 0x41, 0x01, 0xC3, 0x00, 0x42, 0x01, 0xC4, 0x00, 0x43, 0x01
	.byte 0xC5, 0x00, 0x44, 0x01, 0xC6, 0x00, 0x45, 0x01, 0xC7, 0x00, 0x46, 0x01, 0xC8, 0x00, 0x47, 0x01
	.byte 0xC9, 0x00, 0x48, 0x01, 0xCA, 0x00, 0x49, 0x01, 0xCB, 0x00, 0x4A, 0x01, 0xCC, 0x00, 0x4B, 0x01
	.byte 0xCD, 0x00, 0x4C, 0x01, 0xCE, 0x00, 0x4D, 0x01, 0xCF, 0x00, 0x4E, 0x01, 0xD0, 0x00, 0x4F, 0x01
	.byte 0xD1, 0x00, 0x50, 0x01, 0xD2, 0x00, 0x51, 0x01, 0xD3, 0x00, 0x52, 0x01, 0xD4, 0x00, 0x53, 0x01
	.byte 0xD5, 0x00, 0x54, 0x01, 0xD6, 0x00, 0x55, 0x01, 0xD7, 0x00, 0x56, 0x01, 0xD8, 0x00, 0x57, 0x01
	.byte 0xD9, 0x00, 0x58, 0x01, 0xDA, 0x00, 0x59, 0x01, 0xDB, 0x00, 0x5A, 0x01, 0xDC, 0x00, 0x5B, 0x01
	.byte 0xDD, 0x00, 0x5C, 0x01, 0xDE, 0x00, 0x5D, 0x01, 0xDF, 0x00, 0x5E, 0x01, 0x1F, 0x01, 0x1F, 0x01
	.byte 0xF6, 0x00, 0xC4, 0x01, 0x63, 0x01, 0x63, 0x01, 0x75, 0x01, 0x75, 0x01, 0x7B, 0x01, 0x7B, 0x01
	.byte 0x83, 0x01, 0x83, 0x01, 0x95, 0x01, 0x95, 0x01, 0x9B, 0x01, 0x9B, 0x01

	.data

ov74_0223BD5C: ; 0x0223BD5C
	.word 0x00150116 ; bitfield
	.word ov74_0223D090
	.word ov74_0223D080

ov74_0223BD68: ; 0x0223BD68
	.byte 0x00, 0x00, 0xFF, 0xFF, 0x21, 0x00, 0xE1, 0x00
	.byte 0x23, 0x00, 0xC0, 0x01, 0x25, 0x00, 0xD2, 0x01, 0x27, 0x00, 0xEA, 0x00, 0x28, 0x00, 0xEB, 0x00
	.byte 0x29, 0x00, 0xBF, 0x01, 0x2A, 0x00, 0xBD, 0x01, 0x2B, 0x00, 0xAD, 0x01, 0x2C, 0x00, 0xBE, 0x01
	.byte 0x2E, 0x00, 0xB1, 0x01, 0x30, 0x00, 0xA2, 0x00, 0x31, 0x00, 0xA3, 0x00, 0x32, 0x00, 0xA4, 0x00
	.byte 0x33, 0x00, 0xA5, 0x00, 0x34, 0x00, 0xA6, 0x00, 0x35, 0x00, 0xA7, 0x00, 0x36, 0x00, 0xA8, 0x00
	.byte 0x37, 0x00, 0xA9, 0x00, 0x38, 0x00, 0xAA, 0x00, 0x39, 0x00, 0xAB, 0x00, 0x3A, 0x00, 0xC4, 0x01
	.byte 0x3B, 0x00, 0xC5, 0x01, 0x3C, 0x00, 0xEC, 0x00, 0x3E, 0x00, 0xED, 0x00, 0x3F, 0x00, 0xAC, 0x01
	.byte 0x41, 0x00, 0xAC, 0x00, 0x42, 0x00, 0xAD, 0x00, 0x43, 0x00, 0xAE, 0x00, 0x44, 0x00, 0xAF, 0x00
	.byte 0x45, 0x00, 0xB0, 0x00, 0x46, 0x00, 0xB1, 0x00, 0x47, 0x00, 0xB2, 0x00, 0x48, 0x00, 0xB3, 0x00
	.byte 0x49, 0x00, 0xB4, 0x00, 0x4A, 0x00, 0xB5, 0x00, 0x4B, 0x00, 0xB6, 0x00, 0x4C, 0x00, 0xB7, 0x00
	.byte 0x4D, 0x00, 0xB8, 0x00, 0x4E, 0x00, 0xB9, 0x00, 0x4F, 0x00, 0xBA, 0x00, 0x50, 0x00, 0xBB, 0x00
	.byte 0x51, 0x00, 0xBC, 0x00, 0x52, 0x00, 0xBD, 0x00, 0x53, 0x00, 0xBE, 0x00, 0x54, 0x00, 0xBF, 0x00
	.byte 0x55, 0x00, 0xC0, 0x00, 0x56, 0x00, 0xC1, 0x00, 0x57, 0x00, 0xC2, 0x00, 0x58, 0x00, 0xC3, 0x00
	.byte 0x59, 0x00, 0xC4, 0x00, 0x5A, 0x00, 0xC5, 0x00, 0x61, 0x00, 0xC6, 0x00, 0x62, 0x00, 0xC7, 0x00
	.byte 0x63, 0x00, 0xC8, 0x00, 0x64, 0x00, 0xC9, 0x00, 0x65, 0x00, 0xCA, 0x00, 0x66, 0x00, 0xCB, 0x00
	.byte 0x67, 0x00, 0xCC, 0x00, 0x68, 0x00, 0xCD, 0x00, 0x69, 0x00, 0xCE, 0x00, 0x6A, 0x00, 0xCF, 0x00
	.byte 0x6B, 0x00, 0xD0, 0x00, 0x6C, 0x00, 0xD1, 0x00, 0x6D, 0x00, 0xD2, 0x00, 0x6E, 0x00, 0xD3, 0x00
	.byte 0x6F, 0x00, 0xD4, 0x00, 0x70, 0x00, 0xD5, 0x00, 0x71, 0x00, 0xD6, 0x00, 0x72, 0x00, 0xD7, 0x00
	.byte 0x73, 0x00, 0xD8, 0x00, 0x74, 0x00, 0xD9, 0x00, 0x75, 0x00, 0xDA, 0x00, 0x76, 0x00, 0xDB, 0x00
	.byte 0x77, 0x00, 0xDC, 0x00, 0x78, 0x00, 0xDD, 0x00, 0x79, 0x00, 0xDE, 0x00, 0x7A, 0x00, 0xDF, 0x00
	.byte 0x81, 0x00, 0x02, 0x00, 0x82, 0x00, 0x03, 0x00, 0x83, 0x00, 0x04, 0x00, 0x84, 0x00, 0x05, 0x00
	.byte 0x85, 0x00, 0x06, 0x00, 0x86, 0x00, 0x07, 0x00, 0x87, 0x00, 0x08, 0x00, 0x88, 0x00, 0x09, 0x00
	.byte 0x89, 0x00, 0x0A, 0x00, 0x8A, 0x00, 0x0B, 0x00, 0x8B, 0x00, 0x0C, 0x00, 0x8C, 0x00, 0x0D, 0x00
	.byte 0x8D, 0x00, 0x0E, 0x00, 0x8E, 0x00, 0x0F, 0x00, 0x8F, 0x00, 0x10, 0x00, 0x90, 0x00, 0x11, 0x00
	.byte 0x91, 0x00, 0x12, 0x00, 0x92, 0x00, 0x13, 0x00, 0x93, 0x00, 0x14, 0x00, 0x94, 0x00, 0x15, 0x00
	.byte 0x95, 0x00, 0x16, 0x00, 0x96, 0x00, 0x17, 0x00, 0x97, 0x00, 0x18, 0x00, 0x98, 0x00, 0x19, 0x00
	.byte 0x99, 0x00, 0x1A, 0x00, 0x9A, 0x00, 0x1B, 0x00, 0x9B, 0x00, 0x1C, 0x00, 0x9C, 0x00, 0x1D, 0x00
	.byte 0x9D, 0x00, 0x1E, 0x00, 0x9E, 0x00, 0x1F, 0x00, 0x9F, 0x00, 0x20, 0x00, 0xA0, 0x00, 0x21, 0x00
	.byte 0xA1, 0x00, 0x22, 0x00, 0xA2, 0x00, 0x23, 0x00, 0xA3, 0x00, 0x24, 0x00, 0xA4, 0x00, 0x25, 0x00
	.byte 0xA5, 0x00, 0x26, 0x00, 0xA6, 0x00, 0x27, 0x00, 0xA7, 0x00, 0x28, 0x00, 0xA8, 0x00, 0x29, 0x00
	.byte 0xA9, 0x00, 0x2A, 0x00, 0xAA, 0x00, 0x2B, 0x00, 0xAB, 0x00, 0x2C, 0x00, 0xAC, 0x00, 0x2D, 0x00
	.byte 0xAD, 0x00, 0x2E, 0x00, 0xAE, 0x00, 0x2F, 0x00, 0xAF, 0x00, 0x30, 0x00, 0xB0, 0x00, 0x31, 0x00
	.byte 0xB1, 0x00, 0x32, 0x00, 0xB2, 0x00, 0x33, 0x00, 0xB3, 0x00, 0x34, 0x00, 0xB4, 0x00, 0x35, 0x00
	.byte 0xB5, 0x00, 0x36, 0x00, 0xB6, 0x00, 0x37, 0x00, 0xB7, 0x00, 0x38, 0x00, 0xB8, 0x00, 0x39, 0x00
	.byte 0xB9, 0x00, 0x3A, 0x00, 0xBA, 0x00, 0x3B, 0x00, 0xBB, 0x00, 0x3C, 0x00, 0xBC, 0x00, 0x3D, 0x00
	.byte 0xBD, 0x00, 0x3E, 0x00, 0xBE, 0x00, 0x3F, 0x00, 0xBF, 0x00, 0x40, 0x00, 0xC0, 0x00, 0x41, 0x00
	.byte 0xC1, 0x00, 0x42, 0x00, 0xC2, 0x00, 0x43, 0x00, 0xC3, 0x00, 0x44, 0x00, 0xC4, 0x00, 0x45, 0x00
	.byte 0xC5, 0x00, 0x46, 0x00, 0xC6, 0x00, 0x47, 0x00, 0xC7, 0x00, 0x48, 0x00, 0xC8, 0x00, 0x49, 0x00
	.byte 0xC9, 0x00, 0x4A, 0x00, 0xCA, 0x00, 0x4B, 0x00, 0xCB, 0x00, 0x4C, 0x00, 0xCC, 0x00, 0x4D, 0x00
	.byte 0xCD, 0x00, 0x4E, 0x00, 0xCF, 0x00, 0x4F, 0x00, 0xD2, 0x00, 0x50, 0x00, 0xD3, 0x00, 0x51, 0x00
	.byte 0xE1, 0x00, 0x52, 0x00, 0xE2, 0x00, 0x53, 0x00, 0xE3, 0x00, 0x54, 0x00, 0xE4, 0x00, 0x55, 0x00
	.byte 0xE5, 0x00, 0x56, 0x00, 0xE6, 0x00, 0x57, 0x00, 0xE7, 0x00, 0x58, 0x00, 0xE8, 0x00, 0x59, 0x00
	.byte 0xE9, 0x00, 0x5A, 0x00, 0xEA, 0x00, 0x5B, 0x00, 0xEB, 0x00, 0x5C, 0x00, 0xEC, 0x00, 0x5D, 0x00
	.byte 0xED, 0x00, 0x5E, 0x00, 0xEE, 0x00, 0x5F, 0x00, 0xEF, 0x00, 0x60, 0x00, 0xF0, 0x00, 0x61, 0x00
	.byte 0xF1, 0x00, 0x62, 0x00, 0xF2, 0x00, 0x63, 0x00, 0xF3, 0x00, 0x64, 0x00, 0xF4, 0x00, 0x65, 0x00
	.byte 0xF5, 0x00, 0x66, 0x00, 0xF6, 0x00, 0x67, 0x00, 0xF7, 0x00, 0x68, 0x00, 0xF8, 0x00, 0x69, 0x00
	.byte 0xF9, 0x00, 0x6A, 0x00, 0xFA, 0x00, 0x6B, 0x00, 0xFB, 0x00, 0x6C, 0x00, 0xFC, 0x00, 0x6D, 0x00
	.byte 0xFD, 0x00, 0x6E, 0x00, 0xFE, 0x00, 0x6F, 0x00, 0xFF, 0x00, 0x70, 0x00, 0x00, 0x01, 0x71, 0x00
	.byte 0x01, 0x01, 0x72, 0x00, 0x02, 0x01, 0x73, 0x00, 0x03, 0x01, 0x74, 0x00, 0x04, 0x01, 0x75, 0x00
	.byte 0x05, 0x01, 0x76, 0x00, 0x06, 0x01, 0x77, 0x00, 0x07, 0x01, 0x78, 0x00, 0x08, 0x01, 0x79, 0x00
	.byte 0x09, 0x01, 0x7A, 0x00, 0x0A, 0x01, 0x7B, 0x00, 0x0B, 0x01, 0x7C, 0x00, 0x0C, 0x01, 0x7D, 0x00
	.byte 0x0D, 0x01, 0x7E, 0x00, 0x0E, 0x01, 0x7F, 0x00, 0x0F, 0x01, 0x80, 0x00, 0x10, 0x01, 0x81, 0x00
	.byte 0x11, 0x01, 0x82, 0x00, 0x12, 0x01, 0x83, 0x00, 0x13, 0x01, 0x84, 0x00, 0x14, 0x01, 0x85, 0x00
	.byte 0x15, 0x01, 0x86, 0x00, 0x16, 0x01, 0x87, 0x00, 0x17, 0x01, 0x88, 0x00, 0x18, 0x01, 0x89, 0x00
	.byte 0x19, 0x01, 0x8A, 0x00, 0x1A, 0x01, 0x8B, 0x00, 0x1B, 0x01, 0x8C, 0x00, 0x1C, 0x01, 0x8D, 0x00
	.byte 0x1D, 0x01, 0x8E, 0x00, 0x1E, 0x01, 0x8F, 0x00, 0x1F, 0x01, 0x90, 0x00, 0x20, 0x01, 0x91, 0x00
	.byte 0x21, 0x01, 0x92, 0x00, 0x22, 0x01, 0x93, 0x00, 0x23, 0x01, 0x94, 0x00, 0x24, 0x01, 0x95, 0x00
	.byte 0x25, 0x01, 0x96, 0x00, 0x26, 0x01, 0x97, 0x00, 0x27, 0x01, 0x98, 0x00, 0x28, 0x01, 0x99, 0x00
	.byte 0x29, 0x01, 0x9A, 0x00, 0x2A, 0x01, 0x9B, 0x00, 0x2B, 0x01, 0x9C, 0x00, 0x2C, 0x01, 0x9D, 0x00
	.byte 0x2D, 0x01, 0x9E, 0x00, 0x2F, 0x01, 0x9F, 0x00, 0x32, 0x01, 0xA0, 0x00, 0x33, 0x01, 0xA1, 0x00
	.byte 0x40, 0x01, 0xEA, 0x00, 0x41, 0x01, 0xEB, 0x00, 0x42, 0x01, 0xE8, 0x00, 0x43, 0x01, 0xE9, 0x00
	.byte 0x46, 0x01, 0xE6, 0x00, 0x47, 0x01, 0xE5, 0x00, 0x48, 0x01, 0xEE, 0x00, 0x49, 0x01, 0xEF, 0x00
	.byte 0x4A, 0x01, 0xE4, 0x00, 0x4B, 0x01, 0x12, 0x01, 0x4D, 0x01, 0x1C, 0x01, 0x4E, 0x01, 0x1E, 0x01
	.byte 0x4F, 0x01, 0x1D, 0x01, 0x50, 0x01, 0x1B, 0x01, 0x7C, 0x01, 0x9F, 0x01, 0x7D, 0x01, 0xA0, 0x01
	.byte 0x80, 0x01, 0x5F, 0x01, 0x81, 0x01, 0x60, 0x01, 0x82, 0x01, 0x61, 0x01, 0x84, 0x01, 0x63, 0x01
	.byte 0x87, 0x01, 0x66, 0x01, 0x89, 0x01, 0x68, 0x01, 0x8A, 0x01, 0x69, 0x01, 0x8B, 0x01, 0x6A, 0x01
	.byte 0x8C, 0x01, 0x6B, 0x01, 0x8D, 0x01, 0x6C, 0x01, 0x8E, 0x01, 0x6D, 0x01, 0x8F, 0x01, 0x6E, 0x01
	.byte 0x93, 0x01, 0x72, 0x01, 0x94, 0x01, 0x73, 0x01, 0x96, 0x01, 0x75, 0x01, 0x9A, 0x01, 0x79, 0x01
	.byte 0x9B, 0x01, 0x7A, 0x01, 0x9C, 0x01, 0x7B, 0x01, 0x9F, 0x01, 0x7E, 0x01, 0xA0, 0x01, 0x7F, 0x01
	.byte 0xA1, 0x01, 0x80, 0x01, 0xA2, 0x01, 0x81, 0x01, 0xA4, 0x01, 0x83, 0x01, 0xA7, 0x01, 0x86, 0x01
	.byte 0xA9, 0x01, 0x88, 0x01, 0xAA, 0x01, 0x89, 0x01, 0xAB, 0x01, 0x8A, 0x01, 0xAC, 0x01, 0x8B, 0x01
	.byte 0xAD, 0x01, 0x8C, 0x01, 0xAE, 0x01, 0x8D, 0x01, 0xAF, 0x01, 0x8E, 0x01, 0xB3, 0x01, 0x92, 0x01
	.byte 0xB4, 0x01, 0x93, 0x01, 0xB6, 0x01, 0x95, 0x01, 0xBA, 0x01, 0x99, 0x01, 0xBB, 0x01, 0x9A, 0x01
	.byte 0xBC, 0x01, 0x9B, 0x01

ov74_0223C1F4: ; 0x0223C1F4
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov74_0223C220: ; 0x0223C220
	.word 0x00000012, ov74_0222A560
	.word 0x00000013, ov74_0222A2A4

ov74_0223C230: ; 0x0223C230
	.word 0x00000012, ov74_0222A4CC
	.word 0x00000013, ov74_0222A2A4

ov74_0223C240: ; 0x0223C240
	.word 0x00000012, ov74_0222A504
	.word 0x00000013, ov74_0222A538

ov74_0223C250: ; 0x0223C250
	.word 0x00000012, ov74_02229F90
	.word 0x00000013, ov74_0222A2A4

ov74_0223C260: ; 0x0223C260
	.word 0x00000012, ov74_02229FF4
	.word 0x00000013, ov74_0222A494

ov74_0223C270: ; 0x0223C270
	.word 0
	.word ov74_02235FF8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x03, 0x00, 0x00, 0x0C, 0x00, 0x10, 0x2F, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00
	.word msg_0247_00012, ov74_0222A5CC
	.word msg_0247_00013, ov74_0222A650

ov74_0223C2A0: ; 0x0223C2A0
	.word msg_0247_00021, ov74_0222A688
	.word msg_0247_00014, ov74_0222A6C0

ov74_0223C2B0: ; 0x0223C2B0
	.word msg_0247_00015, ov74_0222A2E0
	.word msg_0247_00020, ov74_0222A3CC
	.word msg_0247_00016, ov74_0222A35C
	.word msg_0247_00017, ov74_0222A5AC

ov74_0223C2D0: ; 0x0223C2D0
	.word msg_0247_00065, ov74_0222D358
	.word msg_0247_00066, ov74_0222D414

ov74_0223C2E0: ; 0x0223C2E0
	.word msg_0247_00065, 16
	.word msg_0247_00066, ov74_0222D414

ov74_0223C2F0: ; 0x0223C2F0
	.word msg_0247_00065, 15
	.word msg_0247_00066, ov74_0222D414
	.word msg_0247_00043, 6
	.word msg_0247_00044, ov74_0222D2D4
	.word msg_0247_00045, ov74_0222D308
	.word msg_0247_00046, 11

ov74_0223C320: ; 0x0223C320
	.word 0
	.word ov74_02235FF8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x04, 0x00, 0x00, 0x0C, 0x00, 0x10, 0x2F, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00

ov74_0223C340: ; 0x0223C340
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x25, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x29, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222D4E4
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222D494
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x32, 0x00, 0x00, 0x00
	.word ov74_0222D55C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x0A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222D5C4
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x2A, 0x00, 0x00, 0x00
	.word ov74_0222D614
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x0F, 0x00, 0x00, 0x00
	.byte 0x25, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x08, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222D690
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222D774
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222D78C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0E, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x35, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0E, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x38, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0E, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x3A, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0E, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x3B, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x39, 0x00, 0x00, 0x00
	.word ov74_0222D7D0
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00
	.byte 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x0E, 0x00, 0x00, 0x00
	.byte 0x3C, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x0E, 0x00, 0x00, 0x00
	.byte 0x3D, 0x00, 0x00, 0x00
	.word ov74_0222D490
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov74_0223C6D0: ; 0x0223C6D0
	.byte 0x2B, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00

ov74_0223C6E0: ; 0x0223C6E0
	.word 0
	.word ov74_02235FF8
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x04, 0x00, 0x00, 0x0C, 0x00, 0x10, 0x2F, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00

ov74_0223C700: ; 0x0223C700
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x25, 0x00, 0x00, 0x00
	.word ov74_0222EE08
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x29, 0x00, 0x00, 0x00
	.word ov74_0222EE08
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222EE58
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0F, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222EE0C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x32, 0x00, 0x00, 0x00
	.word ov74_0222EEB0
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x0A, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222EF18
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0x2A, 0x00, 0x00, 0x00
	.word ov74_0222EF64
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x0F, 0x00, 0x00, 0x00
	.byte 0x25, 0x00, 0x00, 0x00
	.word ov74_0222EE08
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.word ov74_0222EF68
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x01, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.public ov74_0223C920
ov74_0223C920: ; 0x0223C920
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x01, 0x40, 0x00, 0x00, 0x00, 0x01, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov74_0223C960: ; 0x0223C960
	.byte 0x00, 0x02, 0x01, 0x03, 0x04, 0x05, 0x00, 0x00

ov74_0223C968: ; 0x0223C968
	.byte 0x00, 0x00, 0x00, 0x00
#ifdef HEARTGOLD
	.byte 0x14, 0x00, 0x00, 0x00
	.byte 0x12, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00
#else
	.byte 0x15, 0x00, 0x00, 0x00
	.byte 0x13, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00
#endif

ov74_0223C980: ; 0x0223C980
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00

ov74_0223C998: ; 0x0223C998
	.byte 0x0F, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00
	.byte 0x39, 0x00, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00

ov74_0223C9A8: ; 0x0223C9A8
	.byte 0x94, 0x00, 0x00, 0x00, 0xF9, 0x00, 0x00, 0x00
	.byte 0x7F, 0x00, 0x00, 0x00, 0x23, 0x01, 0x00, 0x00

ov74_0223C9B8: ; 0x0223C9B8
	.byte 0x00, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00
	.byte 0x1F, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x07, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00

ov74_0223C9D8: ; 0x0223C9D8
	.byte 0x05, 0x00, 0x34, 0x00, 0x35, 0x00, 0x36, 0x00
	.byte 0x37, 0x00, 0x38, 0x00, 0x39, 0x00, 0x3A, 0x00, 0x3B, 0x00, 0x3C, 0x00, 0x3D, 0x00, 0x3E, 0x00
	.byte 0x48, 0x00, 0x52, 0x00, 0x57, 0x00, 0x58, 0x00, 0x59, 0x00, 0x5A, 0x00, 0x5B, 0x00, 0x5C, 0x00
	.byte 0x63, 0x00, 0x64, 0x00, 0x65, 0x00, 0x66, 0x00, 0x69, 0x00, 0x70, 0x00, 0x71, 0x00, 0x72, 0x00
	.byte 0x73, 0x00, 0x74, 0x00, 0x75, 0x00, 0x76, 0x00, 0x77, 0x00, 0x78, 0x00, 0x79, 0x00, 0x7A, 0x00
	.byte 0x7B, 0x00, 0x7C, 0x00, 0x7D, 0x00, 0x7E, 0x00, 0x7F, 0x00, 0x80, 0x00, 0x81, 0x00, 0x82, 0x00
	.byte 0x83, 0x00, 0x84, 0x00, 0xB0, 0x00, 0xB1, 0x00, 0xB2, 0x00, 0xE2, 0x00, 0xE3, 0x00, 0xE4, 0x00
	.byte 0xE5, 0x00, 0xE6, 0x00, 0xE7, 0x00, 0xE8, 0x00, 0xE9, 0x00, 0xEA, 0x00, 0xEB, 0x00, 0xEC, 0x00
	.byte 0xED, 0x00, 0xEE, 0x00, 0xEF, 0x00, 0xF0, 0x00, 0xF1, 0x00, 0xF2, 0x00, 0xF3, 0x00, 0xF4, 0x00
	.byte 0xF5, 0x00, 0xF6, 0x00, 0xF7, 0x00, 0xF8, 0x00, 0xF9, 0x00, 0xFA, 0x00, 0xFB, 0x00, 0xFC, 0x00
	.byte 0xFD, 0x00, 0x03, 0x01, 0x04, 0x01, 0x05, 0x01, 0x06, 0x01, 0x07, 0x01, 0x08, 0x01, 0x09, 0x01
	.byte 0x0A, 0x01, 0x0B, 0x01, 0x0C, 0x01, 0x0D, 0x01, 0x0E, 0x01, 0x0F, 0x01, 0x10, 0x01, 0x11, 0x01
	.byte 0x12, 0x01, 0x13, 0x01, 0x14, 0x01, 0x15, 0x01, 0x16, 0x01, 0x17, 0x01, 0x18, 0x01, 0x19, 0x01
	.byte 0x1A, 0x01, 0x1B, 0x01, 0x1C, 0x01, 0x1D, 0x01, 0x1E, 0x01, 0x1F, 0x01, 0x20, 0x01, 0x53, 0x01
	.byte 0x54, 0x01, 0x55, 0x01, 0x56, 0x01, 0x57, 0x01, 0x58, 0x01, 0x59, 0x01, 0x5A, 0x01, 0x5B, 0x01
	.byte 0x5C, 0x01, 0x5D, 0x01, 0x5E, 0x01, 0x5F, 0x01, 0x60, 0x01, 0x61, 0x01, 0x62, 0x01, 0x63, 0x01
	.byte 0x64, 0x01, 0x65, 0x01, 0x66, 0x01, 0x67, 0x01, 0x68, 0x01, 0x69, 0x01, 0x6A, 0x01, 0x6B, 0x01
	.byte 0x6C, 0x01, 0x6D, 0x01, 0x6E, 0x01, 0x6F, 0x01, 0x70, 0x01, 0x71, 0x01, 0x72, 0x01, 0x73, 0x01
	.byte 0x74, 0x01, 0x75, 0x01, 0x76, 0x01, 0x77, 0x01, 0x78, 0x01, 0x00, 0x00

sPmAgbCartridgeSpec: ; 0x0223CAFC
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0xFF, 0xFF, 0xFF, 0xFF

sAgbCartNintendoLogo: ; 0x0223CB04
	.byte 0x24, 0xFF, 0xAE, 0x51, 0x69, 0x9A, 0xA2, 0x21, 0x3D, 0x84, 0x82, 0x0A
	.byte 0x84, 0xE4, 0x09, 0xAD, 0x11, 0x24, 0x8B, 0x98, 0xC0, 0x81, 0x7F, 0x21, 0xA3, 0x52, 0xBE, 0x19
	.byte 0x93, 0x09, 0xCE, 0x20, 0x10, 0x46, 0x4A, 0x4A, 0xF8, 0x27, 0x31, 0xEC, 0x58, 0xC7, 0xE8, 0x33
	.byte 0x82, 0xE3, 0xCE, 0xBF, 0x85, 0xF4, 0xDF, 0x94, 0xCE, 0x4B, 0x09, 0xC1, 0x94, 0x56, 0x8A, 0xC0
	.byte 0x13, 0x72, 0xA7, 0xFC, 0x9F, 0x84, 0x4D, 0x73, 0xA3, 0xCA, 0x9A, 0x61, 0x58, 0x97, 0xA3, 0x27
	.byte 0xFC, 0x03, 0x98, 0x76, 0x23, 0x1D, 0xC7, 0x61, 0x03, 0x04, 0xAE, 0x56, 0xBF, 0x38, 0x84, 0x00
	.byte 0x40, 0xA7, 0x0E, 0xFD, 0xFF, 0x52, 0xFE, 0x03, 0x6F, 0x95, 0x30, 0xF1, 0x97, 0xFB, 0xC0, 0x85
	.byte 0x60, 0xD6, 0x80, 0x25, 0xA9, 0x63, 0xBE, 0x03, 0x01, 0x4E, 0x38, 0xE2, 0xF9, 0xA2, 0x34, 0xFF
	.byte 0xBB, 0x3E, 0x03, 0x44, 0x78, 0x00, 0x90, 0xCB, 0x88, 0x11, 0x3A, 0x94, 0x65, 0xC0, 0x7C, 0x63
	.byte 0x87, 0xF0, 0x3C, 0xAF, 0xD6, 0x25, 0xE4, 0x8B, 0x38, 0x0A, 0xAC, 0x72, 0x21, 0xD4, 0xF8, 0x07

ov74_0223CBA0: ; 0x0223CBA0
	.byte 0x10, 0x00, 0x11, 0x00, 0x12, 0x00, 0x1D, 0x00, 0x1E, 0x00, 0x1F, 0x00, 0x20, 0x00, 0x21, 0x00
	.byte 0x22, 0x00, 0x23, 0x00, 0x24, 0x00, 0x2E, 0x00, 0x2F, 0x00, 0x30, 0x00, 0x31, 0x00, 0x34, 0x00
	.byte 0x35, 0x00, 0x38, 0x00, 0x39, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x56, 0x00, 0x57, 0x00
	.byte 0x5A, 0x00, 0x5B, 0x00, 0x60, 0x00, 0x61, 0x00, 0x6A, 0x00, 0x6B, 0x00, 0x72, 0x00, 0x73, 0x00
	.byte 0x74, 0x00, 0x75, 0x00, 0x7A, 0x00, 0x7B, 0x00, 0x7C, 0x00, 0x7F, 0x00, 0x80, 0x00, 0x85, 0x00
	.byte 0x86, 0x00, 0x87, 0x00, 0x88, 0x00, 0x89, 0x00, 0xAD, 0x00, 0xBB, 0x00, 0xBC, 0x00, 0xBD, 0x00
	.byte 0xBF, 0x00, 0xC0, 0x00, 0xC4, 0x00, 0xC5, 0x00, 0xC6, 0x00, 0xD2, 0x00, 0xD4, 0x00, 0xD5, 0x00
	.byte 0xD8, 0x00, 0xD9, 0x00, 0xDC, 0x00, 0xDD, 0x00, 0xDF, 0x00, 0xE0, 0x00, 0xE6, 0x00, 0xE9, 0x00
	.byte 0xEA, 0x00, 0xEB, 0x00, 0xEC, 0x00, 0xED, 0x00, 0xEE, 0x00, 0xF1, 0x00, 0x05, 0x01, 0x06, 0x01
	.byte 0x07, 0x01, 0x08, 0x01, 0x1D, 0x01, 0x1E, 0x01, 0x2C, 0x01, 0x2D, 0x01, 0x2E, 0x01, 0x3A, 0x01
	.byte 0x42, 0x01, 0x43, 0x01, 0x47, 0x01, 0x53, 0x01, 0x54, 0x01, 0x61, 0x01, 0x62, 0x01, 0x65, 0x01
	.byte 0x67, 0x01, 0x69, 0x01, 0x6A, 0x01, 0x6B, 0x01, 0x6C, 0x01, 0x6D, 0x01

ov74_0223CC5C: ; 0x0223CC5C
	.byte 0x15, 0x01

ov74_0223CC5E: ; 0x0223CC5E
	.byte 0xFC, 0x00
	.byte 0x16, 0x01, 0xFD, 0x00, 0x17, 0x01, 0xFE, 0x00, 0x18, 0x01, 0xFF, 0x00, 0x19, 0x01, 0x00, 0x01
	.byte 0x1A, 0x01, 0x01, 0x01, 0x1B, 0x01, 0x02, 0x01, 0x1C, 0x01, 0x03, 0x01, 0x1D, 0x01, 0x04, 0x01
	.byte 0x1E, 0x01, 0x05, 0x01, 0x1F, 0x01, 0x06, 0x01, 0x20, 0x01, 0x07, 0x01, 0x21, 0x01, 0x08, 0x01
	.byte 0x22, 0x01, 0x09, 0x01, 0x23, 0x01, 0x0A, 0x01, 0x24, 0x01, 0x0B, 0x01, 0x25, 0x01, 0x0C, 0x01
	.byte 0x26, 0x01, 0x0D, 0x01, 0x27, 0x01, 0x0E, 0x01, 0x28, 0x01, 0x0F, 0x01, 0x29, 0x01, 0x10, 0x01
	.byte 0x2A, 0x01, 0x11, 0x01, 0x2B, 0x01, 0x12, 0x01, 0x2C, 0x01, 0x13, 0x01, 0x2D, 0x01, 0x22, 0x01
	.byte 0x2E, 0x01, 0x23, 0x01, 0x2F, 0x01, 0x24, 0x01, 0x30, 0x01, 0x14, 0x01, 0x31, 0x01, 0x15, 0x01
	.byte 0x32, 0x01, 0x1D, 0x01, 0x33, 0x01, 0x1E, 0x01, 0x34, 0x01, 0x47, 0x01, 0x35, 0x01, 0x16, 0x01
	.byte 0x36, 0x01, 0x17, 0x01, 0x37, 0x01, 0x1B, 0x01, 0x38, 0x01, 0x1C, 0x01, 0x39, 0x01, 0x40, 0x01
	.byte 0x3A, 0x01, 0x41, 0x01, 0x3B, 0x01, 0x2C, 0x01, 0x3C, 0x01, 0x2D, 0x01, 0x3D, 0x01, 0x60, 0x01
	.byte 0x3E, 0x01, 0x57, 0x01, 0x3F, 0x01, 0x58, 0x01, 0x40, 0x01, 0x2B, 0x01, 0x41, 0x01, 0x44, 0x01
	.byte 0x42, 0x01, 0x2E, 0x01, 0x43, 0x01, 0x53, 0x01, 0x44, 0x01, 0x54, 0x01, 0x45, 0x01, 0x72, 0x01
	.byte 0x46, 0x01, 0x55, 0x01, 0x47, 0x01, 0x56, 0x01, 0x48, 0x01, 0x5D, 0x01, 0x49, 0x01, 0x5E, 0x01
	.byte 0x4A, 0x01, 0x3E, 0x01, 0x4B, 0x01, 0x3F, 0x01, 0x4C, 0x01, 0x48, 0x01, 0x4D, 0x01, 0x49, 0x01
	.byte 0x4E, 0x01, 0x4A, 0x01, 0x4F, 0x01, 0x28, 0x01, 0x50, 0x01, 0x29, 0x01, 0x51, 0x01, 0x35, 0x01
	.byte 0x52, 0x01, 0x36, 0x01, 0x53, 0x01, 0x42, 0x01, 0x54, 0x01, 0x43, 0x01, 0x55, 0x01, 0x6B, 0x01
	.byte 0x56, 0x01, 0x6C, 0x01, 0x57, 0x01, 0x6D, 0x01, 0x58, 0x01, 0x4B, 0x01, 0x59, 0x01, 0x4C, 0x01
	.byte 0x5A, 0x01, 0x69, 0x01, 0x5B, 0x01, 0x6A, 0x01, 0x5C, 0x01, 0x51, 0x01, 0x5D, 0x01, 0x52, 0x01
	.byte 0x5E, 0x01, 0x2A, 0x01, 0x5F, 0x01, 0x45, 0x01, 0x60, 0x01, 0x46, 0x01, 0x61, 0x01, 0x37, 0x01
	.byte 0x62, 0x01, 0x38, 0x01, 0x63, 0x01, 0x2F, 0x01, 0x64, 0x01, 0x33, 0x01, 0x65, 0x01, 0x34, 0x01
	.byte 0x66, 0x01, 0x4D, 0x01, 0x67, 0x01, 0x4E, 0x01, 0x68, 0x01, 0x68, 0x01, 0x69, 0x01, 0x63, 0x01
	.byte 0x6A, 0x01, 0x64, 0x01, 0x6B, 0x01, 0x3B, 0x01, 0x6C, 0x01, 0x1F, 0x01, 0x6D, 0x01, 0x20, 0x01
	.byte 0x6E, 0x01, 0x21, 0x01, 0x6F, 0x01, 0x3C, 0x01, 0x70, 0x01, 0x3D, 0x01, 0x71, 0x01, 0x65, 0x01
	.byte 0x72, 0x01, 0x25, 0x01, 0x73, 0x01, 0x26, 0x01, 0x74, 0x01, 0x27, 0x01, 0x75, 0x01, 0x6E, 0x01
	.byte 0x76, 0x01, 0x6F, 0x01, 0x77, 0x01, 0x70, 0x01, 0x78, 0x01, 0x67, 0x01, 0x79, 0x01, 0x61, 0x01
	.byte 0x7A, 0x01, 0x62, 0x01, 0x7B, 0x01, 0x50, 0x01, 0x7C, 0x01, 0x4F, 0x01, 0x7D, 0x01, 0x71, 0x01
	.byte 0x7E, 0x01, 0x30, 0x01, 0x7F, 0x01, 0x31, 0x01, 0x80, 0x01, 0x32, 0x01, 0x81, 0x01, 0x5F, 0x01
	.byte 0x82, 0x01, 0x39, 0x01, 0x83, 0x01, 0x3A, 0x01, 0x84, 0x01, 0x59, 0x01, 0x85, 0x01, 0x5A, 0x01
	.byte 0x86, 0x01, 0x5B, 0x01, 0x87, 0x01, 0x5C, 0x01, 0x88, 0x01, 0x18, 0x01, 0x89, 0x01, 0x19, 0x01
	.byte 0x8A, 0x01, 0x1A, 0x01, 0x8B, 0x01, 0x73, 0x01, 0x8C, 0x01, 0x74, 0x01, 0x8D, 0x01, 0x75, 0x01
	.byte 0x8E, 0x01, 0x76, 0x01, 0x8F, 0x01, 0x77, 0x01, 0x90, 0x01, 0x78, 0x01, 0x91, 0x01, 0x79, 0x01
	.byte 0x92, 0x01, 0x7A, 0x01, 0x93, 0x01, 0x7B, 0x01, 0x94, 0x01, 0x7E, 0x01, 0x95, 0x01, 0x7F, 0x01
	.byte 0x96, 0x01, 0x80, 0x01, 0x97, 0x01, 0x7C, 0x01, 0x98, 0x01, 0x7D, 0x01, 0x99, 0x01, 0x81, 0x01
	.byte 0x9A, 0x01, 0x82, 0x01, 0x9B, 0x01, 0x66, 0x01, 0x9C, 0x01, 0x9C, 0x01, 0x9D, 0x01, 0x9D, 0x01
	.byte 0x9E, 0x01, 0x9E, 0x01, 0x9F, 0x01, 0x9F, 0x01, 0xA0, 0x01, 0xA0, 0x01, 0xA1, 0x01, 0xA1, 0x01
	.byte 0xA2, 0x01, 0xA2, 0x01, 0xA3, 0x01, 0xA3, 0x01, 0xA4, 0x01, 0xA4, 0x01

ov74_0223CE9C: ; 0x0223CE9C
	.ascii "EB5B"
	.ascii "EC5B"
	.ascii "ED5B"
	.ascii "EE5B"
	.ascii "EF5B"
	.ascii "EG5B"
	.ascii "EH5B"
	.ascii "EI5B"
	.ascii "EJ5B"
	.ascii "EK5B"
	.ascii "EL5B"
	.ascii "EM5B"
	.ascii "EP5B"
	.ascii "EQ5B"
	.ascii "ER5B"
	.ascii "ES5B"
	.ascii "ET5B"
	.ascii "EU5B"
	.ascii "EV5B"
	.ascii "EW5B"
	.ascii "\x00\x00\x00\x00"
ov74_0223CEF0:
	.asciz "mywh_SYSSTATE_IDLE"
	.balign 4, 0
ov74_0223CF04:
	.asciz "mywh_SYSSTATE_BUSY"
	.balign 4, 0
ov74_0223CF18:
	.asciz "mywh_SYSSTATE_STOP"
	.balign 4, 0
ov74_0223CF2C:
	.asciz "mywh_SYSSTATE_ERROR"
	.balign 4, 0
ov74_0223CF40:
	.asciz "mywh_SYSSTATE_SCANNING"
	.balign 4, 0
ov74_0223CF58:
	.asciz "mywh_SYSSTATE_CONNECTED"
	.balign 4, 0
ov74_0223CF70:
	.asciz "mywh_SYSSTATE_KEYSHARING"
	.balign 4, 0
ov74_0223CF8C:
	.asciz "mywh_SYSSTATE_DATASHARING"
	.balign 4, 0
ov74_0223CFA8:
	.asciz "mywh_SYSSTATE_CONNECT_FAIL"
	.balign 4, 0
ov74_0223CFC4:
	.asciz "mywh_SYSSTATE_MEASURECHANNEL"
	.balign 4, 0

ov74_0223CFE4: ; 0x0223CFE4
	.word ov74_0223CF18
	.word ov74_0223CEF0
	.word ov74_0223CF40
	.word ov74_0223CF04
	.word ov74_0223CF58
	.word ov74_0223CF8C
	.word ov74_0223CF70
	.word ov74_0223CFC4
	.word ov74_0223CFA8
	.word ov74_0223CF2C

ov74_0223D00C: ; 0x0223D00C
	.asciz "%s -> "
	.balign 4, 0

ov74_0223D014: ; 0x0223D014
	.asciz "%s\n"
	.balign 4, 0

ov74_0223D018: ; 0x0223D018
	.asciz "not my parent ggid (%d != %d)\n"
	.balign 4, 0

ov74_0223D038: ; 0x0223D038
	.asciz "IPGE"
	.balign 4, 0

ov74_0223D040: ; 0x0223D040
	.asciz "K5WfPEw9T3cvqzHa"
	.balign 4, 0

ov74_0223D054: ; 0x0223D054
	.byte 0x00, 0x00, 0x00, 0x00

	.bss

ov74_0223D080:
	.space 0x10

ov74_0223D090: ; 0x0223D090
	.space 0x14

ov74_0223D0A4: ; 0x0223D0A4
	.space 0x4

ov74_0223D0A8: ; 0x0223D0A8
	.space 0x14

ov74_0223D0BC: ; 0x0223D0BC
	.space 0x4

ov74_0223D0C0: ; 0x0223D0C0
	.space 0x4

	.public ov74_0223D0C4
ov74_0223D0C4: ; 0x0223D0C4
	.space 0x274

ov74_0223D338: ; 0x0223D338
	.space 0x4

ov74_0223D33C: ; 0x0223D33C
	.space 0x10

ov74_0223D34C: ; 0x0223D34C
	.space 0x8

sPmAgbRomHeader: ; 0x0223D354
	.space 0xFC

ov74_0223D450: ; 0x0223D450
	.space 0x4

ov74_0223D454: ; 0x0223D454
	.space 0x34

ov74_0223D488: ; 0x0223D488
	.space 0x4

ov74_0223D48C: ; 0x0223D48C
	.space 0x1C8

ov74_0223D654: ; 0x0223D654
	.space 0xC80

ov74_0223E2D4: ; 0x0223E2D4
	.space 0x28

ov74_0223E2FC: ; 0x0223E2FC
	.space 0x8

ov74_0223E304: ; 0x0223E304
	.space 0x14

ov74_0223E318: ; 0x0223E318
	.space 0x6e0
