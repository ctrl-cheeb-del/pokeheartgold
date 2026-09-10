	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
	.public sub_02011130
	.public sub_0201164C
	.public sub_0201169C
	.public sub_020116EC
	.public sub_02011744
	.public sub_020117A0
	.public sub_020117FC
	.public sub_02011884
	.public sub_020118BC
	.public sub_02011918
	.public sub_020119F4
	.public sub_02011A44
	.public sub_02011AD8
	.public sub_02011B5C
	.public sub_02011B94
	.public sub_02011BF0
	.public sub_02011CB8
	.public sub_02011D08
	.public sub_02011D60
	.public sub_02011D98
	.public sub_02011DEC
	.public sub_02011EC0
	.public sub_02011F10
	.public sub_02011FF8
	.public sub_02012030
	.public sub_02012090
	.public sub_020121A4
	thumb_func_start sub_020117A0
sub_020117A0: ; 0x020117A0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r1, #0
	add r1, r4, #4
	add r5, r0, #0
	add r6, r2, #0
	str r1, [sp]
	add r1, r5, #0
	add r2, r5, #0
	add r7, r3, #0
	add r1, #0x20
	add r2, #0x10
	add r3, r4, #0
	str r6, [sp, #4]
	bl sub_02010AB0
	ldr r1, [sp, #0x30]
	str r1, [r5, #0x30]
	ldrb r0, [r4, #8]
	str r0, [r5, #0x34]
	str r6, [r5, #0x38]
	str r7, [r5, #0x3c]
	mov r0, #0
	str r0, [r5, #0x40]
	ldr r0, [sp, #0x34]
	str r0, [r5, #0x48]
	ldrb r2, [r4, #0xb]
	str r2, [r5, #0x44]
	str r1, [sp]
	ldrb r1, [r4]
	str r1, [sp, #4]
	ldrb r1, [r4, #1]
	str r1, [sp, #8]
	ldrb r1, [r4, #2]
	str r1, [sp, #0xc]
	ldrb r1, [r4, #3]
	str r1, [sp, #0x10]
	ldr r1, [r5, #0x44]
	str r1, [sp, #0x14]
	ldrb r1, [r4, #9]
	ldrb r2, [r4, #0xa]
	ldrb r3, [r4, #8]
	bl sub_02010F84
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_020117A0
