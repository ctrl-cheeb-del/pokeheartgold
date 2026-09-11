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

	thumb_func_start ov80_0222A5E0
ov80_0222A5E0: ; 0x0222A5E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x7c
	str r0, [sp]
	ldr r0, [sp, #0x90]
	add r7, r3, #0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r0, [sp, #0x90]
	cmp r0, #6
	ble _0222A5F8
	bl GF_AssertFail
_0222A5F8:
	ldr r0, [sp, #0x90]
	mov r4, #0
	str r4, [sp, #0x14]
	cmp r0, #0
	beq _0222A6A6
	add r0, sp, #0x1c
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x94]
	str r0, [sp, #0xc]
_0222A60A:
	bl LCRandom
	ldr r1, [sp]
	ldrh r1, [r1, #2]
	bl _s32_div_f
	ldr r0, [sp]
	lsl r1, r1, #1
	add r0, r0, r1
	ldrh r0, [r0, #4]
	mov r2, #0xcd
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x18]
	bl ov80_02229EF4
	mov r0, #0
	cmp r4, #0
	ble _0222A64E
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #0x10]
	ldrh r2, [r2]
	ldrh r3, [r3, #0xc]
	add r1, sp, #0x1c
_0222A63A:
	ldrh r5, [r1]
	cmp r5, r2
	beq _0222A64E
	ldrh r5, [r1, #0xc]
	cmp r5, r3
	beq _0222A64E
	add r0, r0, #1
	add r1, #0x10
	cmp r0, r4
	blt _0222A63A
_0222A64E:
	cmp r0, r4
	bne _0222A6A0
	ldr r0, [sp, #0x14]
	cmp r0, #0x32
	bge _0222A68C
	mov r3, #0
	cmp r7, #0
	ble _0222A680
	ldr r2, [sp, #0x10]
	ldr r5, [sp, #0x10]
	ldrh r2, [r2]
	ldrh r6, [r5, #0xc]
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
_0222A66A:
	ldrh r5, [r0]
	cmp r2, r5
	beq _0222A680
	ldrh r5, [r1]
	cmp r6, r5
	beq _0222A680
	add r3, r3, #1
	add r0, r0, #2
	add r1, r1, #2
	cmp r3, r7
	blt _0222A66A
_0222A680:
	cmp r3, r7
	beq _0222A68C
	ldr r0, [sp, #0x14]
	add r0, r0, #1
	str r0, [sp, #0x14]
	b _0222A6A0
_0222A68C:
	ldr r1, [sp, #0x18]
	ldr r0, [sp, #0xc]
	add r4, r4, #1
	strh r1, [r0]
	ldr r0, [sp, #0x10]
	add r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r0, r0, #2
	str r0, [sp, #0xc]
_0222A6A0:
	ldr r0, [sp, #0x90]
	cmp r4, r0
	bne _0222A60A
_0222A6A6:
	ldr r0, [sp, #0x14]
	cmp r0, #0x32
	blt _0222A6B2
	add sp, #0x7c
	mov r0, #1
	pop {r4, r5, r6, r7, pc}
_0222A6B2:
	mov r0, #0
	add sp, #0x7c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov80_0222A5E0


	thumb_func_start ov80_0222A6B8
ov80_0222A6B8: ; 0x0222A6B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x74
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x8c]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	str r0, [sp, #0x8c]
	add r0, sp, #0x44
	mov r2, #0xb
	mov r3, #0xcc
	add r5, r1, #0
	bl ov80_02229F04
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x10]
	mov r4, #0
	cmp r0, #0
	ble _0222A6EE
_0222A6DC:
	add r0, r5, #0
	bl ov80_0222A5A4
	ldr r1, [sp, #0x8c]
	strb r0, [r1, r4]
	ldr r0, [sp, #0x10]
	add r4, r4, #1
	cmp r4, r0
	blt _0222A6DC
_0222A6EE:
	add r0, sp, #0x78
	ldrb r0, [r0, #0x1c]
	add r1, sp, #0x2c
	cmp r0, #0
	bne _0222A710
	ldr r0, [sp, #0x10]
	add r2, sp, #0x24
	str r0, [sp]
	ldr r0, [sp, #0x18]
	mov r3, #0
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	ldr r0, [sp, #0x20]
	bl ov80_0222A5E0
	b _0222A7A6
_0222A710:
	ldr r0, [sp, #0x10]
	add r2, sp, #0x24
	lsr r0, r0, #1
	str r0, [sp, #0x1c]
	str r0, [sp]
	ldr r0, [sp, #0x18]
	mov r3, #0
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	ldr r0, [sp, #0x20]
	bl ov80_0222A5E0
	ldr r0, [sp, #0x1c]
	mov r7, #0
	cmp r0, #0
	ble _0222A75C
	ldr r6, [sp, #0x18]
	add r4, sp, #0x2c
	add r5, sp, #0x24
_0222A738:
	ldrh r1, [r6]
	add r0, sp, #0x34
	mov r2, #0xcd
	bl ov80_02229EF4
	add r0, sp, #0x24
	ldrh r0, [r0, #0x10]
	add r7, r7, #1
	add r6, r6, #2
	strh r0, [r4]
	add r0, sp, #0x24
	ldrh r0, [r0, #0x1c]
	add r4, r4, #2
	strh r0, [r5]
	ldr r0, [sp, #0x1c]
	add r5, r5, #2
	cmp r7, r0
	blt _0222A738
_0222A75C:
	ldr r0, [sp, #0x20]
	bl Heap_Free
	ldr r1, [sp, #0x14]
	add r0, sp, #0x44
	mov r2, #0xb
	mov r3, #0xcc
	bl ov80_02229F04
	ldr r1, [sp, #0x10]
	str r0, [sp, #0x20]
	lsr r6, r1, #1
	ldr r1, [sp, #0x18]
	lsl r2, r6, #1
	add r1, r1, r2
	str r6, [sp]
	str r1, [sp, #4]
	mov r1, #0xb
	str r1, [sp, #8]
	add r1, sp, #0x2c
	add r2, sp, #0x24
	add r3, r6, #0
	bl ov80_0222A5E0
	mov r5, #0
	cmp r6, #0
	ble _0222A7A6
	ldr r0, [sp, #0x8c]
	add r4, r0, r6
_0222A796:
	ldr r0, [sp, #0x14]
	bl ov80_0222A5A4
	strb r0, [r4]
	add r5, r5, #1
	add r4, r4, #1
	cmp r5, r6
	blt _0222A796
_0222A7A6:
	ldr r0, [sp, #0x20]
	bl Heap_Free
	ldr r0, [sp, #0x90]
	ldr r1, [sp, #0x18]
	str r0, [sp]
	ldr r0, [sp, #0x10]
	ldr r2, [sp, #0x8c]
	str r0, [sp, #4]
	mov r0, #0xb
	str r0, [sp, #8]
	mov r0, #0xcd
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x88]
	mov r3, #0
	bl ov80_0222A52C
	add sp, #0x74
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov80_0222A6B8
