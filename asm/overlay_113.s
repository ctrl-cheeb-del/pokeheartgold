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

	thumb_func_start UnownReport_Init
UnownReport_Init: ; 0x021E5900
	push {r4, r5, r6, lr}
	add r5, r1, #0
	ldr r1, [r5]
	add r6, r0, #0
	cmp r1, #0
	beq _021E5912
	cmp r1, #1
	beq _021E5954
	b _021E5964
_021E5912:
	bl ov113_021E59F8
	mov r2, #2
	mov r0, #3
	mov r1, #0x98
	lsl r2, r2, #0x10
	bl Heap_Create
	mov r1, #0x16
	add r0, r6, #0
	lsl r1, r1, #4
	mov r2, #0x98
	bl OverlayManager_CreateAndGetData
	mov r2, #0x16
	mov r1, #0
	lsl r2, r2, #4
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x98
	str r0, [r4]
	add r0, r6, #0
	bl OverlayManager_GetArgs
	str r0, [r4, #4]
	add r0, r4, #0
	bl ov113_021E5A7C
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _021E5964
_021E5954:
	bl OverlayManager_GetData
	bl ov113_021E5B70
	cmp r0, #0
	beq _021E5964
	mov r0, #1
	pop {r4, r5, r6, pc}
_021E5964:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end UnownReport_Init


	thumb_func_start UnownReport_Main
UnownReport_Main: ; 0x021E5968
	push {r3, r4, r5, lr}
	add r4, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r4]
	add r5, r0, #0
	cmp r1, #4
	bhi _021E59B2
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021E5984: ; jump table
	.short _021E598E - _021E5984 - 2 ; case 0
	.short _021E5996 - _021E5984 - 2 ; case 1
	.short _021E599E - _021E5984 - 2 ; case 2
	.short _021E59A6 - _021E5984 - 2 ; case 3
	.short _021E59AE - _021E5984 - 2 ; case 4
_021E598E:
	bl ov113_021E5BC4
	str r0, [r4]
	b _021E59B2
_021E5996:
	bl ov113_021E5C0C
	str r0, [r4]
	b _021E59B2
_021E599E:
	bl ov113_021E5C60
	str r0, [r4]
	b _021E59B2
_021E59A6:
	bl ov113_021E5C68
	str r0, [r4]
	b _021E59B2
_021E59AE:
	mov r0, #1
	pop {r3, r4, r5, pc}
_021E59B2:
	add r0, r5, #0
	add r0, #0xb0
	ldr r0, [r0]
	bl SpriteSystem_DrawSprites
	add r5, #0xb4
	ldr r0, [r5]
	bl SpriteSystem_DrawSprites
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end UnownReport_Main
