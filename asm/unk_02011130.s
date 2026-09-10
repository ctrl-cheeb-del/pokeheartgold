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
	thumb_func_start sub_02011130
sub_02011130: ; 0x02011130
	push {r3, r4, r5, lr}
	add r4, r0, #0
	bne _0201113A
	bl GF_AssertFail
_0201113A:
	ldr r0, _02011428 ; =0x04000006
	ldrh r0, [r0]
	cmp r0, #0xc0
	bge _020111BC
	add r0, r0, #1
	cmp r0, #0xbf
	ble _0201114A
	sub r0, #0xc0
_0201114A:
	mov r2, #0xc2
	lsl r2, r2, #2
	ldrb r1, [r4, r2]
	cmp r1, #1
	beq _02011156
	b _020112F0
_02011156:
	add r0, r4, r0
	add r0, #0xc0
	ldrb r0, [r0]
	cmp r0, #0
	bne _02011226
	add r0, r2, #1
	ldrb r0, [r4, r0]
	cmp r0, #0
	ldr r0, _0201142C ; =0x04000004
	bne _02011186
	ldrh r2, [r0]
	mov r1, #2
	tst r1, r2
	beq _020111A0
	add r0, #0x46
	ldrh r2, [r0]
	mov r1, #0x3f
	bic r2, r1
	mov r1, #0x3f
	orr r2, r1
	mov r1, #0x20
	orr r1, r2
	strh r1, [r0]
	b _020111A0
_02011186:
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	beq _020111A0
	ldr r1, _02011430 ; =0x0400104A
	mov r0, #0x3f
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #0x3f
	orr r2, r0
	mov r0, #0x20
	orr r0, r2
	strh r0, [r1]
_020111A0:
	ldr r0, _02011434 ; =0x00000309
	ldrb r1, [r4, r0]
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _020111EC
	cmp r1, #0
	bne _020111D0
	ldr r2, _0201142C ; =0x04000004
	mov r0, #2
	ldrh r1, [r2]
	tst r0, r1
	bne _020111BE
_020111BC:
	b _02011634
_020111BE:
	add r2, #0x44
	ldrh r1, [r2]
	mov r0, #0x3f
	bic r1, r0
	mov r0, #0x20
	orr r1, r0
	orr r0, r1
	strh r0, [r2]
	pop {r3, r4, r5, pc}
_020111D0:
	ldr r0, _0201142C ; =0x04000004
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	beq _020112D8
	ldr r1, _02011438 ; =0x04001048
	mov r0, #0x3f
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #0x20
	orr r2, r0
	orr r0, r2
	strh r0, [r1]
	pop {r3, r4, r5, pc}
_020111EC:
	cmp r1, #0
	ldr r0, _0201142C ; =0x04000004
	bne _0201120C
	ldrh r1, [r0]
	mov r2, #2
	tst r1, r2
	beq _020112D8
	add r0, #0x44
	ldrh r3, [r0]
	ldr r1, _0201143C ; =0xFFFFC0FF
	and r3, r1
	lsl r1, r2, #0xc
	orr r3, r1
	orr r1, r3
	strh r1, [r0]
	pop {r3, r4, r5, pc}
_0201120C:
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	beq _020112D8
	ldr r2, _02011438 ; =0x04001048
	ldr r0, _0201143C ; =0xFFFFC0FF
	ldrh r1, [r2]
	and r1, r0
	lsr r0, r2, #0xd
	orr r1, r0
	orr r0, r1
	strh r0, [r2]
	pop {r3, r4, r5, pc}
_02011226:
	add r0, r2, #1
	ldrb r0, [r4, r0]
	cmp r0, #0
	ldr r0, _0201142C ; =0x04000004
	bne _0201124A
	ldrh r2, [r0]
	mov r1, #2
	tst r1, r2
	beq _02011262
	add r0, #0x46
	ldrh r2, [r0]
	mov r1, #0x3f
	bic r2, r1
	mov r1, #0x20
	orr r2, r1
	orr r1, r2
	strh r1, [r0]
	b _02011262
_0201124A:
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	beq _02011262
	ldr r1, _02011430 ; =0x0400104A
	mov r0, #0x3f
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #0x20
	orr r2, r0
	orr r0, r2
	strh r0, [r1]
_02011262:
	ldr r0, _02011434 ; =0x00000309
	ldrb r1, [r4, r0]
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	cmp r0, #0
	ldr r0, _0201142C ; =0x04000004
	bne _020112AE
	cmp r1, #0
	bne _02011292
	ldrh r2, [r0]
	mov r1, #2
	tst r1, r2
	beq _020112D8
	add r0, #0x44
	ldrh r2, [r0]
	mov r1, #0x3f
	bic r2, r1
	mov r1, #0x3f
	orr r2, r1
	mov r1, #0x20
	orr r1, r2
	strh r1, [r0]
	pop {r3, r4, r5, pc}
_02011292:
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	beq _020112D8
	ldr r1, _02011438 ; =0x04001048
	mov r0, #0x3f
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #0x3f
	orr r2, r0
	mov r0, #0x20
	orr r0, r2
	strh r0, [r1]
	pop {r3, r4, r5, pc}
_020112AE:
	cmp r1, #0
	bne _020112D0
	ldrh r1, [r0]
	mov r2, #2
	tst r1, r2
	beq _020112D8
	add r0, #0x44
	ldrh r3, [r0]
	ldr r1, _0201143C ; =0xFFFFC0FF
	and r3, r1
	mov r1, #0x3f
	lsl r1, r1, #8
	orr r3, r1
	lsl r1, r2, #0xc
	orr r1, r3
	strh r1, [r0]
	pop {r3, r4, r5, pc}
_020112D0:
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	bne _020112DA
_020112D8:
	b _02011634
_020112DA:
	ldr r2, _02011438 ; =0x04001048
	ldr r0, _0201143C ; =0xFFFFC0FF
	ldrh r1, [r2]
	and r1, r0
	mov r0, #0x3f
	lsl r0, r0, #8
	orr r1, r0
	lsr r0, r2, #0xd
	orr r0, r1
	strh r0, [r2]
	pop {r3, r4, r5, pc}
_020112F0:
	add r1, r4, r0
	add r1, #0xc0
	ldrb r1, [r1]
	cmp r1, #0
	bne _020113BC
	add r1, r2, #1
	ldrb r1, [r4, r1]
	cmp r1, #0
	ldr r1, _0201142C ; =0x04000004
	bne _02011320
	ldrh r3, [r1]
	mov r2, #2
	tst r2, r3
	beq _0201133A
	add r1, #0x46
	ldrh r3, [r1]
	mov r2, #0x3f
	bic r3, r2
	mov r2, #0x3f
	orr r3, r2
	mov r2, #0x20
	orr r2, r3
	strh r2, [r1]
	b _0201133A
_02011320:
	ldrh r2, [r1]
	mov r1, #2
	tst r1, r2
	beq _0201133A
	ldr r2, _02011430 ; =0x0400104A
	mov r1, #0x3f
	ldrh r3, [r2]
	bic r3, r1
	mov r1, #0x3f
	orr r3, r1
	mov r1, #0x20
	orr r1, r3
	strh r1, [r2]
_0201133A:
	ldr r1, _02011434 ; =0x00000309
	ldrb r2, [r4, r1]
	mov r1, #6
	lsl r1, r1, #6
	ldr r1, [r4, r1]
	cmp r1, #0
	ldr r1, _0201142C ; =0x04000004
	bne _02011382
	cmp r2, #0
	bne _02011368
	ldrh r3, [r1]
	mov r2, #2
	tst r2, r3
	beq _0201138E
	add r1, #0x44
	ldrh r3, [r1]
	mov r2, #0x3f
	bic r3, r2
	mov r2, #0x20
	orr r3, r2
	orr r2, r3
	strh r2, [r1]
	b _0201149A
_02011368:
	ldrh r2, [r1]
	mov r1, #2
	tst r1, r2
	beq _0201138E
	ldr r2, _02011438 ; =0x04001048
	mov r1, #0x3f
	ldrh r3, [r2]
	bic r3, r1
	mov r1, #0x20
	orr r3, r1
	orr r1, r3
	strh r1, [r2]
	b _0201149A
_02011382:
	cmp r2, #0
	bne _020113A2
	ldrh r2, [r1]
	mov r3, #2
	tst r2, r3
	bne _02011390
_0201138E:
	b _0201149A
_02011390:
	add r1, #0x44
	ldrh r5, [r1]
	ldr r2, _0201143C ; =0xFFFFC0FF
	and r5, r2
	lsl r2, r3, #0xc
	orr r5, r2
	orr r2, r5
	strh r2, [r1]
	b _0201149A
_020113A2:
	ldrh r2, [r1]
	mov r1, #2
	tst r1, r2
	beq _0201149A
	ldr r3, _02011438 ; =0x04001048
	ldr r1, _0201143C ; =0xFFFFC0FF
	ldrh r2, [r3]
	and r2, r1
	lsr r1, r3, #0xd
	orr r2, r1
	orr r1, r2
	strh r1, [r3]
	b _0201149A
_020113BC:
	add r1, r2, #1
	ldrb r1, [r4, r1]
	cmp r1, #0
	ldr r1, _0201142C ; =0x04000004
	bne _020113E0
	ldrh r3, [r1]
	mov r2, #2
	tst r2, r3
	beq _020113F8
	add r1, #0x46
	ldrh r3, [r1]
	mov r2, #0x3f
	bic r3, r2
	mov r2, #0x20
	orr r3, r2
	orr r2, r3
	strh r2, [r1]
	b _020113F8
_020113E0:
	ldrh r2, [r1]
	mov r1, #2
	tst r1, r2
	beq _020113F8
	ldr r2, _02011430 ; =0x0400104A
	mov r1, #0x3f
	ldrh r3, [r2]
	bic r3, r1
	mov r1, #0x20
	orr r3, r1
	orr r1, r3
	strh r1, [r2]
_020113F8:
	ldr r1, _02011434 ; =0x00000309
	ldrb r2, [r4, r1]
	mov r1, #6
	lsl r1, r1, #6
	ldr r1, [r4, r1]
	cmp r1, #0
	ldr r1, _0201142C ; =0x04000004
	bne _0201145C
	cmp r2, #0
	bne _02011440
	ldrh r3, [r1]
	mov r2, #2
	tst r2, r3
	beq _0201149A
	add r1, #0x44
	ldrh r3, [r1]
	mov r2, #0x3f
	bic r3, r2
	mov r2, #0x3f
	orr r3, r2
	mov r2, #0x20
	orr r2, r3
	strh r2, [r1]
	b _0201149A
	.balign 4, 0
_02011428: .word 0x04000006
_0201142C: .word 0x04000004
_02011430: .word 0x0400104A
_02011434: .word 0x00000309
_02011438: .word 0x04001048
_0201143C: .word 0xFFFFC0FF
_02011440:
	ldrh r2, [r1]
	mov r1, #2
	tst r1, r2
	beq _0201149A
	ldr r2, _02011638 ; =0x04001048
	mov r1, #0x3f
	ldrh r3, [r2]
	bic r3, r1
	mov r1, #0x3f
	orr r3, r1
	mov r1, #0x20
	orr r1, r3
	strh r1, [r2]
	b _0201149A
_0201145C:
	cmp r2, #0
	bne _0201147E
	ldrh r2, [r1]
	mov r3, #2
	tst r2, r3
	beq _0201149A
	add r1, #0x44
	ldrh r5, [r1]
	ldr r2, _0201163C ; =0xFFFFC0FF
	and r5, r2
	mov r2, #0x3f
	lsl r2, r2, #8
	orr r5, r2
	lsl r2, r3, #0xc
	orr r2, r5
	strh r2, [r1]
	b _0201149A
_0201147E:
	ldrh r2, [r1]
	mov r1, #2
	tst r1, r2
	beq _0201149A
	ldr r3, _02011638 ; =0x04001048
	ldr r1, _0201163C ; =0xFFFFC0FF
	ldrh r2, [r3]
	and r2, r1
	mov r1, #0x3f
	lsl r1, r1, #8
	orr r2, r1
	lsr r1, r3, #0xd
	orr r1, r2
	strh r1, [r3]
_0201149A:
	mov r1, #0x61
	lsl r1, r1, #2
	add r1, r4, r1
	add r0, r1, r0
	add r0, #0xc0
	ldrb r0, [r0]
	cmp r0, #0
	ldr r0, _02011640 ; =0x00000309
	bne _02011570
	ldrb r0, [r4, r0]
	cmp r0, #0
	ldr r0, _02011644 ; =0x04000004
	bne _020114D0
	ldrh r3, [r0]
	mov r2, #2
	tst r2, r3
	beq _020114EA
	add r0, #0x46
	ldrh r3, [r0]
	mov r2, #0x3f
	bic r3, r2
	mov r2, #0x3f
	orr r3, r2
	mov r2, #0x20
	orr r2, r3
	strh r2, [r0]
	b _020114EA
_020114D0:
	ldrh r2, [r0]
	mov r0, #2
	tst r0, r2
	beq _020114EA
	ldr r2, _02011648 ; =0x0400104A
	mov r0, #0x3f
	ldrh r3, [r2]
	bic r3, r0
	mov r0, #0x3f
	orr r3, r0
	mov r0, #0x20
	orr r0, r3
	strh r0, [r2]
_020114EA:
	ldr r0, _02011640 ; =0x00000309
	ldrb r2, [r4, r0]
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	cmp r0, #0
	bne _02011536
	cmp r2, #0
	bne _02011518
	ldr r2, _02011644 ; =0x04000004
	mov r0, #2
	ldrh r1, [r2]
	tst r0, r1
	beq _02011522
	add r2, #0x44
	ldrh r1, [r2]
	mov r0, #0x3f
	bic r1, r0
	mov r0, #0x20
	orr r1, r0
	orr r0, r1
	strh r0, [r2]
	pop {r3, r4, r5, pc}
_02011518:
	ldr r0, _02011644 ; =0x04000004
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	bne _02011524
_02011522:
	b _02011634
_02011524:
	ldr r1, _02011638 ; =0x04001048
	mov r0, #0x3f
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #0x20
	orr r2, r0
	orr r0, r2
	strh r0, [r1]
	pop {r3, r4, r5, pc}
_02011536:
	cmp r2, #0
	ldr r0, _02011644 ; =0x04000004
	bne _02011556
	ldrh r1, [r0]
	mov r2, #2
	tst r1, r2
	beq _02011634
	add r0, #0x44
	ldrh r3, [r0]
	ldr r1, _0201163C ; =0xFFFFC0FF
	and r3, r1
	lsl r1, r2, #0xc
	orr r3, r1
	orr r1, r3
	strh r1, [r0]
	pop {r3, r4, r5, pc}
_02011556:
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	beq _02011634
	ldr r2, _02011638 ; =0x04001048
	ldr r0, _0201163C ; =0xFFFFC0FF
	ldrh r1, [r2]
	and r1, r0
	lsr r0, r2, #0xd
	orr r1, r0
	orr r0, r1
	strh r0, [r2]
	pop {r3, r4, r5, pc}
_02011570:
	ldrb r0, [r4, r0]
	cmp r0, #0
	ldr r0, _02011644 ; =0x04000004
	bne _02011592
	ldrh r3, [r0]
	mov r2, #2
	tst r2, r3
	beq _020115AA
	add r0, #0x46
	ldrh r3, [r0]
	mov r2, #0x3f
	bic r3, r2
	mov r2, #0x20
	orr r3, r2
	orr r2, r3
	strh r2, [r0]
	b _020115AA
_02011592:
	ldrh r2, [r0]
	mov r0, #2
	tst r0, r2
	beq _020115AA
	ldr r2, _02011648 ; =0x0400104A
	mov r0, #0x3f
	ldrh r3, [r2]
	bic r3, r0
	mov r0, #0x20
	orr r3, r0
	orr r0, r3
	strh r0, [r2]
_020115AA:
	ldr r0, _02011640 ; =0x00000309
	ldrb r2, [r4, r0]
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r1, r0]
	cmp r0, #0
	ldr r0, _02011644 ; =0x04000004
	bne _020115F6
	cmp r2, #0
	bne _020115DA
	ldrh r2, [r0]
	mov r1, #2
	tst r1, r2
	beq _02011634
	add r0, #0x44
	ldrh r2, [r0]
	mov r1, #0x3f
	bic r2, r1
	mov r1, #0x3f
	orr r2, r1
	mov r1, #0x20
	orr r1, r2
	strh r1, [r0]
	pop {r3, r4, r5, pc}
_020115DA:
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	beq _02011634
	ldr r1, _02011638 ; =0x04001048
	mov r0, #0x3f
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #0x3f
	orr r2, r0
	mov r0, #0x20
	orr r0, r2
	strh r0, [r1]
	pop {r3, r4, r5, pc}
_020115F6:
	cmp r2, #0
	bne _02011618
	ldrh r1, [r0]
	mov r2, #2
	tst r1, r2
	beq _02011634
	add r0, #0x44
	ldrh r3, [r0]
	ldr r1, _0201163C ; =0xFFFFC0FF
	and r3, r1
	mov r1, #0x3f
	lsl r1, r1, #8
	orr r3, r1
	lsl r1, r2, #0xc
	orr r1, r3
	strh r1, [r0]
	pop {r3, r4, r5, pc}
_02011618:
	ldrh r1, [r0]
	mov r0, #2
	tst r0, r1
	beq _02011634
	ldr r2, _02011638 ; =0x04001048
	ldr r0, _0201163C ; =0xFFFFC0FF
	ldrh r1, [r2]
	and r1, r0
	mov r0, #0x3f
	lsl r0, r0, #8
	orr r1, r0
	lsr r0, r2, #0xd
	orr r0, r1
	strh r0, [r2]
_02011634:
	pop {r3, r4, r5, pc}
	nop
_02011638: .word 0x04001048
_0201163C: .word 0xFFFFC0FF
_02011640: .word 0x00000309
_02011644: .word 0x04000004
_02011648: .word 0x0400104A
	thumb_func_end sub_02011130
