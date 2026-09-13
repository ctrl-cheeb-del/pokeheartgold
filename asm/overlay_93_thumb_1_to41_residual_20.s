	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225EB70
	.public ov93_0225EC98
	.extern ov93_0225EE4C

	thumb_func_start ov93_0225EB70
ov93_0225EB70: ; 0x0225EB70
	push {r4, r5, r6, lr}
	sub sp, #0x38
	add r5, r0, #0
	ldr r0, _0225EC80 ; =0x2D8B6127
	add r1, sp, #0x1c
	str r0, [sp, #0x1c]
	mov r0, #0x32
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	ldr r0, _0225EC84 ; =0x00007FFF
	add r1, sp, #0x18
	str r0, [sp, #0x18]
	mov r0, #0x33
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	mov r1, #0
	mov r0, #0x11
	add r2, r1, #0
	bl NNS_G3dGeBufferOP_N
	mov r0, #0
	str r0, [sp, #0x2c]
	mov r0, #0x13
	lsl r0, r0, #0xc
	str r0, [sp, #0x30]
	ldr r0, _0225EC88 ; =0xFFFFB000
	add r1, sp, #0x2c
	str r0, [sp, #0x34]
	mov r0, #0x1c
	mov r2, #3
	bl NNS_G3dGeBufferOP_N
	mov r0, #0x99
	lsl r0, r0, #2
	ldr r4, [r5, r0]
	add r0, r0, #6
	ldrsh r0, [r5, r0]
	mov r1, #0x64
	mul r0, r4
	bl _s32_div_f
	mov r1, #0x26
	lsl r1, r1, #4
	add r6, r4, r0
	add r0, r1, #0
	ldr r4, [r5, r1]
	add r0, #8
	add r1, #0xc
	ldrsh r2, [r5, r0]
	ldrsh r0, [r5, r1]
	mov r1, #0x64
	add r0, r2, r0
	mul r0, r4
	bl _s32_div_f
	add r0, r4, r0
	str r0, [sp, #0x20]
	mov r0, #1
	lsl r0, r0, #0xc
	str r0, [sp, #0x28]
	mov r0, #0x1b
	add r1, sp, #0x20
	mov r2, #3
	str r6, [sp, #0x24]
	bl NNS_G3dGeBufferOP_N
	mov r0, #3
	str r0, [sp, #0x14]
	mov r0, #0x10
	add r1, sp, #0x14
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	mov r1, #0
	mov r0, #0x15
	add r2, r1, #0
	bl NNS_G3dGeBufferOP_N
	mov r0, #2
	str r0, [sp, #0x10]
	mov r0, #0x10
	add r1, sp, #0x10
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	mov r0, #1
	add r1, r0, #0
	bl ov93_0225EE4C
	bl ov93_0225EE98
	ldr r1, [r5, #4]
	mov r2, #1
	ldr r0, [r1, #0x2c]
	lsl r4, r0, #0x10
	ldr r0, [r1, #8]
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	ldr r0, _0225EC8C ; =0x1FFFFFFF
	and r1, r0
	ldr r0, _0225EC90 ; =0x72400000
	orr r0, r1
	str r0, [sp, #0xc]
	mov r0, #0x2a
	add r1, sp, #0xc
	bl NNS_G3dGeBufferOP_N
	lsr r0, r4, #0x11
	str r0, [sp, #8]
	mov r0, #0x2b
	add r1, sp, #8
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	ldr r0, _0225EC94 ; =0x001F00C1
	add r1, sp, #4
	str r0, [sp, #4]
	mov r0, #0x29
	mov r2, #1
	bl NNS_G3dGeBufferOP_N
	add r0, r5, #0
	bl ov93_0225EFAC
	mov r2, #1
	mov r0, #0x12
	add r1, sp, #0
	str r2, [sp]
	bl NNS_G3dGeBufferOP_N
	bl NNS_G3dGeFlushBuffer
	add sp, #0x38
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0225EC80: .word 0x2D8B6127
_0225EC84: .word 0x00007FFF
_0225EC88: .word 0xFFFFB000
_0225EC8C: .word 0x1FFFFFFF
_0225EC90: .word 0x72400000
_0225EC94: .word 0x001F00C1
	thumb_func_end ov93_0225EB70


	thumb_func_start ov93_0225EC98
ov93_0225EC98: ; 0x0225EC98
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0xc9
	mov r1, #0x1d
	mov r2, #0x75
	bl AllocAndReadWholeNarcMemberByIdPair
	str r0, [r5]
	bl NNS_G3dGetTex
	str r0, [r5, #4]
	bl GF3dRender_AllocAndLoadTexResources
	ldr r6, [r5, #4]
	ldrh r0, [r6, #0x30]
	ldr r7, [r6, #0x38]
	lsl r4, r0, #3
	ldr r0, [r6, #0x2c]
	lsl r0, r0, #0x10
	lsr r0, r0, #0xd
	str r0, [sp]
	mov r0, #0x93
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0225ECD0
	bl GF_AssertFail
_0225ECD0:
	mov r0, #0x75
	add r1, r4, #0
	bl Heap_Alloc
	mov r1, #0x93
	lsl r1, r1, #2
	str r0, [r5, r1]
	mov r0, #0x75
	add r1, r4, #0
	bl Heap_Alloc
	mov r1, #0x25
	lsl r1, r1, #4
	str r0, [r5, r1]
	sub r1, r1, #4
	ldr r1, [r5, r1]
	add r0, r6, r7
	add r2, r4, #0
	bl MI_CpuCopy8
	mov r1, #0x25
	lsl r1, r1, #4
	ldr r1, [r5, r1]
	add r0, r6, r7
	add r2, r4, #0
	bl MI_CpuCopy8
	mov r0, #0x25
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl DC_FlushRange
	mov r1, #0x96
	ldr r0, [sp]
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r0, r1, #4
	str r4, [r5, r0]
	ldr r0, [r5, #4]
	ldr r0, [r0, #0x14]
	cmp r0, #0
	bne _0225ED2A
	bl GF_AssertFail
_0225ED2A:
	ldr r2, [r5, #4]
	ldr r0, [r5]
	ldr r1, [r2, #0x14]
	add r1, r2, r1
	sub r1, r1, r0
	bl Heap_Realloc
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov93_0225EC98
