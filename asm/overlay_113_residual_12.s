	.include "asm/macros.inc"
	.include "overlay_113.inc"
	.include "asm/include/overlay_113_split.inc"
	.include "global.inc"

	.text
	.public UnownReport_Exit
	.public ov113_021E59F8
	.public ov113_021E5A48
	.public ov113_021E5B60
	.public ov113_021E5B70
	.public ov113_021E5BB0
	.public ov113_021E5C60
	.public ov113_021E5CF8
	.public ov113_021E5D28
	.public ov113_021E5D4C
	.public ov113_021E5EC4
	.public ov113_021E6274
	.public ov113_021E629C
	.public ov113_021E62E0
	.public ov113_021E64DC
	.public ov113_021E663C
	.public ov113_021E66E4
	.public ov113_021E6754
	.public ov113_021E6930
	.public ov113_021E6988
	.public ov113_021E69A8

	thumb_func_start ov113_021E677C
ov113_021E677C: ; 0x021E677C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r5, r0, #0
	ldr r1, [r5]
	mov r0, #0x20
	bl GF_CreateVramTransferManager
	ldr r0, [r5]
	bl SpriteSystem_Alloc
	add r1, r5, #0
	add r1, #0xac
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xac
	ldr r0, [r0]
	ldr r1, _021E6920 ; =ov113_021E6CB0
	ldr r2, _021E6924 ; =ov113_021E6BA4
	mov r3, #2
	bl SpriteSystem_Init
	ldr r0, [r5]
	bl thunk_ClearMainOAM
	ldr r0, [r5]
	bl thunk_ClearSubOAM
	add r0, r5, #0
	add r0, #0xac
	ldr r0, [r0]
	bl SpriteManager_New
	add r1, r5, #0
	add r1, #0xb0
	str r0, [r1]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xac
	add r1, #0xb0
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #0x11
	bl SpriteSystem_InitSprites
	mov r3, #0
	add r0, r5, #0
	add r1, r5, #0
	str r3, [sp]
	add r0, #0xac
	add r1, #0xb0
	ldr r0, [r0]
	ldr r1, [r1]
	ldr r2, _021E6928 ; =ov113_021E6B74
	bl sub_0200D2A4
	ldr r3, _021E692C ; =ov113_021E6BB8
	add r2, sp, #0x10
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	add r0, r5, #0
	add r0, #0xac
	ldr r0, [r0]
	bl SpriteManager_New
	add r1, r5, #0
	add r1, #0xb4
	str r0, [r1]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xac
	add r1, #0xb4
	ldr r0, [r0]
	ldr r1, [r1]
	add r2, sp, #0x10
	bl SpriteSystem_InitManagerWithCapacities
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	bl SpriteManager_GetSpriteList
	add r1, r0, #0
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	bl SpriteManager_SetSpriteList
	ldr r1, [r5]
	mov r0, #0x14
	bl NARC_New
	add r1, r5, #0
	add r1, #0xfc
	str r0, [r1]
	bl sub_02074490
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r1, #1
	add r2, r5, #0
	str r1, [sp, #4]
	mov r0, #3
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xac
	add r1, #0xb4
	add r2, #0xfc
	ldr r0, [r0]
	ldr r1, [r1]
	ldr r2, [r2]
	bl SpriteSystem_LoadPlttResObjFromOpenNarc
	bl sub_02074494
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r5, #0
	add r2, r5, #0
	add r0, #0xac
	add r1, #0xb4
	add r2, #0xfc
	ldr r0, [r0]
	ldr r1, [r1]
	ldr r2, [r2]
	bl SpriteSystem_LoadCellResObjFromOpenNarc
	bl sub_020744A0
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xac
	add r1, #0xb4
	ldr r0, [r0]
	ldr r1, [r1]
	mov r2, #0x14
	bl SpriteSystem_LoadAnimResObj
	mov r4, #0
	add r6, r4, #0
	mov r7, #2
_021E68B4:
	mov r0, #0xc9
	mov r1, #0
	add r2, r4, #0
	bl GetMonIconNaixEx
	str r6, [sp]
	add r3, r0, #0
	add r1, r5, #0
	add r2, r5, #0
	str r7, [sp, #4]
	add r0, r4, #1
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0xac
	add r1, #0xb4
	add r2, #0xfc
	ldr r0, [r0]
	ldr r1, [r1]
	ldr r2, [r2]
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	add r4, r4, #1
	cmp r4, #7
	blt _021E68B4
	mov r4, #7
	mov r6, #0
	mov r7, #1
_021E68EA:
	mov r0, #0xc9
	mov r1, #0
	add r2, r4, #0
	bl GetMonIconNaixEx
	str r6, [sp]
	add r3, r0, #0
	add r1, r5, #0
	add r2, r5, #0
	str r7, [sp, #4]
	add r0, r4, #1
	str r0, [sp, #8]
	add r0, r5, #0
	add r0, #0xac
	add r1, #0xb4
	add r2, #0xfc
	ldr r0, [r0]
	ldr r1, [r1]
	ldr r2, [r2]
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	add r4, r4, #1
	cmp r4, #0xe
	blt _021E68EA
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6920: .word ov113_021E6CB0
_021E6924: .word ov113_021E6BA4
_021E6928: .word ov113_021E6B74
_021E692C: .word ov113_021E6BB8
	thumb_func_end ov113_021E677C

