	.include "asm/macros.inc"
	.include "overlay_87.inc"
	.include "global.inc"
	.extern ov87_021E7F6C
	.extern ov87_021E7FD4
	.extern ov87_021E8194
	.extern ov87_021E82E4
	.public ov87_021E6668
	.public ov87_021E66B8
	.public ov87_021E6704

	.text

thumb_func_start ov87_021E6668
ov87_021E6668: ; 0x021E6668
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0x5b
	lsl r0, r0, #2
	ldr r4, _021E66B4 ; =ov87_021E82E4
	mov r6, #0
	add r7, r5, r0
_021E6678:
	ldrh r0, [r4, #2]
	mov r1, #3
	mov r2, #2
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	ldrh r3, [r4]
	add r0, r7, #0
	bl ov87_021E7F6C
	mov r1, #0xd1
	lsl r1, r1, #2
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #0
	bl ov87_021E7FD4
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r6, #3
	blt _021E6678
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E66B4: .word ov87_021E82E4
	thumb_func_end ov87_021E6668

	thumb_func_start ov87_021E66B8
ov87_021E66B8: ; 0x021E66B8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #0x5b
	lsl r0, r0, #2
	ldr r4, _021E6700 ; =ov87_021E8194
	mov r6, #0
	add r7, r5, r0
_021E66C8:
	ldrh r0, [r4, #2]
	mov r1, #1
	mov r2, #0
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldrh r3, [r4]
	add r0, r7, #0
	bl ov87_021E7F6C
	mov r1, #0x35
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r1, #0
	ldr r0, [r5, r0]
	mov r1, #0
	bl ov87_021E7FD4
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #4
	cmp r6, #3
	blt _021E66C8
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6700: .word ov87_021E8194
	thumb_func_end ov87_021E66B8

	thumb_func_start ov87_021E6704
ov87_021E6704: ; 0x021E6704
	push {r4, lr}
	sub sp, #0x10
	mov r1, #0xa0
	add r4, r0, #0
	str r1, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r2, #1
	str r2, [sp, #8]
	add r1, #0xcc
	str r0, [sp, #0xc]
	add r0, r4, r1
	mov r1, #3
	mov r3, #0x44
	bl ov87_021E7F6C
	mov r1, #0xcf
	lsl r1, r1, #2
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl ov87_021E7FD4
	mov r3, #0x44
	str r3, [sp]
	mov r1, #0
	str r1, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x5b
	str r1, [sp, #0xc]
	lsl r0, r0, #2
	mov r1, #3
	add r0, r4, r0
	add r2, r1, #0
	bl ov87_021E7F6C
	mov r1, #0xd
	lsl r1, r1, #6
	str r0, [r4, r1]
	ldr r0, [r4, r1]
	mov r1, #0
	bl ov87_021E7FD4
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov87_021E6704
