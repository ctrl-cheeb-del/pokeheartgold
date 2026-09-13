#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FD788
	.public ov15_021FD7D0
	.public ov15_021FD810
	.public ov15_021FD850
	.public ov15_021FD93C
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
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
	.extern ov15_021FDAD0
	.extern ov15_021FDAF4
	.extern ov15_021FDD70
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

	thumb_func_start ov15_021FD788
ov15_021FD788: ; 0x021FD788
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #1
	bne _021FD7C0
	mov r1, #1
	bl ov15_022004DC
	add r0, r4, #0
	mov r1, #0
	bl ov15_021FF29C
	add r0, r4, #0
	add r0, #0x74
	bl ScheduleWindowCopyToVram
	mov r0, #0xa7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl ManagedSprite_SetAnimationFrame
	mov r0, #0xa7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x10
	bl ManagedSprite_SetAnim
	pop {r4, pc}
_021FD7C0:
	mov r1, #0
	bl ov15_022004DC
	add r0, r4, #0
	bl ov15_021FF844
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov15_021FD788


	thumb_func_start ov15_021FD7D0
ov15_021FD7D0: ; 0x021FD7D0
	push {r4, r5}
	mov r4, #0x25
	lsl r4, r4, #6
	add r0, r0, r4
	mov r4, #0
	strb r4, [r0, #2]
	strb r1, [r0]
	ldrb r5, [r0, #1]
	mov r4, #0xf
	mov r1, #0xf
	and r1, r2
	bic r5, r4
	orr r1, r5
	strb r1, [r0, #1]
	lsl r2, r3, #0x1c
	ldrb r5, [r0, #1]
	mov r1, #0xf0
	lsr r2, r2, #0x18
	bic r5, r1
	orr r2, r5
	strb r2, [r0, #1]
	ldr r2, [sp, #8]
	str r2, [r0, #4]
	ldrb r2, [r0, #3]
	bic r2, r4
	strb r2, [r0, #3]
	ldrb r2, [r0, #3]
	bic r2, r1
	strb r2, [r0, #3]
	mov r0, #0x23
	pop {r4, r5}
	bx lr
	thumb_func_end ov15_021FD7D0


	thumb_func_start ov15_021FD810
ov15_021FD810: ; 0x021FD810
	push {r4, r5, r6, lr}
	add r6, r2, #0
	mov r2, #0x25
	add r4, r0, #0
	lsl r2, r2, #6
	add r0, r4, r2
	mov r5, #1
	strb r5, [r0, #2]
	strb r1, [r0]
	str r3, [r0, #4]
	ldrb r5, [r0, #3]
	mov r3, #0xf
	bic r5, r3
	strb r5, [r0, #3]
	ldrb r5, [r0, #3]
	mov r3, #0xf0
	bic r5, r3
	strb r5, [r0, #3]
	lsr r0, r2, #2
	add r5, r4, r0
	lsl r4, r1, #2
	ldr r0, [r5, r4]
	mov r1, #0
	bl ManagedSprite_SetAnimationFrame
	ldr r0, [r5, r4]
	add r1, r6, #0
	bl ManagedSprite_SetAnim
	mov r0, #0x23
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov15_021FD810


	thumb_func_start ov15_021FD850
ov15_021FD850: ; 0x021FD850
	push {r3, r4, r5, lr}
	mov r5, #0x25
	lsl r5, r5, #6
	add r4, r0, r5
	ldrb r1, [r4, #2]
	cmp r1, #1
	bne _021FD874
	ldrb r1, [r4]
	lsl r1, r1, #2
	add r1, r0, r1
	lsr r0, r5, #2
	ldr r0, [r1, r0]
	bl ManagedSprite_IsAnimated
	cmp r0, #0
	bne _021FD936
	ldr r0, [r4, #4]
	pop {r3, r4, r5, pc}
_021FD874:
	ldrb r2, [r4, #3]
	lsl r1, r2, #0x1c
	lsr r1, r1, #0x1c
	beq _021FD886
	cmp r1, #1
	beq _021FD8B6
	cmp r1, #2
	beq _021FD910
	b _021FD936
_021FD886:
	ldrb r1, [r4]
	lsl r1, r1, #2
	add r1, r0, r1
	lsr r0, r5, #2
	ldr r0, [r1, r0]
	ldrb r1, [r4, #1]
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x1c
	bl ManagedSprite_SetPaletteOverride
	ldrb r2, [r4, #3]
	mov r1, #0xf
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x1c
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r2, r1, #0x18
	mov r1, #0xf
	and r1, r2
	orr r0, r1
	strb r0, [r4, #3]
	b _021FD936
_021FD8B6:
	add r1, r2, #0
	lsl r2, r2, #0x18
	lsr r2, r2, #0x1c
	add r2, r2, #1
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	mov r3, #0xf0
	lsl r2, r2, #0x1c
	bic r1, r3
	lsr r2, r2, #0x18
	orr r1, r2
	strb r1, [r4, #3]
	ldrb r1, [r4, #3]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	cmp r1, #4
	bne _021FD936
	ldrb r1, [r4]
	lsl r1, r1, #2
	add r1, r0, r1
	lsr r0, r5, #2
	ldr r0, [r1, r0]
	ldrb r1, [r4, #1]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x1c
	bl ManagedSprite_SetPaletteOverride
	ldrb r1, [r4, #3]
	mov r0, #0xf0
	bic r1, r0
	strb r1, [r4, #3]
	ldrb r2, [r4, #3]
	mov r1, #0xf
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x1c
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r2, r1, #0x18
	mov r1, #0xf
	and r1, r2
	orr r0, r1
	strb r0, [r4, #3]
	b _021FD936
_021FD910:
	mov r1, #0xf0
	add r0, r2, #0
	bic r0, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x1c
	add r1, r1, #1
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	lsl r1, r1, #0x1c
	lsr r1, r1, #0x18
	orr r0, r1
	strb r0, [r4, #3]
	ldrb r0, [r4, #3]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	cmp r0, #2
	bne _021FD936
	ldr r0, [r4, #4]
	pop {r3, r4, r5, pc}
_021FD936:
	mov r0, #0x23
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov15_021FD850


	thumb_func_start ov15_021FD93C
ov15_021FD93C: ; 0x021FD93C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #6
	bl GF3dRender_InitSimpleManager
	ldr r2, _021FDA94 ; =0x04000060
	ldr r0, _021FDA98 ; =0xFFFFCFFF
	ldrh r1, [r2]
	and r1, r0
	mov r0, #0x10
	orr r0, r1
	strh r0, [r2]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl G3X_SetFog
	mov r0, #0
	ldr r2, _021FDA9C ; =0x00007FFF
	add r1, r0, #0
	add r3, r0, #0
	str r0, [sp]
	bl G3X_SetClearColor
	ldr r0, _021FDAA0 ; =0x00003DEF
	ldr r1, _021FDAA4 ; =0x0000294A
	mov r2, #0
	bl NNS_G3dGlbMaterialColorDiffAmb
	ldr r0, _021FDAA0 ; =0x00003DEF
	mov r2, #0
	add r1, r0, #0
	bl NNS_G3dGlbMaterialColorSpecEmi
	mov r0, #0x1f
	mov r1, #0
	str r0, [sp]
	mov r0, #0xf
	mov r2, #3
	add r3, r1, #0
	str r1, [sp, #4]
	bl NNS_G3dGlbPolygonAttr
	ldr r2, _021FDA94 ; =0x04000060
	ldr r0, _021FDA98 ; =0xFFFFCFFF
	ldrh r1, [r2]
	and r1, r0
	mov r0, #0x20
	orr r0, r1
	strh r0, [r2]
	ldr r0, _021FDAA8 ; =ov15_02201304
	bl G3X_SetEdgeColorTable
	mov r0, #0
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #6
	bl Camera_New
	ldr r2, _021FDAAC ; =0x00000818
	ldr r4, _021FDAB0 ; =ov15_02200500
	str r0, [r5, r2]
	add r0, r2, #0
	add r0, #0xec
	add r3, r5, r0
	ldmia r4!, {r0, r1}
	add r6, r3, #0
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	ldr r4, _021FDAB4 ; =ov15_0220053C
	str r0, [r3]
	add r0, r2, #0
	add r0, #0xf8
	add r3, r5, r0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	str r0, [r3]
	ldr r3, _021FDAB8 ; =0x0000091C
	ldrb r0, [r5, r3]
	add r1, r3, #0
	sub r1, #0xc
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r0, [r5, r2]
	add r2, r3, #0
	str r0, [sp, #8]
	add r3, r3, #2
	sub r2, #8
	ldrh r3, [r5, r3]
	ldr r1, [r5, r1]
	add r0, r6, #0
	add r2, r5, r2
	bl Camera_Init_FromTargetDistanceAndAngle
	ldr r0, _021FDABC ; =0x00000934
	ldr r3, _021FDAC0 ; =ov15_0220050C
	add r2, r5, r0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, _021FDAC4 ; =0x00000808
	add r0, r5, r0
	bl ov15_021FDAD0
	mov r1, #0x8d
	lsl r1, r1, #2
	ldr r1, [r5, r1]
	ldr r0, _021FDAC4 ; =0x00000808
	add r1, #0x64
	ldrb r1, [r1]
	add r0, r5, r0
	mov r2, #7
	add r1, r1, #1
	bl ov15_021FDAF4
	ldr r2, _021FDAAC ; =0x00000818
	mov r0, #0x7b
	ldr r1, _021FDAC8 ; =0x006A4000
	ldr r2, [r5, r2]
	lsl r0, r0, #0xc
	bl Camera_SetPerspectiveClippingPlane
	ldr r0, _021FDAAC ; =0x00000818
	ldr r0, [r5, r0]
	bl Camera_SetStaticPtr
	mov r6, #1
	ldr r7, _021FDA9C ; =0x00007FFF
	mov r4, #0
	lsl r6, r6, #0xc
_021FDA58:
	mov r2, #0
	add r0, r4, #0
	add r1, r6, #0
	add r3, r2, #0
	bl NNS_G3dGlbLightVector
	add r0, r4, #0
	add r1, r7, #0
	bl NNS_G3dGlbLightColor
	add r4, r4, #1
	cmp r4, #4
	blo _021FDA58
	add r0, r5, #0
	bl ov15_021FDD70
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r1, _021FDACC ; =0x04000008
	mov r0, #3
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #2
	orr r0, r2
	strh r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021FDA94: .word 0x04000060
_021FDA98: .word 0xFFFFCFFF
_021FDA9C: .word 0x00007FFF
_021FDAA0: .word 0x00003DEF
_021FDAA4: .word 0x0000294A
_021FDAA8: .word ov15_02201304
_021FDAAC: .word 0x00000818
_021FDAB0: .word ov15_02200500
_021FDAB4: .word ov15_0220053C
_021FDAB8: .word 0x0000091C
_021FDABC: .word 0x00000934
_021FDAC0: .word ov15_0220050C
_021FDAC4: .word 0x00000808
_021FDAC8: .word 0x006A4000
_021FDACC: .word 0x04000008
	thumb_func_end ov15_021FD93C
