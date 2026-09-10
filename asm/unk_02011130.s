	.include "asm/macros.inc"
	.include "unk_0201010C.inc"
	.include "global.inc"
	.text
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
	thumb_func_start sub_0201164C
sub_0201164C: ; 0x0201164C
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r6, r1, #0
	mov r1, #0x4c
	bl Heap_Alloc
	str r0, [r5, #0x14]
	add r4, r0, #0
	ldr r0, [r5, #0x10]
	add r1, r6, #0
	str r0, [sp]
	ldr r0, [r5, #0x18]
	str r0, [sp, #4]
	ldr r2, [r5, #4]
	ldr r3, [r5, #8]
	add r0, r4, #0
	bl sub_020117A0
	ldrb r0, [r6, #8]
	cmp r0, #0
	ldr r0, [r5, #0x18]
	bne _02011688
	ldr r2, [r4, #0x30]
	ldr r3, [r4, #0x44]
	mov r1, #1
	bl sub_02011068
	b _02011692
_02011688:
	ldr r2, [r4, #0x30]
	ldr r3, [r4, #0x44]
	mov r1, #2
	bl sub_02011068
_02011692:
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #8
	pop {r4, r5, r6, pc}
	thumb_func_end sub_0201164C
	thumb_func_start sub_0201169C
sub_0201169C: ; 0x0201169C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	ldr r4, [r5, #0x14]
	cmp r0, #1
	beq _020116B4
	cmp r0, #2
	beq _020116D0
	cmp r0, #3
	beq _020116E4
	b _020116E6
_020116B4:
	add r0, r4, #0
	bl sub_020117FC
	cmp r0, #1
	bne _020116E6
	ldr r0, [r4, #0x44]
	ldr r1, [r5, #0x18]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _020116E6
_020116D0:
	add r0, r4, #0
	bl Heap_Free
	add r0, r6, #0
	str r0, [r5, #0x14]
	ldr r0, [r5, #0xc]
	mov r6, #1
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _020116E6
_020116E4:
	mov r6, #1
_020116E6:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_0201169C
	thumb_func_start sub_020116EC
sub_020116EC: ; 0x020116EC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r6, r1, #0
	mov r1, #0x98
	add r7, r2, #0
	bl Heap_Alloc
	str r0, [r5, #0x14]
	add r4, r0, #0
	ldr r0, [r5, #0x10]
	add r1, r6, #0
	str r0, [sp]
	ldr r0, [r5, #0x18]
	str r0, [sp, #4]
	ldr r2, [r5, #4]
	ldr r3, [r5, #8]
	add r0, r4, #0
	bl sub_020117A0
	ldr r0, [r5, #0x10]
	add r1, r7, #0
	str r0, [sp]
	ldr r0, [r5, #0x18]
	str r0, [sp, #4]
	add r0, r4, #0
	ldr r2, [r5, #4]
	ldr r3, [r5, #8]
	add r0, #0x4c
	bl sub_020117A0
	ldr r0, [r5, #0x18]
	ldr r2, [r5, #0x10]
	ldr r3, [r4, #0x44]
	mov r1, #3
	bl sub_02011068
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020116EC
	thumb_func_start sub_02011744
sub_02011744: ; 0x02011744
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r7, #0
	ldr r6, [r5, #0x14]
	cmp r0, #1
	beq _0201175C
	cmp r0, #2
	beq _02011784
	cmp r0, #3
	beq _02011798
	b _0201179A
_0201175C:
	add r0, r6, #0
	bl sub_020117FC
	add r4, r0, #0
	add r0, r6, #0
	add r0, #0x4c
	bl sub_020117FC
	add r0, r4, r0
	cmp r0, #2
	bne _0201179A
	ldr r0, [r6, #0x44]
	ldr r1, [r5, #0x18]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _0201179A
_02011784:
	add r0, r6, #0
	bl Heap_Free
	add r0, r7, #0
	str r0, [r5, #0x14]
	ldr r0, [r5, #0xc]
	mov r7, #1
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _0201179A
_02011798:
	mov r7, #1
_0201179A:
	add r0, r7, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02011744
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
	thumb_func_start sub_020117FC
sub_020117FC: ; 0x020117FC
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r1, [r4, #0x40]
	add r2, r1, #1
	str r2, [r4, #0x40]
	ldr r1, [r4, #0x3c]
	cmp r2, r1
	blt _0201187C
	mov r1, #0
	str r1, [r4, #0x40]
	ldr r1, [r4, #0x38]
	sub r1, r1, #1
	cmp r1, #0
	ble _02011826
	str r1, [r4, #0x38]
	add r1, r4, #0
	add r1, #0x10
	bl sub_02010A8C
	b _02011844
_02011826:
	ldr r0, [r4, #0x2c]
	str r0, [sp]
	ldr r0, [r4, #0x34]
	str r0, [sp, #4]
	ldr r0, [r4, #0x30]
	str r0, [sp, #8]
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x20]
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x28]
	bl sub_02013488
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_02011844:
	ldr r1, [r4, #0xc]
	asr r0, r1, #6
	lsr r0, r0, #0x19
	add r0, r1, r0
	asr r0, r0, #7
	str r0, [sp]
	ldr r0, [r4, #0x34]
	str r0, [sp, #4]
	ldr r0, [r4, #0x30]
	str r0, [sp, #8]
	ldr r2, [r4]
	ldr r3, [r4, #4]
	asr r1, r2, #6
	lsr r1, r1, #0x19
	add r1, r2, r1
	ldr r0, [r4, #0x48]
	asr r2, r3, #6
	lsr r2, r2, #0x19
	add r2, r3, r2
	ldr r4, [r4, #8]
	asr r1, r1, #7
	asr r3, r4, #6
	lsr r3, r3, #0x19
	add r3, r4, r3
	asr r2, r2, #7
	asr r3, r3, #7
	bl sub_02013488
_0201187C:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end sub_020117FC
	thumb_func_start sub_02011884
sub_02011884: ; 0x02011884
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r4, r1, #0
	mov r1, #0x38
	bl Heap_Alloc
	str r0, [r5, #0x14]
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
	bl sub_02011918
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02011884
	thumb_func_start sub_020118BC
sub_020118BC: ; 0x020118BC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	ldr r4, [r5, #0x14]
	cmp r0, #1
	beq _020118D4
	cmp r0, #2
	beq _020118F0
	cmp r0, #3
	beq _0201190A
	b _0201190E
_020118D4:
	add r0, r4, #0
	bl sub_020119F4
	cmp r0, #1
	bne _02011912
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02011912
_020118F0:
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
	b _02011912
_0201190A:
	mov r6, #1
	b _02011912
_0201190E:
	bl GF_AssertFail
_02011912:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_020118BC
	thumb_func_start sub_02011918
sub_02011918: ; 0x02011918
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r0, #0
	add r4, r1, #0
	mov r0, #0
	mov r1, #2
	ldrsh r0, [r4, r0]
	ldrsh r1, [r4, r1]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	ldr r6, [sp, #0x38]
	ldr r7, [sp, #0x3c]
	bl sub_02010A6C
	str r0, [sp, #0x20]
	ldrb r1, [r4, #8]
	ldr r3, [sp, #0x44]
	add r0, r5, #0
	add r2, r6, #0
	bl sub_02010E64
	mov r0, #0
	ldrsh r1, [r4, r0]
	lsl r1, r1, #7
	str r1, [r5, #0xc]
	mov r1, #4
	ldrsh r1, [r4, r1]
	str r1, [r5, #0x10]
	mov r1, #6
	ldrsh r1, [r4, r1]
	str r1, [r5, #0x14]
	ldr r1, [sp, #0x20]
	str r1, [r5, #0x18]
	ldr r1, [sp, #0x18]
	str r1, [r5, #0x1c]
	ldr r1, [sp, #0x1c]
	str r1, [r5, #0x20]
	str r0, [r5, #0x24]
	ldr r0, [sp, #0x40]
	str r7, [r5, #0x30]
	str r0, [r5, #0x34]
	ldr r0, [sp, #0x44]
	str r0, [r5, #0x28]
	ldrb r0, [r4, #0xb]
	str r0, [r5, #0x2c]
	add r0, r5, #0
	bl sub_02011AD8
	ldr r0, _020119E8 ; =sub_02010F00
	ldr r2, _020119EC ; =0x000003FF
	add r1, r5, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r5, #0
	mov r1, #0
	bl sub_02010EE0
	mov r1, #3
	str r6, [sp]
	lsl r1, r1, #8
	ldrsh r1, [r0, r1]
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #0x12
	lsl r1, r1, #6
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x2c]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #9]
	ldrb r2, [r4, #0xa]
	ldrb r3, [r4, #8]
	add r0, r7, #0
	bl sub_02010F84
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _020119C8
	ldr r3, [r5, #0x2c]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	bl sub_02011068
	b _020119D4
_020119C8:
	ldr r3, [r5, #0x2c]
	add r0, r7, #0
	mov r1, #2
	add r2, r6, #0
	bl sub_02011068
_020119D4:
	ldr r0, [sp, #0x44]
	ldr r2, _020119F0 ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r5, #0x34]
	add r1, r5, #0
	add r3, r6, #0
	bl sub_0200FF88
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_020119E8: .word sub_02010F00
_020119EC: .word 0x000003FF
_020119F0: .word sub_02010C38
	thumb_func_end sub_02011918
	thumb_func_start sub_020119F4
sub_020119F4: ; 0x020119F4
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x24]
	add r2, r1, #1
	str r2, [r4, #0x24]
	ldr r1, [r4, #0x20]
	cmp r2, r1
	blt _02011A38
	mov r1, #0
	str r1, [r4, #0x24]
	ldr r1, [r4, #0x1c]
	sub r1, r1, #1
	cmp r1, #0
	ble _02011A2A
	str r1, [r4, #0x1c]
	ldr r2, [r4, #0xc]
	ldr r1, [r4, #0x18]
	add r1, r2, r1
	str r1, [r4, #0xc]
	bl sub_02011AD8
	ldr r0, _02011A3C ; =sub_02010F00
	ldr r2, _02011A40 ; =0x000003FF
	add r1, r4, #0
	bl SysTask_CreateOnVWaitQueue
	b _02011A38
_02011A2A:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x28]
	bl sub_0200FFB4
	mov r0, #1
	pop {r4, pc}
_02011A38:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_02011A3C: .word sub_02010F00
_02011A40: .word 0x000003FF
	thumb_func_end sub_020119F4
	thumb_func_start sub_02011A44
sub_02011A44: ; 0x02011A44
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r1, [sp]
	asr r1, r0, #6
	lsr r1, r1, #0x19
	add r1, r0, r1
	asr r1, r1, #7
	ldr r5, [sp, #0x20]
	ldr r4, [sp, #0x24]
	sub r0, r3, r2
	bpl _02011A5C
	neg r0, r0
_02011A5C:
	cmp r0, r1
	blt _02011A6A
	mov r0, #0
	str r0, [r5]
	add sp, #0xc
	str r0, [r4]
	pop {r4, r5, r6, r7, pc}
_02011A6A:
	lsl r0, r0, #0xc
	str r0, [sp, #4]
	asr r7, r0, #0x1f
	lsl r0, r1, #0xc
	asr r1, r0, #0x1f
	add r2, r0, #0
	add r3, r1, #0
	bl _ll_mul
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r6, r1, #0
	add r1, r7, #0
	add r2, r0, #0
	add r3, r7, #0
	bl _ll_mul
	add r2, r0, #0
	add r3, r1, #0
	mov r0, #2
	ldr r1, [sp, #8]
	mov r7, #0
	lsl r0, r0, #0xa
	add r0, r1, r0
	adc r6, r7
	lsl r1, r6, #0x14
	lsr r0, r0, #0xc
	orr r0, r1
	mov r1, #2
	lsl r1, r1, #0xa
	add r2, r2, r1
	adc r3, r7
	lsl r1, r3, #0x14
	lsr r2, r2, #0xc
	orr r2, r1
	sub r0, r0, r2
	bl FX_Sqrt
	asr r2, r0, #0xc
	ldr r0, [sp]
	sub r0, r0, r2
	str r0, [r5]
	bpl _02011AC4
	add r0, r7, #0
	str r0, [r5]
_02011AC4:
	ldr r1, [r5]
	lsl r0, r2, #1
	add r0, r1, r0
	str r0, [r4]
	cmp r0, #0xff
	ble _02011AD4
	mov r0, #0xff
	str r0, [r4]
_02011AD4:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_02011A44
	thumb_func_start sub_02011AD8
sub_02011AD8: ; 0x02011AD8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov r1, #0
	add r5, r0, #0
	bl sub_02010EE0
	add r7, r0, #0
	mov r4, #0
	add r6, r7, #0
_02011AEA:
	ldr r2, [r5, #0x14]
	cmp r4, r2
	bgt _02011B04
	add r0, sp, #0xc
	str r0, [sp]
	add r0, sp, #8
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x10]
	add r3, r4, #0
	bl sub_02011A44
	b _02011B3E
_02011B04:
	lsl r0, r2, #1
	cmp r4, r0
	bgt _02011B2C
	sub r0, r0, r4
	lsl r0, r0, #1
	add r1, r7, r0
	mov r0, #3
	lsl r0, r0, #8
	ldrsh r0, [r1, r0]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x14]
	lsl r0, r0, #1
	sub r0, r0, r4
	lsl r0, r0, #1
	add r1, r7, r0
	mov r0, #0x12
	lsl r0, r0, #6
	ldrsh r0, [r1, r0]
	str r0, [sp, #8]
	b _02011B3E
_02011B2C:
	add r0, sp, #0xc
	str r0, [sp]
	add r0, sp, #8
	str r0, [sp, #4]
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x10]
	add r3, r4, #0
	bl sub_02011A44
_02011B3E:
	mov r0, #3
	ldr r1, [sp, #0xc]
	lsl r0, r0, #8
	strh r1, [r6, r0]
	mov r0, #0x12
	ldr r1, [sp, #8]
	lsl r0, r0, #6
	strh r1, [r6, r0]
	add r4, r4, #1
	add r6, r6, #2
	cmp r4, #0xc0
	blt _02011AEA
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02011AD8
	thumb_func_start sub_02011B5C
sub_02011B5C: ; 0x02011B5C
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r4, r1, #0
	mov r1, #0x30
	bl Heap_Alloc
	str r0, [r5, #0x14]
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
	bl sub_02011BF0
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02011B5C
	thumb_func_start sub_02011B94
sub_02011B94: ; 0x02011B94
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	ldr r4, [r5, #0x14]
	cmp r0, #1
	beq _02011BAC
	cmp r0, #2
	beq _02011BC8
	cmp r0, #3
	beq _02011BE2
	b _02011BE6
_02011BAC:
	add r0, r4, #0
	bl sub_02011CB8
	cmp r0, #1
	bne _02011BEA
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02011BEA
_02011BC8:
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
	b _02011BEA
_02011BE2:
	mov r6, #1
	b _02011BEA
_02011BE6:
	bl GF_AssertFail
_02011BEA:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02011B94
	thumb_func_start sub_02011BF0
sub_02011BF0: ; 0x02011BF0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	add r4, r1, #0
	add r5, r0, #0
	ldrh r0, [r4]
	ldrh r1, [r4, #2]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	ldr r6, [sp, #0x38]
	ldr r7, [sp, #0x3c]
	bl sub_02010A6C
	str r0, [r5, #0x10]
	ldrb r1, [r4, #4]
	ldr r3, [sp, #0x44]
	add r0, r5, #0
	add r2, r6, #0
	bl sub_02010E64
	ldrh r0, [r4]
	lsl r0, r0, #7
	str r0, [r5, #0xc]
	ldr r0, [sp, #0x18]
	str r0, [r5, #0x14]
	ldr r0, [sp, #0x1c]
	str r0, [r5, #0x18]
	mov r0, #0
	str r0, [r5, #0x1c]
	ldr r0, [sp, #0x40]
	str r7, [r5, #0x24]
	str r0, [r5, #0x28]
	ldr r0, [sp, #0x44]
	str r0, [r5, #0x2c]
	ldrb r0, [r4, #7]
	str r0, [r5, #0x20]
	add r0, r5, #0
	bl sub_02011D08
	ldr r0, _02011CAC ; =sub_02010F00
	ldr r2, _02011CB0 ; =0x000003FF
	add r1, r5, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r5, #0
	mov r1, #0
	bl sub_02010EE0
	mov r1, #3
	str r6, [sp]
	lsl r1, r1, #8
	ldrsh r1, [r0, r1]
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #0x12
	lsl r1, r1, #6
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x20]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #4]
	add r0, r7, #0
	bl sub_02010F84
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _02011C8C
	ldr r3, [r5, #0x20]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	bl sub_02011068
	b _02011C98
_02011C8C:
	ldr r3, [r5, #0x20]
	add r0, r7, #0
	mov r1, #2
	add r2, r6, #0
	bl sub_02011068
_02011C98:
	ldr r0, [sp, #0x44]
	ldr r2, _02011CB4 ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r5, #0x28]
	add r1, r5, #0
	add r3, r6, #0
	bl sub_0200FF88
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02011CAC: .word sub_02010F00
_02011CB0: .word 0x000003FF
_02011CB4: .word sub_02010C38
	thumb_func_end sub_02011BF0
	thumb_func_start sub_02011CB8
sub_02011CB8: ; 0x02011CB8
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x1c]
	add r2, r1, #1
	str r2, [r4, #0x1c]
	ldr r1, [r4, #0x18]
	cmp r2, r1
	blt _02011CFC
	mov r1, #0
	str r1, [r4, #0x1c]
	ldr r1, [r4, #0x14]
	sub r1, r1, #1
	cmp r1, #0
	ble _02011CEE
	str r1, [r4, #0x14]
	ldr r2, [r4, #0xc]
	ldr r1, [r4, #0x10]
	add r1, r2, r1
	str r1, [r4, #0xc]
	bl sub_02011D08
	ldr r0, _02011D00 ; =sub_02010F00
	ldr r2, _02011D04 ; =0x000003FF
	add r1, r4, #0
	bl SysTask_CreateOnVWaitQueue
	b _02011CFC
_02011CEE:
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x2c]
	bl sub_0200FFB4
	mov r0, #1
	pop {r4, pc}
_02011CFC:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_02011D00: .word sub_02010F00
_02011D04: .word 0x000003FF
	thumb_func_end sub_02011CB8
	thumb_func_start sub_02011D08
sub_02011D08: ; 0x02011D08
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x104
	add r4, r0, #0
	mov r1, #0
	bl sub_02010EE0
	ldr r1, [r4, #0xc]
	add r5, r0, #0
	asr r0, r1, #6
	lsr r0, r0, #0x19
	add r0, r1, r0
	asr r0, r0, #7
	add r1, sp, #0
	mov r2, #0xc0
	mov r3, #0
	bl sub_02010A00
	mov r7, #0x12
	mov r6, #0
	add r4, sp, #0
	lsl r7, r7, #6
_02011D34:
	ldr r1, [r4]
	mov r0, #0x80
	neg r1, r1
	bl sub_02010A7C
	mov r1, #3
	lsl r1, r1, #8
	strh r0, [r5, r1]
	ldr r1, [r4]
	mov r0, #0x80
	bl sub_02010A7C
	strh r0, [r5, r7]
	add r6, r6, #1
	add r4, r4, #4
	add r5, r5, #2
	cmp r6, #0xc0
	blt _02011D34
	add sp, #0x1fc
	add sp, #0x104
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02011D08
	thumb_func_start sub_02011D60
sub_02011D60: ; 0x02011D60
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r4, r1, #0
	mov r1, #0x34
	bl Heap_Alloc
	str r0, [r5, #0x14]
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
	bl sub_02011DEC
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02011D60
	thumb_func_start sub_02011D98
sub_02011D98: ; 0x02011D98
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	ldr r4, [r5, #0x14]
	cmp r0, #1
	beq _02011DB0
	cmp r0, #2
	beq _02011DCC
	cmp r0, #3
	beq _02011DE6
	b _02011DE8
_02011DB0:
	add r0, r4, #0
	bl sub_02011EC0
	cmp r0, #1
	bne _02011DE8
	ldr r0, [r4, #0x24]
	ldr r1, [r4, #0x28]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _02011DE8
_02011DCC:
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
	b _02011DE8
_02011DE6:
	mov r6, #1
_02011DE8:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02011D98
	thumb_func_start sub_02011DEC
sub_02011DEC: ; 0x02011DEC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r4, r1, #0
	add r5, r0, #0
	ldrh r1, [r4, #2]
	ldrh r0, [r4]
	str r2, [sp, #0x18]
	str r3, [sp, #0x1c]
	sub r0, r1, r0
	add r1, r2, #0
	ldr r6, [sp, #0x38]
	ldr r7, [sp, #0x3c]
	bl _s32_div_f
	str r0, [sp, #0x20]
	ldrb r1, [r4, #4]
	ldr r3, [sp, #0x44]
	add r0, r5, #0
	add r2, r6, #0
	bl sub_02010E64
	mov r0, #2
	lsl r0, r0, #0x12
	str r0, [r5, #0xc]
	ldrh r0, [r4]
	str r0, [r5, #0x10]
	ldr r0, [sp, #0x20]
	str r0, [r5, #0x14]
	ldr r0, [sp, #0x18]
	str r0, [r5, #0x18]
	ldr r0, [sp, #0x1c]
	str r0, [r5, #0x1c]
	mov r0, #0
	str r0, [r5, #0x20]
	ldr r0, [sp, #0x40]
	str r7, [r5, #0x28]
	str r0, [r5, #0x2c]
	ldr r0, [sp, #0x44]
	str r0, [r5, #0x30]
	ldrb r0, [r4, #7]
	str r0, [r5, #0x24]
	add r0, r5, #0
	bl sub_02011F10
	ldr r0, _02011EB4 ; =sub_02010F00
	ldr r2, _02011EB8 ; =0x000003FF
	add r1, r5, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r5, #0
	mov r1, #0
	bl sub_02010EE0
	mov r1, #0xf
	str r6, [sp]
	lsl r1, r1, #6
	ldrsh r1, [r0, r1]
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #0x15
	lsl r1, r1, #6
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r5, #0x24]
	str r0, [sp, #0x14]
	ldrb r1, [r4, #5]
	ldrb r2, [r4, #6]
	ldrb r3, [r4, #4]
	add r0, r7, #0
	bl sub_02010F84
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _02011E94
	ldr r3, [r5, #0x24]
	add r0, r7, #0
	mov r1, #1
	add r2, r6, #0
	bl sub_02011068
	b _02011EA0
_02011E94:
	ldr r3, [r5, #0x24]
	add r0, r7, #0
	mov r1, #2
	add r2, r6, #0
	bl sub_02011068
_02011EA0:
	ldr r0, [sp, #0x44]
	ldr r2, _02011EBC ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r5, #0x2c]
	add r1, r5, #0
	add r3, r6, #0
	bl sub_0200FF88
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02011EB4: .word sub_02010F00
_02011EB8: .word 0x000003FF
_02011EBC: .word sub_02010C38
	thumb_func_end sub_02011DEC
	thumb_func_start sub_02011EC0
sub_02011EC0: ; 0x02011EC0
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x20]
	add r2, r1, #1
	str r2, [r4, #0x20]
	ldr r1, [r4, #0x1c]
	cmp r2, r1
	blt _02011F04
	mov r1, #0
	str r1, [r4, #0x20]
	ldr r1, [r4, #0x18]
	sub r1, r1, #1
	cmp r1, #0
	ble _02011EF6
	str r1, [r4, #0x18]
	ldr r2, [r4, #0x10]
	ldr r1, [r4, #0x14]
	add r1, r2, r1
	str r1, [r4, #0x10]
	bl sub_02011F10
	ldr r0, _02011F08 ; =sub_02010F00
	ldr r2, _02011F0C ; =0x000003FF
	add r1, r4, #0
	bl SysTask_CreateOnVWaitQueue
	b _02011F04
_02011EF6:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x30]
	bl sub_0200FFB4
	mov r0, #1
	pop {r4, pc}
_02011F04:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
_02011F08: .word sub_02010F00
_02011F0C: .word 0x000003FF
	thumb_func_end sub_02011EC0
	thumb_func_start sub_02011F10
sub_02011F10: ; 0x02011F10
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x110
	add r4, r0, #0
	mov r1, #0
	bl sub_02010EE0
	str r0, [sp]
	ldr r0, [r4, #0x10]
	ldr r2, [r4, #0xc]
	asr r0, r0, #4
	lsl r1, r0, #2
	ldr r0, _02011FF0 ; =FX_SinCosTable_
	asr r3, r2, #0x1f
	ldrsh r0, [r0, r1]
	asr r1, r0, #0x1f
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	asr r7, r1, #0xc
	lsl r0, r7, #1
	mov r1, #0x15
	bl _s32_div_f
	add r0, r0, #1
	lsl r0, r0, #1
	mov r1, #0xb4
	sub r2, r1, r0
	ldr r0, _02011FF4 ; =0x0000FFFF
	add r1, #0xb4
	mul r0, r2
	bl _s32_div_f
	lsr r1, r0, #0x1f
	add r1, r0, r1
	asr r4, r1, #1
	mov r1, #1
	add r0, r4, #0
	lsl r1, r1, #8
	bl sub_02010A54
	asr r0, r0, #0xc
	str r0, [sp, #4]
	cmp r0, #0xc0
	blt _02011F7C
	bl GF_AssertFail
_02011F7C:
	ldr r2, [sp, #4]
	add r0, r4, #0
	add r1, sp, #0xc
	mov r3, #0
	bl sub_02010A00
	ldr r5, [sp]
	mov r4, #0
_02011F8C:
	ldr r0, [sp, #4]
	add r1, r4, #1
	sub r0, r0, r1
	add r6, r7, #0
	cmp r0, #0
	ble _02011FA4
	lsl r1, r0, #2
	add r0, sp, #0xc
	ldr r0, [r0, r1]
	cmp r0, r7
	ble _02011FA4
	add r6, r0, #0
_02011FA4:
	mov r0, #0x80
	neg r1, r6
	bl sub_02010A7C
	str r0, [sp, #8]
	mov r0, #0x80
	add r1, r6, #0
	bl sub_02010A7C
	ldr r1, [sp, #8]
	lsl r0, r0, #0x10
	lsl r1, r1, #0x10
	asr r2, r1, #0x10
	mov r1, #3
	lsl r1, r1, #8
	strh r2, [r5, r1]
	asr r1, r0, #0x10
	mov r0, #0x12
	lsl r0, r0, #6
	strh r1, [r5, r0]
	mov r0, #0xbf
	sub r0, r0, r4
	lsl r3, r0, #1
	ldr r0, [sp]
	add r4, r4, #1
	add r0, r0, r3
	mov r3, #3
	lsl r3, r3, #8
	strh r2, [r0, r3]
	mov r2, #0x12
	lsl r2, r2, #6
	add r5, r5, #2
	strh r1, [r0, r2]
	cmp r4, #0x60
	blt _02011F8C
	add sp, #0x1fc
	add sp, #0x110
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02011FF0: .word FX_SinCosTable_
_02011FF4: .word 0x0000FFFF
	thumb_func_end sub_02011F10
	thumb_func_start sub_02011FF8
sub_02011FF8: ; 0x02011FF8
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	ldr r0, [r5, #0x20]
	add r4, r1, #0
	mov r1, #0x30
	bl Heap_Alloc
	str r0, [r5, #0x14]
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
	bl sub_02012090
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_02011FF8
	thumb_func_start sub_02012030
sub_02012030: ; 0x02012030
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5, #0xc]
	mov r6, #0
	ldr r4, [r5, #0x14]
	cmp r0, #1
	beq _02012048
	cmp r0, #2
	beq _02012064
	cmp r0, #3
	beq _02012084
	b _02012088
_02012048:
	add r0, r4, #0
	bl sub_020121A4
	cmp r0, #1
	bne _0201208C
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	ldr r2, [r5, #0x10]
	bl sub_02010F34
	ldr r0, [r5, #0xc]
	add r0, r0, #1
	str r0, [r5, #0xc]
	b _0201208C
_02012064:
	add r0, r4, #0
	bl sub_020121F4
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
	b _0201208C
_02012084:
	mov r6, #1
	b _0201208C
_02012088:
	bl GF_AssertFail
_0201208C:
	add r0, r6, #0
	pop {r4, r5, r6, pc}
	thumb_func_end sub_02012030
	thumb_func_start sub_02012090
sub_02012090: ; 0x02012090
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	add r5, r1, #0
	add r6, r0, #0
	str r2, [sp, #0x18]
	ldr r0, [sp, #0x38]
	ldrh r2, [r5, #8]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x44]
	mov r1, #0x30
	mul r1, r2
	str r3, [sp, #0x1c]
	str r0, [sp, #0x44]
	bl Heap_Alloc
	str r0, [r6, #0xc]
	cmp r0, #0
	bne _020120B8
	bl GF_AssertFail
_020120B8:
	ldrh r0, [r5, #8]
	str r0, [r6, #0x10]
	mov r0, #0
	str r0, [sp, #0x20]
	ldrh r0, [r5, #8]
	cmp r0, #0
	ble _020120F8
	ldr r4, [sp, #0x20]
	add r7, r4, #0
_020120CA:
	ldr r0, [r5, #4]
	ldr r2, [r6, #0xc]
	add r0, r0, r4
	str r0, [sp]
	ldr r0, [sp, #0x18]
	str r0, [sp, #4]
	add r0, r2, r7
	ldr r3, [r5]
	add r1, r0, #0
	add r2, r2, r7
	add r1, #0x20
	add r2, #0x10
	add r3, r3, r4
	bl sub_02010AB0
	ldr r0, [sp, #0x20]
	ldrh r1, [r5, #8]
	add r0, r0, #1
	add r4, r4, #4
	add r7, #0x30
	str r0, [sp, #0x20]
	cmp r0, r1
	blt _020120CA
_020120F8:
	ldrh r1, [r5, #0xa]
	ldr r2, [sp, #0x38]
	ldr r3, [sp, #0x44]
	add r0, r6, #0
	bl sub_02010E64
	ldr r0, [sp, #0x18]
	str r0, [r6, #0x14]
	ldr r0, [sp, #0x1c]
	str r0, [r6, #0x18]
	mov r0, #0
	str r0, [r6, #0x1c]
	ldr r0, [sp, #0x3c]
	str r0, [r6, #0x24]
	ldr r0, [sp, #0x40]
	str r0, [r6, #0x28]
	ldr r0, [sp, #0x44]
	str r0, [r6, #0x2c]
	ldrh r0, [r5, #0xe]
	str r0, [r6, #0x20]
	add r0, r6, #0
	bl sub_02012204
	ldr r0, _02012198 ; =sub_02010F00
	ldr r2, _0201219C ; =0x000003FF
	add r1, r6, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r6, #0
	mov r1, #0
	bl sub_02010EE0
	ldr r1, [sp, #0x38]
	str r1, [sp]
	mov r1, #3
	lsl r1, r1, #8
	ldrsh r1, [r0, r1]
	str r1, [sp, #4]
	mov r1, #0
	str r1, [sp, #8]
	mov r1, #0x12
	lsl r1, r1, #6
	ldrsh r0, [r0, r1]
	str r0, [sp, #0xc]
	mov r0, #0xc0
	str r0, [sp, #0x10]
	ldr r0, [r6, #0x20]
	str r0, [sp, #0x14]
	ldrb r1, [r5, #0xc]
	ldrb r2, [r5, #0xd]
	ldrh r3, [r5, #0xa]
	ldr r0, [sp, #0x3c]
	bl sub_02010F84
	ldrh r0, [r5, #0xa]
	cmp r0, #0
	ldr r0, [r6, #0x24]
	bne _02012178
	ldr r2, [sp, #0x38]
	ldr r3, [r6, #0x20]
	mov r1, #1
	bl sub_02011068
	b _02012182
_02012178:
	ldr r2, [sp, #0x38]
	ldr r3, [r6, #0x20]
	mov r1, #2
	bl sub_02011068
_02012182:
	ldr r0, [sp, #0x44]
	ldr r2, _020121A0 ; =sub_02010C38
	str r0, [sp]
	ldr r0, [r6, #0x28]
	ldr r3, [sp, #0x38]
	add r1, r6, #0
	bl sub_0200FF88
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	nop
_02012198: .word sub_02010F00
_0201219C: .word 0x000003FF
_020121A0: .word sub_02010C38
	thumb_func_end sub_02012090
	thumb_func_start sub_020121A4
sub_020121A4: ; 0x020121A4
	push {r4, lr}
	add r4, r0, #0
	ldr r1, [r4, #0x1c]
	add r2, r1, #1
	str r2, [r4, #0x1c]
	ldr r1, [r4, #0x18]
	cmp r2, r1
	blt _020121E6
	mov r1, #0
	str r1, [r4, #0x1c]
	ldr r1, [r4, #0x14]
	sub r1, r1, #1
	cmp r1, #0
	ble _020121D8
	str r1, [r4, #0x14]
	bl sub_02012290
	add r0, r4, #0
	bl sub_02012204
	ldr r0, _020121EC ; =sub_02010F00
	ldr r2, _020121F0 ; =0x000003FF
	add r1, r4, #0
	bl SysTask_CreateOnVWaitQueue
	b _020121E6
_020121D8:
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0x2c]
	bl sub_0200FFB4
	mov r0, #1
	pop {r4, pc}
_020121E6:
	mov r0, #0
	pop {r4, pc}
	nop
_020121EC: .word sub_02010F00
_020121F0: .word 0x000003FF
	thumb_func_end sub_020121A4
