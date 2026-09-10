	.include "asm/macros.inc"
	.include "overlay_120.inc"
	.include "global.inc"

	.public ov120_022601BC
	.public ov120_022601D8
	.public ov120_022601F4
	.public ov120_022601F8
	.public ov120_022601FC
	.public ov120_02260200
	.public ov120_022602E4
	.public ov120_022602FC
	.public ov120_02260314
	.public ov120_0226032C

	.public _0226019C

	.text
	.public ov120_0225F020
	.public ov120_0225F038
	.public ov120_0225F040
	.public ov120_0225F08C
	.public ov120_0225F0FC
	.public ov120_0225F118
	.public ov120_0225F120
	.public ov120_0225F14C
	.public ov120_0225F1E8
	.public ov120_0225F240
	.public ov120_0225F268
	.public ov120_0225F294
	.public ov120_0225F2B8
	.public ov120_0225F318
	.public ov120_0225F4DC
	.public ov120_0225F6AC
	.public ov120_0225F6BC
	.public ov120_0225F6FC
	.public ov120_0225F704
	.public ov120_0225F714
	.public ov120_0225F8B0
	.public ov120_0225F90C
	.public ov120_0225F970
	.public ov120_0225F9D4
	.public ov120_0225FA5C
	.public ov120_0225FA68
	.public ov120_0225FA74
	.public ov120_0225FBAC
	.public ov120_0225FBB8
	.public ov120_0225FBC4
	.public ov120_0225FCFC
	.public ov120_0225FD08
	.public ov120_0225FD14
	.public ov120_0225FD2C
	.public ov120_0225FDA0
	.public ov120_0225FE08
	.public ov120_0225FECC
	.public ov120_0225FEE8
	.public ov120_0225FF00
	thumb_func_start ov120_0225F714
ov120_0225F714: ; 0x0225F714
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r5, r1, #0
	add r6, r0, #0
	ldr r0, [r5]
	ldr r4, [r5, #0xc]
	cmp r0, #5
	bls _0225F726
	b _0225F892
_0225F726:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225F732: ; jump table
	.short _0225F73E - _0225F732 - 2 ; case 0
	.short _0225F7F8 - _0225F732 - 2 ; case 1
	.short _0225F810 - _0225F732 - 2 ; case 2
	.short _0225F81C - _0225F732 - 2 ; case 3
	.short _0225F826 - _0225F732 - 2 ; case 4
	.short _0225F842 - _0225F732 - 2 ; case 5
_0225F73E:
	mov r1, #0x67
	mov r0, #4
	lsl r1, r1, #2
	bl Heap_Alloc
	mov r2, #0x67
	str r0, [r5, #0xc]
	mov r1, #0
	lsl r2, r2, #2
	bl memset
	ldr r4, [r5, #0xc]
	mov r0, #4
	mov r1, #1
	bl AllocWindows
	str r0, [r4]
	mov r3, #0
	str r3, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, [r5, #0x10]
	ldr r1, [r4]
	ldr r0, [r0, #8]
	mov r2, #3
	bl AddWindowParameterized
	mov r1, #0
	add r0, sp, #0x14
	strh r1, [r0]
	mov r0, #3
	add r1, sp, #0x14
	mov r2, #2
	mov r3, #0x1e
	bl BG_LoadPlttData
	ldr r0, [r4]
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	bl ScheduleWindowCopyToVram
	add r0, r4, #0
	add r0, #0x10
	mov r1, #2
	mov r2, #1
	bl ov01_021F05C4
	mov r3, #6
	mov r0, #0
	lsl r3, r3, #6
	str r0, [sp]
	add r1, r4, r3
	add r2, r4, #0
	sub r3, #0x34
	ldr r0, [r5, #0x20]
	add r2, #0x10
	add r3, r4, r3
	bl ov120_0225F9D4
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r5, #0x10]
	ldr r1, _0225F8A4 ; =ov120_0225F8B0
	ldr r0, [r0, #4]
	ldr r0, [r0, #0x1c]
	str r0, [r4, #8]
	mov r0, #0x61
	lsl r0, r0, #2
	add r0, r4, r0
	bl ov120_0225F6FC
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r1, _0225F8A8 ; =ov120_0225F90C
	add r0, r4, r0
	bl ov120_0225F6FC
	mov r0, #0x65
	lsl r0, r0, #2
	ldr r1, _0225F8AC ; =ov120_0225F970
	add r0, r4, r0
	bl ov120_0225F6FC
	mov r0, #1
	str r0, [r5]
	b _0225F892
_0225F7F8:
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	add r1, r0, #0
	sub r1, #0x11
	add r2, r1, #0
	add r3, r5, #4
	bl ov01_021EFCF8
	mov r0, #2
	str r0, [r5]
	b _0225F892
_0225F810:
	ldr r0, [r5, #4]
	cmp r0, #0
	beq _0225F892
	mov r0, #3
	str r0, [r5]
	b _0225F892
_0225F81C:
	mov r0, #0
	str r0, [r4, #0xc]
	mov r0, #4
	str r0, [r5]
	b _0225F892
_0225F826:
	mov r0, #0x61
	lsl r0, r0, #2
	add r1, r4, r0
	ldr r0, [r4, #0xc]
	lsl r0, r0, #3
	add r0, r1, r0
	add r1, r4, #0
	bl ov120_0225F704
	cmp r0, #0
	beq _0225F892
	mov r0, #5
	str r0, [r5]
	b _0225F892
_0225F842:
	mov r0, #0
	bl sub_0200FC20
	ldr r1, [r5, #0x14]
	cmp r1, #0
	beq _0225F852
	mov r0, #1
	str r0, [r1]
_0225F852:
	ldr r0, [r4]
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, [r4]
	bl RemoveWindow
	ldr r0, [r4]
	mov r1, #1
	bl WindowArray_Delete
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl Sprite_Delete
	mov r1, #0x53
	add r0, r4, #0
	lsl r1, r1, #2
	add r0, #0x10
	add r1, r4, r1
	bl ov01_021F06EC
	add r4, #0x10
	add r0, r4, #0
	bl ov01_021F05F4
	add r0, r5, #0
	add r1, r6, #0
	bl ov01_021EFCDC
	add sp, #0x18
	pop {r4, r5, r6, pc}
_0225F892:
	ldr r0, [r5]
	cmp r0, #5
	beq _0225F89E
	ldr r0, [r4, #0x10]
	bl SpriteList_RenderAndAnimateSprites
_0225F89E:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	nop
_0225F8A4: .word ov120_0225F8B0
_0225F8A8: .word ov120_0225F90C
_0225F8AC: .word ov120_0225F970
	thumb_func_end ov120_0225F714

