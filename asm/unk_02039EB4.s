	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02039EB4
sub_02039EB4: ; 0x02039EB4
	push {r4, r5, r6, lr}
	add r4, r2, #0
	add r6, r1, #0
	ldr r1, [r4]
	add r5, r0, #0
	cmp r1, #6
	bhi _02039F64
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02039ECE: ; jump table
	.short _02039EDC - _02039ECE - 2 ; case 0
	.short _02039EE8 - _02039ECE - 2 ; case 1
	.short _02039F00 - _02039ECE - 2 ; case 2
	.short _02039F28 - _02039ECE - 2 ; case 3
	.short _02039F38 - _02039ECE - 2 ; case 4
	.short _02039F5A - _02039ECE - 2 ; case 5
	.short _02039F60 - _02039ECE - 2 ; case 6
_02039EDC:
	mov r0, #0x6f
	bl sub_02037AC0
	mov r0, #1
	str r0, [r4]
	b _02039F64
_02039EE8:
	mov r0, #0x6f
	bl sub_02037B38
	cmp r0, #0
	beq _02039F64
	add r0, r5, #0
	add r1, r6, #0
	bl Save_PrepareForAsyncWrite
	mov r0, #2
	str r0, [r4]
	b _02039F64
_02039F00:
	bl Save_WriteFileAsync
	add r5, r0, #0
	cmp r5, #2
	bne _02039F0E
	bl GF_AssertFail
_02039F0E:
	cmp r5, #1
	bne _02039F1E
	mov r0, #3
	str r0, [r4]
	mov r0, #0x70
	bl sub_02037AC0
	b _02039F64
_02039F1E:
	cmp r5, #3
	bne _02039F64
	mov r0, #7
	str r0, [r4]
	b _02039F64
_02039F28:
	mov r0, #0x70
	bl sub_02037B38
	cmp r0, #0
	beq _02039F64
	mov r0, #4
	str r0, [r4]
	b _02039F64
_02039F38:
	bl Save_WriteFileAsync
	add r5, r0, #0
	cmp r5, #1
	bne _02039F46
	bl GF_AssertFail
_02039F46:
	cmp r5, #2
	bne _02039F50
	mov r0, #5
	str r0, [r4]
	b _02039F64
_02039F50:
	cmp r5, #3
	bne _02039F64
	mov r0, #7
	str r0, [r4]
	b _02039F64
_02039F5A:
	mov r0, #6
	str r0, [r4]
	b _02039F64
_02039F60:
	mov r0, #1
	pop {r4, r5, r6, pc}
_02039F64:
	mov r0, #0
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02039EB4
	thumb_func_start sub_02039F68
sub_02039F68: ; 0x02039F68
	push {r3, r4, r5, r6, r7, lr}
	str r0, [sp]
	bl sub_02037454
	add r7, r0, #0
	mov r0, #0
	bl sub_02034818
	cmp r0, #0
	beq _02039FB6
	mov r5, #0
	cmp r7, #0
	ble _02039FB6
_02039F82:
	bl sub_0203769C
	cmp r5, r0
	beq _02039FB0
	add r0, r5, #0
	bl sub_020348A8
	add r4, r0, #0
	add r0, r5, #0
	bl sub_020348CC
	add r6, r0, #0
	add r0, r5, #0
	bl sub_02034818
	bl PlayerProfile_GetLanguage
	add r3, r0, #0
	ldr r0, [sp]
	add r1, r4, #0
	add r2, r6, #0
	bl sub_02039FB8
_02039FB0:
	add r5, r5, #1
	cmp r5, r7
	blt _02039F82
_02039FB6:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02039F68
