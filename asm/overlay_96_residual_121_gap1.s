	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text

	thumb_func_start ov96_022194C4
ov96_022194C4: ; 0x022194C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #0x10]
	cmp r5, #0
	bne _022194D8
	bl GF_AssertFail
_022194D8:
	cmp r6, #0
	bne _022194E0
	bl GF_AssertFail
_022194E0:
	cmp r7, #0
	bne _022194E8
	bl GF_AssertFail
_022194E8:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	bne _022194F2
	bl GF_AssertFail
_022194F2:
	ldr r0, [sp, #0x28]
	cmp r0, #0
	bne _022194FC
	bl GF_AssertFail
_022194FC:
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	bne _02219506
	bl GF_AssertFail
_02219506:
	ldr r0, [sp, #0x34]
	mov r1, #0xc8
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0xc8
	bl MI_CpuFill8
	str r5, [r4, #8]
	str r6, [r4, #0xc]
	str r7, [r4, #0x10]
	add r0, sp, #0x18
	ldrb r1, [r0, #0x18]
	add r0, r4, #0
	add r0, #0x22
	strb r1, [r0]
	ldr r0, [sp, #0x34]
	str r0, [r4, #4]
	ldr r0, [sp, #0x10]
	str r0, [r4, #0x14]
	ldr r0, [sp, #0x28]
	str r0, [r4, #0x18]
	ldr r0, [sp, #0x2c]
	str r0, [r4, #0x1c]
	ldr r0, [sp, #0x38]
	str r0, [r4]
	ldr r1, [r4, #4]
	mov r0, #0x14
	bl NARC_New
	str r0, [r4, #0x24]
	ldr r0, [r4, #4]
	add r3, r4, #0
	str r0, [sp]
	mov r0, #0xf2
	mov r1, #7
	mov r2, #1
	add r3, #0x2c
	bl GfGfxLoader_GetScrnData
	str r0, [r4, #0x28]
	bl sub_02074490
	add r3, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _022195C4 ; =0x00002714
	add r1, r6, #0
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r2, #0x14
	bl SpriteSystem_LoadPlttResObj
	strh r0, [r4, #0x20]
	ldr r0, [sp, #0x38]
	bl ov96_021E5F24
	add r1, r0, #0
	ldr r0, [sp, #0x38]
	bl PokeathlonCourse_GetParticipantUnk04
	add r6, r0, #0
	mov r7, #0
	add r5, r4, #0
_02219590:
	ldr r1, [r4, #4]
	mov r0, #0xb
	bl String_New
	add r1, r5, #0
	add r1, #0xb0
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xb0
	add r1, r6, #0
	ldr r0, [r0]
	add r1, #0x12
	bl CopyU16ArrayToString
	add r7, r7, #1
	add r5, r5, #4
	add r6, #0x28
	cmp r7, #3
	blt _02219590
	add r0, r4, #0
	bl ov96_02219A08
	add r0, r4, #0
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_022195C4: .word 0x00002714
	thumb_func_end ov96_022194C4

