	.include "asm/macros.inc"
	.include "unk_02032844.inc"
	.include "global.inc"

	.data

	.public _0210F8FC
_0210F8FC:
	.byte 0x44, 0x50, 0x00, 0x00

	.bss

	.public _021D4124
_021D4124:
	.space 0x8

	.text
	thumb_func_start sub_02032934
sub_02032934: ; 0x02032934
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldrh r0, [r5, #0x10]
	mov r1, #1
	lsl r1, r0
	lsl r0, r1, #0x10
	lsr r4, r0, #0x10
	ldrh r0, [r5, #2]
	cmp r0, #0
	beq _02032954
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	pop {r4, r5, r6, pc}
_02032954:
	ldrh r0, [r5, #8]
	cmp r0, #7
	bgt _0203296C
	bge _02032986
	cmp r0, #2
	bgt _02032A24
	cmp r0, #0
	blt _02032A24
	beq _02032A16
	cmp r0, #2
	beq _02032978
	pop {r4, r5, r6, pc}
_0203296C:
	cmp r0, #9
	bgt _02032974
	beq _020329F8
	pop {r4, r5, r6, pc}
_02032974:
	cmp r0, #0x1a
	pop {r4, r5, r6, pc}
_02032978:
	ldr r0, _02032A28 ; =_021D4124
	ldr r2, [r0, #4]
	ldr r0, _02032A2C ; =0x00001345
	ldrb r1, [r2, r0]
	add r1, r1, #1
	strb r1, [r2, r0]
	pop {r4, r5, r6, pc}
_02032986:
	ldr r0, _02032A28 ; =_021D4124
	ldr r2, [r0, #4]
	ldr r0, _02032A30 ; =0x00001343
	ldrb r1, [r2, r0]
	cmp r1, #1
	beq _020329C4
	sub r0, r0, #1
	ldrb r0, [r2, r0]
	cmp r0, #1
	beq _020329C4
	bl sub_02033264
	ldr r1, _02032A28 ; =_021D4124
	ldr r2, [r1, #4]
	ldr r1, _02032A34 ; =0x00001334
	ldrb r1, [r2, r1]
	cmp r0, r1
	bge _020329C4
	bl sub_0203993C
	ldrb r1, [r5, #0x14]
	cmp r1, r0
	bne _020329C4
	add r1, r5, #0
	ldr r0, _02032A38 ; =_0210F8FC
	add r1, #0x15
	mov r2, #3
	bl memcmp
	cmp r0, #0
	beq _020329DC
_020329C4:
	ldrh r1, [r5, #0x10]
	mov r0, #0
	bl WM_Disconnect
	cmp r0, #2
	beq _02032A24
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	pop {r4, r5, r6, pc}
_020329DC:
	ldr r1, _02032A28 ; =_021D4124
	ldr r0, _02032A3C ; =0x0000132E
	ldr r3, [r1, #4]
	ldrh r2, [r3, r0]
	orr r2, r4
	strh r2, [r3, r0]
	ldr r1, [r1, #4]
	sub r0, r0, #6
	ldr r1, [r1, r0]
	cmp r1, #0
	beq _02032A24
	ldrh r0, [r5, #0x10]
	blx r1
	pop {r4, r5, r6, pc}
_020329F8:
	ldr r2, _02032A28 ; =_021D4124
	ldr r1, _02032A3C ; =0x0000132E
	ldr r0, [r2, #4]
	mvn r3, r4
	ldrh r6, [r0, r1]
	and r3, r6
	strh r3, [r0, r1]
	ldr r0, [r2, #4]
	sub r1, #0xa
	ldr r1, [r0, r1]
	cmp r1, #0
	beq _02032A24
	ldrh r0, [r5, #0x10]
	blx r1
	pop {r4, r5, r6, pc}
_02032A16:
	bl sub_02032A40
	cmp r0, #0
	bne _02032A24
	mov r0, #9
	bl sub_02032844
_02032A24:
	pop {r4, r5, r6, pc}
	nop
_02032A28: .word _021D4124
_02032A2C: .word 0x00001345
_02032A30: .word 0x00001343
_02032A34: .word 0x00001334
_02032A38: .word _0210F8FC
_02032A3C: .word 0x0000132E
	thumb_func_end sub_02032934
	thumb_func_start sub_02032A40
sub_02032A40: ; 0x02032A40
	push {r4, lr}
	sub sp, #8
	ldr r0, _02032A9C ; =_021D4124
	ldr r1, [r0, #4]
	ldr r0, _02032AA0 ; =0x00001310
	ldr r0, [r1, r0]
	sub r0, r0, #4
	cmp r0, #2
	bhi _02032A58
	add sp, #8
	mov r0, #1
	pop {r4, pc}
_02032A58:
	mov r0, #4
	bl sub_02032844
	ldr r0, _02032A9C ; =_021D4124
	ldr r2, _02032AA4 ; =0x00001304
	ldr r4, [r0, #4]
	ldr r3, _02032AA8 ; =0x00001020
	ldr r0, [r4, r2]
	add r2, r2, #4
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	ldr r2, [r4, r2]
	add r1, r4, r3
	lsl r2, r2, #0x10
	sub r3, #0xe0
	ldr r0, _02032AAC ; =sub_02032AB0
	lsr r2, r2, #0x10
	add r3, r4, r3
	bl WM_StartMP
	cmp r0, #2
	beq _02032A94
	bl sub_02032858
	add sp, #8
	mov r0, #0
	pop {r4, pc}
_02032A94:
	mov r0, #1
	add sp, #8
	pop {r4, pc}
	nop
_02032A9C: .word _021D4124
_02032AA0: .word 0x00001310
_02032AA4: .word 0x00001304
_02032AA8: .word 0x00001020
_02032AAC: .word sub_02032AB0
	thumb_func_end sub_02032A40
	thumb_func_start sub_02032AB0
sub_02032AB0: ; 0x02032AB0
	push {r3, lr}
	ldrh r1, [r0, #2]
	cmp r1, #0
	beq _02032AC6
	add r0, r1, #0
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	pop {r3, pc}
_02032AC6:
	ldrh r0, [r0, #4]
	sub r0, #0xa
	cmp r0, #3
	bhi _02032B00
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02032ADA: ; jump table
	.short _02032AE2 - _02032ADA - 2 ; case 0
	.short _02032B00 - _02032ADA - 2 ; case 1
	.short _02032B00 - _02032ADA - 2 ; case 2
	.short _02032B00 - _02032ADA - 2 ; case 3
_02032AE2:
	ldr r0, _02032B04 ; =_021D4124
	ldr r2, [r0, #4]
	ldr r0, _02032B08 ; =0x00001314
	ldr r1, [r2, r0]
	cmp r1, #2
	bne _02032AFA
	sub r0, r0, #4
	ldr r0, [r2, r0]
	cmp r0, #4
	beq _02032AFA
	cmp r0, #6
	beq _02032B00
_02032AFA:
	mov r0, #4
	bl sub_02032844
_02032B00:
	pop {r3, pc}
	nop
_02032B04: .word _021D4124
_02032B08: .word 0x00001314
	thumb_func_end sub_02032AB0
