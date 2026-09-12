	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public BgClearTilemapBufferAndCommit
	.public BgSetPosTextAndCommit
	.public Heap_Free
	.public Main_SetVBlankIntrCB
	.public PaletteData_BlendPalettes
	.public PlaySE
	.public SetBgPriority
	.public StopSE
	.public UnloadOverlayByID
	.public ov39_022273B0
	.public ov39_02227D44
	.public ov40_0222BC54
	.public ov40_0222BD04
	.public ov40_0222BF64
	.public ov40_0222BF80
	.public ov40_0222D88C
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAA8
	.public ov40_0222DD08
	.public ov40_0222DED0
	.public ov40_0222DFB0
	.public ov40_0222FB28
	.public ov40_0222FB90
	.public ov40_0222FBB4
	.public ov40_0223077C
	.public ov40_02230964
	.public ov40_02230CDC
	.public ov40_022344D8
	.public ov40_0223480C
	.public ov40_02235994
	.public ov40_02235B10
	.public ov40_02236130
	.public ov40_0223D540
	.public ov40_0223D5CC
	.public ov41_0224B57C
	.public sub_020314A4
	.public sub_020314BC
	.public sub_020314C4
	.public sub_020879E0
	.public sub_02087A08
	.text

	thumb_func_start ov40_022344D8
ov40_022344D8: ; 0x022344D8
	push {r3, r4, r5, lr}
	sub sp, #8
	mov r1, #0x86
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r5, [r4, r1]
	bl ov40_0223D5CC
	cmp r0, #0
	bne _022344F2
	add sp, #8
	mov r0, #0
	pop {r3, r4, r5, pc}
_022344F2:
	ldr r0, [r4, #8]
	cmp r0, #6
	bls _022344FA
	b _0223473E
_022344FA:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02234506: ; jump table
	.short _02234514 - _02234506 - 2 ; case 0
	.short _02234586 - _02234506 - 2 ; case 1
	.short _022345FA - _02234506 - 2 ; case 2
	.short _02234652 - _02234506 - 2 ; case 3
	.short _0223467E - _02234506 - 2 ; case 4
	.short _022346CE - _02234506 - 2 ; case 5
	.short _022346F0 - _02234506 - 2 ; case 6
_02234514:
	mov r0, #0
	mov r1, #1
	bl SetBgPriority
	mov r0, #1
	mov r1, #3
	bl SetBgPriority
	mov r0, #2
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #3
	mov r1, #1
	bl SetBgPriority
	mov r0, #4
	mov r1, #1
	bl SetBgPriority
	mov r0, #5
	mov r1, #3
	bl SetBgPriority
	mov r0, #6
	mov r1, #2
	bl SetBgPriority
	mov r0, #7
	mov r1, #1
	bl SetBgPriority
	mov r0, #0x8e
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Heap_Free
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl sub_020314BC
	ldr r0, [r4, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	bl ov40_02236130
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022347F2
_02234586:
	add r0, r5, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #1
	mov r3, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _022345E0
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_02235B10
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r4, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r4, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	mov r2, #0
	ldr r0, [r4, #0x24]
	mov r1, #2
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_022345E0:
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _022347F2
_022345FA:
	mov r1, #0x6f
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	add r0, r4, #0
	mov r2, #0x80
	mov r3, #0x60
	bl ov40_0223077C
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	mov r1, #0x18
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl sub_02087A08
	ldr r1, _022347F8 ; =0x0000011E
	add r0, r4, #0
	bl ov40_0222DED0
	mov r0, #0x6d
	bl sub_020314A4
	mov r1, #0xb7
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	mov r1, #0x83
	lsl r1, r1, #4
	ldr r1, [r4, r1]
	bl sub_020314C4
	ldr r0, _022347FC ; =0x0000057D
	bl PlaySE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022347F2
_02234652:
	add r0, r4, #0
	bl ov40_0223D540
	mov r2, #0xb7
	lsl r2, r2, #2
	ldr r1, [r5, r2]
	sub r2, #0xb0
	ldr r2, [r5, r2]
	bl ov39_022273B0
	cmp r0, #1
	beq _0223466C
	b _022347F2
_0223466C:
	mov r0, #0xb7
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl sub_020314BC
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022347F2
_0223467E:
	add r0, r4, #0
	bl ov40_0222DFB0
	add r0, r4, #0
	bl ov40_0223D540
	add r1, sp, #4
	bl ov39_02227D44
	cmp r0, #1
	ldr r0, _022347FC ; =0x0000057D
	bne _022346B2
	mov r1, #0
	bl StopSE
	ldr r3, [sp, #4]
	add r0, r4, #0
	ldr r2, [r3, #0xc]
	ldr r3, [r3, #4]
	mov r1, #0
	bl ov40_02230CDC
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022347F2
_022346B2:
	mov r1, #0
	bl StopSE
	add r0, r4, #0
	mov r1, #0x24 ; SCORE_EVENT_UPLOADED_DRESS_UP_DATA
	bl ov40_0222FB28
	ldr r0, _02234800 ; =0x00000577
	bl PlaySE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022347F2
_022346CE:
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	mov r1, #0
	ldr r0, [r4, r0]
	add r2, r1, #0
	bl sub_02087A08
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022347F2
_022346F0:
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r5, #8
	add r0, r5, #0
	bl ov40_0222DAA8
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
	add r0, r4, #0
	mov r1, #1
	bl ov40_0222FB90
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022347F2
_0223473E:
	add r0, r4, #0
	bl ov40_0222FBB4
	cmp r0, #0
	beq _022347F2
	add r0, r5, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	cmp r0, #0
	beq _022347C2
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _02234776
	bl ov41_0224B57C
	add r0, r4, #0
	bl ov40_0222BC54
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	bl ov40_02235994
_02234776:
	add r0, r4, #0
	bl ov40_0222DD08
	add r0, r5, #0
	add r0, #8
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
	add r0, r5, #0
	bl Heap_Free
	ldr r0, _02234804 ; =FS_OVERLAY_ID(OVY_41)
	bl UnloadOverlayByID
	ldr r0, _02234808 ; =ov40_0222BD04
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	b _022347F2
_022347C2:
	ldr r0, [r4, #0x58]
	mov r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
_022347F2:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
_022347F8: .word 0x0000011E
_022347FC: .word 0x0000057D
_02234800: .word 0x00000577
_02234804: .word FS_OVERLAY_ID(OVY_41)
_02234808: .word ov40_0222BD04
	thumb_func_end ov40_022344D8


	thumb_func_start ov40_0223480C
ov40_0223480C: ; 0x0223480C
	push {r3, r4, r5, lr}
	mov r1, #0x86
	add r5, r0, #0
	lsl r1, r1, #4
	ldr r4, [r5, r1]
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _02234826
	cmp r1, #1
	beq _02234898
	cmp r1, #2
	beq _022348F8
	b _02234946
_02234826:
	mov r0, #0
	mov r1, #1
	bl SetBgPriority
	mov r0, #1
	mov r1, #3
	bl SetBgPriority
	mov r0, #2
	add r1, r0, #0
	bl SetBgPriority
	mov r0, #3
	mov r1, #1
	bl SetBgPriority
	mov r0, #4
	mov r1, #1
	bl SetBgPriority
	mov r0, #5
	mov r1, #3
	bl SetBgPriority
	mov r0, #6
	mov r1, #2
	bl SetBgPriority
	mov r0, #7
	mov r1, #1
	bl SetBgPriority
	mov r0, #0x8e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Heap_Free
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl sub_020314BC
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	add r0, r5, #0
	bl ov40_02236130
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02234A08
_02234898:
	add r0, r4, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	add r0, r4, #0
	add r1, r4, #4
	mov r2, #1
	mov r3, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _022348DE
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_02235B10
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_022348DE:
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
	b _02234A08
_022348F8:
	add r4, #8
	add r0, r4, #0
	bl ov40_0222DAA8
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0222D88C
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r5, #0x24]
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x24]
	mov r1, #7
	bl BgClearTilemapBufferAndCommit
	add r0, r5, #0
	mov r1, #1
	bl ov40_0222FB90
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02234A08
_02234946:
	bl ov40_0222FBB4
	cmp r0, #0
	beq _02234A08
	add r0, r4, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	cmp r0, #0
	beq _022349D8
	add r0, r5, #0
	mov r1, #1
	bl ov40_02230964
	mov r0, #0x8a
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #0
	beq _02234984
	bl ov41_0224B57C
	add r0, r5, #0
	bl ov40_0222BC54
	mov r0, #2
	mov r1, #0
	bl SetBgPriority
	bl ov40_02235994
_02234984:
	add r0, r5, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r5, #0
	bl ov40_0222DD08
	add r0, r4, #0
	add r0, #8
	bl ov40_0222DAA8
	ldr r0, [r5, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r5, #0x28]
	mov r2, #0xc
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	mov r1, #1
	ldr r3, [r5, #0x10]
	add r0, r5, #0
	add r2, r1, #0
	bl ov40_0222BF64
	add r0, r5, #0
	mov r1, #5
	bl ov40_0222BF80
	add r0, r4, #0
	bl Heap_Free
	ldr r0, _02234A0C ; =FS_OVERLAY_ID(OVY_41)
	bl UnloadOverlayByID
	ldr r0, _02234A10 ; =ov40_0222BD04
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	b _02234A08
_022349D8:
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
_02234A08:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_02234A0C: .word FS_OVERLAY_ID(OVY_41)
_02234A10: .word ov40_0222BD04
	thumb_func_end ov40_0223480C
