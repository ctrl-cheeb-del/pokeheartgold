	.include "asm/macros.inc"
	.include "unk_02013534.inc"
	.include "global.inc"

	.rodata

	.public _020F5F2C
_020F5F2C:
	.byte 0x08
_020F5F2D:
	.byte 0x08, 0x08, 0x04
	.byte 0x04, 0x08, 0x04, 0x04, 0x04, 0x02, 0x04, 0x01, 0x02, 0x04, 0x02, 0x02, 0x02, 0x01, 0x01, 0x04
	.byte 0x01, 0x02, 0x01, 0x01

	.text

	thumb_func_start sub_02013E78
sub_02013E78: ; 0x02013E78
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	add r0, r1, #0
	ldr r4, [r0, #0xc]
	str r1, [sp, #4]
	add r7, r2, #0
	add r6, r3, #0
	cmp r4, r0
	beq _02013EC8
	mov r5, #0
_02013E8E:
	ldr r0, [sp]
	add r1, r4, #0
	add r2, r7, #0
	bl sub_02013EF0
	ldr r1, [r6]
	str r0, [r1, r5]
	ldr r0, [r6]
	ldr r0, [r0, r5]
	cmp r0, #0
	bne _02013EA8
	bl GF_AssertFail
_02013EA8:
	ldr r0, [r4]
	add r7, #0x24
	lsl r1, r0, #3
	ldr r0, [r6]
	add r0, r0, r5
	str r1, [r0, #4]
	ldr r0, [r4, #4]
	lsl r1, r0, #3
	ldr r0, [r6]
	add r0, r0, r5
	str r1, [r0, #8]
	ldr r4, [r4, #0xc]
	ldr r0, [sp, #4]
	add r5, #0xc
	cmp r4, r0
	bne _02013E8E
_02013EC8:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02013E78

	thumb_func_start sub_02013ECC
sub_02013ECC: ; 0x02013ECC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #4]
	mov r6, #0
	cmp r0, #0
	ble _02013EEC
	add r4, r6, #0
_02013EDA:
	ldr r0, [r5]
	ldr r0, [r0, r4]
	bl Sprite_Delete
	ldr r0, [r5, #4]
	add r6, r6, #1
	add r4, #0xc
	cmp r6, r0
	blt _02013EDA
_02013EEC:
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02013ECC

	thumb_func_start sub_02013EF0
sub_02013EF0: ; 0x02013EF0
	push {r4, r5, lr}
	sub sp, #0x44
	add r5, r0, #0
	mov r0, #0
	str r2, [sp]
	str r0, [sp, #4]
	add r4, r1, #0
	ldr r1, [r5, #0xc]
	str r1, [sp, #8]
	ldr r1, [r4, #8]
	ldr r2, [r5]
	lsl r1, r1, #2
	add r1, r2, r1
	ldr r1, [r1, #0x30]
	str r1, [sp, #0xc]
	str r0, [sp, #0x10]
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	ldr r2, [r5, #0x20]
	add r1, sp, #0x20
	strb r2, [r1]
	ldr r1, [r5, #8]
	str r1, [sp, #0x24]
	add r1, sp, #0
	str r1, [sp, #0x28]
	ldr r1, [r5, #0x24]
	str r1, [sp, #0x38]
	ldr r1, [r5, #0x28]
	str r1, [sp, #0x3c]
	ldr r1, [r5, #0x2c]
	str r1, [sp, #0x40]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _02013F4C
	bl Sprite_GetMatrixPtr
	add r3, r0, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0x2c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
_02013F4C:
	ldr r1, [r4]
	ldr r2, [r5, #0x18]
	lsl r1, r1, #3
	add r1, r2, r1
	ldr r0, [sp, #0x2c]
	lsl r1, r1, #0xc
	add r0, r0, r1
	str r0, [sp, #0x2c]
	ldr r1, [r4, #4]
	ldr r2, [r5, #0x1c]
	lsl r1, r1, #3
	add r1, r2, r1
	ldr r0, [sp, #0x30]
	lsl r1, r1, #0xc
	add r0, r0, r1
	str r0, [sp, #0x30]
	add r0, sp, #0x24
	bl Sprite_Create
	add sp, #0x44
	pop {r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02013EF0

	thumb_func_start sub_02013F78
sub_02013F78: ; 0x02013F78
	push {r4, lr}
	mov r1, #0x14
	bl Heap_AllocAtEnd
	add r4, r0, #0
	bne _02013F88
	bl GF_AssertFail
_02013F88:
	mov r0, #0
	str r0, [r4, #0xc]
	str r0, [r4, #0x10]
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02013F78

	thumb_func_start sub_02013F94
sub_02013F94: ; 0x02013F94
	push {r4, lr}
	add r4, r0, #0
	bne _02013F9E
	bl GF_AssertFail
_02013F9E:
	add r0, r4, #0
	bl Heap_Free
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02013F94

	thumb_func_start sub_02013FA8
sub_02013FA8: ; 0x02013FA8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, r5
	beq _02013FBE
_02013FB2:
	ldr r4, [r0, #0xc]
	bl sub_02013F94
	add r0, r4, #0
	cmp r4, r5
	bne _02013FB2
_02013FBE:
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02013FA8

	thumb_func_start sub_02013FC0
sub_02013FC0: ; 0x02013FC0
	ldr r2, [r1, #0xc]
	str r2, [r0, #0xc]
	str r1, [r0, #0x10]
	ldr r2, [r1, #0xc]
	str r0, [r2, #0x10]
	str r0, [r1, #0xc]
	bx lr
	.balign 4, 0
	thumb_func_end sub_02013FC0

	thumb_func_start sub_02013FD0
sub_02013FD0: ; 0x02013FD0
	ldr r3, _02013FD8 ; =sub_02013728
	str r1, [r0, #8]
	bx r3
	nop
_02013FD8: .word sub_02013728
	thumb_func_end sub_02013FD0
