	.include "asm/macros.inc"
	.public DestroySingle2DGfxResObj
	.public GF_AssertFail
	.public SpriteResourceCollection_Find
	.public SpriteTransfer_DeleteCharTransferTask
	.public SpriteTransfer_DeletePlttTransferTask
	.public sub_0200A740
	.public ov02_0224A8D4
	.text

	thumb_func_start ov02_0224A8D4
ov02_0224A8D4:
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x67
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl SpriteResourceCollection_Find
	add r4, r0, #0
	bl SpriteTransfer_DeleteCharTransferTask
	mov r0, #0x67
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl DestroySingle2DGfxResObj
	mov r1, #0x6b
	mov r0, #0
	add r3, r5, #0
	lsl r1, r1, #2
_r17_a8fe:
	ldr r2, [r3, r1]
	cmp r2, r4
	bne _r17_a912
	lsl r1, r0, #2
	add r2, r5, r1
	mov r1, #0x6b
	mov r3, #0
	lsl r1, r1, #2
	str r3, [r2, r1]
	b _r17_a91a
_r17_a912:
	add r0, r0, #1
	add r3, r3, #4
	cmp r0, #4
	blt _r17_a8fe
_r17_a91a:
	cmp r0, #4
	blt _r17_a922
	bl GF_AssertFail
_r17_a922:
	mov r0, #0x1a
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #3
	bl SpriteResourceCollection_Find
	add r4, r0, #0
	bl SpriteTransfer_DeletePlttTransferTask
	mov r0, #0x1a
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl DestroySingle2DGfxResObj
	mov r1, #0x6f
	mov r0, #0
	add r3, r5, #0
	lsl r1, r1, #2
_r17_a948:
	ldr r2, [r3, r1]
	cmp r2, r4
	bne _r17_a95c
	lsl r1, r0, #2
	add r2, r5, r1
	mov r1, #0x6f
	mov r3, #0
	lsl r1, r1, #2
	str r3, [r2, r1]
	b _r17_a964
_r17_a95c:
	add r0, r0, #1
	add r3, r3, #4
	cmp r0, #3
	blt _r17_a948
_r17_a964:
	cmp r0, #3
	blt _r17_a96c
	bl GF_AssertFail
_r17_a96c:
	mov r0, #0x69
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #3
	bl SpriteResourceCollection_Find
	add r4, r0, #0
	bl sub_0200A740
	mov r0, #0x69
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl DestroySingle2DGfxResObj
	mov r1, #0x72
	mov r0, #0
	add r3, r5, #0
	lsl r1, r1, #2
_r17_a992:
	ldr r2, [r3, r1]
	cmp r2, r4
	bne _r17_a9a6
	lsl r1, r0, #2
	add r2, r5, r1
	mov r1, #0x72
	mov r3, #0
	lsl r1, r1, #2
	str r3, [r2, r1]
	b _r17_a9ae
_r17_a9a6:
	add r0, r0, #1
	add r3, r3, #4
	cmp r0, #4
	blt _r17_a992
_r17_a9ae:
	cmp r0, #4
	blt _r17_a9b6
	bl GF_AssertFail
_r17_a9b6:
	pop {r3, r4, r5, pc}
	thumb_func_end ov02_0224A8D4
