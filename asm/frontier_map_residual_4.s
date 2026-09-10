
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

	thumb_func_start ov80_022392F8
ov80_022392F8: ; 0x022392F8
	push {r3, lr}
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, _02239364 ; =0x04000008
	mov r1, #3
	ldrh r2, [r0]
	bic r2, r1
	mov r1, #1
	orr r1, r2
	strh r1, [r0]
	add r0, #0x58
	ldrh r2, [r0]
	ldr r1, _02239368 ; =0xFFFFCFFD
	and r2, r1
	strh r2, [r0]
	add r2, r1, #2
	ldrh r3, [r0]
	add r1, r1, #2
	and r3, r2
	mov r2, #0x10
	orr r2, r3
	strh r2, [r0]
	ldrh r3, [r0]
	ldr r2, _0223936C ; =0x0000CFFB
	and r3, r2
	strh r3, [r0]
	ldrh r3, [r0]
	sub r2, #0x1c
	and r3, r1
	mov r1, #8
	orr r1, r3
	strh r1, [r0]
	ldrh r1, [r0]
	and r1, r2
	strh r1, [r0]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl G3X_SetFog
	mov r0, #0
	ldr r2, _02239370 ; =0x00007FFF
	add r1, r0, #0
	mov r3, #0x3f
	str r0, [sp]
	bl G3X_SetClearColor
	ldr r1, _02239374 ; =0xBFFF0000
	ldr r0, _02239378 ; =0x04000580
	str r1, [r0]
	pop {r3, pc}
	.balign 4, 0
_02239364: .word 0x04000008
_02239368: .word 0xFFFFCFFD
_0223936C: .word 0x0000CFFB
_02239370: .word 0x00007FFF
_02239374: .word 0xBFFF0000
_02239378: .word 0x04000580
	thumb_func_end ov80_022392F8
