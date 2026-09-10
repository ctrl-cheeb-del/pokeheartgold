	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02010AB0
sub_02010AB0: ; 0x02010AB0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r3, #0
	add r6, r2, #0
	ldrb r2, [r5]
	ldr r4, [sp, #0x18]
	ldr r7, [sp, #0x1c]
	lsl r2, r2, #7
	str r2, [r0]
	ldrb r2, [r5, #1]
	lsl r2, r2, #7
	str r2, [r0, #4]
	ldrb r2, [r5, #2]
	lsl r2, r2, #7
	str r2, [r0, #8]
	ldrb r2, [r5, #3]
	lsl r2, r2, #7
	str r2, [r0, #0xc]
	ldrb r0, [r4]
	add r2, r7, #0
	str r0, [r1]
	ldrb r0, [r4, #1]
	str r0, [r1, #4]
	ldrb r0, [r4, #2]
	str r0, [r1, #8]
	ldrb r0, [r4, #3]
	str r0, [r1, #0xc]
	ldrb r0, [r5]
	ldrb r1, [r4]
	bl sub_02010A6C
	str r0, [r6]
	ldrb r0, [r5, #1]
	ldrb r1, [r4, #1]
	add r2, r7, #0
	bl sub_02010A6C
	str r0, [r6, #4]
	ldrb r0, [r5, #2]
	ldrb r1, [r4, #2]
	add r2, r7, #0
	bl sub_02010A6C
	str r0, [r6, #8]
	ldrb r0, [r5, #3]
	ldrb r1, [r4, #3]
	add r2, r7, #0
	bl sub_02010A6C
	str r0, [r6, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02010AB0
	thumb_func_start sub_02010B14
sub_02010B14: ; 0x02010B14
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r6, r1, #0
	mov r1, #0x1c
	bl Heap_Alloc
	str r0, [r5, #0x14]
	mov r2, #0x1c
	mov r1, #0
_02010B28:
	strb r1, [r0]
	add r0, r0, #1
	sub r2, r2, #1
	bne _02010B28
	ldr r4, [r5, #0x14]
	cmp r6, #0
	ldrh r1, [r5, #0x24]
	ldr r0, _02010BB0 ; =0x00007FFF
	bne _02010B5C
	cmp r1, r0
	bne _02010B44
	mov r7, #0x10
	mov r6, #0
	b _02010B7C
_02010B44:
	cmp r1, #0
	bne _02010B50
	mov r7, #0xf
	mvn r7, r7
	mov r6, #0
	b _02010B7C
_02010B50:
	mov r7, #0xf
	mvn r7, r7
	mov r6, #0
	bl GF_AssertFail
	b _02010B7C
_02010B5C:
	cmp r1, r0
	bne _02010B66
	mov r7, #0
	mov r6, #0x10
	b _02010B7C
_02010B66:
	cmp r1, #0
	bne _02010B72
	mov r7, #0
	add r6, r7, #0
	sub r6, #0x10
	b _02010B7C
_02010B72:
	mov r7, #0
	add r6, r7, #0
	sub r6, #0x10
	bl GF_AssertFail
_02010B7C:
	ldr r0, [r5, #0x10]
	add r1, r7, #0
	bl SetMasterBrightness
	ldr r0, [r5, #4]
	add r1, r6, #0
	str r0, [r4]
	ldr r0, [r5, #8]
	str r0, [r4, #4]
	mov r0, #0
	str r0, [r4, #8]
	lsl r0, r7, #7
	str r0, [r4, #0xc]
	lsl r0, r6, #7
	str r0, [r4, #0x10]
	ldr r2, [r5, #4]
	add r0, r7, #0
	bl sub_02010A6C
	str r0, [r4, #0x14]
	ldr r0, [r5, #0x10]
	str r0, [r4, #0x18]
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02010BB0: .word 0x00007FFF
	thumb_func_end sub_02010B14
	thumb_func_start sub_02010BB4
sub_02010BB4: ; 0x02010BB4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r1, [r5, #0xc]
	mov r4, #0
	ldr r0, [r5, #0x14]
	cmp r1, #1
	beq _02010BCC
	cmp r1, #2
	beq _02010BDC
	cmp r1, #3
	beq _02010BEE
	b _02010BF0
_02010BCC:
	bl sub_02010BF4
	cmp r0, #1
	bne _02010BF0
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02010BF0
_02010BDC:
	bl Heap_Free
	add r0, r4, #0
	str r0, [r5, #0x14]
	ldr r0, [r5, #0xc]
	mov r4, #1
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02010BF0
_02010BEE:
	mov r4, #1
_02010BF0:
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02010BB4
	thumb_func_start sub_02010BF4
sub_02010BF4: ; 0x02010BF4
	push {r4, lr}
	add r1, r0, #0
	ldr r0, [r1, #8]
	mov r4, #0
	add r2, r0, #1
	str r2, [r1, #8]
	ldr r0, [r1, #4]
	cmp r2, r0
	blt _02010C32
	str r4, [r1, #8]
	ldr r0, [r1]
	sub r0, r0, #1
	cmp r0, #0
	ble _02010C1C
	str r0, [r1]
	ldr r2, [r1, #0xc]
	ldr r0, [r1, #0x14]
	add r0, r2, r0
	str r0, [r1, #0xc]
	b _02010C22
_02010C1C:
	ldr r0, [r1, #0x10]
	mov r4, #1
	str r0, [r1, #0xc]
_02010C22:
	ldr r2, [r1, #0xc]
	ldr r0, [r1, #0x18]
	asr r1, r2, #6
	lsr r1, r1, #0x19
	add r1, r2, r1
	asr r1, r1, #7
	bl SetMasterBrightness
_02010C32:
	add r0, r4, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02010BF4
	thumb_func_start sub_02010C38
sub_02010C38: ; 0x02010C38
	push {r4, r5, r6, lr}
	add r4, r0, #0
	bne _02010C42
	bl GF_AssertFail
_02010C42:
	ldr r0, _02010E54 ; =0x04000006
	ldrh r0, [r0]
	cmp r0, #0xc0
	bge _02010CE8
	add r5, r0, #1
	cmp r5, #0xbf
	ble _02010C52
	sub r5, #0xc0
_02010C52:
	ldr r0, [r4, #4]
	cmp r0, #1
	bne _02010D02
	add r0, r4, #0
	mov r1, #0
	bl sub_02010EE0
	ldr r3, [r4, #8]
	lsl r5, r5, #1
	mov r4, #6
	add r1, r0, r5
	lsl r4, r4, #6
	ldrsh r2, [r1, r4]
	lsl r4, r4, #2
	ldrsh r1, [r0, r5]
	ldr r0, [r0, r4]
	cmp r0, #0
	ldr r0, _02010E58 ; =0x04000004
	bne _02010CBC
	cmp r3, #0
	bne _02010C9C
	ldrh r4, [r0]
	mov r3, #2
	tst r3, r4
	beq _02010CE8
	lsl r3, r1, #8
	mov r1, #0xff
	lsl r1, r1, #8
	and r3, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	orr r1, r3
	strh r1, [r0, #0x3c]
	mov r1, #0xc0
	add r0, #0x40
	strh r1, [r0]
	pop {r4, r5, r6, pc}
_02010C9C:
	ldrh r3, [r0]
	mov r0, #2
	tst r0, r3
	beq _02010CE8
	mov r0, #0xff
	lsl r1, r1, #8
	lsl r0, r0, #8
	and r1, r0
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	ldr r1, _02010E5C ; =0x04001040
	strh r0, [r1]
	mov r0, #0xc0
	strh r0, [r1, #4]
	pop {r4, r5, r6, pc}
_02010CBC:
	cmp r3, #0
	bne _02010CE0
	ldrh r4, [r0]
	mov r3, #2
	tst r3, r4
	beq _02010CE8
	lsl r3, r1, #8
	mov r1, #0xff
	lsl r1, r1, #8
	and r3, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	orr r1, r3
	strh r1, [r0, #0x3e]
	mov r1, #0xc0
	add r0, #0x42
	strh r1, [r0]
	pop {r4, r5, r6, pc}
_02010CE0:
	ldrh r3, [r0]
	mov r0, #2
	tst r0, r3
	bne _02010CEA
_02010CE8:
	b _02010E50
_02010CEA:
	mov r0, #0xff
	lsl r1, r1, #8
	lsl r0, r0, #8
	and r1, r0
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	ldr r1, _02010E60 ; =0x04001042
	strh r0, [r1]
	mov r0, #0xc0
	strh r0, [r1, #4]
	pop {r4, r5, r6, pc}
_02010D02:
	add r0, r4, #0
	mov r1, #0
	bl sub_02010EE0
	add r3, r0, #0
	lsl r5, r5, #1
	mov r6, #6
	add r1, r3, r5
	lsl r6, r6, #6
	ldrsh r2, [r1, r6]
	lsl r6, r6, #2
	ldrsh r1, [r3, r5]
	ldr r3, [r3, r6]
	ldr r0, [r4, #8]
	cmp r3, #0
	bne _02010D68
	cmp r0, #0
	ldr r0, _02010E58 ; =0x04000004
	bne _02010D48
	ldrh r6, [r0]
	mov r3, #2
	tst r3, r6
	beq _02010DAC
	lsl r3, r1, #8
	mov r1, #0xff
	lsl r1, r1, #8
	and r3, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	orr r1, r3
	strh r1, [r0, #0x3c]
	mov r1, #0xc0
	add r0, #0x40
	strh r1, [r0]
	b _02010DAC
_02010D48:
	ldrh r3, [r0]
	mov r0, #2
	tst r0, r3
	beq _02010DAC
	mov r0, #0xff
	lsl r1, r1, #8
	lsl r0, r0, #8
	and r1, r0
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	ldr r1, _02010E5C ; =0x04001040
	strh r0, [r1]
	mov r0, #0xc0
	strh r0, [r1, #4]
	b _02010DAC
_02010D68:
	cmp r0, #0
	ldr r0, _02010E58 ; =0x04000004
	bne _02010D8E
	ldrh r6, [r0]
	mov r3, #2
	tst r3, r6
	beq _02010DAC
	lsl r3, r1, #8
	mov r1, #0xff
	lsl r1, r1, #8
	and r3, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	orr r1, r3
	strh r1, [r0, #0x3e]
	mov r1, #0xc0
	add r0, #0x42
	strh r1, [r0]
	b _02010DAC
_02010D8E:
	ldrh r3, [r0]
	mov r0, #2
	tst r0, r3
	beq _02010DAC
	mov r0, #0xff
	lsl r1, r1, #8
	lsl r0, r0, #8
	and r1, r0
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	ldr r1, _02010E60 ; =0x04001042
	strh r0, [r1]
	mov r0, #0xc0
	strh r0, [r1, #4]
_02010DAC:
	add r0, r4, #0
	mov r1, #1
	bl sub_02010EE0
	ldr r3, [r4, #8]
	mov r4, #6
	add r1, r0, r5
	lsl r4, r4, #6
	ldrsh r2, [r1, r4]
	lsl r4, r4, #2
	ldrsh r1, [r0, r5]
	ldr r0, [r0, r4]
	cmp r0, #0
	ldr r0, _02010E58 ; =0x04000004
	bne _02010E0E
	cmp r3, #0
	bne _02010DEE
	ldrh r4, [r0]
	mov r3, #2
	tst r3, r4
	beq _02010E50
	lsl r3, r1, #8
	mov r1, #0xff
	lsl r1, r1, #8
	and r3, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	orr r1, r3
	strh r1, [r0, #0x3c]
	mov r1, #0xc0
	add r0, #0x40
	strh r1, [r0]
	pop {r4, r5, r6, pc}
_02010DEE:
	ldrh r3, [r0]
	mov r0, #2
	tst r0, r3
	beq _02010E50
	mov r0, #0xff
	lsl r1, r1, #8
	lsl r0, r0, #8
	and r1, r0
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	ldr r1, _02010E5C ; =0x04001040
	strh r0, [r1]
	mov r0, #0xc0
	strh r0, [r1, #4]
	pop {r4, r5, r6, pc}
_02010E0E:
	cmp r3, #0
	bne _02010E32
	ldrh r4, [r0]
	mov r3, #2
	tst r3, r4
	beq _02010E50
	lsl r3, r1, #8
	mov r1, #0xff
	lsl r1, r1, #8
	and r3, r1
	lsl r1, r2, #0x18
	lsr r1, r1, #0x18
	orr r1, r3
	strh r1, [r0, #0x3e]
	mov r1, #0xc0
	add r0, #0x42
	strh r1, [r0]
	pop {r4, r5, r6, pc}
_02010E32:
	ldrh r3, [r0]
	mov r0, #2
	tst r0, r3
	beq _02010E50
	mov r0, #0xff
	lsl r1, r1, #8
	lsl r0, r0, #8
	and r1, r0
	lsl r0, r2, #0x18
	lsr r0, r0, #0x18
	orr r0, r1
	ldr r1, _02010E60 ; =0x04001042
	strh r0, [r1]
	mov r0, #0xc0
	strh r0, [r1, #4]
_02010E50:
	pop {r4, r5, r6, pc}
	nop
_02010E54: .word 0x04000006
_02010E58: .word 0x04000004
_02010E5C: .word 0x04001040
_02010E60: .word 0x04001042
	thumb_func_end sub_02010C38
	thumb_func_start sub_02010E64
sub_02010E64: ; 0x02010E64
	push {r4, r5, r6, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r6, r2, #0
	cmp r4, #0
	beq _02010E7A
	cmp r4, #1
	beq _02010E7A
	cmp r4, #2
	beq _02010E94
	pop {r4, r5, r6, pc}
_02010E7A:
	ldr r1, _02010EC0 ; =0x00000604
	add r0, r3, #0
	bl Heap_Alloc
	str r0, [r5]
	mov r0, #1
	str r0, [r5, #4]
	str r6, [r5, #8]
	mov r0, #6
	ldr r1, [r5]
	lsl r0, r0, #8
	str r4, [r1, r0]
	pop {r4, r5, r6, pc}
_02010E94:
	ldr r1, _02010EC4 ; =0x00000C08
	add r0, r3, #0
	bl Heap_Alloc
	str r0, [r5]
	mov r0, #2
	str r0, [r5, #4]
	mov r0, #6
	mov r3, #0
	lsl r0, r0, #8
	str r6, [r5, #8]
	add r4, r3, #0
	add r1, r0, #4
_02010EAE:
	ldr r2, [r5]
	add r2, r2, r4
	str r3, [r2, r0]
	add r3, r3, #1
	add r4, r4, r1
	cmp r3, #2
	blt _02010EAE
	pop {r4, r5, r6, pc}
	nop
_02010EC0: .word 0x00000604
_02010EC4: .word 0x00000C08
	thumb_func_end sub_02010E64
