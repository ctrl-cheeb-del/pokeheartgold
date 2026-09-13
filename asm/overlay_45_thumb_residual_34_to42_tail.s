#include "config.h"
	.include "asm/macros.inc"
	.include "overlay_45_thumb.inc"
	.include "global.inc"

	.text
	.public ov45_0222FBD8
	.public ov45_0222FC44
	.public ov45_0222FCE0
	.public ov45_0222FD50
	.extern ov45_0222F7B0
	.extern ov45_0222FB5C
	.extern ov45_02254C30
	.extern _022577C0
	.extern ov45_0222F74C
	.extern ov45_02254EF0
	.extern ov45_0222F7A8
	.extern ov45_0222FB84
	.extern ov45_0222FA74
	.extern ov45_0222EB94
	.extern ov45_0222F898
	.extern ov45_0222F928
	.extern ov45_0222F8D8
	.extern ov45_0222FB24
	.extern ov45_02230008
	.extern ov45_0222F978
	.extern ov45_0222F8FC
	.extern ov45_0222FAF8

thumb_func_start ov45_0222FBD8
ov45_0222FBD8: ; 0x0222FBD8
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	str r1, [sp]
	cmp r1, #4
	blt _0222FBE8
	bl GF_AssertFail
_0222FBE8:
	ldr r0, [sp]
	bl ov45_0222F7B0
	str r0, [sp, #4]
	ldr r0, _0222FC3C ; =0x0000011E
	mov r7, #0
	ldrh r0, [r6, r0]
	add r4, r7, #0
	cmp r0, #0
	ble _0222FC26
	add r5, r6, #0
_0222FBFE:
	add r0, r6, #0
	add r1, r4, #0
	mov r2, #0
	bl ov45_0222FB5C
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FC1A
	ldr r1, [r5, #0x34]
	ldr r0, [sp, #4]
	cmp r0, r1
	bne _0222FC1A
	add r7, r7, #1
_0222FC1A:
	ldr r0, _0222FC3C ; =0x0000011E
	add r4, r4, #1
	ldrh r0, [r6, r0]
	add r5, #0xc
	cmp r4, r0
	blt _0222FBFE
_0222FC26:
	ldr r1, _0222FC40 ; =ov45_02254C30
	ldr r0, [sp]
	ldrb r0, [r1, r0]
	cmp r0, r7
	ble _0222FC36
	add sp, #8
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0222FC36:
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0222FC3C: .word 0x0000011E
_0222FC40: .word ov45_02254C30
	thumb_func_end ov45_0222FBD8

thumb_func_start ov45_0222FC44
ov45_0222FC44: ; 0x0222FC44
	push {r3, r4, r5, lr}
	add r5, r0, #0
	cmp r1, #0
	bne _0222FC84
	ldr r0, _0222FCD0 ; =_022577C0
	mov r3, #1
	ldr r2, [r0]
	ldr r1, _0222FCD4 ; =0x000005B4
	lsl r3, r3, #0xa
	str r3, [r2, r1]
	ldr r2, [r0]
	mov r0, #0x6d
	lsl r0, r0, #2
	add r0, r2, r0
	add r1, r2, r1
	bl ov45_02232170
	bl ov45_0222F74C
	cmp r0, #0
	bne _0222FC72
	bl GF_AssertFail
_0222FC72:
	ldr r2, _0222FCD8 ; =ov45_02254EF0
	mov r0, #0
	mov r1, #0
	ldr r2, [r2]
	mvn r0, r0
	add r3, r1, #0
	bl ov45_02232304
	pop {r3, r4, r5, pc}
_0222FC84:
	ldr r0, _0222FCD0 ; =_022577C0
	ldr r4, [r0]
	add r0, r1, #0
	bl ov45_0222F7A8
	ldr r1, _0222FCDC ; =0x0000012D
	ldrb r2, [r4, r1]
	cmp r2, r0
	bne _0222FCC4
	cmp r5, #1
	bne _0222FCBC
	mov r2, #1
	add r0, r1, #2
	strb r2, [r4, r0]
	ldr r0, _0222FCD0 ; =_022577C0
	ldr r0, [r0]
	ldrb r1, [r0, r1]
	bl ov45_0222FB84
	bl ov45_02232580
	add r1, r0, #0
	ldr r0, _0222FCD0 ; =_022577C0
	mov r2, #1
	ldr r0, [r0]
	bl ov45_0222FA74
	pop {r3, r4, r5, pc}
_0222FCBC:
	mov r2, #2
	add r0, r1, #2
	strb r2, [r4, r0]
	pop {r3, r4, r5, pc}
_0222FCC4:
	bl GF_AssertFail
	bl ov45_0222EB94
	pop {r3, r4, r5, pc}
	nop
_0222FCD0: .word _022577C0
_0222FCD4: .word 0x000005B4
_0222FCD8: .word ov45_02254EF0
_0222FCDC: .word 0x0000012D
	thumb_func_end ov45_0222FC44

thumb_func_start ov45_0222FCE0
ov45_0222FCE0: ; 0x0222FCE0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp]
	bl ov45_02232580
	cmp r5, r0
	bne _0222FD04
	ldr r0, _0222FD4C ; =_022577C0
	ldr r1, [r0]
	mov r0, #0x67
	lsl r0, r0, #2
	add r0, r1, r0
	bl ov45_022320C4
	mov r4, #1
	b _0222FD06
_0222FD04:
	mov r4, #0
_0222FD06:
	ldr r0, _0222FD4C ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #0
	bl ov45_0222FA74
	ldr r0, _0222FD4C ; =_022577C0
	ldr r3, [sp]
	ldr r0, [r0]
	add r1, r5, #0
	add r2, r7, #0
	bl ov45_0222F898
	ldr r0, _0222FD4C ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	add r2, r6, #0
	bl ov45_0222F928
	ldr r0, _0222FD4C ; =_022577C0
	add r1, r5, #0
	ldr r6, [r0]
	add r0, r6, #0
	bl ov45_0222F8D8
	add r3, r4, #0
	ldr r4, _0222FD4C ; =_022577C0
	add r1, r0, #0
	ldr r4, [r4]
	ldr r2, [r6, #0x20]
	ldr r4, [r4, #0xc]
	add r0, r5, #0
	blx r4
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222FD4C: .word _022577C0
	thumb_func_end ov45_0222FCE0

thumb_func_start ov45_0222FD50
ov45_0222FD50: ; 0x0222FD50
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #0
	bl ov45_0222FB24
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _0222FDC8
	mov r6, #0
	ldr r7, _0222FDCC ; =_022577C0
	add r4, r6, #0
_0222FD6E:
	ldr r1, [r7]
	mov r0, #6
	add r2, r1, r4
	lsl r0, r0, #8
	ldr r0, [r2, r0]
	cmp r5, r0
	bne _0222FD88
	ldr r2, _0222FDD0 ; =0x000005B8
	add r0, r5, #0
	add r1, r1, r2
	add r1, r1, r4
	bl ov45_02230008
_0222FD88:
	add r6, r6, #1
	add r4, #0x4c
	cmp r6, #3
	blt _0222FD6E
	ldr r0, _0222FDCC ; =_022577C0
	ldr r2, [r0]
	add r0, r5, #0
	ldr r1, [r2, #0x20]
	ldr r2, [r2, #0x10]
	blx r2
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	bl ov45_0222F978
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	bl ov45_0222F8FC
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #0
	bl ov45_0222FAF8
	ldr r0, _0222FDCC ; =_022577C0
	add r1, r5, #0
	ldr r0, [r0]
	mov r2, #1
	bl ov45_0222FAF8
_0222FDC8:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0222FDCC: .word _022577C0
_0222FDD0: .word 0x000005B8
	thumb_func_end ov45_0222FD50
