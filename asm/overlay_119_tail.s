	.include "asm/macros.inc"
	.include "overlay_119.inc"
	.include "global.inc"

	.text

	thumb_func_start ov119_02260258
ov119_02260258: ; 0x02260258
	push {r4, r5, r6, r7, lr}
	sub sp, #0x44
	str r0, [sp, #0x14]
	add r0, r1, #0
	ldr r0, [r0]
	str r1, [sp, #0x18]
	ldr r4, [r1, #0xc]
	cmp r0, #9
	bls _0226026C
	b _02260688
_0226026C:
	add r1, r0, r0
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02260278: ; jump table
	.short _0226028C - _02260278 - 2 ; case 0
	.short _02260388 - _02260278 - 2 ; case 1
	.short _022603A8 - _02260278 - 2 ; case 2
	.short _022603C0 - _02260278 - 2 ; case 3
	.short _0226043C - _02260278 - 2 ; case 4
	.short _022604B8 - _02260278 - 2 ; case 5
	.short _0226052E - _02260278 - 2 ; case 6
	.short _0226056E - _02260278 - 2 ; case 7
	.short _022605B4 - _02260278 - 2 ; case 8
	.short _02260604 - _02260278 - 2 ; case 9
_0226028C:
	mov r1, #0x8a
	mov r0, #4
	lsl r1, r1, #2
	bl Heap_Alloc
	ldr r1, [sp, #0x18]
	mov r2, #0x8a
	str r0, [r1, #0xc]
	mov r1, #0
	lsl r2, r2, #2
	bl memset
	ldr r0, [sp, #0x18]
	mov r2, #1
	ldr r4, [r0, #0xc]
	ldr r0, [r0, #0x10]
	ldr r1, [r0, #0x24]
	mov r0, #0x82
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r4, #0
	mov r1, #3
	bl ov01_021F05C4
	mov r0, #1
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #5
	str r0, [sp, #0xc]
	ldr r0, _022605F4 ; =0x000927C0
	mov r2, #0x4f
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	lsl r2, r2, #2
	ldr r0, [r0, #0x20]
	add r1, r4, #0
	add r2, r4, r2
	mov r3, #0
	bl ov01_021F0614
	mov r7, #0x4f
	mov r6, #0
	add r5, r4, #0
	lsl r7, r7, #2
_022602EA:
	mov r0, #0
	mov r2, #0
	str r0, [sp]
	add r3, r2, #0
	str r0, [sp, #4]
	add r0, r4, #0
	add r1, r4, r7
	sub r3, #0x20
	bl ov01_021F0718
	mov r1, #0x17
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #3
	blt _022602EA
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #1
	bl AllocWindows
	mov r1, #2
	lsl r1, r1, #8
	str r0, [r4, r1]
	mov r3, #0
	str r3, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, [sp, #0x18]
	ldr r1, [r4, r1]
	ldr r0, [r0, #0x10]
	mov r2, #3
	ldr r0, [r0, #8]
	bl AddWindowParameterized
	mov r1, #0
	add r0, sp, #0x28
	strh r1, [r0]
	mov r0, #3
	add r1, sp, #0x28
	mov r2, #2
	mov r3, #0x1e
	bl BG_LoadPlttData
	mov r0, #2
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #2
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	bl ScheduleWindowCopyToVram
	mov r0, #4
	bl ov01_021F09BC
	mov r1, #0x81
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _02260688
_02260388:
	mov r1, #0x10
	ldr r3, [sp, #0x18]
	mov r0, #2
	add r2, r1, #0
	str r0, [sp]
	mov r0, #1
	sub r2, #0x20
	add r3, r3, #4
	bl ov01_021EFCF8
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _02260688
_022603A8:
	ldr r1, [sp, #0x18]
	ldr r1, [r1, #4]
	cmp r1, #0
	beq _022603D0
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	mov r0, #0x89
	mov r1, #0
	lsl r0, r0, #2
	strh r1, [r4, r0]
	b _02260688
_022603C0:
	mov r0, #0x89
	lsl r0, r0, #2
	ldrsh r1, [r4, r0]
	sub r1, r1, #1
	strh r1, [r4, r0]
	ldrsh r1, [r4, r0]
	cmp r1, #0
	ble _022603D2
_022603D0:
	b _02260688
_022603D2:
	sub r0, #0xa8
	mov r1, #0x1f
	add r0, r4, r0
	mvn r1, r1
	mov r2, #0xe0
	mov r3, #5
	bl ov01_021EFE34
	mov r1, #2
	ldr r2, _022605F8 ; =0xFFFE0000
	add r0, sp, #0x38
	lsl r1, r1, #0x12
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x6e
	lsl r0, r0, #2
	ldr r2, _022605FC ; =0x0000FFFF
	add r0, r4, r0
	mov r1, #0
	mov r3, #5
	bl ov01_021EFE34
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #2
	bl Sprite_SetAffineOverwriteMode
	mov r1, #0x7d
	mov r3, #1
	lsl r1, r1, #2
	str r3, [r4, r1]
	ldr r0, [sp, #0x18]
	add r1, #0x30
	ldr r0, [r0]
	add r2, r0, #1
	ldr r0, [sp, #0x18]
	str r2, [r0]
	strh r3, [r4, r1]
	b _02260688
_0226043C:
	mov r0, #0x89
	lsl r0, r0, #2
	ldrsh r1, [r4, r0]
	sub r1, r1, #1
	strh r1, [r4, r0]
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bgt _02260548
	sub r0, #0x94
	mov r1, #0x1f
	add r0, r4, r0
	mvn r1, r1
	mov r2, #0xe0
	mov r3, #5
	bl ov01_021EFE34
	mov r1, #0xd
	ldr r2, _022605F8 ; =0xFFFE0000
	add r0, sp, #0x38
	lsl r1, r1, #0x10
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x5d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #0x5d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x73
	lsl r0, r0, #2
	ldr r2, _02260600 ; =0xFFFF0001
	add r0, r4, r0
	mov r1, #0
	mov r3, #5
	bl ov01_021EFE34
	mov r0, #0x5d
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl Sprite_SetAffineOverwriteMode
	mov r1, #0x7e
	mov r0, #1
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [sp, #0x18]
	add r1, #0x2c
	ldr r0, [r0]
	add r2, r0, #1
	ldr r0, [sp, #0x18]
	str r2, [r0]
	mov r0, #3
	strh r0, [r4, r1]
	b _02260688
_022604B8:
	mov r0, #0x89
	lsl r0, r0, #2
	ldrsh r1, [r4, r0]
	sub r1, r1, #1
	strh r1, [r4, r0]
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bgt _02260548
	sub r0, #0x80
	mov r1, #0x1f
	add r0, r4, r0
	mvn r1, r1
	mov r2, #0xe0
	mov r3, #5
	bl ov01_021EFE34
	mov r1, #3
	ldr r2, _022605F8 ; =0xFFFE0000
	add r0, sp, #0x38
	lsl r1, r1, #0x10
	mov r3, #0
	bl ov01_021F074C
	mov r0, #0x5e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, sp, #0x38
	bl Sprite_SetMatrix
	mov r0, #0x5e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0x1e
	lsl r0, r0, #4
	ldr r2, _022605FC ; =0x0000FFFF
	add r0, r4, r0
	mov r1, #0
	mov r3, #5
	bl ov01_021EFE34
	mov r0, #0x5e
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #2
	bl Sprite_SetAffineOverwriteMode
	mov r0, #0x7f
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r4, r0]
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _02260688
_0226052E:
	mov r1, #0x7d
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	cmp r0, #0
	bne _02260548
	add r0, r1, #4
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _02260548
	add r1, #8
	ldr r0, [r4, r1]
	cmp r0, #0
	beq _0226054A
_02260548:
	b _02260688
_0226054A:
	mov r7, #0x17
	mov r6, #0
	add r5, r4, #0
	lsl r7, r7, #4
_02260552:
	ldr r0, [r5, r7]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #3
	blt _02260552
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _02260688
_0226056E:
	mov r0, #0xf
	mov r1, #1
	str r0, [sp]
	mov r0, #0x81
	lsl r0, r0, #2
	lsl r3, r1, #9
	ldr r0, [r4, r0]
	ldr r3, [r4, r3]
	add r2, r1, #0
	bl ov01_021F0A0C
	mov r0, #0x82
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl Camera_GetDistance
	add r1, r0, #0
	mov r0, #0x40
	str r0, [sp]
	mov r0, #0x83
	mov r2, #0xfa
	lsl r0, r0, #2
	lsl r2, r2, #0xe
	mov r3, #0xa
	add r0, r4, r0
	sub r2, r1, r2
	lsl r3, r3, #0xc
	bl ov01_021EFEC8
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _02260688
_022605B4:
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov01_021F0A4C
	add r5, r0, #0
	mov r0, #2
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	bl ScheduleWindowCopyToVram
	mov r0, #0x83
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov01_021EFF28
	mov r1, #0x83
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	sub r1, r1, #4
	ldr r1, [r4, r1]
	bl Camera_SetDistance
	cmp r5, #1
	bne _02260688
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	b _02260688
	nop
_022605F4: .word 0x000927C0
_022605F8: .word 0xFFFE0000
_022605FC: .word 0x0000FFFF
_02260600: .word 0xFFFF0001
_02260604:
	mov r0, #0
	bl sub_0200FC20
	ldr r0, [sp, #0x18]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	beq _02260616
	mov r0, #1
	str r0, [r1]
_02260616:
	mov r7, #0x17
	mov r6, #0
	add r5, r4, #0
	lsl r7, r7, #4
_0226061E:
	ldr r0, [r5, r7]
	bl Sprite_Delete
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #3
	blt _0226061E
	mov r1, #0x4f
	lsl r1, r1, #2
	add r0, r4, #0
	add r1, r4, r1
	bl ov01_021F06EC
	add r0, r4, #0
	bl ov01_021F05F4
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov01_021F09EC
	mov r0, #2
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	bl ClearWindowTilemapAndCopyToVram
	mov r0, #2
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	bl RemoveWindow
	mov r0, #2
	lsl r0, r0, #8
	ldr r0, [r4, r0]
	mov r1, #1
	bl WindowArray_Delete
	mov r0, #3
	mov r1, #0x20
	mov r2, #0
	mov r3, #4
	bl BG_ClearCharDataRange
	ldr r0, [sp, #0x18]
	mov r1, #3
	ldr r0, [r0, #0x10]
	ldr r0, [r0, #8]
	bl BgClearTilemapBufferAndCommit
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x14]
	bl ov01_021EFCDC
_02260688:
	mov r1, #0x5f
	mov r0, #0
	lsl r1, r1, #2
	str r0, [sp, #0x1c]
	add r0, r4, r1
	add r1, #0x3c
	add r5, r4, #0
	str r0, [sp, #0x20]
	add r7, r4, r1
	add r6, r4, #0
_0226069C:
	mov r0, #0x7d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #1
	bne _02260704
	ldr r0, [sp, #0x20]
	bl ov01_021EFE44
	str r0, [sp, #0x24]
	add r0, r7, #0
	bl ov01_021EFE44
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _022606C2
	mov r0, #0x7d
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r5, r0]
_022606C2:
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	add r2, sp, #0x2c
	ldmia r3!, {r0, r1}
	mov ip, r2
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	mov r1, ip
	str r0, [r2]
	mov r0, #0x5f
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	lsl r0, r0, #0xc
	str r0, [sp, #0x30]
	mov r0, #0x17
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl Sprite_SetMatrix
	mov r1, #0x6e
	lsl r1, r1, #2
	mov r0, #0x17
	ldr r1, [r6, r1]
	lsl r0, r0, #4
	lsl r1, r1, #0x10
	ldr r0, [r5, r0]
	lsr r1, r1, #0x10
	bl Sprite_SetAffineZRotation
_02260704:
	ldr r0, [sp, #0x20]
	add r5, r5, #4
	add r0, #0x14
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	add r7, #0x14
	add r0, r0, #1
	add r6, #0x14
	str r0, [sp, #0x1c]
	cmp r0, #3
	blt _0226069C
	ldr r0, [sp, #0x18]
	ldr r0, [r0]
	cmp r0, #9
	beq _02260728
	ldr r0, [r4]
	bl SpriteList_RenderAndAnimateSprites
_02260728:
	add sp, #0x44
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov119_02260258
