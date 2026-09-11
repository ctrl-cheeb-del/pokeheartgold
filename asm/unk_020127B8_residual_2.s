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
