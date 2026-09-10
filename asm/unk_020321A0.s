	.include "asm/macros.inc"
	.include "unk_02031B0C.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_020321A0
sub_020321A0: ; 0x020321A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	mov r4, #0
	add r5, r0, #0
	str r0, [sp]
	add r7, r1, #0
	str r2, [sp, #4]
	str r3, [sp, #8]
	str r4, [sp, #0x10]
	add r5, #0x38
_020321B4:
	add r0, r5, #0
	bl sub_02031D6C
	cmp r0, #0
	beq _020321CC
	ldr r0, [sp, #0x10]
	add r4, r4, #1
	add r0, r0, #1
	add r5, #0x20
	str r0, [sp, #0x10]
	cmp r4, #3
	blt _020321B4
_020321CC:
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	cmp r0, #0
	ble _020322A6
_020321D6:
	ldr r1, [sp, #0xc]
	ldr r0, [sp, #8]
	cmp r1, r0
	beq _02032298
	add r0, r7, #0
	add r0, #0x18
	bl sub_02031D6C
	cmp r0, #0
	beq _02032298
	mov r4, #0
	str r4, [sp, #0x14]
	ldr r5, [sp]
	ldr r6, [sp, #0x14]
	add r5, #0x20
_020321F4:
	add r0, r7, #0
	add r1, r5, #0
	bl sub_02032158
	cmp r0, #0
	beq _0203220A
	lsl r0, r6, #0x18
	lsr r4, r0, #0x18
	mov r0, #1
	str r0, [sp, #0x14]
	b _02032212
_0203220A:
	add r6, r6, #1
	add r5, #0x20
	cmp r6, #3
	blt _020321F4
_02032212:
	ldr r0, [sp, #0x10]
	cmp r0, #3
	blt _02032222
	mov r0, #2
	mov ip, r0
	mov r0, #1
	str r0, [sp, #0x14]
	b _02032242
_02032222:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _02032234
	ldr r0, [sp, #0x10]
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov ip, r0
	b _02032242
_02032234:
	ldr r0, [sp, #0x10]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	mov ip, r0
	ldr r0, [sp, #0x10]
	add r0, r0, #1
	str r0, [sp, #0x10]
_02032242:
	ldr r0, [sp, #0x14]
	cmp r0, #0
	beq _0203227C
	mov r0, ip
	cmp r4, r0
	bhs _0203227C
	ldr r0, [sp, #0x10]
	sub r6, r0, #1
	cmp r4, r6
	bge _0203227C
	ldr r0, [sp]
	lsl r1, r4, #5
	add r5, r0, r1
_0203225C:
	add r3, r5, #0
	add r2, r5, #0
	add r3, #0x40
	add r2, #0x20
	add r5, r2, #0
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	add r4, r4, #1
	stmia r2!, {r0, r1}
	cmp r4, r6
	blt _0203225C
_0203227C:
	mov r0, ip
	lsl r1, r0, #5
	ldr r0, [sp]
	add r3, r7, #0
	add r2, r0, r1
	add r2, #0x20
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
_02032298:
	ldr r0, [sp, #0xc]
	add r7, #0x20
	add r1, r0, #1
	ldr r0, [sp, #4]
	str r1, [sp, #0xc]
	cmp r1, r0
	blt _020321D6
_020322A6:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020321A0
