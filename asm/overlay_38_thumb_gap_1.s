.include "asm/macros.inc"
.include "overlay_38_thumb.inc"
.include "global.inc"

.public ov38_0221BA00
.public ov38_0221BA10
.public ov38_0221BB44

	.text

	thumb_func_start ov38_0221BA38
ov38_0221BA38: ; 0x0221BA38
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	mov r0, #0
	add r5, r2, #0
	str r0, [sp, #0x14]
	add r0, r5, #0
	str r0, [sp, #0x10]
	add r0, #8
	add r7, r1, #0
	str r3, [sp]
	str r0, [sp, #0x10]
	bl ov38_0221BB44
	ldr r1, [sp, #0x30]
	add r0, r0, #1
	cmp r1, r0
	bge _0221BA62
	add sp, #0x18
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_0221BA62:
	ldr r1, [sp, #0x10]
	mov r0, #0xa
	bl ov00_021EC2A8
	add r6, r0, #0
	bne _0221BA74
	add sp, #0x18
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0221BA74:
	lsr r0, r4, #0x18
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0x14]
	add r0, r0, r1
	lsr r1, r4, #0x10
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #8]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r0, r0, r1
	lsr r1, r4, #8
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	str r1, [sp, #0xc]
	lsl r1, r1, #0x18
	lsr r1, r1, #0x18
	add r0, r0, r1
	lsl r1, r4, #0x18
	lsr r4, r1, #0x18
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
	add r0, r0, r1
	str r0, [sp, #0x14]
	mov r0, #0
	cmp r5, #0
	ble _0221BAC0
_0221BAB2:
	ldrb r2, [r7, r0]
	ldr r1, [sp, #0x14]
	add r0, r0, #1
	add r1, r1, r2
	str r1, [sp, #0x14]
	cmp r0, r5
	blt _0221BAB2
_0221BAC0:
	ldr r0, [sp, #0x14]
	bl ov38_0221BA00
	bl ov38_0221BA10
	eor r0, r4
	strb r0, [r6, #4]
	bl ov38_0221BA10
	ldr r1, [sp, #0xc]
	eor r0, r1
	strb r0, [r6, #5]
	bl ov38_0221BA10
	ldr r1, [sp, #8]
	eor r0, r1
	strb r0, [r6, #6]
	bl ov38_0221BA10
	ldr r1, [sp, #4]
	mov r4, #0
	eor r0, r1
	strb r0, [r6, #7]
	cmp r5, #0
	ble _0221BB04
_0221BAF2:
	bl ov38_0221BA10
	ldrb r1, [r7, r4]
	eor r1, r0
	add r0, r6, r4
	add r4, r4, #1
	strb r1, [r0, #8]
	cmp r4, r5
	blt _0221BAF2
_0221BB04:
	ldr r1, _0221BB40 ; =0x4A3B2C1D
	ldr r0, [sp, #0x14]
	add r5, #8
	eor r1, r0
	lsr r0, r1, #0x18
	strb r0, [r6]
	lsr r0, r1, #0x10
	strb r0, [r6, #1]
	lsr r0, r1, #8
	strb r0, [r6, #2]
	strb r1, [r6, #3]
	ldr r1, [sp]
	add r0, r6, #0
	add r2, r5, #0
	mov r3, #2
	bl ov00_021FFC18
	ldr r0, [sp, #0x10]
	bl ov38_0221BB44
	ldr r1, [sp]
	mov r2, #0
	strb r2, [r1, r0]
	mov r0, #0xa
	add r1, r6, #0
	bl ov00_021EC2EC
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221BB40: .word 0x4A3B2C1D
	thumb_func_end ov38_0221BA38
