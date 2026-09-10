	.include "asm/macros.inc"
	.include "unk_02035900.inc"
	.include "global.inc"
	.text
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
	thumb_func_start sub_02036438
sub_02036438: ; 0x02036438
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	str r0, [sp]
	mov r7, #0
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_0203772C
	str r0, [sp, #0xc]
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r0, r0, #1
	str r0, [sp, #8]
	add r0, r7, #0
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	cmp r0, #0
	ble _020364F0
	ldr r0, [sp]
	ldr r6, [sp, #4]
	mov r1, #0xc0
	add r5, r0, #0
	add r4, r6, #0
	mul r5, r1
_02036474:
	ldr r0, _02036504 ; =_021D4140
	ldr r1, [r0, #8]
	mov r0, #0x4b
	lsl r0, r0, #4
	add r0, r1, r0
	add r0, r0, r6
	bl sub_02033C28
	ldr r0, [sp, #4]
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	beq _020364A2
	ldr r0, _02036504 ; =_021D4140
	ldr r0, [r0, #8]
	add r0, r5, r0
	add r1, r4, r0
	add r1, #0x80
	mov r0, #0xe
	strb r0, [r1]
	b _020364B4
_020364A2:
	ldr r0, _02036504 ; =_021D4140
	add r7, r7, #1
	ldr r0, [r0, #8]
	add r0, r5, r0
	add r1, r4, r0
	add r1, #0x80
	mov r0, #0xff
	strb r0, [r1]
	b _020364DE
_020364B4:
	ldr r0, _02036504 ; =_021D4140
	ldr r2, [sp, #0xc]
	ldr r1, [r0, #8]
	mov r0, #0x4b
	lsl r0, r0, #4
	add r0, r1, r0
	add r1, #0x80
	add r1, r1, r5
	add r0, r0, r6
	add r1, r1, r4
	bl sub_02033B4C
	ldr r0, _02036504 ; =_021D4140
	ldr r0, [r0, #8]
	add r0, r5, r0
	add r0, r4, r0
	add r0, #0x80
	ldrb r0, [r0]
	cmp r0, #0xe
	bne _020364DE
	add r7, r7, #1
_020364DE:
	ldr r0, [sp, #0xc]
	add r6, #0xc
	add r4, r4, r0
	ldr r0, [sp, #4]
	add r1, r0, #1
	ldr r0, [sp, #8]
	str r1, [sp, #4]
	cmp r1, r0
	blt _02036474
_020364F0:
	ldr r0, [sp, #8]
	cmp r7, r0
	bne _020364FC
	add sp, #0x10
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_020364FC:
	mov r0, #1
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02036504: .word _021D4140
	thumb_func_end sub_02036438
	thumb_func_start sub_02036508
sub_02036508: ; 0x02036508
	push {r3, r4, r5, r6, r7, lr}
	ldr r0, _02036620 ; =_021D4140
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _02036514
	b _0203661C
_02036514:
	bl sub_0203993C
	bl sub_02034044
	cmp r0, #0
	bne _0203661C
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_0203772C
	bl sub_0203993C
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	bl sub_02033FC4
	add r6, r0, #1
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	cmp r1, #2
	beq _02036548
	ldrb r0, [r0]
	cmp r0, #0
	bne _0203661C
_02036548:
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	add r1, r1, #1
	strb r1, [r0]
	bl sub_02035FF0
	cmp r0, #1
	bne _02036572
	ldr r0, _02036620 ; =_021D4140
	ldrb r1, [r0]
	cmp r1, #0
	bne _02036572
	ldr r1, [r0, #8]
	mov r0, #0x6b
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	bl sub_02036438
	ldr r0, _02036620 ; =_021D4140
	mov r1, #1
	strb r1, [r0]
_02036572:
	bl sub_02033298
	cmp r0, #4
	bne _020365A4
	ldr r0, _02036620 ; =_021D4140
	ldr r1, [r0, #8]
	mov r0, #0x6b
	lsl r0, r0, #4
	ldrb r0, [r1, r0]
	add r3, r1, #0
	mov r1, #0xc0
	add r2, r0, #0
	add r3, #0x80
	mul r2, r1
	add r0, r3, r2
	ldr r3, _02036628 ; =sub_02036ABC
	mov r2, #0xe
	bl sub_02033800
	cmp r0, #0
	bne _020365A4
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	sub r1, r1, #1
	strb r1, [r0]
_020365A4:
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	cmp r1, #1
	beq _020365B2
	ldrb r0, [r0]
	cmp r0, #3
	bne _0203660C
_020365B2:
	ldr r7, _02036620 ; =_021D4140
	mov r4, #0
	strb r4, [r7]
	cmp r6, #0
	ble _020365E0
	add r5, r4, #0
_020365BE:
	lsl r0, r4, #0x10
	lsr r0, r0, #0x10
	bl sub_020373B4
	cmp r0, #0
	beq _020365D8
	ldr r0, [r7, #8]
	ldr r1, _0203662C ; =0x0000066C
	add r0, r0, r5
	ldr r1, [r0, r1]
	add r2, r1, #1
	ldr r1, _0203662C ; =0x0000066C
	str r2, [r0, r1]
_020365D8:
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, r6
	blt _020365BE
_020365E0:
	ldr r0, _02036620 ; =_021D4140
	mov r1, #0x6b
	ldr r2, [r0, #8]
	lsl r1, r1, #4
	ldrb r1, [r2, r1]
	add r4, r2, #0
	mov r2, #0xc0
	add r3, r1, #0
	add r4, #0x80
	mul r3, r2
	mov r0, #0
	add r1, r4, r3
	bl sub_020367B0
	ldr r0, _02036620 ; =_021D4140
	mov r1, #0x6b
	ldr r3, [r0, #8]
	lsl r1, r1, #4
	ldrb r2, [r3, r1]
	mov r0, #1
	sub r0, r0, r2
	strb r0, [r3, r1]
_0203660C:
	bl sub_02033298
	cmp r0, #4
	beq _0203661C
	ldr r0, _02036624 ; =_0210F900
	ldrb r1, [r0]
	add r1, r1, #1
	strb r1, [r0]
_0203661C:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02036620: .word _021D4140
_02036624: .word _0210F900
_02036628: .word sub_02036ABC
_0203662C: .word 0x0000066C
	thumb_func_end sub_02036508
