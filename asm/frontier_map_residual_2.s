
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

	thumb_func_start ov80_02238A18
ov80_02238A18: ; 0x02238A18
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r5, r0, #0
	ldr r0, [r5, #8]
	bl sub_02096864
	ldr r7, _02238A78 ; =0x0000FFFF
	add r4, r0, #0
	mov r6, #0
_02238A2A:
	ldrh r1, [r4]
	cmp r1, r7
	beq _02238A3A
	ldrb r2, [r4, #2]
	ldr r0, [r5, #0x20]
	mov r3, #0x65
	bl ov42_02228FE0
_02238A3A:
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #0x18
	blt _02238A2A
	ldr r7, _02238A78 ; =0x0000FFFF
	mov r4, #0
	add r6, sp, #0
_02238A48:
	ldr r0, [r5, #8]
	add r1, r4, #0
	bl sub_0209686C
	ldrh r1, [r0, #0xc]
	cmp r1, r7
	beq _02238A66
	add r1, r6, #0
	bl ov80_02239900
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	bl ov80_02239510
_02238A66:
	add r4, r4, #1
	cmp r4, #0x20
	blt _02238A48
	add r0, r5, #0
	bl ov80_02239828
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02238A78: .word 0x0000FFFF
	thumb_func_end ov80_02238A18
