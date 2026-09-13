	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225E7B0
	.extern ov93_0225EC98

	thumb_func_start ov93_0225E7B0
ov93_0225E7B0: ; 0x0225E7B0
	push {r3, r4, r5, lr}
	mov r1, #0x9e
	add r5, r0, #0
	mov r0, #0x75
	lsl r1, r1, #2
	bl Heap_Alloc
	mov r2, #0x9e
	mov r1, #0
	lsl r2, r2, #2
	add r4, r0, #0
	bl MI_CpuFill8
	ldr r0, [r5]
	ldr r1, [r0, #0x34]
	mov r0, #0x27
	lsl r0, r0, #4
	str r1, [r4, r0]
	add r0, r4, #0
	bl ov93_0225EC98
	add r0, r4, #0
	bl ov93_0225EF0C
	add r0, r4, #0
	bl ov93_0225EF5C
	ldr r0, [r5]
	ldr r0, [r0, #0x34]
	cmp r0, #1
	beq _0225E806
	cmp r0, #2
	bne _0225E81A
	mov r1, #1
	mov r0, #0x26
	lsl r1, r1, #0x12
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #0x1a
	lsl r1, r1, #0xe
	add r0, r0, #4
	str r1, [r4, r0]
	b _0225E828
_0225E806:
	mov r1, #9
	mov r0, #0x26
	lsl r1, r1, #0x10
	lsl r0, r0, #4
	str r1, [r4, r0]
	mov r1, #7
	lsl r1, r1, #0x10
	add r0, r0, #4
	str r1, [r4, r0]
	b _0225E828
_0225E81A:
	mov r1, #6
	mov r0, #0x26
	lsl r1, r1, #0x10
	lsl r0, r0, #4
	str r1, [r4, r0]
	add r0, r0, #4
	str r1, [r4, r0]
_0225E828:
	mov r0, #0x87
	mov r1, #0x80
	lsl r0, r0, #2
	str r1, [r4, r0]
	mov r1, #0x28
	add r0, r0, #4
	str r1, [r4, r0]
	add r0, r5, #0
	bl ov93_0225F9D8
	add r0, r5, #0
	bl ov93_0225FB00
	mov r1, #0x8d
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r1, [r4, r1]
	add r0, r4, #0
	bl ov93_0225FB6C
	mov r1, #2
	mov r0, #0x92
	lsl r1, r1, #0xc
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov93_0225E7B0
