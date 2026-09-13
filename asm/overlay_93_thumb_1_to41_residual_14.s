	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225E10C

	thumb_func_start ov93_0225E10C
ov93_0225E10C: ; 0x0225E10C
	push {r4, r5, r6, r7}
	ldr r5, [r0]
	ldr r3, [r0, #0xc]
	add r4, r5, #0
	add r4, #0x30
	ldrb r6, [r4]
	add r1, r5, #0
	add r1, #0x2c
	mov r2, #1
	ldrb r1, [r1]
	cmp r6, #1
	ble _0225E13C
	add r4, r0, #4
_0225E126:
	ldr r7, [r4, #0xc]
	cmp r3, r7
	bhs _0225E134
	add r1, r5, r2
	add r1, #0x2c
	ldrb r1, [r1]
	add r3, r7, #0
_0225E134:
	add r2, r2, #1
	add r4, r4, #4
	cmp r2, r6
	blt _0225E126
_0225E13C:
	str r1, [r0, #4]
	add r0, r1, #0
	pop {r4, r5, r6, r7}
	bx lr
	thumb_func_end ov93_0225E10C
