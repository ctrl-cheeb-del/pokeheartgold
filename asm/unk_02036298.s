	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
	.public sub_02036298
	.public sub_02036438
	.public sub_02036508
	.public sub_02036438
	thumb_func_start sub_02036298
sub_02036298: ; 0x02036298
	push {r3, r4, r5, r6, r7, lr}
	bl sub_0203993C
	bl sub_02034084
	cmp r0, #0
	beq _0203634C
	ldr r0, _02036420 ; =_021D4140
	ldr r1, _02036424 ; =0x000006B6
	ldr r0, [r0, #8]
	ldrb r2, [r0, r1]
	cmp r2, #0
	beq _02036308
	sub r1, #0x52
	ldr r1, [r0, r1]
	cmp r1, #0
	beq _020362DA
	bl sub_02036630
	cmp r0, #0
	beq _020362F8
	ldr r0, _02036428 ; =_0210F900
	ldrb r0, [r0, #1]
	cmp r0, #4
	bne _020362F0
	ldr r0, _02036420 ; =_021D4140
	ldr r0, [r0, #8]
	bl sub_02036E60
	ldr r0, _02036428 ; =_0210F900
	mov r1, #2
	strb r1, [r0, #1]
	b _020362F0
_020362DA:
	ldr r1, _02036428 ; =_0210F900
	ldrb r1, [r1, #1]
	cmp r1, #4
	bne _020362F0
	bl sub_02036E60
	cmp r0, #0
	beq _020362F8
	ldr r0, _02036428 ; =_0210F900
	mov r1, #2
	strb r1, [r0, #1]
_020362F0:
	bl sub_02036FA8
	cmp r0, #0
	beq _020362FA
_020362F8:
	b _0203641C
_020362FA:
	ldr r0, _02036420 ; =_021D4140
	mov r1, #0x26
	ldr r0, [r0, #8]
	bl ov00_021E60E8
	cmp r0, #0
	bne _0203630A
_02036308:
	b _0203641C
_0203630A:
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r6, r0, #1
	mov r4, #0
	cmp r6, #0
	ble _02036344
	ldr r7, _02036420 ; =_021D4140
	add r5, r4, #0
_02036322:
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	beq _0203633C
	ldr r0, [r7, #8]
	ldr r1, _0203642C ; =0x0000066C
	add r0, r0, r5
	ldr r1, [r0, r1]
	add r2, r1, #1
	ldr r1, _0203642C ; =0x0000066C
	str r2, [r0, r1]
_0203633C:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r6
	blt _02036322
_02036344:
	ldr r0, _02036428 ; =_0210F900
	mov r1, #4
	strb r1, [r0, #1]
	pop {r3, r4, r5, r6, r7, pc}
_0203634C:
	bl sub_0203993C
	bl sub_02034044
	cmp r0, #0
	beq _020363CA
	ldr r0, _02036420 ; =_021D4140
	ldr r2, _02036424 ; =0x000006B6
	ldr r0, [r0, #8]
	ldrb r1, [r0, r2]
	cmp r1, #0
	beq _0203641C
	add r1, r2, #0
	sub r1, #0x52
	ldr r1, [r0, r1]
	cmp r1, #0
	beq _0203638A
	sub r2, #0x4e
	ldr r1, [r0, r2]
	cmp r1, #3
	bgt _0203641C
	ldr r1, _02036428 ; =_0210F900
	ldrb r1, [r1, #1]
	cmp r1, #4
	bne _020363A0
	bl sub_02036E60
	ldr r0, _02036428 ; =_0210F900
	mov r1, #2
	strb r1, [r0, #1]
	b _020363A0
_0203638A:
	ldr r1, _02036428 ; =_0210F900
	ldrb r1, [r1, #1]
	cmp r1, #4
	bne _020363A0
	bl sub_02036E60
	cmp r0, #0
	beq _0203641C
	ldr r0, _02036428 ; =_0210F900
	mov r1, #2
	strb r1, [r0, #1]
_020363A0:
	bl sub_02036FA8
	cmp r0, #0
	bne _0203641C
	ldr r0, _02036420 ; =_021D4140
	mov r1, #0x26
	ldr r0, [r0, #8]
	bl ov00_021E5F84
	cmp r0, #0
	beq _0203641C
	ldr r0, _02036428 ; =_0210F900
	mov r1, #4
	strb r1, [r0, #1]
	ldr r0, _02036420 ; =_021D4140
	ldr r2, [r0, #8]
	ldr r0, _02036430 ; =0x00000668
	ldr r1, [r2, r0]
	add r1, r1, #1
	str r1, [r2, r0]
	pop {r3, r4, r5, r6, r7, pc}
_020363CA:
	bl sub_02033298
	cmp r0, #4
	bne _0203641C
	bl sub_0203769C
	bl sub_020373B4
	cmp r0, #0
	beq _0203641C
	ldr r0, _02036428 ; =_0210F900
	ldrb r0, [r0, #1]
	cmp r0, #4
	bne _02036418
	ldr r0, _02036420 ; =_021D4140
	ldr r2, [r0, #8]
	ldr r0, _02036430 ; =0x00000668
	ldr r1, [r2, r0]
	cmp r1, #3
	bgt _02036418
	add r0, #0x47
	ldrb r0, [r2, r0]
	lsl r0, r0, #6
	add r0, r2, r0
	bl sub_02036E60
	ldr r0, _02036420 ; =_021D4140
	ldr r2, [r0, #8]
	ldr r0, _02036434 ; =0x000006AF
	ldrb r1, [r2, r0]
	mov r0, #1
	sub r0, r0, r1
	lsl r0, r0, #6
	add r0, r2, r0
	bl sub_02036E60
	ldr r0, _02036428 ; =_0210F900
	mov r1, #0
	strb r1, [r0, #1]
_02036418:
	bl sub_02036AD8
_0203641C:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02036420: .word _021D4140
_02036424: .word 0x000006B6
_02036428: .word _0210F900
_0203642C: .word 0x0000066C
_02036430: .word 0x00000668
_02036434: .word 0x000006AF
	thumb_func_end sub_02036298
