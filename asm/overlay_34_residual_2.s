	.include "asm/macros.inc"
	.public ov34_0225D520
	.public ov34_0225D558
	.public ov34_0225D5A0
	.public ov34_0225D5F8
	.public ov34_0225D650
	.public ov34_0225D77C
	.public ov34_0225D7A8
	.public ov34_0225D87C
	.public ov34_0225D900
	.public ov34_0225D924
	.public ov34_0225DA50
	.public ov34_0225DB20
	.public ov34_0225DC00
	.public ov34_0225DC0C
	.public ov34_0225DC18
	.public ov34_0225DD04
	.public ov34_0225DDB8
	.public ov34_0225DE04
	.public ov34_0225DE94
	.public ov34_0225E020
	.public ov34_0225E0E4
	.public ov34_0225E164
	.public ov34_0225E1C4
	.public ov34_0225E2BC
	.public ov34_0225E348
	.public ov34_0225E428
	.public ov34_0225E4A8
	.public ov34_0225E4F8
	.public ov34_0225E560
	.public ov34_0225E56C
	.public ov34_0225E58C
	.public ov34_0225E5D4
	.public ov34_0225E5DC
	.public ov34_0225E5E4
	.public ov34_0225E5EC
	.public ov34_0225E630
	.public _0225E694
	.public ov34_0225E6A0
	.public ov34_0225E6AC
	.public ov34_0225E6C0
	.public ov34_0225E6DC
	.public ov34_0225E6F8
	.public ov34_0225E714
	.public ov34_0225E730
	.include "overlay_34.inc"
	.include "global.inc"

	.text

	thumb_func_start ov34_0225D650
ov34_0225D650: ; 0x0225D650
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	add r7, r0, #0
	mov r0, #0xa0
	str r0, [sp, #0x24]
	mov r0, #0xd0
	str r0, [sp, #0x20]
	mov r0, #5
	str r0, [sp, #0x1c]
	ldr r0, _0225D774 ; =0x00000265
	add r5, r1, #0
	str r2, [sp, #0x14]
	mov r4, #0
	mov r6, #3
	str r0, [sp, #0x18]
_0225D66E:
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #8
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x24]
	add r2, r4, #4
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r2, r2, #0x18
	str r0, [sp, #0x10]
	add r0, r7, #0
	add r1, r5, #0
	lsr r2, r2, #0x18
	mov r3, #1
	bl AddWindowParameterized
	add r0, r5, #0
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	bl CopyWindowToVram
	ldr r0, [sp, #0x1c]
	add r2, r4, #4
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r0, #5
	str r0, [sp, #8]
	mov r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x20]
	add r1, r5, #0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	lsl r2, r2, #0x18
	str r0, [sp, #0x10]
	add r0, r7, #0
	add r1, #0x10
	lsr r2, r2, #0x18
	mov r3, #2
	bl AddWindowParameterized
	add r0, r5, #0
	add r0, #0x10
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x10
	bl CopyWindowToVram
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0xf
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x18]
	add r2, r4, #4
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	add r1, r5, #0
	lsl r2, r2, #0x18
	str r0, [sp, #0x10]
	add r0, r7, #0
	add r1, #0x20
	lsr r2, r2, #0x18
	mov r3, #0xc
	bl AddWindowParameterized
	add r0, r5, #0
	add r0, #0x20
	mov r1, #0
	bl FillWindowPixelBuffer
	add r0, r5, #0
	add r0, #0x20
	bl CopyWindowToVram
	ldr r0, [sp, #0x24]
	add r4, r4, #1
	add r0, #0x10
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x20]
	add r6, r6, #7
	add r0, #0x87
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	add r5, #0x38
	add r0, r0, #7
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	add r0, #0x1e
	str r0, [sp, #0x18]
	cmp r4, #3
	blt _0225D66E
	mov r0, #0
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, _0225D778 ; =0x000002BF
	ldr r1, [sp, #0x14]
	str r0, [sp, #0x10]
	add r0, r7, #0
	mov r2, #4
	mov r3, #8
	bl AddWindowParameterized
	ldr r0, [sp, #0x14]
	mov r1, #0
	bl FillWindowPixelBuffer
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225D774: .word 0x00000265
_0225D778: .word 0x000002BF
	thumb_func_end ov34_0225D650
