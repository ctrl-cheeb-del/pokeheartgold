
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

	thumb_func_start ov80_02239740
ov80_02239740: ; 0x02239740
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	ldr r0, [r0, #8]
	bl sub_02096878
	ldr r4, [sp]
	add r6, r0, #0
	ldr r0, _02239814 ; =0x0000FFFF
	add r4, #0x3c
	mov r3, #0
_02239756:
	lsl r2, r3, #1
	add r1, r4, r2
	ldrh r1, [r1, #0x34]
	cmp r1, r0
	beq _02239764
	strh r1, [r6, r2]
	add r3, r3, #1
_02239764:
	add r3, r3, #1
	cmp r3, #8
	blt _02239756
	add r0, r6, #0
	str r0, [sp, #8]
	add r0, #0x12
	str r0, [sp, #8]
	add r0, r6, #0
	add r5, r6, #0
	str r0, [sp, #4]
	add r0, #0x10
	mov r7, #0
	add r5, #0x16
	str r4, [sp, #0xc]
	str r0, [sp, #4]
_02239782:
	ldr r0, [r4]
	cmp r0, #0
	beq _022397F0
	bl ManagedSprite_GetActiveAnim
	strb r0, [r6, #0x15]
	ldr r0, [r4]
	bl ManagedSprite_GetAnimationFrame
	ldrh r2, [r5]
	ldr r1, _02239818 ; =0xFFFFE000
	and r1, r2
	ldr r2, _0223981C ; =0x00001FFF
	and r0, r2
	orr r0, r1
	strh r0, [r5]
	lsl r1, r7, #0x10
	ldr r0, [sp]
	lsr r1, r1, #0x10
	bl ov80_02239734
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r0, r0, #0x1f
	ldrh r2, [r5]
	ldr r1, _02239820 ; =0xFFFFDFFF
	lsr r0, r0, #0x12
	and r1, r2
	orr r0, r1
	strh r0, [r5]
	ldr r0, [r4]
	bl ManagedSprite_GetDrawFlag
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r0, r0, #0x1f
	ldrh r2, [r5]
	ldr r1, _02239824 ; =0xFFFFBFFF
	lsr r0, r0, #0x11
	and r1, r2
	orr r0, r1
	strh r0, [r5]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #4]
	ldrh r0, [r0, #0x20]
	ldr r2, [sp, #8]
	strb r0, [r6, #0x14]
	ldr r0, [r4]
	bl ManagedSprite_GetPositionXY
	mov r0, #2
	ldrh r1, [r5]
	lsl r0, r0, #0xe
	orr r0, r1
	strh r0, [r5]
_022397F0:
	ldr r0, [sp, #0xc]
	add r7, r7, #1
	add r0, r0, #2
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r4, r4, #4
	add r0, #8
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r6, #8
	add r0, #8
	add r5, #8
	str r0, [sp, #4]
	cmp r7, #8
	blt _02239782
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02239814: .word 0x0000FFFF
_02239818: .word 0xFFFFE000
_0223981C: .word 0x00001FFF
_02239820: .word 0xFFFFDFFF
_02239824: .word 0xFFFFBFFF
	thumb_func_end ov80_02239740


	thumb_func_start ov80_02239828
ov80_02239828: ; 0x02239828
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r7, r0, #0
	ldr r0, [r7, #8]
	bl sub_02096878
	add r5, r0, #0
	mov r0, #0xb8
	mov r1, #0x65
	bl NARC_New
	str r0, [sp, #4]
	mov r6, #0
	add r4, r5, #0
_02239844:
	ldrh r1, [r4]
	ldr r0, _022398E0 ; =0x0000FFFF
	cmp r1, r0
	beq _02239862
	str r1, [sp]
	ldr r0, [r7, #0x34]
	ldr r1, [r7, #0x38]
	ldr r2, [sp, #4]
	ldr r3, [r7, #4]
	bl ov80_02239AF8
	ldrh r1, [r4]
	add r0, r7, #0
	bl ov80_0223962C
_02239862:
	add r6, r6, #1
	add r4, r4, #2
	cmp r6, #8
	blt _02239844
	add r4, r5, #0
	mov r6, #0
	add r4, #0x16
_02239870:
	ldrh r0, [r4]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x1f
	cmp r0, #1
	bne _022398C4
	ldrb r2, [r5, #0x14]
	lsl r1, r6, #0x10
	add r0, r7, #0
	lsr r1, r1, #0x10
	bl ov80_0223968C
	mov r1, #0x10
	mov r2, #0x12
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	str r0, [sp, #8]
	bl ManagedSprite_SetPositionXY
	ldrh r1, [r4]
	ldr r0, [sp, #8]
	lsl r1, r1, #0x11
	lsr r1, r1, #0x1f
	bl ManagedSprite_SetDrawFlag
	ldrh r2, [r4]
	lsl r1, r6, #0x10
	add r0, r7, #0
	lsl r2, r2, #0x12
	lsr r1, r1, #0x10
	lsr r2, r2, #0x1f
	bl ov80_02239708
	ldrb r1, [r5, #0x15]
	ldr r0, [sp, #8]
	bl ManagedSprite_SetAnim
	ldrh r1, [r4]
	ldr r0, [sp, #8]
	lsl r1, r1, #0x13
	lsr r1, r1, #0x13
	bl ManagedSprite_SetAnimationFrame
_022398C4:
	add r6, r6, #1
	add r4, #8
	add r5, #8
	cmp r6, #8
	blt _02239870
	ldr r0, [sp, #4]
	bl NARC_Delete
	ldr r0, [r7, #8]
	bl sub_02096884
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_022398E0: .word 0x0000FFFF
	thumb_func_end ov80_02239828
