	.include "asm/macros.inc"
	.public Sprite_SetDrawFlag
	.public Sprite_SetAnimCtrlSeq
	.public Sprite_ResetAnimCtrlState
	.public Heap_Alloc
	.public MI_CpuFill8
	.public _fflt
	.public _fadd
	.public _fsub
	.public _ffix
	.public FX_Div
	.public Sprite_SetAffineScale
	.public ov59_0223BE44
	.public SysTask_CreateOnMainQueue
	.public ov59_0223BFC8
	.text

	thumb_func_start ov59_0223BE44
ov59_0223BE44: ; 0x0223BE44
	push {r4, r5, r6, lr}
	add r1, #8
	lsl r5, r1, #2
	mov r1, #0x26
	lsl r1, r1, #4
	add r4, r0, r1
	ldr r0, [r4, r5]
	add r1, r3, #0
	add r6, r2, #0
	bl Sprite_SetDrawFlag
	cmp r6, #0xff
	beq _0223BE6C
	ldr r0, [r4, r5]
	add r1, r6, #0
	bl Sprite_SetAnimCtrlSeq
	ldr r0, [r4, r5]
	bl Sprite_ResetAnimCtrlState
_0223BE6C:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov59_0223BE44


	thumb_func_start ov59_0223BE70
ov59_0223BE70: ; 0x0223BE70
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r6, r1, #0
	mov r1, #0x20
	add r7, r2, #0
	bl Heap_Alloc
	add r4, r0, #0
	mov r1, #0
	mov r2, #0x20
	bl MI_CpuFill8
	str r5, [r4]
	strb r7, [r4, #4]
	mov r0, #0x1e
	strb r0, [r4, #6]
	lsl r0, r6, #1
	ldrh r1, [r5, #0x2e]
	add r0, r6, r0
	asr r1, r0
	mov r0, #7
	and r0, r1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r7, #0
	bne _0223BEFE
	add r1, r5, #0
	add r1, #0x38
	ldrb r1, [r1]
	add r0, r0, r1
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, _0223BFBC ; =0x0000019A
	str r0, [r4, #0x10]
	str r0, [r4, #0x14]
	mov r0, #0
	str r0, [r4, #0x18]
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _0223BED6
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0223BEE4
_0223BED6:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0223BEE4:
	bl _ffix
	add r1, r0, #0
	mov r0, #1
	lsl r0, r0, #0xc
	bl FX_Div
	str r0, [r4, #8]
	mov r0, #0xc
	strh r0, [r4, #0xe]
	mov r0, #0
	strh r0, [r4, #0xc]
	b _0223BF5C
_0223BEFE:
	add r1, r5, #0
	add r1, #0x38
	ldrb r1, [r1]
	sub r0, r0, r1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, _0223BFC0 ; =0x0000119A
	str r0, [r4, #0x10]
	str r0, [r4, #0x14]
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [r4, #0x18]
	ldrb r0, [r4, #6]
	cmp r0, #0
	beq _0223BF2E
	lsl r0, r0, #0xc
	bl _fflt
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	b _0223BF3C
_0223BF2E:
	lsl r0, r0, #0xc
	bl _fflt
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
_0223BF3C:
	bl _ffix
	add r1, r0, #0
	mov r0, #1
	lsl r0, r0, #0xc
	bl FX_Div
	neg r0, r0
	str r0, [r4, #8]
	mov r0, #0xe
	ldrsh r0, [r4, r0]
	sub r0, #0xc
	strh r0, [r4, #0xe]
	mov r0, #0x5a
	lsl r0, r0, #2
	strh r0, [r4, #0xc]
_0223BF5C:
	lsl r0, r6, #2
	add r0, r6, r0
	add r0, r7, r0
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r7, #0
	add r0, #8
	lsl r0, r0, #2
	add r1, r5, r0
	mov r0, #0x26
	lsl r0, r0, #4
	ldr r0, [r1, r0]
	add r1, r4, #0
	add r1, #0x10
	str r0, [r4, #0x1c]
	bl Sprite_SetAffineScale
	add r2, r5, r6
	add r2, #0x30
	ldrb r2, [r2]
	add r0, r5, #0
	add r1, r7, #0
	add r2, r2, #4
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	mov r3, #1
	bl ov59_0223BE44
	ldr r0, _0223BFC4 ; =ov59_0223BFC8
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnMainQueue
	add r0, r5, #0
	add r0, #0x4f
	ldrb r0, [r0]
	add r1, r0, #1
	add r0, r5, #0
	add r0, #0x4f
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x38
	ldrb r0, [r0]
	add r5, #0x38
	add r0, r0, #1
	strb r0, [r5]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0223BFBC: .word 0x0000019A
_0223BFC0: .word 0x0000119A
_0223BFC4: .word ov59_0223BFC8
	thumb_func_end ov59_0223BE70
