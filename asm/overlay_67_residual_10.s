	.include "asm/macros.inc"
	.include "overlay_67.inc"
	.include "global.inc"

	.public ov67_021E6D50
	.public ov67_021E6D5C
	.public ov67_021E6D6C
	.public ov67_021E6D7C
	.public ov67_021E6D90
	.public ov67_021E6DA8
	.public ov67_021E6DC4
	.public ov67_021E6DE0
	.public ov67_021E6DFC
	.public ov67_021E6E18
	.public ov67_021E6E38
	.public ov67_021E6E60
	.public ov67_021E6E98
	.public ov67_021E6EE8
	.public ov67_021E6F50
	.public ov67_021E7020

	.public _021E6D4C

	.text
	.public ov67_021E5900
	.public ov67_021E5968
	.public ov67_021E5984
	.public ov67_021E5A6C
	.public ov67_021E5B44
	.public ov67_021E5BC0
	.public ov67_021E5BE0
	.public ov67_021E5C04
	.public ov67_021E5C44
	.public ov67_021E5DA0
	.public ov67_021E5E84
	.public ov67_021E5EB0
	.public ov67_021E6008
	.public ov67_021E6080
	.public ov67_021E60B4
	.public ov67_021E60F4
	.public ov67_021E6118
	.public ov67_021E6164
	.public ov67_021E61A0
	.public ov67_021E61E8
	.public ov67_021E6220
	.public ov67_021E63E8
	.public ov67_021E6474
	.public ov67_021E6490
	.public ov67_021E6530
	.public ov67_021E65C0
	.public ov67_021E6688
	.public ov67_021E681C
	.public ov67_021E6820
	.public ov67_021E6990
	.public ov67_021E69D8
	.public ov67_021E6A00
	.public ov67_021E6A08
	.public ov67_021E6A28
	.public ov67_021E6A40
	.public ov67_021E6B6C
	.public ov67_021E6BB8
	.public ov67_021E6BC4
	.public ov67_021E6C04
	.public ov67_021E6C14
	.public ov67_021E6C5C
	.public ov67_021E6C60
	.public ov67_021E6D20
	thumb_func_start ov67_021E6C60
ov67_021E6C60: ; 0x021E6C60
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	ldr r0, _021E6D1C ; =0x000004A8
	mov r1, #0
	add r6, r2, #0
	str r1, [r5, r0]
	cmp r4, #2
	bne _021E6C76
	cmp r6, #0
	beq _021E6C8E
_021E6C76:
	cmp r4, #5
	bne _021E6C7E
	cmp r6, #3
	beq _021E6C8E
_021E6C7E:
	cmp r4, #8
	bne _021E6C86
	cmp r6, #6
	beq _021E6C8E
_021E6C86:
	cmp r4, #0xb
	bne _021E6CB2
	cmp r6, #9
	bne _021E6CB2
_021E6C8E:
	mov r0, #0x4a
	lsl r0, r0, #4
	ldrh r1, [r5, r0]
	cmp r1, #0
	beq _021E6C9C
	sub r1, r1, #1
	b _021E6C9E
_021E6C9C:
	mov r1, #2
_021E6C9E:
	strh r1, [r5, r0]
	add r0, r5, #0
	bl ov67_021E6490
	add r0, r5, #0
	bl ov67_021E6530
	ldr r0, _021E6D1C ; =0x000004A8
	mov r1, #1
	str r1, [r5, r0]
_021E6CB2:
	cmp r4, #0
	bne _021E6CBA
	cmp r6, #2
	beq _021E6CD2
_021E6CBA:
	cmp r4, #3
	bne _021E6CC2
	cmp r6, #5
	beq _021E6CD2
_021E6CC2:
	cmp r4, #6
	bne _021E6CCA
	cmp r6, #8
	beq _021E6CD2
_021E6CCA:
	cmp r4, #9
	bne _021E6CF6
	cmp r6, #0xb
	bne _021E6CF6
_021E6CD2:
	mov r0, #0x4a
	lsl r0, r0, #4
	ldrh r1, [r5, r0]
	cmp r1, #2
	bhs _021E6CE0
	add r1, r1, #1
	b _021E6CE2
_021E6CE0:
	mov r1, #0
_021E6CE2:
	strh r1, [r5, r0]
	add r0, r5, #0
	bl ov67_021E6490
	add r0, r5, #0
	bl ov67_021E6530
	ldr r0, _021E6D1C ; =0x000004A8
	mov r1, #2
	str r1, [r5, r0]
_021E6CF6:
	cmp r4, #0xc
	bne _021E6CFE
	mov r1, #0x1e
	b _021E6D0A
_021E6CFE:
	mov r0, #0x4a
	lsl r0, r0, #4
	ldrh r1, [r5, r0]
	mov r0, #0xc
	mul r0, r1
	add r1, r4, r0
_021E6D0A:
	add r0, r5, #0
	bl ov67_021E6688
	add r0, r5, #0
	add r1, r4, #0
	bl ov67_021E6C14
	pop {r4, r5, r6, pc}
	nop
_021E6D1C: .word 0x000004A8
	thumb_func_end ov67_021E6C60

