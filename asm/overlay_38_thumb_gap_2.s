.include "asm/macros.inc"
.include "overlay_38_thumb.inc"
.include "global.inc"

.public ov38_0221BA38
.public _02225040
.public _02224E4C
.public ov38_02225074
.public ov38_0222508C
.public ov38_02225094
.public ov38_0222509C
.public ov38_022250B4
.public ov38_022250CC
.public ov38_022250E4
.public ov38_022250FC
.public ov38_02225114

	.text

	thumb_func_start ov38_0221BBD0
ov38_0221BBD0: ; 0x0221BBD0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	add r4, r1, #0
	mov r3, #0
	ldr r1, _0221BE58 ; =_02225040
	mvn r3, r3
	str r3, [r1, #4]
	ldr r3, [r1]
	add r6, r0, #0
	cmp r3, #1
	bne _0221BBE8
	b _0221BE52
_0221BBE8:
	cmp r2, #0
	beq _0221BBEE
	b _0221BDA2
_0221BBEE:
	cmp r3, #4
	beq _0221BBFA
	cmp r3, #6
	beq _0221BCC6
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BBFA:
	cmp r4, #0x20
	bne _0221BCBE
	ldr r5, [r1, #0x28]
	ldr r3, _0221BE5C ; =_02224E4C
	add r5, #0x14
	add r2, sp, #4
	mov r1, #0x11
_0221BC08:
	ldrb r0, [r3]
	add r3, r3, #1
	strb r0, [r2]
	add r2, r2, #1
	sub r1, r1, #1
	bne _0221BC08
	add r3, sp, #0x14
	ldr r2, _0221BE60 ; =ov38_02225074
	add r3, #1
	mov r1, #0x15
_0221BC1C:
	ldrb r0, [r2]
	add r2, r2, #1
	strb r0, [r3]
	add r3, r3, #1
	sub r1, r1, #1
	bne _0221BC1C
	add r0, sp, #0x14
	add r0, #1
	add r1, r6, #0
	add r2, r4, #0
	bl strncat
	add r0, sp, #0x14
	add r0, #1
	bl strlen
	add r1, sp, #0x14
	add r2, r0, #0
	add r0, r5, #0
	add r1, #1
	bl MATH_CalcSHA1
	ldr r0, _0221BE58 ; =_02225040
	ldr r1, _0221BE64 ; =ov38_0222508C
	ldr r0, [r0, #0x24]
	bl strcat
	mov r2, #0
	ldr r4, _0221BE58 ; =_02225040
	add r3, r2, #0
	add r1, sp, #4
	mov r7, #0xf
_0221BC5C:
	ldrb r0, [r5, r2]
	asr r0, r0, #4
	ldrsb r6, [r1, r0]
	ldr r0, [r4, #0x28]
	strb r6, [r0, r3]
	ldrb r0, [r5, r2]
	ldr r6, [r4, #0x28]
	add r2, r2, #1
	and r0, r7
	ldrsb r0, [r1, r0]
	add r6, r6, r3
	add r3, r3, #2
	strb r0, [r6, #1]
	cmp r2, #0x14
	blt _0221BC5C
	ldr r0, _0221BE58 ; =_02225040
	mov r2, #0
	ldr r1, [r0, #0x28]
	add r1, #0x28
	strb r2, [r1]
	ldr r0, [r0, #0x24]
	ldr r1, _0221BE68 ; =ov38_02225094
	bl strcat
	ldr r3, _0221BE58 ; =_02225040
	ldr r0, [r3, #0x30]
	str r0, [sp]
	ldr r0, [r3, #0x10]
	ldr r1, [r3, #0x14]
	ldr r2, [r3, #0x18]
	ldr r3, [r3, #0x2c]
	bl ov38_0221BA38
	cmp r0, #0
	beq _0221BCB4
	cmp r0, #1
	beq _0221BCAA
	cmp r0, #2
	bne _0221BCB4
_0221BCAA:
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #1
	str r1, [r0]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BCB4:
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #5
	str r1, [r0]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BCBE:
	mov r0, #1
	str r0, [r1]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BCC6:
	cmp r4, #0x16
	bne _0221BD70
	ldr r1, _0221BE6C ; =ov38_0222509C
	mov r2, #0x16
	bl strncmp
	cmp r0, #0
	bne _0221BCE4
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #1
	str r1, [r0]
	mov r1, #0x1a
	str r1, [r0, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BCE4:
	ldr r1, _0221BE70 ; =ov38_022250B4
	add r0, r6, #0
	mov r2, #0x16
	bl strncmp
	cmp r0, #0
	bne _0221BD00
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #1
	str r1, [r0]
	mov r1, #0x1b
	str r1, [r0, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BD00:
	ldr r1, _0221BE74 ; =ov38_022250CC
	add r0, r6, #0
	mov r2, #0x16
	bl strncmp
	cmp r0, #0
	bne _0221BD1C
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #1
	str r1, [r0]
	mov r1, #0x1c
	str r1, [r0, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BD1C:
	ldr r1, _0221BE78 ; =ov38_022250E4
	add r0, r6, #0
	mov r2, #0x16
	bl strncmp
	cmp r0, #0
	bne _0221BD38
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #1
	str r1, [r0]
	mov r1, #0x1d
	str r1, [r0, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BD38:
	ldr r1, _0221BE7C ; =ov38_022250FC
	add r0, r6, #0
	mov r2, #0x16
	bl strncmp
	cmp r0, #0
	bne _0221BD54
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #1
	str r1, [r0]
	mov r1, #0x1e
	str r1, [r0, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BD54:
	ldr r1, _0221BE80 ; =ov38_02225114
	add r0, r6, #0
	mov r2, #0x16
	bl strncmp
	cmp r0, #0
	bne _0221BD70
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #1
	str r1, [r0]
	mov r1, #0x1f
	str r1, [r0, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BD70:
	ldr r0, _0221BE58 ; =_02225040
	ldr r2, [r0, #0x20]
	cmp r4, r2
	ldr r0, [r0, #0x1c]
	bgt _0221BD8A
	add r1, r6, #0
	add r2, r4, #0
	bl memcpy
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #7
	str r1, [r0]
	b _0221BD9A
_0221BD8A:
	add r1, r6, #0
	bl memcpy
	ldr r0, _0221BE58 ; =_02225040
	mov r1, #1
	str r1, [r0]
	mov r1, #0x20
	str r1, [r0, #8]
_0221BD9A:
	ldr r0, _0221BE58 ; =_02225040
	add sp, #0x4c
	str r4, [r0, #0xc]
	pop {r4, r5, r6, r7, pc}
_0221BDA2:
	mov r0, #1
	str r0, [r1]
	cmp r2, #0x13
	bhi _0221BE52
	add r0, r2, r2
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221BDB6: ; jump table
	.short _0221BE52 - _0221BDB6 - 2 ; case 0
	.short _0221BDDE - _0221BDB6 - 2 ; case 1
	.short _0221BDE6 - _0221BDB6 - 2 ; case 2
	.short _0221BDEE - _0221BDB6 - 2 ; case 3
	.short _0221BDF6 - _0221BDB6 - 2 ; case 4
	.short _0221BDFE - _0221BDB6 - 2 ; case 5
	.short _0221BE06 - _0221BDB6 - 2 ; case 6
	.short _0221BE0E - _0221BDB6 - 2 ; case 7
	.short _0221BE16 - _0221BDB6 - 2 ; case 8
	.short _0221BE1E - _0221BDB6 - 2 ; case 9
	.short _0221BE26 - _0221BDB6 - 2 ; case 10
	.short _0221BE2E - _0221BDB6 - 2 ; case 11
	.short _0221BE36 - _0221BDB6 - 2 ; case 12
	.short _0221BE52 - _0221BDB6 - 2 ; case 13
	.short _0221BE52 - _0221BDB6 - 2 ; case 14
	.short _0221BE3E - _0221BDB6 - 2 ; case 15
	.short _0221BE46 - _0221BDB6 - 2 ; case 16
	.short _0221BE52 - _0221BDB6 - 2 ; case 17
	.short _0221BE52 - _0221BDB6 - 2 ; case 18
	.short _0221BE4E - _0221BDB6 - 2 ; case 19
_0221BDDE:
	mov r0, #8
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BDE6:
	mov r0, #9
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BDEE:
	mov r0, #0xa
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BDF6:
	mov r0, #0xb
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BDFE:
	mov r0, #0xc
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE06:
	mov r0, #0xd
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE0E:
	mov r0, #0xe
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE16:
	mov r0, #0xf
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE1E:
	mov r0, #0x10
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE26:
	mov r0, #0x11
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE2E:
	mov r0, #0x12
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE36:
	mov r0, #0x13
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE3E:
	mov r0, #0x16
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE46:
	mov r0, #0x17
	str r0, [r1, #8]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
_0221BE4E:
	mov r0, #0x19
	str r0, [r1, #8]
_0221BE52:
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	nop
_0221BE58: .word _02225040
_0221BE5C: .word _02224E4C
_0221BE60: .word ov38_02225074
_0221BE64: .word ov38_0222508C
_0221BE68: .word ov38_02225094
_0221BE6C: .word ov38_0222509C
_0221BE70: .word ov38_022250B4
_0221BE74: .word ov38_022250CC
_0221BE78: .word ov38_022250E4
_0221BE7C: .word ov38_022250FC
_0221BE80: .word ov38_02225114
	thumb_func_end ov38_0221BBD0
