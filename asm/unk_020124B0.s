	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020124B0
sub_020124B0: ; 0x020124B0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	ldr r0, [r0, #0xc]
	ldr r1, _020125D0 ; =0x00003FFF
	bl _s32_div_f
	lsl r0, r1, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	ldr r0, [sp]
	mov r1, #0
	bl sub_02010EE0
	add r7, r0, #0
	ldr r0, [sp]
	mov r1, #1
	bl sub_02010EE0
	add r4, r0, #0
	mov r6, #0
	add r5, r4, #0
_020124DC:
	ldr r0, [sp]
	ldr r1, [r0, #0xc]
	ldr r0, _020125D0 ; =0x00003FFF
	cmp r1, r0
	bge _02012520
	mov r1, #0x60
	ldr r0, [sp, #4]
	sub r1, r1, r6
	bl sub_020109D8
	cmp r0, #0x7f
	ble _020124F6
	mov r0, #0x7f
_020124F6:
	mov r1, #0xbf
	sub r1, r1, r6
	lsl r1, r1, #1
	add r3, r7, r1
	mov r1, #0x80
	sub r2, r1, r0
	mov r1, #3
	lsl r1, r1, #8
	strh r2, [r3, r1]
	mov r1, #0x12
	mov r2, #0x80
	lsl r1, r1, #6
	strh r2, [r3, r1]
	mov r1, #3
	lsl r1, r1, #8
	strh r2, [r5, r1]
	mov r1, #0x12
	add r0, #0x80
	lsl r1, r1, #6
	strh r0, [r5, r1]
	b _02012548
_02012520:
	mov r0, #0xbf
	sub r0, r0, r6
	lsl r0, r0, #1
	mov r1, #3
	add r0, r7, r0
	mov r2, #0
	lsl r1, r1, #8
	strh r2, [r0, r1]
	mov r1, #0x12
	mov r2, #0x80
	lsl r1, r1, #6
	strh r2, [r0, r1]
	mov r0, #3
	add r1, r2, #0
	lsl r0, r0, #8
	strh r1, [r5, r0]
	mov r0, #0x12
	mov r1, #0xff
	lsl r0, r0, #6
	strh r1, [r5, r0]
_02012548:
	add r6, r6, #1
	add r5, r5, #2
	cmp r6, #0x60
	blt _020124DC
	ldr r1, _020125D0 ; =0x00003FFF
	ldr r0, [sp, #4]
	mov r5, #0x60
	add r4, #0xc0
	sub r6, r1, r0
_0201255A:
	ldr r0, [sp]
	ldr r1, [r0, #0xc]
	ldr r0, _020125D0 ; =0x00003FFF
	cmp r1, r0
	bge _0201258A
	mov r0, #0xbf
	sub r0, r0, r5
	lsl r0, r0, #1
	mov r1, #3
	add r0, r7, r0
	mov r2, #0x80
	lsl r1, r1, #8
	strh r2, [r0, r1]
	mov r1, #0x12
	lsl r1, r1, #6
	strh r2, [r0, r1]
	mov r0, #3
	add r1, r2, #0
	lsl r0, r0, #8
	strh r1, [r4, r0]
	mov r0, #0x12
	lsl r0, r0, #6
	strh r1, [r4, r0]
	b _020125C4
_0201258A:
	add r1, r5, #0
	add r0, r6, #0
	sub r1, #0x60
	bl sub_020109D8
	add r1, r0, #0
	cmp r1, #0x7f
	ble _0201259C
	mov r1, #0x7f
_0201259C:
	mov r0, #0xbf
	sub r0, r0, r5
	lsl r0, r0, #1
	mov r2, #3
	add r0, r7, r0
	mov r3, #0
	lsl r2, r2, #8
	strh r3, [r0, r2]
	mov r2, #0x80
	sub r3, r2, r1
	mov r2, #0x12
	lsl r2, r2, #6
	strh r3, [r0, r2]
	mov r0, #3
	add r1, #0x80
	lsl r0, r0, #8
	strh r1, [r4, r0]
	mov r1, #0xff
	add r0, r2, #0
	strh r1, [r4, r0]
_020125C4:
	add r5, r5, #1
	add r4, r4, #2
	cmp r5, #0xc0
	blt _0201255A
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_020125D0: .word 0x00003FFF
	thumb_func_end sub_020124B0
	thumb_func_start sub_020125D4
sub_020125D4: ; 0x020125D4
	push {r4, lr}
	add r4, r0, #0
	ldr r3, [r4, #8]
	add r0, r3, #0
	mul r0, r1
	add r1, r2, #0
	bl _s32_div_f
	ldr r1, [r4, #4]
	add r0, r0, r1
	str r0, [r4]
	pop {r4, pc}
	thumb_func_end sub_020125D4
	thumb_func_start sub_020125EC
sub_020125EC: ; 0x020125EC
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r4, r1, #0
	mov r1, #0x38
	bl Heap_Alloc
	str r0, [r5, #0x14]
	mov r1, #0
	mov r2, #0x38
	bl memset
	ldr r0, [r5, #0x10]
	add r1, r4, #0
	str r0, [sp]
	ldr r0, [r5, #0x18]
	str r0, [sp, #4]
	ldr r0, [r5, #0x1c]
	str r0, [sp, #8]
	ldr r0, [r5, #0x20]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x14]
	ldr r2, [r5, #4]
	ldr r3, [r5, #8]
	bl sub_0201268C
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_020125EC
	thumb_func_start sub_0201262C
sub_0201262C: ; 0x0201262C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	ldr r4, [r5, #0x14]
	cmp r0, #1
	beq _02012644
	cmp r0, #2
	beq _02012660
	cmp r0, #3
	beq _02012680
	b _02012684
_02012644:
	add r0, r4, #0
	bl sub_0201275C
	cmp r0, #1
	bne _02012688
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x30]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02012688
_02012660:
	add r0, r4, #0
	bl sub_020127B4
	add r0, r4, #0
	bl sub_02010EC8
	ldr r0, [r5, #0x14]
	bl Heap_Free
	add r0, r6, #0
	str r0, [r5, #0x14]
	ldr r0, [r5, #0xc]
	mov r6, #1
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02012688
_02012680:
	mov r6, #1
	b _02012688
_02012684:
	bl GF_AssertFail
_02012688:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	thumb_func_end sub_0201262C
	thumb_func_start sub_0201268C
sub_0201268C: ; 0x0201268C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r4, r1, #0
	ldrh r1, [r4]
	add r5, r0, #0
	str r3, [sp, #0x1c]
	str r1, [r5, #0xc]
	ldrh r1, [r4]
	str r2, [sp, #0x18]
	ldr r6, [sp, #0x38]
	str r1, [r5, #0x10]
	ldrh r2, [r4, #2]
	ldrh r1, [r4]
	ldr r3, [sp, #0x44]
	ldr r7, [sp, #0x3c]
	sub r1, r2, r1
	str r1, [r5, #0x14]
	mov r1, #2
	add r2, r6, #0
	bl sub_02010E64
	ldr r0, [sp, #0x18]
	mov r1, #0
	str r0, [r5, #0x18]
	ldr r0, [sp, #0x1c]
	str r1, [r5, #0x1c]
	str r0, [r5, #0x20]
	str r1, [r5, #0x24]
	ldr r0, [sp, #0x40]
	str r7, [r5, #0x30]
	str r0, [r5, #0x34]
	ldr r0, [sp, #0x44]
	str r0, [r5, #0x2c]
	ldrh r0, [r4, #6]
	str r0, [r5, #0x28]
	add r0, r5, #0
	bl sub_020127B8
	ldr r0, _02012750 ; =sub_02010F00
	ldr r2, _02012754 ; =0x000003FF
	add r1, r5, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r5, #0
	mov r1, #0
	bl sub_02010EE0
	add r0, r5, #0
	mov r1, #1
	bl sub_02010EE0
	str r6, [sp]
	mov r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	mov r0, #0xff
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x28]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	add r0, r7, #0
	bl sub_02010F84
	str r6, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0xff
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x28]
	mov r3, #1
	str r0, [sp, #0x14]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #5]
	add r0, r7, #0
	bl sub_02010F84
	ldr r3, [r5, #0x28]
	add r0, r7, #0
	mov r1, #3
	add r2, r6, #0
	bl sub_02011068
	ldr r0, [sp, #0x44]
	ldr r2, _02012758 ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r5, #0x34]
	add r1, r5, #0
	add r3, r6, #0
	bl sub_0200FF88
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02012750: .word sub_02010F00
_02012754: .word 0x000003FF
_02012758: .word sub_02010C38
	thumb_func_end sub_0201268C
	thumb_func_start sub_0201275C
sub_0201275C: ; 0x0201275C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0x24]
	add r1, r0, #1
	str r1, [r4, #0x24]
	ldr r0, [r4, #0x20]
	cmp r1, r0
	blt _020127A6
	mov r0, #0
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x1c]
	add r1, r0, #1
	ldr r0, [r4, #0x18]
	cmp r1, r0
	bgt _02012798
	str r1, [r4, #0x1c]
	add r0, r4, #0
	ldr r2, [r4, #0x18]
	add r0, #0xc
	bl sub_02012884
	add r0, r4, #0
	bl sub_020127B8
	ldr r0, _020127AC ; =sub_02010F00
	ldr r2, _020127B0 ; =0x000003FF
	add r1, r4, #0
	bl SysTask_CreateOnVWaitQueue
	b _020127A6
_02012798:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x2c]
	bl sub_0200FFB4
	mov r0, #1
	pop {r4, pc}
_020127A6:
	mov r0, #0
	pop {r4, pc}
	nop
_020127AC: .word sub_02010F00
_020127B0: .word 0x000003FF
	thumb_func_end sub_0201275C
