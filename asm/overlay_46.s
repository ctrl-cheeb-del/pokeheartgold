	.include "asm/macros.inc"
	.public _02258918
	.public _0225891C
	.public _02258920
	.public _02258924
	.public _02258928
	.public _0225894A
	.public _02258956
	.public _02258976
	.public _02258994
	.public _022589A4
	.public _022589CA
	.public _022589D0
	.public _022589EC
	.public _022589F0
	.public _022589F2
	.public _02258A0A
	.public _02258A32
	.public _02258A42
	.public _02258A4E
	.public _02258A64
	.public _02258A74
	.public _02258A80
	.public _02258AB2
	.public _02258ACE
	.public _02258ADC
	.public _02258B0E
	.public _02258B20
	.public _02258B22
	.public _02258B40
	.public _02258B46
	.public _02258B4C
	.public _02258B74
	.public _02258B94
	.public _02258BA6
	.public _02258BB4
	.public _02258BD8
	.public _02258BF6
	.public _02258C16
	.public _02258C24
	.public _02258C28
	.public _02258C30
	.public _02258C34
	.public _02258C68
	.public _02258CB0
	.public _02258D98
	.public _02258D9C
	.public _02258DA0
	.public _02258DA4
	.public _02258DC6
	.public _02258DD2
	.public _02258DE8
	.public _02258E06
	.public _02258E14
	.public _02258E2E
	.public _02258E3C
	.public _02258E4A
	.public _02258E5A
	.public _02258E6E
	.public _02258E74
	.public _02258E7E
	.public _02258E9A
	.public _02258EAE
	.public _02258EBC
	.public _02258EDC
	.public _02258EF2
	.public _02258EF8
	.public _02258F2C
	.public _02258F6C
	.public _02258FAE
	.public _02259126
	.public _02259138
	.public _02259142
	.public _0225915A
	.public _022591A6
	.public _022591F4
	.public _022591F8
	.public _022591FC
	.public _02259200
	.public _02259204
	.public _02259208
	.public _0225920C
	.public _02259246
	.public _02259254
	.public _0225926A
	.public _02259292
	.public _022592AE
	.public _022592B0
	.public _022592B4
	.public _02259598
	.public ov46_02258800
	.public ov46_0225892C
	.public ov46_02258C38
	.public ov46_02258CB4
	.public ov46_02258DA8
	.public ov46_02258EFC
	.public ov46_02258F78
	.public ov46_02259210
	.public ov46_022595A4
	.public ov46_022595B4
	.public ov46_022595DC
	.public _02259598
	.public ov46_02258800
	.public ov46_0225892C
	.public ov46_02258C38
	.public ov46_02258CB4
	.public ov46_02258DA8
	.public ov46_02258EFC
	.public ov46_02258F70
	.public ov46_02258F78
	.public ov46_02259210
	.public ov46_022592B8
	.public ov46_022592E0
	.public ov46_022592EC
	.public ov46_02259374
	.public ov46_022593F8
	.public ov46_02259450
	.public ov46_02259474
	.public ov46_02259494
	.public ov46_022594E0
	.public ov46_02259534
	.public ov46_02259550
	.include "overlay_46.inc"
	.include "global.inc"

	.text
	.public ov46_02258F70
	.public ov46_022592B8
	.public ov46_022592E0
	.public ov46_022592EC
	.public ov46_02259374
	.public ov46_022593F8
	.public ov46_02259450
	.public ov46_02259474
	.public ov46_02259494
	.public ov46_022594E0
	.public ov46_02259534
	.public ov46_02259550

	thumb_func_start ov46_02258800
ov46_02258800: ; 0x02258800
	push {r4, r5, lr}
	sub sp, #0x1c
	mov r2, #2
	add r4, r0, #0
	mov r0, #3
	mov r1, #0x77
	lsl r2, r2, #0x10
	bl Heap_Create
	ldr r1, _02258918 ; =0x00000404
	add r0, r4, #0
	mov r2, #0x77
	bl OverlayManager_CreateAndGetData
	ldr r2, _02258918 ; =0x00000404
	mov r1, #0
	add r5, r0, #0
	bl memset
	add r0, r4, #0
	bl OverlayManager_GetArgs
	add r4, r0, #0
	ldr r0, [r4]
	ldr r1, _0225891C ; =0x0000047D
	str r0, [r5]
	mov r0, #0xb
	mov r2, #0
	bl Sound_SetSceneAndPlayBGM
	mov r0, #0
	str r0, [r4, #0x10]
	add r0, r5, #0
	mov r1, #0x77
	bl ov46_02258F78
	mov r0, #2
	str r0, [sp]
	mov r0, #0x13
	str r0, [sp, #4]
	mov r0, #0x1b
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0x28
	str r0, [sp, #0x10]
	ldr r0, [r5]
	ldr r3, _02258920 ; =0x0000030A
	str r0, [sp, #0x14]
	mov r0, #0x77
	str r0, [sp, #0x18]
	add r0, r5, #0
	ldr r1, [r5, #0xc]
	add r0, #0x40
	mov r2, #1
	bl ov46_022592EC
	mov r0, #2
	str r0, [sp]
	mov r0, #0x13
	str r0, [sp, #4]
	mov r0, #0x1b
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0x28
	str r0, [sp, #0x10]
	ldr r0, [r5]
	mov r3, #0x32
	str r0, [sp, #0x14]
	mov r0, #0x77
	str r0, [sp, #0x18]
	add r0, r5, #0
	ldr r1, [r5, #0xc]
	add r0, #0x70
	mov r2, #1
	lsl r3, r3, #4
	bl ov46_022592EC
	mov r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x17
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	mov r0, #0x94
	str r0, [sp, #0x10]
	ldr r0, [r5]
	mov r3, #0x32
	str r0, [sp, #0x14]
	mov r0, #0x77
	str r0, [sp, #0x18]
	add r0, r5, #0
	ldr r1, [r5, #0xc]
	add r0, #0xa0
	mov r2, #0
	lsl r3, r3, #4
	bl ov46_022592EC
	mov r0, #5
	str r0, [sp]
	mov r2, #1
	str r2, [sp, #4]
	mov r0, #0x16
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0x81
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r5]
	ldr r3, _02258920 ; =0x0000030A
	str r0, [sp, #0x14]
	mov r0, #0x77
	str r0, [sp, #0x18]
	add r0, r5, #0
	ldr r1, [r5, #0xc]
	add r0, #0x10
	bl ov46_022592EC
	add r0, r5, #0
	add r0, #0x10
	mov r1, #0x15
	bl ov46_022594E0
	ldr r0, _02258924 ; =ov46_02258F70
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	ldr r0, _02258928 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	add sp, #0x1c
	pop {r4, r5, pc}
	.balign 4, 0
_02258918: .word 0x00000404
_0225891C: .word 0x0000047D
_02258920: .word 0x0000030A
_02258924: .word ov46_02258F70
_02258928: .word gSystem + 0x60
	thumb_func_end ov46_02258800


	thumb_func_start ov46_0225892C
ov46_0225892C: ; 0x0225892C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r6, r0, #0
	add r4, r1, #0
	bl OverlayManager_GetData
	add r5, r0, #0
	add r0, r6, #0
	bl OverlayManager_GetArgs
	add r6, r0, #0
	ldr r0, [r4]
	cmp r0, #0xf
	bls _0225894A
	b _02258C24
_0225894A:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02258956: ; jump table
	.short _02258976 - _02258956 - 2 ; case 0
	.short _02258994 - _02258956 - 2 ; case 1
	.short _022589A4 - _02258956 - 2 ; case 2
	.short _022589D0 - _02258956 - 2 ; case 3
	.short _02258A0A - _02258956 - 2 ; case 4
	.short _02258A32 - _02258956 - 2 ; case 5
	.short _02258A64 - _02258956 - 2 ; case 6
	.short _02258BF6 - _02258956 - 2 ; case 7
	.short _02258C16 - _02258956 - 2 ; case 8
	.short _02258AB2 - _02258956 - 2 ; case 9
	.short _02258B0E - _02258956 - 2 ; case 10
	.short _02258B4C - _02258956 - 2 ; case 11
	.short _02258B74 - _02258956 - 2 ; case 12
	.short _02258BA6 - _02258956 - 2 ; case 13
	.short _02258BB4 - _02258956 - 2 ; case 14
	.short _02258BD8 - _02258956 - 2 ; case 15
_02258976:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x77
	str r0, [sp, #8]
	ldr r3, _02258C30 ; =0x0000FFFF
	mov r0, #0
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_02258994:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _022589F0
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_022589A4:
	ldr r0, [r6, #8]
	cmp r0, #0
	bne _022589CA
	add r0, r5, #0
	add r0, #0x70
	mov r1, #0x11
	bl ov46_02259374
	mov r1, #0x23
	ldr r0, [r5, #0xc]
	lsl r1, r1, #4
	bl ov46_02259550
	add r5, #0xd0
	str r0, [r5]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_022589CA:
	mov r0, #4
	str r0, [r4]
	b _02258C28
_022589D0:
	add r0, r5, #0
	add r0, #0xd0
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _022589EC
	add r5, #0xd0
	ldr r0, [r5]
	bl YesNoPrompt_Destroy
	mov r0, #4
	str r0, [r4]
	b _02258C28
_022589EC:
	cmp r0, #2
	beq _022589F2
_022589F0:
	b _02258C28
_022589F2:
	add r0, r5, #0
	add r0, #0xd0
	ldr r0, [r0]
	bl YesNoPrompt_Destroy
	add r5, #0x40
	add r0, r5, #0
	bl ov46_022593F8
	mov r0, #7
	str r0, [r4]
	b _02258C28
_02258A0A:
	ldr r0, [r6, #4]
	bl ov45_0222A5C0
	add r1, r0, #0
	ldr r0, [r5]
	bl sub_0203976C
	add r0, r5, #0
	add r0, #0x70
	mov r1, #0x17
	bl ov46_02259374
	add r5, #0x70
	add r0, r5, #0
	bl ov46_02259450
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_02258A32:
	bl sub_020393C8
	cmp r0, #0
	bne _02258A42
	bl sub_020397FC
	cmp r0, #0
	beq _02258A4E
_02258A42:
	add r5, #0x70
	add r0, r5, #0
	bl ov46_02259474
	mov r0, #9
	str r0, [r4]
_02258A4E:
	bl sub_020397E4
	cmp r0, #1
	bne _02258B20
	ldr r0, [r6, #4]
	bl ov45_0222B244
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_02258A64:
	bl sub_020393C8
	cmp r0, #0
	bne _02258A74
	bl sub_020397FC
	cmp r0, #0
	beq _02258A80
_02258A74:
	add r0, r5, #0
	add r0, #0x70
	bl ov46_02259474
	mov r0, #9
	str r0, [r4]
_02258A80:
	bl sub_02039274
	cmp r0, #0
	beq _02258B20
	add r0, r5, #0
	add r0, #0x70
	bl ov46_02259474
	ldr r0, [r5]
	bl Save_GameStats_Get
	mov r1, #0x21 ; SCORE_EVENT_WIFI_PLAZA_ACCESSED
	bl GameStats_AddScore
	bl GF_RTC_DateTimeToSec
	ldr r2, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, #1
	str r0, [r6, #0x10]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_02258AB2:
	bl sub_020393C8
	cmp r0, #0
	beq _02258ACE
	bl sub_020392D8
	add r7, r0, #0
	ldr r0, [r7]
	ldr r1, [r7, #4]
	bl ov45_0222D7CC
	str r0, [sp, #0xc]
	ldr r7, [r7]
	b _02258ADC
_02258ACE:
	bl ov45_0222E7CC
	bl ov45_0222E7FC
	add r7, r0, #0
	mov r0, #0x20
	str r0, [sp, #0xc]
_02258ADC:
	ldr r0, [r6, #4]
	bl ov45_0222B270
	add r0, r5, #0
	add r0, #0x40
	bl ov46_022593F8
	add r0, r5, #0
	add r0, #0x70
	bl ov46_022593F8
	add r0, r5, #0
	add r0, #0xa0
	add r1, r7, #0
	bl ov46_02259534
	add r5, #0xa0
	ldr r1, [sp, #0xc]
	add r0, r5, #0
	bl ov46_02259374
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_02258B0E:
	ldr r0, _02258C34 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #3
	tst r0, r1
	bne _02258B22
	bl System_GetTouchNew
	cmp r0, #1
	beq _02258B22
_02258B20:
	b _02258C28
_02258B22:
	bl sub_020393C8
	cmp r0, #0
	beq _02258B46
	bl sub_020392D8
	add r1, r0, #0
	ldmia r1!, {r0, r1}
	bl ov45_0222D7FC
	cmp r0, #0
	bne _02258B40
	mov r0, #0xb
	str r0, [r4]
	b _02258C28
_02258B40:
	mov r0, #0xe
	str r0, [r4]
	b _02258C28
_02258B46:
	mov r0, #0xb
	str r0, [r4]
	b _02258C28
_02258B4C:
	add r0, r5, #0
	add r0, #0xa0
	bl ov46_022593F8
	add r0, r5, #0
	add r0, #0x40
	mov r1, #0x58
	bl ov46_02259374
	mov r1, #0x23
	ldr r0, [r5, #0xc]
	lsl r1, r1, #4
	bl ov46_02259550
	add r5, #0xd0
	str r0, [r5]
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_02258B74:
	add r0, r5, #0
	add r0, #0xd0
	ldr r0, [r0]
	bl YesNoPrompt_HandleInput
	cmp r0, #1
	bne _02258B94
	add r5, #0xd0
	ldr r0, [r5]
	bl YesNoPrompt_Destroy
	bl sub_020397C8
	mov r0, #0xd
	str r0, [r4]
	b _02258C28
_02258B94:
	cmp r0, #2
	bne _02258C28
	add r5, #0xd0
	ldr r0, [r5]
	bl YesNoPrompt_Destroy
	mov r0, #0xe
	str r0, [r4]
	b _02258C28
_02258BA6:
	bl sub_02037D78
	cmp r0, #0
	bne _02258C28
	mov r0, #4
	str r0, [r4]
	b _02258C28
_02258BB4:
	add r0, r5, #0
	add r0, #0x40
	bl ov46_022593F8
	add r0, r5, #0
	add r0, #0x70
	bl ov46_022593F8
	add r5, #0xa0
	add r0, r5, #0
	bl ov46_022593F8
	bl sub_020397C8
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_02258BD8:
	bl sub_02037D78
	cmp r0, #0
	bne _02258C28
	add r0, r5, #0
	add r0, #0x40
	bl ov46_022593F8
	add r5, #0x70
	add r0, r5, #0
	bl ov46_022593F8
	mov r0, #7
	str r0, [r4]
	b _02258C28
_02258BF6:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x77
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258C28
_02258C16:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02258C28
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_02258C24:
	bl GF_AssertFail
_02258C28:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02258C30: .word 0x0000FFFF
_02258C34: .word gSystem
	thumb_func_end ov46_0225892C


	thumb_func_start ov46_02258C38
ov46_02258C38: ; 0x02258C38
	push {r4, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	add r0, r4, #0
	add r0, #0xd4
	ldr r0, [r0]
	cmp r0, #0
	beq _02258C68
	bl SysTask_Destroy
	add r0, r4, #0
	mov r1, #0
	add r0, #0xd4
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xd8
	str r1, [r0]
_02258C68:
	add r0, r4, #0
	add r0, #0x40
	bl ov46_02259494
	add r0, r4, #0
	add r0, #0x70
	bl ov46_02259494
	add r0, r4, #0
	add r0, #0xa0
	bl ov46_02259494
	add r0, r4, #0
	add r0, #0x10
	bl ov46_02259494
	add r0, r4, #0
	bl ov46_022592B8
	add r0, r4, #0
	mov r1, #0
	add r0, #0xd8
	str r1, [r0]
	add r0, r4, #0
	bl Heap_Free
	mov r0, #0x77
	bl Heap_Destroy
	ldr r0, _02258CB0 ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
_02258CB0: .word gSystem + 0x60
	thumb_func_end ov46_02258C38


	thumb_func_start ov46_02258CB4
ov46_02258CB4: ; 0x02258CB4
	push {r4, r5, lr}
	sub sp, #0x1c
	mov r2, #2
	add r5, r0, #0
	mov r0, #3
	mov r1, #0x77
	lsl r2, r2, #0x10
	bl Heap_Create
	ldr r1, _02258D98 ; =0x00000404
	add r0, r5, #0
	mov r2, #0x77
	bl OverlayManager_CreateAndGetData
	ldr r2, _02258D98 ; =0x00000404
	mov r1, #0
	add r4, r0, #0
	bl memset
	add r0, r5, #0
	bl OverlayManager_GetArgs
	ldr r0, [r0]
	mov r1, #0x77
	str r0, [r4]
	add r0, r4, #0
	bl ov46_02258F78
	mov r0, #2
	str r0, [sp]
	mov r0, #0x13
	str r0, [sp, #4]
	mov r0, #0x1b
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r0, #0x28
	str r0, [sp, #0x10]
	ldr r0, [r4]
	mov r3, #0x32
	str r0, [sp, #0x14]
	mov r0, #0x77
	str r0, [sp, #0x18]
	add r0, r4, #0
	ldr r1, [r4, #0xc]
	add r0, #0x40
	mov r2, #1
	lsl r3, r3, #4
	bl ov46_022592EC
	mov r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #0x17
	str r0, [sp, #8]
	mov r0, #0x10
	str r0, [sp, #0xc]
	mov r0, #0x94
	str r0, [sp, #0x10]
	ldr r0, [r4]
	mov r3, #0x32
	str r0, [sp, #0x14]
	mov r0, #0x77
	str r0, [sp, #0x18]
	add r0, r4, #0
	ldr r1, [r4, #0xc]
	add r0, #0xa0
	mov r2, #0
	lsl r3, r3, #4
	bl ov46_022592EC
	mov r0, #5
	str r0, [sp]
	mov r2, #1
	str r2, [sp, #4]
	mov r0, #0x16
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0x81
	lsl r0, r0, #2
	str r0, [sp, #0x10]
	ldr r0, [r4]
	ldr r3, _02258D9C ; =0x0000030A
	str r0, [sp, #0x14]
	mov r0, #0x77
	str r0, [sp, #0x18]
	add r0, r4, #0
	ldr r1, [r4, #0xc]
	add r0, #0x10
	bl ov46_022592EC
	add r0, r4, #0
	add r0, #0x10
	mov r1, #0x15
	bl ov46_022594E0
	bl sub_0203A880
	ldr r0, _02258DA0 ; =ov46_02258F70
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	ldr r0, _02258DA4 ; =gSystem + 0x60
	mov r1, #1
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	add sp, #0x1c
	pop {r4, r5, pc}
	nop
_02258D98: .word 0x00000404
_02258D9C: .word 0x0000030A
_02258DA0: .word ov46_02258F70
_02258DA4: .word gSystem + 0x60
	thumb_func_end ov46_02258CB4


	thumb_func_start ov46_02258DA8
ov46_02258DA8: ; 0x02258DA8
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r6, r0, #0
	add r4, r1, #0
	bl OverlayManager_GetData
	add r5, r0, #0
	add r0, r6, #0
	bl OverlayManager_GetArgs
	add r6, r0, #0
	ldr r0, [r4]
	cmp r0, #0xa
	bls _02258DC6
	b _02258EF2
_02258DC6:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02258DD2: ; jump table
	.short _02258DE8 - _02258DD2 - 2 ; case 0
	.short _02258E06 - _02258DD2 - 2 ; case 1
	.short _02258E14 - _02258DD2 - 2 ; case 2
	.short _02258E4A - _02258DD2 - 2 ; case 3
	.short _02258E5A - _02258DD2 - 2 ; case 4
	.short _02258E74 - _02258DD2 - 2 ; case 5
	.short _02258E7E - _02258DD2 - 2 ; case 6
	.short _02258E9A - _02258DD2 - 2 ; case 7
	.short _02258EAE - _02258DD2 - 2 ; case 8
	.short _02258EBC - _02258DD2 - 2 ; case 9
	.short _02258EDC - _02258DD2 - 2 ; case 10
_02258DE8:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x77
	str r0, [sp, #8]
	ldr r3, _02258EF8 ; =0x0000FFFF
	mov r0, #0
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258EF2
_02258E06:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02258EF2
	mov r0, #2
	str r0, [r4]
	b _02258EF2
_02258E14:
	add r0, r5, #0
	add r0, #0x40
	mov r1, #0x1a
	bl ov46_02259374
	bl sub_020393C8
	cmp r0, #0
	bne _02258E2E
	bl sub_020397FC
	cmp r0, #0
	beq _02258E3C
_02258E2E:
	mov r0, #5
	add r5, #0x40
	str r0, [r4]
	add r0, r5, #0
	bl ov46_02259450
	b _02258EF2
_02258E3C:
	mov r0, #3
	add r5, #0x40
	str r0, [r4]
	add r0, r5, #0
	bl ov46_02259450
	b _02258EF2
_02258E4A:
	bl ov45_0222ED7C
	mov r0, #0xe1
	lsl r0, r0, #2
	str r0, [r5, #8]
	mov r0, #4
	str r0, [r4]
	b _02258EF2
_02258E5A:
	ldr r0, [r5, #8]
	sub r0, r0, #1
	str r0, [r5, #8]
	bl ov45_0222EDA8
	cmp r0, #0
	bne _02258E6E
	ldr r0, [r5, #8]
	cmp r0, #0
	bne _02258EF2
_02258E6E:
	mov r0, #5
	str r0, [r4]
	b _02258EF2
_02258E74:
	bl sub_020397C8
	mov r0, #6
	str r0, [r4]
	b _02258EF2
_02258E7E:
	bl sub_02037D78
	cmp r0, #0
	bne _02258EF2
	add r5, #0x70
	add r0, r5, #0
	bl ov46_02259474
	ldr r0, [r6, #4]
	bl ov45_0222B270
	mov r0, #7
	str r0, [r4]
	b _02258EF2
_02258E9A:
	add r0, r5, #0
	add r0, #0x40
	mov r1, #0x1b
	bl ov46_02259374
	mov r0, #0x5a
	str r0, [r5, #8]
	mov r0, #8
	str r0, [r4]
	b _02258EF2
_02258EAE:
	ldr r0, [r5, #8]
	sub r0, r0, #1
	str r0, [r5, #8]
	bne _02258EF2
	mov r0, #9
	str r0, [r4]
	b _02258EF2
_02258EBC:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x77
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldr r0, [r4]
	add r0, r0, #1
	str r0, [r4]
	b _02258EF2
_02258EDC:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02258EF2
	add r5, #0x40
	add r0, r5, #0
	bl ov46_02259474
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, r5, r6, pc}
_02258EF2:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_02258EF8: .word 0x0000FFFF
	thumb_func_end ov46_02258DA8


	thumb_func_start ov46_02258EFC
ov46_02258EFC: ; 0x02258EFC
	push {r4, lr}
	bl OverlayManager_GetData
	add r4, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	add r0, r4, #0
	add r0, #0xd4
	ldr r0, [r0]
	cmp r0, #0
	beq _02258F2C
	bl SysTask_Destroy
	add r0, r4, #0
	mov r1, #0
	add r0, #0xd4
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xd8
	str r1, [r0]
_02258F2C:
	add r0, r4, #0
	add r0, #0x40
	bl ov46_02259494
	add r0, r4, #0
	add r0, #0xa0
	bl ov46_02259494
	add r0, r4, #0
	add r0, #0x10
	bl ov46_02259494
	add r0, r4, #0
	bl ov46_022592B8
	add r0, r4, #0
	mov r1, #0
	add r0, #0xd8
	str r1, [r0]
	add r0, r4, #0
	bl Heap_Free
	mov r0, #0x77
	bl Heap_Destroy
	ldr r0, _02258F6C ; =gSystem + 0x60
	mov r1, #0
	strb r1, [r0, #9]
	bl GfGfx_SwapDisplay
	mov r0, #1
	pop {r4, pc}
	.balign 4, 0
_02258F6C: .word gSystem + 0x60
	thumb_func_end ov46_02258EFC
