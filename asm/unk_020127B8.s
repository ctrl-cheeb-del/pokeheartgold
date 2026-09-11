	.include "asm/macros.inc"
	.public _020127E6
	.public _02012804
	.public _0201280A
	.public _02012880
	.public _020128F8
	.public _0201291A
	.public _02012934
	.public _02012938
	.public _0201293C
	.public _0201297A
	.public _02012990
	.public _02012A02
	.public _02012A18
	.public _02012A72
	.public _02012A86
	.public sub_020127B8
	.public sub_02012884
	.public sub_0201289C
	.public sub_020128E0
	.public sub_02012940
	.public sub_02012A2C
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	.public sub_02012884
	.public sub_0201289C
	.public sub_020128E0
	.public sub_02012A2C
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
