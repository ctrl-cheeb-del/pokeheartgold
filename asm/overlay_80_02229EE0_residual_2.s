	.include "asm/macros.inc"
	.public _02229F00
	.public _02229F68
	.public _02229FC2
	.public _02229FCC
	.public _02229FD0
	.public _02229FDC
	.public _02229FE8
	.public _02229FF8
	.public _0222A026
	.public _0222A028
	.public _0222A068
	.public _0222A078
	.public _0222A08C
	.public _0222A092
	.public _0222A0A4
	.public _0222A0D4
	.public _0222A0E8
	.public _0222A0FA
	.public _0222A118
	.public _0222A11C
	.public _0222A120
	.public _0222A124
	.public _0222A128
	.public _0222A12C
	.public _0222A130
	.public _0222A134
	.public _0222A138
	.public _0222A13C
	.public _0222A158
	.public _0222A15E
	.public _0222A1BC
	.public _0222A2E4
	.public _0222A2F0
	.public _0222A308
	.public _0222A310
	.public _0222A31E
	.public _0222A32C
	.public _0222A330
	.public _0222A3B8
	.public _0222A3FC
	.public _0222A428
	.public _0222A42E
	.public _0222A454
	.public _0222A45E
	.public _0222A462
	.public _0222A466
	.public _0222A46A
	.public _0222A46E
	.public _0222A554
	.public _0222A55E
	.public _0222A560
	.public _0222A56E
	.public _0222A570
	.public _0222A58C
	.public _0222A5A0
	.public _0222A5AC
	.public _0222A5B4
	.public _0222A5BC
	.public _0222A5C4
	.public _0222A5CC
	.public _0222A5D4
	.public _0222A5DC
	.public _0222A5F8
	.public _0222A60A
	.public _0222A63A
	.public _0222A64E
	.public _0222A66A
	.public _0222A680
	.public _0222A68C
	.public _0222A6A0
	.public _0222A6A6
	.public _0222A6B2
	.public _0222A6DC
	.public _0222A6EE
	.public _0222A710
	.public _0222A738
	.public _0222A75C
	.public _0222A796
	.public _0222A7A6
	.public _0222A804
	.public _0222A816
	.public _0222A81E
	.public _0222A822
	.public _0222A82A
	.public _0222A82E
	.public _0222A836
	.public _0222A83C
	.public _0223B620
	.public ov80_02229EE0
	.public ov80_02229EF4
	.public ov80_02229F04
	.public ov80_02229F6C
	.public ov80_0222A140
	.public ov80_0222A30C
	.public ov80_0222A334
	.public ov80_0222A3BC
	.public ov80_0222A3D4
	.public ov80_0222A400
	.public ov80_0222A43C
	.public ov80_0222A474
	.public ov80_0222A480
	.public ov80_0222A4EC
	.public ov80_0222A52C
	.public ov80_0222A5A4
	.public ov80_0222A5E0
	.public ov80_0222A6B8
	.public ov80_0222A7CC
	.public ov80_0222A7EC
	.public ov80_0222A840
	.public ov80_0223B628
	.public ov80_0223B62A
	.include "overlay_80_02229EE0.inc"
	.include "global.inc"

	.text
	.public ov80_02229EE0
	.public ov80_02229EF4
	.public ov80_02229F04
	.public ov80_0222A334
	.public ov80_0222A3BC
	.public ov80_0222A3D4
	.public ov80_0222A400
	.public ov80_0222A43C
	.public ov80_0222A474
	.public ov80_0222A480
	.public ov80_0222A5A4
	.public ov80_0222A7CC
	.public ov80_0222A7EC
	.public ov80_0222A840

	thumb_func_start ov80_0222A4EC
ov80_0222A4EC: ; 0x0222A4EC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r7, r0, #0
	str r1, [sp, #0x14]
	add r5, r2, #0
	add r4, r3, #0
	bl LCRandom
	add r6, r0, #0
	bl LCRandom
	lsl r0, r0, #0x10
	add r2, r6, #0
	orr r2, r0
	lsl r0, r5, #0x18
	str r4, [sp]
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r0, [sp, #0x34]
	ldr r3, [sp, #0x30]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	add r0, r7, #0
	bl ov80_02229F6C
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_0222A4EC


	thumb_func_start ov80_0222A52C
ov80_0222A52C: ; 0x0222A52C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x30]
	add r7, r1, #0
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x34]
	str r2, [sp, #0x10]
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x38]
	str r3, [sp, #0x14]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x3c]
	mov r4, #0
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x34]
	cmp r0, #0
	ble _0222A5A0
	ldr r5, [sp, #0x30]
	add r6, r3, #0
_0222A554:
	ldr r0, [sp, #0x10]
	cmp r0, #0
	bne _0222A55E
	mov r0, #0
	b _0222A560
_0222A55E:
	ldrb r0, [r0, r4]
_0222A560:
	lsl r0, r0, #0x18
	lsr r3, r0, #0x18
	ldr r0, [sp, #0x14]
	cmp r0, #0
	bne _0222A56E
	mov r0, #0
	b _0222A570
_0222A56E:
	ldr r0, [r6]
_0222A570:
	str r0, [sp]
	ldr r0, [sp, #0x38]
	add r2, r4, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #8]
	ldrh r1, [r7]
	ldr r0, [sp, #0xc]
	bl ov80_0222A4EC
	ldr r1, [sp, #0x30]
	cmp r1, #0
	beq _0222A58C
	str r0, [r5]
_0222A58C:
	ldr r0, [sp, #0xc]
	add r4, r4, #1
	add r0, #0x38
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x34]
	add r6, r6, #4
	add r7, r7, #2
	add r5, r5, #4
	cmp r4, r0
	blt _0222A554
_0222A5A0:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov80_0222A52C
