	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public GF_SinDeg
	.public Heap_Alloc
	.public Heap_Free
	.public MI_CpuFill8
	.public ManagedSprite_GetSpritePositionFxXY
	.public ManagedSprite_SetPositonFxXY
	.public PaletteData_BlendPalettes
	.public TextOBJ_SetSpritesDrawFlag
	.public _s32_div_f
	.public ov40_0222C39C
	.public ov40_0222D288
	.public ov40_0222D294
	.public ov40_0223142C
	.public sub_020136B4
	.public sub_020878B8
	.public sub_02087948
	.public sub_020879E0
	.text

	thumb_func_start ov40_0223142C
ov40_0223142C: ; 0x0223142C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	ldr r0, [r5, #8]
	cmp r0, #0
	beq _0223143E
	cmp r0, #1
	beq _0223152A
	b _0223161A
_0223143E:
	mov r0, #0x6d
	mov r1, #0x54
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x54
	add r4, r0, #0
	bl MI_CpuFill8
	mov r0, #0x86
	lsl r0, r0, #4
	str r4, [r5, r0]
	add r0, r4, #0
	add r3, r4, #0
	mov r1, #0x10
	add r0, #0x50
	strb r1, [r0]
	ldr r0, [r5, #0x58]
	add r3, #0x50
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldrb r3, [r3]
	ldr r0, [r5, #0x28]
	mov r1, #2
	mov r2, #0xc
	bl PaletteData_BlendPalettes
	mov r0, #0
	str r0, [sp, #0x14]
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	cmp r0, #0
	ble _02231522
	ldr r0, [sp, #0x14]
	mov r7, #0x19
	str r0, [sp, #4]
	add r6, r5, #0
_0223148C:
	ldr r0, [sp, #4]
	mov r2, #0x6e
	str r0, [r4]
	mov r0, #0x5a
	str r0, [r4, #4]
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	mov r0, #5
	sub r0, r0, r1
	lsl r0, r0, #4
	add r0, r7, r0
	strh r0, [r4, #8]
	lsl r2, r2, #4
	ldr r3, [r5, r2]
	mov r2, #5
	sub r2, r2, r3
	ldr r0, _02231690 ; =0x000005FC
	lsl r2, r2, #4
	add r2, #0xa9
	lsl r2, r2, #0x10
	ldr r0, [r6, r0]
	mov r1, #0x2a
	asr r2, r2, #0x10
	bl ov40_0222D288
	ldr r0, _02231690 ; =0x000005FC
	add r1, r4, #0
	ldr r0, [r6, r0]
	add r1, #0xc
	add r2, sp, #0x20
	bl ManagedSprite_GetSpritePositionFxXY
	mov r2, #0x6e
	lsl r2, r2, #4
	ldr r3, [r5, r2]
	mov r2, #5
	ldr r0, _02231690 ; =0x000005FC
	sub r2, r2, r3
	lsl r2, r2, #4
	add r2, #0xa9
	ldr r0, [r6, r0]
	ldr r1, [r4, #0xc]
	lsl r2, r2, #0xc
	bl ManagedSprite_SetPositonFxXY
	mov r0, #0x61
	lsl r0, r0, #4
	mov r1, #0x24
	add r2, r1, #0
	ldr r0, [r6, r0]
	sub r2, #0x2c
	bl sub_020136B4
	mov r0, #0x61
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	ldr r0, [sp, #4]
	add r4, #0x10
	add r0, r0, #4
	str r0, [sp, #4]
	ldr r0, [sp, #0x14]
	add r7, #0x24
	add r0, r0, #1
	str r0, [sp, #0x14]
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	ldr r0, [sp, #0x14]
	add r6, #0x28
	cmp r0, r1
	blt _0223148C
_02231522:
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223168A
_0223152A:
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r4, [r5, r0]
	add r0, r4, #0
	add r0, #0x50
	ldrb r0, [r0]
	cmp r0, #0
	beq _02231560
	add r0, r4, #0
	add r0, #0x50
	ldrb r0, [r0]
	add r3, r4, #0
	add r3, #0x50
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x50
	strb r1, [r0]
	ldr r0, [r5, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldrb r3, [r3]
	ldr r0, [r5, #0x28]
	mov r2, #0xc
	bl PaletteData_BlendPalettes
_02231560:
	mov r0, #0
	str r0, [sp, #0xc]
	str r0, [sp, #0x10]
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	cmp r1, #0
	ble _0223160C
	add r6, r5, #0
	add r7, sp, #0x18
_02231574:
	ldr r0, [r4]
	cmp r0, #0
	beq _02231580
	sub r0, r0, #1
	str r0, [r4]
	b _022315F6
_02231580:
	ldr r0, _02231690 ; =0x000005FC
	add r1, sp, #0x1c
	ldr r0, [r6, r0]
	add r1, #2
	add r2, sp, #0x1c
	bl ov40_0222D294
	mov r0, #8
	mov r1, #4
	ldrsh r0, [r4, r0]
	ldrsh r2, [r7, r1]
	cmp r2, r0
	bne _022315A2
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	b _022315F6
_022315A2:
	add r1, r2, #0
	sub r1, #8
	cmp r1, r0
	ble _022315B0
	sub r2, #8
	strh r2, [r7, #4]
	b _022315B2
_022315B0:
	strh r0, [r7, #4]
_022315B2:
	mov r0, #4
	ldrsh r0, [r7, r0]
	ldr r1, [r4, #4]
	lsl r0, r0, #0xc
	str r0, [sp, #8]
	ldr r0, _02231694 ; =0x0000FFFF
	mul r0, r1
	mov r1, #0x5a
	lsl r1, r1, #2
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl GF_SinDeg
	lsl r1, r0, #4
	ldr r0, [r4, #4]
	ldr r2, [r4, #0xc]
	sub r0, r0, #4
	str r0, [r4, #4]
	ldr r0, _02231690 ; =0x000005FC
	add r1, r2, r1
	ldr r0, [r6, r0]
	ldr r2, [sp, #8]
	bl ManagedSprite_SetPositonFxXY
	mov r0, #0x61
	lsl r0, r0, #4
	mov r1, #0x24
	add r2, r1, #0
	ldr r0, [r6, r0]
	sub r2, #0x2c
	bl sub_020136B4
_022315F6:
	ldr r0, [sp, #0x10]
	add r4, #0x10
	add r0, r0, #1
	str r0, [sp, #0x10]
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	ldr r0, [sp, #0x10]
	add r6, #0x28
	cmp r0, r1
	blt _02231574
_0223160C:
	ldr r0, [sp, #0xc]
	cmp r0, r1
	bne _0223168A
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _0223168A
_0223161A:
	ldr r1, _02231698 ; =0x000006E4
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r2, [r5, r1]
	ldr r4, [r5, r0]
	mov r0, #0x28
	mul r0, r2
	add r0, r5, r0
	sub r1, #0xe8
	ldr r0, [r0, r1]
	add r1, sp, #0x18
	add r1, #2
	add r2, sp, #0x18
	bl ov40_0222D294
	mov r0, #0x6f
	lsl r0, r0, #4
	add r2, sp, #0x18
	mov r1, #2
	ldrsh r1, [r2, r1]
	mov r3, #0
	ldrsh r2, [r2, r3]
	add r1, #0x10
	lsl r1, r1, #0x10
	ldr r0, [r5, r0]
	asr r1, r1, #0x10
	bl sub_02087948
	mov r0, #0x6f
	lsl r0, r0, #4
	add r2, sp, #0x18
	mov r1, #2
	ldrsh r1, [r2, r1]
	mov r3, #0
	ldrsh r2, [r2, r3]
	add r1, #0x10
	lsl r1, r1, #0x10
	ldr r0, [r5, r0]
	asr r1, r1, #0x10
	bl sub_020878B8
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl sub_020879E0
	add r0, r5, #0
	bl ov40_0222C39C
	add r0, r4, #0
	bl Heap_Free
	add sp, #0x24
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0223168A:
	mov r0, #0
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02231690: .word 0x000005FC
_02231694: .word 0x0000FFFF
_02231698: .word 0x000006E4
	thumb_func_end ov40_0223142C
