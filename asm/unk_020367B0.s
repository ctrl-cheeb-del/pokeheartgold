	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020367B0
sub_020367B0: ; 0x020367B0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r0, _020368E4 ; =_021D4140
	add r5, r1, #0
	ldr r2, [r0, #8]
	ldr r0, _020368E8 ; =0x00000668
	ldr r1, [r2, r0]
	sub r1, r1, #1
	str r1, [r2, r0]
	cmp r5, #0
	beq _020367D4
	ldrb r0, [r5]
	cmp r0, #0xb
	bne _020367DA
	bl sub_02035FF0
	cmp r0, #1
	bne _020367D6
_020367D4:
	b _020368E0
_020367D6:
	add r5, r5, #1
	b _020367E2
_020367DA:
	bl sub_02035FF0
	cmp r0, #0
	beq _020368E0
_020367E2:
	ldr r0, _020368E4 ; =_021D4140
	ldr r1, _020368EC ; =0x000006B2
	ldr r0, [r0, #8]
	ldrb r1, [r0, r1]
	cmp r1, #0
	beq _020367F6
	ldrb r2, [r5]
	mov r1, #1
	tst r1, r2
	bne _020368E0
_020367F6:
	ldr r1, _020368EC ; =0x000006B2
	mov r2, #0
	strb r2, [r0, r1]
	bl sub_02035FF0
	cmp r0, #1
	bne _020368B4
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_0203772C
	add r6, r0, #0
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r0, r0, #1
	mov r4, #0
	str r0, [sp, #4]
	cmp r0, #0
	ble _020368E0
	sub r0, r6, #1
	add r7, r4, #0
	str r0, [sp]
_0203682E:
	ldrb r0, [r5]
	cmp r0, #0xff
	bne _02036846
	ldr r0, _020368E4 ; =_021D4140
	mov r2, #1
	ldr r1, [r0, #8]
	ldr r0, _020368F0 ; =0x00000694
	lsl r2, r4
	ldrh r0, [r1, r0]
	mvn r2, r2
	and r2, r0
	b _02036854
_02036846:
	ldr r0, _020368E4 ; =_021D4140
	mov r2, #1
	ldr r1, [r0, #8]
	ldr r0, _020368F0 ; =0x00000694
	lsl r2, r4
	ldrh r0, [r1, r0]
	orr r2, r0
_02036854:
	ldr r0, _020368F0 ; =0x00000694
	strh r2, [r1, r0]
	ldrb r2, [r5]
	cmp r2, #0xff
	bne _02036862
	add r5, r5, r6
	b _020368A6
_02036862:
	cmp r2, #0xe
	bne _0203686A
	add r5, r5, r6
	b _020368A6
_0203686A:
	ldr r0, _020368E4 ; =_021D4140
	ldr r3, [r0, #8]
	ldr r0, _020368F4 ; =0x0000069E
	add r1, r3, r4
	ldrb r0, [r1, r0]
	cmp r0, #0
	beq _02036882
	mov r0, #1
	tst r0, r2
	beq _02036882
	add r5, r5, r6
	b _020368A6
_02036882:
	ldr r0, _020368F8 ; =0x0000051C
	add r5, r5, #1
	add r0, r3, r0
	ldr r3, _020368FC ; =0x0000054C
	ldr r2, [sp]
	add r0, r0, r7
	add r1, r5, #0
	add r3, r4, r3
	bl sub_02033AF0
	ldr r0, [sp]
	mov r1, #0
	add r5, r5, r0
	ldr r0, _020368E4 ; =_021D4140
	ldr r0, [r0, #8]
	add r2, r0, r4
	ldr r0, _020368F4 ; =0x0000069E
	strb r1, [r2, r0]
_020368A6:
	ldr r0, [sp, #4]
	add r4, r4, #1
	add r7, #0xc
	cmp r4, r0
	blt _0203682E
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_020368B4:
	ldr r1, _020368E4 ; =_021D4140
	ldrb r3, [r5, #1]
	ldr r2, [r1, #8]
	ldr r0, _020368F0 ; =0x00000694
	strh r3, [r2, r0]
	ldr r3, [r1, #8]
	ldrh r2, [r3, r0]
	lsl r2, r2, #8
	strh r2, [r3, r0]
	ldr r4, [r1, #8]
	ldrb r2, [r5, #2]
	ldrh r3, [r4, r0]
	add r2, r3, r2
	strh r2, [r4, r0]
	ldr r0, [r1, #8]
	ldr r3, _02036900 ; =0x000004A4
	ldrb r2, [r5, #3]
	add r0, r0, r3
	add r1, r5, #4
	add r3, #0xbc
	bl sub_02033AF0
_020368E0:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_020368E4: .word _021D4140
_020368E8: .word 0x00000668
_020368EC: .word 0x000006B2
_020368F0: .word 0x00000694
_020368F4: .word 0x0000069E
_020368F8: .word 0x0000051C
_020368FC: .word 0x0000054C
_02036900: .word 0x000004A4
	thumb_func_end sub_020367B0
