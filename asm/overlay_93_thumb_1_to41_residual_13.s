	.include "asm/macros.inc"
	.include "overlay_93_thumb_1.inc"
	.include "global.inc"

	.text

	thumb_func_start ov93_0225DF38
ov93_0225DF38: ; 0x0225DF38
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0x4b
	lsl r0, r0, #4
	add r5, #0xd8
	cmp r1, r0
	ble _0225DF4C
	mov r2, #3
	b _0225DF5E
_0225DF4C:
	cmp r1, #2
	ble _0225DF54
	mov r2, #2
	b _0225DF5E
_0225DF54:
	cmp r1, #1
	ble _0225DF5C
	mov r2, #1
	b _0225DF5E
_0225DF5C:
	mov r2, #0
_0225DF5E:
	add r0, r5, #0
	str r0, [sp, #4]
	add r0, #0x88
	mov r1, #0x90
	str r0, [sp, #4]
	lsl r0, r2, #4
	mul r1, r2
	mov r3, #9
	mov ip, r0
	mov r0, #0
	add r1, r5, r1
	lsl r3, r3, #6
_0225DF76:
	add r4, r1, #0
	add r4, #0xc8
	ldr r4, [r4]
	cmp r4, #0
	bne _0225DFF2
	add r4, r2, #0
	mov r1, #0x90
	mul r4, r1
	lsl r1, r0, #3
	add r0, r0, r1
	lsl r7, r0, #6
	add r0, r5, #0
	add r0, #0xcc
	add r6, r0, r7
	ldr r1, [sp, #4]
	mov r2, ip
	add r0, r6, r4
	add r1, r1, r2
	bl sub_020181B0
	mov r1, #0
	ldr r2, _0225E000 ; =0xFFFE7000
	add r0, r6, r4
	add r3, r1, #0
	bl sub_020182A8
	mov r1, #1
	lsl r1, r1, #0xc
	add r0, r6, r4
	add r2, r1, #0
	add r3, r1, #0
	bl sub_020182C4
	add r0, r6, r4
	mov r1, #1
	bl sub_020182A0
	mov r0, #0x51
	lsl r0, r0, #2
	add r0, r5, r0
	add r0, r0, r7
	str r0, [sp]
	add r0, r0, r4
	mov r1, #0
	bl sub_02018198
	ldr r1, [sp]
	add r0, r6, r4
	add r1, r1, r4
	bl sub_020181D4
	add r0, r5, r7
	add r0, r0, r4
	mov r1, #1
	add r0, #0xc8
	str r1, [r0]
	ldr r0, _0225E004 ; =0x00000591
	bl PlaySE
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0225DFF2:
	add r0, r0, #1
	add r1, r1, r3
	cmp r0, #8
	blt _0225DF76
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225E000: .word 0xFFFE7000
_0225E004: .word 0x00000591
	thumb_func_end ov93_0225DF38
