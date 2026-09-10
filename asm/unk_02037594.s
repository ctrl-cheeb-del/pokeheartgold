	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02037594
sub_02037594: ; 0x02037594
	push {r3, lr}
	ldr r0, _0203760C ; =_021D4140
	ldr r2, [r0, #8]
	cmp r2, #0
	beq _02037608
	ldr r1, _02037610 ; =0x000006AB
	ldrb r0, [r2, r1]
	cmp r0, #1
	beq _020375AC
	cmp r0, #3
	beq _020375E4
	pop {r3, pc}
_020375AC:
	bl sub_02035FF0
	cmp r0, #1
	bne _020375C4
	ldr r1, _0203760C ; =_021D4140
	mov r0, #0xb
	ldr r2, [r1, #8]
	ldr r1, _02037614 ; =0x000006AC
	add r1, r2, r1
	bl sub_020376E0
	b _020375D4
_020375C4:
	ldr r1, _0203760C ; =_021D4140
	mov r0, #0xb
	ldr r2, [r1, #8]
	ldr r1, _02037614 ; =0x000006AC
	add r1, r2, r1
	mov r2, #1
	bl sub_02037108
_020375D4:
	cmp r0, #0
	beq _02037608
	ldr r0, _0203760C ; =_021D4140
	mov r2, #2
	ldr r1, [r0, #8]
	ldr r0, _02037610 ; =0x000006AB
	strb r2, [r1, r0]
	pop {r3, pc}
_020375E4:
	add r1, r1, #1
	mov r0, #0xc
	add r1, r2, r1
	bl sub_020376E0
	cmp r0, #0
	beq _02037608
	ldr r0, _0203760C ; =_021D4140
	ldr r1, [r0, #8]
	ldr r0, _02037614 ; =0x000006AC
	ldrb r0, [r1, r0]
	bl sub_02035FA8
	ldr r0, _0203760C ; =_021D4140
	mov r2, #0
	ldr r1, [r0, #8]
	ldr r0, _02037610 ; =0x000006AB
	strb r2, [r1, r0]
_02037608:
	pop {r3, pc}
	nop
_0203760C: .word _021D4140
_02037610: .word 0x000006AB
_02037614: .word 0x000006AC
	thumb_func_end sub_02037594
