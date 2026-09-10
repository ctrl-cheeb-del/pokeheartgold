	.include "asm/macros.inc"
	.include "unk_02054648.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02054D10
sub_02054D10: ; 0x02054D10
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r7, r2, #0
	str r0, [sp]
	add r0, r1, #0
	lsl r1, r7, #2
	str r3, [sp, #4]
	bl Heap_AllocAtEnd
	str r0, [sp, #8]
	mov r0, #0
	cmp r7, #0
	ble _02054D36
	ldr r1, [sp, #8]
	ldr r2, [sp, #0x38]
_02054D2E:
	add r0, r0, #1
	stmia r1!, {r2}
	cmp r0, r7
	blt _02054D2E
_02054D36:
	mov r4, #0
	str r4, [sp, #0xc]
_02054D3A:
	ldr r1, [sp]
	ldr r0, [sp, #0xc]
	ldr r1, [r1, #0x2c]
	add r2, sp, #0x10
	bl ov01_021F630C
	ldr r0, [sp, #0x10]
	cmp r0, #0
	beq _02054DB2
	ldr r0, [sp]
	ldr r1, [sp, #0xc]
	ldr r0, [r0, #0x2c]
	bl ov01_021F652C
	add r5, r0, #0
	ldr r0, [sp]
	ldr r0, [r0, #0x30]
	bl MapMatrix_GetWidth
	add r1, r0, #0
	add r0, r5, #0
	add r2, sp, #0x14
	bl sub_02054DC8
	mov r5, #0
_02054D6C:
	ldr r0, [sp, #0x10]
	add r1, r5, #0
	bl MapPropManager_GetMapPropByIndex
	ldr r1, [sp, #4]
	add r2, sp, #0x14
	add r6, r0, #0
	bl sub_02054A9C
	cmp r0, #0
	beq _02054DA8
	add r0, r6, #0
	bl MapProp_GetBuildModel
	cmp r0, #0
	beq _02054DA8
	cmp r4, r7
	blo _02054D9A
	bl GF_AssertFail
	ldr r0, [sp, #8]
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
_02054D9A:
	add r1, r4, #1
	lsl r1, r1, #0x18
	add r2, r4, #0
	lsr r4, r1, #0x18
	ldr r1, [sp, #8]
	lsl r2, r2, #2
	str r0, [r1, r2]
_02054DA8:
	add r0, r5, #1
	lsl r0, r0, #0x18
	lsr r5, r0, #0x18
	cmp r5, #0x20
	blo _02054D6C
_02054DB2:
	ldr r0, [sp, #0xc]
	add r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	cmp r0, #4
	blo _02054D3A
	ldr r0, [sp, #8]
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02054D10
