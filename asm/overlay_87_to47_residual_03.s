	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E6BB8
	.extern ov87_021E7E98
	.extern ov87_021E7FC0
	.extern ov87_021E80F0
	.public ov87_021E6780

	.text

thumb_func_start ov87_021E6780
ov87_021E6780: ; 0x021E6780
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r7, #0xbe
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_021E678C:
	ldr r0, [r5, r7]
	cmp r0, #0
	beq _021E6796
	bl ov87_021E7FC0
_021E6796:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _021E678C
	mov r7, #0xc2
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_021E67A6:
	ldr r0, [r4, r7]
	cmp r0, #0
	beq _021E67B0
	bl ov87_021E7FC0
_021E67B0:
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #9
	blt _021E67A6
	mov r0, #0xcf
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	beq _021E67C6
	bl ov87_021E7FC0
_021E67C6:
	mov r0, #0xd
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	cmp r0, #0
	beq _021E67D4
	bl ov87_021E7FC0
_021E67D4:
	mov r7, #0xd1
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #2
_021E67DC:
	ldr r0, [r4, r7]
	cmp r0, #0
	beq _021E67E6
	bl ov87_021E7FC0
_021E67E6:
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #3
	blt _021E67DC
	mov r7, #0x35
	mov r5, #0
	add r4, r6, #0
	lsl r7, r7, #4
_021E67F6:
	ldr r0, [r4, r7]
	cmp r0, #0
	beq _021E6800
	bl ov87_021E7FC0
_021E6800:
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #3
	blt _021E67F6
	mov r0, #0xd7
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	cmp r0, #0
	beq _021E6816
	bl ov87_021E7FC0
_021E6816:
	mov r0, #2
	bl FontID_Release
	mov r0, #0x57
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #2
	bl PaletteData_FreeBuffers
	mov r0, #0x57
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	mov r1, #0
	bl PaletteData_FreeBuffers
	mov r0, #0x57
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl PaletteData_Free
	mov r0, #0x57
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r6, r0]
	add r0, #0x10
	add r0, r6, r0
	bl ov87_021E7E98
	ldr r0, [r6, #0x34]
	bl sub_020164C4
	ldr r0, [r6, #0x38]
	bl DestroyMsgData
	ldr r0, [r6, #0x3c]
	bl MessageFormat_Delete
	ldr r0, [r6, #0x40]
	bl String_Delete
	ldr r0, [r6, #0x44]
	bl String_Delete
	mov r0, #0x16
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl MessagePrinter_Delete
	mov r0, #0xe1
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl Heap_Free
	mov r0, #0xe3
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl Heap_Free
	add r0, r6, #0
	add r0, #0x5c
	bl ov87_021E80F0
	ldr r0, [r6, #0x58]
	bl ov87_021E6BB8
	mov r0, #0xe
	lsl r0, r0, #6
	ldr r0, [r6, r0]
	bl NARC_Delete
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov87_021E6780
