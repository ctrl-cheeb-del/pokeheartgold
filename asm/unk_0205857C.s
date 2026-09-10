	.include "asm/macros.inc"
	.include "unk_02058034.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0205857C
sub_0205857C: ; 0x0205857C
	push {r3, r4, r5, r6, r7, lr}
	mov r0, #0
	str r0, [sp]
	bl sub_02037454
	cmp r0, #0
	ble _020585F0
	mov r7, #0
_0205858C:
	bl sub_0203769C
	ldr r1, [sp]
	cmp r1, r0
	beq _020585E0
	add r0, r1, #0
	bl sub_02037B5C
	cmp r0, #0x5e
	bne _020585E0
	ldr r6, _02058600 ; =_021D41C8
	ldr r0, [r6]
	ldr r1, [r0, #0x14]
	ldr r0, [r1, #0x10]
	cmp r0, #0
	bne _020585E0
	add r1, #0xd2
	ldrb r0, [r1]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1a
	bne _020585E0
	mov r4, #0
	add r5, r4, #0
_020585BA:
	ldr r0, [r6]
	ldr r0, [r0, r5]
	cmp r0, #0
	beq _020585CA
	bl Heap_Free
	ldr r0, [r6]
	str r7, [r0, r5]
_020585CA:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _020585BA
	ldr r0, _02058600 ; =_021D41C8
	ldr r1, _02058604 ; =0x0000238E
	ldr r0, [r0]
	mov r2, #0
	ldr r0, [r0, #0x14]
	bl StartMapSceneScript
_020585E0:
	ldr r0, [sp]
	add r0, r0, #1
	str r0, [sp]
	bl sub_02037454
	ldr r1, [sp]
	cmp r1, r0
	blt _0205858C
_020585F0:
	ldr r1, _02058600 ; =_021D41C8
	mov r0, #4
	ldr r1, [r1]
	ldr r1, [r1, #0x14]
	ldr r1, [r1, #8]
	bl sub_020399FC
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02058600: .word _021D41C8
_02058604: .word 0x0000238E
	thumb_func_end sub_0205857C
