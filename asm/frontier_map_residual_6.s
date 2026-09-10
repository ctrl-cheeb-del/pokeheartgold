
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

	thumb_func_start ov80_02239510
ov80_02239510: ; 0x02239510
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r0, #0
	ldr r0, [r6, #8]
	add r5, r1, #0
	add r4, r2, #0
	bl sub_02096868
	mov r1, #0
	mvn r1, r1
	cmp r4, r1
	bne _02239540
	mov r4, #0
_0223952A:
	ldr r1, [r0]
	cmp r1, #0
	beq _02239538
	add r4, r4, #1
	add r0, #0x3c
	cmp r4, #0x20
	blt _0223952A
_02239538:
	cmp r4, #0x20
	bne _02239540
	bl GF_AssertFail
_02239540:
	mov r0, #6
	ldrsh r0, [r5, r0]
	add r1, sp, #8
	strh r0, [r1]
	mov r0, #8
	ldrsh r0, [r5, r0]
	strh r0, [r1, #2]
	ldrh r0, [r5, #4]
	strh r0, [r1, #4]
	ldrh r0, [r5, #2]
	strh r0, [r1, #6]
	ldrb r0, [r5, #0xa]
	strh r0, [r1, #8]
	ldrh r0, [r5]
	strh r0, [r1, #0xa]
	ldr r0, [r6, #0x14]
	add r1, sp, #8
	bl ov42_022280B8
	str r0, [sp, #4]
	ldr r0, [r6, #0x20]
	ldr r1, [sp, #4]
	mov r2, #0
	mov r3, #0x65
	bl ov42_0222903C
	ldrb r1, [r5, #0xb]
	add r7, r0, #0
	bl ov42_02229200
	str r5, [sp]
	ldr r0, [r6, #8]
	ldr r2, [sp, #4]
	add r1, r4, #0
	add r3, r7, #0
	bl ov80_02239914
	ldr r0, [sp, #4]
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov80_02239510
