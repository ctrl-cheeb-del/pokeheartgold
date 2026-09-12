	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public BgClearTilemapBufferAndCommit
	.public G2x_SetBlendAlpha_
	.public GfGfxLoader_LoadCharDataFromOpenNarc
	.public GfGfx_EngineATogglePlanes
	.public GfGfx_EngineBTogglePlanes
	.public HandleLoadOverlay
	.public Heap_Alloc
	.public Heap_Free
	.public Main_SetVBlankIntrCB
	.public PaletteData_BlendPalettes
	.public PaletteData_LoadPaletteSlotFromHardware
	.public PlaySE
	.public RequestSwap3DBuffers
	.public Save_FashionData_Get
	.public SetBgPriority
	.public Thunk_G3X_Reset
	.public memset
	.public ov40_0222BC44
	.public ov40_0222BF64
	.public ov40_0222BF80
	.public ov40_0222D874
	.public ov40_0222D88C
	.public ov40_0222D9E8
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAA8
	.public ov40_0222DD08
	.public ov40_0222FB90
	.public ov40_0222FBB4
	.public ov40_022307DC
	.public ov40_02230964
	.public ov40_0223320C
	.public ov40_022338D0
	.public ov40_02233AEC
	.public ov40_02233F28
	.public ov40_0223414C
	.public ov40_022341E0
	.public ov40_02234330
	.public ov40_02235900
	.public ov40_02235940
	.public ov40_02235A30
	.public ov40_02235B4C
	.public ov41_0224B530
	.public ov41_0224B554
	.public ov41_0224B5D0
	.public sub_0202B998
	.public sub_0202B9B8
	.public sub_020314A4
	.public sub_020879E0
	.text

	thumb_func_start ov40_02233F28
ov40_02233F28: ; 0x02233F28
	push {r3, r4, r5, lr}
	add r4, r0, #0
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r5, [r4, r0]
	ldr r0, [r4, #8]
	cmp r0, #4
	bls _02233F3A
	b _0223409E
_02233F3A:
	add r1, r0, r0
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02233F46: ; jump table
	.short _02233F50 - _02233F46 - 2 ; case 0
	.short _02233FAE - _02233F46 - 2 ; case 1
	.short _02233FB2 - _02233F46 - 2 ; case 2
	.short _02233FFA - _02233F46 - 2 ; case 3
	.short _0223403E - _02233F46 - 2 ; case 4
_02233F50:
	ldr r0, [r5]
	cmp r0, #0
	bne _02233F5C
	ldr r0, _0223413C ; =0x0000057A
	bl PlaySE
_02233F5C:
	ldr r0, [r5]
	cmp r0, #0x10
	beq _02233F66
	add r0, r0, #2
	str r0, [r5]
_02233F66:
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
	ldr r0, [r4, #0x58]
	ldr r2, _02234140 ; =0x00004018
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #1
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_02233AEC
	cmp r0, #0
	beq _02233FA2
	b _02234136
_02233FA2:
	mov r0, #0
	str r0, [r5]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234136
_02233FAE:
	add r0, r0, #1
	str r0, [r4, #8]
_02233FB2:
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_022338D0
	add r0, r4, #0
	bl ov40_0223320C
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #8
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0
	str r0, [r5]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234136
_02233FFA:
	mov r0, #1
	bl ov40_0222BC44
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0222D88C
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r4, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02234136
_0223403E:
	ldr r1, [r5]
	cmp r1, #0
	beq _0223404A
	sub r0, r1, #2
	str r0, [r5]
	b _02234136
_0223404A:
	add r0, r0, #1
	str r0, [r4, #8]
	add r0, r5, #0
	bl ov40_0222DAA8
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
	mov r2, #0x1c
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
	b _02234136
_0223409E:
	add r0, r5, #0
	mov r1, #0
	bl ov40_0222DA84
	cmp r0, #0
	beq _02234106
	mov r0, #8
	str r0, [sp]
	ldr r0, _02234144 ; =0x04000050
	mov r1, #4
	mov r2, #0x12
	mov r3, #7
	bl G2x_SetBlendAlpha_
	mov r0, #8
	str r0, [sp]
	ldr r0, _02234148 ; =0x04001050
	mov r1, #4
	mov r2, #0x12
	mov r3, #7
	bl G2x_SetBlendAlpha_
	add r0, r5, #0
	bl Heap_Free
	add r0, r4, #0
	bl ov40_0222DD08
	add r0, r5, #0
	bl ov40_0222DAA8
	ldr r0, [r4, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x28]
	mov r2, #0xc
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	mov r1, #1
	ldr r3, [r4, #0x10]
	add r0, r4, #0
	add r2, r1, #0
	bl ov40_0222BF64
	add r0, r4, #0
	mov r1, #5
	bl ov40_0222BF80
	b _02234136
_02234106:
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
_02234136:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0223413C: .word 0x0000057A
_02234140: .word 0x00004018
_02234144: .word 0x04000050
_02234148: .word 0x04001050
	thumb_func_end ov40_02233F28


	thumb_func_start ov40_0223414C
ov40_0223414C: ; 0x0223414C
	push {r3, r4, r5, lr}
	mov r1, #0xba
	add r5, r0, #0
	mov r0, #0x6d
	lsl r1, r1, #2
	bl Heap_Alloc
	mov r2, #0xba
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl memset
	mov r0, #0x86
	lsl r0, r0, #4
	str r4, [r5, r0]
	ldr r0, _022341DC ; =FS_OVERLAY_ID(OVY_41)
	mov r1, #2
	bl HandleLoadOverlay
	mov r1, #0x86
	ldr r0, [r5, #0x24]
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r2, #0x48
	add r0, r1, #4
	str r2, [r4, r0]
	add r0, r1, #0
	mov r2, #0x10
	add r0, #8
	str r2, [r4, r0]
	mov r0, #0x6d
	add r1, #0xc
	str r0, [r4, r1]
	bl sub_0202B998
	mov r1, #0x8e
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0x6d
	bl sub_020314A4
	mov r1, #0x25
	lsl r1, r1, #4
	str r0, [r4, r1]
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	add r1, r4, #4
	mov r2, #0
	bl ov40_0222D9E8
	add r0, r5, #0
	mov r1, #1
	bl ov40_0222BF80
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_022341DC: .word FS_OVERLAY_ID(OVY_41)
	thumb_func_end ov40_0223414C


	thumb_func_start ov40_022341E0
ov40_022341E0: ; 0x022341E0
	push {r3, r4, r5, lr}
	sub sp, #0x10
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _022341FC
	cmp r1, #1
	beq _0223425A
	cmp r1, #2
	beq _022342AE
	b _022342C4
_022341FC:
	add r0, r4, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	cmp r0, #0
	beq _02234210
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_02234210:
	ldr r0, [r5, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r5, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r5, #0x58]
	mov r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02234328
_0223425A:
	mov r0, #0
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	mov r0, #1
	mov r1, #3
	bl SetBgPriority
	mov r0, #3
	mov r1, #2
	bl SetBgPriority
	mov r0, #4
	mov r1, #0
	bl SetBgPriority
	mov r0, #6
	mov r1, #1
	bl SetBgPriority
	mov r0, #5
	mov r1, #3
	bl SetBgPriority
	mov r0, #7
	mov r1, #2
	bl SetBgPriority
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0
	bl sub_020879E0
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02234328
_022342AE:
	mov r1, #0
	bl ov40_0222FB90
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02234328
_022342C4:
	bl ov40_0222FBB4
	cmp r0, #0
	beq _02234328
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0222D874
	add r0, r5, #0
	bl ov40_02235A30
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x14]
	ldr r2, [r5, #0x24]
	mov r1, #0x3e
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x14]
	ldr r2, [r5, #0x24]
	mov r1, #0x3e
	mov r3, #7
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	add r0, r5, #0
	mov r1, #2
	bl ov40_0222BF80
_02234328:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov40_022341E0


	thumb_func_start ov40_02234330
ov40_02234330: ; 0x02234330
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _0223434A
	cmp r1, #1
	beq _022343DA
	cmp r1, #2
	beq _022343F0
	b _02234440
_0223434A:
	bl ov40_02235940
	add r0, r5, #0
	mov r1, #0x23
	mov r2, #3
	bl ov40_022307DC
	add r0, r5, #0
	mov r1, #0x25
	mov r2, #7
	bl ov40_022307DC
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	mov r0, #0x83
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl Save_FashionData_Get
	mov r1, #0
	bl sub_0202B9B8
	mov r1, #0x8b
	lsl r1, r1, #2
	str r0, [r4, r1]
	sub r0, r1, #4
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _022343B2
	add r0, r1, #0
	sub r0, #0x14
	ldr r1, [r4, r1]
	add r0, r4, r0
	bl ov41_0224B530
	mov r1, #0x8a
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #1
	bl ov41_0224B5D0
_022343B2:
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, _0223446C ; =ov40_02235900
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02234446
_022343DA:
	mov r1, #0
	mov r3, #2
	ldr r0, [r5, #0x28]
	add r2, r1, #0
	lsl r3, r3, #8
	bl PaletteData_LoadPaletteSlotFromHardware
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02234446
_022343F0:
	add r0, r4, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	mov r2, #0
	add r0, r4, #0
	add r1, r4, #4
	add r3, r2, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _02234426
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #1
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	add r0, r5, #0
	bl ov40_02235B4C
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_02234426:
	ldr r0, [r5, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #8]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02234446
_02234440:
	mov r1, #3
	bl ov40_0222BF80
_02234446:
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02234466
	bl Thunk_G3X_Reset
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov41_0224B554
	mov r0, #0
	add r1, r0, #0
	bl RequestSwap3DBuffers
_02234466:
	mov r0, #0
	pop {r3, r4, r5, pc}
	nop
_0223446C: .word ov40_02235900
	thumb_func_end ov40_02234330
