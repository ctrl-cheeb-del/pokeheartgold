	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020127B8
sub_020127B8: ; 0x020127B8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r4, r0, #0
	ldr r1, [r4, #0xc]
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	str r1, [sp, #8]
	mov r1, #0
	bl sub_02010EE0
	str r0, [sp, #0x10]
	add r0, r4, #0
	mov r1, #1
	bl sub_02010EE0
	str r0, [sp, #0xc]
	add r5, r0, #0
	ldr r1, _02012880 ; =0x00003FFF
	ldr r0, [sp, #8]
	ldr r6, [sp, #0x10]
	sub r0, r1, r0
	mov r7, #0
	str r0, [sp, #4]
_020127E6:
	mov r0, #0x60
	sub r0, r0, r7
	str r0, [sp]
	ldr r0, [sp, #8]
	ldr r1, [sp]
	bl sub_020109D8
	add r4, r0, #0
	ldr r0, [sp, #4]
	ldr r1, [sp]
	bl sub_020109D8
	cmp r4, #0x7f
	ble _02012804
	mov r4, #0x7f
_02012804:
	cmp r0, #0x7f
	ble _0201280A
	mov r0, #0x7f
_0201280A:
	mov r1, #0x80
	sub r1, r1, r0
	lsl r1, r1, #0x10
	mov r2, #3
	asr r1, r1, #0x10
	lsl r2, r2, #8
	str r1, [sp, #0x14]
	strh r1, [r6, r2]
	mov r1, #0x80
	sub r1, r1, r4
	lsl r1, r1, #0x10
	asr r2, r1, #0x10
	mov r1, #0x12
	lsl r1, r1, #6
	strh r2, [r6, r1]
	mov r1, #0xbf
	sub r1, r1, r7
	mov ip, r2
	lsl r1, r1, #1
	ldr r2, [sp, #0x10]
	add r0, #0x80
	add r3, r2, r1
	str r1, [sp, #0x18]
	mov r2, #3
	ldr r1, [sp, #0x14]
	lsl r2, r2, #8
	strh r1, [r3, r2]
	mov r1, #0x12
	mov r2, ip
	lsl r1, r1, #6
	strh r2, [r3, r1]
	add r4, #0x80
	lsl r1, r4, #0x10
	asr r2, r1, #0x10
	mov r1, #3
	lsl r1, r1, #8
	lsl r0, r0, #0x10
	strh r2, [r5, r1]
	asr r1, r0, #0x10
	mov r0, #0x12
	lsl r0, r0, #6
	strh r1, [r5, r0]
	ldr r3, [sp, #0xc]
	ldr r0, [sp, #0x18]
	add r7, r7, #1
	add r0, r3, r0
	mov r3, #3
	lsl r3, r3, #8
	strh r2, [r0, r3]
	mov r2, #0x12
	lsl r2, r2, #6
	strh r1, [r0, r2]
	add r6, r6, #2
	add r5, r5, #2
	cmp r7, #0x60
	blt _020127E6
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_02012880: .word 0x00003FFF
	thumb_func_end sub_020127B8
	thumb_func_start sub_02012884
sub_02012884: ; 0x02012884
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
	thumb_func_end sub_02012884
	thumb_func_start sub_0201289C
sub_0201289C: ; 0x0201289C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r4, r1, #0
	mov r1, #0xcd
	ldr r0, [r5, #0x20]
	lsl r1, r1, #2
	bl Heap_Alloc
	mov r2, #0xcd
	str r0, [r5, #0x14]
	mov r1, #0
	lsl r2, r2, #2
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
	bl sub_02012940
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_0201289C
	thumb_func_start sub_020128E0
sub_020128E0: ; 0x020128E0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	ldr r4, [r5, #0x14]
	cmp r0, #1
	beq _020128F8
	cmp r0, #2
	beq _0201291A
	cmp r0, #3
	beq _02012934
	b _02012938
_020128F8:
	add r0, r4, #0
	bl sub_02012A2C
	cmp r0, #1
	bne _0201293C
	mov r1, #0xc9
	lsl r1, r1, #2
	ldr r0, [r4, r1]
	add r1, #8
	ldr r1, [r4, r1]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _0201293C
_0201291A:
	add r0, r4, #0
	bl sub_02012A8C
	ldr r0, [r5, #0x14]
	bl Heap_Free
	add r0, r6, #0
	str r0, [r5, #0x14]
	ldr r0, [r5, #0xc]
	mov r6, #1
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _0201293C
_02012934:
	mov r6, #1
	b _0201293C
_02012938:
	bl GF_AssertFail
_0201293C:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	thumb_func_end sub_020128E0
	thumb_func_start sub_02012940
sub_02012940: ; 0x02012940
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	ldr r7, [sp, #0x38]
	str r3, [sp, #0x1c]
	mov r3, #0
	add r4, r1, #0
	str r2, [sp, #0x18]
	str r3, [sp]
	add r1, r7, #0
	mov r2, #1
	add r5, r0, #0
	ldr r6, [sp, #0x3c]
	bl sub_02011080
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _0201297A
	add r0, r5, #0
	mov r1, #1
	mov r2, #0xc0
	bl memset
	add r0, r5, #0
	add r0, #0xc0
	mov r1, #1
	mov r2, #0xc0
	bl memset
	b _02012990
_0201297A:
	add r0, r5, #0
	mov r1, #0
	mov r2, #0xc0
	bl memset
	add r0, r5, #0
	add r0, #0xc0
	mov r1, #0
	mov r2, #0xc0
	bl memset
_02012990:
	mov r1, #0xc3
	ldr r0, [r4]
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldrh r2, [r4, #4]
	add r0, r1, #4
	ldr r3, [sp, #0x44]
	str r2, [r5, r0]
	add r0, r1, #0
	ldrh r2, [r4, #6]
	add r0, #0x18
	str r2, [r5, r0]
	add r0, r1, #0
	add r0, #0x1c
	str r3, [r5, r0]
	add r2, r1, #0
	ldr r0, [sp, #0x18]
	add r2, #8
	str r0, [r5, r2]
	add r2, r1, #0
	add r2, #0xc
	mov r0, #0
	str r0, [r5, r2]
	add r2, r1, #0
	ldr r0, [sp, #0x1c]
	add r2, #0x10
	str r0, [r5, r2]
	add r2, r1, #0
	add r2, #0x14
	mov r0, #0
	str r0, [r5, r2]
	add r0, r1, #0
	add r0, #0x20
	str r6, [r5, r0]
	ldr r0, [sp, #0x40]
	add r1, #0x24
	str r0, [r5, r1]
	add r1, r5, #0
	add r2, r3, #0
	bl sub_020110DC
	ldrh r0, [r4, #6]
	cmp r0, #1
	str r7, [sp]
	bne _02012A02
	mov r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, r6, #0
	mov r1, #0x20
	mov r2, #0x3f
	bl sub_02010F84
	b _02012A18
_02012A02:
	mov r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, r6, #0
	mov r1, #0x3f
	mov r2, #0x20
	bl sub_02010F84
_02012A18:
	mov r3, #0xc9
	lsl r3, r3, #2
	ldr r3, [r5, r3]
	add r0, r6, #0
	mov r1, #1
	add r2, r7, #0
	bl sub_02011068
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02012940
	thumb_func_start sub_02012A2C
sub_02012A2C: ; 0x02012A2C
	push {r4, lr}
	mov r2, #0x32
	add r4, r0, #0
	lsl r2, r2, #4
	ldr r1, [r4, r2]
	add r1, r1, #1
	str r1, [r4, r2]
	sub r1, r2, #4
	ldr r3, [r4, r2]
	ldr r1, [r4, r1]
	cmp r3, r1
	blt _02012A86
	mov r1, #0
	str r1, [r4, r2]
	add r1, r2, #0
	sub r1, #8
	ldr r1, [r4, r1]
	add r3, r1, #1
	add r1, r2, #0
	sub r1, #0xc
	ldr r1, [r4, r1]
	cmp r3, r1
	bgt _02012A72
	add r1, r2, #0
	sub r1, #8
	ldr r1, [r4, r1]
	sub r2, #8
	add r1, r1, #1
	str r1, [r4, r2]
	bl sub_02012A90
	add r0, r4, #0
	bl sub_020110C4
	b _02012A86
_02012A72:
	add r0, r2, #0
	add r0, #0x10
	add r2, #8
	ldr r0, [r4, r0]
	ldr r2, [r4, r2]
	add r1, r4, #0
	bl sub_020110F4
	mov r0, #1
	pop {r4, pc}
_02012A86:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02012A2C
