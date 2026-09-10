
	.public FrontierMap_Free
	.public FrontierMap_Init
	.public FrontierMap_LoadPaletteData
	.public FrontierMap_Scroll
	.public FrontierMap_SetVramBank
	.public FrontierMap_Update
	.public ov80_02238A18
	.public ov80_02238B7C
	.public ov80_02238C78
	.public ov80_02238FA0
	.public ov80_02239004
	.public ov80_022392F8
	.public ov80_022393E8
	.public ov80_0223947C
	.public ov80_02239510
	.public ov80_02239740
	.public ov80_02239828
	.public ov80_02239914
	.public ov80_0223D554
	.public ov80_0223D560
	.public ov80_0223D570
	.public ov80_0223D584
	.public ov80_0223D59C
	.public ov80_0223D5B8
	.public ov80_0223D5D8
	.public ov80_0223D600
	.public ov80_0223D654
	.include "asm/macros.inc"
	.include "overlay_80_02238648.inc"
	.include "global.inc"

    .text
	.public FrontierMap_VBlank
	.public ov80_022389C4
	.public ov80_02238AAC
	.public ov80_02238AB0
	.public ov80_02238ABC
	.public ov80_0223927C
	.public ov80_022392DC
	.public ov80_0223937C
	.public ov80_02239384
	.public ov80_022394D8
	.public ov80_02239590
	.public ov80_022395E8
	.public ov80_0223962C
	.public ov80_0223965C
	.public ov80_0223968C
	.public ov80_022396D8
	.public ov80_02239700
	.public ov80_02239708
	.public ov80_02239734
	.public ov80_022398E4
	.public ov80_02239900
	.public ov80_02239938

	thumb_func_start ov80_022393E8
ov80_022393E8: ; 0x022393E8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r6, #0
	add r4, r5, #0
_022393F0:
	ldr r0, [r4, #0x3c]
	cmp r0, #0
	beq _022393FA
	bl ov80_02239BE8
_022393FA:
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #8
	blt _022393F0
	ldr r7, _02239474 ; =0x0000FFFF
	mov r6, #0
	add r4, r5, #0
_02239408:
	add r0, r4, #0
	add r0, #0x70
	ldrh r1, [r0]
	cmp r1, r7
	beq _02239418
	ldr r0, [r5, #0x38]
	bl ov80_02239B7C
_02239418:
	add r6, r6, #1
	add r4, r4, #2
	cmp r6, #8
	blt _02239408
	ldr r7, _02239478 ; =0x0000C350
	mov r4, #0
	add r6, r5, #0
_02239426:
	add r0, r6, #0
	add r0, #0x80
	ldr r0, [r0]
	cmp r0, #0
	beq _0223945A
	bl Sprite_DeleteAndFreeResources
	ldr r1, _02239478 ; =0x0000C350
	ldr r0, [r5, #0x38]
	add r1, r4, r1
	bl SpriteManager_UnloadCharObjById
	ldr r1, _02239478 ; =0x0000C350
	ldr r0, [r5, #0x38]
	add r1, r4, r1
	bl SpriteManager_UnloadPlttObjById
	ldr r1, _02239478 ; =0x0000C350
	ldr r0, [r5, #0x38]
	add r1, r4, r1
	bl SpriteManager_UnloadCellObjById
	ldr r0, [r5, #0x38]
	add r1, r4, r7
	bl SpriteManager_UnloadAnimObjById
_0223945A:
	add r4, r4, #1
	add r6, r6, #4
	cmp r4, #4
	blt _02239426
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	bl SpriteSystem_FreeResourcesAndManager
	ldr r0, [r5, #0x34]
	bl SpriteSystem_Free
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02239474: .word 0x0000FFFF
_02239478: .word 0x0000C350
	thumb_func_end ov80_022393E8


	thumb_func_start ov80_0223947C
ov80_0223947C: ; 0x0223947C
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r0, [r6, #8]
	add r5, r1, #0
	bl sub_02096864
	add r7, r0, #0
	ldrh r3, [r5]
	mov r1, #0
	add r2, r7, #0
_02239490:
	ldrh r0, [r2]
	cmp r3, r0
	beq _022394D2
	add r1, r1, #1
	add r2, r2, #4
	cmp r1, #0x18
	blt _02239490
	ldr r0, _022394D4 ; =0x0000FFFF
	mov r4, #0
	add r2, r7, #0
_022394A4:
	ldrh r1, [r2]
	cmp r1, r0
	beq _022394B2
	add r4, r4, #1
	add r2, r2, #4
	cmp r4, #0x18
	blt _022394A4
_022394B2:
	cmp r4, #0x18
	bne _022394BA
	bl GF_AssertFail
_022394BA:
	ldrh r0, [r5]
	lsl r2, r4, #2
	add r1, r7, r2
	strh r0, [r7, r2]
	ldrh r0, [r5, #2]
	mov r3, #0x65
	strh r0, [r1, #2]
	ldrh r1, [r5]
	ldrb r2, [r5, #2]
	ldr r0, [r6, #0x20]
	bl ov42_02228FE0
_022394D2:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_022394D4: .word 0x0000FFFF
	thumb_func_end ov80_0223947C
