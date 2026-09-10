
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

	thumb_func_start ov80_02239914
ov80_02239914: ; 0x02239914
	push {r3, r4, r5, lr}
	add r5, r2, #0
	add r4, r3, #0
	bl sub_0209686C
	str r5, [r0]
	str r4, [r0, #4]
	ldr r3, [sp, #0x10]
	add r0, #8
	mov r2, #0xf
_02239928:
	ldrh r1, [r3]
	add r3, r3, #2
	strh r1, [r0]
	add r0, r0, #2
	sub r2, r2, #1
	bne _02239928
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov80_02239914
