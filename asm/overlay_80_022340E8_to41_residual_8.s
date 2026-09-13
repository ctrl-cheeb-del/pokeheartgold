	.include "asm/macros.inc"
	.include "overlay_80_022340E8.inc"
	.include "global.inc"

    .text

	thumb_func_start ov80_02234F28
ov80_02234F28: ; 0x02234F28
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r2, [sp, #8]
	str r0, [sp]
	mov r5, #0
	ldr r0, [sp, #8]
	str r1, [sp, #4]
	str r5, [sp, #0xc]
	cmp r0, #0
	ble _02234F98
_02234F3C:
	ldr r0, [sp, #4]
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r4, r0, #0
	mov r1, #0xb1
	mov r2, #0
	bl GetMonData
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #0xb2
	mov r2, #0
	bl GetMonData
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0
	bl GetMonData
	cmp r6, #3
	beq _02234F7A
	cmp r7, #3
	beq _02234F7A
	cmp r6, #8
	beq _02234F7A
	cmp r7, #8
	beq _02234F7A
	cmp r0, #0x11
	bne _02234F82
_02234F7A:
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	str r0, [sp, #0xc]
	b _02234F90
_02234F82:
	mov r0, #8
	str r0, [sp, #0x10]
	add r0, r4, #0
	mov r1, #0xa0
	add r2, sp, #0x10
	bl SetMonData
_02234F90:
	ldr r0, [sp, #8]
	add r5, r5, #1
	cmp r5, r0
	blt _02234F3C
_02234F98:
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #8]
	cmp r1, r0
	blt _02234FA6
	ldr r0, [sp]
	mov r1, #1
	strb r1, [r0, #0x1f]
_02234FA6:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_02234F28


	thumb_func_start ov80_02234FAC
ov80_02234FAC: ; 0x02234FAC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r2, [sp, #8]
	str r0, [sp]
	mov r6, #0
	ldr r0, [sp, #8]
	add r5, r6, #0
	str r1, [sp, #4]
	cmp r0, #0
	ble _02235012
_02234FC0:
	ldr r0, [sp, #4]
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r4, r0, #0
	mov r1, #0xb1
	mov r2, #0
	bl GetMonData
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #0xb2
	mov r2, #0
	bl GetMonData
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0
	bl GetMonData
	cmp r7, #4
	beq _02234FF8
	ldr r1, [sp, #0xc]
	cmp r1, #4
	beq _02234FF8
	cmp r0, #7
	bne _02234FFC
_02234FF8:
	add r6, r6, #1
	b _0223500A
_02234FFC:
	mov r0, #0x40
	str r0, [sp, #0x10]
	add r0, r4, #0
	mov r1, #0xa0
	add r2, sp, #0x10
	bl SetMonData
_0223500A:
	ldr r0, [sp, #8]
	add r5, r5, #1
	cmp r5, r0
	blt _02234FC0
_02235012:
	ldr r0, [sp, #8]
	cmp r6, r0
	blt _0223501E
	ldr r0, [sp]
	mov r1, #1
	strb r1, [r0, #0x1f]
_0223501E:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_02234FAC


	thumb_func_start ov80_02235024
ov80_02235024: ; 0x02235024
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	str r2, [sp, #8]
	str r0, [sp]
	mov r6, #0
	ldr r0, [sp, #8]
	add r5, r6, #0
	str r1, [sp, #4]
	cmp r0, #0
	ble _0223508A
_02235038:
	ldr r0, [sp, #4]
	add r1, r5, #0
	bl Party_GetMonByIndex
	add r4, r0, #0
	mov r1, #0xb1
	mov r2, #0
	bl GetMonData
	add r7, r0, #0
	add r0, r4, #0
	mov r1, #0xb2
	mov r2, #0
	bl GetMonData
	str r0, [sp, #0xc]
	add r0, r4, #0
	mov r1, #0xa
	mov r2, #0
	bl GetMonData
	cmp r7, #0xa
	beq _02235070
	ldr r1, [sp, #0xc]
	cmp r1, #0xa
	beq _02235070
	cmp r0, #0x29
	bne _02235074
_02235070:
	add r6, r6, #1
	b _02235082
_02235074:
	mov r0, #0x10
	str r0, [sp, #0x10]
	add r0, r4, #0
	mov r1, #0xa0
	add r2, sp, #0x10
	bl SetMonData
_02235082:
	ldr r0, [sp, #8]
	add r5, r5, #1
	cmp r5, r0
	blt _02235038
_0223508A:
	ldr r0, [sp, #8]
	cmp r6, r0
	blt _02235096
	ldr r0, [sp]
	mov r1, #1
	strb r1, [r0, #0x1f]
_02235096:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov80_02235024
