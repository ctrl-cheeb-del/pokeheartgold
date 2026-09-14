	.include "asm/macros.inc"
	.include "overlay_96.inc"
	.include "global.inc"
	.include "overlay_96_exact_bank.inc"

	.text
	thumb_func_start ov96_021ECA70
ov96_021ECA70: ; 0x021ECA70
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r6, r0, #0
	mov r7, #0
	mov r4, #1
	mov r5, #2
_021ECA84:
	lsl r1, r4, #0x18
	ldr r0, [r6, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [sp, #8]
	lsl r1, r5, #0x18
	ldr r0, [r6, #0x14]
	lsr r1, r1, #0x18
	bl ov96_021EAA04
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	mov r1, #0
	bl ov96_021EAB38
	ldr r0, [sp, #0xc]
	mov r1, #0
	bl ov96_021EAB38
	add r7, r7, #1
	add r4, r4, #3
	add r5, r5, #3
	cmp r7, #4
	blt _021ECA84
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl ov96_021EC790
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ECA70




	thumb_func_start ov96_021ECAC4
ov96_021ECAC4: ; 0x021ECAC4
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	bl PokeathlonCourse_GetHeapAllocPtr4
	add r7, r0, #0
	str r0, [sp]
	add r0, #0x20
	mov r4, #0
	add r5, r7, #0
	str r0, [sp]
_021ECAD8:
	add r0, r6, #0
	bl PokeathlonCourse_GetParticipantCount
	cmp r4, #4
	bne _021ECAF6
	mov r0, #2
	bl ov96_021EEBC8
	add r1, r0, #0
	ldr r0, [r5, #0x20]
	ldr r3, [r7]
	mov r2, #0xb
	bl ov96_021EEA88
	b _021ECB2C
_021ECAF6:
	cmp r4, r0
	bge _021ECB0A
	lsl r2, r4, #0x18
	ldr r0, [sp]
	add r1, r6, #0
	lsr r2, r2, #0x18
	mov r3, #0
	bl ov96_021EEB74
	b _021ECB2C
_021ECB0A:
	add r0, r6, #0
	add r1, r4, #0
	bl PokeathlonCourse_GetParticipantData
	ldr r0, [r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl ov96_021E8424
	bl ov96_021EEDCC
	add r1, r0, #0
	ldr r0, [r5, #0x20]
	ldr r3, [r7]
	mov r2, #0
	bl ov96_021EEA88
_021ECB2C:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #5
	blt _021ECAD8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov96_021ECAC4




	thumb_func_start ov96_021ECB38
ov96_021ECB38: ; 0x021ECB38
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r2, #0
	str r0, [sp]
	str r1, [sp, #4]
	add r0, r1, #0
	add r1, r5, #0
	add r7, r3, #0
	bl PokeathlonCourse_GetParticipantData
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECB56
	mov r6, #1
	b _021ECB58
_021ECB56:
	mov r6, #0
_021ECB58:
	cmp r7, #1
	beq _021ECB62
	cmp r7, #2
	beq _021ECB66
	b _021ECB72
_021ECB62:
	mov r4, #0
	b _021ECB76
_021ECB66:
	cmp r6, #0
	beq _021ECB6E
	mov r4, #0xb
	b _021ECB76
_021ECB6E:
	mov r4, #0x1b
	b _021ECB76
_021ECB72:
	bl GF_AssertFail
_021ECB76:
	cmp r6, #0
	beq _021ECBA6
	ldr r0, [sp, #4]
	add r1, r5, #0
	bl PokeathlonCourse_GetParticipantData
	ldr r0, [r0]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl ov96_021E8424
	bl ov96_021EEDCC
	add r1, r0, #0
	ldr r0, [sp]
	lsl r2, r5, #2
	ldr r0, [r0, r2]
	lsl r2, r4, #0x18
	ldr r3, [sp, #0x20]
	lsr r2, r2, #0x18
	bl ov96_021EEA88
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_021ECBA6:
	lsl r2, r5, #0x18
	ldr r0, [sp]
	ldr r1, [sp, #4]
	lsr r2, r2, #0x18
	add r3, r4, #0
	bl ov96_021EEB74
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021ECB38




	thumb_func_start ov96_021ECBB8
ov96_021ECBB8: ; 0x021ECBB8
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	mov r1, #0x70
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x70
	str r0, [sp]
	bl MI_CpuFill8
	ldr r3, [sp]
	mov r1, #0
	mov r4, #5
_021ECBD2:
	lsl r0, r4, #2
	mov r2, #0
	add r5, r7, r0
	add r6, r3, #0
_021ECBDA:
	ldr r0, [r5]
	add r2, r2, #1
	add r5, r5, #4
	stmia r6!, {r0}
	cmp r2, #4
	blt _021ECBDA
	add r1, r1, #1
	add r3, #0x1c
	add r4, r4, #4
	cmp r1, #4
	blt _021ECBD2
	ldr r0, [sp]
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov96_021ECBB8
