	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text
	.public ov93_0225E3C4
	.public ov93_0225E45C
	.extern ov93_02262A54

	thumb_func_start ov93_0225E3C4
ov93_0225E3C4: ; 0x0225E3C4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	add r7, r1, #0
	bl sub_0203769C
	mov r6, #0xff
	add r4, r6, #0
	mov r1, #0
	b _0225E3F6
_0225E3D8:
	ldr r2, [r5]
	add r2, r2, r1
	add r2, #0x2c
	ldrb r2, [r2]
	cmp r0, r2
	bne _0225E3E6
	add r4, r1, #0
_0225E3E6:
	ldr r2, [r5]
	add r2, r2, r1
	add r2, #0x2c
	ldrb r2, [r2]
	cmp r7, r2
	bne _0225E3F4
	add r6, r1, #0
_0225E3F4:
	add r1, r1, #1
_0225E3F6:
	ldr r2, [r5]
	add r2, #0x30
	ldrb r2, [r2]
	cmp r1, r2
	blt _0225E3D8
	mov r0, #0
	cmp r6, #0xff
	beq _0225E40C
	cmp r4, #0xff
	beq _0225E40C
	mov r0, #1
_0225E40C:
	cmp r0, #0
	bne _0225E414
	bl GF_AssertFail
_0225E414:
	mov r1, #0
	ldr r0, _0225E458 ; =ov93_02262A54
	b _0225E440
_0225E41A:
	ldr r2, [r5]
	add r2, #0x30
	ldrb r2, [r2]
	lsl r2, r2, #2
	add r2, r0, r2
	ldrb r2, [r1, r2]
	cmp r4, r2
	bne _0225E42C
	str r1, [sp]
_0225E42C:
	ldr r2, [r5]
	add r2, #0x30
	ldrb r2, [r2]
	lsl r2, r2, #2
	add r2, r0, r2
	ldrb r2, [r1, r2]
	cmp r6, r2
	bne _0225E43E
	str r1, [sp, #4]
_0225E43E:
	add r1, r1, #1
_0225E440:
	ldr r2, [r5]
	add r2, #0x30
	ldrb r2, [r2]
	cmp r1, r2
	blt _0225E41A
	ldr r1, [sp, #4]
	ldr r0, [sp]
	sub r0, r1, r0
	bpl _0225E454
	add r0, r0, r2
_0225E454:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225E458: .word ov93_02262A54
	thumb_func_end ov93_0225E3C4


	thumb_func_start ov93_0225E45C
ov93_0225E45C: ; 0x0225E45C
	push {r4, lr}
	ldr r3, [r0]
	mov r2, #0
	add r0, r3, #0
	add r0, #0x30
	ldrb r4, [r0]
	cmp r4, #0
	ble _0225E482
_0225E46C:
	add r0, r3, #0
	add r0, #0x2c
	ldrb r0, [r0]
	cmp r1, r0
	bne _0225E47A
	add r0, r2, #0
	pop {r4, pc}
_0225E47A:
	add r2, r2, #1
	add r3, r3, #1
	cmp r2, r4
	blt _0225E46C
_0225E482:
	bl GF_AssertFail
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov93_0225E45C
