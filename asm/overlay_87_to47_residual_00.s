	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E5AFC
	.extern ov87_021E5B48
	.extern ov87_021E5C38
	.extern ov87_021E5CEC
	.extern ov87_021E5E00
	.extern ov87_021E6080
	.extern ov87_021E64F8
	.extern ov87_021E65FC
	.extern ov87_021E6668
	.extern ov87_021E66B8
	.extern ov87_021E6760
	.extern ov87_021E68A4
	.extern ov87_021E68DC
	.extern ov87_021E725C
	.extern ov87_021E7334

	.text

thumb_func_start ScratchOffCards_Init
ScratchOffCards_Init: ; 0x021E5900
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r7, r1, #0
	bl ov87_021E68A4
	mov r2, #0x12
	mov r0, #3
	mov r1, #0x7a
	lsl r2, r2, #0xe
	bl Heap_Create
	ldr r1, _021E59AC ; =0x000099FC
	add r0, r5, #0
	mov r2, #0x7a
	bl OverlayManager_CreateAndGetData
	ldr r2, _021E59AC ; =0x000099FC
	mov r1, #0
	add r4, r0, #0
	bl memset
	mov r0, #0x7a
	bl BgConfig_Alloc
	str r0, [r4, #0x58]
	add r0, r5, #0
	str r5, [r4]
	bl OverlayManager_GetArgs
	add r5, r0, #0
	mov r1, #0x5a
	add r2, r5, #0
	ldr r0, [r5]
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldrb r0, [r5, #4]
	add r2, #0x14
	strb r0, [r4, #9]
	mov r0, #0xdd
	lsl r0, r0, #2
	str r2, [r4, r0]
	ldr r0, [r4, r1]
	bl Save_PlayerData_GetOptionsAddr
	mov r1, #0x59
	lsl r1, r1, #2
	str r0, [r4, r1]
	add r1, r5, #0
	mov r0, #0xde
	add r1, #8
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r5, #0xe
	add r0, r0, #4
	str r5, [r4, r0]
	add r0, r4, #0
	bl ov87_021E7334
	mov r1, #0
	mov r3, #0xde
	lsl r3, r3, #2
	add r2, r1, #0
	add r0, r1, #0
	add r5, r3, #4
_021E5980:
	ldr r6, [r4, r3]
	add r1, r1, #1
	strh r0, [r6, r2]
	ldr r6, [r4, r5]
	strh r0, [r6, r2]
	add r2, r2, #2
	cmp r1, #3
	blt _021E5980
	ldr r1, _021E59B0 ; =0x0000039D
	strb r0, [r4, r1]
	add r0, r4, #0
	bl ov87_021E68DC
	mov r1, #0
	mov r0, #0x42
	add r2, r1, #0
	str r1, [r7]
	bl Sound_SetSceneAndPlayBGM
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E59AC: .word 0x000099FC
_021E59B0: .word 0x0000039D
	thumb_func_end ScratchOffCards_Init

	thumb_func_start ScratchOffCards_Main
ScratchOffCards_Main: ; 0x021E59B4
	push {r3, r4, r5, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	cmp r1, #7
	bhi _021E5AB2
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E59D0: ; jump table
	.short _021E59E0 - _021E59D0 - 2 ; case 0
	.short _021E59F4 - _021E59D0 - 2 ; case 1
	.short _021E5A08 - _021E59D0 - 2 ; case 2
	.short _021E5A1C - _021E59D0 - 2 ; case 3
	.short _021E5A58 - _021E59D0 - 2 ; case 4
	.short _021E5A6C - _021E59D0 - 2 ; case 5
	.short _021E5A92 - _021E59D0 - 2 ; case 6
	.short _021E5AA6 - _021E59D0 - 2 ; case 7
_021E59E0:
	bl ov87_021E5AFC
	cmp r0, #1
	bne _021E5AB2
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #1
	bl ov87_021E725C
	b _021E5AB2
_021E59F4:
	bl ov87_021E5B48
	cmp r0, #1
	bne _021E5AB2
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #2
	bl ov87_021E725C
	b _021E5AB2
_021E5A08:
	bl ov87_021E5C38
	cmp r0, #1
	bne _021E5AB2
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #3
	bl ov87_021E725C
	b _021E5AB2
_021E5A1C:
	bl ov87_021E5CEC
	cmp r0, #1
	bne _021E5AB2
	ldrb r0, [r4, #0xe]
	cmp r0, #3
	blo _021E5A4C
	mov r0, #0
	strb r0, [r4, #0xe]
	add r0, r4, #0
	bl ov87_021E6760
	add r0, r4, #0
	bl ov87_021E6668
	add r0, r4, #0
	bl ov87_021E66B8
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #4
	bl ov87_021E725C
	b _021E5AB2
_021E5A4C:
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #1
	bl ov87_021E725C
	b _021E5AB2
_021E5A58:
	bl ov87_021E5E00
	cmp r0, #1
	bne _021E5AB2
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #5
	bl ov87_021E725C
	b _021E5AB2
_021E5A6C:
	bl ov87_021E6080
	cmp r0, #1
	bne _021E5AB2
	ldrb r0, [r4, #0xe]
	cmp r0, #3
	blo _021E5A86
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #7
	bl ov87_021E725C
	b _021E5AB2
_021E5A86:
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #6
	bl ov87_021E725C
	b _021E5AB2
_021E5A92:
	bl ov87_021E64F8
	cmp r0, #1
	bne _021E5AB2
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #4
	bl ov87_021E725C
	b _021E5AB2
_021E5AA6:
	bl ov87_021E65FC
	cmp r0, #1
	bne _021E5AB2
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E5AB2:
	mov r0, #0x5b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl SpriteList_RenderAndAnimateSprites
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ScratchOffCards_Main
