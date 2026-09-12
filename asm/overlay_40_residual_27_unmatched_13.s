	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public BgClearTilemapBufferAndCommit
	.public FrontierData_BattlePointAction
	.public GfGfx_EngineBTogglePlanes
	.public Heap_Alloc
	.public MI_CpuFill8
	.public PaletteData_BlendPalettes
	.public PlaySE
	.public Save_FrontierData_Get
	.public SetBgPriority
	.public ov40_0222BF80
	.public ov40_0222D874
	.public ov40_0222D980
	.public ov40_0222D9E8
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222FB90
	.public ov40_0222FBB4
	.public ov40_02230738
	.public ov40_02230964
	.public ov40_0223316C
	.public ov40_02233238
	.public ov40_02233550
	.public ov40_022335F4
	.public ov40_022339CC
	.public ov40_02233C3C
	.public ov40_02233CAC
	.public sub_020879E0
	.text

	thumb_func_start ov40_02233CAC
ov40_02233CAC: ; 0x02233CAC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r0, [r4, #8]
	cmp r0, #0
	bne _02233D4E
	mov r0, #0x6d
	mov r1, #0xdc
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0xdc
	add r5, r0, #0
	bl MI_CpuFill8
	mov r0, #0x86
	lsl r0, r0, #4
	str r5, [r4, r0]
	mov r0, #0
	str r0, [r5]
	add r1, r5, #0
	add r2, r0, #0
	mov r7, #0x40
	mov r6, #0x34
_02233CDC:
	sub r3, r0, #2
	cmp r3, #1
	bhi _02233CE6
	str r6, [r1, #0x18]
	b _02233CE8
_02233CE6:
	str r7, [r1, #0x18]
_02233CE8:
	ldr r3, _02233EE0 ; =0x3E4CCCCD
	str r2, [r1, #0x2c]
	str r3, [r1, #4]
	add r0, r0, #1
	add r1, r1, #4
	add r2, #0x48
	cmp r0, #5
	blt _02233CDC
	ldr r0, [r4, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xd4
	add r1, #0xd8
	mov r2, #0
	bl ov40_0222D9E8
	mov r0, #4
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r2, #0
	add r0, r5, #0
	add r1, r5, #0
	add r0, #0xd4
	add r1, #0xd8
	add r3, r2, #0
	str r2, [sp, #8]
	bl ov40_0222D980
	ldr r0, _02233EE4 ; =0x00000579
	bl PlaySE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02233D54
_02233D4E:
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r5, [r4, r0]
_02233D54:
	ldr r0, [r4, #8]
	cmp r0, #4
	bls _02233D5C
	b _02233ED0
_02233D5C:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02233D68: ; jump table
	.short _02233ED0 - _02233D68 - 2 ; case 0
	.short _02233D72 - _02233D68 - 2 ; case 1
	.short _02233DE6 - _02233D68 - 2 ; case 2
	.short _02233E42 - _02233D68 - 2 ; case 3
	.short _02233E86 - _02233D68 - 2 ; case 4
_02233D72:
	add r0, r5, #0
	mov r1, #1
	bl ov40_0222DA84
	cmp r0, #0
	beq _02233D9C
	mov r0, #0x83
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Save_FrontierData_Get
	mov r1, #0
	add r2, r1, #0
	bl FrontierData_BattlePointAction
	add r1, r5, #0
	add r1, #0x90
	str r0, [r1]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02233D9C:
	ldr r0, [r4, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	mov r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02233ED8
_02233DE6:
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0222D874
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r4, #0
	mov r1, #0
	bl ov40_0222FB90
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl sub_020879E0
	bl ov40_02230738
	mov r0, #6
	mov r1, #2
	bl SetBgPriority
	add r0, r4, #0
	bl ov40_02233238
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0x1c
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02233ED8
_02233E42:
	add r0, r4, #0
	bl ov40_0222FBB4
	cmp r0, #0
	beq _02233ED8
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0223316C
	add r0, r4, #0
	bl ov40_022335F4
	add r0, r4, #0
	bl ov40_02233550
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02233ED8
_02233E86:
	add r0, r4, #0
	bl ov40_022339CC
	add r6, r0, #0
	add r0, r5, #0
	add r1, r5, #0
	mov r2, #0
	add r0, #0xd4
	add r1, #0xd8
	add r3, r2, #0
	bl ov40_0222DA00
	add r0, r5, #0
	mov r1, #0
	bl ov40_0222DA84
	cmp r6, #0
	bne _02233EB6
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	add r0, r4, #0
	bl ov40_02233C3C
_02233EB6:
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0x1c
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02233ED8
_02233ED0:
	add r0, r4, #0
	mov r1, #1
	bl ov40_0222BF80
_02233ED8:
	mov r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_02233EE0: .word 0x3E4CCCCD
_02233EE4: .word 0x00000579
	thumb_func_end ov40_02233CAC
